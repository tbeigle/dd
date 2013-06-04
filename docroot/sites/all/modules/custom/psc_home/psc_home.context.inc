<?php
/**
 * @file
 * psc_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function psc_home_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_blocks';
  $context->description = 'Blocks for the homepage.';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'psc_site-psc_site_home_slideshow' => array(
          'module' => 'psc_site',
          'delta' => 'psc_site_home_slideshow',
          'region' => 'masthead',
          'weight' => '-10',
        ),
        'menu-menu-ministries-at-park-street' => array(
          'module' => 'menu',
          'delta' => 'menu-ministries-at-park-street',
          'region' => 'content_secondary',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for the homepage.');
  t('home');
  $export['home_blocks'] = $context;

  return $export;
}
