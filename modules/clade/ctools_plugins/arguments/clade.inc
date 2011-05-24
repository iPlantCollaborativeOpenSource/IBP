<?php
// $Id$

/**
 * @file
 *
 * Plugin to provide an argument handler for a clade
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Clade"),
  'keyword' => 'clade',
  'description' => t('Creates a clade context from a clade.'),
  'context' => 'clade_argument_clade_context',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the tid of a clade for this argument'),
  ),
);

/**
 * Discover if this argument gives us the node we crave.
 */
function clade_argument_clade_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('clade');
  }

  // We can accept either a node object or a pure nid.
  if (is_object($arg)) {
    return ctools_context_create('clade', $arg);
  }

  if (!is_numeric($arg)) {
    return FALSE;
  }

  $clade = clade_load($arg);
  if (!$node) {
    return FALSE;
  }

  return ctools_context_create('clade', $clade);
}

