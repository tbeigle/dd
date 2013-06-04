<?php
/**
 * @file
 * psc_downloads.features.inc
 */

/**
 * Implements hook_views_api().
 */
function psc_downloads_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function psc_downloads_eck_bundle_info() {
  $items = array(
  'downloads_weekly_announcement' => array(
  'machine_name' => 'downloads_weekly_announcement',
  'entity_type' => 'downloads',
  'name' => 'weekly_announcement',
  'label' => 'Weekly Announcement',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function psc_downloads_eck_entity_type_info() {
$items = array(
       'downloads' => array(
  'name' => 'downloads',
  'label' => 'Downloads',
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
