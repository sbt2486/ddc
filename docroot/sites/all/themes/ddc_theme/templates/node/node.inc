<?php
/**
 * @file
 * Node template functions.
 */

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

function ddc_theme_preprocess_node__article__teaser(&$variables) {

  // Create linked title.
  $variables['linked_title'] = l($variables['title'], 'node/' . $variables['nid']);

  // Check for highlighted option and add classes in case it's set.
  if (ddc_custom_article_is_highlighted($variables['node'])) {
    $variables['classes_array'][] = 'article-highlighted';
  }
}

/**
 * Implements pre-processing for article content rendered in full view mode.
 */
function ddc_theme_preprocess_node__article__full(&$variables) {
  if ($variables['uid']) {
    $account = user_load($variables['uid']);

    // Retrieve all profile fields and attach to $account->content.
    user_build_content($account);
    $user_profile = $account->content;
    // We don't need duplicate rendering info in account->content.
    unset($account->content);
    $user_profile += array(
      '#theme' => 'user_profile',
      '#account' => $account,
    );
    $variables['author'] = drupal_render($user_profile);
  }
}
