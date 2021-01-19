LittlerootTown_MaysHouse_2F_MapScripts:: @ 81F9296
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_2F_OnFrame
	map_script MAP_SCRIPT_ON_INTRO_TRAINERS, LittlerootTown_MaysHouse_2F_OnIntroTrainers
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition: @ 81F92A1
	end

LittlerootTown_MaysHouse_2F_OnWarp: @ 81F931D
	.2byte 0

LittlerootTown_MaysHouse_2F_OnFrame:
	.2byte 0

LittlerootTown_MaysHouse_2F_OnIntroTrainers:
	declaretrainer 1
	declaretrainer 2
	end

LittlerootTown_MaysHouse_2F_EventScript_Tiana::
	trainerbattle_single 1, 0, 0
	msgbox LittlerootTown_BrendansHouse_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

LittlerootTown_MaysHouse_2F_EventScript_Tiana2::
	trainerbattle_single 2, 0, 0
	msgbox LittlerootTown_BrendansHouse_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end