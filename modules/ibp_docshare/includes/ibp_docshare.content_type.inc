<?php
function ibp_docshare_content_type_def() {
  $content['type']  = array (
    'name' => 'IBP Shared Document',
    'type' => 'ibp_docshare',
    'description' => 'A shared document content type.  Allows multiple users to work on the same document and track the versioning of that document.',
    'title_label' => 'Document name',
    'body_label' => 'Description',
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
    'parentmenu' => '0',
    'parentmenuzh-hans' => '0',
    'parentmenuen' => '0',
    'automenu_hide' => 0,
    'old_type' => 'docshare',
    'orig_type' => '',
    'module' => 'node',
    'custom' => '1',
    'modified' => '1',
    'locked' => '0',
    'content_profile_use' => 0,
    'comment' => '2',
    'comment_default_mode' => '4',
    'comment_default_order' => '1',
    'comment_default_per_page' => '50',
    'comment_controls' => '3',
    'comment_anonymous' => 0,
    'comment_subject_field' => '1',
    'comment_preview' => '1',
    'comment_form_location' => '0',
  );
  $content['fields']  = array (
    0 => 
    array (
      'label' => 'Document',
      'field_name' => 'ibp_docshare_document',
      'type' => 'fileversion',
      'widget_type' => 'fileversion_widget',
      'change' => 'Change basic information',
      'weight' => '-2',
      'file_extensions' => '',
      'progress_indicator' => 'bar',
      'file_path' => '',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'description' => '',
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'op' => 'Save field settings',
      'module' => 'fileversion',
      'widget_module' => 'fileversion',
      'columns' => 
      array (
        'value' => 
        array (
          'type' => 'varchar',
          'length' => 255,
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
      'label' => 'Crop community',
      'field_name' => 'ibp_docshare_crop',
      'type' => 'content_taxonomy',
      'widget_type' => 'content_taxonomy_select',
      'change' => 'Change basic information',
      'weight' => '-1',
      'show_depth' => 1,
      'group_parent' => '0',
      'description' => 'If you want to share this document in a community, please select the community.',
      'default_value' => 
      array (
        0 => 
        array (
          'value' => '',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' => NULL,
      'group' => false,
      'required' => 0,
      'multiple' => '1',
      'save_term_node' => 0,
      'vid' => '1',
      'parent' => '0',
      'parent_php_code' => '',
      'depth' => '',
      'op' => 'Save field settings',
      'module' => 'content_taxonomy',
      'widget_module' => 'content_taxonomy_options',
      'columns' => 
      array (
        'value' => 
        array (
          'type' => 'int',
          'not null' => false,
          'sortable' => false,
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
          'format' => 'link',
          'exclude' => 0,
        ),
        'full' => 
        array (
          'format' => 'link',
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
    'revision_information' => '1',
    'author' => '0',
    'options' => '2',
    'comment_settings' => '4',
    'menu' => '-4',
    'path' => '5',
  );
  return $content;
}