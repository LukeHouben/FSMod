#include maps\_utility;
#include maps\_music;
#include maps\_busing;
#include common_scripts\utility;
#include maps\_zombiemode_utility; 


init()
{

}

main()
{
	level.overridePlayerKilled = ::player_killed_override;
	level.overridePlayerDamage = ::player_damage_override;
	thread end_game2();
	handle_gm();

}

handle_gm()
{
	init_weapon_list();
	players = GetPlayers();
	array_thread(players,::prepare_player);
	thread start_zombie_spawn_logic();
	thread remove_guns();
	thread remove_debris();
}


start_zombie_spawn_logic()
{
	if( level.intermission )
	{
		return;
	}
	old_spawn = undefined;
	level.zombie_move_speed = 0;
	level.zombie_health = Int( level.zombie_vars["zombie_health_increase"] );
	thread ai_calculate_health(); 
	while( 1 )
	{
		//iPrintLn("trying to spawn a zombie");
		wait_network_frame(); //UGX fix
		if(level.enemy_spawns.size <= 0) iPrintLn("^1NO SPAWNERS!!!"); //UGX fix
		spawn_point = level.enemy_spawns[RandomInt( level.enemy_spawns.size )]; 
		if( !IsDefined( old_spawn ) )
		{
				old_spawn = spawn_point;
		}
		else if( Spawn_point == old_spawn )
		{
				spawn_point = level.enemy_spawns[RandomInt( level.enemy_spawns.size )]; 
		}
		old_spawn = spawn_point;

	//	iPrintLn(spawn_point.targetname + " " + level.zombie_vars["zombie_spawn_delay"]);
		//while( get_enemy_count() > 20)
		//{
		//	wait( 0.05 );
		//}

		ai = spawn_zombie( spawn_point ); 
		//if(isDefined(ai)) iPrintLn("Zombie spawned!");
		//else iPrintLn("Zombie spawn failed!");
		wait( 2 ); 
		level.zombie_move_speed += 35;
		//wait_network_frame();
		
	}

}

ai_calculate_health()
{
	wait(120);
	while(level.zombie_health < 550){
		level.zombie_health += 100; 
		wait((600-120)/5);
	}
	if(level.zombie_health > 550) level.zombie_health = 550;
}

prepare_player()
{
	self.gun_rank = 0;
	self.lives = 3;
	self.kills_lost = 0;
	self.health = 100;
	self.maxhealth = 100;
	self.health = 100;
	self thread player_watch_rank();
	self thread points_watch();
}

points_watch()
{
	self endon("disconnect");
	level endon("end_game2");
	while(1)
	{
		wait_network_frame();
		if((self.stats["kills"]-self.kills_lost) >= int(level._gungame_weapons_kills[self.gun_rank]))
		{
			self.gun_rank += 1;
			if(!isDefined(level._gungame_weapons_kills[self.gun_rank]))
			{
				self.gun_rank -= 1;
				self.ignoreme = true;
				level notify("end_game2",self);
				return;
			}
		} else if((self.stats["kills"]-self.kills_lost) < level._gungame_weapons_kills[self.gun_rank-1] && isDefined(level._gungame_weapons_kills[self.gun_rank-1])) {
			self.gun_rank -=1;
		}
	}
}

init_weapon_list()
{
	level._gungame_weapons = [];
	level._gungame_weapons_kills = [];
	//add_weapon( weapon file name here, how many kills do you need to get with that gun (includes all before) to rank up)
	/*
	add_weapon("browning_zm",20);
	add_weapon("tac45",55);
	add_weapon("mp9",75);
	add_weapon("m14",105);
	add_weapon("vector",130);
	add_weapon("ak47_zm",150);
	add_weapon("honeybadger",180);
	add_weapon("acr",205);
	add_weapon("mp5",235);
	add_weapon("m72_law",250);
	add_weapon("s12_zm",280);
	//add_weapon("mw2_aug",325);
	add_weapon("p90",360);
	add_weapon("m27",400);
	add_weapon("arx_160",440);
	//add_weapon("hamr",490);
	add_weapon("striker",535);
	//add_weapon("mw3_ak74u",570);
	add_weapon("msr",595);
	add_weapon("magnum",615);
	//add_weapon("mw2_spas12",645);
	add_weapon("mg36",690);
	add_weapon("ksg_z",720);
	add_weapon("cheytac",745);
	add_weapon("raygun_mark2",795);
	//add_weapon("minigun",845);
	add_weapon("scavenger",895);
	//add_weapon("slip_gun",945);
	*/
	add_weapon("fs_colt",20);
	add_weapon("fs_m4",40);
}

add_weapon(weapname,kills_needed)
{
	level._gungame_weapons[level._gungame_weapons.size] = weapname;
	if(isDefined(kills_needed))
		level._gungame_weapons_kills[level._gungame_weapons_kills.size] = kills_needed;
	else
		level._gungame_weapons_kills[level._gungame_weapons_kills.size] = int(level._gungame_weapons_kills[level._gungame_weapons_kills.size-1]*1.5);
}

// Pasted it here, cause might come in use
player_damage_override( eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime )
{
	/*	
	if(self hasperk("specialty_armorvest") && eAttacker != self)
	{
			iDamage = iDamage * 0.75;
			iprintlnbold(idamage);
	}*/

	if(self.is_dead == 1 || level.intermission) return;
	
	if( sMeansOfDeath == "MOD_FALLING" )
	{
		sMeansOfDeath = "MOD_EXPLOSIVE";
	}

	if( isDefined( eAttacker ) )
	{
		eAttacker notify( "hit_player" );
	}
	finalDamage = iDamage;

	if( sMeansOfDeath == "MOD_PROJECTILE" || sMeansOfDeath == "MOD_PROJECTILE_SPLASH" || sMeansOfDeath == "MOD_GRENADE" || sMeansOfDeath == "MOD_GRENADE_SPLASH" )
	{
		if( self.health > 75 )
		{
			finalDamage = 75;
			self maps\_callbackglobal::finishPlayerDamageWrapper( eInflictor, eAttacker, finalDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime ); 
			return;
		}
	}

	if( iDamage < self.health )
	{
		if ( IsDefined( eAttacker ) )
		{
			eAttacker.sound_damage_player = self;
		}
		
		//iprintlnbold(iDamage);
		self maps\_callbackglobal::finishPlayerDamageWrapper( eInflictor, eAttacker, finalDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime ); 
		return;
	}
	//iPrintLn("hey, "+self.playername+" just got noscoped by a zombie!");
	players = get_players();

	if(self.lives != 0)	{
		self player_die();
		//iprintln("player has lives");
	} else {
		//iprintln("player dies");
		self player_final_death();
		if(GetPlayers().size == 1){
			level notify("end_game2");
		}
		else
		{
			iprintlnbold(self.playername+" died!");
			self.is_dead = 1;
			self.gun_rank = 0;
			players = GetPlayers();
			for(i=0;i<players.size;i++)
			{
				if(players[i].is_dead == 0) break;
				level notify("end_game2");
			}
		}
	}

	self maps\_callbackglobal::finishPlayerDamageWrapper( eInflictor, eAttacker, finalDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime ); 
}


remove_guns()
{
	weapon_spawns = GetEntArray( "weapon_upgrade", "targetname" ); 
	for( i = 0; i < weapon_spawns.size; i++ )
	{
		weapon_spawns[i] SetHintString("");
		weapon_spawns[i] trigger_off();
	}
}

remove_debris()
{
	// DOORS ----------------------------------------------------------------------------- //
	zombie_doors = GetEntArray( "zombie_door", "targetname" ); 

	for( i = 0; i < zombie_doors.size; i++ )
	{
		zombie_doors[i] notify("trigger",undefined,true);
	}

	// DEBRIS ---------------------------------------------------------------------------- //
	zombie_debris = GetEntArray( "zombie_debris", "targetname" ); 

	for( i = 0; i < zombie_debris.size; i++ )
	{
		zombie_debris[i] notify("trigger",undefined,true);
	}
}

player_final_death()
{
	self notify ("fake_death");
	self EnableInvulnerability();
	self.health = self.maxhealth;
	self TakeAllWeapons();
	self AllowStand( false );
	self AllowCrouch( false );
	self AllowProne( true );
	self DisableWeapons();
	wait(1);
	self.ignoreme = true;
	self.gun_rank = -1;
	self.stats["kills"] = 0;
	self FreezeControls( true );
}

player_die()
{
	self notify ("fake_death");
	//if(self.gun_rank != 0) self.gun_rank -= 1; // OLD SCRIPT
	if(self.gun_rank != 0){
		self.kills_lost += int(self.stats["kills"]*0.75);
	}
	self.lives -= 1;
	death_origin = self GetOrigin();
	nodes = GetAllNodes();
	while(1)
	{
		randomNode = RandomInt(nodes.size);
		if(!nodes[randomNode] IsTouchingPlayable() && Distance(nodes[randomNode].origin,death_origin) < 256) continue;
		else
		break;
	}
	
	self SetOrigin(nodes[randomNode].origin);
	self.health = self.maxhealth;
	self iprintlnbold("Lives left: "+self.lives);
	self SetStance("stand");
}

player_watch_rank()
{
	self endon("disconnect");
	while(1)
	{
		wait_network_frame();
		if(!self HasWeapon(level._gungame_weapons[self.gun_rank]) || self GetCurrentWeapon() != level._gungame_weapons[self.gun_rank])
		{
			self TakeAllWeapons();
			self GiveWeapon(level._gungame_weapons[self.gun_rank]);
			self GiveMaxAmmo(level._gungame_weapons[self.gun_rank]);
			self SwitchToWeapon(level._gungame_weapons[self.gun_rank]);
		} else if(self.gun_rank == -1){
			self TakeAllWeapons();
		} else {
			self SetWeaponAmmoStock(level._gungame_weapons[self.gun_rank],WeaponMaxAmmo(level._gungame_weapons[self.gun_rank]));
		}
	}
}

player_killed_override()
{
	// BLANK
	level waittill( "forever" );
}

IsTouchingPlayable()
{
	playable = GetEntArray("playable_area","targetname");
	for(i=0;i<playable.size;i++)
	{
		if(!self IsTouching(playable[i])) return false;
	}
	return true;
}

// HERE WE HANDLE ENDING THE GAME 

end_game2()
{
	level waittill ( "end_game2" ,who_won);

	level.intermission = true;

	//update_leaderboards();

	game_over = NewHudElem( self );
	game_over.alignX = "center";
	game_over.alignY = "middle";
	game_over.horzAlign = "center";
	game_over.vertAlign = "middle";
	game_over.y -= 10;
	game_over.foreground = true;
	game_over.fontScale = 3;
	game_over.alpha = 0;
	game_over.color = ( 1.0, 1.0, 1.0 );
	game_over SetText( "GAME OVER" );

	game_over FadeOverTime( 1 );
	game_over.alpha = 1;

	survived = NewHudElem( self );
	survived.alignX = "center";
	survived.alignY = "middle";
	survived.horzAlign = "center";
	survived.vertAlign = "middle";
	survived.y += 20;
	survived.foreground = true;
	survived.fontScale = 2;
	survived.alpha = 0;
	survived.color = ( 1.0, 1.0, 1.0 );
	if(isDefined(who_won))
		survived SetText( who_won.playername+" wins!");
	else
		survived SetText( "No one wins!");
	//TUEY had to change this since we are adding other musical elements
	setmusicstate("end_of_game");
	setbusstate("default");

	survived FadeOverTime( 1 );
	survived.alpha = 1;

	wait( 1 );


	//play_sound_at_pos( "end_of_game", ( 0, 0, 0 ) );
	wait( 2 );
	players = GetPlayers();
	scores = [];
	for(i=0;i<players.size;i++)
	{
		scores[i] = MakeScoreBar(players[i],i);
	}

	game_over MoveOverTime(5);
	game_over.y -=180;
	game_over FadeOverTime(5);
	game_over.color = (1,0,0);
	survived MoveOverTime(5);
	survived.y -=180;
	//intermission();

	wait( level.zombie_vars["zombie_intermission_time"] );

	level notify( "stop_intermission" );
	//array_thread( get_players(), ::player_exit_level );

	bbPrint( "zombie_epilogs: rounds %d", level.round_number );

	wait( 1.5 );

	if( is_coop() )
	{
		ExitLevel( false );
	}
	else
	{
		MissionFailed();
	}



	// Let's not exit the function
	wait( 666 );
}

MakeScoreBar(player,ofsy)
{
	p1_kills = NewHudElem();
	p1_kills.alignX = "center";
	p1_kills.alignY = "middle";
	p1_kills.horzAlign = "center";
	p1_kills.vertAlign = "middle";
	p1_kills.y += 20*ofsy;
	p1_kills.foreground = true;
	p1_kills.fontScale = 2;
	p1_kills.alpha = 0;
	p1_kills.color = ( 1.0, 1.0, 1.0 );
	p1_kills FadeOverTime(2);
	p1_kills.alpha = 1;
	p1_kills SetText("^2"+player.playername+"^7 - Kills: ^1"+player.stats["kills"]+" - Rank: "+player.gun_rank+"");
	return p1_kills;
}