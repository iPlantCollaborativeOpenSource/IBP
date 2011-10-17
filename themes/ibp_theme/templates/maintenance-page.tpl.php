<?php
/**
 * @file maintenance-page.tpl.php
 *
 * Theme implementation to display a single Drupal page while off-line.
 *
 * All the available variables are mirrored in page.tpl.php. Some may be left
 * blank but they are provided for consistency.
 *
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">

  <div id="page-wrapper"><div id="page">

    <div id="header"><div class="section clearfix">

      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
      <?php endif; ?>
			
      <?php if ($site_name || $site_slogan): ?>
        <div id="name-and-slogan">
          <?php if ($site_name): ?>
            <?php if ($title): ?>
              <div id="site-name">
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </div>
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

      <?php print $header; ?>
      
			<div id="navigation">
				<?php print $navigation; ?>
				<div class="subnavigation"></div>
			</div><!-- /#navigation -->

    </div></div><!-- /.section, /#header -->

		<div id="main-topper"><div class="section clearfix">
			<?php if ($title): ?>
				<h1 class="title">
					<?php print $title; ?>
				</h1>
			<?php endif; ?>
			<?php print $breadcrumb; ?>
			<?php if ($tabs): ?>
				<div class="tabs"><?php print $tabs; ?></div>
			<?php endif; ?>
		</div></div>
		
    <div id="main-wrapper">
    	<div id="main">
				<div id="columns">
					<div id="content-wrapper">
						<div id="content">
							<div class="section">
								<?php if ($mission): ?>
									<div id="mission"><?php print $mission; ?></div>
								<?php endif; ?>
				
								<?php print $highlight; ?>
				
								<?php print $help; ?>
				
								<?php print $content_top; ?>
				
								<div id="content-area">
									<?php print $content; ?>
								</div>
				
								<?php print $content_bottom; ?>
				
								<?php if ($feed_icons): ?>
									<div class="feed-icons"><?php print $feed_icons; ?></div>
								<?php endif; ?>
							</div>
						</div>
					</div>
					<?php print $sidebar_first; ?>
					<?php print $sidebar_second; ?>
				</div>
    	</div>
    </div><!-- /#main, /#main-wrapper -->

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
