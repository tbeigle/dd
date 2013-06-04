<?php

/**
 * Expose themes as context reactions.
 */
class psc_site_context_reaction_first_segment_class extends context_reaction {
  /**
   * Editor form.
   */
  function editor_form($context) {
    $form = $this->options_form($context);

    // Hide descriptions which take up too much space.
    unset($form['title']['#description']);
    unset($form['subtitle']['#description']);
    unset($form['class']['#description']);
    return $form;
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
      '#title' => t('First Segment Class'),
      'title' => array(
        '#title' => t('Segment Class'),
        '#description' => t('Provides this as additional classes for the first segment div tag.'),
        '#type' => 'textfield',
        '#maxlength' => 255,
        '#default_value' => isset($values['title']) ? $values['title'] : '',
      ),
    );
    return $form;
  }

  /**
   * Set 'section_class'
   */
  function execute(&$vars) {
    $classes = array();
    foreach ($this->get_contexts() as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['title']) && !isset($vars['first_segment_class'])) {
        $vars['first_segment_class'] = check_plain(t($v->reactions[$this->plugin]['title']));
      }
    }
  }
}
