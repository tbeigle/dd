<?php
/**
 * Helper class for building a portfolio slideshow slide
 */
class _dd_portfolio_slider_slide {
  var $img = array();
  var $url = '';
  var $title = '';
  var $caption = '';
  
  function __construct($node = NULL) {
    if (!empty($node)) {
      $this->_build_slide($node);
    }
  }
  
  /**
   * Loads the slide details
   */
  private function _build_slide($node) {
    if (is_numeric($node)) {
      $node = node_load($node);
    }
    
    if (empty($node->nid)) return;
    
    $nw = entity_metadata_wrapper('node', $node);
    $company = $nw->field_portfolio_comp->value();
    $cw = entity_metadata_wrapper('taxonomy_term', $company);
    
    $i = $nw->field_portfolio_img->value();
    $u = $cw->field_comps_url->value();
    $c = $nw->field_portfolio_desc->value();
    
    $this->img = array(
      'src' => file_create_url($i['uri']),
      'alt' => $i['alt'],
    );
    
    $this->url = $u['url'];
    $this->title = trim(preg_replace('/https?:\/\/(www\.)?/', '', $this->url), '/');
    $this->caption = $c['value'];
  }
}
