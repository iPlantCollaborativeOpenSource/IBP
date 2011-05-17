$content['type']  = array (
	'name' => 'Image',
	'type' => 'clade_image',
	'description' => 'A image upload associated with a clade.',
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
	'old_type' => 'clade_image',
	'orig_type' => 'clade_image',
	'module' => 'clade_gallery',
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
		'label' => 'Image info',
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
		'group_name' => 'group_image_info',
	),
);
$content['fields']  = array (
	0 => 
	array (
		'label' => 'Image',
		'field_name' => 'clade_gallery_image',
		'type' => 'filefield',
		'widget_type' => 'imagefield_widget',
		'change' => 'Change basic information',
		'weight' => '-3',
		'file_extensions' => 'png gif jpg jpeg',
		'progress_indicator' => 'bar',
		'file_path' => '',
		'max_filesize_per_file' => '',
		'max_filesize_per_node' => '',
		'max_resolution' => 0,
		'min_resolution' => 0,
		'custom_alt' => 1,
		'alt' => '',
		'custom_title' => 1,
		'title_type' => 'textfield',
		'title' => '',
		'use_default_image' => 0,
		'default_image_upload' => '',
		'default_image' => NULL,
		'description' => '',
		'group' => 'group_image_info',
		'required' => 1,
		'multiple' => '0',
		'list_field' => '0',
		'list_default' => 1,
		'description_field' => '0',
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
			'weight' => '-3',
			'parent' => '',
			'label' => 
			array (
				'format' => 'hidden',
			),
			'teaser' => 
			array (
				'format' => 'thumb_linked',
				'exclude' => 0,
			),
			'full' => 
			array (
				'format' => 'large_imagelink',
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
	1 => 
	array (
		'label' => 'Description',
		'field_name' => 'field_description',
		'type' => 'text',
		'widget_type' => 'text_textarea',
		'change' => 'Change basic information',
		'weight' => '-2',
		'rows' => '3',
		'size' => 60,
		'description' => 'Provide a description of the image.',
		'default_value' => 
		array (
			0 => 
			array (
				'value' => '',
				'_error_element' => 'default_value_widget][field_description][0][value',
			),
		),
		'default_value_php' => '',
		'default_value_widget' => 
		array (
			'field_description' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_description][0][value',
				),
			),
		),
		'group' => 'group_image_info',
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
	2 => 
	array (
		'label' => 'Photographer/Artist',
		'field_name' => 'field_photographer',
		'type' => 'text',
		'widget_type' => 'text_textfield',
		'change' => 'Change basic information',
		'weight' => '-1',
		'rows' => 5,
		'size' => '60',
		'description' => 'Provide the name of the photographer or artist responsible for this image.',
		'default_value' => 
		array (
			0 => 
			array (
				'value' => '',
				'_error_element' => 'default_value_widget][field_photographer][0][value',
			),
		),
		'default_value_php' => '',
		'default_value_widget' => 
		array (
			'field_photographer' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_photographer][0][value',
				),
			),
		),
		'group' => 'group_image_info',
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
			'weight' => '-3',
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
		'label' => 'Copyright Information',
		'field_name' => 'field_copyright',
		'type' => 'text',
		'widget_type' => 'text_textfield',
		'change' => 'Change basic information',
		'weight' => 0,
		'rows' => 5,
		'size' => '60',
		'description' => 'Provide information regarding any copyrights to this image.  By uploading this image you are affirming that you have the right to use this image.',
		'default_value' => 
		array (
			0 => 
			array (
				'value' => '',
				'_error_element' => 'default_value_widget][field_copyright][0][value',
			),
		),
		'default_value_php' => '',
		'default_value_widget' => 
		array (
			'field_copyright' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_copyright][0][value',
				),
			),
		),
		'group' => 'group_image_info',
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
			'weight' => '-2',
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
		'label' => 'Source',
		'field_name' => 'field_source',
		'type' => 'text',
		'widget_type' => 'text_textfield',
		'change' => 'Change basic information',
		'weight' => '1',
		'rows' => 5,
		'size' => '60',
		'description' => 'Where did you get this image?  E.g. self-produced, web URL, published work.',
		'default_value' => 
		array (
			0 => 
			array (
				'value' => '',
				'_error_element' => 'default_value_widget][field_source][0][value',
			),
		),
		'default_value_php' => '',
		'default_value_widget' => 
		array (
			'field_source' => 
			array (
				0 => 
				array (
					'value' => '',
					'_error_element' => 'default_value_widget][field_source][0][value',
				),
			),
		),
		'group' => 'group_image_info',
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
			'weight' => '-1',
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
		'label' => 'Geotag',
		'field_name' => 'field_geotag',
		'type' => 'location',
		'widget_type' => 'location',
		'change' => 'Change basic information',
		'weight' => '2',
		'description' => 'Where was this image taken?',
		'default_value' => 
		array (
			0 => 
			array (
				'name' => '',
				'street' => '',
				'additional' => '',
				'city' => '',
				'province' => '',
				'country' => 'us',
				'locpick' => 
				array (
					'user_latitude' => '',
					'user_longitude' => '',
				),
				'cck_preview_in_progress' => true,
				'location_settings' => 
				array (
					'form' => 
					array (
						'fields' => 
						array (
							'name' => 
							array (
								'default' => '',
								'collect' => '1',
								'weight' => '2',
							),
							'street' => 
							array (
								'default' => '',
								'collect' => '1',
								'weight' => '4',
							),
							'additional' => 
							array (
								'default' => '',
								'collect' => '1',
								'weight' => '6',
							),
							'city' => 
							array (
								'default' => '',
								'collect' => '1',
								'weight' => '8',
							),
							'province' => 
							array (
								'default' => '',
								'collect' => '1',
								'weight' => '10',
							),
							'postal_code' => 
							array (
								'default' => '',
								'collect' => '0',
								'weight' => '12',
							),
							'country' => 
							array (
								'default' => 'us',
								'collect' => '1',
								'weight' => '14',
							),
							'locpick' => 
							array (
								'default' => 
								array (
									'user_latitude' => '',
									'user_longitude' => '',
								),
								'collect' => '1',
								'weight' => '20',
								'nodiff' => true,
							),
							'cck_preview_in_progress' => 
							array (
								'default' => true,
							),
							'location_settings' => 
							array (
								'default' => 
								array (
									'form' => 
									array (
										'fields' => 
										array (
											'name' => 
											array (
												'default' => '',
												'collect' => '1',
												'weight' => '2',
											),
											'street' => 
											array (
												'default' => '',
												'collect' => '1',
												'weight' => '4',
											),
											'additional' => 
											array (
												'default' => '',
												'collect' => '1',
												'weight' => '6',
											),
											'city' => 
											array (
												'default' => '',
												'collect' => '1',
												'weight' => '8',
											),
											'province' => 
											array (
												'default' => '',
												'collect' => '1',
												'weight' => '10',
											),
											'postal_code' => 
											array (
												'default' => '',
												'collect' => '0',
												'weight' => '12',
											),
											'country' => 
											array (
												'default' => 'us',
												'collect' => '1',
												'weight' => '14',
											),
											'locpick' => 
											array (
												'default' => 
												array (
													'user_latitude' => '',
													'user_longitude' => '',
												),
												'collect' => '1',
												'weight' => '20',
												'nodiff' => true,
											),
											'cck_preview_in_progress' => 
											array (
												'default' => true,
											),
											'location_settings' => 
											array (
												'default' => 
												array (
													'form' => 
													array (
														'fields' => 
														array (
															'name' => 
															array (
																'default' => '',
																'collect' => '1',
																'weight' => '2',
															),
															'street' => 
															array (
																'default' => '',
																'collect' => '1',
																'weight' => '4',
															),
															'additional' => 
															array (
																'default' => '',
																'collect' => '1',
																'weight' => '6',
															),
															'city' => 
															array (
																'default' => '',
																'collect' => '1',
																'weight' => '8',
															),
															'province' => 
															array (
																'default' => '',
																'collect' => '1',
																'weight' => '10',
															),
															'postal_code' => 
															array (
																'default' => '',
																'collect' => '0',
																'weight' => '12',
															),
															'country' => 
															array (
																'default' => 'us',
																'collect' => '1',
																'weight' => '14',
															),
															'locpick' => 
															array (
																'default' => 
																array (
																	'user_latitude' => '',
																	'user_longitude' => '',
																),
																'collect' => '1',
																'weight' => '20',
																'nodiff' => true,
															),
															'cck_preview_in_progress' => 
															array (
																'default' => true,
															),
															'location_settings' => 
															array (
																'default' => 
																array (
																	'form' => 
																	array (
																		'fields' => 
																		array (
																			'name' => 
																			array (
																				'default' => '',
																				'collect' => '1',
																				'weight' => '2',
																			),
																			'street' => 
																			array (
																				'default' => '',
																				'collect' => '1',
																				'weight' => '4',
																			),
																			'additional' => 
																			array (
																				'default' => '',
																				'collect' => '1',
																				'weight' => '6',
																			),
																			'city' => 
																			array (
																				'default' => '',
																				'collect' => '1',
																				'weight' => '8',
																			),
																			'province' => 
																			array (
																				'default' => '',
																				'collect' => '1',
																				'weight' => '10',
																			),
																			'postal_code' => 
																			array (
																				'default' => '',
																				'collect' => '0',
																				'weight' => '12',
																			),
																			'country' => 
																			array (
																				'default' => 'us',
																				'collect' => '1',
																				'weight' => '14',
																			),
																			'locpick' => 
																			array (
																				'default' => 
																				array (
																					'user_latitude' => '',
																					'user_longitude' => '',
																				),
																				'collect' => '1',
																				'weight' => '20',
																				'nodiff' => true,
																			),
																			'cck_preview_in_progress' => 
																			array (
																				'default' => true,
																			),
																			'location_settings' => 
																			array (
																				'default' => 
																				array (
																					'form' => 
																					array (
																						'fields' => 
																						array (
																							'name' => 
																							array (
																								'default' => '',
																								'collect' => '1',
																								'weight' => '2',
																							),
																							'street' => 
																							array (
																								'default' => '',
																								'collect' => '1',
																								'weight' => '4',
																							),
																							'additional' => 
																							array (
																								'default' => '',
																								'collect' => '1',
																								'weight' => '6',
																							),
																							'city' => 
																							array (
																								'default' => '',
																								'collect' => '1',
																								'weight' => '8',
																							),
																							'province' => 
																							array (
																								'default' => '',
																								'collect' => '1',
																								'weight' => '10',
																							),
																							'postal_code' => 
																							array (
																								'default' => '',
																								'collect' => '0',
																								'weight' => '12',
																							),
																							'country' => 
																							array (
																								'default' => 'us',
																								'collect' => '1',
																								'weight' => '14',
																							),
																							'locpick' => 
																							array (
																								'default' => 
																								array (
																									'user_latitude' => '',
																									'user_longitude' => '',
																								),
																								'collect' => '1',
																								'weight' => '20',
																								'nodiff' => true,
																							),
																							'cck_preview_in_progress' => 
																							array (
																								'default' => true,
																							),
																							'location_settings' => 
																							array (
																								'default' => 
																								array (
																									'form' => 
																									array (
																										'fields' => 
																										array (
																											'name' => 
																											array (
																												'default' => '',
																												'collect' => '1',
																												'weight' => '2',
																											),
																											'street' => 
																											array (
																												'default' => '',
																												'collect' => '1',
																												'weight' => '4',
																											),
																											'additional' => 
																											array (
																												'default' => '',
																												'collect' => '1',
																												'weight' => '6',
																											),
																											'city' => 
																											array (
																												'default' => '',
																												'collect' => '1',
																												'weight' => '8',
																											),
																											'province' => 
																											array (
																												'default' => '',
																												'collect' => '1',
																												'weight' => '10',
																											),
																											'postal_code' => 
																											array (
																												'default' => '',
																												'collect' => '0',
																												'weight' => '12',
																											),
																											'country' => 
																											array (
																												'default' => 'us',
																												'collect' => '1',
																												'weight' => '14',
																											),
																											'locpick' => 
																											array (
																												'default' => 
																												array (
																													'user_latitude' => '',
																													'user_longitude' => '',
																												),
																												'collect' => '1',
																												'weight' => '20',
																												'nodiff' => true,
																											),
																											'cck_preview_in_progress' => 
																											array (
																												'default' => true,
																											),
																											'location_settings' => 
																											array (
																												'default' => 
																												array (
																													'form' => 
																													array (
																														'fields' => 
																														array (
																															'name' => 
																															array (
																																'default' => '',
																																'collect' => '1',
																																'weight' => '2',
																															),
																															'street' => 
																															array (
																																'default' => '',
																																'collect' => '1',
																																'weight' => '4',
																															),
																															'additional' => 
																															array (
																																'default' => '',
																																'collect' => '1',
																																'weight' => '6',
																															),
																															'city' => 
																															array (
																																'default' => '',
																																'collect' => '1',
																																'weight' => '8',
																															),
																															'province' => 
																															array (
																																'default' => '',
																																'collect' => '1',
																																'weight' => '10',
																															),
																															'postal_code' => 
																															array (
																																'default' => '',
																																'collect' => '0',
																																'weight' => '12',
																															),
																															'country' => 
																															array (
																																'default' => 'us',
																																'collect' => '1',
																																'weight' => '14',
																															),
																															'locpick' => 
																															array (
																																'default' => 
																																array (
																																	'user_latitude' => '',
																																	'user_longitude' => '',
																																),
																																'collect' => '1',
																																'weight' => '20',
																																'nodiff' => true,
																															),
																															'cck_preview_in_progress' => 
																															array (
																																'default' => true,
																															),
																															'location_settings' => 
																															array (
																																'default' => 
																																array (
																																	'form' => 
																																	array (
																																		'fields' => 
																																		array (
																																			'lid' => 
																																			array (
																																				'default' => false,
																																			),
																																			'name' => 
																																			array (
																																				'default' => '',
																																				'collect' => 1,
																																				'weight' => 2,
																																			),
																																			'street' => 
																																			array (
																																				'default' => '',
																																				'collect' => 1,
																																				'weight' => 4,
																																			),
																																			'additional' => 
																																			array (
																																				'default' => '',
																																				'collect' => 1,
																																				'weight' => 6,
																																			),
																																			'city' => 
																																			array (
																																				'default' => '',
																																				'collect' => 0,
																																				'weight' => 8,
																																			),
																																			'province' => 
																																			array (
																																				'default' => '',
																																				'collect' => 0,
																																				'weight' => 10,
																																			),
																																			'postal_code' => 
																																			array (
																																				'default' => '',
																																				'collect' => 0,
																																				'weight' => 12,
																																			),
																																			'country' => 
																																			array (
																																				'default' => 'us',
																																				'collect' => 1,
																																				'weight' => 14,
																																			),
																																			'locpick' => 
																																			array (
																																				'default' => false,
																																				'collect' => 1,
																																				'weight' => 20,
																																				'nodiff' => true,
																																			),
																																			'latitude' => 
																																			array (
																																				'default' => 0,
																																			),
																																			'longitude' => 
																																			array (
																																				'default' => 0,
																																			),
																																			'source' => 
																																			array (
																																				'default' => 0,
																																			),
																																			'is_primary' => 
																																			array (
																																				'default' => 0,
																																			),
																																			'delete_location' => 
																																			array (
																																				'default' => false,
																																				'nodiff' => true,
																																			),
																																		),
																																	),
																																),
																															),
																															'lid' => 
																															array (
																																'default' => false,
																															),
																															'latitude' => 
																															array (
																																'default' => 0,
																															),
																															'longitude' => 
																															array (
																																'default' => 0,
																															),
																															'source' => 
																															array (
																																'default' => 0,
																															),
																															'is_primary' => 
																															array (
																																'default' => 0,
																															),
																															'delete_location' => 
																															array (
																																'default' => false,
																																'nodiff' => true,
																															),
																														),
																													),
																													'display' => 
																													array (
																														'hide' => 
																														array (
																															'name' => 0,
																															'street' => 0,
																															'additional' => 0,
																															'city' => 0,
																															'province' => 0,
																															'postal_code' => 0,
																															'country' => 0,
																															'locpick' => 0,
																															'province_name' => 0,
																															'country_name' => 0,
																															'map_link' => 0,
																															'coords' => 0,
																														),
																													),
																												),
																											),
																											'lid' => 
																											array (
																												'default' => false,
																											),
																											'latitude' => 
																											array (
																												'default' => 0,
																											),
																											'longitude' => 
																											array (
																												'default' => 0,
																											),
																											'source' => 
																											array (
																												'default' => 0,
																											),
																											'is_primary' => 
																											array (
																												'default' => 0,
																											),
																											'delete_location' => 
																											array (
																												'default' => false,
																												'nodiff' => true,
																											),
																										),
																									),
																									'display' => 
																									array (
																										'hide' => 
																										array (
																											'name' => 0,
																											'street' => 0,
																											'additional' => 0,
																											'city' => 0,
																											'province' => 0,
																											'postal_code' => 0,
																											'country' => 0,
																											'locpick' => 0,
																											'province_name' => 0,
																											'country_name' => 0,
																											'map_link' => 0,
																											'coords' => 0,
																										),
																									),
																								),
																							),
																							'lid' => 
																							array (
																								'default' => false,
																							),
																							'latitude' => 
																							array (
																								'default' => 0,
																							),
																							'longitude' => 
																							array (
																								'default' => 0,
																							),
																							'source' => 
																							array (
																								'default' => 0,
																							),
																							'is_primary' => 
																							array (
																								'default' => 0,
																							),
																							'delete_location' => 
																							array (
																								'default' => false,
																								'nodiff' => true,
																							),
																						),
																					),
																					'display' => 
																					array (
																						'hide' => 
																						array (
																							'name' => 0,
																							'street' => 0,
																							'additional' => 0,
																							'city' => 0,
																							'province' => 0,
																							'postal_code' => 0,
																							'country' => 0,
																							'locpick' => 0,
																							'province_name' => 0,
																							'country_name' => 0,
																							'map_link' => 0,
																							'coords' => 0,
																						),
																					),
																				),
																			),
																			'lid' => 
																			array (
																				'default' => false,
																			),
																			'latitude' => 
																			array (
																				'default' => 0,
																			),
																			'longitude' => 
																			array (
																				'default' => 0,
																			),
																			'source' => 
																			array (
																				'default' => 0,
																			),
																			'is_primary' => 
																			array (
																				'default' => 0,
																			),
																			'delete_location' => 
																			array (
																				'default' => false,
																				'nodiff' => true,
																			),
																		),
																	),
																	'display' => 
																	array (
																		'hide' => 
																		array (
																			'name' => 0,
																			'street' => 0,
																			'additional' => 0,
																			'city' => 0,
																			'province' => 0,
																			'postal_code' => 0,
																			'country' => 0,
																			'locpick' => 0,
																			'province_name' => 0,
																			'country_name' => 0,
																			'map_link' => 0,
																			'coords' => 0,
																		),
																	),
																),
															),
															'lid' => 
															array (
																'default' => false,
															),
															'latitude' => 
															array (
																'default' => 0,
															),
															'longitude' => 
															array (
																'default' => 0,
															),
															'source' => 
															array (
																'default' => 0,
															),
															'is_primary' => 
															array (
																'default' => 0,
															),
															'delete_location' => 
															array (
																'default' => false,
																'nodiff' => true,
															),
														),
													),
													'display' => 
													array (
														'hide' => 
														array (
															'name' => 0,
															'street' => 0,
															'additional' => 0,
															'city' => 0,
															'province' => 0,
															'postal_code' => 0,
															'country' => 0,
															'locpick' => 0,
															'province_name' => 0,
															'country_name' => 0,
															'map_link' => 0,
															'coords' => 0,
														),
													),
												),
											),
											'lid' => 
											array (
												'default' => false,
											),
											'latitude' => 
											array (
												'default' => 0,
											),
											'longitude' => 
											array (
												'default' => 0,
											),
											'source' => 
											array (
												'default' => 0,
											),
											'is_primary' => 
											array (
												'default' => 0,
											),
											'delete_location' => 
											array (
												'default' => false,
												'nodiff' => true,
											),
										),
									),
									'display' => 
									array (
										'hide' => 
										array (
											'name' => 0,
											'street' => 0,
											'additional' => 0,
											'city' => 0,
											'province' => 0,
											'postal_code' => 0,
											'country' => 0,
											'locpick' => 0,
											'province_name' => 0,
											'country_name' => 0,
											'map_link' => 0,
											'coords' => 0,
										),
									),
								),
							),
							'lid' => 
							array (
								'default' => false,
							),
							'latitude' => 
							array (
								'default' => 0,
							),
							'longitude' => 
							array (
								'default' => 0,
							),
							'source' => 
							array (
								'default' => 0,
							),
							'is_primary' => 
							array (
								'default' => 0,
							),
							'delete_location' => 
							array (
								'default' => false,
								'nodiff' => true,
							),
						),
					),
					'display' => 
					array (
						'hide' => 
						array (
							'name' => 0,
							'street' => 0,
							'additional' => 0,
							'city' => 0,
							'province' => 0,
							'postal_code' => 0,
							'country' => 0,
							'locpick' => 0,
							'province_name' => 0,
							'country_name' => 0,
							'map_link' => 0,
							'coords' => 0,
						),
					),
				),
			),
		),
		'default_value_php' => '',
		'default_value_widget' => 
		array (
			'field_geotag' => 
			array (
				0 => 
				array (
					'lid' => false,
					'name' => '',
					'street' => '',
					'additional' => '',
					'city' => '',
					'province' => '',
					'postal_code' => '',
					'country' => 'us',
					'locpick' => 
					array (
						'user_latitude' => '',
						'user_longitude' => '',
					),
					'latitude' => 0,
					'longitude' => 0,
					'source' => 0,
					'is_primary' => 0,
					'delete_location' => false,
					'cck_preview_in_progress' => true,
					'location_settings' => 
					array (
						'form' => 
						array (
							'fields' => 
							array (
								'name' => 
								array (
									'default' => '',
									'collect' => '1',
									'weight' => '2',
								),
								'street' => 
								array (
									'default' => '',
									'collect' => '1',
									'weight' => '4',
								),
								'additional' => 
								array (
									'default' => '',
									'collect' => '1',
									'weight' => '6',
								),
								'city' => 
								array (
									'default' => '',
									'collect' => '1',
									'weight' => '8',
								),
								'province' => 
								array (
									'default' => '',
									'collect' => '1',
									'weight' => '10',
								),
								'postal_code' => 
								array (
									'default' => '',
									'collect' => '0',
									'weight' => '12',
								),
								'country' => 
								array (
									'default' => 'us',
									'collect' => '1',
									'weight' => '14',
								),
								'locpick' => 
								array (
									'default' => 
									array (
										'user_latitude' => '',
										'user_longitude' => '',
									),
									'collect' => '1',
									'weight' => '20',
									'nodiff' => true,
								),
								'cck_preview_in_progress' => 
								array (
									'default' => true,
								),
								'location_settings' => 
								array (
									'default' => 
									array (
										'form' => 
										array (
											'fields' => 
											array (
												'name' => 
												array (
													'default' => '',
													'collect' => '1',
													'weight' => '2',
												),
												'street' => 
												array (
													'default' => '',
													'collect' => '1',
													'weight' => '4',
												),
												'additional' => 
												array (
													'default' => '',
													'collect' => '1',
													'weight' => '6',
												),
												'city' => 
												array (
													'default' => '',
													'collect' => '1',
													'weight' => '8',
												),
												'province' => 
												array (
													'default' => '',
													'collect' => '1',
													'weight' => '10',
												),
												'postal_code' => 
												array (
													'default' => '',
													'collect' => '0',
													'weight' => '12',
												),
												'country' => 
												array (
													'default' => 'us',
													'collect' => '1',
													'weight' => '14',
												),
												'locpick' => 
												array (
													'default' => 
													array (
														'user_latitude' => '',
														'user_longitude' => '',
													),
													'collect' => '1',
													'weight' => '20',
													'nodiff' => true,
												),
												'cck_preview_in_progress' => 
												array (
													'default' => true,
												),
												'location_settings' => 
												array (
													'default' => 
													array (
														'form' => 
														array (
															'fields' => 
															array (
																'name' => 
																array (
																	'default' => '',
																	'collect' => '1',
																	'weight' => '2',
																),
																'street' => 
																array (
																	'default' => '',
																	'collect' => '1',
																	'weight' => '4',
																),
																'additional' => 
																array (
																	'default' => '',
																	'collect' => '1',
																	'weight' => '6',
																),
																'city' => 
																array (
																	'default' => '',
																	'collect' => '1',
																	'weight' => '8',
																),
																'province' => 
																array (
																	'default' => '',
																	'collect' => '1',
																	'weight' => '10',
																),
																'postal_code' => 
																array (
																	'default' => '',
																	'collect' => '0',
																	'weight' => '12',
																),
																'country' => 
																array (
																	'default' => 'us',
																	'collect' => '1',
																	'weight' => '14',
																),
																'locpick' => 
																array (
																	'default' => 
																	array (
																		'user_latitude' => '',
																		'user_longitude' => '',
																	),
																	'collect' => '1',
																	'weight' => '20',
																	'nodiff' => true,
																),
																'cck_preview_in_progress' => 
																array (
																	'default' => true,
																),
																'location_settings' => 
																array (
																	'default' => 
																	array (
																		'form' => 
																		array (
																			'fields' => 
																			array (
																				'name' => 
																				array (
																					'default' => '',
																					'collect' => '1',
																					'weight' => '2',
																				),
																				'street' => 
																				array (
																					'default' => '',
																					'collect' => '1',
																					'weight' => '4',
																				),
																				'additional' => 
																				array (
																					'default' => '',
																					'collect' => '1',
																					'weight' => '6',
																				),
																				'city' => 
																				array (
																					'default' => '',
																					'collect' => '1',
																					'weight' => '8',
																				),
																				'province' => 
																				array (
																					'default' => '',
																					'collect' => '1',
																					'weight' => '10',
																				),
																				'postal_code' => 
																				array (
																					'default' => '',
																					'collect' => '0',
																					'weight' => '12',
																				),
																				'country' => 
																				array (
																					'default' => 'us',
																					'collect' => '1',
																					'weight' => '14',
																				),
																				'locpick' => 
																				array (
																					'default' => 
																					array (
																						'user_latitude' => '',
																						'user_longitude' => '',
																					),
																					'collect' => '1',
																					'weight' => '20',
																					'nodiff' => true,
																				),
																				'cck_preview_in_progress' => 
																				array (
																					'default' => true,
																				),
																				'location_settings' => 
																				array (
																					'default' => 
																					array (
																						'form' => 
																						array (
																							'fields' => 
																							array (
																								'name' => 
																								array (
																									'default' => '',
																									'collect' => '1',
																									'weight' => '2',
																								),
																								'street' => 
																								array (
																									'default' => '',
																									'collect' => '1',
																									'weight' => '4',
																								),
																								'additional' => 
																								array (
																									'default' => '',
																									'collect' => '1',
																									'weight' => '6',
																								),
																								'city' => 
																								array (
																									'default' => '',
																									'collect' => '1',
																									'weight' => '8',
																								),
																								'province' => 
																								array (
																									'default' => '',
																									'collect' => '1',
																									'weight' => '10',
																								),
																								'postal_code' => 
																								array (
																									'default' => '',
																									'collect' => '0',
																									'weight' => '12',
																								),
																								'country' => 
																								array (
																									'default' => 'us',
																									'collect' => '1',
																									'weight' => '14',
																								),
																								'locpick' => 
																								array (
																									'default' => 
																									array (
																										'user_latitude' => '',
																										'user_longitude' => '',
																									),
																									'collect' => '1',
																									'weight' => '20',
																									'nodiff' => true,
																								),
																								'cck_preview_in_progress' => 
																								array (
																									'default' => true,
																								),
																								'location_settings' => 
																								array (
																									'default' => 
																									array (
																										'form' => 
																										array (
																											'fields' => 
																											array (
																												'name' => 
																												array (
																													'default' => '',
																													'collect' => '1',
																													'weight' => '2',
																												),
																												'street' => 
																												array (
																													'default' => '',
																													'collect' => '1',
																													'weight' => '4',
																												),
																												'additional' => 
																												array (
																													'default' => '',
																													'collect' => '1',
																													'weight' => '6',
																												),
																												'city' => 
																												array (
																													'default' => '',
																													'collect' => '1',
																													'weight' => '8',
																												),
																												'province' => 
																												array (
																													'default' => '',
																													'collect' => '1',
																													'weight' => '10',
																												),
																												'postal_code' => 
																												array (
																													'default' => '',
																													'collect' => '0',
																													'weight' => '12',
																												),
																												'country' => 
																												array (
																													'default' => 'us',
																													'collect' => '1',
																													'weight' => '14',
																												),
																												'locpick' => 
																												array (
																													'default' => 
																													array (
																														'user_latitude' => '',
																														'user_longitude' => '',
																													),
																													'collect' => '1',
																													'weight' => '20',
																													'nodiff' => true,
																												),
																												'cck_preview_in_progress' => 
																												array (
																													'default' => true,
																												),
																												'location_settings' => 
																												array (
																													'default' => 
																													array (
																														'form' => 
																														array (
																															'fields' => 
																															array (
																																'name' => 
																																array (
																																	'default' => '',
																																	'collect' => '1',
																																	'weight' => '2',
																																),
																																'street' => 
																																array (
																																	'default' => '',
																																	'collect' => '1',
																																	'weight' => '4',
																																),
																																'additional' => 
																																array (
																																	'default' => '',
																																	'collect' => '1',
																																	'weight' => '6',
																																),
																																'city' => 
																																array (
																																	'default' => '',
																																	'collect' => '1',
																																	'weight' => '8',
																																),
																																'province' => 
																																array (
																																	'default' => '',
																																	'collect' => '1',
																																	'weight' => '10',
																																),
																																'postal_code' => 
																																array (
																																	'default' => '',
																																	'collect' => '0',
																																	'weight' => '12',
																																),
																																'country' => 
																																array (
																																	'default' => 'us',
																																	'collect' => '1',
																																	'weight' => '14',
																																),
																																'locpick' => 
																																array (
																																	'default' => 
																																	array (
																																		'user_latitude' => '',
																																		'user_longitude' => '',
																																	),
																																	'collect' => '1',
																																	'weight' => '20',
																																	'nodiff' => true,
																																),
																																'cck_preview_in_progress' => 
																																array (
																																	'default' => true,
																																),
																																'location_settings' => 
																																array (
																																	'default' => 
																																	array (
																																		'form' => 
																																		array (
																																			'fields' => 
																																			array (
																																				'name' => 
																																				array (
																																					'default' => '',
																																					'collect' => '1',
																																					'weight' => '2',
																																				),
																																				'street' => 
																																				array (
																																					'default' => '',
																																					'collect' => '1',
																																					'weight' => '4',
																																				),
																																				'additional' => 
																																				array (
																																					'default' => '',
																																					'collect' => '1',
																																					'weight' => '6',
																																				),
																																				'city' => 
																																				array (
																																					'default' => '',
																																					'collect' => '1',
																																					'weight' => '8',
																																				),
																																				'province' => 
																																				array (
																																					'default' => '',
																																					'collect' => '1',
																																					'weight' => '10',
																																				),
																																				'postal_code' => 
																																				array (
																																					'default' => '',
																																					'collect' => '0',
																																					'weight' => '12',
																																				),
																																				'country' => 
																																				array (
																																					'default' => 'us',
																																					'collect' => '1',
																																					'weight' => '14',
																																				),
																																				'locpick' => 
																																				array (
																																					'default' => 
																																					array (
																																						'user_latitude' => '',
																																						'user_longitude' => '',
																																					),
																																					'collect' => '1',
																																					'weight' => '20',
																																					'nodiff' => true,
																																				),
																																				'cck_preview_in_progress' => 
																																				array (
																																					'default' => true,
																																				),
																																				'location_settings' => 
																																				array (
																																					'default' => 
																																					array (
																																						'form' => 
																																						array (
																																							'fields' => 
																																							array (
																																								'lid' => 
																																								array (
																																									'default' => false,
																																								),
																																								'name' => 
																																								array (
																																									'default' => '',
																																									'collect' => 1,
																																									'weight' => 2,
																																								),
																																								'street' => 
																																								array (
																																									'default' => '',
																																									'collect' => 1,
																																									'weight' => 4,
																																								),
																																								'additional' => 
																																								array (
																																									'default' => '',
																																									'collect' => 1,
																																									'weight' => 6,
																																								),
																																								'city' => 
																																								array (
																																									'default' => '',
																																									'collect' => 0,
																																									'weight' => 8,
																																								),
																																								'province' => 
																																								array (
																																									'default' => '',
																																									'collect' => 0,
																																									'weight' => 10,
																																								),
																																								'postal_code' => 
																																								array (
																																									'default' => '',
																																									'collect' => 0,
																																									'weight' => 12,
																																								),
																																								'country' => 
																																								array (
																																									'default' => 'us',
																																									'collect' => 1,
																																									'weight' => 14,
																																								),
																																								'locpick' => 
																																								array (
																																									'default' => false,
																																									'collect' => 1,
																																									'weight' => 20,
																																									'nodiff' => true,
																																								),
																																								'latitude' => 
																																								array (
																																									'default' => 0,
																																								),
																																								'longitude' => 
																																								array (
																																									'default' => 0,
																																								),
																																								'source' => 
																																								array (
																																									'default' => 0,
																																								),
																																								'is_primary' => 
																																								array (
																																									'default' => 0,
																																								),
																																								'delete_location' => 
																																								array (
																																									'default' => false,
																																									'nodiff' => true,
																																								),
																																							),
																																						),
																																					),
																																				),
																																				'lid' => 
																																				array (
																																					'default' => false,
																																				),
																																				'latitude' => 
																																				array (
																																					'default' => 0,
																																				),
																																				'longitude' => 
																																				array (
																																					'default' => 0,
																																				),
																																				'source' => 
																																				array (
																																					'default' => 0,
																																				),
																																				'is_primary' => 
																																				array (
																																					'default' => 0,
																																				),
																																				'delete_location' => 
																																				array (
																																					'default' => false,
																																					'nodiff' => true,
																																				),
																																			),
																																		),
																																		'display' => 
																																		array (
																																			'hide' => 
																																			array (
																																				'name' => 0,
																																				'street' => 0,
																																				'additional' => 0,
																																				'city' => 0,
																																				'province' => 0,
																																				'postal_code' => 0,
																																				'country' => 0,
																																				'locpick' => 0,
																																				'province_name' => 0,
																																				'country_name' => 0,
																																				'map_link' => 0,
																																				'coords' => 0,
																																			),
																																		),
																																	),
																																),
																																'lid' => 
																																array (
																																	'default' => false,
																																),
																																'latitude' => 
																																array (
																																	'default' => 0,
																																),
																																'longitude' => 
																																array (
																																	'default' => 0,
																																),
																																'source' => 
																																array (
																																	'default' => 0,
																																),
																																'is_primary' => 
																																array (
																																	'default' => 0,
																																),
																																'delete_location' => 
																																array (
																																	'default' => false,
																																	'nodiff' => true,
																																),
																															),
																														),
																														'display' => 
																														array (
																															'hide' => 
																															array (
																																'name' => 0,
																																'street' => 0,
																																'additional' => 0,
																																'city' => 0,
																																'province' => 0,
																																'postal_code' => 0,
																																'country' => 0,
																																'locpick' => 0,
																																'province_name' => 0,
																																'country_name' => 0,
																																'map_link' => 0,
																																'coords' => 0,
																															),
																														),
																													),
																												),
																												'lid' => 
																												array (
																													'default' => false,
																												),
																												'latitude' => 
																												array (
																													'default' => 0,
																												),
																												'longitude' => 
																												array (
																													'default' => 0,
																												),
																												'source' => 
																												array (
																													'default' => 0,
																												),
																												'is_primary' => 
																												array (
																													'default' => 0,
																												),
																												'delete_location' => 
																												array (
																													'default' => false,
																													'nodiff' => true,
																												),
																											),
																										),
																										'display' => 
																										array (
																											'hide' => 
																											array (
																												'name' => 0,
																												'street' => 0,
																												'additional' => 0,
																												'city' => 0,
																												'province' => 0,
																												'postal_code' => 0,
																												'country' => 0,
																												'locpick' => 0,
																												'province_name' => 0,
																												'country_name' => 0,
																												'map_link' => 0,
																												'coords' => 0,
																											),
																										),
																									),
																								),
																								'lid' => 
																								array (
																									'default' => false,
																								),
																								'latitude' => 
																								array (
																									'default' => 0,
																								),
																								'longitude' => 
																								array (
																									'default' => 0,
																								),
																								'source' => 
																								array (
																									'default' => 0,
																								),
																								'is_primary' => 
																								array (
																									'default' => 0,
																								),
																								'delete_location' => 
																								array (
																									'default' => false,
																									'nodiff' => true,
																								),
																							),
																						),
																						'display' => 
																						array (
																							'hide' => 
																							array (
																								'name' => 0,
																								'street' => 0,
																								'additional' => 0,
																								'city' => 0,
																								'province' => 0,
																								'postal_code' => 0,
																								'country' => 0,
																								'locpick' => 0,
																								'province_name' => 0,
																								'country_name' => 0,
																								'map_link' => 0,
																								'coords' => 0,
																							),
																						),
																					),
																				),
																				'lid' => 
																				array (
																					'default' => false,
																				),
																				'latitude' => 
																				array (
																					'default' => 0,
																				),
																				'longitude' => 
																				array (
																					'default' => 0,
																				),
																				'source' => 
																				array (
																					'default' => 0,
																				),
																				'is_primary' => 
																				array (
																					'default' => 0,
																				),
																				'delete_location' => 
																				array (
																					'default' => false,
																					'nodiff' => true,
																				),
																			),
																		),
																		'display' => 
																		array (
																			'hide' => 
																			array (
																				'name' => 0,
																				'street' => 0,
																				'additional' => 0,
																				'city' => 0,
																				'province' => 0,
																				'postal_code' => 0,
																				'country' => 0,
																				'locpick' => 0,
																				'province_name' => 0,
																				'country_name' => 0,
																				'map_link' => 0,
																				'coords' => 0,
																			),
																		),
																	),
																),
																'lid' => 
																array (
																	'default' => false,
																),
																'latitude' => 
																array (
																	'default' => 0,
																),
																'longitude' => 
																array (
																	'default' => 0,
																),
																'source' => 
																array (
																	'default' => 0,
																),
																'is_primary' => 
																array (
																	'default' => 0,
																),
																'delete_location' => 
																array (
																	'default' => false,
																	'nodiff' => true,
																),
															),
														),
														'display' => 
														array (
															'hide' => 
															array (
																'name' => 0,
																'street' => 0,
																'additional' => 0,
																'city' => 0,
																'province' => 0,
																'postal_code' => 0,
																'country' => 0,
																'locpick' => 0,
																'province_name' => 0,
																'country_name' => 0,
																'map_link' => 0,
																'coords' => 0,
															),
														),
													),
												),
												'lid' => 
												array (
													'default' => false,
												),
												'latitude' => 
												array (
													'default' => 0,
												),
												'longitude' => 
												array (
													'default' => 0,
												),
												'source' => 
												array (
													'default' => 0,
												),
												'is_primary' => 
												array (
													'default' => 0,
												),
												'delete_location' => 
												array (
													'default' => false,
													'nodiff' => true,
												),
											),
										),
										'display' => 
										array (
											'hide' => 
											array (
												'name' => 0,
												'street' => 0,
												'additional' => 0,
												'city' => 0,
												'province' => 0,
												'postal_code' => 0,
												'country' => 0,
												'locpick' => 0,
												'province_name' => 0,
												'country_name' => 0,
												'map_link' => 0,
												'coords' => 0,
											),
										),
									),
								),
								'lid' => 
								array (
									'default' => false,
								),
								'latitude' => 
								array (
									'default' => 0,
								),
								'longitude' => 
								array (
									'default' => 0,
								),
								'source' => 
								array (
									'default' => 0,
								),
								'is_primary' => 
								array (
									'default' => 0,
								),
								'delete_location' => 
								array (
									'default' => false,
									'nodiff' => true,
								),
							),
						),
						'display' => 
						array (
							'hide' => 
							array (
								'name' => 0,
								'street' => 0,
								'additional' => 0,
								'city' => 0,
								'province' => 0,
								'postal_code' => 0,
								'country' => 0,
								'locpick' => 0,
								'province_name' => 0,
								'country_name' => 0,
								'map_link' => 0,
								'coords' => 0,
							),
						),
					),
				),
			),
		),
		'group' => 'group_image_info',
		'required' => 0,
		'multiple' => '0',
		'location_settings' => 
		array (
			'form' => 
			array (
				'fields' => 
				array (
					'name' => 
					array (
						'collect' => '1',
						'default' => '',
						'weight' => '2',
					),
					'street' => 
					array (
						'collect' => '1',
						'default' => '',
						'weight' => '4',
					),
					'additional' => 
					array (
						'collect' => '1',
						'default' => '',
						'weight' => '6',
					),
					'city' => 
					array (
						'collect' => '1',
						'default' => '',
						'weight' => '8',
					),
					'province' => 
					array (
						'collect' => '1',
						'default' => '',
						'weight' => '10',
					),
					'postal_code' => 
					array (
						'collect' => '0',
						'default' => '',
						'weight' => '12',
					),
					'country' => 
					array (
						'collect' => '1',
						'default' => 'us',
						'weight' => '14',
					),
					'locpick' => 
					array (
						'collect' => '1',
						'weight' => '20',
					),
				),
			),
			'display' => 
			array (
				'hide' => 
				array (
					'name' => 0,
					'street' => 0,
					'additional' => 0,
					'city' => 0,
					'province' => 0,
					'postal_code' => 0,
					'country' => 0,
					'locpick' => 0,
					'province_name' => 0,
					'country_name' => 0,
					'map_link' => 0,
					'coords' => 0,
				),
			),
		),
		'gmap_macro' => '[gmap ]',
		'gmap_marker' => 'default',
		'op' => 'Save field settings',
		'module' => 'location_cck',
		'widget_module' => 'location_cck',
		'columns' => 
		array (
			'lid' => 
			array (
				'type' => 'int',
				'unsigned' => true,
				'not null' => false,
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
				'format' => 'all',
				'exclude' => 1,
			),
			'full' => 
			array (
				'format' => 'all',
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
	'body_field' => '4',
	'revision_information' => '5',
	'author' => '6',
	'options' => '7',
	'comment_settings' => '8',
	'menu' => '3',
	'path' => '10',
	'detailed_question' => '9',
);