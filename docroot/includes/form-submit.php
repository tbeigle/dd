<?php
if (empty($_POST) || !empty($_POST['subject'])) {
  header('location: /');
  return;
}

$form = new ddForm($_POST);
$form->validate();

if (!empty($form->errors)) {
  print json_encode(array('errors' => $form->errors));
}
else {
  print json_encode(array('message' => 'Thank you for submitting our contact form. We will respond at our earliest opportunity.'));
}

class ddForm {
  var $name = '';
  var $email = '';
  var $message = '';
  var $result = '';
  var $errors = array();
  
  function __construct($form) {
    $this->construct_ran = 1;
    foreach ($form as $key => $val) {
      if (!isset($this->{$key})) continue;
      $this->{$key} = $this->_test_input($val);
    }
  }
  
  public function validate() {
    $required = array('name', 'email', 'message');
    foreach ($required as $field) {
      if (empty($this->{$field})) {
        $this->errors[$field] = 'Please enter a valid ' . $field . ' to complete submission of the form.';
        continue;
      }
      
      if ($field == 'name' && !preg_match('/^[a-zA-Z]/', $this->{$field})) {
        $this->errors[$field] = 'You must enter a valid name beginning with a letter to proceed.';
      }
      elseif ($field == 'email' && !filter_var($this->{$field}, FILTER_VALIDATE_EMAIL)) {
        $this->errors[$field] = 'Please enter a valid email address formatted like so: name@domain.com.';
      }
    }
    
    if (empty($this->errors)) {
      $this->_submit();
    }
  }
  
  private function _submit() {
    require_once('../../ddinc/con.php');
    if (class_exists('ddDb')) {
      $db = new ddDb();
      
      $query =
        'INSERT INTO `contact_submissions` ' .
        'SET ' .
          '`name` = "' . $this->name . '", ' .
          '`email` = "' . $this->email . '", ' .
          '`message` = "' . $this->message . '";';
      $this->result = $db->q($query);
    }
  }
  
  private function _test_input($val) {
    $val = trim($val);
    $val = stripslashes($val);
    $val = htmlspecialchars($val);
    
    return $val;
  }
}
?>