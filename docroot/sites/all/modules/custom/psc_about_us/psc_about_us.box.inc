<?php
/**
 * @file
 * psc_about_us.box.inc
 */

/**
 * Implements hook_default_box().
 */
function psc_about_us_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'about_page_cta_block';
  $box->plugin_key = 'simple';
  $box->title = 'More About Park Street';
  $box->description = 'Bottom CTA block on the about us page.';
  $box->options = array(
    'body' => array(
      'value' => '<p>Learn more about our <a href="#">Belief &amp; Bylaws</a> as well as <a href="#">Membership</a> at Park Street Church.</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['about_page_cta_block'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'video_about_psc';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Video for the about page masthead';
  $box->options = array(
    'body' => array(
      'value' => '<div class="focal video video-med">
	<iframe allowfullscreen="" frameborder="0" height="720" src="http://www.youtube.com/embed/Ip4CEiem8O4" width="1280"></iframe></div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['video_about_psc'] = $box;

  return $export;
}
