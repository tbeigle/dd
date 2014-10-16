<?php
if (empty($_POST) || !empty($_POST['subject'])) {
  header('location: /');
  return;
}

require_once('../../ddinc/mail-config.php');
require_once('../../PHPMailer/PHPMailerAutoload.php');
require_once('../../ddinc/ddMailer.php');

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
  var $school = '';
  var $graduation = '';
  var $majors = '';
  var $minors = '';
  var $gpa = '';
  var $coursework = '';
  var $critical_thinking = '';
  var $work_ind = '';
  var $work_partner = '';
  var $self_teach = '';
  var $drupal_interest = '';
  var $drupal_why = '';
  var $fav_movie = '';
  var $fav_movie_why = '';
  var $like_dogs = '';
  var $like_dogs_why = '';
  var $availability = '';
  var $home_office = '';
  var $intern_interest = '';
  var $resume = '';
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
    /*
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
    */
    // Send the email
    $m = new ddMailer();
    $m->Subject = 'DD Contact form submission from ' . $this->name;
    $m->Body = 'Contact form submission by ' . $this->name . ' (' . $this->email . '): ' . "\n\n" . $this->message;
    $m->addAddress('tom@designated-developers.com', 'Tom Beigle');
    //$m->addAddress('sara@designated-developers.com', 'Sara Beigle');
    
    if (!$m->Send()) {
      // Whoops. Something went wrong.
    }
    
    $m->ClearAddresses();
    $m->ClearAttachments();
  }
  
  private function _test_input($val) {
    $val = trim($val);
    $val = stripslashes($val);
    $val = htmlspecialchars($val);
    
    return $val;
  }
}
