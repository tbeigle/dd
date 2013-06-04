<?php

/**
 * Expose themes as context reactions.
 */
class psc_site_context_reaction_section_class extends context_reaction {
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
      '#title' => t('Set Section Class'),
      'section_class' => array(
        '#title' => t('Section Class'),
        '#description' => t('Provides this as additional classes for the section tag.'),
        '#type' => 'textfield',
        '#maxlength' => 255,
        '#default_value' => isset($values['section_class']) ? $values['section_class'] : '',
      ),
    );
    return $form;
  }

  /**
   * Set 'section_class'
   */
  function execute(&$vars) {
    foreach ($this->get_contexts() as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['section_class']) && !isset($vars['section_class'])) {
        $vars['section_class'] = check_plain(t($v->reactions[$this->plugin]['section_class']));
      }
    }
  }
}
