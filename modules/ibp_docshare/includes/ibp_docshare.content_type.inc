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
    'old_type' => 'ibp_docshare',
    'orig_type' => '',
    'module' => 'ibp_docshare',
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
      'conditional_fields' =>
      array (
        'available_fields' =>
        array (
          'ibp_docshare_crop' => 'conditional_field_no_value',
          'ibp_docshare_access_type' => 'conditional_field_no_value',
          'ibp_docshare_allowed_users' => 'conditional_field_no_value',
        ),
      ),
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
      'conditional_fields' =>
      array (
        'available_fields' =>
        array (
          'ibp_docshare_access_type' => 'conditional_field_no_value',
          'ibp_docshare_allowed_users' => 'conditional_field_no_value',
        ),
      ),
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
        'weight' => '-1',
        'parent' => '',
        'label' =>
        array (
          'format' => 'above',
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
    2 =>
    array (
      'label' => 'Access restriction',
      'field_name' => 'ibp_docshare_access_type',
      'type' => 'text',
      'widget_type' => 'optionwidgets_buttons',
      'change' => 'Change basic information',
      'weight' => 0,
      'description' => 'Select the access permission for this Document.  ',
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
      'conditional_fields' =>
      array (
        'available_fields' =>
        array (
          'ibp_docshare_crop' => 'conditional_field_no_value',
        ),
      ),
      'required' => 1,
      'multiple' => '0',
      'text_processing' => '0',
      'max_length' => '',
      'allowed_values' => 'closed|Closed (only you can edit)
    open|Open (anyone can edit)
    community|Community (anyone in the community can edit)
    user|Specified users (only the specified users can edit)',
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
      'controlled_fields' =>
      array (
        'ibp_docshare_allowed_users' =>
        array (
          'user' => 'user',
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
      'label' => 'Allowed users',
      'field_name' => 'ibp_docshare_allowed_users',
      'type' => 'userreference',
      'widget_type' => 'userreference_autocomplete',
      'change' => 'Change basic information',
      'weight' => '1',
      'autocomplete_match' => 'contains',
      'size' => '60',
      'reverse_link' => 0,
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'uid' => NULL,
          '_error_element' => 'default_value_widget][ibp_docshare_allowed_users][0][uid][uid',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' => NULL,
      'group' => false,
      'conditional_fields' =>
      array (
        'available_fields' =>
        array (
          'ibp_docshare_crop' => 'conditional_field_no_value',
          'ibp_docshare_access_type' =>
          array (
            'user' => 'user',
          ),
        ),
      ),
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
        8 => 0,
        9 => 0,
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
        'weight' => 0,
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
    'comment_settings' => '5',
    'menu' => '-4',
    'path' => '6',
    'xmlsitemap' => '7',
  );
  return $content;
}