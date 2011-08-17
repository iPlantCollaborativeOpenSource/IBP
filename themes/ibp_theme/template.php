<?php
/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to ibp_theme_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: ibp_theme_breadcrumb()
 *
 *   where ibp_theme is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


/**
 * Implementation of HOOK_theme().
 */
function ibp_theme_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  // Add your theme hooks like this:
  /*
  $hooks['hook_name_here'] = array( // Details go here );
  */
  // @TODO: Needs detailed comments. Patches welcome!
  
  $hooks['loginlinks'] = array(
		'arguments' => array(
			'user' => NULL,
			),
  	);
  $hooks['user_login'] = array(
    'template' => 'templates/user_login',
    'arguments' => array('form' => NULL),
		);
  $hooks['flag'] = array(
    'arguments' => array('code' => NULL),
		);
  $hooks['user_flag'] = array(
    'arguments' => array('account' => NULL),
		);
  return $hooks;
}

function ibp_theme_loginlinks($user) {
	$items = array();
	if ($user->uid) {
		$items[] = t("<span class='loginstatus'>You are logged in as <strong>@user</strong></span>", array("@user" => $user->name));
		// TODO My Links
		$mylinks = array();
		$mylinks[] = l(t('My Saved Pages'), "user/$user->uid/my-ibp-pages");
		$mylinks[] = l(t('My Communities'), 'community');
		$mylinks[] = l(t('My Issue Tracker'), 'issues');
		$mylinks[] = l(t('My Account'), 'user');
		$items[] = array(
			'data' => theme('item_list', $mylinks, t('My Links'), 'ul'),
			'id' => 'my-links'
			);
		drupal_add_js(drupal_get_path('theme', 'ibp_theme') . 'js/my-links.js', 'theme');
		$items[] = l(t('Log out'), 'logout');
	} else {
		$items[] = l(t('Register for an account'), 'user/register', array('attributes'=>array('target'=>'_blank')));
		$items[] = l(t('Log in'), 'user/login', array('query' => drupal_get_destination()));
	}
	return theme('item_list', $items, NULL, 'ul', array('class' => 'loginlinks'));
}

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function ibp_theme_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function ibp_theme_preprocess_page(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');

  // To remove a class from $classes_array, use array_diff().
  //$vars['classes_array'] = array_diff($vars['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function ibp_theme_preprocess_node(&$vars, $hook) {
	$node = $vars['node'];
	
  // Optionally, run node-type-specific preprocess functions, like
  // ibp_theme_preprocess_node_page() or ibp_theme_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $node->type;
  if (function_exists($function)) {
    $function($vars, $hook);
  }
  
  // add css per node type
  drupal_add_css(drupal_get_path('theme','ibp_theme').'/css/node-'.$node->type.'.css');

	if ($node->type == 'training_page') {
		// don't show training types in taxonomy links
		$vocabs = taxonomy_get_vocabularies();
		$training_vocab = 0;
		$clade_vocab = variable_get('clade_vocabulary',0);
		foreach ($vocabs as $v) {
			if ($v->name == 'Training types') {
				$training_vocab = $v->vid;
			}
		}
		$training_terms = array_keys(taxonomy_node_get_terms_by_vocabulary($node, $training_vocab));
		$links = array();
		foreach ($node->taxonomy as $tid => &$term) {
			if ($term->vid == $training_vocab) {
				continue;
			} else if ($term->vid == $clade_vocab) {
				$links[] = array(
						'title' => $term->name,
						'href' => 'training/' . $training_terms[0] . '/' . $term->tid,
						'attributes' => array(
							'rel' => 'tag', 
							'title' => strip_tags($term->description),
						));
			} else {
				$links[] = array(
						'title' => $term->name,
						'href' => taxonomy_term_path($term),
						'attributes' => array(
							'rel' => 'tag', 
							'title' => strip_tags($term->description),
						));
			}
		}
		$vars['terms'] = theme('links', $links, array('class' => 'links inline terms'));
	} else if ($node->type == 'ibp_tool') {
		drupal_add_js(drupal_get_path('theme','ibp_theme').'/js/ibp_tool.js');
	}
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function ibp_theme_preprocess_comment(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function ibp_theme_preprocess_block(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

function ibp_theme_links($links, $attributes = array('class' => 'links'), $heading = '') {
	if ($links['node_read_more']) {
		$links['node_read_more']['title'] = t('Continue reading');
	}
	
	if (strpos(array_shift(array_keys($links)), 'taxonomy_term') === 0) {
		$attributes['class'] .= ' terms';
	}
	
	return theme_links($links, $attributes, $heading);
}
// */

// fix menutrails for views http://drupal.org/node/340725#comment-3753404
function ibp_theme_preprocess_views_view(&$vars){
	$view=$vars['view'];
	$menu_item = menu_get_item();
	if ($menu_item['page_callback'] == 'views_page'){
		//only for page display
		$term_trails = variable_get('menutrails_terms', array());
		$term=$view->args[0];
		$current_path = drupal_get_normal_path($_GET['q']);
		if (!empty($term_trails[$term])) {
			//only if exists in menutrails_terms
			$menu_item['href'] = $term_trails[$term];
			menu_set_item($current_path,$menu_item);
		}
	}
}

function ibp_theme_preprocess_user_profile(&$vars) {
	global $user;
	$account = $vars['account'];
	if ($account->uid == $user->uid) {
		drupal_set_title(t('My profile'));
	}
	else if (module_exists('profile')) {
		profile_load_profile($account);
		$name = $account->profile_first_name;
		if ($account->profile_middle_name) {
			$name .= ' ' . $account->profile_middle_name;
		}
		$name .= ' ' . $account->profile_last_name;
		drupal_set_title($name .'\'s Profile');
	}
	
	if (module_exists('clade_subscriptions')) {
		$vars['communities'] = implode(', ',
				array_map(
					function($c) {
						$tid = $c['tid'];
						$clade = l($c['name'], "clade/$tid");
						if ($c['is_admin']) {
							$clade .= '*';
						}
						return $clade;
					},
				$account->clades)
			);
	}
	
	drupal_add_css(drupal_get_path('theme','ibp_theme').'/css/user_profile.css', 'theme');
}

function ibp_theme_user_flag($account) {
	if (module_exists('profile') && module_exists('countries_api')) {
		profile_load_profile($object);
		$countries = $countries = countries_api_get_array('printable_name', 'iso2');
		if ($countries[$account->profile_country]) {
			$flag = theme('flag', $countries[$account->profile_country]);
		}
	}
	return $flag;
}

function ibp_theme_flag($code) {
	return '<span class="flag '.strtolower($code).'"></span>';
}

function ibp_theme_username($object) {
	if ($object->uid && $object->name) {
		if (module_exists('profile')) {
			profile_load_profile($object);
			$name = $object->profile_first_name;
			if ($object->profile_middle_name) {
				$name .= ' ' . $object->profile_middle_name;
			}
			$name .= ' ' . $object->profile_last_name;
			$name = trim($name);
			
			if (module_exists('countries_api')) {
				$countries = $countries = countries_api_get_array('printable_name', 'iso2');
				if ($countries[$object->profile_country]) {
					$flag = theme('flag', $countries[$object->profile_country]);
				}
			}
		}
		
		if (empty($name)) {
			$name = $object->name;
		}
		
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($name) > 20) {
      $name = drupal_substr($name, 0, 15) . '...';
    }

    if (user_access('access user profiles')) {
      $name = l($name, 'user/' . $object->uid, array('title' => t('View user profile.')));
    }
    else {
      $name = check_plain($name);
    }
    
    $output = $flag.$name;
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if ($object->homepage) {
      $output = l($object->name, $object->homepage);
    }
    else {
      $output = check_plain($object->name);
    }

    $output .= ' (' . t('not verified') . ')';
  }
  else {
    $output = variable_get('anonymous', t('Anonymous'));
  }

  return $output;
}

function ibp_theme_preprocess_faq_category_questions_top(&$variables) {
	static $added = FALSE;
	if (! $added) {
		$added = TRUE;
		drupal_add_css(drupal_get_path('theme', 'ibp_theme') . '/css/ibp_faq.css', 'theme');
		drupal_add_js(drupal_get_path('theme', 'ibp_theme') . '/js/ibp_faq.js', 'theme');
	}
}

function ibp_theme_filefield_icon($file) {
	global $base_url;

  if (is_object($file)) {
    $file = (array) $file;
  }
  $mime = check_plain($file['filemime']);
  $dashed_mime = strtr($mime, array('/' => '-', '+' => '-'));
  
  if ($icon_path = _ibp_theme_filefield_icon_path($file)) {
  	$icon_url = $base_url . '/' . $icon_path;
    return '<img class="filefield-icon field-icon-'. $dashed_mime .'"  alt="'. t('@mime icon', array('@mime' => $mime)) .'" src="'. $icon_url .'" />';
  } else {
  	return theme_filefield_icon($file);
  }
}

function _ibp_theme_filefield_icon_path($file) {
	$dir = drupal_get_path('theme', 'ibp_theme') . '/images/filefield/';
	$dashed_mime = strtr($file['filemime'], array('/' => '-'));
	
	$path = $dir.$dashed_mime.'.png';
	if (file_exists($path)) {
		return $path;
	}
	
	if ($generic_name = _filefield_generic_icon_map($file)) {
		$path = $dir.$generic_name.'.png';
		if (file_exists($path)) {
			return $path;
		}
	}
	
	foreach (array('audio', 'image', 'text', 'video') as $category) {
		if (strpos($file['filemime'], $category .'/') === 0) {
			$path = $dir.$category.'-x-generic'.'.png';
			if (file_exists($path)) {
				return $path;
			}
		}
	}
	
	// Try application-octet-stream as last fallback.
	$path = $dir.'application-octet-stream'.'.png';
	if (file_exists($path)) {
		return $path;
	}
	
	return NULL;
}

function ibp_theme_preprocess_user_login(&$vars) {
	$vars['form'] = drupal_render($vars['form']);
	$vars['pass_reset_url'] = 'https://auth.iplantcollaborative.org/account_management/request_reset.py';
}