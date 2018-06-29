#include "global.h"
#include "main.h"
#include "bg.h"
#include "costume_menu.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/rgb.h"
#include "constants/songs.h"

u8 gCostumeSpriteId[7];
u16 selection;
s8 slot;

// static declarations

static void CreateOverworldScrollBar(void);
static void UpdateSpritePositions(void);
static void HandleKeyPresses(void);

//.rodata

static const u8 gGraphics_CostumeScreenBackground[] = INCBIN_U8("graphics/costume_screen/background.4bpp.lz");
static const u16 gPalette_CostumeScreenBackground[] = INCBIN_U16("graphics/costume_screen/background.gbapal");
static const u16 gTilemap_CostumeScreenBackground[] = INCBIN_U16("graphics/costume_screen/background_tilemap.bin.lz");

const struct BgTemplate gBgTemplates_CostumeScreen[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 1,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct OamData sOamData_CostumeSlots =
{
    .y = 0,						//top of sprite
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,					// .4bpp if 0, .8bpp if 1?
    .shape = 0,					// square, wide, tall
    .x = 0,						// left of sprite
    .matrixNum = 0,
    .size = 2,					//0 = 8x8, 1 = 16x16, 2 = 32x32, 3 = 64x64? (if shape is square)
    .tileNum = 0,
    .priority = 0,				//draw order, higher = drawn earlier
    .paletteNum = 0,
    .affineParam = 0,
};

const u8 gGraphics_Costume_Red[] = INCBIN_U8("graphics/costume_screen/overworlds/red.4bpp.lz");
const u8 gPalette_Costume_Red[] = INCBIN_U8("graphics/costume_screen/overworlds/red.gbapal.lz");
const u8 gGraphics_Costume_Lyra[] = INCBIN_U8("graphics/costume_screen/overworlds/lyra.4bpp.lz");
const u8 gPalette_Costume_Lyra[] = INCBIN_U8("graphics/costume_screen/overworlds/lyra.gbapal.lz");
const u8 gGraphics_Costume_Lance[] = INCBIN_U8("graphics/costume_screen/overworlds/lance.4bpp.lz");
const u8 gPalette_Costume_Lance[] = INCBIN_U8("graphics/costume_screen/overworlds/lance.gbapal.lz");
const u8 gGraphics_Costume_Misty[] = INCBIN_U8("graphics/costume_screen/overworlds/misty.4bpp.lz");
const u8 gPalette_Costume_Misty[] = INCBIN_U8("graphics/costume_screen/overworlds/misty.gbapal.lz");
const u8 gGraphics_Costume_RocketM[] = INCBIN_U8("graphics/costume_screen/overworlds/rocket_m.4bpp.lz");
const u8 gPalette_Costume_RocketM[] = INCBIN_U8("graphics/costume_screen/overworlds/rocket_m.gbapal.lz");
const u8 gGraphics_Costume_RocketF[] = INCBIN_U8("graphics/costume_screen/overworlds/rocket_f.4bpp.lz");
const u8 gPalette_Costume_RocketF[] = INCBIN_U8("graphics/costume_screen/overworlds/rocket_f.gbapal.lz");
const u8 gGraphics_Costume_ProfOak[] = INCBIN_U8("graphics/costume_screen/overworlds/prof_oak.4bpp.lz");
const u8 gPalette_Costume_ProfOak[] = INCBIN_U8("graphics/costume_screen/overworlds/prof_oak.gbapal.lz");

#define GFX_TAG_COSTUME_RED 10000
#define GFX_TAG_COSTUME_LYRA 10001
#define GFX_TAG_COSTUME_LANCE 10002
#define GFX_TAG_COSTUME_MISTY 10003
#define GFX_TAG_COSTUME_ROCKET_M 10004
#define GFX_TAG_COSTUME_ROCKET_F 10005
#define GFX_TAG_COSTUME_PROF_OAK 10006

const struct CompressedSpriteSheet sCostumeOverworldSpriteTable[] =
{
// .data              .size            .tag
	{gGraphics_Costume_Red, 512, 10000},                  // (32x32/2) = 512 = 0x200
	{gGraphics_Costume_Lyra, 512, 10001},
	{gGraphics_Costume_Lance, 512, 10002},
	{gGraphics_Costume_Misty, 512, 10003},
	{gGraphics_Costume_RocketM, 512, 10004},
	{gGraphics_Costume_RocketF, 512, 10005},
	{gGraphics_Costume_ProfOak, 512, 10006},
// duplicates
	{gGraphics_Costume_ProfOak, 512, 10006},
	{gGraphics_Costume_ProfOak, 512, 10006},
	{gGraphics_Costume_ProfOak, 512, 10006},
	{gGraphics_Costume_ProfOak, 512, 10006},
};

const struct CompressedSpritePalette sCostumeOverworldPaletteTable[] =
{
	{gPalette_Costume_Red, 10000},
	{gPalette_Costume_Lyra, 10001},
	{gPalette_Costume_Lance, 10002},
	{gPalette_Costume_Misty, 10003},
	{gPalette_Costume_RocketM, 10004},
	{gPalette_Costume_RocketF, 10005},
	{gPalette_Costume_ProfOak, 10006},
// duplicates
	{gPalette_Costume_ProfOak, 10006},
	{gPalette_Costume_ProfOak, 10006},
	{gPalette_Costume_ProfOak, 10006},
	{gPalette_Costume_ProfOak, 10006},
};

static const struct SpriteTemplate sSpriteTemplate_Costumes[] = 
{
//        .tileTag             .paletteTag             .oam                  .anims         .images        .affineAnims               .callback
    {GFX_TAG_COSTUME_RED, GFX_TAG_COSTUME_RED, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy,},
	{GFX_TAG_COSTUME_LYRA, GFX_TAG_COSTUME_LYRA, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_LANCE, GFX_TAG_COSTUME_LANCE, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_MISTY, GFX_TAG_COSTUME_MISTY, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_ROCKET_M, GFX_TAG_COSTUME_ROCKET_M, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_ROCKET_F, GFX_TAG_COSTUME_ROCKET_F, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_PROF_OAK, GFX_TAG_COSTUME_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
// duplicates
	{GFX_TAG_COSTUME_PROF_OAK, GFX_TAG_COSTUME_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_PROF_OAK, GFX_TAG_COSTUME_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_PROF_OAK, GFX_TAG_COSTUME_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
	{GFX_TAG_COSTUME_PROF_OAK, GFX_TAG_COSTUME_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy},
};

// .text

void LoadBackgroundGraphics(void)
{
	LZ77UnCompVram(gGraphics_CostumeScreenBackground, (void *)VRAM);
    LoadPalette(gPalette_CostumeScreenBackground, 0x00, 0x20);
	LZ77UnCompVram(gTilemap_CostumeScreenBackground, (u16 *)BG_SCREEN_ADDR(1));
	
	InitBgsFromTemplates(0, gBgTemplates_CostumeScreen, 1);
	ShowBg(0);
	HideBg(3);
	HideBg(1);
	HideBg(2);
}

void CB2_CostumeMenu(void)
{
    switch (gMain.state)
    {
        case 0:
        default:
			ScanlineEffect_Stop();
            ResetTasks();
            ResetSpriteData();
            ResetPaletteFade();
            FreeAllSpritePalettes();
			DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
            gMain.state++;
            break;
        case 1:
			LoadBackgroundGraphics();
			//LoadOam();			
			CreateOverworldScrollBar();
			BuildOamBuffer();
            gMain.state++;
            break;
        case 2:
			SetMainCallback2(HandleKeyPresses);
			break;
    }
}

static void HandleKeyPresses(void)
{
	if (gMain.newKeys & DPAD_RIGHT)
	{
		if (selection != NUMBER_OF_COSTUMES)
		{
			selection++;
			PlaySE(SE_SELECT);
			UpdateSpritePositions();
		}
		else
			PlaySE(SE_PIN);
	}
	if (gMain.newKeys & DPAD_LEFT)
	{
		if (selection != 0)
		{
			selection--;
			PlaySE(SE_SELECT);			
			UpdateSpritePositions();
		}
		else
			PlaySE(SE_PIN);
	}
	if (gMain.newKeys & R_BUTTON)
	{
		if (selection <= NUMBER_OF_COSTUMES - 7)
			selection = selection + 7;
		else if (selection == NUMBER_OF_COSTUMES)
			PlaySE(SE_PIN);
		else
			selection = NUMBER_OF_COSTUMES;
	}
	if (gMain.newKeys & L_BUTTON)
	{
		if (selection >= 7)
			selection = selection - 7;
		else if (selection == 0)
			PlaySE(SE_PIN);
		else
			selection = 0;
	}
	if (gMain.newKeys & A_BUTTON)
	{
		//pop-up confirmation menu first
		PlaySE(SE_SELECT);
	}
	if (gMain.newKeys & B_BUTTON)
	{
		BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
		PlaySE(SE_PC_OFF);
		SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
	}
	if (gMain.heldKeys & DPAD_LEFT)
	{
        PlaySE(SE_Z_SCROLL);
	}
}

u8 XPos_initial = 24;

static void CreateOverworldScrollBar(void)
{
	//s8 slot;
	u8 XPos;
	u16 DisplayedCostume;
	u8 YPos = 136;
	
	for (slot = 0; slot <= 6; slot++)
	{
		XPos = XPos_initial + (slot * 32);
		DisplayedCostume = selection + slot;
		LoadCompressedObjectPic(&sCostumeOverworldSpriteTable[DisplayedCostume]);
		LoadCompressedObjectPalette(&sCostumeOverworldPaletteTable[DisplayedCostume]);
		gCostumeSpriteId[slot] = CreateSprite(&sSpriteTemplate_Costumes[DisplayedCostume], XPos, YPos, 0);
	}
}


static void UpdateSpritePositions(void)
{
	s8 slot;
	
	for (slot = 0; slot <=6; slot++)
	{
	DestroySprite(&gSprites[gCostumeSpriteId[slot]]);
	}
	
	CreateOverworldScrollBar();
}
/*
static void UpdateSpritePositions(void)
{
	//s8 slot;

	DestroySprite(&gSprites[gCostumeSpriteId[0]]);
	DestroySprite(&gSprites[gCostumeSpriteId[1]]);
	DestroySprite(&gSprites[gCostumeSpriteId[2]]);
	DestroySprite(&gSprites[gCostumeSpriteId[3]]);
	DestroySprite(&gSprites[gCostumeSpriteId[4]]);
	DestroySprite(&gSprites[gCostumeSpriteId[5]]);
	DestroySprite(&gSprites[gCostumeSpriteId[6]]);
	CreateOverworldScrollBar();
}
*/