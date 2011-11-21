<?php

function ibp_projects_drush_command() {
	$items = array();
	
	$items['ibp-proj-cck'] = array(
		'callback' => 'ibp_projects_setup_content_type',
		'description' => 'Set up the IBP Project content type',
		'aliases' => array('ibppcck'),
	);
	
	$items['ibp-proj-menus'] = array(
		'callback' => 'ibp_projects_project_setup_menus',
		'description' => 'Set up IBP Project menus for crops',
		'aliases' => array('ibppmenu'),
	);
	
	return $items;
}

function ibp_projects_drush_help($section) {
  switch ($section) {
    case 'drush:ibp-proj-cck':
      return dt("Set up the IBP Project content type.");
    case 'drush:ibp-proj-menus':
      return dt('Set up IBP Project menus for crops.');
  }
}


function ibp_projects_setup_content_type() {
	module_load_include("inc","ibp_projects","includes/ibp_project.content_type");
	$values = array();
	$values['type_name'] = 'ibp_project';
	$content = _ibp_projects_ibp_project_content_type_def();
	$values['macro'] = '$content = ' . var_export($content, TRUE) . ';';
	$form_state = array();
	$form_state['values'] = $values;
	drupal_execute("content_copy_import_form", $form_state);
	content_clear_type_cache();
}

function ibp_projects_project_setup_menus() {
	$clades = taxonomy_get_tree(variable_get('clade_vocabulary',0));
	foreach ($clades as $clade) {
		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/projects"))) {
			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/projects"));
			if ($existing) {
				// already exists
				continue;
			}
			$clade_menu = menu_get_item("clade/$clade->tid");
			$menu = array(
				'menu_name' => 'primary-links',
				'plid' => $clade_menu['mlid'],
				'router_path' => 'clade/%/projects',
				'link_path' => "clade/$clade->tid/projects",
				'link_title' => $clade->name . ' projects',
				'weight' => 15,
				);
			menu_link_save($menu);
		}
	}
}