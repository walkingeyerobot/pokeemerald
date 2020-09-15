LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
	end

LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
	end

LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
	.2byte 0

LittlerootTown_BrendansHouse_EventScript_Tiana::
	trainerbattle_single TRAINER_SAWYER_1, LittlerootTown_BrendansHouse_Text_TianaIntro, LittlerootTown_BrendansHouse_Text_TianaDefeated
	msgbox LittlerootTown_BrendansHouse_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

LittlerootTown_BrendansHouse_Text_TianaIntro:
	.string "intro$"

LittlerootTown_BrendansHouse_Text_TianaDefeated:
	.string "defeated$"

LittlerootTown_BrendansHouse_Text_TianaPostBattle:
	.string "postbattle$"
