<?php
/**
 * @file
 * psc_home.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function psc_home_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}