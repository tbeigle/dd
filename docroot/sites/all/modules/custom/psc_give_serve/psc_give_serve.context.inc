<?php
/**
 * @file
 * psc_give_serve.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function psc_give_serve_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_give_serve';
  $context->description = 'Blocks for the give and serve pages';
  $context->tag = 'give / serve';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/11' => 'node/11',
      ),
    ),
    'views' => array(
      'values' => array(
        'positions:serve' => 'positions:serve',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-masthead_give_serve' => array(
          'module' => 'boxes',
          'delta' => 'masthead_give_serve',
          'region' => 'masthead',
          'weight' => '-10',
        ),
        'boxes-box_bottom_cta_give_serve' => array(
          'module' => 'boxes',
          'delta' => 'box_bottom_cta_give_serve',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
    'section_nav' => array(
      'section_nav_class' => 'segment-nav-give-serve',
      'section_nav' => 'node/11|Give Financially
serve|Serve a Ministry
',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for the give and serve pages');
  t('give / serve');
  $export['blocks_give_serve'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'page_tpl_give_serve';
  $context->description = '';
  $context->tag = 'page templates';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/11' => 'node/11',
      ),
    ),
    'views' => array(
      'values' => array(
        'positions:serve' => 'positions:serve',
      ),
    ),
  );
  $context->reactions = array(
    'page_tpl' => array(
      'title' => 'page__give_serve',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page templates');
  $export['page_tpl_give_serve'] = $context;

  return $export;
}
