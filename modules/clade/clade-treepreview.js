Drupal.behaviors.clade = function(context) {
	Drupal.clade.silentNodeForm(context);
};

Drupal.clade.readTree = function(tree, parentid) {
	$('input.parent-group[value=' + parentid + ']').each(
			function() {
				var foo = $(this);
				var bar = {};
				var titletd = foo.parent().parent().prev();
				if (titletd.children('.form-item').length > 0) {
					var field = titletd.children('.form-item').children('input');
					if (field.hasClass('silent-node-form')) {
						return;
					}
					bar['name'] = field.val().trim() + '*';
				} else {
					bar['name'] = titletd.text().trim();
				}
				var nid = foo.parent().prev().val();
				bar['id'] = 'tb_' + nid;
				bar['data'] = {};
				var active = foo.parent().next().val();
				bar['data']['active'] = active;
				bar['children'] = [];
				Drupal.clade.readTree(bar, nid);
				if (tree) {
					tree.children.push(bar);
				} else {
					tree = bar;
				}
			}
		);
	return tree;
};

Drupal.clade.silentNodeForm = function(context) {
	var fields = $('input.silent-node-form', context);
	fields.each(
			function() {
				var self = $(this);
				self.defaultValue = self.value;
				self.focus(
						function() {
							if (this.value == this.defaultValue) {
							    //console.log('focus');
								this.value = '';
							}
							$(this).removeClass('silent-node-form');
						}
					);
				self.blur(
						function() {
							if (this.value == '') {
							    //console.log('blur');
								this.value = this.defaultValue;
								$(this).addClass('silent-node-form');
							} else {
								// check if removed from tree i.e. parent == 0?
								if ($(this).parent().parent().next().find('.parent-group').val() == 0) {
									$(this).addClass('silent-node-form');
								}
							}
						}
					);
			}
		);
	$('input.silent-node-form', context).parents('form:first').submit(
			function() {
				fields.each(
						function() {
							if (this.value == this.defaultValue) {
								this.value = '';
							}
						}
					);
			}
		);
};

Drupal.clade.refreshPreview = function(stid) {
	if (typeof(window.jit_spacetree) !== "undefined") {
		window.jit_spacetree[stid].render(Drupal.clade.readTree(null, 0));
	}
	return false;
};
