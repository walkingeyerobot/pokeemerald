Shuffler_Trainer1::
	trainerbattle_single 1, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer2::
	trainerbattle_single 2, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer3::
	trainerbattle_single 3, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer4::
	trainerbattle_single 4, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer5::
	trainerbattle_single 5, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer6::
	trainerbattle_single 6, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer7::
	trainerbattle_single 7, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer8::
	trainerbattle_single 8, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Trainer9::
	trainerbattle_single 9, 0, 0
	msgbox Shuffler_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
Shuffler_Text_PostBattle:
	.string "postbattle$"
Shuffler_WildMon_Common::
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	removeobject VAR_LAST_TALKED
	releaseall
	end
Shuffler_WildMon1::
	lockall
	setwildbattle 1, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon2::
	lockall
	setwildbattle 2, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon3::
	lockall
	setwildbattle 3, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon4::
	lockall
	setwildbattle 4, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon5::
	lockall
	setwildbattle 5, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon6::
	lockall
	setwildbattle 6, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon7::
	lockall
	setwildbattle 7, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon8::
	lockall
	setwildbattle 8, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_WildMon9::
	lockall
	setwildbattle 9, 69, ITEM_NONE
    call Shuffler_WildMon_Common
Shuffler_Item1::
	finditem 1
	end
Shuffler_Item2::
	finditem 2
	end
Shuffler_Item3::
	finditem 3
	end
Shuffler_Item4::
	finditem 4
	end
Shuffler_Item5::
	finditem 5
	end
Shuffler_Item6::
	finditem 6
	end
Shuffler_Item7::
	finditem 7
	end
Shuffler_Item8::
	finditem 8
	end
Shuffler_Item9::
	finditem 9
	end
