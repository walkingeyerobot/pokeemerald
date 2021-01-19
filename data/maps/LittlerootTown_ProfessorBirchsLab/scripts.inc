LittlerootTown_ProfessorBirchsLab_MapScripts:: @ 81F9C91
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	map_script MAP_SCRIPT_ON_INTRO_TRAINERS, LittlerootTown_ProfessorBirchsLab_OnIntroTrainers
	.byte 0

LittlerootTown_ProfessorBirchsLab_OnTransition: @ 81F9CA1
	end

LittlerootTown_ProfessorBirchsLab_OnWarp: @ 81F9D06
	.2byte 0

LittlerootTown_ProfessorBirchsLab_OnFrame: @ 81F9DB9
	.2byte 0

LittlerootTown_ProfessorBirchsLab_OnIntroTrainers:
	declarewildmon 1
	declarewildmon 2
	declarewildmon 3
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WildMon1::
	lockall
	setwildbattle 1, 69, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject VAR_LAST_TALKED
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WildMon2::
	lockall
	setwildbattle 2, 69, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject VAR_LAST_TALKED
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WildMon3::
	lockall
	setwildbattle 3, 69, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject VAR_LAST_TALKED
	releaseall
	end