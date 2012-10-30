<?php


/**
 * Return a description of the profile for the initial installation screen.
 *
 * @return
 *   An array with keys 'name' and 'description' describing this profile,
 *   and optional 'language' to override the language selection for
 *   language-specific profiles.
 */
function ibp_profile_details() {
  return array(
    'name' => 'IBP',
    'description' => 'Select this profile to install the Integrated Breeding Platform Drupal Portal.'
  );
}


function ibp_profile_modules() {
  return array(
		// core modules
		'block', 'filter', 'node', 'system', 'user',
	);
}

function ibp_profile_task_list() {
	return array(
		'enable_contrib_modules' => st('Enable contrib modules'),
		'enable_custom_modules' => st('Enable custom modules'),
		'set_variables' => st('Set variables')
	);
}

function ibp_profile_tasks(&$task, $url) {
	if ($task == 'profile') {
		$task = 'enable_contrib_modules';

		$modules = parse_ini_file(drupal_get_path('profile', 'ibp') . '/ibp_modules.info');
		drupal_install_modules($modules['contrib']);

		$task = 'enable_custom_modules';

		$modules = parse_ini_file(drupal_get_path('profile', 'ibp') . '/ibp_modules.info');
		drupal_install_modules($modules['custom']);

		$task = 'set_variables';

		$variables = parse_ini_file(drupal_get_path('profile','ibp').'/ibp_variables.info');
		foreach ($variables as $name => $value) {
			variable_set($name, $value);
		}

		$task = 'profile-finished';
	}
}