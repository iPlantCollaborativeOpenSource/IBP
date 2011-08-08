<?php if ($node->build_mode === NODE_BUILD_NORMAL): ?>
	<a name="comments"></a>
<?php endif; ?>
<div class="teaser-comments-container">
	<?php if (isset($show_all)): ?>
		<?php echo $show_all; ?>
	<?php endif; ?>
	<div class="teaser-comments">
		<?php echo $content; ?>
	</div>
</div>