<?php

function oho_basic_responsive_theme($existing, $type, $theme, $path) {
 $path = drupal_get_path('theme', 'oho_basic_responsive') . '/templates/custom';
 
 return array(
  'oho_filtered_list_header' => array(
    'variables' => array('msg' => 'Displaying all posts for: ', 'filters' => array(), 'view_all_msg' => 'View all items &raquo;', 'view_all_link' => ''),
   ),
 );
}

function oho_basic_responsive_oho_filtered_list_header($vars) {
  $output = '';
  
  if(isset($vars['filters'])) {
    $filters = implode(', ', $vars['filters']);
    
    $output = '<div class="filtered-list-header clearfix">';
    $output .= '<span>' . $vars['msg'] . '<strong>' . $filters . '</strong></span>';
    $output .= '<a class="unfilter-link" href="' . $vars['view_all_link'] . '">' . $vars['view_all_msg'] . '</a>';
    $output .= '</div>';
  }
  
  return $output;
}

function oho_basic_responsive_preprocess_page(&$vars) {
  //Fluid 12 Col Grid, 4.4% Gutter, 60px Col width
  if (!empty($vars['page']['sidebar_first']) && empty($vars['page']['sidebar_second'])) {
    $vars['sb_first_grid_classes'] = 'four columns';
    $vars['content_grid_classes'] = 'eight columns';
  }
  if (empty($vars['page']['sidebar_first']) && !empty($vars['page']['sidebar_second'])) {
    $vars['content_grid_classes'] = 'eight columns';
    $vars['sb_second_grid_classes'] = 'four columns';
  } 
  if (!empty($vars['page']['sidebar_first']) && !empty($vars['page']['sidebar_second'])) {
    $vars['sb_first_grid_classes'] = 'three columns';
    $vars['sb_second_grid_classes'] = 'three columns';
    $vars['content_grid_classes'] = 'six columns';
  }
  if (empty($vars['page']['sidebar_first']) && empty($vars['page']['sidebar_second'])) {
    $vars['content_grid_classes'] = 'twelve columns';
  }
  
  // Work-around a stupid bug in Drupal 7 - Borrowed from Adaptive Theme
  if (arg(0) == 'user' && arg(1) == 'login') {
    drupal_set_title(t('User login'));
  }
  if (arg(0) == 'user' && arg(1) == 'password') {
    drupal_set_title(t('Request new password'));
  }
  if (arg(0) == 'user' && arg(1) == 'register') {
    drupal_set_title(t('Create new account'));
  }
  
}


function oho_basic_responsive_preprocess_block(&$vars) {
  //Something to distinguish this title from others in the block
  $vars['title_attributes_array']['class'][] = 'title';
  
  //If blocktheme exists and the block has the require variable
  //add it to the class array
  if (module_exists('blocktheme') && isset($vars['blocktheme'])) {
   $vars['classes_array'][] = 'blocktheme-' . $vars['blocktheme'];
  }
}

//Implements template_preprocess_html()

//forces rendering using the latest engine
function oho_basic_responsive_preprocess_html(&$vars) {
  // Add IE HTML classes and meta tag if the browser is IE
  $ua = $_SERVER['HTTP_USER_AGENT'];
  $ie_class_arr = array(
    7 => 'ie7 lte7 lte8 lte9 lte10 ie',
    8 => 'ie8 lte8 lte9 lte10 ie',
    9 => 'ie9 lte9 lte10 ie',
    10 => 'ie10 lte10 ie',
  );
  
  $meta_versions = array(7,8,9);
  
  $ie_classes = '';
  
  if (preg_match('/MSIE ([0-9]+)/', $ua, $matches)) {
    if (in_array($matches[1], $meta_versions)) {
      $element = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
          'http-equiv' => 'X-UA-Compatible',
          'content' => 'IE=edge,chrome=1',
        ),
        '#weight'=> -60,
      );
    }
    
    drupal_add_html_head($element, 'ie_meta');
    
    if (!empty($ie_class_arr[$matches[1]])) {
      $ie_classes = $ie_class_arr[$matches[1]];
    }
  }
  
  $vars['html_ie_classes'] = $ie_classes;
  
  // Add the viewport meta tag
  $_meta = array(
    '#tag' => 'meta',
    '#attributes' => array(
       'name'=> 'viewport',
       'content' => 'width=device-width, initial-scale=1.0'
    ),
  );
  
  drupal_add_html_head($_meta, 'viewport_meta');
  
  //Add helper classes for Mac & PC platform
  $user_agent = $_SERVER['HTTP_USER_AGENT'];
	if (stripos($user_agent, 'macintosh')) {
		$vars['classes_array'][] = 'platform-mac';
	} else if (stripos($user_agent, 'windows')) {
		$vars['classes_array'][] = 'platform-windows';
	}
	
}

//Override to allow boxes to act like blocks and hide boxes when there is no content
//Modified from boxes.admin
function oho_basic_responsive_boxes_box($variables) {
  $block = $variables['block'];
  
  $empty = '';
  
  // Box is empty
  if (!empty($block['content'])) {
    $output = "<div id='boxes-box-" . $block['delta'] . "' class='boxes-box" . (!empty($block['editing']) ? ' boxes-box-editing' : '') . $empty . "'>";
    $output .= '<div class="boxes-box-content">' . $block['content'] . '</div>';
    //This is usually where the box controls are, removed as we don't use them
    if (!empty($block['editing'])) {
      $output .= '<div class="box-editor">' . drupal_render($block['editing']) . '</div>';
    }
    $output .= '</div>';
  }
  
  return $output;
}

/**
 * Implements hook_preprocess_comments().
 */
function oho_basic_responsive_preprocess_comment(&$vars) {
 // Adding comment IDs to the comment wrapper div instead of using empty a tags
 // @see oho_basic_responsive_comment_view_alter
 $vars['attributes_array']['id'][] = 'comment-' . $vars['comment']->cid;
}

/**
 * Implements hook_comment_view_alter().
 */
function oho_basic_responsive_comment_view_alter(&$build, $type) {
  //Removing the empty anchors, just do this in the div IDs
  $build['#prefix'] = preg_replace('/<a id="comment-[^>]+\><\/a>/i', '', $build['#prefix']);
}

//	
//	Converts a string to a suitable html ID attribute.
//	
//	 http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
//	 valid ID attribute in HTML. This function:
//	
//	- Ensure an ID starts with an alpha character by optionally adding an 'n'.
//	- Replaces any character except A-Z, numbers, and underscores with dashes.
//	- Converts entire string to lowercase.
//	
//	@param $string
//	  The string
//	@return
//	  The converted string
//	


function oho_basic_responsive_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9_-]+/', '-', $string));
  // If the first character is not a-z, add 'n' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id'. $string;
  }
  return $string;
}

/**
 * Switch a field from the $fields array to a new one so we can print manually
 * and leave the existing foreach in place.
 */
function oho_basic_responsive_shift_views_field_array(&$fields, $manual_field_names = array()) {
  foreach ($manual_field_names as $manual_field_name) {
    if(isset($fields[$manual_field_name])) {
     $manual_fields[$manual_field_name] = $fields[$manual_field_name];
     unset($fields[$manual_field_name]);
    }
  }
  return $manual_fields;
}
