<?php

/**
 * @file
 * Multisite list module,
 * helper functions.
 */


function multisite_list_get_full_sites_list() {
  global $base_url;
  dsm($base_url);
  require 'sites/sites.php';
  $sites_list = array();

  // For each site, let's get his name and url
  foreach ($sites as $domain => $folder) {
    require 'sites/' . $folder . '/settings.php';
    $sites_list[$domain] = array(
      'name' => (isset($conf['site_name'])) ? $conf['site_name'] : variable_get('site_name', NULL),
      'current' => ($domain == 1) ? TRUE : FALSE,
    );
  }

  return $sites_list;
}
