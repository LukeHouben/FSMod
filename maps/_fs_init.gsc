#include maps\_utility;
#include common_scripts\utility;

init()
{
	PrecacheMenu("fs_gamemode_select");
}

main()
{
	handle_gm();
}


handle_gm()
{
	players = GetPlayers();
	players[0] FreezeControls(true);
	players[0] thread handle_gm_watcher("fs_gamemode_select");
	players[0] thread handle_gm_result();
}

handle_gm_result()
{
	self waittill("gm_chosen");
	self FreezeControls(false);
	if(GetDvarInt("fs_start_round")>1 && self.gm_result == 0)
		level notify("gm_has_been_chosen",GetDvarInt("fs_start_round"));
	else if(self.gm_result == 0)
		level notify("gm_has_been_chosen");
	if(self.gm_result == 0){
		wait(10);
		add_points_based_on_rounds();
	}
	level.gm_result = self.gm_result;
	if(self.gm_result == 2) maps\_fs_turned::main();
	if(self.gm_result == 3) maps\_fs_scavenger_gm::main();	// do the stuff here
}

add_points_based_on_rounds()
{
	players = GetPlayers();
	for(i=0;i<players.size;i++)
	{
		result = 0;
		for(i=0;i<level.round_number;i++){
			result += 100;
		}
		players[i] maps\_zombiemode_score::add_to_player_score(result);
	}
}

handle_gm_watcher(menu)
{
	self openMenu(menu);
	self.gm_result = 0;
	self.gm_chosen = false;
	while(1)
	{
		
		self waittill("menuresponse", responsemenu, response);
		
		if(responsemenu != menu)
			continue;
			
		switch(response)
		{
			case "classic":
				self.gm_result = 0;
				break;
			case "gungame":
				self.gm_result = 1;
				break;
			case "turned":
				self.gm_result = 2;
				break;
			case "scavenger":
				self.gm_result = 3;
				break;
			case "4":
				self.gm_result = 4;
				break;
			case "5":
				self.gm_result = 5;
				break;
			case "start":
				self.gm_chosen = true;
				self notify("gm_chosen");
				self FreezeControls(false);
				self CloseMenu(menu);
				break;
		}
	}
}