<?php

function ibphelper_drush_command() {
	$items = array();
	
	$items['ibphelper-menus'] = array(
		'callback' => 'ibphelper_setup_menus',
		'description' => 'Set up some menus stuff for crops',
		'aliases' => array('ibphmenu'),
	);
	
	return $items;
}

function ibphelper_drush_help($section) {
  switch ($section) {
    case 'drush:ibphelper-menus':
      return dt('Set up some menus stuff for crops.');
  }
}

function ibphelper_setup_menus() {
	$clades = taxonomy_get_tree(variable_get('clade_vocabulary',0));
	foreach ($clades as $clade) {
		$clade_menu = menu_get_item("clade/$clade->tid");
		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/digest"))) {
			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/digest"));
			if (! $existing) {
				$menu = array(
					'menu_name' => 'primary-links',
					'plid' => $clade_menu['mlid'],
					'router_path' => 'clade/%/digest',
					'link_path' => "clade/$clade->tid/digest",
					'link_title' => $clade->name . ' digest',
					'weight' => 9,
					);
				menu_link_save($menu);
			}
		}
		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/blog"))) {
			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/blog"));
			if (! $existing) {
				$menu = array(
					'menu_name' => 'primary-links',
					'plid' => $clade_menu['mlid'],
					'router_path' => 'clade/%/blog',
					'link_path' => "clade/$clade->tid/blog",
					'link_title' => $clade->name . ' blog',
					'weight' => 10,
					);
				menu_link_save($menu);
			}
		}
		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/forums"))) {
			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/forums"));
			if (! $existing) {
				$menu = array(
					'menu_name' => 'primary-links',
					'plid' => $clade_menu['mlid'],
					'router_path' => 'clade/%/forums',
					'link_path' => "clade/$clade->tid/forums",
					'link_title' => $clade->name . ' forum',
					'weight' => 11,
					);
				menu_link_save($menu);
			}
		}
	}
}