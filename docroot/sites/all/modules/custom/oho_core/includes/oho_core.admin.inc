<?php

/**
 * Form for the special content domain source settings
 */
function oho_domain_content_settings($form, &$form_state) {
  global $_oho_core;
  
  $settings = !empty($_oho_core['domain_source_settings']) ? $_oho_core['domain_source_settings'] : '';
  
  $vocabularies = !empty($settings['vocabularies']) ? $settings['vocabularies'] : array();
  $views = !empty($settings['views']) ? $settings['views'] : array();
  
  $domains = array(0 => 'No Source Domain');
  
  if (!db_table_exists('domain')) return t('The domain access module is required to edit these settings.');
  
  $sql =
    'SELECT `domain_id`, `sitename` '.
    'FROM {domain} '.
    'ORDER BY `domain_id`;';
  $results = db_query($sql);
  
  foreach ($results as $row) {
    $domains[$row->domain_id] = $row->sitename;
  }
  
  // Taxonomy vocabularies
  $form['vocabularies'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taxonomy Vocabularies'),
    '#tree' => TRUE,
  );
  
  $sql =
    'SELECT `vid`, `name` '.
    'FROM {taxonomy_vocabulary} '.
    'ORDER BY `weight` ASC;';
  $results = db_query($sql);
  
  foreach ($results as $row) {
    $form['vocabularies'][$row->vid] = array(
      '#type' => 'select',
      '#title' => $row->name,
      '#options' => $domains,
      '#default_value' => !empty($vocabularies[$row->vid]) ? $vocabularies[$row->vid] : 0,
    );
  }
  
  // Views
  if (function_exists('views_get_all_views')) {
    $form['views'] = array(
      '#type' => 'fieldset',
      '#title' => t('Views'),
      '#tree' => TRUE,
    );
    
    $all_views = views_get_all_views();
    
    if (empty($all_views)) {
      $all_views = array();
    }
    
    asort($all_views);
    
    foreach ($all_views as $name => $view) {
      if (!empty($name) && !empty($view->human_name) && empty($view->disabled)) {
        $form['views'][$name] = array(
          '#type' => 'select',
          '#title' => $view->human_name,
          '#options' => $domains,
          '#default_value' => !empty($views[$name]) ? $views[$name] : 0,
        );
      }
    }
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save configuration',
  );
  
  $form['#submit'][] = 'oho_domain_content_settings_submit';
  
  return $form;
}

/**
 * Submit handler for the oho_domain_content_settings form
 */
function oho_domain_content_settings_submit(&$form, &$form_state) {
  $variables = array(
    'vocabularies' => array(),
    'views' => array(),
  );
  
  foreach ($variables as $var => $arr) {
    $values = !empty($form_state['values'][$var]) ? $form_state['values'][$var] : array();
    
    foreach ($values as $key => $val) {
      $variables[$var][$key] = $val;
    }
  }
  
  variable_set('oho_domain_source_settings', $variables);
  
  drupal_set_message('Your configuration settings have been saved.');
}