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
projects[] = "admin_menu"
projects[] = "advanced_help"
projects[] = "automenu"
projects[] = "auto_nodetitle"
projects[] = "backup_migrate"
projects[] = "biblio"
;projects[] = "biblio_helper"
projects[] = "calendar"
projects[] = "cck"
projects[] = "ckeditor"
;projects[] = "clade"
projects[] = "content_profile"
projects[] = "content_taxonomy"
projects[] = "countries_api"
projects[] = "css_names"
projects[] = "ctools"
projects[] = "date"
projects[] = "devel"
projects[] = "drupalchat"
projects[] = "ed_readmore"
projects[] = "faq"
projects[] = "filefield"
projects[] = "filefield_track"
projects[] = "fpa"
projects[] = "getid3"
projects[] = "globalredirect"
projects[] = "google_analytics"
projects[] = "i18n"
projects[] = "i18nmenu_node"
projects[] = "i18nviews"
;projects[] = "ibphelper"
;projects[] = "ibp_projects"
;projects[] = "ibp_variety_releases"
projects[] = "imageapi"
projects[] = "imagecache"
projects[] = "imagecache_profiles"
projects[] = "imagefield"
projects[] = "imce"
;projects[] = "jit"
projects[] = "jquery_ui"
projects[] = "jquery_update"
projects[] = "l10n_update"
projects[] = "lang_dropdown"
projects[] = "languageicons"
projects[] = "ldap_integration"
projects[] = "libraries"
projects[] = "link"
projects[] = "location"
projects[] = "menu_block"
projects[] = "menu_per_role"
projects[] = "menutrails"
projects[] = "messaging"
projects[] = "mimemail"
projects[] = "multiblock"
projects[] = "node_convert"
projects[] = "noreqnewpass"
projects[] = "notifications"
projects[] = "panels"
projects[] = "pathauto"
projects[] = "permissions_api"
projects[] = "phone"
projects[] = "potx"
projects[] = "profile_migrate"
projects[] = "revision_deletion"
projects[] = "role_delegation"
projects[] = "rules"
projects[] = "site_map"
projects[] = "stringoverrides"
projects[] = "subpath_alias"
projects[] = "taxonomy_menu"
projects[] = "taxonomy_menu_trails"
;projects[] = "teaser_comments"
projects[] = "token"
projects[] = "translation_overview"
projects[] = "translation_table"
projects[] = "transliteration"
projects[] = "upload_replace"
projects[] = "url_alter"
projects[] = "user_relationships"
projects[] = "views"
projects[] = "views_or"
projects[] = "webform"
projects[] = "xmlsitemap"

;projects[] = "admin_menu"
;projects[] = "advanced_help"
;projects[] = "auto_nodetitle"
;projects[] = "automenu"
;projects[] = "backup_migrate"
;projects[] = "biblio"
;projects[] = "ctools"
;projects[] = "calendar"
;projects[] = "cck"
;projects[] = "content_profile"
;projects[] = "content_taxonomy"
;projects[] = "countries_api"
;projects[] = "css_names"
;projects[] = "date"
;projects[] = "drupalchat"
;projects[] = "ed_readmore"
;projects[] = "faq"
;projects[] = "filefield"
;projects[] = "filefield_track"
;projects[] = "fpa"
;projects[] = "globalredirect"
;projects[] = "google_analytics"
;projects[] = "imageapi"
;projects[] = "imagecache"
;projects[] = "imagecache_profiles"
;projects[] = "imagefield"
;projects[] = "imce"
;projects[] = "jquery_ui"
;projects[] = "jquery_update"
;projects[] = "ldap_integration"
;projects[] = "libraries"
;projects[] = "link"
;projects[] = "location"
;projects[] = "menu_block"
;projects[] = "messaging"
;projects[] = "mimemail"
;projects[] = "multiblock"
;projects[] = "node_convert"
;projects[] = "noreqnewpass"
;projects[] = "notifications"
;projects[] = "panels"
;projects[] = "pathauto"
;projects[] = "phone"
;projects[] = "revision_deletion"
;projects[] = "role_delegation"
;projects[] = "rules"
;projects[] = "site_map"
;projects[] = "stringoverrides"
;projects[] = "subpath_alias"
;projects[] = "taxonomy_menu"
;projects[] = "taxonomy_menu_trails"
;projects[] = "token"
;projects[] = "transliteration"
;projects[] = "upload_replace"
;projects[] = "url_alter"
;projects[] = "user_relationships"
;projects[] = "views"
;projects[] = "views_or"
;projects[] = "webform"
;projects[] = "xmlsitemap"
;
;; Translation modules
;projects[] = "i18n"
;projects[] = "i18nmenu_node"
;projects[] = "i18nviews"
;projects[] = "l10n_update"
;projects[] = "lang_dropdown"
;projects[] = "languageicons"
;projects[] = "potx"
;projects[] = "translation_overview"
;projects[] = "translation_table"

; Themes

projects[] = zen

; Custom Modules
; INSTALL THESE MODULES FROM GIT
;; clade
;projects[clade][download][type] = git
;projects[clade][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
;projects[clade][download][subtree] = modules/clade
;projects[clade][type] = module
;
;; ibphelper
;projects[ibphelper][download][type] = git
;projects[ibphelper][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
;projects[ibphelper][download][subtree] = modules/ibphelper
;projects[ibphelper][type] = module
;
;; ibp_projects
;projects [ibp_projects][download][type] = git
;projects [ibp_projects][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
;projects [ibp_projects][download][subtree] = modules ibp_projects
;projects [ibp_projects][type] = module
;
;; ibp_variety_releases
;projects[ibp_variety_releases][download][type] = git
;projects[ibp_variety_releases][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
;projects[ibp_variety_releases][download][subtree] = modules/ibp_variety_releases
;projects[ibp_variety_releases][type] = module
;
;; jit
;projects[jit][download][type] = git
;projects[jit][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
;projects[jit][download][subtree] = modules/jit
;projects[jit][type] = module
;
;; teaser_comments
;projects[teaser_comments][download][type] = git
;projects[teaser_comments][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
;projects[teaser_comments][download][subtree] = modules/teaser_comments
;projects[teaser_comments][type] = module
;
;; ibp_theme
;projects[teaser_comments][download][type] = git
;projects[teaser_comments][download][url] = git@github.com:iPlantCollaborativeOpenSource/IBP.git
;projects[teaser_comments][download][subtree] = themes/ibp_theme
;projects[teaser_comments][type] = theme

; Libraries

; JIT
libraries[jit][download][type] = get
libraries[jit][download][url] = http://thejit.org/downloads/Jit-2.0.1.zip
libraries[jit][type] = library

;ckeditor
; use drush command `drush ckeditor-download`

; getid3
; use drush command `drush getid3-download`
;libraries[getid3][download][type] = get
;libraries[getid3][download][url] = http://downloads.sourceforge.net/project/getid3/getID3%28%29%201.x/1.8.5/getid3-1.8.5-20110218.zip
;libraries[getid3][type] = library

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

; yui for drupalchat
libraries[yui][download][type] = get
libraries[yui][download][url] = http://yui.zenfs.com/releases/yui3/yui_3.5.1.zip
libraries[yui][type] = library