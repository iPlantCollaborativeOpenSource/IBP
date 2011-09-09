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
		'comment' => 2,
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
	$content['fields']  = array (
		0 => 
		array (
			'label' => 'Project Number',
			'field_name' => 'ibp_project_number',
			'type' => 'text',
			'widget_type' => 'text_textfield',
			'change' => 'Change basic information',
			'weight' => '-4',
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
			'weight' => '-3',
			'autocomplete_match' => 'contains',
			'size' => '60',
			'reverse_link' => 0,
			'description' => '',
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
				'field_pi' => 
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
			'required' => 1,
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
			'advanced_view' => '--',
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
			'label' => 'Collaborators',
			'field_name' => 'ibp_project_collaborators',
			'type' => 'userreference',
			'widget_type' => 'userreference_autocomplete',
			'change' => 'Change basic information',
			'weight' => '-2',
			'autocomplete_match' => 'contains',
			'size' => '60',
			'reverse_link' => 0,
			'description' => '',
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
				'field_collaborators' => 
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
			'advanced_view' => '--',
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
	);
	$content['extra']  = array (
		'title' => '-5',
		'body_field' => '-1',
		'revision_information' => '3',
		'author' => '2',
		'options' => '4',
		'comment_settings' => '5',
		'menu' => '0',
		'path' => '6',
		'detailed_question' => '1',
	);
	return $content;
}
