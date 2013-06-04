<?php
/**
 * @file
 * psc_positions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function psc_positions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function psc_positions_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function psc_positions_eck_bundle_info() {
  $items = array(
  'position_paid' => array(
  'machine_name' => 'position_paid',
  'entity_type' => 'position',
  'name' => 'paid',
  'label' => 'Paid',
),
  'position_volunteer' => array(
  'machine_name' => 'position_volunteer',
  'entity_type' => 'position',
  'name' => 'volunteer',
  'label' => 'Volunteer',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function psc_positions_eck_entity_type_info() {
$items = array(
       'position' => array(
  'name' => 'position',
  'label' => 'Position',
  'properties' => array(
    'title' => array(
      'label' => 'Title',
      'type' => 'text',
      'behavior' => 'title',
    ),
  ),
),
  );
  return $items;
}
