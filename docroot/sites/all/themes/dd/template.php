<?php
/**
 * @file template.php
 */

/**
 * Implements template_preprocess_block().
 */
function dd_preprocess_block(&$vars) {
  if (!empty($vars['blocktheme'])) {
    if ($vars['is_front'] && $vars['block']->region == 'content') {
      if (!in_array('scrollto-section', $vars['classes_array'])) {
        $vars['classes_array'][] = 'scrollto-section';
      }
      
      if ($vars['blocktheme'] !== 'port') {
        if (!in_array('container', $vars['classes_array'])) $vars['classes_array'][] = 'container';
        
        if ($vars['blocktheme'] == 'wwa') {
          $tp = _dd_theme_path();
          $vars['img_path'] = $tp . '/assets/images/logo-wwa.png';
        }
      }
    }
  }
}

/**
 * Implements template_preprocess_html().
 */
function dd_preprocess_html(&$vars) {
  if (empty($vars['classes_array'])) $vars['classes_array'] = array();
  if (!in_array('no-overlay', $vars['classes_array'])) $vars['classes_array'][] = 'no-overlay';
  
  // Meta viewport header
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1',
    ),
  );
  
  drupal_add_html_head($element, 'meta_viewport');
}

/**
 * Implements template_preprocess_node().
 */
function dd_preprocess_node(&$vars) {
  if (variable_get('node_submitted_' . $vars['node']->type, TRUE)) {
    $date = format_date($vars['node']->created);
    $vars['submitted'] =
      '<div class="submitted-details author">' .
        t('By !username', array('!username' => $vars['name'])) .
      '</div>' .
      '<div class="submitted-details date-posted">' .
        $date .
      '</div>';
  }
}

/**
 * Implements template_preprocess_page().
 */
function dd_preprocess_page(&$vars) {
  $vars['show_title'] = !$vars['is_front'] && empty($vars['node']);
  
  // Social media links
  $tp = _dd_theme_path();
  $imgs_path = $tp . '/assets/images/';
  $vars['dd_sm'] = array(
    'Facebook' => array(
      'img' => url($imgs_path . 'sm-facebook.jpg'),
      'url' => 'https://www.facebook.com/DesignatedDevelopers',
    ),
    'LinkedIn' =>  array(
      'img' => url($imgs_path . 'sm-linkedin.jpg'),
      'url' => 'https://www.linkedin.com/company/designated-developers',
    ),
    'Twitter' =>  array(
      'img' => url($imgs_path . 'sm-twitter.jpg'),
      'url' => 'https://twitter.com/desdevelopers',
    ),
  );
  
  if ($vars['is_front'] && !empty($vars['page']['content']['system_main'])) {
    $sm = $vars['page']['content']['system_main'];
    
    if (!empty($sm['default_message'])) {
      unset($vars['page']['content']['system_main']);
    }
  }
  
  if (!$vars['is_front']) {
    if (empty($vars['logo'])) {
      $vars['logo'] = url($imgs_path . 'logo-watermark.png', array('absolute' => TRUE));
    }
  }
}

/**
 * Helper function for retrieving the path to the theme.
 */
function _dd_theme_path() {
  global $_dd_theme_path;
  
  if (!isset($_dd_theme_path)) {
    $_dd_theme_path = drupal_get_path('theme', 'dd');
  }
  
  return $_dd_theme_path;
}
