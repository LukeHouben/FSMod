
		#define MENU_LOADOUT_BUTTON(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString aftermath_weapon1 imgArg;\
				setLocalVarInt ui_loadout_index_highlight indexArg; \
				setdvar loadout_primary idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} 

#define MENU_LOADOUT_BUTTON2(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg)&& visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight2) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString aftermath_weapon2 imgArg;\
				setLocalVarInt ui_loadout_index_highlight2 indexArg; \
				setdvar loadout_secondary idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		}


#define MENU_LOADOUT_BUTTON_PERK1(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \

#define MENU_LOADOUT_BUTTON_PERK3(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk3 imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk3 idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg  && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \

#define MENU_LOADOUT_BUTTON_PERK2(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk2 imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk2 idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \

#define MENU_LOADOUT_BUTTON_PERK1_GREED(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk_2 imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk_2 idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \

#define MENU_LOADOUT_BUTTON_PERK3_GREED(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk3_2 imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk3_2 idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \

#define MENU_LOADOUT_BUTTON_PERK2_GREED(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk2_2 imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk2_2 idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \


#define MENU_LOADOUT_BUTTON_TACTICAL(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \

#define MENU_LOADOUT_BUTTON_LETHAL(indexArg, columnArg, rowArg, idArg, imgArg, textArg, actionArg, xpArg, visArg) \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0.1 0.1 0.1 1 \
			visible when(  !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_FILLED \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp 		rect W(180*(PLAYER_CURRENT_XP/xpArg)) \
			backcolor 1 0.8 0.45 1 \
			visible when(  !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_FILLED \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 	0 0.8 0 1 \
			visible when(  !localVarBool( ui_hideBack ) && localVarInt(ui_loadout_index_highlight3) == indexArg && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			style 		WINDOW_STYLE_SHADER \
			rect 		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			forecolor 	1 1 1 1 \
			exp 		material("gradient_top"); \
			border 		0 \
			bordersize 	0 \
			bordercolor 0 0 0 0 \
			visible		 when ( !localVarBool( ui_hideBack ) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_BUTTON \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	1 1 1 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP >= xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
				setLocalVarString loadout_perk imgArg;\
				setLocalVarInt ui_loadout_index_highlight3 indexArg; \
				setdvar loadout_perk idArg; \
				actionArg \
			}  \
		} \
		itemDef \
		{ \
			name		quit \
			type		ITEM_TYPE_TEXT \
			style		WINDOW_STYLE_FILLED \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			rect		(LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)) 180 18 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			exp			text(textArg) \
			forecolor	0.2 0.2 0.2 1 \
			textfont	9 \
			textalign	ITEM_ALIGN_CENTER \
			textalignY	18 \
			textscale	0.375 \
			visible		when(PLAYER_CURRENT_XP < xpArg && visArg) \
			mouseEnter    \
			{   \
				play "mouse_over";   \
			} \
			action   \
			{ \
				play "mouse_click"; \
			}  \
		} \
		itemDef \
		{ \
			style WINDOW_STYLE_SHADER \
			background "specialty_locked" \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 16 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			backcolor 1 1 1 1 \
			visible when ( !localVarBool( ui_hideBack ) && (PLAYER_CURRENT_XP < xpArg) && visArg); \
			decoration \
		} \
		itemDef \
		{ \
			rect (LD_BTN_ORIGIN_X+(LD_BTN_SPACING_X*columnArg)+1) (LD_BTN_ORIGIN_Y+(LD_BTN_SPACING_Y*rowArg)+1) 176 16 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER \
			style 0 \
			border 0 \
			ownerdraw 0 \
			ownerdrawFlag 0 \
			borderSize 0 \
			foreColor 1 1 1 1 \
			backColor 0 0 0 0 \
			borderColor 0 0 0 0 \
			outlineColor 0 0 0 0 \
			decoration \
			type 0 \
			align 0 \
			textAlign ITEM_ALIGN_MIDDLE_RIGHT \
			textScale 0.2 \
			textstyle	ITEM_TEXTSTYLE_SHADOWED \
			textFont 1 \
			feeder 0 \
			visible when ( PLAYER_CURRENT_XP < xpArg && visArg) \
			exp text ( (xpArg-PLAYER_CURRENT_XP)+" XP left" ) \
		} \

