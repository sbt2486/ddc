<?php
/**
 * @file
 * ddc_basic_page.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ddc_basic_page_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_basic-page:node/add/basic-page
  $menu_links['navigation_basic-page:node/add/basic-page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/basic-page',
    'router_path' => 'node/add/basic-page',
    'link_title' => 'Basic page',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>basic pages</em> for your static content, such as an \'About us\' page.',
      ),
      'identifier' => 'navigation_basic-page:node/add/basic-page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic page');

  return $menu_links;
}
