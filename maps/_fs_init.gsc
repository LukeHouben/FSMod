#include maps\_utility;
#include common_scripts\utility;
/*
Name: _fs_init
Description: This script initializes FS Mod gamemode selection menu and handles the host's choice
ToDo:
- Player voting?
- Add support for other gamemodes
Notes:
- Gamemode selection menufile is in ui/scriptmenus/fs_gamemode_select.menu
*/
init()
{
	// PRECACHE ALL STUFF HERE
	PrecacheMenu("fs_gamemode_select");
}

main()
{
	// No idea why I made a separate function for that but okay....
	handle_gm();
}


handle_gm()
{
	players = GetPlayers();
	players[0] FreezeControls(true); // Host can't move until a vote is made
	players[0] thread handle_gm_watcher("fs_gamemode_select"); // Open the Gamemode selection menu and wait until vote
	players[0] thread handle_gm_result(); // After all votes have been made, it's time to start the game!
}

handle_gm_result()
{
	self waittill("gm_chosen");
	self FreezeControls(false); // Unfreeze the host
	if(GetDvarInt("fs_start_round")>1 && self.gm_result == 0)
		level notify("gm_has_been_chosen",GetDvarInt("fs_start_round")); // Are we starting from round 5 or 20?
	else if(self.gm_result == 0)
		level notify("gm_has_been_chosen"); // Default round
	if(self.gm_result == 0){
		wait(10);
		add_points_based_on_rounds(); // Give points based on start round, just like in BO2
	}
	level.gm_result = self.gm_result; // Store the gamemode ID in here, for use in scripts
	if(self.gm_result == 2) maps\_fs_turned::main(); // Execute turned
	if(self.gm_result == 3) maps\_fs_scavenger_gm::main();	// Execute Scavenger
}

add_points_based_on_rounds()
{
	players = GetPlayers();
	result = 0;
	for(i=0;i<players.size;i++)
	{
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
		
		if(responsemenu != menu) // Was the response from a different menu? not good, continue
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
				self FreezeControls(false); // Unfreezing the host in here too, just in case
				self CloseMenu(menu);
				break;
		}
	}
}
