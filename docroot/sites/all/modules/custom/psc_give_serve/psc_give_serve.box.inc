<?php
/**
 * @file
 * psc_give_serve.box.inc
 */

/**
 * Implements hook_default_box().
 */
function psc_give_serve_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box_bottom_cta_give_serve';
  $box->plugin_key = 'simple';
  $box->title = 'Serve a Ministry';
  $box->description = 'Bottom CTA block on the give / serve pages.';
  $box->options = array(
    'body' => array(
      'value' => '<p>Learn more about <a href="#">Serving a Ministry</a> at Park Street Church with your time and talents.</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['box_bottom_cta_give_serve'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'masthead_give_serve';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Masthead image for the Give / Serve pages';
  $box->options = array(
    'body' => array(
      'value' => '<img alt="masthead-2_0.jpg" height="315" src="/sites/default/files/masthead-2_0.jpg" width="958" />
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['masthead_give_serve'] = $box;

  return $export;
}
