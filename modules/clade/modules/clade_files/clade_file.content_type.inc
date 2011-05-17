$content['type'] = array (
	'name' => 'File',
	'type' => 'clade_file',
	'description' => 'A file upload associated with a Clade.',
	'title_label' => 'Title',
	'body_label' => 'Body',
	'min_word_count' => '0',
	'help' => '',
	'node_options' => 
	array (
		'status' => true,
		'promote' => true,
		'sticky' => false,
		'revision' => false,
	),
	'language_content_type' => '0',
	'addthis_nodetype' => 1,
	'old_type' => 'clade_file',
	'orig_type' => 'clade_file',
	'module' => 'clade_files',
	'custom' => '0',
	'modified' => '1',
	'locked' => '1',
	'reset' => 'Reset to defaults',
	'content_profile_use' => 0,
	'comment' => '2',
	'comment_default_mode' => '2',
	'comment_default_order' => '2',
	'comment_default_per_page' => '50',
	'comment_controls' => '3',
	'comment_anonymous' => 0,
	'comment_subject_field' => '1',
	'comment_preview' => '0',
	'comment_form_location' => '1',
	'teaserthumbnail' => '0',
	'teaserthumbnail_attachment' => 0,
	'teaserthumbnail_teaser' => '1',
	'teaserthumbnail_rss' => '1',
	'teaserthumbnail_link' => 1,
	'teaserthumbnail_align' => '0',
	'teaserthumbnail_preset' => '',
	'teaserthumbnail_min_height' => '',
	'teaserthumbnail_min_width' => '',
	'location_addanother' => 0,
	'ant' => '0',
	'ant_pattern' => '',
	'auto_nodetitle_php' => 0,
	'notifications_content_type' => 
	array (
		'thread' => true,
		'nodetype' => true,
		'author' => true,
		'taxonomy' => false,
		'typeauthor' => false,
	),
);
$content['groups']  = array (
	0 => 
	array (
		'label' => 'File info',
		'group_type' => 'standard',
		'settings' => 
		array (
			'form' => 
			array (
				'style' => 'fieldset',
				'description' => '',
			),
			'display' => 
			array (
				'description' => '',
				'teaser' => 
				array (
					'format' => 'fieldset',
					'exclude' => 0,
				),
				'full' => 
				array (
					'format' => 'fieldset',
					'exclude' => 0,
				),
				4 => 
				array (
					'format' => 'fieldset',
					'exclude' => 0,
				),
				2 => 
				array (
					'format' => 'fieldset',
					'exclude' => 0,
				),
				3 => 
				array (
					'format' => 'fieldset',
					'exclude' => 0,
				),
				'token' => 
				array (
					'format' => 'fieldset',
					'exclude' => 0,
				),
				'label' => 'above',
			),
		),
		'weight' => '-4',
		'group_name' => 'group_file_info',
	),
);
$content['fields']  = array (
	0 => 
	array (
		'label' => 'File',
		'field_name' => 'clade_file_file',
		'type' => 'filefield',
		'widget_type' => 'filefield_widget',
		'change' => 'Change basic information',
		'weight' => '-3',
		'file_extensions' => '',
		'progress_indicator' => 'bar',
		'file_path' => '',
		'max_filesize_per_file' => '',
		'max_filesize_per_node' => '',
		'description' => '',
		'group' => 'group_file_info',
		'required' => 1,
		'multiple' => '0',
		'list_field' => '0',
		'list_default' => 1,
		'description_field' => '1',
		'op' => 'Save field settings',
		'module' => 'filefield',
		'widget_module' => 'filefield',
		'columns' => 
		array (
			'fid' => 
			array (
				'type' => 'int',
				'not null' => false,
				'views' => true,
			),
			'list' => 
			array (
				'type' => 'int',
				'size' => 'tiny',
				'not null' => false,
				'views' => true,
			),
			'data' => 
			array (
				'type' => 'text',
				'serialize' => true,
				'views' => true,
			),
		),
		'display_settings' => 
		array (
			'label' => 
			array (
				'format' => 'above',
				'exclude' => 0,
			),
			'teaser' => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			'full' => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			4 => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			2 => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			3 => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			'token' => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
		),
	),
	1 => 
	array (
		'label' => 'Source',
		'field_name' => 'field_file_source',
		'type' => 'text',
		'widget_type' => 'text_textfield',
		'change' => 'Change basic information',
		'weight' => '-2',
		'rows' => 5,
		'size' => '60',
		'description' => 'Where did you get this file? E.g. own work, web URL.',
		'default_value' => 
		array (
			0 => 
			array (
				'value' => '',
				'_error_element' => 'default_value_widget][field_file_source][0][value',
			),
		),
		'default_value_php' => '',
		'default_value_widget' => 
		array (
			'field_file_source' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_file_source][0][value',
				),
			),
		),
		'group' => 'group_file_info',
		'required' => 0,
		'multiple' => '0',
		'text_processing' => '0',
		'max_length' => '',
		'allowed_values' => '',
		'allowed_values_php' => '',
		'op' => 'Save field settings',
		'module' => 'text',
		'widget_module' => 'text',
		'columns' => 
		array (
			'value' => 
			array (
				'type' => 'text',
				'size' => 'big',
				'not null' => false,
				'sortable' => true,
				'views' => true,
			),
		),
		'display_settings' => 
		array (
			'label' => 
			array (
				'format' => 'above',
				'exclude' => 0,
			),
			'teaser' => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			'full' => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			4 => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			2 => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			3 => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
			'token' => 
			array (
				'format' => 'default',
				'exclude' => 0,
			),
		),
	),
);
$content['extra']  = array (
	'title' => '-5',
	'body_field' => '0',
	'revision_information' => '2',
	'author' => '3',
	'options' => '4',
	'comment_settings' => '5',
	'menu' => '-1',
	'taxonomy' => '-2',
	'path' => '6',
	'detailed_question' => '1',
);