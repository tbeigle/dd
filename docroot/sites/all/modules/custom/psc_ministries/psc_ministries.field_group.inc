<?php
/**
 * @file
 * psc_ministries.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function psc_ministries_field_group_info() {
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ministry_contact_method|node|ministry_detail|default';
  $field_group->group_name = 'group_ministry_contact_method';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ministry_detail';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_ministry_contact';
  $field_group->data = array(
    'label' => 'Ministry Contact Methods',
    'weight' => '11',
    'children' => array(
      0 => 'field_ministry_contact_email',
      1 => 'field_ministry_contact_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Ministry Contact Methods',
      'instance_settings' => array(
        'classes' => 'contact-info contact-info-alt col col-2 capless-children',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ministry_contact_method|node|ministry_detail|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ministry_contact_name|node|ministry_detail|default';
  $field_group->group_name = 'group_ministry_contact_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ministry_detail';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_ministry_contact';
  $field_group->data = array(
    'label' => 'Contact Name',
    'weight' => '10',
    'children' => array(
      0 => 'field_ministry_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Name',
      'instance_settings' => array(
        'classes' => 'contact-name brand-alpha col col-1 capless-children',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ministry_contact_name|node|ministry_detail|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ministry_contact|node|ministry_detail|default';
  $field_group->group_name = 'group_ministry_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ministry_detail';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Info',
    'weight' => '10',
    'children' => array(
      0 => 'group_ministry_contact_name',
      1 => 'group_ministry_contact_method',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Info',
      'instance_settings' => array(
        'classes' => 'contact-well well col-wrapper-2 group',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ministry_contact|node|ministry_detail|default'] = $field_group;

  return $export;
}
