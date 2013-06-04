<?php
/**
 * @file
 * psc_downloads.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function psc_downloads_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'recent_weekly_announcements';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_downloads';
  $view->human_name = 'Recent Weekly Announcements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'group actions actions-2 col-wrapper-2';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Downloads: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_downloads';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Downloads: Bulletin */
  $handler->display->display_options['fields']['field_bulletin']['id'] = 'field_bulletin';
  $handler->display->display_options['fields']['field_bulletin']['table'] = 'field_data_field_bulletin';
  $handler->display->display_options['fields']['field_bulletin']['field'] = 'field_bulletin';
  $handler->display->display_options['fields']['field_bulletin']['label'] = '';
  $handler->display->display_options['fields']['field_bulletin']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bulletin']['type'] = 'file_url_plain';
  /* Sort criterion: Downloads: Date (field_bulletin_date) */
  $handler->display->display_options['sorts']['field_bulletin_date_value']['id'] = 'field_bulletin_date_value';
  $handler->display->display_options['sorts']['field_bulletin_date_value']['table'] = 'field_data_field_bulletin_date';
  $handler->display->display_options['sorts']['field_bulletin_date_value']['field'] = 'field_bulletin_date_value';
  $handler->display->display_options['sorts']['field_bulletin_date_value']['order'] = 'DESC';
  /* Filter criterion: Downloads: downloads type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_downloads';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'weekly_announcement' => 'weekly_announcement',
  );

  /* Display: Block: Recent Weekly Announcements */
  $handler = $view->new_display('block', 'Block: Recent Weekly Announcements', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['recent_weekly_announcements'] = $view;

  return $export;
}
