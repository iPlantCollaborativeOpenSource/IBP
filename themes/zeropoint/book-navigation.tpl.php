<?php
// $Id: book-navigation.tpl.php,v 1.1 2007/11/04 14:29:09 goba Exp $

/**
 * @file book-navigation.tpl.php
 * Default theme implementation to navigate books. Presented under nodes that
 * are a part of book outlines.
 *
 * Available variables:
 * - $tree: The immediate children of the current node rendered as an
 *   unordered list.
 * - $current_depth: Depth of the current node within the book outline.
 *   Provided for context.
 * - $prev_url: URL to the previous node.
 * - $prev_title: Title of the previous node.
 * - $parent_url: URL to the parent node.
 * - $parent_title: Title of the parent node. Not printed by default. Provided
 *   as an option.
 * - $next_url: URL to the next node.
 * - $next_title: Title of the next node.
 * - $has_links: Flags TRUE whenever the previous, parent or next data has a
 *   value.
 * - $book_id: The book ID of the current outline being viewed. Same as the
 *   node ID containing the entire outline. Provided for context.
 * - $book_url: The book/node URL of the current outline being viewed.
 *   Provided as an option. Not used by default.
 * - $book_title: The book/node title of the current outline being viewed.
 *   Provided as an option. Not used by default.
 *
 * @see template_preprocess_book_navigation()
 */
?>
<?php if ($tree || $parent_tree): ?>
  <div id="book-navigation-<?php print $book_id; ?>" class="<?php echo $classes; ?>">
  <?php if ($two_col) { ?>
  	<div class="right-back">
			<div class="left-back">
				<?php if ($parent_tree): ?>
				<div class="left">
					<div class="column-wrapper">
						<a class="parent-link" href="<?php print $parent_link_url; ?>" title="<?php print $parent_link_title; ?>"><?php print $parent_link_title; ?></a>
						<?php print $parent_tree; ?>
					</div>
				</div>
				<?php endif; ?>
				<?php if ($tree): ?>
				<div class="right">
					<div class="column-wrapper">
						<?php print $book_title; ?>
						<?php print $tree; ?>
					</div>
				</div>
				<?php endif; ?>
			</div>
  	</div>
  <?php } else { ?>
		<?php if ($parent_tree): ?>
		<div class="left">
			<div class="column-wrapper">
				<a class="parent-link" href="<?php print $parent_link_url; ?>" title="<?php print $parent_link_title; ?>"><?php print $parent_link_title; ?></a>
				<?php print $parent_tree; ?>
			</div>
		</div>
		<?php endif; ?>
		<?php if ($tree): ?>
		<div class="left">			
			<div class="column-wrapper">
				<?php print $book_title; ?>
				<?php print $tree; ?>
			</div>
		</div>
		<?php endif; ?>
  <?php } ?>
  </div>
<?php endif; ?>
