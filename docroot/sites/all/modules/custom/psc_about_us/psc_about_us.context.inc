<?php
/**
 * @file
 * psc_about_us.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function psc_about_us_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about_us_main_blocks';
  $context->description = '';
  $context->tag = 'about';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/3' => 'node/3',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-video_about_psc' => array(
          'module' => 'boxes',
          'delta' => 'video_about_psc',
          'region' => 'masthead',
          'weight' => '-10',
        ),
        'nodeblock-5' => array(
          'module' => 'nodeblock',
          'delta' => '5',
          'region' => 'content',
          'weight' => '-1',
        ),
        'boxes-about_page_cta_block' => array(
          'module' => 'boxes',
          'delta' => 'about_page_cta_block',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('about');
  $export['about_us_main_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_pages_about_us';
  $context->description = 'Miscellaneous elements that appear on the about us internal pages.';
  $context->tag = 'about';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'about_us_section_page' => 'about_us_section_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'section_nav' => array(
      'section_nav_class' => '',
      'section_nav' => 'node/5|Statement of Faith
node/6|Bylaws
node/8|Membership',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Miscellaneous elements that appear on the about us internal pages.');
  t('about');
  $export['section_pages_about_us'] = $context;

  return $export;
}
