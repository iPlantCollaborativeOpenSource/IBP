<?php

function _ibp_projects_ibp_project_content_type_def() {
	$content['type']  = array (
		'name' => 'IBP Project',
		'type' => 'ibp_project',
		'description' => 'A project within a crop or crops.',
		'title_label' => 'Project Name',
		'body_label' => 'Description',
		'min_word_count' => 0,
		'help' => '',
		'node_options' => 
		array (
			'status' => true,
			'promote' => true,
			'sticky' => false,
			'revision' => false,
		),
		'parentmenu' => 0,
		'parentmenuen' => 0,
		'automenu_hide' => 0,
		'old_type' => 'ibp_project',
		'orig_type' => 'ibp_project',
		'module' => 'ibp_projects',
		'custom' => false,
		'modified' => false,
		'locked' => true,
		'reset' => 'Reset to defaults',
		'comment' => 0,
		'comment_default_mode' => 4,
		'comment_default_order' => 1,
		'comment_default_per_page' => 50,
		'comment_controls' => 3,
		'comment_anonymous' => 0,
		'comment_subject_field' => 1,
		'comment_preview' => 1,
		'comment_form_location' => 0,
		'notifications_node_ui' => 
		array (
			'block' => true,
			0 => 1,
			'form' => false,
			'comment' => false,
			'links' => false,
			'teaserlinks' => false,
			'subform' => false,
		),
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
			'label' => 'Project Proposal',
			'group_type' => 'standard',
			'settings' => 
			array (
				'form' => 
				array (
					'style' => 'fieldset_collapsed',
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
			'weight' => '1',
			'group_name' => 'group_proposal_files',
		),
		1 => 
		array (
			'label' => 'Project Reports',
			'group_type' => 'standard',
			'settings' => 
			array (
				'form' => 
				array (
					'style' => 'fieldset_collapsed',
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
			'weight' => '2',
			'group_name' => 'group_reports',
		),
		2 => 
		array (
			'label' => 'Project Publications',
			'group_type' => 'standard',
			'settings' => 
			array (
				'form' => 
				array (
					'style' => 'fieldset_collapsed',
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
			'weight' => '3',
			'group_name' => 'group_publications',
		),
		3 => 
		array (
			'label' => 'Project Products',
			'group_type' => 'standard',
			'settings' => 
			array (
				'form' => 
				array (
					'style' => 'fieldset_collapsed',
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
			'weight' => '4',
			'group_name' => 'group_products',
		),
		4 => 
		array (
			'label' => 'Project Datasets',
			'group_type' => 'standard',
			'settings' => 
			array (
				'form' => 
				array (
					'style' => 'fieldset_collapsed',
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
			'weight' => '5',
			'group_name' => 'group_datasets',
		),
		5 => 
		array (
			'label' => 'Project Media',
			'group_type' => 'standard',
			'settings' => 
			array (
				'form' => 
				array (
					'style' => 'fieldset_collapsed',
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
			'weight' => '6',
			'group_name' => 'group_media',
		),
	);
	$content['fields']  = array (
		0 => 
		array (
			'label' => 'Project Number',
			'field_name' => 'ibp_project_number',
			'type' => 'text',
			'widget_type' => 'text_textfield',
			'change' => 'Change basic information',
			'weight' => '-6',
			'rows' => 5,
			'size' => '60',
			'description' => '',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][ibp_project_number][0][value',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => NULL,
			'group' => false,
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
		1 => 
		array (
			'label' => 'Principal Investigator',
			'field_name' => 'ibp_project_pi',
			'type' => 'userreference',
			'widget_type' => 'userreference_autocomplete',
			'change' => 'Change basic information',
			'weight' => '-5',
			'autocomplete_match' => 'contains',
			'size' => '60',
			'reverse_link' => 0,
			'description' => 'Provide the username of the IBP user who is the PI on the project.',
			'default_value' => 
			array (
				0 => 
				array (
					'uid' => NULL,
					'_error_element' => 'default_value_widget][ibp_project_pi][0][uid][uid',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'ibp_project_pi' => 
				array (
					0 => 
					array (
						'uid' => 
						array (
							'uid' => '',
							'_error_element' => 'default_value_widget][ibp_project_pi][0][uid][uid',
						),
						'_error_element' => 'default_value_widget][ibp_project_pi][0][uid][uid',
					),
				),
			),
			'group' => false,
			'required' => 0,
			'multiple' => '0',
			'referenceable_roles' => 
			array (
				2 => 0,
				6 => 0,
				5 => 0,
				4 => 0,
				7 => 0,
				3 => 0,
			),
			'referenceable_status' => '',
			'advanced_view' => 'select_user_lookup',
			'advanced_view_args' => '',
			'op' => 'Save field settings',
			'module' => 'userreference',
			'widget_module' => 'userreference',
			'columns' => 
			array (
				'uid' => 
				array (
					'type' => 'int',
					'unsigned' => true,
					'not null' => false,
					'index' => true,
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
		2 => 
		array (
			'label' => 'Principal Investigator (non-IBP user)',
			'field_name' => 'ibp_project_pi_text',
			'type' => 'text',
			'widget_type' => 'text_textfield',
			'change' => 'Change basic information',
			'weight' => '-4',
			'rows' => 5,
			'size' => '60',
			'description' => 'If the PI is not an IBP user, then simply enter the person\'s name.',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][ibp_project_pi_text][0][value',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'ibp_project_pi_text' => 
				array (
					0 => 
					array (
						'value' => '',
						'_error_element' => 'default_value_widget][ibp_project_pi_text][0][value',
					),
				),
			),
			'group' => false,
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
		3 => 
		array (
			'label' => 'Collaborators',
			'field_name' => 'ibp_project_collaborators',
			'type' => 'userreference',
			'widget_type' => 'userreference_autocomplete',
			'change' => 'Change basic information',
			'weight' => '-3',
			'autocomplete_match' => 'contains',
			'size' => '60',
			'reverse_link' => 0,
			'description' => 'Provide the username(s) of IBP users who are collaborators on this project.',
			'default_value' => 
			array (
				0 => 
				array (
					'uid' => NULL,
					'_error_element' => 'default_value_widget][ibp_project_collaborators][0][uid][uid',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'ibp_project_collaborators' => 
				array (
					0 => 
					array (
						'uid' => 
						array (
							'uid' => '',
							'_error_element' => 'default_value_widget][ibp_project_collaborators][0][uid][uid',
						),
						'_error_element' => 'default_value_widget][ibp_project_collaborators][0][uid][uid',
					),
				),
			),
			'group' => false,
			'required' => 0,
			'multiple' => '1',
			'referenceable_roles' => 
			array (
				2 => 0,
				6 => 0,
				5 => 0,
				4 => 0,
				7 => 0,
				3 => 0,
			),
			'referenceable_status' => '',
			'advanced_view' => 'select_user_lookup',
			'advanced_view_args' => '',
			'op' => 'Save field settings',
			'module' => 'userreference',
			'widget_module' => 'userreference',
			'columns' => 
			array (
				'uid' => 
				array (
					'type' => 'int',
					'unsigned' => true,
					'not null' => false,
					'index' => true,
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
		4 => 
		array (
			'label' => 'Collaborators (non-IBP users)',
			'field_name' => 'ibp_project_collaborators_text',
			'type' => 'text',
			'widget_type' => 'text_textfield',
			'change' => 'Change basic information',
			'weight' => '-2',
			'rows' => 5,
			'size' => '60',
			'description' => 'Enter any project collaborators that are not IBP users.',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][ibp_project_collaborators_text][0][value',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'ibp_project_collaborators_text' => 
				array (
					0 => 
					array (
						'value' => '',
						'_error_element' => 'default_value_widget][ibp_project_collaborators_text][0][value',
					),
				),
			),
			'group' => false,
			'required' => 0,
			'multiple' => '1',
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
		5 => 
		array (
			'label' => 'Proposal Files',
			'field_name' => 'ibp_project_proposal_file',
			'type' => 'filefield',
			'widget_type' => 'filefield_widget',
			'change' => 'Change basic information',
			'weight' => '10',
			'file_extensions' => 'txt',
			'progress_indicator' => 'bar',
			'file_path' => '',
			'max_filesize_per_file' => '',
			'max_filesize_per_node' => '',
			'description' => '',
			'group' => 'group_proposal_files',
			'required' => 0,
			'multiple' => '1',
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
		6 => 
		array (
			'label' => 'Project Report Files',
			'field_name' => 'ibp_project_report_file',
			'type' => 'filefield',
			'widget_type' => 'filefield_widget',
			'change' => 'Change basic information',
			'weight' => '10',
			'file_extensions' => '',
			'progress_indicator' => 'bar',
			'file_path' => '',
			'max_filesize_per_file' => '',
			'max_filesize_per_node' => '',
			'description' => '',
			'group' => 'group_reports',
			'required' => 0,
			'multiple' => '1',
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
		7 => 
		array (
			'label' => 'Project Publication Files',
			'field_name' => 'ibp_project_publication_file',
			'type' => 'filefield',
			'widget_type' => 'filefield_widget',
			'change' => 'Change basic information',
			'weight' => '11',
			'file_extensions' => '',
			'progress_indicator' => 'bar',
			'file_path' => '',
			'max_filesize_per_file' => '',
			'max_filesize_per_node' => '',
			'description' => '',
			'group' => 'group_publications',
			'required' => 0,
			'multiple' => '1',
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
		8 => 
		array (
			'label' => 'Project Product Files',
			'field_name' => 'ibp_project_product_file',
			'type' => 'filefield',
			'widget_type' => 'filefield_widget',
			'change' => 'Change basic information',
			'weight' => '12',
			'file_extensions' => '',
			'progress_indicator' => 'bar',
			'file_path' => '',
			'max_filesize_per_file' => '',
			'max_filesize_per_node' => '',
			'description' => '',
			'group' => 'group_products',
			'required' => 0,
			'multiple' => '1',
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
		9 => 
		array (
			'label' => 'Project Dataset Files',
			'field_name' => 'ibp_project_dataset_file',
			'type' => 'filefield',
			'widget_type' => 'filefield_widget',
			'change' => 'Change basic information',
			'weight' => '13',
			'file_extensions' => '',
			'progress_indicator' => 'bar',
			'file_path' => '',
			'max_filesize_per_file' => '',
			'max_filesize_per_node' => '',
			'description' => '',
			'group' => 'group_datasets',
			'required' => 0,
			'multiple' => '1',
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
		10 => 
		array (
			'label' => 'Project Images',
			'field_name' => 'ibp_project_image',
			'type' => 'filefield',
			'widget_type' => 'imagefield_widget',
			'change' => 'Change basic information',
			'weight' => '14',
			'file_extensions' => 'png gif jpg jpeg',
			'progress_indicator' => 'bar',
			'file_path' => '',
			'max_filesize_per_file' => '',
			'max_filesize_per_node' => '',
			'max_resolution' => 0,
			'min_resolution' => 0,
			'custom_alt' => 0,
			'alt' => '',
			'custom_title' => 0,
			'title_type' => 'textfield',
			'title' => '',
			'use_default_image' => 0,
			'default_image_upload' => '',
			'default_image' => NULL,
			'description' => '',
			'group' => 'group_media',
			'required' => 0,
			'multiple' => '1',
			'list_field' => '0',
			'list_default' => 1,
			'description_field' => '1',
			'op' => 'Save field settings',
			'module' => 'filefield',
			'widget_module' => 'imagefield',
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
					'format' => 'image_plain',
					'exclude' => 0,
				),
				'full' => 
				array (
					'format' => 'image_plain',
					'exclude' => 0,
				),
				4 => 
				array (
					'format' => 'image_plain',
					'exclude' => 0,
				),
				2 => 
				array (
					'format' => 'image_plain',
					'exclude' => 0,
				),
				3 => 
				array (
					'format' => 'image_plain',
					'exclude' => 0,
				),
				'token' => 
				array (
					'format' => 'image_plain',
					'exclude' => 0,
				),
			),
		),
	);
	$content['extra']  = array (
		'title' => '-7',
		'body_field' => '-1',
		'revision_information' => '10',
		'author' => '9',
		'options' => '11',
		'comment_settings' => '12',
		'menu' => '7',
		'taxonomy' => '0',
		'path' => '8',
		'detailed_question' => '13',
	);

	return $content;
}
