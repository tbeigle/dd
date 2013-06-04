<?php
/**
 * @file
 * psc_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function psc_global_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'four_col_shim_page';
  $context->description = '';
  $context->tag = 'page templates';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ministries' => 'ministries',
      ),
    ),
  );
  $context->reactions = array(
    'page_tpl' => array(
      'title' => 'page__four_col_shim',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page templates');
  $export['four_col_shim_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_elements';
  $context->description = 'Miscellaneous elements that appear sitewide.';
  $context->tag = 'common';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-logo-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-logo-menu',
          'region' => 'header_left',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-9',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'footer_top',
          'weight' => '-10',
        ),
        'menu-menu-footer-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-navigation',
          'region' => 'footer_top',
          'weight' => '-9',
        ),
        'views-81b85408d79e9a93ab4fb678d1aee70e' => array(
          'module' => 'views',
          'delta' => '81b85408d79e9a93ab4fb678d1aee70e',
          'region' => 'footer_mid',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'footer_mid',
          'weight' => '-9',
        ),
        'psc_site-psc_site_footer_info' => array(
          'module' => 'psc_site',
          'delta' => 'psc_site_footer_info',
          'region' => 'footer_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Miscellaneous elements that appear sitewide.');
  t('common');
  $export['global_elements'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'left_sidebar_nav_from_footer';
  $context->description = '';
  $context->tag = 'sidebar';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'jobs:jobs_page_main' => 'jobs:jobs_page_main',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sidebar');
  $export['left_sidebar_nav_from_footer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'page_booster_class';
  $context->description = 'Assigns the page-booster class to the section tag on selected pages.';
  $context->tag = 'section classes';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/3' => 'node/3',
      ),
    ),
    'views' => array(
      'values' => array(
        'jobs:jobs_page_main' => 'jobs:jobs_page_main',
      ),
    ),
  );
  $context->reactions = array(
    'section_class' => array(
      'section_class' => 'page-booster',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assigns the page-booster class to the section tag on selected pages.');
  t('section classes');
  $export['page_booster_class'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'segment_page_four_col_shim_class';
  $context->description = '';
  $context->tag = 'top segment class';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ministries:page' => 'ministries:page',
      ),
    ),
  );
  $context->reactions = array(
    'first_segment_class' => array(
      'title' => 'segment wrapper',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('top segment class');
  $export['segment_page_four_col_shim_class'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'segment_page_masthead_class';
  $context->description = '';
  $context->tag = 'top segment class';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/3' => 'node/3',
      ),
    ),
  );
  $context->reactions = array(
    'first_segment_class' => array(
      'title' => 'segment segment-alt segment-page-masthead',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('top segment class');
  $export['segment_page_masthead_class'] = $context;

  return $export;
}
