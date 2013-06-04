<?php
/**
 * @file
 * psc_global.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function psc_global_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_section_col_top|field_collection_item|field_content_section_col|form';
  $field_group->group_name = 'group_content_section_col_top';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_content_section_col';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Column Headline',
    'weight' => '0',
    'children' => array(
      0 => 'field_content_section_col_head',
      1 => 'field_content_section_col_html',
      2 => 'field_content_section_col_hclass',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_content_section_col_top|field_collection_item|field_content_section_col|form'] = $field_group;

  return $export;
}
