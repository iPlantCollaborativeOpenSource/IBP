<?php
$content['type']  = array (
  'name' => 'Post',
  'type' => 'clade_page',
  'description' => 'A posting within a Clade.',
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
  'parentmenu' => '0',
  'parentmenuen' => '0',
  'automenu_hide' => 0,
  'old_type' => 'clade_page',
  'orig_type' => 'clade_page',
  'module' => 'clade',
  'custom' => '0',
  'modified' => '1',
  'locked' => '1',
  'reset' => 'Reset to defaults',
  'comment' => '2',
  'comment_default_mode' => '2',
  'comment_default_order' => '2',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '0',
  'comment_preview' => '0',
  'comment_form_location' => '1',
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
    'label' => 'Attach an Image',
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
    'weight' => '-2',
    'group_name' => 'group_image_info',
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Image',
    'field_name' => 'field_clade_image',
    'type' => 'filefield',
    'widget_type' => 'imagefield_widget',
    'change' => 'Change basic information',
    'weight' => '7',
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
    'group' => 'group_image_info',
    'required' => 0,
    'multiple' => '0',
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
      'weight' => '7',
      'parent' => 'group_image_info',
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'clade_page_image_linked',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'clade_page_image_imagelink',
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
    'label' => 'Photographer/Artist',
    'field_name' => 'field_clade_image_photographer',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '8',
    'rows' => 5,
    'size' => '60',
    'description' => 'The photographer or creator of this image.',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_clade_image_photographer][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_clade_image_photographer' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_clade_image_photographer][0][value',
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
      'weight' => '8',
      'parent' => 'group_image_info',
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
    'label' => 'Copyright',
    'field_name' => 'field_clade_image_copyright',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '9',
    'rows' => 5,
    'size' => '60',
    'description' => 'Provide any copyright information for the image.',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_clade_image_copyright][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_clade_image_copyright' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_clade_image_copyright][0][value',
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
      'weight' => '9',
      'parent' => 'group_image_info',
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
    'label' => 'Source',
    'field_name' => 'field_clade_image_source',
    'type' => 'link',
    'widget_type' => 'link',
    'change' => 'Change basic information',
    'weight' => '10',
    'description' => 'Provide the source (with link to source, if possible.)',
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
      'field_clade_image_source' => 
      array (
        0 => 
        array (
          'title' => '',
          'url' => '',
        ),
      ),
    ),
    'group' => 'group_image_info',
    'required' => 0,
    'multiple' => '0',
    'validate_url' => 1,
    'url' => 'optional',
    'title' => 'required',
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
      'weight' => '10',
      'parent' => 'group_image_info',
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
  'body_field' => '-3',
  'revision_information' => '3',
  'author' => '2',
  'options' => '4',
  'comment_settings' => '6',
  'menu' => '0',
  'taxonomy' => '-4',
  'path' => '5',
  'detailed_question' => '1',
);
