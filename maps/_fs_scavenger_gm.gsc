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
	level.global_damage_func = maps\_fs_scavenger_gm::zombie_damage; 
	level.global_damage_func_ads = maps\_fs_scavenger_gm::zombie_damage_ads;
	level.overridePlayerKilled = maps\_fs_scavenger_gm::player_killed_override;
	level.overridePlayerDamage = maps\_fs_scavenger_gm::player_damage_override;
	thread end_game2();
	thread time_count();
	gamemode_think();
}

time_count()
{
	level endon("end_game2");
	level.tg_seconds = 0;
	level.tg_minutes = 0;
	level.tg_hours = 0;
	for(;;wait(1))
	{
		level.tg_seconds++;
		if(level.tg_seconds >= 60){
			level.tg_seconds = 0;
			level.tg_minutes++;
		}
		if(level.tg_minutes >= 60)
		{
			level.tg_minutes = 0;
			level.tg_hours++;
		}
	}
}

init_weapon_list()
{
	add_scavenger_weapon("fs_colt",10);
	add_scavenger_weapon("fs_m4",10);
	add_scavenger_weapon("fs_aug",10);
	add_scavenger_weapon("fs_himar",10);
}

gamemode_think()
{
	flag_set("electricity_on");
	level._gm_scavenger_weapons = [];
	thread remove_debris();
	thread remove_guns();
	thread remove_perks();
	thread start_zombie_spawn_logic();
	players = GetPlayers();
	array_thread (players, ::prepare_players);
	thread start_weapon_spawn_logic();
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

remove_perks()
{
	vending_triggers = GetEntArray( "zombie_vending", "targetname" );
	vending_upgrade_trigger = GetEntArray("zombie_vending_upgrade", "targetname");
	for( i = 0; i < vending_triggers.size; i++ ) vending_triggers[i] trigger_off();
	for( i = 0; i < vending_upgrade_trigger.size; i++ ) vending_upgrade_trigger[i] trigger_off();
	machine = getentarray("zombie_vending_bo1", "targetname");
	for( i = 0; i < machine.size; i++ )	machine[i] trigger_off();
	chests = GetEntArray( "treasure_chest_use", "targetname" );
	for( i = 0; i < chests.size; i++ ) chests[i] trigger_off();
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

prepare_players()
{
	self.maxhealth = 100*2;
	self.health = self.maxhealth;
	self SetClientDvar("miniscoreboardhide",1);
	self.kill_count = 0;
}

start_weapon_spawn_logic()
{
	level endon("end_game");
	level.gun_count_max = 16;
	level.gun_count = 0;
	init_weapon_list();
	//thread waittill_pickup();
	start_weapons = 9;
	nodes = GetAllNodes();
	for(i=0;i<start_weapons;i++)
	{
		wait_network_frame();
		playable = GetEnt("playable_area","targetname");
		temp = array_randomize(level._gm_scavenger_weapons);
		randomNode = RandomInt(nodes.size);
		if(!(nodes[randomNode] isTouching(playable))) continue;
		SpawnWeapon(temp[0],nodes[randomNode].origin);
		//iPrintLn("A weapon called "+temp[0]+" has just been spawned!");
	}
	while(1)		
	{
		wait_network_frame();
		playable = GetEnt("playable_area","targetname");
		temp = array_randomize(level._gm_scavenger_weapons);
		randomNode = RandomInt(nodes.size);
		if(!(nodes[randomNode] isTouching(playable)) || !players_see_node(nodes[randomNode]) ) continue;
		SpawnWeapon(temp[0],nodes[randomNode].origin);
		//iPrintLn("A weapon called "+temp[0]+" has just been spawned!");
		wait(randomInt(10));
	}
}

// CODE BELOW THANKS TO DidUknowiPwn

SpawnWeapon( weapon_name, origin )
{
        weapon = weapon_name;
        item = Spawn( "weapon_" + weapon_name, origin + (0,0,12) );
        item SetModel( GetWeaponModel(weapon) );
        item.weaponDropped = weapon;
        clipAmmo = RandomInt( WeaponClipSize(weapon) );
        stockAmmo = RandomIntRange( WeaponClipSize(weapon), WeaponMaxAmmo( weapon ) + 1 );
        stockMax = WeaponMaxAmmo( weapon );
        if ( stockAmmo > stockMax )
                stockAmmo = stockMax;
 
        item ItemWeaponSetAmmo( clipAmmo, stockAmmo );
        item itemRemoveAmmoFromAltModes();

        //item SetHintString("Press &&1 to pick up "+item getItemWeaponName());
 
}
 
itemRemoveAmmoFromAltModes()
{
        origweapname = self getItemWeaponName();
 
        curweapname = weaponAltWeaponName( origweapname );
 
        altindex = 1;
        while ( curweapname != "none" && curweapname != origweapname )
        {
                self itemWeaponSetAmmo( 0, 0, altindex );
                curweapname = weaponAltWeaponName( curweapname );
                altindex++;
        }
}
 
getItemWeaponName()
{
        classname = self.classname;
        assert( getsubstr( classname, 0, 7 ) == "weapon_" );
        weapname = getsubstr( classname, 7 );
        return weapname;
}

// END OF PWN's CODE

players_see_node(node)
{
	players = GetPlayers();
	for(i=0;i<players.size;i++)
	{
		if(within_fov( players[i].origin, players[i] GetPlayerAngles(), node.origin, cos(90) )) return true;
	}
	return false;
}

add_scavenger_weapon(weapname,chances)
{
	if(!isDefined(chances)) chances = 1;
	for(i=0;i<chances;i++)
	{
		level._gm_scavenger_weapons[level._gm_scavenger_weapons.size] = weapname;
	}
}

start_zombie_spawn_logic()
{
	level endon( "intermission" );

	if( level.intermission )
	{
		return;
	}

	ai_calculate_health(); 
	old_spawn = undefined;
	level.zombie_move_speed = 0;
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
	level.zombie_health = Int( level.zombie_vars["zombie_health_increase"] ); 
}

// DAMAGING ZOMBIES IS HANDLED HERE
// Why am I doing this? Since the scoreboard is hidden, there's no point for having the score points pop up

zombie_damage( mod, hit_location, hit_origin, player )
{
	if( is_magic_bullet_shield_enabled( self ) )
	{
		return;
	}

	//ChrisP - 12/8 - no points for killing gassed zombies!
	player.use_weapon_type = mod;
	if(isDefined(self.marked_for_death))
	{
		return;
	}	

	if( !IsDefined( player ) )
	{
		return; 
	}


	if ( mod == "MOD_GRENADE" || mod == "MOD_GRENADE_SPLASH" )
	{
		if ( isdefined( player ) && isalive( player ) )
		{
			self DoDamage( level.round_number + randomintrange( 100, 500 ), self.origin, player);
		}
		else
		{
			self DoDamage( level.round_number + randomintrange( 100, 500 ), self.origin, undefined );
		}
	}
	else if( mod == "MOD_PROJECTILE" || mod == "MOD_EXPLOSIVE" || mod == "MOD_PROJECTILE_SPLASH" || mod == "MOD_PROJECTILE_SPLASH")
	{
		if ( isdefined( player ) && isalive( player ) )
		{
			self DoDamage( level.round_number * randomintrange( 0, 100 ), self.origin, player);
		}
		else
		{
			self DoDamage( level.round_number * randomintrange( 0, 100 ), self.origin, undefined );
		}
	}
	else if( mod == "MOD_ZOMBIE_BETTY" )
	{
		if ( isdefined( player ) && isalive( player ) )
		{
			self DoDamage( level.round_number * randomintrange( 100, 200 ), self.origin, player);
		}
		else
		{
			self DoDamage( level.round_number * randomintrange( 100, 200 ), self.origin, undefined );
		}
	}
	
	if(self.health<=0) player.kill_count++;

	//self thread maps\_zombiemode_powerups::check_for_instakill( player );
}

zombie_damage_ads( mod, hit_location, hit_origin, player )
{
	if( is_magic_bullet_shield_enabled( self ) )
	{
		return;
	}

	player.use_weapon_type = mod;
	if( !IsDefined( player ) )
	{
		return; 
	}

	//self thread maps\_zombiemode_powerups::check_for_instakill( player );
}

// NOW HERE WE DAMAGE THE PLAYER


player_damage_override( eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime )
{
	/*	
	if(self hasperk("specialty_armorvest") && eAttacker != self)
	{
			iDamage = iDamage * 0.75;
			iprintlnbold(idamage);
	}*/
	
	if( sMeansOfDeath == "MOD_FALLING" )
	{
		sMeansOfDeath = "MOD_EXPLOSIVE";
	}

	if( isDefined( eAttacker ) )
	{
		if( isDefined( self.ignoreAttacker ) && self.ignoreAttacker == eAttacker ) 
		{
			return;
		}
		
		if( isDefined( eAttacker.is_zombie ) && eAttacker.is_zombie )
		{
			//self.ignoreAttacker = eAttacker;
			//self thread remove_ignore_attacker();
		}
		
		if( isDefined( eAttacker.damage_mult ) )
		{
			iDamage *= eAttacker.damage_mult;
		}
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
	if( level.intermission )
	{
		level waittill( "forever" );
	}

	players = get_players();
	count = 0;
	for( i = 0; i < players.size; i++ )
	{
		if( players[i] == self || players[i].is_zombie || players[i] maps\_laststand::player_is_in_laststand() || players[i].sessionstate == "spectator" )
		{
			count++;
		}
	}

	if( count < players.size )
	{
		self maps\_callbackglobal::finishPlayerDamageWrapper( eInflictor, eAttacker, finalDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime ); 
		return;
	}

	self.intermission = true;

	self thread maps\_laststand::PlayerLastStand( eInflictor, eAttacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime );
	self player_fake_death();

	if( count == players.size )
	{
		level notify( "end_game2" );
	}
	else
	{
		self maps\_callbackglobal::finishPlayerDamageWrapper( eInflictor, eAttacker, finalDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime ); 
	}
}

player_fake_death()
{
	level notify ("fake_death");
	self notify ("fake_death");
	self ShellShock("dog_bite",100000);
	self TakeAllWeapons();
	self AllowStand( false );
	self AllowCrouch( false );
	self AllowProne( true );
	self DisableWeapons();

	self.ignoreme = true;
	self EnableInvulnerability();

	wait( 1 );
	self FreezeControls( true );
}

player_killed_override()
{
	// BLANK
	level waittill( "forever" );
}

// HERE WE HANDLE ENDING THE GAME 

end_game2()
{
	level waittill ( "end_game2" );

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
	game_over SetText( &"ZOMBIE_GAME_OVER" );

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
	if(level.tg_hours == 0)
		survived SetText( "You survived "+level.tg_minutes+":"+level.tg_seconds );
	else
		survived SetText( "You survived "+level.tg_hours+":"+level.tg_minutes+":"+level.tg_seconds );
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
	p1_kills.y += 60+10*ofsy;
	p1_kills.foreground = true;
	p1_kills.fontScale = 2;
	p1_kills.alpha = 0;
	p1_kills.color = ( 1.0, 1.0, 1.0 );
	p1_kills FadeOverTime(2);
	p1_kills.alpha = 1;
	score = player.score-level.zombie_vars["zombie_score_start"];
	if(score < 0) score = 0;
	p1_kills SetText("^2"+player.playername+"^7 - Kills: ^1"+player.stats["kills"]+" ^7Score: ^3"+score);
	return p1_kills;
}