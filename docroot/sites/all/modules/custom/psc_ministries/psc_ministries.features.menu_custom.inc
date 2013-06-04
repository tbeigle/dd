<?php
/**
 * @file
 * psc_ministries.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function psc_ministries_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ministries-at-park-street.
  $menus['menu-ministries-at-park-street'] = array(
    'menu_name' => 'menu-ministries-at-park-street',
    'title' => 'Ministries at Park Street',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ministries at Park Street');


  return $menus;
}
