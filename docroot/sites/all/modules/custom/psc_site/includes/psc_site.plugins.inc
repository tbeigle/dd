<?php

/**
 * Implement hook_ctools_plugin_api().
 */
function psc_site_ctools_plugin_api($module, $api) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * CTools plugin API hook for Context. Note that a proper entry in
 * hook_ctools_plugin_api() must exist for this hook to be called.
 */
function psc_site_context_plugins() {
  $plugins = array();
  
  $plugins['psc_site_context_reaction_first_segment_class'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'psc_site') . '/plugins',
      'file' => 'psc_site_context_reaction_first_segment_class.inc',
      'class' => 'psc_site_context_reaction_first_segment_class',
      'parent' => 'context_reaction',
    ),
  );
  
  $plugins['psc_site_context_reaction_page_tpl'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'psc_site') . '/plugins',
      'file' => 'psc_site_context_reaction_page_tpl.inc',
      'class' => 'psc_site_context_reaction_page_tpl',
      'parent' => 'context_reaction',
    ),
  );
  
  $plugins['psc_site_context_reaction_section_class'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'psc_site') .'/plugins',
      'file' => 'psc_site_context_reaction_section_class.inc',
      'class' => 'psc_site_context_reaction_section_class',
      'parent' => 'context_reaction',
    ),
  );
  
  $plugins['psc_site_context_reaction_section_nav'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'psc_site') . '/plugins',
      'file' => 'psc_site_context_reaction_section_nav.inc',
      'class' => 'psc_site_context_reaction_section_nav',
      'parent' => 'context_reaction',
    ),
  );
  
  return $plugins;
}

/**
 * Registry hook for conditions & reactions.
 *
 * Each entry associates a condition or reaction with the CTools plugin to be
 * used as its plugin class.
 */
function psc_site_context_registry() {
  return array(
    'reactions' => array(
      'first_segment_class' => array(
        'title' => t('First Segment Class'),
        'description' => t('Enter classes to applied to the first .segment div.'),
        'plugin' => 'psc_site_context_reaction_first_segment_class',
      ),
      'page_tpl' => array(
        'title' => t('Page Theme Hook Suggestion'),
        'description' => t('Enter a theme hook suggestion if there is a specific page .tpl file you wish to use.'),
        'plugin' => 'psc_site_context_reaction_page_tpl',
      ),
      'section_class' => array(
        'title' => t('Section Class'),
        'description' => t('Enter classes to be applied to the section.'),
        'plugin' => 'psc_site_context_reaction_section_class',
      ),
      'section_nav' => array(
        'title' => t('Content Section Navigation'),
        'description' => t('Enter items to be used for an internal section navigation.'),
        'plugin' => 'psc_site_context_reaction_section_nav',
      ),
    ),
  );
}
