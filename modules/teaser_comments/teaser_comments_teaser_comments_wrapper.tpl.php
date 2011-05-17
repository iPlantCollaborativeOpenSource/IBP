<div class="teaser-comments-container">
	<?php if ($num_comments > 0) : ?>
		<?php if (isset($show_all)): ?>
			<?php echo $show_all; ?>
		<?php endif; ?>
		<div class="teaser-comments">
			<?php echo $content; ?>
		</div>
	<?php endif; ?>
	<?php if (isset($comment_form)) : ?>
	<div class="teaser-comment-form">
		<?php echo $comment_form; ?>
	</div>
	<?php endif; ?>
</div>