Drupal.clade = {
/*
	initMenu: function() {
		$(".up").live('click',
				function() {
				  var nid = $(this).parent().attr('id');
					Drupal.clade.loadParentClade(nid);
				}
			);
		$(".closed").live('click',
				function() {
				  var nid = $(this).parent().attr('id');
					Drupal.clade.toggleSubclades(nid);
				}
			);
		$(".open").live('click',
				function() {
				  var nid = $(this).parent().attr('id');
					Drupal.clade.toggleSubclades(nid);
				}
			);
		$("._tg_menu_control").click(
		    function() {
		      class0 = "tray";
		      class1 = "tray1";
		      spd1 = 400;
		      var tray = $(this).parent();
		      if (tray.hasClass("tray")) {
            $(this).attr("title","Pop out Clades");
            // 100% w and h causes it to return to obeying the bounds of its parent
            tray.animate({"width":"100%","height":"100%"}, function() { tray.toggleClass("tray"); });
		      } else {
            $(this).attr("title","Pop in");
            tray.toggleClass("tray");
            tray.animate({"width":600, "height":400});
		      }
		      return false;
		    }
		  );
	},
	toggleSubclades: function(clade) {
		var cladediv = $("#"+clade);
		var children = cladediv.children(".descendants");
		if (children.length == 0) {
			Drupal.clade.loadSubclades(clade);
		} else {
			children.slideToggle(
			    'fast',
					function() {
						if (children.is(":visible")) {
							cladediv.children(".closed").removeClass("closed").addClass("open");
						} else {
							cladediv.children(".open").removeClass("open").addClass("closed");
						}
					}
				);
		}

	},
  loadSubclades: function(clade) {
  	nid = clade.replace('_tg_menu_','');
		var url = Drupal.settings.basePath + "treegroups/" + nid + "/load-children";
		$.ajax({
				url: url,
				method: 'GET',
				dataType: 'json',
				success: function(resp) {
					var cladediv = $('#'+clade);
					if (resp.status == 0) {
						children = $(resp.html);
						children.hide();
						cladediv.append(children);
						children.slideDown(
						    'fast',
								function() {
									cladediv.children(".closed").removeClass("closed").addClass("open");
								}
							);
					} else {
						cladediv.children(".closed").removeClass("closed").addClass("empty");
					}
				}
			});
	},
	loadParentClade: function(clade) {
		var nid = clade.replace('_tg_menu_','');
		var url = Drupal.settings.basePath + "treegroups/" + nid + "/load-parent";
		$.ajax({
				url: url,
				method: 'GET',
				dataType: 'json',
				success: function(resp) {
					var cladediv = $('#'+clade);
					var parent = $(resp.parent);
					var desc = $("<div class='descendants'>");
					parent.append(desc);
					for (var i = 0; i < resp.sibs_before.length; i++) {
					  desc.append(resp.sibs_before[i]);
					}
					desc.append(cladediv);
					if (resp.sibs_after.length == 0) {
					  cladediv.addClass("last");
					} else {
            for (var i = 0; i < resp.sibs_after.length; i++) {
              desc.append(resp.sibs_after[i]);
            }
          }
					$("._tg_menu").append(parent);
					cladediv.children(".up").removeClass("up").addClass("open");
				}
			});
	}
*/
};