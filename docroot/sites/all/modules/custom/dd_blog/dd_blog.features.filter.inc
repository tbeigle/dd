<?php
/**
 * @file
 * dd_blog.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function dd_blog_filter_default_formats() {
  $formats = array();

  // Exported format: Advanced.
  $formats['advanced'] = array(
    'format' => 'advanced',
    'name' => 'Advanced',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
