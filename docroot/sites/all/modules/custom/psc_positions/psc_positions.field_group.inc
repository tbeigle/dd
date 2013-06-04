<?php
/**
 * @file
 * psc_positions.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function psc_positions_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pos_pay_info_dis|position|paid|default';
  $field_group->group_name = 'group_pos_pay_info_dis';
  $field_group->entity_type = 'position';
  $field_group->bundle = 'paid';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Information Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_pos_pay_info_name',
      1 => 'field_pos_pay_info_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More Information Details',
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
  $export['group_pos_pay_info_dis|position|paid|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pos_pay_info|position|paid|form';
  $field_group->group_name = 'group_pos_pay_info';
  $field_group->entity_type = 'position';
  $field_group->bundle = 'paid';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_pos_pay_info_name',
      1 => 'field_pos_pay_info_email',
      2 => 'field_pos_pay_learn_more',
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
  $export['group_pos_pay_info|position|paid|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pos_vol_info_dis_contact|position|volunteer|default';
  $field_group->group_name = 'group_pos_vol_info_dis_contact';
  $field_group->entity_type = 'position';
  $field_group->bundle = 'volunteer';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_pos_vol_info_dis';
  $field_group->data = array(
    'label' => 'Contact Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_pos_vol_info_email',
      1 => 'field_pos_vol_info_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Info',
      'instance_settings' => array(
        'classes' => 'contact-info contact-info-alt',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pos_vol_info_dis_contact|position|volunteer|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pos_vol_info_dis|position|volunteer|default';
  $field_group->group_name = 'group_pos_vol_info_dis';
  $field_group->entity_type = 'position';
  $field_group->bundle = 'volunteer';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Information Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_pos_vol_info_name',
      1 => 'group_pos_vol_info_dis_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More Information Details',
      'instance_settings' => array(
        'classes' => 'card-contact-info-details contact-well separator',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pos_vol_info_dis|position|volunteer|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pos_vol_info|position|volunteer|form';
  $field_group->group_name = 'group_pos_vol_info';
  $field_group->entity_type = 'position';
  $field_group->bundle = 'volunteer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_pos_vol_info_name',
      1 => 'field_pos_vol_info_email',
      2 => 'field_pos_vol_info_phone',
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
  $export['group_pos_vol_info|position|volunteer|form'] = $field_group;

  return $export;
}
