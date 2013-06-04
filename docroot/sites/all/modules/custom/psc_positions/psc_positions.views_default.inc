<?php
/**
 * @file
 * psc_positions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function psc_positions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_position';
  $view->human_name = 'Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current Job Openings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Blurb';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Field: Position: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_position';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Position: Description */
  $handler->display->display_options['fields']['field_pos_pay_desc']['id'] = 'field_pos_pay_desc';
  $handler->display->display_options['fields']['field_pos_pay_desc']['table'] = 'field_data_field_pos_pay_desc';
  $handler->display->display_options['fields']['field_pos_pay_desc']['field'] = 'field_pos_pay_desc';
  $handler->display->display_options['fields']['field_pos_pay_desc']['label'] = '';
  $handler->display->display_options['fields']['field_pos_pay_desc']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pos_pay_desc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_pay_desc']['element_default_classes'] = FALSE;
  /* Field: Position: Contact Name */
  $handler->display->display_options['fields']['field_pos_pay_info_name']['id'] = 'field_pos_pay_info_name';
  $handler->display->display_options['fields']['field_pos_pay_info_name']['table'] = 'field_data_field_pos_pay_info_name';
  $handler->display->display_options['fields']['field_pos_pay_info_name']['field'] = 'field_pos_pay_info_name';
  $handler->display->display_options['fields']['field_pos_pay_info_name']['label'] = '';
  $handler->display->display_options['fields']['field_pos_pay_info_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_pay_info_name']['type'] = 'psc_contact_name_formatter';
  /* Field: Position: Contact Email */
  $handler->display->display_options['fields']['field_pos_pay_info_email']['id'] = 'field_pos_pay_info_email';
  $handler->display->display_options['fields']['field_pos_pay_info_email']['table'] = 'field_data_field_pos_pay_info_email';
  $handler->display->display_options['fields']['field_pos_pay_info_email']['field'] = 'field_pos_pay_info_email';
  $handler->display->display_options['fields']['field_pos_pay_info_email']['label'] = '';
  $handler->display->display_options['fields']['field_pos_pay_info_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_pay_info_email']['type'] = 'psc_email_with_icon_formatter';
  /* Field: Position: Learn More Download */
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['id'] = 'field_pos_pay_learn_more';
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['table'] = 'field_data_field_pos_pay_learn_more';
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['field'] = 'field_pos_pay_learn_more';
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['label'] = '';
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['type'] = 'psc_download_button_formatter';
  $handler->display->display_options['fields']['field_pos_pay_learn_more']['settings'] = array(
    'text' => 'Learn More',
  );
  /* Sort criterion: Position: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'eck_position';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Position: position type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_position';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'paid' => 'paid',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'jobs_page_main');
  $handler->display->display_options['path'] = 'jobs';
  $export['jobs'] = $view;

  $view = new view();
  $view->name = 'positions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_position';
  $view->human_name = 'Positions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Serve Title';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'col-wrapper-2 group';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_pos_vol_ministry_target_id']['id'] = 'field_pos_vol_ministry_target_id';
  $handler->display->display_options['relationships']['field_pos_vol_ministry_target_id']['table'] = 'field_data_field_pos_vol_ministry';
  $handler->display->display_options['relationships']['field_pos_vol_ministry_target_id']['field'] = 'field_pos_vol_ministry_target_id';
  $handler->display->display_options['relationships']['field_pos_vol_ministry_target_id']['required'] = TRUE;
  /* Field: Position: Id (hidden) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_position';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['ui_name'] = 'Position: Id (hidden)';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Position: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_position';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'card-title brand-alpha brand-standout';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Position: Description */
  $handler->display->display_options['fields']['field_pos_vol_desc']['id'] = 'field_pos_vol_desc';
  $handler->display->display_options['fields']['field_pos_vol_desc']['table'] = 'field_data_field_pos_vol_desc';
  $handler->display->display_options['fields']['field_pos_vol_desc']['field'] = 'field_pos_vol_desc';
  $handler->display->display_options['fields']['field_pos_vol_desc']['label'] = '';
  $handler->display->display_options['fields']['field_pos_vol_desc']['alter']['text'] = '[field_pos_vol_desc-value]';
  $handler->display->display_options['fields']['field_pos_vol_desc']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pos_vol_desc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_vol_desc']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_pos_vol_desc']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pos_vol_desc']['group_column'] = 'entity_id';
  /* Field: Position: Contact Name */
  $handler->display->display_options['fields']['field_pos_vol_info_name']['id'] = 'field_pos_vol_info_name';
  $handler->display->display_options['fields']['field_pos_vol_info_name']['table'] = 'field_data_field_pos_vol_info_name';
  $handler->display->display_options['fields']['field_pos_vol_info_name']['field'] = 'field_pos_vol_info_name';
  $handler->display->display_options['fields']['field_pos_vol_info_name']['label'] = '';
  $handler->display->display_options['fields']['field_pos_vol_info_name']['alter']['text'] = '<div class="card-contact-info-details contact-well separator">
  <div class="contact-name brand-alpha">
  </div>
</div>';
  $handler->display->display_options['fields']['field_pos_vol_info_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_vol_info_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pos_vol_info_name']['type'] = 'psc_contact_name_formatter';
  $handler->display->display_options['fields']['field_pos_vol_info_name']['group_column'] = 'entity_id';
  /* Field: Position: Contact Email */
  $handler->display->display_options['fields']['field_pos_vol_info_email']['id'] = 'field_pos_vol_info_email';
  $handler->display->display_options['fields']['field_pos_vol_info_email']['table'] = 'field_data_field_pos_vol_info_email';
  $handler->display->display_options['fields']['field_pos_vol_info_email']['field'] = 'field_pos_vol_info_email';
  $handler->display->display_options['fields']['field_pos_vol_info_email']['label'] = '';
  $handler->display->display_options['fields']['field_pos_vol_info_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_vol_info_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pos_vol_info_email']['type'] = 'psc_email_with_icon_formatter';
  $handler->display->display_options['fields']['field_pos_vol_info_email']['group_column'] = 'entity_id';
  /* Field: Position: Contact Phone */
  $handler->display->display_options['fields']['field_pos_vol_info_phone']['id'] = 'field_pos_vol_info_phone';
  $handler->display->display_options['fields']['field_pos_vol_info_phone']['table'] = 'field_data_field_pos_vol_info_phone';
  $handler->display->display_options['fields']['field_pos_vol_info_phone']['field'] = 'field_pos_vol_info_phone';
  $handler->display->display_options['fields']['field_pos_vol_info_phone']['label'] = '';
  $handler->display->display_options['fields']['field_pos_vol_info_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pos_vol_info_phone']['type'] = 'psc_phone_formatter';
  $handler->display->display_options['fields']['field_pos_vol_info_phone']['group_column'] = 'entity_id';
  /* Sort criterion: Position: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'eck_position';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_pos_vol_ministry_target_id';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Position: Relevant Skills (field_pos_vol_skills) */
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['id'] = 'field_pos_vol_skills_tid';
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['table'] = 'field_data_field_pos_vol_skills';
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['field'] = 'field_pos_vol_skills_tid';
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_pos_vol_skills_tid']['break_phrase'] = TRUE;
  /* Filter criterion: Position: position type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_position';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'volunteer' => 'volunteer',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'serve');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p class="blurb">Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'serve';
  $export['positions'] = $view;

  return $export;
}
