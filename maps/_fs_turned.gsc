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
	handle_gm();
}

handle_gm()
{
	init_weapon_list();
	players = GetPlayers();
	array_thread(players,::debug_player);
}

debug_player()
{
	self IPrintLnBold(self.stats);
}

init_weapon_list()
{
	level._turned_weapons = [];
	add_weapon("fs_m4");
	add_weapon("fs_aug");
	add_weapon("fs_colt");
}

add_weapon(weapname)
{
	level._turned_weapons[level._turned_weapons.size] = weapname;
}

spawn_cure()
{

}

make_all_players_zombies()
{

}

// Pasted it here, cause might come in use

ai_damage( mod, hit_location, hit_origin, player )
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
	

	//self thread maps\_zombiemode_powerups::check_for_instakill( player );
}

ai_damage_ads( mod, hit_location, hit_origin, player )
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
			self.ignoreAttacker = eAttacker;
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

	self.intermission = true;

	self thread maps\_laststand::PlayerLastStand( eInflictor, eAttacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime );
	self player_die();
	level notify("player_died",self);

	self maps\_callbackglobal::finishPlayerDamageWrapper( eInflictor, eAttacker, finalDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, modelIndex, psOffsetTime ); 
}

player_die()
{
	if(self.isHuman){
		self.isHuman = false;
		self.team = "axis";
		self TakeAllWeapons();
		self.gun_rank = 0;
		self become_zombie();
	}
}

become_zombie()
{
	//self SetViewModel(); // I need the viewhands first
	self GiveWeapon("zm_hands");
}

player_become_human()
{
	self.isHuman = true;
	self.team = "allies";
	self TakeAllWeapons();
	self.gun_rank = 0;
	self GiveWeapon("fs_m4");
}

player_watch_rank()
{
	self endon("disconnect");
	while(!level.intermission)
	{
		wait_network_frame();
		if(!self HasWeapon(level._turned_weapons[self.gun_rank]) || self GetCurrentWeapon() != level._turned_weapons[self.gun_rank])
		{
			self TakeAllWeapons();
			self GiveWeapon(level._turned_weapons[self.gun_rank]);
		} else {
			continue;
		}
	}
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
	p1_kills.y += 20*ofsy;
	p1_kills.foreground = true;
	p1_kills.fontScale = 2;
	p1_kills.alpha = 0;
	p1_kills.color = ( 1.0, 1.0, 1.0 );
	p1_kills FadeOverTime(2);
	p1_kills.alpha = 1;
	score = player.score;
	if(score < 0) score = 0;
	p1_kills SetText("^2"+player.playername+"^7 - Kills: ^1"+player.stats["kills"]+" ^7Score: ^3"+score);
	return p1_kills;
}