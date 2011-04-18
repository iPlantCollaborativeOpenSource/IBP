<?php
// $Id: treegroups.module,v 1 2010/06/29 praveen@tacc.utexas.edu 
//TreeGroups (TG)
// $Id: clade.module,v 1 2010/09/20 praveen@tacc.utexas.edu 
//Clade.pages.inc 

/**
 * clade subscription options
 **/
function clade_subscribe($node, $uid = NULL) {
  global $user;
  if (is_null($uid)) {
    if ($user->uid) {
      $account = $user;
    }
    else {
      $dest = drupal_get_destination();
      if (variable_get('user_register', 1) == 0) {
        drupal_set_message(t('In order to join this group, you must <a href="!login">login</a>. After you have successfully done so, you will need to request membership again.', array('!login' => url("user/login", array('query' => $dest)))));
      }
      else {
        drupal_set_message(t('In order to join this group, you must <a href="!login">login</a> or <a href="!register">register</a> a new account. After you have successfully done so, you will need to request membership again.', array('!register' => url("user/register", array('query' => $dest)), '!login' => url("user/login", array('query' => $dest)))));
      }
      drupal_goto('user');
    }
  }
  else {
    $account = user_load(array('uid' => $uid));
  }

  if ($node->og_selective >= OG_INVITE_ONLY || $node->status == 0 || !og_is_group_type($node->type)) {
    drupal_access_denied();
    exit();
  }
  
  // Only admins can add another member.
  if ($account->uid != $user->uid && !og_is_group_admin($node)) {
    drupal_access_denied();
    exit();
  }
  // User is already a member of this group, redirect to group homepage.
  else if (isset($account->og_groups[$node->nid])) {
    drupal_set_message(t('@user is already a member the group @group.', array('@user' => $account->name, '@group' => $node->title)));
    drupal_goto('node/'. $node->nid);
  }
  else {
		//add some js/jquery to the form
		drupal_add_js("$('#edit-subscribe-3').click(function(){ $('fieldset.collapsed').find('legend a').trigger('click');});", "inline", "footer");
//	jquery_ui_add('effects.core');
//	drupal_add_js(drupal_get_path("module", "clade")."/clade.js");
//	drupal_add_js("$(document).ready(Drupal.clade.initMenu);", "inline", "footer");
    return drupal_get_form('clade_subscribe_form', $node->nid, $node, $account);
  }
}


/**
 * clade_subscribe_form subscription form - 
 */
function clade_subscribe_form($form_state, $gid, $node, $account) {
	//radio buttons to choose none, all or custom children 
  	$options = array(
				'1' => t('Join @clade Network Only.', array('@clade' => $node->title)),
 				'2' => t('Join @clade Network and all its Sub-Clade Networks', array('@clade' => $node->title)),
				'3' => t('Join @clade Network and let me select its Sub-Clade Networks to join', array('@clade' => $node->title)),
	);

	$form['subscribe'] = array(
    	'#type' => 'radios',
    	'#title' => t('Please choose subscription options below'),
    	'#default_value' =>  variable_get('log', 1),
    	'#options' => $options,
  	);
  

	//custom children population -

  	$form['sub-clades'] = array(
    	'#type' => 'fieldset',
    	'#title' => t('Select Sub-clade Networks to join'),
    	'#collapsible' => TRUE,
    	'#collapsed' => TRUE,
  	);
	//variable to collect all children of a node, which the user is not a member of, in a csv format
	$clade_children = '';
	//write open divs
	$i = 1;
	//check if clade has any sub-clades.
	$children = nodehierarchy_get_children($node->nid);
  	if (count($children) > 0) {		// if yes then show sub-clades
		$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => '<div><div class="_tg_menu">');
		//write first element
		_clade_subscribe_checkboxes_get_clade_div($form, $node, "tg_menu_item last", $i, 1);
		//write middle elements
		_clade_subscribe_checkboxes_get_children($form, $node, $i, $clade_children);
		//close the parent div
		$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => '</div>');
		//close all divs in the last element
		$form['sub-clades']['checkboxes_note'] = array(
			'#type' => 'markup', 
			'#value' => '<br /> *Networks you are already a member of are in <strong>BOLD</strong>.'
		);
		$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => '</div></div>');

	} else {		// if not then show message
		$form['sub-clades']['checkboxes_div_'.$i++] = array(
			'#type' => 'markup', 
			'#value' => t(' <div>No Sub-Clade Networks available for @clade at this time.</div>', array('@clade'=>$node->title))
		);		
	}
			
  	$form['clade_children'] = array('#type' => 'value', '#value' => $clade_children);
  	$form['submit'] = array('#type' => 'submit', '#value' => t('Join'));
	$form['cancel'] = array(
	'#type' => 'button',
	'#value' => t('Cancel'),
	//'#attributes' => array('onclick' => 'window.location = '. base_path() .'; return false; '),
	//'#attributes' => array('onClick' => 'drupal_goto("node/". $node->nid)'),
	'#weight' => 20,
	'#executes_submit_callback' => TRUE,
	//'#submit' => array('drupal_goto("node/'.$node->nid'");'),
	'#submit' => array('clade_subscribe_form_cancel'),
	);
	
	//add other stuff to the form
  	$form['gid'] = array('#type' => 'value', '#value' => $gid);
  	$form['clade_title'] = array('#type' => 'value', '#value' => $node->title);
  	$form['account'] = array('#type' => 'value', '#value' => $account);
  	if ($node->og_selective == OG_MODERATED) {
    	$form['request'] = array(
      		'#type' => 'textarea', 
      		'#title' => t('Additional details'), 
      		'#description' => t('Add any detail which will help an administrator decide whether to approve or deny your membership request.')
    	);
	}
  	else {
    	$form['request'] = array(
      		'#type' => 'value', 
      		'#value' => '',
   		);
 	}
	return $form;

}

/**
 * clade_subscribe_form_cancel join Cancel action handler
 */
function clade_subscribe_form_cancel($form){
	$clade_title= $form['clade_title']['#value'];
	if ( !is_null($clade_title)) {
		$url = 'clade/'.$clade_title;
	}
	drupal_goto($url);	
}

/**
 * clade_subscribe_form Validation handler - 
 */
//function clade_subscribe_form_validate($form, &$form_state) {	
//}

/**
 * clade_subscribe_form submit handler - 
 */
function clade_subscribe_form_submit($form, &$form_state) {

	$account = $form_state['values']['account'];	//user account info
	$request = $form_state['values']['request'];	//request info if any set
	$gid = $form_state['values']['gid'];			//node id of the clade
	$clade_children = $form_state['values']['clade_children'];	//children, if any,  of the current gid which user is not a member of, above in csv format- -- it is stored in form value clade_children
	//Check for value of radio button 'subscribe'
	if($form_state['values']['subscribe'] == 1){		//if value is 1; join only the clade, no subclades
		  $return = og_subscribe_user($gid, $account, $request);
		//send message
	  	if (!empty($return['message'])) {
			drupal_set_message($return['message']);
	  	}
	}
	 else if($form_state['values']['subscribe'] == 2){		//if value is 2; join all sub clades
		//first become member of parent clade
		$return = og_subscribe_user($gid, $account, $request);
		//send message
	  	if (!empty($return['message'])) {
			drupal_set_message($return['message']);
	  	}
		//now join children, if any
		$children_array = explode(',' , $clade_children);
		foreach($children_array as $child){
			if($child){	//takes care of any commas at the start or end of the clade_children string or empty csv
				$return = og_subscribe_user($child, $account, $request);
				//send message
			  	if (!empty($return['message'])) {
					drupal_set_message($return['message']);
			  	}
			}
		}		
	}
	 else if($form_state['values']['subscribe'] == 3){		//if value is 3; join only selected sub clades
		//first become member of parent clade
		$return = og_subscribe_user($gid, $account, $request);
		//send message
	  	if (!empty($return['message'])) {
			drupal_set_message($return['message']);
	  	}
	
		//get all the selected checkbox values(which are the nodeids)		
		$children_array = explode(',' , $clade_children);	//get all the clade_children which user is not a member of
		foreach($children_array as $child){
			if($child){	//takes care of any commas at the start or end of the clade_children string or empty csv
				$checkbox_value = $form_state['values']['subscription_checkboxes_'.$child];	//is zero if not checked and will be set to nid if checked
//				print $checkbox_value.'and clade children value is'.$clade_children.'and child is'.$child;
				if($checkbox_value > 0){
					$return = og_subscribe_user($checkbox_value, $account, $request);	
					//send message
				  	if (!empty($return['message'])) {
						drupal_set_message($return['message']);
				  	}
				} else{
					//checkbox not checked so do nothing and go to next checkbox
				}
			}
		}
	}

  	$form_state['redirect'] = 'node/'. $form_state['values']['gid'];
} 

/**
 * clade UnSubscribe options
 **/
function clade_unsubscribe($node, $account){
	global $user;
	//add some js/jquery to the form
	drupal_add_js("$('#edit-unsubscribe-3').click(function(){ $('fieldset.collapsed').find('legend a').trigger('click');});", "inline", "footer");
//	jquery_ui_add('effects.core');
//	drupal_add_js(drupal_get_path("module", "clade")."/clade.js");
//	drupal_add_js("$(document).ready(Drupal.clade.initMenu);", "inline", "footer");
	return drupal_get_form('clade_unsubscribe_form', $node->nid, $node, $account);	
}

/**
 * clade_unsubscribe_form unsubscribe form - 
 **/
function clade_unsubscribe_form($form_state, $gid=NULL, $node=NULL, $account=NULL){
	
	$confirm_admin_remove_user = FALSE;
	//IF FIRST TIME THEN LOAD CONFIRM FORM AND ASK USER TO CONFIRM //ELSE LOAD FORM AND ASK USER TO HIT SUBMIT
	
	$page = isset($form_state['storage']['page']) ? $form_state['storage']['page'] : 1 ;
	switch($page) {
		case 1:				//IF FIRST TIME THEN LOAD FORM AND ASK USER TO HIT SUBMIT
			global $user;
		  	$form['group_node'] = array('#type' => 'value', '#value' => $node);
		  	$form['account'] = array('#type' => 'value', '#value' => $account);
		  	if ($account->uid <> $user->uid) {  //if clade manager
				$form['remove_user'] = array('#type' => 'value', '#value' => 'remove_user');
		    	$message = t('Are you sure you want to remove !name from the group %title?', 
									array('!name' => theme('username', $account), '%title' => $node->title));
		    	$confirm_text = t("Remove");
				$confirm_admin_remove_user = TRUE;				
		  	}
			else {	//if self unjoin
				//radio buttons to choose none, all or custom children 
			  	$options = array(
							'1' => t('Leave @clade Network Only.', array('@clade' => $node->title)),
			 				'2' => t('Leave @clade Network and all its Sub-Clade Networks that I am a member of.', array('@clade' => $node->title)),
							'3' => t('Leave @clade Network and let me select which Sub-Clade Networks to leave', array('@clade' => $node->title)),
				);

				$form['unsubscribe'] = array(
			    	'#type' => 'radios',
			    	'#title' => t('Please choose options below'),
			    	'#default_value' =>  variable_get('log', 1),
			    	'#options' => $options,
			  	);

				//custom children population -
			  	$form['sub-clades-leave'] = array(
			    	'#type' => 'fieldset',
			    	'#title' => t('Select Sub-clade Networks to Leave'),
			    	'#collapsible' => TRUE,
			    	'#collapsed' => TRUE,
			  	);
				$clade_children = '';			//variable to collect all children of a node, which the user is a member of, in a csv format
				$i = 1; 						//write open divs
				$children = nodehierarchy_get_children($node->nid);			//check if clade has any sub-clades.
			  	if (count($children) > 0) {		// if yes then show sub-clades
					$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => '<div><div class="_tg_menu">'); 
					//write first element
					_clade_unsubscribe_checkboxes_get_clade_div($form, $node, "tg_menu_item last", $i, 1);
					//write middle elements
					_clade_unsubscribe_checkboxes_get_children($form, $node, $i, $clade_children);
					//close the parent div
					$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => '</div>');
					//close all divs in the last element
					$form['sub-clades-leave']['checkboxes_note'] = array(
						'#type' => 'markup', 
						'#value' => '<br /> * Networks you are not a member of are in <span class="unsubscribe_clade_disabled"> GREY </span><br />* Networks you are an administrator of are in <span class="unsubscribe_clade_owner">RED</span><br />* Networks that are not active are <span class="unsubscribe_clade_closed">BOLD</span>'
					);
					$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => '</div></div>');

				} 
				else {		// if not then show message
					$form['sub-clades-leave']['checkboxes_div_'.$i++] = array(
						'#type' => 'markup', 
						'#value' => t(' <div>No Sub-Clade Networks available for @clade at this time.</div>', array('@clade'=>$node->title))
					);		
				}
				$form['clade_children'] = array('#type' => 'value', '#value' => $clade_children);
			 	$form['clade_title'] = array('#type' => 'value', '#value' => $node->title);
				$form['submit'] = array('#type' => 'submit', '#value' => t('Leave'));
				$form['cancel'] = array(
					'#type' => 'button',
					'#value' => t('Cancel'),
					'#weight' => 20,
					'#executes_submit_callback' => TRUE,
					'#submit' => array('clade_unsubscribe_form_cancel'),
				);
		  	}	
	        break;

	    case 2:					//ELSE LOAD CONFIRM FORM AND ASK USER TO CONFIRM
			$form_values = $form_state['storage']['values'][$form_state['storage']['page']];
			$group_node = $form_values['group_node'];
			$account = $form_values['account'];
			$unsubscribe = $form_values['unsubscribe'];
			$clade_children = $form_values['clade_children'];

			if($unsubscribe == 1) {	//if only clade
				$clade_listing_title = $group_node->title;
				$clade_listing_nid = $group_node->nid;
			} 
			else if($unsubscribe == 2){	//if clade and all children
				$clade_listing_title = $group_node->title;
				$clade_listing_nid = $group_node->nid;				
				//add all sub clades of the current node which the user is member of
				$children_array = explode(',' , $clade_children);
				foreach($children_array as $child){
					if($child){	//takes care of any commas at the start or end of the clade_children string or empty csv
						$child_node = node_load($child);
						$clade_listing_title .= ', '.$child_node->title;
						$clade_listing_nid .= ', '.$child_node->nid;
					}
				}
			}
			else if($unsubscribe == 3){	//if clade and selection
				$clade_listing_title = $group_node->title;
				$clade_listing_nid = $group_node->nid;
				//print var_export($clade_children, true);				
				//get all the selected checkbox values(which are the nodeids)		
				$children_array = explode(',' , $clade_children);	//get all the clade_children which user is a member of
				foreach($children_array as $child){
					if($child){	//takes care of any commas at the start or end of the clade_children string or empty csv
						$checkbox_value = $form_values['subscription_checkboxes_'.$child];	//is zero if not checked and will be set to nid if checked
						if($checkbox_value > 0){
							$checkbox_value_node = node_load($checkbox_value);
							$clade_listing_title .= ', '.$checkbox_value_node->title;
							$clade_listing_nid .= ', '.$checkbox_value_node->nid;							
						} else{
								//checkbox not checked so do nothing and go to next checkbox
						}
					}
				}				
			}				
			$form['clade_listing_nid'] = array('#type'=> 'value', '#value' => $clade_listing_nid);	//server specific hidden form value	
			$form['confirm_text']= array(
				'#type' => 'markup',
				'#value' => t('<br /><div><b>Are you sure you want to leave the following clade networks:</b><br /><br /> @clade_listing <br /><br /></div>', array('@clade_listing'=>$clade_listing_title))
			);
			$form['clade_id'] = array('#type' => 'value', '#value' => $group_node->nid);
			$form['user_id'] = array('#type' => 'value', '#value' => $account->uid);			
			$form['submit'] = array('#type' => 'submit', '#value' => t('Confirm'));
			$form['cancel'] = array(
					'#type' => 'button',
					'#value' => t('Back'),
					'#weight' => 20,
					'#executes_submit_callback' => TRUE,
					'#submit' => array('clade_unsubscribe_form_confirm_cancel'),
			);
					//$form_state['storage']['page']++; do this if adding and additional there any further steps in the form
	        break;

	    }	//end switch

	return ($confirm_admin_remove_user) ? confirm_form($form, $message, 'og/users/'. $node->nid, ' ', $confirm_text, t('Cancel')) : $form ;
}

/**
 * clade_unsubscribe_form_cancel join Cancel action handler
 */
function clade_unsubscribe_form_cancel($form){
	$clade_title = $form['clade_title']['#value'];
	if ( !is_null($clade_title)) {
		$url = 'clade/'.$clade_title;
	}
	drupal_goto($url);	
}

/**
 * clade_unsubscribe_form_confirm_cancel join Cancel action handler
 */
function clade_unsubscribe_form_confirm_cancel($form){
	$clade_id = $form['clade_id']['#value'];
	$user_id = $form['user_id']['#value'];	
	if ( !is_null($clade_id) && !is_null($user_id)) {
		$url = 'og/unsubscribe/'.$clade_id.'/'.$user_id;
	}
	drupal_goto($url);	
}

/**
 * clade_subscribe_form submit handler - 
 */
function clade_unsubscribe_form_submit($form, &$form_state) {
	global $user;
		$page = (isset($form_state['storage']['page'])) ? $form_state['storage']['page'] : 1 ;

		switch($page) {
			case 1:
				//if confirm_form by admin then process the deletion	
				if(isset($form_state['values']['remove_user'])){	//if user removed by manager then remove_user value will be set
					$group_node = $form_state['values']['group_node'];	//node of the clade
					$account = $form_state['values']['account'];	//user account
					$remove_user = $form_state['values']['remove_user'];
					//check if unjoin by clade manager or self
					if(($user->uid <> $account->uid) && ($remove_user === 'remove_user')) {	//if clade manager
						//since already a confirm form unjoin the user from the group 
						og_delete_subscription($group_node->nid, $account->uid);
						//set message for current group unjoin 
					    $message = t('%user removed from %group.', array('%user' => $account->name, '%group' => $group_node->title));
						drupal_set_message($message);
						$form_state['redirect'] = 'node/'. $group_node->nid;
					}
				}
				else {	//else the request is from user so show confirm before processing
					$page ++;
					$form_state['storage']['page'] = $page;
					$form_state['storage']['values'][$form_state['storage']['page']] = $form_state['values'];
				 	//$form_state['rebuild'] = TRUE; when $form_state[storage] is populated then $form_state['rebuild'] will be set to TRUE by default
				}
				break;
			case 2:
					//read variables as $form_state['storage']['values'][$form_state['storage']['page']]['variablename']
				$account = $form_state['storage']['values'][$form_state['storage']['page']]['account'];
				$group_node = $form_state['storage']['values'][$form_state['storage']['page']]['group_node'];

				$clade_listing_nid = $form_state['values']['clade_listing_nid'];
				$subclade_array = explode(',' , $clade_listing_nid);					
				foreach($subclade_array as $child){
					if(trim($child)){	//takes care of any commas at the start or end of the clade_children string or empty csv & blanks
						og_delete_subscription($child, $account->uid);
						$child_node = node_load($child);
						//set message for child group unjoin 
						$message = t('You left the group %group.', array('%group' => $child_node->title));
						drupal_set_message($message);
					}
				}
				//after all unjoins clear cache and reload 	
				og_get_subscriptions($account->uid, 1, TRUE); // Clear cache.
			    $user = user_load(array('uid' => $user->uid));
				//We must do this or the form will rebuild instead of refreshing.
			    unset($form_state['storage']);
				$form_state['redirect'] = node_access('view', $group_node) ? "node/". $group_node->nid : '';
				break;
			} // end switch($page)	
}

/**
Adds the required form elements to the form shown in join clade page 
 * Returns an UNCLOSED div for the clade, with link to clade node and appropriate classes set.
 * @param &$form the form element
 * @param $node the node to show the clade for
 * @param $class the css class for display
 * @param &$i counter for markup divs
 * @param $parent is the clade the parent of all clades shown in the tree
 */
function _clade_subscribe_checkboxes_get_clade_div( &$form, $node, $class = "tg_menu_item", &$i, $parent = 0){
  $div = "<div id='_tg_menu_" . $node->nid . "' class='" . $class . "'>";
  $div .= "<div class='empty'></div>";
	//add form markup 
	$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $div);
	$div = '';
	if($parent){
		//since parent no check box; parent will be choosen by default
		//also if already a memeber then dont provide check box
		$div = t($node->title);
	}else {
		if(og_is_group_member($node->nid, FALSE)){
			//$form['sub-clades']['subscription_checkboxes_'.$node->nid] ['#disabled']= TRUE;
			//$form['sub-clades']['subscription_checkboxes_'.$node->nid] ['#default_value']= 1;		
			$div = '<b>'.t($node->title).'</b>';	
		} else {
			//if not parent add form element checkbox
			$form['sub-clades']['subscription_checkboxes_'.$node->nid]= array(
				'#type' => 'checkbox', 
				'#default_value' => 0, 
				'#return_value' => $node->nid ,
			);
			$div = t($node->title);
		}
	}	
	$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $div);
}

/**
Populates children clades to add the required form elements to the form shown in join clade page 
 * Returns an UNCLOSED div for the clade, with link to clade node and appropriate classes set.
 * @param &$form the form element
 * @param $node the node to show the clade for
 * @param &$i counter for markup divs
 * @param $clade_children store the clade children in csv for future use
 */

function _clade_subscribe_checkboxes_get_children(&$form, $node, &$i, &$clade_children){
  $children = nodehierarchy_get_children($node->nid);
  if (count($children) > 0) {
    $kids = "<div class='descendants'>";
	//add form markup 
	$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $kids);
    foreach ($children as $idx => $c) {
		$child = node_load($c);
		_clade_subscribe_checkboxes_get_clade_div($form, $child, ($idx + 1) == count($children) ? "tg_menu_item last" : "tg_menu_item", $i);
		if(! og_is_group_member($child->nid, FALSE)){
			$clade_children .= $child->nid.',';
		}
      	if (_nodehierarchy_get_children_count($c)) {
        	_clade_subscribe_checkboxes_get_children($form, $child , $i, $clade_children);
      	}
      	$kids = "</div>";
		//add form markup 
		$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $kids);
    }
  	$kids = "</div>";
	//add form markup 
	$form['sub-clades']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $kids);
  }
}

/**
Adds the required form elements to the form shown in leave clade page 
 * Returns an UNCLOSED div for the clade, with link to clade node and appropriate classes set.
 * @param &$form the form element
 * @param $node the node to show the clade for
 * @param $class the css class for display
 * @param &$i counter for markup divs
 * @param $parent is the clade the parent of all clades shown in the tree
 */
function _clade_unsubscribe_checkboxes_get_clade_div( &$form, $node, $class = "tg_menu_item", &$i, $parent = 0){
	global $user;
  	$div = "<div id='_tg_menu_" . $node->nid . "' class='" . $class . "'>";
  	$div .= "<div class='empty'></div>";
	//add form markup 
	$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $div);
	$div = '';
	if($parent){
		//since parent no check box; parent will be choosen by default		
		$div = t($node->title);
	}else {
		//also if not a member then dont provide check box
		if(! og_is_group_member($node->nid, FALSE)){
			//$form['sub-clades']['subscription_checkboxes_'.$node->nid] ['#disabled']= TRUE;
			//$form['sub-clades']['subscription_checkboxes_'.$node->nid] ['#default_value']= 1;		
			$div = '<span class="unsubscribe_clade_disabled">'.t($node->title).'</span>';	
		} else {
			// If groups closed or group manager, user can't leave
		    if ($node->og_selective == OG_CLOSED) {
		      //drupal_set_message(t('You may not leave this group because it is a <em>closed</em> group. You should request removal from a group administrator.'));
				$div = '<span class="unsubscribe_clade_disabled unsubscribe_clade_closed">'.t($node->title).'</span>';
				//todo set hover message to tell user that group is closed
		    }
		    else if ($node->uid == $user->uid) {
		      	//drupal_set_message(t('You may not leave this group because you are its owner. A site administrator can assign ownership to another user and then you may leave.'));
				$div = '<span class="unsubscribe_clade_disabled unsubscribe_clade_owner">'.t($node->title).'</span>';
				//todo set hover message to tell user that group is closed
		    }
		    else {
				//if not parent and user a member add form element checkbox
				$form['sub-clades-leave']['subscription_checkboxes_'.$node->nid]= array(
					'#type' => 'checkbox', 
					'#default_value' => 0, 
					'#return_value' => $node->nid ,
				);
				//$div = t($node->title.'('.$node->nid.')');
				$div = t($node->title);
		    }
		}
	}	
	$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $div);
}

/**
Populates children clades to add the required form elements to the form shown in leave clade page 
 * Returns an UNCLOSED div for the clade, with link to clade node and appropriate classes set.
 * @param &$form the form element
 * @param $node the node to show the clade for
 * @param &$i counter for markup divs
 * @param $clade_children store the clade children in csv for future use
 */
function _clade_unsubscribe_checkboxes_get_children(&$form, $node, &$i, &$clade_children){
	global $user;
	$children = nodehierarchy_get_children($node->nid);
  if (count($children) > 0) {
    $kids = "<div class='descendants'>";
	//add form markup 
	$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $kids);
    foreach ($children as $idx => $c) {
		$child = node_load($c);
		_clade_unsubscribe_checkboxes_get_clade_div($form, $child, ($idx + 1) == count($children) ? "tg_menu_item last" : "tg_menu_item", $i);
		if( og_is_group_member($child->nid, FALSE) && !($child->og_selective == OG_CLOSED) && !($child->uid == $user->uid)){
			$clade_children .= $child->nid.',';
		}
      	if (_nodehierarchy_get_children_count($c)) {
        	_clade_unsubscribe_checkboxes_get_children($form, $child , $i, $clade_children);
      	}
      	$kids = "</div>";
		//add form markup 
		$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $kids);	
    }
  	$kids = "</div>";
	//add form markup 
	$form['sub-clades-leave']['checkboxes_div_'.$i++] = array('#type' => 'markup', '#value' => $kids);
  }
}