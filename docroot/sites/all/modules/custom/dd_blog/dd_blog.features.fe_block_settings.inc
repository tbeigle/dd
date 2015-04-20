<?php
/**
 * @file
 * dd_blog.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dd_blog_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-blog_banners-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'delta' => 'blog_banners-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dd' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dd',
        'weight' => 0,
      ),
    ),
  );

  return $export;
}
