<?php

function clade_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'clade') .'/includes',
    ),
    'handlers' => array(
      // filter

      // field
			'clade_handler_field_clade_post_count_new' => array(
        'parent' => 'views_handler_field_numeric',
      ),
			'clade_handler_field_clade_last_post_date' => array(
        'parent' => 'views_handler_field_date',
      ),

      // argument
      'clade_subscriptions_handler_argument_clade_tid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      
      // sort
      'clade_handler_sort_clade_last_post_date' => array(
      	'parent' => 'views_handler_sort',
      ),
    ),
  );
}

function clade_views_plugins() {
	return array(
    'argument default' => array(
      'clade' => array(
        'title' => t('Current clade from context'),
        'handler' => 'clade_plugin_argument_default_clade_tid',
        'path' => drupal_get_path('module', 'clade') . '/includes',
        'parent' => 'fixed', // so that the parent class is included
      	),
    	),
		);
}

/**
 * Implementation of hook_views_data().
 */
function clade_views_data() {
	$data = array();
	$data['clade']['table']['group']  = t('Clade');
  $data['clade']['table']['join'] = array(
    'term_data' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
    'term_node' => array(
    	'left_field' => 'tid',
    	'field' => 'tid',
    ),
  );
  $data['clade']['active'] = array(
    'title' => t('Is the Clade active'),
    'help' => t('If the Clade is <em>active</em>.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
		'filter' => array(
			'handler' => 'views_handler_filter_boolean_operator',
			'label' => t('Active'),
			'type' => 'yes-no',
		),
    'sort' => array(
       'handler' => 'views_handler_sort',
    ),
  );
  $data['clade']['post_count_new'] = array(
		'title' => t('Post count *new*'),
		'field' => array(
			'handler' => 'clade_handler_field_clade_post_count_new',
			'click sortable' => TRUE,
			'help' => t('Number of new posts in a Clade for the current user.'),
		),
  );
  $data['clade']['last_post_date'] = array(
		'title' => t('Last Post/Comment Date'),
		'field' => array(
			'handler' => 'clade_handler_field_clade_last_post_date',
			'click sortable' => TRUE,
			'help' => t('The timestamp of the latest post or comment in this clade.'),
		),
    'sort' => array(
			'handler' => 'clade_handler_sort_clade_last_post_date',
			'help' => t('The timestamp of the latest post or comment in this clade.'),
    ),
  );
  // TODO url fields?

  return $data;
}
