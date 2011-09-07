<?php
// $Id$

// Declare all the .view files in the views subdir that end in .view
function clade_forum_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'clade_forum'). '/views', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      $views[substr($file->name, 6)] = $view;
    }
  }
  return $views;
}