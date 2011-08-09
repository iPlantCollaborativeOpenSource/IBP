<?php
/**
 * @file
 * Theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $css: An array of CSS files for the current page.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/garland.
 * - $is_front: TRUE if the current page is the front page. Used to toggle the mission statement.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Page metadata:
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $head_title: A modified version of the page title, for use in the TITLE tag.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It should be placed within the <body> tag. When selecting through CSS
 *   it's recommended that you use the body tag, e.g., "body.front". It can be
 *   manipulated through the variable $classes_array from preprocess functions.
 *   The default values can be one or more of the following:
 *   - front: Page is the home page.
 *   - not-front: Page is not the home page.
 *   - logged-in: The current viewer is logged in.
 *   - not-logged-in: The current viewer is not logged in.
 *   - node-type-[node type]: When viewing a single node, the type of that node.
 *     For example, if the node is a "Blog entry" it would result in "node-type-blog".
 *     Note that the machine name will often be in a short form of the human readable label.
 *   - page-views: Page content is generated from Views. Note: a Views block
 *     will not cause this class to appear.
 *   - page-panels: Page content is generated from Panels. Note: a Panels block
 *     will not cause this class to appear.
 *   The following only apply with the default 'sidebar_first' and 'sidebar_second' block regions:
 *     - two-sidebars: When both sidebars have content.
 *     - no-sidebars: When no sidebar content exists.
 *     - one-sidebar and sidebar-first or sidebar-second: A combination of the
 *       two classes when only one of the two sidebars have content.
 * - $node: Full node object. Contains data that may not be safe. This is only
 *   available if the current page is on the node's primary url.
 * - $menu_item: (array) A page's menu item. This is only available if the
 *   current page is in the menu.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $mission: The text of the site mission, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $search_box: HTML to display the search box, empty if search has been disabled.
 * - $primary_links (array): An array containing the Primary menu links for the
 *   site, if they have been configured.
 * - $secondary_links (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title: The page title, for use in the actual HTML content.
 * - $messages: HTML for status and error messages. Should be displayed prominently.
 * - $tabs: Tabs linking to any sub-pages beneath the current page (e.g., the
 *   view and edit tabs when displaying a node).
 * - $help: Dynamic help text, mostly for admin pages.
 * - $content: The main content of the current page.
 * - $feed_icons: A string of all feed icons for the current page.
 *
 * Footer/closing data:
 * - $footer_message: The footer message as defined in the admin settings.
 * - $closure: Final closing markup from any modules that have altered the page.
 *   This variable should always be output last, after all other dynamic content.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * Regions:
 * - $content_top: Items to appear above the main content of the current page.
 * - $content_bottom: Items to appear below the main content of the current page.
 * - $navigation: Items for the navigation bar.
 * - $sidebar_first: Items for the first sidebar.
 * - $sidebar_second: Items for the second sidebar.
 * - $header: Items for the header region.
 * - $footer: Items for the footer region.
 * - $page_closure: Items to appear below the footer.
 *
 * The following variables are deprecated and will be removed in Drupal 7:
 * - $body_classes: This variable has been renamed $classes in Drupal 7.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess()
 * @see zen_process()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <link rel="stylesheet" href="<?php print drupal_get_path('theme','ibp_theme').'/css/page-front.css'; ?>" />
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">

  <?php if ($primary_links): ?>
    <div id="skip-link"><a href="#main-menu"><?php print t('Jump to Navigation'); ?></a></div>
  <?php endif; ?>

  <div id="page-wrapper"><div id="page">

    <div id="header"><div class="section clearfix">

      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
      <?php endif; ?>
			
      <?php if ($site_name || $site_slogan): ?>
        <div id="name-and-slogan">
          <?php if ($site_name): ?>
            <?php if ($title): ?>
              <div id="site-name"><strong>
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </strong></div>
            <?php else: /* Use h1 when the content title is empty */ ?>
              <h1 id="site-name">
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </h1>
            <?php endif; ?>
          <?php endif; ?>

          <?php if ($site_slogan): ?>
            <div id="site-slogan"><?php print $site_slogan; ?></div>
          <?php endif; ?>
        </div><!-- /#name-and-slogan -->
      <?php endif; ?>
			
			<div id="top-bar">
				<?php print theme('loginlinks', $user); ?>
				<?php if ($search_box): ?>
					<div id="search-box"><?php print $search_box; ?></div>
				<?php endif; ?>
			</div>

      <?php print $header; ?>
      
			<?php if ($navigation): ?>
        <div id="navigation">
          <?php print $navigation; ?>
          <div class="subnavigation">
						<h3><?php print t('Providing resources and research communities for crop scientists in developing countries'); ?></h3>
          </div>
        </div><!-- /#navigation -->
      <?php endif; ?>

    </div></div><!-- /.section, /#header -->

		<div id="messages-wrapper"><?php print $messages; ?></div>
		
		<div id="main-topper">
			<div class="introduction-wrapper clearfix">
				<div class="introduction">
					The IBP is a sustainable, web-based, one-stop-shop for information,
					analytical tools and related services to design and carry out integrated
					breeding projects. IBP will boost crop productivity and resilience for
					smallholders in drought-prone environments by exploiting the economies
					of scale afforded by collective access to cutting-edge breeding
					technologies and informatics hitherto unavailable to breeders in
					developing countries.
				</div>
				<div class="front-image">
					<img alt="front image" src="<?php print drupal_get_path('theme','ibp_theme') . '/images/front-image-1.png'; ?>" />
				</div>
				<div class="action clearfix">
					<?php if ($logged_in) { ?>
						<span>Welcome, <?php profile_load_profile($user); print ($user->profile_first_name ? $user->profile_first_name . ' ' . $user->profile_last_name : $user->name); ?>!</span>
						<?php print l(t('Go to My Communities'), 'community', array('attributes' => array('class' => 'button'))); ?>
					<?php } else { ?>
						<span>Get started today by registering for a free account.</span>
						<?php print l(t('Register for an account'), 'user/register', array('attributes' => array('class' => 'button'))); ?>
					<?php } ?>
				</div>

			</div>
		</div>
		
    <div id="front-wrapper">
    	<div class="section clearfix">
    		<div class="column thirty">
    			<div class="column-inner">
    				<div class="column-header">
							<h3>Education</h3>
							<h4>Learn more about our focus crops</h4>
						</div>
						<?php
							$viewname = "crop_info_pages";
							print views_embed_view($viewname);
						?>
					</div>
    		</div>
    		<div class="column forty">
    			<div class="column-inner">
						<div class="column-header">
							<h3>Tools & Services</h3>
							<h4>Learn more about our features</h4>
						</div>
						<div class="column-section">
							<p>
								We have provided a complete and robust set of tools to aid any
								task. Out tools will help you accomplish several tasks including
								genotyping, project management and statistical analysis.
							</p>
							<p><?php print l(t('View Tools'), 'tools', array('attributes' => array('class' => 'go'))); ?></p>
						</div>
						<div class="column-section">
							<p>
								We can help you avoid bottlenecks with your sevice providers.  We
								work closely with many industry laboratories and service companies
								to provide a complete, low-cost support system.
							</p>
							<p><?php print l(t('View Services'), 'services', array('attributes' => array('class' => 'go'))); ?></p>
						</div>
    			</div>
    		</div>
    		<div class="column thirty">
    			<div class="column-inner">
						<div class="column-header">
							<h3>Communities</h3>
							<h4>See what's going on in your field</h4>
						</div>
						<?php
							$viewname = "clade_all_clades";
							print views_embed_view($viewname, 'block_1');
						?>
					</div>
    		</div>
    	</div>
    	
    	<div class="credits section clearfix">
    		<h3>IBP is a collaborative effort.  Various features of this site were brought to you by the following groups:</h3>
    		<div class="picture"><img alt="ICRISAT Logo" title="International Crops Research Insititute for the Semi-Arid Tropics" src="<?php print drupal_get_path('theme','ibp_theme').'/images/icrisat-logo.png'; ?>" /></div>
    		<div class="picture"><img alt="IRRI Logo" title="International Rice Research Institute" src="<?php print drupal_get_path('theme','ibp_theme').'/images/irri-logo.png'; ?>" /></div>
    		<div class="picture"><img alt="CIMMYT Logo" title="International Maize and Wheat Improvement Center" src="<?php print drupal_get_path('theme','ibp_theme').'/images/cimmyt-logo.png'; ?>" /></div>
    		<div class="picture"><img alt="iPlant Logo" title="iPlant Collaborative" src="<?php print drupal_get_path('theme','ibp_theme').'/images/iplant.logo50.jpg'; ?>" /></div>
    	</div>
    </div>
    
		<div id="page-bottom"><div class="section">
			<?php if ($tabs): ?>
				<div class="tabs"><?php print $tabs; ?></div>
			<?php endif; ?>

			<?php print $page_bottom; ?>
		</div></div>
		
		<a href="#" id="back-to-top">Back to top</a>

  </div></div><!-- /#page, /#page-wrapper -->

	<?php if ($footer || $footer_message): ?>
		<div id="footer"><div class="section">

			<?php if ($footer_message): ?>
				<div id="footer-message"><?php print $footer_message; ?></div>
			<?php endif; ?>

			<?php print $footer; ?>

		</div></div><!-- /.section, /#footer -->
	<?php endif; ?>

  <?php print $page_closure; ?>

  <?php print $closure; ?>

</body>
</html>
