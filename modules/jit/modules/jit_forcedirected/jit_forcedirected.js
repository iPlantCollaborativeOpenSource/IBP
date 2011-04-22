Drupal.jit.forceDirected = function(options) {

	var that = this;
	
	that.thisid = options['id'];
	that.jitctxt = jQuery('#' + that.thisid);
	
	var ua = navigator.userAgent,
      iStuff = ua.match(/iPhone/i) || ua.match(/iPad/i),
      typeOfCanvas = typeof HTMLCanvasElement,
      nativeCanvasSupport = (typeOfCanvas == 'object' || typeOfCanvas == 'function'),
      textSupport = nativeCanvasSupport && (typeof document.createElement('canvas').getContext('2d').fillText == 'function'),
			// I'm setting this based on the fact that ExCanvas provides text support for IE
			// and that as of today iPhone/iPad current text support is lame
			labelType = (!nativeCanvasSupport || (textSupport && !iStuff))? 'Native' : 'HTML',
			nativeTextSupport = labelType == 'Native',
			useGradients = nativeCanvasSupport,
			animate = !(iStuff || !nativeCanvasSupport);

	var highlightAdj = function(node) {
		that.fd.graph.eachNode(function(n) {
			n.eachAdjacency(function(adj) {
				adj.removeData('lineWidth');
			});
		});
		if (node) {
			node.eachAdjacency(function(adj) {
				adj.setData('lineWidth', node.Edge.lineWidth + 1.6);
			});
		}
		that.fd.plot();
	};
	
	var defaults = {
		    //id of the visualization container
    injectInto: that.thisid,
    height: 300,
    //Enable zooming and panning
    //by scrolling and DnD
    Navigation: {
      enable: true,
      //Enable panning events only if we're dragging the empty
      //canvas (and not a node).
      panning: 'avoid nodes',
      zooming: 25 //zoom speed. higher is more sensible
    },
    // Change node and edge styles such as
    // color and width.
    // These properties are also set per node
    // with dollar prefixed data-properties in the
    // JSON structure.
    Node: {
      overridable: true
    },
    Edge: {
      overridable: true,
      color: '#23A4FF',
      lineWidth: 0.4
    },
    //Native canvas text styling
    Label: {
      type: labelType, //Native or HTML
      size: 10,
      style: 'normal',
      color: '#454545'
    },
    //Add Tips
    Tips: {
      enable: true,
      onShow: function(tip, node) {
        //count connections
        var count = 0;
        node.eachAdjacency(function() { count++; });
        //display node info in tooltip
        tip.innerHTML = "<div class=\"tip-title\">" + node.name + "</div>"
          + "<div class=\"tip-text\"><b>connections:</b> " + count + "</div>";
      }
    },
    // Add node events
    Events: {
      enable: true,
      //Change cursor style when hovering a node
      onMouseEnter: function() {
        that.fd.canvas.getElement().style.cursor = 'move';
      },
      onMouseLeave: function() {
        that.fd.canvas.getElement().style.cursor = '';
      },
      //Update node positions when dragged
      onDragMove: function(node, eventInfo, e) {
          var pos = eventInfo.getPos();
          node.pos.setc(pos.x, pos.y);
          that.fd.plot();
      },
      //Implement the same handler for touchscreens
      onTouchMove: function(node, eventInfo, e) {
        $jit.util.event.stop(e); //stop default touchmove event
        this.onDragMove(node, eventInfo, e);
      },
      //Add also a click handler to nodes
      onClick: highlightAdj,
      onDragStart: highlightAdj,
      onTouchStart: function(node, eventInfo, e) {
        $jit.util.event.stop(e); //stop default touch event
        this.onDragStart(node, eventInfo, e);
      }
    },
    //Number of iterations for the FD algorithm
    iterations: 200,
    //Edge length
    levelDistance: 150,
    // Add text to the labels. This method is only triggered
    // on label creation and only for DOM labels (not native canvas ones).
    onCreateLabel: function(domElement, node){
      domElement.innerHTML = node.name;
      var style = domElement.style;
      style.fontSize = "0.8em";
      style.color = "#454545";
    },
    // Change node styles when DOM labels are placed
    // or moved.
    onPlaceLabel: function(domElement, node){
      var style = domElement.style;
      var left = parseInt(style.left);
      var top = parseInt(style.top);
      var w = domElement.offsetWidth;
      style.left = (left - w / 2) + 'px';
      style.top = (top + 10) + 'px';
      style.display = '';
    }
	};
	
	that.settings = jQuery.extend({}, defaults, options);
	that.fd = new $jit.ForceDirected(that.settings);
	
	that.render = function(json) {
		that.fd.loadJSON(json);
		that.fd.computeIncremental({
			iter: 40,
			property: 'end',
			onStep: function(perc){
			},
			onComplete: function(){
				that.fd.animate({
					modes: ['linear'],
					transition: $jit.Trans.Back.easeOut,
					duration: 750
				});
			}
		});
	};
	
	$(window).resize(function() {
		var w = $('#' + that.thisid).width(),
				h = $('#' + that.thisid).height();
		that.fd.canvas.resize(w,h);
	});
	
	return that;
};