<?php

function _ibphelper_ibp_tool_content_type_def() {
	$content['type']  = array (
		'name' => 'IBP Tool',
		'type' => 'ibp_tool',
		'description' => 'IBP Tool content type. Should describe an IBP tool like "EDGAR" or "OpenStat"',
		'title_label' => 'Tool name',
		'body_label' => 'Tool description',
		'min_word_count' => '0',
		'help' => '',
		'node_options' => 
		array (
			'status' => true,
			'promote' => true,
			'revision' => true,
			'sticky' => false,
		),
		'parentmenu' => '0',
		'parentmenuen' => '0',
		'automenu_hide' => 0,
		'old_type' => 'ibp_tool',
		'orig_type' => '',
		'module' => 'node',
		'custom' => '1',
		'modified' => '1',
		'locked' => '0',
		'comment' => '2',
		'comment_default_mode' => '4',
		'comment_default_order' => '1',
		'comment_default_per_page' => '50',
		'comment_controls' => '3',
		'comment_anonymous' => 0,
		'comment_subject_field' => '1',
		'comment_preview' => '1',
		'comment_form_location' => '0',
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
			'taxonomy' => false,
			'thread' => false,
			'nodetype' => false,
			'author' => false,
			'typeauthor' => false,
		),
	);
	$content['fields']  = array (
		0 => 
		array (
			'label' => 'Category',
			'field_name' => 'field_tool_category',
			'type' => 'text',
			'widget_type' => 'text_textfield',
			'change' => 'Change basic information',
			'weight' => '-4',
			'rows' => 5,
			'size' => '60',
			'description' => 'Enter the tool category such as Breeding, Genetics, Molecular, Project Management',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_tool_category][0][value',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => NULL,
			'group' => false,
			'required' => 1,
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
				'weight' => '-4',
				'parent' => '',
				'label' => 
				array (
					'format' => 'above',
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
				4 => 
				array (
					'format' => 'default',
					'exclude' => 0,
				),
				5 => 
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
			'label' => 'Usability',
			'field_name' => 'field_tool_usability',
			'type' => 'text',
			'widget_type' => 'optionwidgets_buttons',
			'change' => 'Change basic information',
			'weight' => '-2',
			'description' => 'Some software tools are more usable than others.  Please select how user-friendly this tool is.',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'field_tool_usability' => 
				array (
					'value' => '',
				),
			),
			'group' => false,
			'required' => 1,
			'multiple' => '0',
			'text_processing' => '0',
			'max_length' => '',
			'allowed_values' => 'Completely intuitive
	Easy to use
	Difficult to use
	Very difficult to use
	In development',
			'allowed_values_php' => '',
			'op' => 'Save field settings',
			'module' => 'text',
			'widget_module' => 'optionwidgets',
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
				'weight' => '-2',
				'parent' => '',
				'label' => 
				array (
					'format' => 'above',
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
				4 => 
				array (
					'format' => 'default',
					'exclude' => 0,
				),
				5 => 
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
			'label' => 'Platform',
			'field_name' => 'field_tool_platform',
			'type' => 'text',
			'widget_type' => 'optionwidgets_buttons',
			'change' => 'Change basic information',
			'weight' => '-1',
			'description' => 'Select which platform(s) this tool applies to.',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => NULL,
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'field_tool_platform' => 
				array (
					'value' => 
					array (
						'' => 1,
						'Mac' => false,
						'Windows' => false,
						'Linux' => false,
						'Solaris' => false,
						'Web tool' => false,
					),
				),
			),
			'group' => false,
			'required' => 1,
			'multiple' => '5',
			'text_processing' => '0',
			'max_length' => '',
			'allowed_values' => 'Mac
	Windows
	Linux
	Solaris
	Web tool',
			'allowed_values_php' => '',
			'op' => 'Save field settings',
			'module' => 'text',
			'widget_module' => 'optionwidgets',
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
				'weight' => '-1',
				'parent' => '',
				'label' => 
				array (
					'format' => 'above',
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
				4 => 
				array (
					'format' => 'default',
					'exclude' => 0,
				),
				5 => 
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
			'label' => 'Version',
			'field_name' => 'field_tool_version',
			'type' => 'text',
			'widget_type' => 'text_textfield',
			'change' => 'Change basic information',
			'weight' => 0,
			'rows' => 5,
			'size' => '60',
			'description' => 'Enter the tool\'s version number. (Optional)',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_tool_version][0][value',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'field_tool_version' => 
				array (
					0 => 
					array (
						'value' => '',
						'_error_element' => 'default_value_widget][field_tool_version][0][value',
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
				'weight' => 0,
				'parent' => '',
				'label' => 
				array (
					'format' => 'above',
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
				4 => 
				array (
					'format' => 'default',
					'exclude' => 0,
				),
				5 => 
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
			'label' => 'Website',
			'field_name' => 'field_tool_dl_link',
			'type' => 'link',
			'widget_type' => 'link',
			'change' => 'Change basic information',
			'weight' => '2',
			'description' => 'Link to website for more information about this tool. (Optional)',
			'default_value' => 
			array (
				0 => 
				array (
					'title' => '',
					'url' => '',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'field_tool_dl_link' => 
				array (
					0 => 
					array (
						'title' => '',
						'url' => '',
					),
				),
			),
			'group' => false,
			'required' => 0,
			'multiple' => '0',
			'validate_url' => 1,
			'url' => 0,
			'title' => 'optional',
			'title_value' => '',
			'enable_tokens' => 0,
			'display' => 
			array (
				'url_cutoff' => '80',
			),
			'attributes' => 
			array (
				'target' => '_blank',
				'rel' => '',
				'class' => 'external-link',
				'title' => '',
			),
			'op' => 'Save field settings',
			'module' => 'link',
			'widget_module' => 'link',
			'columns' => 
			array (
				'url' => 
				array (
					'type' => 'varchar',
					'length' => 2048,
					'not null' => false,
					'sortable' => true,
				),
				'title' => 
				array (
					'type' => 'varchar',
					'length' => 255,
					'not null' => false,
					'sortable' => true,
				),
				'attributes' => 
				array (
					'type' => 'text',
					'size' => 'medium',
					'not null' => false,
				),
			),
			'display_settings' => 
			array (
				'weight' => '2',
				'parent' => '',
				'label' => 
				array (
					'format' => 'above',
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
				4 => 
				array (
					'format' => 'default',
					'exclude' => 0,
				),
				5 => 
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
			'label' => 'Downloads',
			'field_name' => 'field_tool_file',
			'type' => 'filefield',
			'widget_type' => 'filefield_widget',
			'change' => 'Change basic information',
			'weight' => '3',
			'file_extensions' => '',
			'progress_indicator' => 'bar',
			'file_path' => 'tools',
			'max_filesize_per_file' => '',
			'max_filesize_per_node' => '',
			'description' => 'If this tool will be downloadable directly from IBP, upload the file here.',
			'group' => false,
			'required' => 0,
			'multiple' => '1',
			'list_field' => '0',
			'list_default' => 1,
			'description_field' => '0',
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
				'weight' => '3',
				'parent' => '',
				'label' => 
				array (
					'format' => 'above',
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
				4 => 
				array (
					'format' => 'default',
					'exclude' => 0,
				),
				5 => 
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
			'label' => 'Screenshots',
			'field_name' => 'field_tool_screenshot',
			'type' => 'filefield',
			'widget_type' => 'imagefield_widget',
			'change' => 'Change basic information',
			'weight' => '4',
			'file_extensions' => 'png gif jpg jpeg',
			'progress_indicator' => 'bar',
			'file_path' => 'tools/screenshots',
			'max_filesize_per_file' => '2M',
			'max_filesize_per_node' => '',
			'max_resolution' => 0,
			'min_resolution' => 0,
			'custom_alt' => 0,
			'alt' => '',
			'custom_title' => 0,
			'title_type' => 'textfield',
			'title' => '',
			'use_default_image' => 1,
			'default_image_upload' => '',
			'default_image' => 
			array (
				'filename' => 'default-tool-screenshot.png',
				'filepath' => 'sites/default/files/imagefield_default_images/default-tool-screenshot.png',
				'filemime' => 'image/png',
				'source' => 'default_image_upload',
				'destination' => 'sites/default/files/imagefield_default_images/default-tool-screenshot.png',
				'filesize' => 58119,
				'uid' => '11',
				'status' => 1,
				'timestamp' => 1313598938,
				'fid' => '45',
			),
			'description' => 'Supply any screenshots of this tool in use.',
			'group' => false,
			'required' => 0,
			'multiple' => '3',
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
				'weight' => '4',
				'parent' => '',
				'label' => 
				array (
					'format' => 'hidden',
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
		7 => 
		array (
			'label' => 'Developers',
			'field_name' => 'field_tool_developers',
			'type' => 'text',
			'widget_type' => 'text_textfield',
			'change' => 'Change basic information',
			'weight' => '5',
			'rows' => 5,
			'size' => '60',
			'description' => '(optional) Enter the name(s) of the development team for this tool.',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_tool_developers][0][value',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'field_tool_developers' => 
				array (
					0 => 
					array (
						'value' => '',
						'_error_element' => 'default_value_widget][field_tool_developers][0][value',
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
		8 => 
		array (
			'label' => 'Technical Support',
			'field_name' => 'field_tool_techsupport',
			'type' => 'userreference',
			'widget_type' => 'userreference_autocomplete',
			'change' => 'Change basic information',
			'weight' => '6',
			'autocomplete_match' => 'contains',
			'size' => '60',
			'reverse_link' => 0,
			'description' => '(optional) Provide the username(s) of IBP users who can support this tool.',
			'default_value' => 
			array (
				0 => 
				array (
					'uid' => NULL,
					'_error_element' => 'default_value_widget][field_tool_techsupport][0][uid][uid',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'field_tool_techsupport' => 
				array (
					0 => 
					array (
						'uid' => 
						array (
							'uid' => '',
							'_error_element' => 'default_value_widget][field_tool_techsupport][0][uid][uid',
						),
						'_error_element' => 'default_value_widget][field_tool_techsupport][0][uid][uid',
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
		9 => 
		array (
			'label' => 'Sort order',
			'field_name' => 'field_tool_sort',
			'type' => 'number_integer',
			'widget_type' => 'number',
			'change' => 'Change basic information',
			'weight' => '7',
			'description' => 'Enter a numerical value to sort tools by. Tools are sorted in ascending order, so lower values appear first.',
			'default_value' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_tool_sort][0][value',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => 
			array (
				'field_tool_sort' => 
				array (
					0 => 
					array (
						'value' => '',
						'_error_element' => 'default_value_widget][field_tool_sort][0][value',
					),
				),
			),
			'group' => false,
			'required' => 0,
			'multiple' => '0',
			'min' => '',
			'max' => '',
			'prefix' => '',
			'suffix' => '',
			'allowed_values' => '',
			'allowed_values_php' => '',
			'op' => 'Save field settings',
			'module' => 'number',
			'widget_module' => 'number',
			'columns' => 
			array (
				'value' => 
				array (
					'type' => 'int',
					'not null' => false,
					'sortable' => true,
				),
			),
			'display_settings' => 
			array (
				'weight' => '12',
				'parent' => '',
				'label' => 
				array (
					'format' => 'above',
				),
				'teaser' => 
				array (
					'format' => 'default',
					'exclude' => 1,
				),
				'full' => 
				array (
					'format' => 'default',
					'exclude' => 1,
				),
				2 => 
				array (
					'format' => 'default',
					'exclude' => 1,
				),
				3 => 
				array (
					'format' => 'default',
					'exclude' => 1,
				),
				4 => 
				array (
					'format' => 'default',
					'exclude' => 1,
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
		'body_field' => '1',
		'revision_information' => '9',
		'author' => '10',
		'options' => '11',
		'comment_settings' => '13',
		'menu' => '8',
		'taxonomy' => '-3',
		'path' => '12',
		'detailed_question' => '14',
	);
	return $content;
}