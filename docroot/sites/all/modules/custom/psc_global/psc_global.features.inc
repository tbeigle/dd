<?php
/**
 * @file
 * psc_global.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function psc_global_ctools_plugin_api() {
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
 * Implements hook_node_info().
 */
function psc_global_node_info() {
  $items = array(
    'node_blocks' => array(
      'name' => t('Node Blocks'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Generic Content Page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'section_landing_page' => array(
      'name' => t('Section Landing Page'),
      'base' => 'node_content',
      'description' => t('Use this content type for top-level landing pages, such as the main "about us" page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
