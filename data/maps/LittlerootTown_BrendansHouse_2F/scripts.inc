LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition: @ 81F83EE
	end

LittlerootTown_BrendansHouse_2F_OnWarp: @ 81F846A
	.2byte 0

LittlerootTown_BrendansHouse_2F_Item1::
	finditem 1
	end
