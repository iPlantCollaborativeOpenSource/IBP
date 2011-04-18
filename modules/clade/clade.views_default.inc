<?php
// $Id$

// Declare all the .view files in the views subdir that end in .view
function clade_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'clade'). '/views', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      $views[substr($file->name, 6)] = $view;
    }
  }
  return $views;
}

