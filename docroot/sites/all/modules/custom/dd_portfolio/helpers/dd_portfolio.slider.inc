<?php
/**
 * Helper class for building the portfolio slideshow
 */
class _dd_portfolio_slider {
  var $slides = array();
  
  function __construct() {
    $this->_build_slides();
  }
  
  /**
   * Builds the slides
   */
  private function _build_slides() {
    $query =
      'SELECT n.`nid` AS `nid` ' .
      'FROM {field_data_field_portfolio_weight} w ' .
        'INNER JOIN {node} n ' .
          'ON w.`entity_id` = n.`nid` ' .
      'WHERE `entity_type` = :type ' .
        'AND n.`status` = :status ' .
      'ORDER BY n.`status` DESC, n.`type` DESC, w.`field_portfolio_weight_value` ASC, n.`title` ASC ' .
      'LIMIT 10';
    $nids = db_query($query, array(':type' => 'node', ':status' => 1))->fetchCol();
    
    if (empty($nids)) return;
    
    $nodes = node_load_multiple($nids);
    foreach ($nodes as $node) {
      $this->slides[] = new _dd_portfolio_slider_slide($node);
    }
  }
}
