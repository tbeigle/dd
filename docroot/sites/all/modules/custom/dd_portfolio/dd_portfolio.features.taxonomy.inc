<?php
/**
 * @file
 * dd_portfolio.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dd_portfolio_taxonomy_default_vocabularies() {
  return array(
    'comps' => array(
      'name' => 'Client Companies',
      'machine_name' => 'comps',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'contacts' => array(
      'name' => 'Company Contacts',
      'machine_name' => 'contacts',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
