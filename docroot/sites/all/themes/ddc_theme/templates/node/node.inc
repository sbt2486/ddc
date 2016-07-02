<?php
/**
 * @file
 * Node template functions.
 */

use \Drupal\ddc_custom\EntityWrapper\Node\NodeWrapper;

/**
 * Implements hook_preprocess_node().
 */
function ddc_theme_preprocess_node(&$variables) {
  $node_type = $variables['node']->type;

  // We want to theme nodes by type and display mode.
  $variables['theme_hook_suggestions'][] = 'node__' . $node_type . '__' . $variables['view_mode'];

  $function_names = array(
    'ddc_theme_preprocess_node__' . $node_type . '__' . $variables['view_mode'],
    'ddc_theme_preprocess_node__' . $node_type,
  );

  foreach ($function_names as $function_name) {
    if (function_exists($function_name)) {
      $function_name($variables);
    }
  }
}

/**
 * Implements pre-processing for article content rendered in teaser view mode.
 */
function ddc_theme_preprocess_node__article__teaser(&$variables) {
  // Create linked title.
  $variables['linked_title'] = l($variables['title'], 'node/' . $variables['nid']);

  $node_wrapper = new NodeWrapper($variables['node']);
  // Check for highlighted option and add classes in case it's set.
  if ($node_wrapper->articleIsHighlighted()) {
    $variables['classes_array'][] = 'article-highlighted';
  }
}

/**
 * Implements pre-processing for article content rendered in full view mode.
 */
function ddc_theme_preprocess_node__article__full(&$variables) {
  if ($variables['uid']) {
    $node_wrapper = new NodeWrapper($variables['node']);
    $variables['author'] = $node_wrapper->renderNodeAuthor();
  }
}
