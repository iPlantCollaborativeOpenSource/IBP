/*
 * Copyright (c) 2011 SimplyCast
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

CKEDITOR.plugins.add('imagemap',
{
  init: function(editor)
  {
    var pluginName = 'imagemap';
    //note: For IE 7+8 support, uncomment this line and install excanvas
    //CKEDITOR.scriptLoader.load(CKEDITOR.getUrl('plugins/imagemap/excanvas.compiled.js')); 
    CKEDITOR.scriptLoader.load(CKEDITOR.getUrl('plugins/imagemap/imagemap.js')); 

    editor.ui.addButton( 'ImageMap',
      {
        label : "Edit Imagemap",
        command : pluginName,
        icon: this.path+'imagemap.gif',
        click: function(editor){
          //var jqeditor = editor;
          var selected = editor.getSelection().getSelectedElement();

          if(selected && selected.is("img")){
          if(null==selected.getAttribute("id")) selected.setAttribute('id','xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) { //add UUID for id
            var r = Math.random()*16|0, v = c == 'x' ? r : (r&0x3|0x8);
            return v.toString(16);
          }));

          //console.log("Beginning editing",jqeditor,selected,selected.getAttribute('id'));
            initImageMapEditor(editor,selected);
          }else{
            alert("Please select an image!");
          }
        }
      });


    //console.log("Added imagemap plugin");   
  }
});

var processingInstance;

function initImageMapEditor(editor,selected){
  $.modal("<div style='width: 640px; height:400px; border: 1px solid black; background: white;' id='imageMapModalDiv'>\
<div id='imageMapCanvasDiv' style='background: grey; width: 400px; height: 400px; border-right: 1px solid black; float: left; overflow: auto;'>\
</div>\
<div style='float: left;'>\
  <div style='height: 200px; border-bottom: 1px solid black; width: 238px;'>\
  <select style='width: 240px; height: 200px;' size='4' onclick='processingInstance.select($(\"#imageMapAreas\").val())' id='imageMapAreas'>\
  </select>\
  </div>\
  <div style='clear: both;'>\
    <button onclick='processingInstance.saveToHtml();'>Save HTML</button><br>\
    <button onclick='processingInstance.removeArea();'>Delete Area</button><br>\
    <button onclick='processingInstance.addArea(\"\",\"\",\"New\",\"circle\",\"20,20,10\");'>Circle</button>\
    <button onclick='processingInstance.addArea(\"\",\"\",\"New\",\"rect\",\"20,20,40,40\");'>Box</button>\
    <button onclick='processingInstance.addArea(\"\",\"\",\"New\",\"poly\",\"\");'>Polygon</button>\
    <table style='display: none; border: none;' id='imageMapRegionEdit'>\
      <tr><td colspan=2>\
      URL: <input type='text' id='imageMapHref' style='width: 190px;' onchange='processingInstance.updateArea();'>\
      </td></tr><td>\
      Title: <input type='text' id='imageMapTitle' style='width: 60px;' onkeyup='processingInstance.updateArea();'>\
      </td><td>\
      Alt: <input type='text' id='imageMapAlt' style='width: 60px;' onchange='processingInstance.updateArea();'>\
      </td></tr>\
    </table>\
  </div>\
  </div>\
  <div id='imageMapHidden' style='display:none;'></div>\
   </div>"); 
  //$("#imageMapHidden").html(editor.val());
  initImageMapCanvas(editor,selected);
}

function initImageMapCanvas(editor,selected){
  var can = document.createElement('canvas');
  document.getElementById('imageMapCanvasDiv').appendChild(can);
  can.setAttribute("width",200);
  can.setAttribute("height",200);
  can.setAttribute("id","imageMapCanvas");
  if($.browser.msie == true && parseFloat($.browser.version) < 9){
    window.G_vmlCanvasManager.init_(document);
    can = G_vmlCanvasManager.initElement(can);  //init the exCanvas element in IE 7 and 8
  }
  //can = document.getElementById('imageMapCanvas');
  //console.log("image: ",$("#"+selected));
  //console.log($("#processing-source").attr("src"));
  //var code =$.ajax({url:$("#processing-source").attr("src"),async: false,cache:false}).responseText; 
  processingInstance=new Object();
  sketchProc(processingInstance);

  processingInstance.load(editor,selected);
 
  processingInstance.draw();


}
