<?php
/**
 * @file
 * psc_ministries.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function psc_ministries_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function psc_ministries_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function psc_ministries_node_info() {
  $items = array(
    'ministry_detail' => array(
      'name' => t('Ministry Detail'),
      'base' => 'node_content',
      'description' => t('PSC ministry detail pages.'),
      'has_title' => '1',
      'title_label' => t('Ministry Name'),
      'help' => '',
    ),
  );
  return $items;
}
