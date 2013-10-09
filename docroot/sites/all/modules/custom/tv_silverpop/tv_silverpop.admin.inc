<?php

/**
 * @file
 * Admin settings
 */

/**
 * Builds the Silverpop admin settings form
 */
function tv_silverpop_admin_settings($form, &$form_state) {
  $test_defaults = array(
    'username' => 'tom@designated-developers.com',
    'password' => '82865!lv3Rp00P',
    'endpoint' => 'www.api3.silverpop.com/XMLAPI',
  );
  $settings = variable_get('tv_silverpop_settings', $test_defaults);
  
  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Silverpop Username'),
    '#required' => TRUE,
  );
  
  if (!empty($settings['username'])) {
    $form['username']['#default_value'] = $settings['username'];
  }
  
  $form['password'] = array(
    '#type' => 'password',
    '#title' => t('Silverpop Password'),
  );
  
  if (empty($settings['password'])) {
    $form['password']['#required'] = TRUE;
  }
  else {
    $form['old_password'] = array(
      '#type' => 'value',
      '#value' => $settings['password'],
    );
  }
  
  $form['endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Endpoint'),
    '#required' => TRUE,
    '#default_value' => !empty($settings['endpoint']) ? $settings['endpoint'] : '',
  );
  
  $form['jsession_id'] = array(
    '#type' => 'hidden',
    '#value' => '',
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  $form['#validate'][] = 'tv_silverpop_admin_settings_validate';
  $form['#submit'][] = 'tv_silverpop_admin_settings_submit';
  
  return $form;
}

/**
 * Validates the Silverpop admin settings form
 */
function tv_silverpop_admin_settings_validate(&$form, &$form_state) {
  if (empty($form_state['values']['old_password']) && empty($form_state['values']['password'])) {
    form_set_error('password', 'Your Silverpop account password is required to proceed.');
    return;
  }
  
  $user = $form_state['values']['username'];
  $pass = !empty($form_state['values']['password']) ? $form_state['values']['password'] : $form_state['values']['old_password'];
  $ep = $form_state['values']['endpoint'];
  
  $sp = new _tv_silverpop($user, $pass, $ep);
  $login = $sp->log_in();
  drupal_set_message('<pre>' . print_r($sp, TRUE) . '</pre>');
  if (!$login) {
    form_set_error('', 'Could not log into Silverpop with the provided username, password, and endpoint.');
  }
  else {
    form_set_error('', 'TESTING');
    //$sp->log_out();
  }
}

/**
 * Handles submission of the Silverpop admin settings form
 */
function tv_silverpop_admin_settings_submit(&$form, &$form_state) {
  $settings = variable_get('tv_silverpop_settings', array());
  $settings['username'] = $form_state['values']['username'];
  
  if (!empty($form_state['values']['password'])) {
    $settings['password'] = $form_state['values']['password'];
  }
  
  variable_set('tv_silverpop_settings', $settings);
}

/**
 * Helper class for Silverpop API transactions
 */
class _tv_silverpop {
  var $username;
  var $password;
  var $endpoint;
  var $session_id;
  var $wrapper;
  var $login_required = FALSE;
  
  function __construct($user = '', $pass = '', $ep = '') {
    $this->set_core_vars($user, $pass,  $ep);
  }
  
  /**
   * Sets username, password, and endpoint variables
   */
  function set_core_vars($user = '', $pass = '', $ep = '') {
    if (empty($user) || empty($pass) || empty($ep)) {
      $settings = variable_get('tv_silverpop_settings', array('username' => '', 'password' => '', 'endpoint' => ''));
      
      foreach ($settings as $key => $setting) {
        $this->{$key} = $setting;
      }
    }
    else {
      $this->username = $user;
      $this->password = $pass;
      $this->endpoint = $ep;
    }
  }
  
  /**
   * Logs into Silverpop and populates the session_id variable
   */
  function log_in() {
    $dom = new DOMDocument;
    $user_text = $dom->createTextNode($this->username);
    $user = $dom->createElement('USERNAME');
    
    $password_text = $dom->createTextNode($this->password);
    $password = $dom->createElement('PASSWORD');
    
    $method = $dom->createElement('Login');
    
    $user->appendChild($user_text);
    $password->appendChild($password_text);
    $method->appendChild($user);
    $method->appendChild($password);
    $dom->appendChild($method);
    
    list($retcode, $response) = $this->_do_call($this->_build_envelope($dom));
    
    // extract the sessionid if it is available
    if (!$retcode) return FALSE;
    
    if (is_object($response) and isset($response->getElementsByTagName('SESSIONID')->item(0)->nodeValue)) {
      $this->session_id = $response->getElementsByTagName('SESSIONID')->item(0)->nodeValue;
      return TRUE;
    }
    
    return FALSE;
  }
  
  /**
   * Logs out of Silverpop
   */
  function log_out() {
    $dom = new DOMDocument;
    $method = $dom->createElement('Logout');
    $dom->appendChild($method);
    
    $this->_do_call($this->_build_envelope($dom));

    return TRUE;
  }
  
  /**
   * build the xml envelope
   * Pass the inner method and paramters as a DOMDocument
   * Return the stringified xml
   */
  function _build_envelope($inner) {
    // Create the outgoing xml.
    // First create the outer wrapper
    $wrapper = new DOMDocument;
    $envelope = $wrapper->createElement('Envelope');
    $body_tag = $wrapper->createElement('Body');
    
    $wrapper->appendChild($envelope);
    $envelope->appendChild($body_tag);
    
    // Now insert the passed parameters into this wrapper
    $node = $inner->documentElement;
    $node = $wrapper->importNode($node, true);
    $wrapper->getElementsByTagName('Body')->item(0)->appendChild($node);
    
    return $wrapper->saveXML();
  }
  
  // low level API call not available to clients
  private function _do_call($wrapper = NULL) {
    // ok now ready to go
    if (!$wrapper) {
      $data = "xml=" . urlencode($this->wrapper);
    }
    else {
      $data = "xml=" . urlencode($wrapper);
    }
    
    // open connection
    // port 80, timeout of 20
    if (($sock = @fsockopen($this->endpoint, 80, $errno, $errstr, 20)) == NULL) {
      watchdog('tv_silverpop', 'Could not connect to host with error number: @errno and diagnostic: @errstr', array('@errno' => $errno, '@errstr' => $errstr), WATCHDOG_ERROR);
      return array(NULL, NULL);
    }
    
    // outgoing message
    $jsessionid = '';
    if ($this->login_required) $jsessionid = ';jsessionid=' . $this->session_id;
    
    fputs($sock, "POST /servlet/XMLAPI{$jsessionid} HTTP/1.1\n");
    fputs($sock, "Host: " . $this->endpoint . "\n");
    fputs($sock, "Content-type: application/x-www-form-urlencoded\n");
    fputs($sock, "Content-length: " . strlen ($data) . "\n");
    fputs($sock, "Connection: close\n\n");
    fputs($sock, $data);
    
    // incoming
    $buffer = "";
    while (!feof($sock)) {
      $buffer .= fgets($sock);
    }
    
    fclose($sock);
    
    // Ok so was there an error? If so, stick it in the log
    if (($pos = stripos($buffer, '<Envelope>')) === NULL) {
      watchdog('silverpop', 'Unspecified error diagnostic. Output dump: @dump', array('@dump' => $buffer), WATCHDOG_ERROR);
      return array(NULL, NULL);
    }
    else {
      $epos = stripos($buffer, '</Envelope>') + strlen('</Envelope>');
      $b_body = substr($buffer, $pos, $epos - $pos);
      
      $response = new DOMDocument;
      $response->loadXML($b_body);
      
      $success = $response->getElementsByTagName('SUCCESS');
      $fault = $response->getElementsByTagName('FaultString');
      $errorid = $response->getElementsByTagName('errorid');
      
      if ($success->length and strtoupper($response->getElementsByTagName('SUCCESS')->item(0)->nodeValue) == 'FALSE') {
        $err_arr = array();
        $msg = 'API call failed.';
        
        // did we get an error message?
        if ($fault->length) { 
          $msg .= ' Diagnostic: @fault'; 
          $err_arr['@fault'] = $response->getElementsByTagName('FaultString')->item(0)->nodeValue; 
        }
        
        // did we get an error number?
        if ($errorid->length) {
          $msg .= ' Error code: @errorid';
          $err_arr['@errorid'] = $response->getElementsByTagName('errorid')->item(0)->nodeValue;
        }
        
        watchdog('silverpop', $msg, $err_arr, WATCHDOG_ERROR);
        return array(FALSE, $response);
      }
    }
    
    return array(TRUE, $response);  
  }
}
