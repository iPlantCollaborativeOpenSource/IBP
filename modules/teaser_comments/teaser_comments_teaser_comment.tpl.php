<div class="<?php echo $classes; ?>" id="comment-<?php echo $comment->cid; ?>">
	<div class="author">
		<?php echo $author_picture; ?>
		<?php echo $author; ?>
	</div>
	<div class="comment-content">
		<?php echo $content; ?>
	</div>
	<?php if (isset($edit_form)): ?>
		<div class="teaser-comment-edit-form">
			<?php echo $edit_form; ?>
		</div>
	<?php endif; ?>
	<div class="meta">
		<?php echo $submitted; ?>
	</div>
	<?php print $links; ?>
	<?php if (isset($reply_form)) : ?>
		<div class="teaser-comment-reply-form">
			<?php echo $reply_form; ?>
		</div>
	<?php endif; ?>
</div>