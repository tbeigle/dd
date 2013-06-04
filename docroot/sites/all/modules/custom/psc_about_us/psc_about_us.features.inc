<?php
/**
 * @file
 * psc_about_us.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function psc_about_us_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function psc_about_us_node_info() {
  $items = array(
    'about_us_section_page' => array(
      'name' => t('About Us Section Page'),
      'base' => 'node_content',
      'description' => t('Use this content type for pages that should be contained within the "About Us" section of the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
