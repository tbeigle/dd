<?php

/**
 * Include the preprocess functions
 */
foreach (glob(dirname(__FILE__) . '/includes/*/*.inc') as $filename) {
  include_once($filename);
}

/**
 * Implements hook_theme()
 */
function psc_theme($existing, $type, $theme, $path) {
  $psc = _psc_theme_global();
  
  $path = '/' . $psc['theme_path'] . '/templates/theme/';
  
  $theme = array();
  
  // Columns wrapper
  $theme['columnar_content_section'] = array(
    'variables' => array(
      'head' => array(
        'copy' => '',
        'tag' => 'h2',
        'attributes' => array(
          'classes' => array(
            'page-title',
            'page-title-secondary',
            'brand-alpha-black',
            'brand-standout',
          ),
        ),
      ),
      'wrappers' => array(
        array(
          'tag' => 'div',
          'attributes' => array(
            'class' => array(
              'segment',
              'wrapper',
              'separator',
            ),
          ),
        ),
      ),
      'content' => array(
        'wrappers' => array(),
        'columns' => array(),
      ),
    ),
    'template' => 'columnar-content-section',
    'path' => $path,
  );
  
  // Group of columns
  $theme['content_section_columns'] = array(
    'variables' => array(
      'wrappers' => array(
        array(
          'tag' => 'div',
          'attributes' => array(
            'class' => array(
              'group',
              'well-parent',
              'brand-alpha-light',
              'shim',
            ),
          ),
        ),
      ),
      'columns' => array(),
    ),
    'template' => 'content-section-columns',
    'path' => $path,
  );
  
  // Individual content column
  $theme['content_section_column'] = array(
    'variables' => array(
      'head' => array(
        'tag' => 'h3',
        'attributes' => array(
          'class' => array(
            'label',
            'label-focus',
            'label-icon',
            'label-icon-focus',
            'brand-standout',
          ),
        ),
        'copy' => NULL,
      ),
      'wrappers' => array(
        array(
          'tag' => 'div',
          'attributes' => array(
            'class' => array(
              'col',
            ),
          ),
        ),
        array(
          'tag' => 'div',
          'attributes' => array(
            'class' => array(
              'well',
              'well-match',
            ),
          ),
        ),
      ),
      'content' => NULL,
    ),
    'template' => 'content-section-column',
    'path' => $path,
  );
  
  // Global header
  $theme['global_header'] = array(
    'variables' => array(
      'messages' => NULL,
      'logo' => NULL,
      'front_page' => NULL,
      'page' => array(
        'header_left' => NULL,
        'header' => NULL,
      ),
      'main_menu' => NULL,
    ),
    'template' => 'global-header',
    'path' => $path,
  );
  
  // Global footer
  $theme['global_footer'] = array(
    'variables' => array(
      'footer_top' => NULL,
      'footer_mid' => NULL,
      'footer_bottom' => NULL,
    ),
    'template' => 'global-footer',
    'path' => $path,
  );
  
  return $theme;
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function psc_form_search_block_form_alter(&$form, &$form_state) {
  $form['#prefix'] = '<p class="search-toggle"><a class="icon icon-search" href="#search">'.t('Search').'</a></p>';
  $form['#id'] = 'search';
  
  _psc_set_class_array($form);
  
  $form['#attributes']['class'][] = 'header-search-form';
  $form['#attributes']['class'][] = 'infield-labels';
  
  $form['search_block_form']['#prefix'] =
    '<fieldset>' .
      '<legend>' .
        t('Search') .
      '</legend>';
  
  $form['search_block_form']['#suffix'] = '</fieldset>';
  
  $form['search_block_form']['#title'] = t('Search Park Street');
  $form['search_block_form']['#title_display'] = 'before';
  
  _psc_set_class_array($form['search_block_form']);
  
  $form['search_block_form']['#attributes']['class'][] = 'brand-beta-em';
  
  //$form['actions']['submit']['#type'] = 'button';
  $form['actions']['submit']['#attributes']['class'][] = 'ir';
  $form['actions']['submit']['#attributes']['class'][] = 'icon';
  $form['actions']['submit']['#attributes']['class'][] = 'icon-search';
  /*$form['actions']['submit']['#value'] = '<span class="visuallyhidden">' . t('Search') . '</span>';
  
  $form['actions']['submit']['#html_button'] = 1;*/
}

/**
 * Implements hook_comment_view_alter().
 */
function psc_comment_view_alter(&$build, $type) {
  //Removing the empty anchors, just do this in the div IDs
  $build['#prefix'] = preg_replace('/<a id="comment-[^>]+\><\/a>/i', '', $build['#prefix']);
}

/**
 * Switch a field from the $fields array to a new one so we can print manually
 * and leave the existing foreach in place.
 */
function psc_shift_views_field_array(&$fields, $manual_field_names = array()) {
  foreach ($manual_field_names as $manual_field_name) {
    if(isset($fields[$manual_field_name])) {
     $manual_fields[$manual_field_name] = $fields[$manual_field_name];
     unset($fields[$manual_field_name]);
    }
  }
  return $manual_fields;
}

/**
 * Build the #attributes and class arrays if they do not exist
 */
function _psc_set_class_array(&$vars) {
  if (!isset($vars['#attributes'])) $vars['#attributes'] = array();
  
  if (!isset($vars['#attributes']['class'])) $vars['#attributes']['class'] = array();
}

/**
 * Converts a string to a suitable html ID attribute.
 *
 * http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
 * valid ID attribute in HTML. This function:
 * 
 *   - Ensures an ID starts with an alpha character by optionally adding an 'n'.
 *   - Replaces any character except A-Z, numbers, and underscores with dashes.
 *   - Converts entire string to lowercase.
 * 
 * @param $string
 *   The string
 *
 * @return
 *   The converted string
 */
function _psc_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9_-]+/', '-', $string));
  // If the first character is not a-z, add 'n' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id'. $string;
  }
  return $string;
}

/**
 * Simple function to set and return the global $_psc variable
 */
function _psc_theme_global() {
  global $_psc;
  
  if (empty($_psc['theme_path'])) {
    $_psc['theme_path'] = drupal_get_path('theme', 'psc');
  }
  
  return $_psc;
}

/**
 * Themes menu links
 */
function _psc_theme_menu_link($vars, $assign_active = TRUE, $use_li = TRUE) {
  $element = $vars['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  
  if ($assign_active) {
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  } else {
    $output = _psc_l($element['#title'], $element['#href'], $element['#localized_options']);
  }
  
  if (isset($element['#localized_options']['attributes']['class'])) {
    $a_class = $element['#localized_options']['attributes']['class'];
    
    if (isset($element['#attributes']['class'])) {
      $element['#attributes']['class'] = $a_class;
    }
  }
  
  if ($use_li) {
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
  }
  else {
    return $output;
  }
}

/**
 * Custom function to replace Drupal's l() function so the "active" class is not assigned
 */
function _psc_l($text, $path, array $options = array()) {
  global $language_url;
  static $use_theme = NULL;

  // Merge in defaults.
  $options += array(
    'attributes' => array(),
    'html' => FALSE,
  );

  // Remove all HTML and PHP tags from a tooltip. For best performance, we act only
  // if a quick strpos() pre-check gave a suspicion (because strip_tags() is expensive).
  if (isset($options['attributes']['title']) && strpos($options['attributes']['title'], '<') !== FALSE) {
    $options['attributes']['title'] = strip_tags($options['attributes']['title']);
  }

  // Determine if rendering of the link is to be done with a theme function
  // or the inline default. Inline is faster, but if the theme system has been
  // loaded and a module or theme implements a preprocess or process function
  // or overrides the theme_link() function, then invoke theme(). Preliminary
  // benchmarks indicate that invoking theme() can slow down the l() function
  // by 20% or more, and that some of the link-heavy Drupal pages spend more
  // than 10% of the total page request time in the l() function.
  if (!isset($use_theme) && function_exists('theme')) {
    // Allow edge cases to prevent theme initialization and force inline link
    // rendering.
    if (variable_get('theme_link', TRUE)) {
      drupal_theme_initialize();
      $registry = theme_get_registry(FALSE);
      // We don't want to duplicate functionality that's in theme(), so any
      // hint of a module or theme doing anything at all special with the 'link'
      // theme hook should simply result in theme() being called. This includes
      // the overriding of theme_link() with an alternate function or template,
      // the presence of preprocess or process functions, or the presence of
      // include files.
      $use_theme = !isset($registry['link']['function']) || ($registry['link']['function'] != 'theme_link');
      $use_theme = $use_theme || !empty($registry['link']['preprocess functions']) || !empty($registry['link']['process functions']) || !empty($registry['link']['includes']);
    }
    else {
      $use_theme = FALSE;
    }
  }
  if ($use_theme) {
    return theme('link', array('text' => $text, 'path' => $path, 'options' => $options));
  }
  // The result of url() is a plain-text URL. Because we are using it here
  // in an HTML argument context, we need to encode it properly.
  return '<a href="' . check_plain(url($path, $options)) . '"' . drupal_attributes($options['attributes']) . '>' . ($options['html'] ? $text : check_plain($text)) . '</a>';
}

/**
 * Helper function to retrieve field values with those irritating nested arrays
 */
function _psc_get_field_value($field, $value_column = 'value', $default_value = '') {
  return !empty($field[LANGUAGE_NONE][0][$value_column]) ? $field[LANGUAGE_NONE][0][$value_column] : $default_value;
}

/**
 * Helper function to render opening and closing wrapper HTML elements
 */
function _psc_render_html_wrappers(&$wrappers) {
  $wrappers_prefix = $wrappers;
  $wrappers_suffix = array_reverse($wrappers_prefix);
  
  $wrappers = array(
    'open' => '',
    'close' => '',
  );
  
  foreach ($wrappers_prefix as $open) {
    $wrappers['open'] .= '<' . $open['tag'] . drupal_attributes($open['attributes']) . '>';
  }
  
  foreach ($wrappers_suffix as $close) {
    $wrappers['close'] .= '</' . $close['tag'] . '>';
  }
}

/**
 * Builds column wrapper classes based on node type
 */
function _psc_cols_wrapper_class($type, $section_entity, $has_section_title = TRUE) {
  $output = array();
  $cols_count = count($section_entity->field_content_section_col[LANGUAGE_NONE]);
  
  if ($cols_count > 1) {
    $output[] = 'group';
  }
  
  switch ($type) {
    case 'about_us_section_page': {
      if ($has_section_title) {
        $output[] = 'separator';
      }
      
      $output[] = 'hentry';
      
      if ($cols_count == 1) {
        $output[] = 'focal';
      }
      break;
    }
    case 'section_landing_page': {
      $output[] = 'well-parent';
      $output[] = 'brand-alpha-light';
      $output[] = 'shim';
      $output[] = 'cols-about-overview';
      break;
    }
    default: {
    }
  }
  
  if (!empty($section_entity->field_content_section_col[LANGUAGE_NONE])) {
    
    $output[] = 'col-wrapper-' . count($section_entity->field_content_section_col[LANGUAGE_NONE]);
  }
  
  return $output;
}
/**
 * Builds colum section variables
 */
function _psc_build_col_section($fc, $type) {
  $output = array();
  
  $section_entity = $fc['#entity'];
  $has_title = (!empty($fc['field_content_section_col_head']) || !empty($fc['field_content_section_col_subhd']));
  
  $items = $fc['field_content_section_col']['#items'];
  
  $cols_wrapper_class = _psc_cols_wrapper_class($type, $section_entity, $has_title);
  
  if (!empty($section_entity->field_content_section_col_head)) {
    $output['head'] = array(
      'copy' => _psc_get_field_value($section_entity->field_content_section_col_head),
      'tag' => _psc_get_field_value($section_entity->field_content_section_col_html, 'value', 'h2'),
      'attributes' => array(
        'class' => array(),
      ),
    );
    
    if (!empty($section_entity->field_content_section_col_hclass)) {
      $output['head']['attributes']['class'] = explode(' ', $section_entity->field_content_section_col_hclass[LANGUAGE_NONE][0]['value']);
    }
  }
  
  $output['wrappers'] = array();
  
  if ($type == 'about_us_section_page') {
    $output['head']['prefix'] = '<header class="meta-header">';
    $output['head']['suffix'] = '</header>';
    
    if (!empty($section_entity->field_content_section_col_subhd)) {
      $output['subhead'] = _psc_get_field_value($section_entity->field_content_section_col_subhd);
    }
  } elseif ($type == 'section_landing_page') {
    $output['wrappers'][] = array(
      'tag' => 'div',
      'attributes' => array(
        'class' => array(
          'segment',
          'wrapper',
          'separator',
        ),
      ),
    );
  }
  
  $output['content'] = array(
    'wrappers' => array(
      array(
        'tag' => 'div',
        'attributes' => array(
          'class'=> $cols_wrapper_class,
        ),
      ),
    ),
    'columns' => array(),
  );
  
  _psc_build_col_section_cols($output, $fc, $type);
  
  if (empty($output['content']['columns'])) $output = NULL;
  
  return $output;
}

/**
 * Buids content section columns variables
 */
function _psc_build_col_section_cols(&$section, $fc, $type) {
  $col_items = $fc['field_content_section_col']['#items'];
  $counter = 1;
  
  if ($type == 'ministry_detail') {
    $section['content']['wrappers'][0]['attributes']['class'][] = 'hentry';
  }
  
  foreach ($col_items as $col_key => $col_info) {
    $col_id = !empty($col_info['value']) ? $col_info['value'] : 0;
    
    if (!empty($col_id)) {
      if (!empty($fc['field_content_section_col'][$col_key]['entity']['field_collection_item'][$col_id]['#entity'])) {
        $fc_col = $fc['field_content_section_col'][$col_key]['entity']['field_collection_item'][$col_id];
        $col_entity = $fc_col['#entity'];
        
        $col_num = $counter;
        $counter++;
        
        $col_head = !empty($col_entity->field_content_section_col_head) ? $col_entity->field_content_section_col_head : array();
        $col_head_html = !empty($col_entity->field_content_section_col_html) ? $col_entity->field_content_section_col_html : array();
        $col_head_class = !empty($col_entity->field_content_section_col_hclass) ? $col_entity->field_content_section_col_hclass : array();
        $col_copy = !empty($col_entity->field_content_section_col_copy) ? $col_entity->field_content_section_col_copy : array();
        
        $head_copy = _psc_get_field_value($col_head);
        $content = _psc_get_field_value($col_copy);
        
        if (empty($head_copy) && empty($content)) continue;
        
        $col_head_classes = _psc_get_field_value($col_head_class, 'value', 'label label-focus label-icon label-icon-focus brand-standout');
        $col_head_classes_array = explode(' ', $col_head_classes);
        
        $column = array(
          'head' => array(
            'copy' => $head_copy,
            'tag' => _psc_get_field_value($col_head_html, 'value', 'h3'),
            'attributes' => array(
              'class' => $col_head_classes_array,
            ),
          ),
          'content' => $content,
          'wrappers' => array(
            array(
              'tag' => 'div',
              'attributes' => array(
                'class' => array(
                  'col',
                  'col-' . $col_num,
                ),
              ),
            ),
          ),
        );
        
        if ($type == 'section_landing_page') {
          $column['wrappers'][] = array(
            'tag' => 'div',
            'attributes' => array(
              'class' => array(
                'well',
                'well-match',
              ),
            ),
          );
        }
        
        $section['content']['columns'][] = $column;
      }
    }
  }
}

/**
 * Implements hook_field_group_pre_render().
 *
 * Last resort to alter the pre_render build.
 */
function psc_field_group_pre_render_alter(&$element, $group, &$form) {
  $groups_check = array(
    'group_pos_vol_info_dis_contact',
    'group_pos_vol_info_dis',
  );
  
  if (!in_array($group->group_name, $groups_check)) return;
  
  if ($group->group_name == 'group_pos_vol_info_dis_contact') {
    $element['#prefix'] .= '<ul>';
    $suffix = '</ul>' . $element['#suffix'];
    $element['#suffix'] = $suffix;
  }
}
