<?php
// $Id: og_views.views.inc,v 1.13.4.11 2010/03/04 07:28:59 amitaibu Exp $

/**
 * Implementation of hook_views_handlers().
 */
function clade_subscriptions_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'clade_subscriptions') .'/includes',
    ),
    'handlers' => array(
      // filter
      // field
      // {clade_uid} fields
      'clade_subscriptions_handler_field_clade_uid' => array(
        'parent' => 'views_handler_field',
      ),
      'clade_subscriptions_handler_field_clade_uid_admins' => array(
        'parent' => 'clade_subscriptions_handler_field_clade_uid',
      ),
      'clade_subscriptions_handler_field_clade_uid_is_admin' => array(
        'parent' => 'clade_subscriptions_handler_field_clade_uid',
      ),
      'clade_subscriptions_handler_field_clade_uid_managelink' => array(
      	'parent' => 'clade_subscriptions_handler_field_clade_uid',
      ),
      'clade_subscriptions_handler_field_clade_uid_managelinkadmin' => array(
      	'parent' => 'clade_subscriptions_handler_field_clade_uid',
      ),
      
      // argument
      'clade_subscriptions_handler_argument_clade_uid_tid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_plugins().
 */
function clade_subscriptions_views_plugins() {
  return array();
}

/**
 * Implementation of hook_views_data().
 */
function clade_subscriptions_views_data() {
	$data = array();
  $data['clade_uid']['table']['group']  = t('Clade');
  $data['clade_uid']['table']['join'] = array(
    'clade' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
    'term_data' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  $data['clade_uid']['tid'] = array(
    'title' => t('Clade'),
    'help' => t('Clade that a user subscribes to.'),
    'relationship' => array(
      'title' => t('Clade (subscriber)'),
      'help' => t("Bring in information about the clade based on a user's subscription."),
      'base' => 'term_data',
      'field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Clade (subscriber)'),
    ),
    'argument' => array(
      'title' => t('Clade'),
      'handler' => 'clade_subscriptions_handler_argument_clade_uid_tid',
      'help' => t('<strong>Subscribers</strong> are filtered for a specific clade.'),
    ),
  );
  $data['clade_uid']['uid'] = array(
    'title' => t('Clade subscriber'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
      'help' => t("Clade: Clade in current user's subscriptions"),
    ),
   'argument' => array(
     'title' => t('Member of a clade'),
     'handler' => 'views_handler_argument_numeric',
     'help' => t("Clade: Clade in specified user's clades."),
   ),
  );
	$data['clade_uid']['admins'] = array(
    'title' => t('Clade: Clade managers'),
    'help' => t('Show the Clade managers'),
    'real field' => 'tid',
    'field' => array(
      'handler' => 'clade_subscriptions_handler_field_clade_uid_admins',
      'click sortable' => FALSE,
    ),
  );
  $data['clade_uid']['is_admin'] = array(
    'title' => t('Clade: Is member a manager in clade'),
    'help' => t('Add <em>admin</em> text if user is a clade manager.'),
    'field' => array(
      'handler' => 'clade_subscriptions_handler_field_clade_uid_is_admin',
      'click sortable' => TRUE,
    ),
    'sort' => array(
       'handler' => 'views_handler_sort',
    ),
  );
  $data['clade_uid']['created'] = array(
    'title' => t('Clade: Join date'),
    'help' => t('Date member joined clade.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
       'handler' => 'views_handler_sort',
    ),
  );
	$data['clade_uid']['managelink'] = array(
    'title' => t('Clade: Remove membership link'),
    'help' => t('A link to remove a clade member (Clade admin only).'),
    'real field' => 'uid',
    'field' => array(
      'handler' => 'clade_subscriptions_handler_field_clade_uid_managelink',
      'click sortable' => FALSE,
    ),
  );
	$data['clade_uid']['managelinkadmin'] = array(
    'title' => t('Clade: Create/remove admin link'),
    'help' => t('A link to create/revoke clade management permissions (Clade admin only).'),
    'real field' => 'uid',
    'field' => array(
      'handler' => 'clade_subscriptions_handler_field_clade_uid_managelinkadmin',
      'click sortable' => FALSE,
    ),
  );
  return $data;
}