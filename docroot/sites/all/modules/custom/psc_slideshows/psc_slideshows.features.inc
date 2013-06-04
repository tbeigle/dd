<?php
/**
 * @file
 * psc_slideshows.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function psc_slideshows_eck_bundle_info() {
  $items = array(
  'slideshow_slide_flex_slide' => array(
  'machine_name' => 'slideshow_slide_flex_slide',
  'entity_type' => 'slideshow_slide',
  'name' => 'flex_slide',
  'label' => 'Flex Slide',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function psc_slideshows_eck_entity_type_info() {
$items = array(
       'slideshow_slide' => array(
  'name' => 'slideshow_slide',
  'label' => 'Slideshow Slide',
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
