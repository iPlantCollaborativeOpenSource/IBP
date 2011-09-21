<?php

function _ibp_variety_releases_ibp_variety_release_content_type_def() {
	$content['type']  = array (
		'name' => 'IBP Variety Release',
		'type' => 'ibp_variety_release',
		'description' => '',
		'title_label' => 'Release Name',
		'body_label' => 'Release Details',
		'min_word_count' => '0',
		'help' => '',
		'node_options' => 
		array (
			'status' => true,
			'promote' => true,
			'sticky' => false,
			'revision' => false,
		),
		'parentmenu' => '0',
		'parentmenuen' => '0',
		'automenu_hide' => 0,
		'old_type' => 'ibp_variety_release',
		'orig_type' => '',
		'module' => 'ibp_variety_releases',
		'custom' => '1',
		'modified' => '1',
		'locked' => '0',
		'comment' => '0',
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
			'label' => 'Links',
			'field_name' => 'ibp_variety_release_links',
			'type' => 'link',
			'widget_type' => 'link',
			'change' => 'Change basic information',
			'weight' => '-3',
			'description' => 'Provide any links to more information about this release.',
			'default_value' => 
			array (
				0 => 
				array (
					'title' => '',
					'url' => '',
				),
			),
			'default_value_php' => '',
			'default_value_widget' => NULL,
			'group' => false,
			'required' => 0,
			'multiple' => '1',
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
				'target' => 'user',
				'rel' => '',
				'class' => '',
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
		'body_field' => '-4',
		'revision_information' => '1',
		'author' => '0',
		'options' => '2',
		'comment_settings' => '3',
		'menu' => '-2',
		'path' => '-1',
		'detailed_question' => '4',
	);
	return $content;
}
