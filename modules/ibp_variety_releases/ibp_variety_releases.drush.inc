<?php

function ibp_variety_releases_drush_command() {
	$items = array();
	
	$items['ibp-variety-release-cck'] = array(
		'callback' => 'ibp_variety_releases_setup_content_type',
		'description' => 'Set up the IBP Project content type',
		'aliases' => array('ibpvcck'),
	);
	
	$items['ibp-variety-release-menus'] = array(
		'callback' => 'ibp_variety_releases_setup_menus',
		'description' => 'Set up IBP Project menus for crops',
		'aliases' => array('ibpvmenu'),
	);
	
	return $items;
}

function ibp_variety_releases_drush_help($section) {
  switch ($section) {
    case 'drush:ibp-proj-cck':
      return dt("Set up the IBP Variety Release CCK content type.");
    case 'drush:ibp-proj-menus':
      return dt('Set up IBP Variety Release menus for crops.');
  }
}


function ibp_variety_releases_setup_content_type() {
	module_load_include("inc","ibp_variety_releases","includes/ibp_variety_release.content_type");
	$values = array();
	$values['type_name'] = 'ibp_variety_release';
	$content = _ibp_variety_releases_ibp_variety_release_content_type_def();
	$values['macro'] = '$content = ' . var_export($content, TRUE) . ';';
	$form_state = array();
	$form_state['values'] = $values;
	drupal_execute("content_copy_import_form", $form_state);
	content_clear_type_cache();
}

function ibp_variety_releases_setup_menus() {
	$clades = taxonomy_get_tree(variable_get('clade_vocabulary',0));
	foreach ($clades as $clade) {
		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/variety-releases"))) {
			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/variety-releases"));
			if ($existing) {
				// already exists
				continue;
			}
			$clade_menu = menu_get_item("clade/$clade->tid");
			$menu = array(
				'menu_name' => 'primary-links',
				'plid' => $clade_menu['mlid'],
				'router_path' => 'clade/%/variety-releases',
				'link_path' => "clade/$clade->tid/variety-releases",
				'link_title' => $clade->name . ' variety releases',
				'weight' => 14,
				);
			menu_link_save($menu);
		}
	}
}