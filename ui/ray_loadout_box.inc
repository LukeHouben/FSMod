
	#define MENU_LOADOUT_BOX2( indexArg, rectXArg, rectYArg, imgArg, blurArg, textArg, actionArg, descArg, backArg, groupArg, visArg, newVisArg ) \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (rectXArg) (rectYArg-110) 256 110 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (rectXArg) (rectYArg-110) 256 110 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 0.5 0 0.25 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt( ui_highlight ) == indexArg  && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg+38) (rectYArg - 100) 180 90 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material(blurArg) \
			visible when( localVarInt( ui_highlight ) != indexArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg+38) (rectYArg - 100) 180 90 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material(imgArg) \
			visible when( localVarInt( ui_highlight ) == indexArg && localVarString( ui_choicegroup ) == groupArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg) (rectYArg - 110) 256 5 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material("gradient_top"); \
			border 0 \
			bordersize 0 \
			bordercolor 0 0 0 0 \
			visible when ( !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg) (rectYArg - 5) 256 5 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material("gradient_bottom"); \
			border 0 \
			bordersize 0 \
			bordercolor 0 0 0 0 \
			visible when ( !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			type ITEM_TYPE_BUTTON \
			rect (rectXArg) (rectYArg - 128) 256 146 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && visArg && localVarInt(pick_item) == 0); \
			MENU_LOADOUT_SCRIPTACTIONS( indexArg, actionArg, groupArg, descArg, backArg ) \
		} \
		itemDef \
		{ \
			style ITEM_TYPE_TEXT \
			rect (rectXArg) (rectYArg - 110) 256 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 0.504 0.504 0.504 1 \
			exp text( textArg ) \
			textfont 9 \
			textscale 0.4 \
			textstyle 0 \
			textalign ITEM_ALIGN_MIDDLE_CENTER \
			visible when( localVarInt( ui_highlight ) != indexArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style ITEM_TYPE_TEXT \
			rect (rectXArg) (rectYArg - 110) 256 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp text( textArg ) \
			textfont 9 \
			textscale 0.4 \
			textstyle 0 \
			textalign ITEM_ALIGN_MIDDLE_CENTER \
			visible when( localVarInt( ui_highlight ) == indexArg && localVarString( ui_choicegroup ) == groupArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_new" \
			rect (rectXArg) (rectYArg - 128) 36 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 0.2 0.2 0.22 1 \
			visible when ( !localVarBool( ui_hideBack ) && visArg && newVisArg ); \
			decoration \
		} 

	#define MENU_LOADOUT_BOX_PERK( indexArg, rectXArg, rectYArg, imgArg, blurArg, textArg, actionArg, descArg, backArg, groupArg, visArg, newVisArg ) \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (rectXArg) (rectYArg-110) 110 110 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (rectXArg) (rectYArg-110) 110 110 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 0.5 0 0.25 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt( ui_highlight ) == indexArg  && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg+10) (rectYArg - 100) 90 90 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material(blurArg) \
			visible when( localVarInt( ui_highlight ) != indexArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg+10) (rectYArg - 100) 90 90 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material(imgArg) \
			visible when( localVarInt( ui_highlight ) == indexArg && localVarString( ui_choicegroup ) == groupArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg) (rectYArg - 110) 110 5 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material("gradient_top"); \
			border 0 \
			bordersize 0 \
			bordercolor 0 0 0 0 \
			visible when ( !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			rect (rectXArg) (rectYArg - 5) 110 5 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp material("gradient_bottom"); \
			border 0 \
			bordersize 0 \
			bordercolor 0 0 0 0 \
			visible when ( !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			type ITEM_TYPE_BUTTON \
			rect (rectXArg) (rectYArg - 110) 110 110 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && visArg && localVarInt(pick_item) == 0); \
			MENU_LOADOUT_SCRIPTACTIONS( indexArg, actionArg, groupArg, descArg, backArg ) \
		} \
		itemDef \
		{ \
			style ITEM_TYPE_TEXT \
			rect (rectXArg) (rectYArg - 110) 110 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 0.504 0.504 0.504 1 \
			exp text( textArg ) \
			textfont 9 \
			textscale 0.4 \
			textstyle 0 \
			textalign ITEM_ALIGN_MIDDLE_CENTER \
			visible when( localVarInt( ui_highlight ) != indexArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style ITEM_TYPE_TEXT \
			rect (rectXArg) (rectYArg - 110) 110 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 1 1 1 1 \
			exp text( textArg ) \
			textfont 9 \
			textscale 0.4 \
			textstyle 0 \
			textalign ITEM_ALIGN_MIDDLE_CENTER \
			visible when( localVarInt( ui_highlight ) == indexArg && localVarString( ui_choicegroup ) == groupArg && !localVarBool( ui_hideBack ) && visArg ); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_new" \
			rect (rectXArg) (rectYArg - 110) 36 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 0.2 0.2 0.22 1 \
			visible when ( !localVarBool( ui_hideBack ) && visArg && newVisArg ); \
			decoration \
		} 

	#define MENU_LOADOUT_SCRIPTACTIONS( indexArg, actionArg, groupArg, descArg, backArg ) \
		onFocus \
		{ \
			play "mouse_over"; \
			setLocalVarInt ui_highlight indexArg; \
			setLocalVarInt ui_highlighted_game backArg; \
			setLocalVarString ui_choicegroup groupArg; \
			setLocalVarString ui_game_desc descArg; \			
			onFocusArg \
		} \
		leaveFocus \
		{ \
			setLocalVarInt ui_highlight 0; \
			leaveFocusArg \
		} \
		action \
		{ \
			play "mouse_click"; \
			actionArg; \
		}	