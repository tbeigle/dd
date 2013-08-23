<?php

/**
 * Implements template_preprocess_html()
 */
function dd_preprocess_html(&$vars) {
  $vars['html_shiv'] = '/';
  
  if (!empty($vars['directory'])) {
    $vars['html_shiv'] .= trim($vars['directory'], '/');
  }
  else {
    $vars['html_shiv'] .= trim(drupal_get_path('theme', 'dd'), '/');
  }
  
  $vars['html_shiv'] .= '/scripts/js/html5shiv.js';
}

/**
 * Implements template_preprocess_page()
 */
function dd_preprocess_page(&$vars) {
  $toggle_breadcrumb = theme_get_setting('toggle_breadcrumb', 'dd');
  $vars['hide_breadcrumb'] = !empty($toggle_breadcrumb);
}
