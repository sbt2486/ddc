<?php

$master_stage_modules = array(
  'admin_views',
  'coder',
  'coder_review',
  'dblog',
  'devel',
  'devel_generate',
  'diff',
  'features_ui',
  'field_ui',
  'strongarm',
  'views_ui',
  'navbar',
);

$master_local_modules = array_merge(
  $master_stage_modules,
  array('admin_menu', 'views_bulk_operations', 'entity')
);

$conf['install_profile'] = 'standard';
$conf['master_version'] = 2;
$conf['master_modules'] = array(
  'base' => array(
    'coffee',
    'shortcut',
    'search',
    'rdf',
    'path',
    'number',
    'menu',
    'list',
    'libraries',
    'help',
    'contextual',
    'comment',
    'color',
    'block',
    'strongarm',
    'features',
    'fe_block',

    // Customizations.
    // Contrib modules.
    'date',
    'date_popup',
    'date_views',
    'date_api',

    // Custom modules.
    'ddc_custom',

    //Features
    'ddc_article',
    'ddc_block',
    'ddc_common',
    'ddc_filter',
    'ddc_homepage',
    'ddc_image',
    'ddc_permission',
    'ddc_system',
  ),
  'local' => $master_local_modules,
  'dev' => $master_local_modules,
  'test' => $master_stage_modules,
  'prod' => array(),
);
$conf['master_uninstall_blacklist'] = array(
  'base' => array(
    'stage_file_proxy',
    'inese_migrate',
  ),
  'local' => array(),
  'prod' => array(),
);
$conf['master_removable_blacklist'] = array(
  0 => 'modules/*',
);
