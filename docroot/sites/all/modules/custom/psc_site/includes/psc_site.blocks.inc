<?php

/**
 * Implements hook_block_info()
 */
function psc_site_block_info() {
  return array(
    'psc_site_footer_info' => array(
      'info' => t('Footer Information'),
    ),
    'psc_site_home_slideshow' => array(
      'info' => t('Slideshow for the Home Page'),
    ),
  );
}

/**
 * Implements hook_block_configure()
 */
function psc_site_block_configure($delta = '') {
  $form = array();
  
  switch ($delta) {
    // Footer
    case 'psc_site_footer_info': {
      $psc_fi = variable_get('psc_site_footer_info', array());
      
      $form['psc_site'] = array(
        '#tree' => TRUE,
      );
      
      $form['psc_site']['address'] = array(
        '#type' => 'textfield',
        '#title' => t('Address'),
        '#default_value' => !empty($psc_fi['address']) ? $psc_fi['address'] : '',
      );
      
      $form['psc_site']['phone'] = array(
        '#type' => 'textfield',
        '#title' => t('Phone Number'),
        '#default_value' => !empty($psc_fi['phone']) ? $psc_fi['phone'] : '',
      );
      
      $form['psc_site']['email'] = array(
        '#type' => 'textfield',
        '#title' => t('Email'),
        '#default_value' => !empty($psc_fi['email']) ? $psc_fi['email'] : '',
      );
      
      $form['psc_site']['copyright'] = array(
        '#type' => 'textfield',
        '#title' => t('Copyright Text'),
        '#default_value' => !empty($psc_fi['copyright']) ? $psc_fi['copyright'] : '',
        '#description' => t('If you would like to have the copyright year always set to the current year simply enter "--Y--" where the year should appear. Also, enter "--C--" wherever you would like the copyright symbol to appear.'),
      );
      break;
    }
    // Home slideshows
    case 'psc_site_home_slideshow': {
      $psc_home_ss_val = variable_get('psc_site_field_slideshows_value', array('home' => 'home'));
      
      $form['psc_site'] = array(
        '#tree' => TRUE,
      );
      
      $form['psc_site']['field_slideshows_value'] = array(
        '#type' => 'textfield',
        '#title' => t('Home Slideshow Field Key'),
        '#default_value' => !empty($psc_home_ss_val['home']) ? $psc_home_ss_val['home'] : '',
      );
      break;
    }
  }
  
  return $form;
}

/**
 * Implements hook_block_save()
 */
function psc_site_block_save($delta = '', $edit = array()) {
  switch ($delta) {
    // Footer
    case 'psc_site_footer_info': {
      $info = !empty($edit['psc_site']) ? $edit['psc_site'] : '';
      
      if (!empty($info)) {
        variable_set('psc_site_footer_info', $info);
      }
      break;
    }
    // Home Slideshow
    case 'psc_site_home_slideshow': {
      $field_slideshows_value = !empty($edit['psc_site']['field_slideshows_value']) ? $edit['psc_site']['field_slideshows_value'] : '';
      
      if (!empty($field_slideshows_value)) {
        $field_slideshows_var = variable_get('psc_site_field_slideshows_value', array());
        
        $field_slideshows_var['home'] = $field_slideshows_value;
        
        variable_set('psc_site_field_slideshows_value', $field_slideshows_var);
      }
      break;
    }
  }
}

/**
 * Implements hook_block_view()
 */
function psc_site_block_view($delta = '') {
  $block = array();
  
  switch ($delta) {
    // Footer
    case 'psc_site_footer_info': {
      $info = variable_get('psc_site_footer_info', array());
      $block['subject'] = '';
      $block['content'] = array(
        '#tree' => TRUE,
        '#prefix' => '<div class="wrapper group copyright">',
        '#suffix' => '</div>',
      );
      
      $contact = array();
      
      if (!empty($info['address'])) {
        $contact[] = $info['address'];
      }
      
      if (!empty($info['phone'])) {
        $contact[] = $info['phone'];
      }
      
      if (!empty($info['email'])) {
        $contact[] = l($info['email'], 'mailto:' . $info['email']);
      }
      
      if (!empty($contact)) {
        $block['content']['contact'] = array(
          '#markup' => implode(' <b class="bull">&bull;</b> ', $contact),
          '#prefix' => '<p class="brand-alpha brand-standout">',
          '#suffix' => '</p>',
        );
      }
      
      if (!empty($info['copyright'])) {
        $block['content']['copyright'] = array(
          '#markup' => str_replace('--C--', '&copy;', str_replace('--Y--', date('Y'), $info['copyright'])),
          '#prefix' => '<p class="brand-beta">',
          '#suffix' => '</p>',
        );
      }
      
      break;
    }
    // Home Slideshow
    case 'psc_site_home_slideshow': {
      $field_slideshows_var = variable_get('psc_site_field_slideshows_value', array());
      
      if (!empty($field_slideshows_var['home'])) {
        $home_slides = array(
          'items' => array(),
          'type' => 'ul',
          'title' => '',
          'attributes' => array(
            'class' => array(
              'slides',
            ),
          ),
        );
        
        $sql =
          'SELECT ' .
            's.`entity_type` AS `entity_type`, ' .
            's.`bundle` AS `bundle`, ' .
            's.`entity_id` AS `entity_id` ' .
          'FROM {field_data_field_slideshows} s ' .
            'LEFT JOIN {field_data_field_weight} w ' .
              'ON  s.`entity_type` = w.`entity_type` ' .
                'AND s.`bundle` = w.`bundle` ' .
                'AND s.`entity_id` = w.`entity_id` ' .
          'WHERE s.`field_slideshows_value` = :field_slideshows_value ' .
          'ORDER BY w.`field_weight_value`;';
        $results = db_query($sql, array(':field_slideshows_value' => $field_slideshows_var['home']));
        
        foreach ($results as $row) {
          $entities = entity_load($row->entity_type, array($row->entity_id));
          $entity = reset($entities);
          
          if ($row->entity_type == 'slideshow_slide') {
            $item = array(
              'class' => array('group'),
            );
            
            $item['data'] = '<div class="segment segment-alt pre-segment-nav segment-page-masthead masthead-hero"';
            
            if (!empty($entity->field_image[LANGUAGE_NONE][0]['uri'])) {
              $image_path = file_create_url($entity->field_image[LANGUAGE_NONE][0]['uri']);
              
              if (!empty($image_path)) {
                $item['data'] .= ' style="background-image: url(' . $image_path . ');"';
              }
            }
            
            $item['data'] .= '>';
            
            if (!empty($entity->field_slide_content[LANGUAGE_NONE][0]['value'])) {
              $item['data'] .= $entity->field_slide_content[LANGUAGE_NONE][0]['value'];
            }
            
            $item['data'] .= '</div>';
          } elseif ($row->entity_type == 'calendar') {
            $item = '<div class="wrapper"><div class="event group">';
            
            if (!empty($entity->field_event_image[LANGUAGE_NONE][0]['uri'])) {
              $image_path = file_create_url($entity->field_event_image[LANGUAGE_NONE][0]['uri']);
              
              if (!empty($image_path)) {
                $item .=
                  '<div class="event-poster">' .
                    '<a href="#">' .
                      '<image src="' . $image_path . '" width="460" alt="' . $entity->title . '">' .
                    '</a>' .
                  '</div>';
              }
            }
            
            $time = strtotime($entity->field_event_date[LANGUAGE_NONE][0]['value']);
            
            $item .= 
              '<div class="event-content">' .
                '<h3 class="brand-standout title">' . $entity->title . '</h3>' .
                '<ul class="event-meta">' .
                  '<li class="event-meta-date">' . 
                    '<dl class="meta-definition">' .
                      '<dt class="brand-alpha-black brand-standout">' .
                        t('Date') .
                      '</dt>' .
                      '<dd class="brand-alpha-light">' .
                        date('F j, Y', $time) .
                      '</dd>' .
                    '</dl>' .
                  '</li>' .
                  '<li class="event-meta-time">' .
                    '<dl class="meta-definition">' .
                      '<dt class="brand-alpha-black brand-standout">' .
                        t('Time') .
                      '</dt>' .
                      '<dd class="brand-alpha-light">' .
                        date('h:ia', $time) .
                      '</dd>' .
                    '</dl>' .
                  '</li>' .
                  '<li class="event-meta-location">' .
                    '<a class="button button-nav button-nav-toggle button-mini" href="#">Details</a>' .
                  '</li>' .
                '</ul>' .
              '</div>';
            
            $item .= '</div></div>';
          }
          
          if (!empty($item)) {
            $home_slides['items'][] = $item;
          }
        }
        
        $block['subject'] = '';
        $block['content'] = _psc_site_theme_item_list($home_slides);
      }
      
      break;
    }
  }
  
  return $block;
}
