<?php
/**
 * @file
 * psc_calendar.features.inc
 */

/**
 * Implements hook_views_api().
 */
function psc_calendar_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function psc_calendar_eck_bundle_info() {
  $items = array(
  'calendar_event' => array(
  'machine_name' => 'calendar_event',
  'entity_type' => 'calendar',
  'name' => 'event',
  'label' => 'Event',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function psc_calendar_eck_entity_type_info() {
$items = array(
       'calendar' => array(
  'name' => 'calendar',
  'label' => 'Calendar',
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
