<?php
/**
 * @file
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $submitted: Themed submission information output from
 *   theme_node_submitted().
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 *   The following applies only to viewers who are registered users:
 *   - node-by-viewer: Node is authored by the user currently viewing the page.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $build_mode: Build mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $build_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * The following variable is deprecated and will be removed in Drupal 7:
 * - $picture: This variable has been renamed $user_picture in Drupal 7.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see zen_preprocess()
 * @see zen_preprocess_node()
 * @see zen_process()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">
  <?php print $user_picture; ?>

  <?php if (!$page && $title): ?>
    <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>

  <?php if ($display_submitted): ?>
    <div class="meta"><span class="submitted">
			<?php print $submitted; ?>
    </span></div>
  <?php endif; ?>

	<?php
		$typeinfo = _content_type_info();
		$fields = $typeinfo['content types']['ibp_project']['fields'];
		
		$crops = array();
		$keywords = array();
		$crop_vid = variable_get('clade_vocabulary',0);
		foreach ($node->taxonomy as $tid => $term) {
			if ($term->vid == $crop_vid) {
				$crops[$tid] = $term;
			} else {
				$keywords[$tid] = $term;
			}
		}
	?>
  <div class="content">
		<?php print $ibp_project_number_rendered; ?>
		
		<?php if ($ibp_project_pi_rendered || $ibp_project_pi_text_rendered) : ?>
			<div class="field field-ibp-project-pi">
				<div class="field-label"><?php print $fields['ibp_project_pi']['widget']['label']; ?></div>
				<div class="field-items">
					<?php if ($ibp_project_pi_rendered) : ?>
						<div class="field-item">
							<?php print $ibp_project_pi[0]['view']; ?>
						</div>
					<?php endif; ?>
					<?php if ($ibp_project_pi_text_rendered) : ?>
						<div class="field-item">
							<?php print $ibp_project_pi_text[0]['view']; ?>
						</div>
					<?php endif; ?>
				</div>
			</div>
		<?php endif; ?>
		
		<?php if ($ibp_project_collaborators_rendered || $ibp_project_collaborators_text_rendered) : ?>
			<div class="field field-ibp-project-collaborators">
				<div class="field-label"><?php print $fields['ibp_project_collaborators']['widget']['label']; ?></div>
				<div class="field-items">
					<?php if ($ibp_project_collaborators_rendered) : ?>
						<?php foreach ($ibp_project_collaborators as $i => $collab) : ?>
							<div class="field-item"><?php print $collab['view']; ?></div>
						<?php endforeach; ?>
					<?php endif; ?>
					<?php if ($ibp_project_collaborators_text_rendered) : ?>
						<?php foreach ($ibp_project_collaborators_text as $i => $collab) : ?>
							<div class="field-item"><?php print $collab['view']; ?></div>
						<?php endforeach; ?>						
					<?php endif; ?>
				</div>
			</div>
		<?php endif; ?>
		
		<div class="crops">
			<div class="crops-label">Crop(s)</div>
			<div class="crops-items">
				<?php foreach ($crops as $tid => $term): ?>
					<div class="crops-item">
						<?php print l($term->name, taxonomy_term_path($term)); ?>
					</div>
				<?php endforeach; ?>
			</div>
		</div>
		
		<?php if (count($keywords)) : ?>
		<div class="keywords">
			<div class="keywords-label">Traits</div>
			<div class="keywords-items">
				<?php foreach ($keywords as $tid => $term): ?>
					<div class="keywords-item">
						<?php print l($term->name, taxonomy_term_path($term)); ?>
					</div>
				<?php endforeach; ?>
			</div>
		</div>
		<?php endif; ?>
		
  	<div class="node-body">
  		<div class="body-label"><?php print $node->content['#content_extra_fields']['body_field']['label']; ?></div>
  		<?php print $node->content['body']['#value']; ?>
  	</div>
  	
  	<?php
  		// proposals
  		if ($ibp_project_proposal_file_rendered) : ?>
	  		<h3>Project Proposal</h3>
				<?php print $ibp_project_proposal_file_rendered; ?>
  	<?php endif; ?>
  	
  	<?php
  		// reports
  		if ($ibp_project_report_file_rendered) : ?>
	  		<h3>Project Reports</h3>
				<?php print $ibp_project_proposal_file_rendered; ?>
  	<?php endif; ?>
  	
  	<?php
  		// publications
  		if ($ibp_project_publication_file_rendered) : ?>
	  		<h3>Project Publications</h3>
				<?php print $ibp_project_proposal_file_rendered; ?>
  	<?php endif; ?>
  	
  	<?php
  		// products
  		if ($ibp_project_product_file_rendered) : ?>
	  		<h3>Project Products</h3>
				<?php print $ibp_project_proposal_file_rendered; ?>
  	<?php endif; ?>
  	
  	<?php
  		// datasets
  		if ($ibp_project_dataset_file_rendered) : ?>
	  		<h3>Data sets for this project</h3>
				<?php print $ibp_project_proposal_file_rendered; ?>
  	<?php endif; ?>
  	
  	<?php if ($ibp_project_image_rendered) : ?>
  		<h3>Media for this project</h3>
  		<div class="project-media">
  		<?php
  			// media
  			$first = 1;
  			foreach ($ibp_project_image as $i => $image) {
  				if ($i % 9 == 0) {
  					if ($first) {
  						$first = 0;
  						print "<div>";
  					} else {
  						print "</div><div>";
  					}
  				}
  				print $image['view'];
  				print '<span class="image-desc">'.$image['data']['description'].'</span>';
  			}
			?>
  		</div></div>
  	<?php endif; ?>
  	
  </div>
  
  <?php print $links; ?>
</div><!-- /.node -->
