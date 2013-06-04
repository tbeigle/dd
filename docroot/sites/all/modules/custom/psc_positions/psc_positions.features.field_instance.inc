<?php
/**
 * @file
 * psc_positions.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function psc_positions_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'position-volunteer-field_pos_vol_desc'
  $field_instances['position-volunteer-field_pos_vol_desc'] = array(
    'bundle' => 'volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'position',
    'field_name' => 'field_pos_vol_desc',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'position-volunteer-field_pos_vol_info_email'
  $field_instances['position-volunteer-field_pos_vol_info_email'] = array(
    'bundle' => 'volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'psc_site',
        'settings' => array(),
        'type' => 'psc_email_with_icon_formatter',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'position',
    'field_name' => 'field_pos_vol_info_email',
    'label' => 'Contact Email',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'position-volunteer-field_pos_vol_info_name'
  $field_instances['position-volunteer-field_pos_vol_info_name'] = array(
    'bundle' => 'volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'psc_site',
        'settings' => array(),
        'type' => 'psc_contact_name_formatter',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'position',
    'field_name' => 'field_pos_vol_info_name',
    'label' => 'Contact Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'position-volunteer-field_pos_vol_info_phone'
  $field_instances['position-volunteer-field_pos_vol_info_phone'] = array(
    'bundle' => 'volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter either a full phone number of at least 10 digits or a phone extension at PSC. Do not include any numbers (for example, 1) before the area code when entering a full phone number.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'psc_site',
        'settings' => array(),
        'type' => 'psc_phone_formatter',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'position',
    'field_name' => 'field_pos_vol_info_phone',
    'label' => 'Contact Phone',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'position-volunteer-field_pos_vol_ministry'
  $field_instances['position-volunteer-field_pos_vol_ministry'] = array(
    'bundle' => 'volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'position',
    'field_name' => 'field_pos_vol_ministry',
    'label' => 'Ministry',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'position-volunteer-field_pos_vol_skills'
  $field_instances['position-volunteer-field_pos_vol_skills'] = array(
    'bundle' => 'volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'position',
    'field_name' => 'field_pos_vol_skills',
    'label' => 'Relevant Skills',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Email');
  t('Contact Name');
  t('Contact Phone');
  t('Description');
  t('Enter either a full phone number of at least 10 digits or a phone extension at PSC. Do not include any numbers (for example, 1) before the area code when entering a full phone number.');
  t('Ministry');
  t('Relevant Skills');

  return $field_instances;
}
