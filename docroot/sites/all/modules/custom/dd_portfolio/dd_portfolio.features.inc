<?php
/**
 * @file
 * dd_portfolio.features.inc
 */

/**
 * Implements hook_node_info().
 */
function dd_portfolio_node_info() {
  $items = array(
    'portfolio' => array(
      'name' => t('Portfolio Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
