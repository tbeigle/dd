<?php
/**
 * @file
 * psc_ministries.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function psc_ministries_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ministry_detail_blocks';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ministry_detail' => 'ministry_detail',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-a1afcabf82abdc48f2eb685bbfc823f8' => array(
          'module' => 'views',
          'delta' => 'a1afcabf82abdc48f2eb685bbfc823f8',
          'region' => 'masthead',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['ministry_detail_blocks'] = $context;

  return $export;
}
