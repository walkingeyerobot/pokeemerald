.set LOCAL_TRAINER_1, 1
.set LOCAL_TRAINER_1_OBJ, 1
.set LOCAL_WILDMON_1, 1
.set LOCAL_WILDMON_1_OBJ, 2

LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	@map_script MAP_SCRIPT_ON_INTRO_TRAINERS, LittlerootTown_BrendansHouse_1F_OnIntroTrainers
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
	end

LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
	end

LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
	.2byte 0

LittlerootTown_BrendansHouse_1F_OnIntroTrainers:
	@declaretrainer LOCAL_TRAINER_1_OBJ, LOCAL_TRAINER_1
	@declarewildmon LOCAL_WILDMON_1_OBJ, LOCAL_WILDMON_1
	end

LittlerootTown_BrendansHouse_1f_EventScript_WildMon1::
	lockall
	setwildbattle LOCAL_WILDMON_1, 69, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject VAR_LAST_TALKED
	releaseall
	end

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
