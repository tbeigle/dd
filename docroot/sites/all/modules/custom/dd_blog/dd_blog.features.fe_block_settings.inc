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
    'css_class' => 'blog-post-banner',
    'custom' => 0,
    'delta' => 'blog_banners-block',
    'module' => 'views',
    'node_types' => array(
      0 => 'blog_post',
    ),
    'pages' => 'blog/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dd' => array(
        'region' => 'highlighted',
        'status' => 1,
        'theme' => 'dd',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
