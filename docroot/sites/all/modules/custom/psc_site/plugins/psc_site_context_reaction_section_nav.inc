<?php

/**
 * Expose themes as context reactions.
 */
class psc_site_context_reaction_section_nav extends context_reaction {
  /**
   * Editor form.
   */
  function editor_form($context) {
  }

  /**
   * Submit handler for editor form.
   */
  function editor_form_submit($context, $values) {
    return $values;
  }

  /**
   * Allow admins to provide a section title, section subtitle and section class.
   */
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    
    $form = array(
      '#tree' => TRUE,
      '#title' => t('Set Internal Section Navigation'),
      'section_nav_class' => array(
        '#title' => t('Additional Classes'),
        '#description' => t('Enter a space-separated list of classes you would like applied to the section navigation wrapper.'),
        '#type' => 'textfield',
        '#maxlength' => 255,
        '#default_value' => isset($values['section_nav_class']) ? $values['section_nav_class'] : '',
      ),
      'section_nav' => array(
        '#title' => t('Nav Items'),
        '#description' => t('Enter line-separated menu items. Enter a URL and some anchor text for each menu item separated by a pipe symbol like so, "node/1|Node Title".'),
        '#type' => 'textarea',
        '#cols' => 30,
        '#rows' => 3,
        '#default_value' => isset($values['section_nav']) ? $values['section_nav'] : '',
      ),
    );
    return $form;
  }

  /**
   * Set 'section_class'
   */
  function execute(&$vars) {
    foreach ($this->get_contexts() as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['section_nav']) && !isset($vars['section_nav'])) {
        $classes_array = array(
          'segment-alt',
          'segment-nav',
        );
        
        if (!empty($v->reactions[$this->plugin]['section_nav_class'])) {
          $section_nav_class = $v->reactions[$this->plugin]['section_nav_class'];
          
          if (strpos($section_nav_class, ' ')) {
            $classes_array += explode(' ', $section_nav_class);
          } else {
            $classes_array[] = $section_nav_class;
          }
        }
        
        $output = array(
          '#markup' => '',
          '#prefix' =>
            '<div class="' . implode(' ', $classes_array) . '">' .
              '<div class="wrapper">' .
                '<ul>',
          '#suffix' =>
                '</ul>' .
              '</div>' .
            '</div>',
        );
        
        $path = $_GET['q'];
        $path_alias = drupal_get_path_alias($path);
        $nav_items = explode("\n", $v->reactions[$this->plugin]['section_nav']);
        
        foreach ($nav_items as $key => $data) {
          $menu_item = explode('|', $data);
          
          if (empty($menu_item[0]) || empty($menu_item[1])) continue;
          $href = $menu_item[0];
          $text = $menu_item[1];
          
          $link_options = array(
            'attributes' => array(
              'class' => array(
                'button',
                'button-nav',
              ),
            ),
          );
          
          $output['#markup'] .= '<li';
          
          $strpos_with_args = strpos($path, $href . '/');
          
          if ($href == $path || $href == $path_alias || ($strpos_with_args == 0 && $strpos_with_args !== FALSE)) {
            $output['#markup'] .= ' class="current"';
            $link_options['attributes']['class'][] = 'current';
          }
          
          $output['#markup'] .= '>' . l($text, $href, $link_options) . '</li>';
        }
        
        $vars['section_nav'] = $output;
      }
    }
  }
}
