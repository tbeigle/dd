<?php
/**
 * Helper class for building the portfolio slideshow
 */
class _dd_people_wwa {
  var $people = array();
  
  function __construct() {
    $this->_get_people();
  }
  
  /**
   * Builds the array of users
   */
  private function _get_people() {
    $rid = variable_get('dd_people_rid', 5);
    
    $query =
      'SELECT u.`uid` ' .
      'FROM {users} u ' .
        'INNER JOIN {field_data_field_user_ln} ln ' .
          'ON u.`uid` = ln.`entity_id` ' .
            'AND ln.`entity_type` = :type_user ' .
        'INNER JOIN {field_data_field_user_fn} fn ' .
          'ON u.`uid` = fn.`entity_id` ' .
            'AND ln.`entity_type` = fn.`entity_type` ' .
        'INNER JOIN {users_roles} ur ' .
          'ON u.`uid` = ur.`uid` ' .
            'AND ur.`rid` = :rid ' .
      'WHERE u.`status` = :status ' .
      'ORDER BY ln.`field_user_ln_value` ASC, fn.`field_user_fn_value` ASC';
    $uids = db_query($query, array(':type_user' => 'user', ':rid' => $rid, ':status' => 1))->fetchCol();
    
    if (empty($uids)) return;
    
    $users = entity_load('user', $uids);
    $toggle = 'right';
    $row = 0;
    $ua = user_access('administer users');
    $lt = t('edit');
    $l_opts = array(
      'attributes' => array('class' => array('wwa-edit-link')),
      'query' => array(
        'destination' => '#wwa-container',
      ),
    );
    
    foreach ($users as $u) {
      if ($toggle == 'right') {
        $toggle = 'left';
        $row++;
      }
      else {
        $toggle = 'right';
      }
      
      if ($ua) {
        $edit_link = l($lt, 'user/' . $u->uid . '/edit', $l_opts);
      }
      else {
        $edit_link = '';
      }
      
      $uw = entity_metadata_wrapper('user', $u);
      $this->people[$row][] = (object) array(
        'name' => $uw->field_user_fn->value() . ' ' . $uw->field_user_ln->value(),
        'position' => $uw->field_user_pos->value(),
        'bio' => $uw->field_user_bio->value->value(),
        'css_class' => 'column six ' . $toggle,
        'link' => !empty($edit_link) ? $edit_link : '',
      );
    }
  }
}