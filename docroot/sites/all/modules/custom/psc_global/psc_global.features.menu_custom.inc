<?php
/**
 * @file
 * psc_global.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function psc_global_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer-navigation.
  $menus['menu-footer-navigation'] = array(
    'menu_name' => 'menu-footer-navigation',
    'title' => 'Footer Navigation',
    'description' => '',
  );
  // Exported menu: menu-logo-menu.
  $menus['menu-logo-menu'] = array(
    'menu_name' => 'menu-logo-menu',
    'title' => 'Logo Menu',
    'description' => 'This menu contains the links that should appear immediately to the right of the logo.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Navigation');
  t('Logo Menu');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('This menu contains the links that should appear immediately to the right of the logo.');


  return $menus;
}
