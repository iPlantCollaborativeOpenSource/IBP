; Drush Make file for IBP
;
; NOTE: this make file utilizes a patch for drush make
; that allows downloading of subtrees of git repos.
; http://drupal.org/node/1074748
;

core = 6.x

api = 2
projects[] = drupal

; Modules
projects[] = admin_menu
projects[] = advanced_help
projects[] = backup_migrate
projects[] = ctools
projects[] = BookMadeSimple 
projects[] = cck
projects[] = ed_readmore
projects[] = filefield
projects[] = imageapi
projects[] = imagecache
projects[] = imagefield
projects[] = jquery_ui
projects[] = jquery_update
projects[] = ldap_integration
projects[] = libraries
projects[] = link
projects[] = messaging
projects[] = menutrails
projects[] = mimemail
projects[] = notifications
projects[] = panels
projects[] = pathauto
projects[] = stringoverrides
projects[] = subpath_alias
projects[] = token
projects[] = url_alter
projects[] = user_relationships
projects[] = views
projects[] = webform

; Themes

projects[] = zen

; Custom Modules

; clade
projects[clade][download][type] = git
projects[clade][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
projects[clade][download][subtree] = modules/clade
projects[clade][type] = module

; jit
projects[jit][download][type] = git
projects[jit][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
projects[jit][download][subtree] = modules/jit
projects[jit][type] = module

; teaser_comments
projects[teaser_comments][download][type] = git
projects[teaser_comments][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
projects[teaser_comments][download][subtree] = modules/teaser_comments
projects[teaser_comments][type] = module

; ibp_theme
projects[teaser_comments][download][type] = git
projects[teaser_comments][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
projects[teaser_comments][download][subtree] = themes/ibp_theme
projects[teaser_comments][type] = theme

; Libraries

; JIT
libraries[jit][download][type] = get
libraries[jit][download][url] = http://thejit.org/downloads/Jit-2.0.1.zip
libraries[jit][type] = library

; getid3
libraries[getid3][download][type] = get
libraries[getid3][download][url] = http://downloads.sourceforge.net/project/getid3/getID3%28%29%201.x/1.8.5/getid3-1.8.5-20110218.zip
libraries[getid3][type] = library

; iphone_check
libraries[iphone_check][download][type] = git
libraries[iphone_check][download][url] = https://github.com/tdreyno/iphone-style-checkboxes.git
libraries[iphone_check][type] = library

; jquery-ui
libraries[jquery_ui][download][type] = get
libraries[jquery_ui][download][url] = http://jquery-ui.googlecode.com/files/jquery-ui-1.7.3.zip
libraries[jquery_ui][download][sha1] = 7707d98bce0c90b06fdd3cd3acbf53c46a2aceb5
libraries[jquery_ui][destination] = modules/jquery_ui
libraries[jquery_ui][directory_name] = jquery.ui
libraries[jquery_ui][type] = library

; jquery_autocomplete
libraries[jquery_autocomplete][download][type] = git
libraries[jquery_autocomplete][download][url] = https://github.com/agarzola/jQueryAutocompletePlugin.git
libraries[jquery_autocomplete][type] = library

