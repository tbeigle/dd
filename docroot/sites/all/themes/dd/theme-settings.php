<?php
function dd_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['toggle_breadcrumb'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Breadcrumb'),
    '#default_value' => theme_get_setting('toggle_breadcrumb'),
  );
}
?>
