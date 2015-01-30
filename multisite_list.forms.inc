<?php

/**
 * @file
 * Multisite list module,
 * forms.
 */

function multisite_list_admin_form() {
  module_load_include('inc', 'multisite_list');
  $form = array();

  // Site list
  $sites = multisite_list_get_full_sites_list();
  $options = array();
  foreach ($sites as $domain => $site) {
    $options[$domain] = $site['name'];
  }
  $form['multisite_list_sites_display'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Which sites form this multisite installation should be displayed in your site list?'),
    '#options' => $options,
    '#default_value' => variable_get('multisite_list_sites_display', array()),
  );

  // Default display for new sites
  $form['multisite_list_new_site_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Should new sites be display automatically in your site list when created?'),
    '#description' => t('If not, you will have to manually add new sites to your site list by checking them below.'),
    '#default_value' => variable_get('multisite_list_new_site_display', FALSE),
  );

  return system_settings_form($form);
}
