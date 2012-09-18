<?php

function ibphelper_drush_command() {
	$items = array();
	
	$items['ibphelper-menus'] = array(
		'callback' => 'ibphelper_setup_menus',
		'description' => 'Set up some menus stuff for crops',
		'aliases' => array('ibphmenu'),
	);
	
	$items['ibphelper-clear-menus'] = array(
		'callback' => 'ibphelper_clear_menus',
		'description' => 'Set up some menus stuff for crops',
	);
	
	return $items;
}

function ibphelper_drush_help($section) {
  switch ($section) {
    case 'drush:ibphelper-menus':
      return dt('Set up some menus stuff for crops.');
  }
}

function ibphelper_clear_menus() {
	$result = db_query("SELECT mlid FROM menu_links where link_path regexp '^clade/[0-9]+/.*'");
	while ($mlid = db_result($result)) {
		menu_link_delete($mlid);
	}

  $result = db_query("SELECT mlid FROM menu_links WHERE link_path IN ('news','events')");
  while ($mlid = db_result($result)) {
    $links = db_query("SELECT mlid FROM menu_links WHERE plid = %d", $mlid);
    while ($child_mlid = db_result($links)) {
      menu_link_delete($child_mlid);
    }
  }

  $result = db_query("SELECT nid FROM node where type = 'story' OR type = 'event'");
  while ($nid = db_result($result)) {
    node_save(node_load($nid));
  }

}

/* better active menu handling now in clade module, don't need these menus anymore */
// function ibphelper_setup_menus() {
// 	$clades = taxonomy_get_tree(variable_get('clade_vocabulary',0));
// 	foreach ($clades as $clade) {
// 		$clade_menu = menu_get_item("clade/$clade->tid");
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/digest"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/digest"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/digest',
// 					'link_path' => "clade/$clade->tid/digest",
// 					'link_title' => $clade->name . ' digest',
// 					'weight' => 9,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/blog"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/blog"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/blog',
// 					'link_path' => "clade/$clade->tid/blog",
// 					'link_title' => $clade->name . ' blog',
// 					'weight' => 10,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/forums"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/forums"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/forums',
// 					'link_path' => "clade/$clade->tid/forums",
// 					'link_title' => $clade->name . ' forum',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/publications"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/publications"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/publications',
// 					'link_path' => "clade/$clade->tid/publications",
// 					'link_title' => $clade->name . ' publications',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/members"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/members"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/members',
// 					'link_path' => "clade/$clade->tid/members",
// 					'link_title' => $clade->name . ' members',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/members/list"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/members/list"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/members/list',
// 					'link_path' => "clade/$clade->tid/members/list",
// 					'link_title' => $clade->name . ' members/list',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/members/faces"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/members/faces"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/members/faces',
// 					'link_path' => "clade/$clade->tid/members/faces",
// 					'link_title' => $clade->name . ' members/faces',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/members/join"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/members/join"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/members/join',
// 					'link_path' => "clade/$clade->tid/members/join",
// 					'link_title' => $clade->name . ' members/join',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/post/add"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/post/add"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/post/add',
// 					'link_path' => "clade/$clade->tid/post/add",
// 					'link_title' => $clade->name . ' post/add',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/edit"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/edit"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/edit',
// 					'link_path' => "clade/$clade->tid/edit",
// 					'link_title' => $clade->name . ' edit',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/edit/links"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/edit/links"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/edit/links',
// 					'link_path' => "clade/$clade->tid/edit/links",
// 					'link_title' => $clade->name . ' edit/links',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 		if (menu_valid_path(array('link_path'=>"clade/$clade->tid/documents"))) {
// 			$existing = db_result(db_query("SELECT mlid FROM {menu_links} WHERE link_path = '%s'", "clade/$clade->tid/documents"));
// 			if (! $existing) {
// 				$menu = array(
// 					'menu_name' => 'primary-links',
// 					'plid' => $clade_menu['mlid'],
// 					'router_path' => 'clade/%/documents',
// 					'link_path' => "clade/$clade->tid/documents",
// 					'link_title' => $clade->name . ' documents',
// 					'weight' => 11,
// 					);
// 				menu_link_save($menu);
// 			}
// 		}
// 	}
// }