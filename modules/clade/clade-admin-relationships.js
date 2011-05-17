Drupal.behaviors.clade_admin_relationships = function(context) {

	$('select.clade-relationships').bind('change', function() {
		var $this = $(this);
		var newval = $this.val();
		if (!newval) {
			newval = [];
		}
		var oldval = $this.data('oldval');
		var thisid = $this.attr('id').split('-')[3];
		if (oldval) {
			var diff = oldval.filter(function(i) { return !(newval.indexOf(i) > -1);});
			for (var i = 0; i < diff.length; i++) {
				$('#edit-groups-group-'+diff[i]+'-relations').find('option[value='+thisid+']').attr('selected','');
			}
		}
		for (var i = 0; i < newval.length; i++) {
			$('#edit-groups-group-'+newval[i]+'-relations').find('option[value='+thisid+']').attr('selected','selected');
		}
		$this.data('oldval', newval);
	});
	$('select.clade-relationships').each(function() {
		$(this).data('oldval',$(this).val());
	});
}