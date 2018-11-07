#include "global.h" //includes constants/costumes.h
#include "bg.h"
#include "costume_menu.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "gpu_regs.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "data/costume_menu/costume_descriptions.h"
#include "data/costume_menu/costumes.h"

extern const struct CompressedSpriteSheet gTrainerFrontPicTable[];
extern const struct CompressedSpriteSheet gTrainerBackPicTable[];
extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];
extern const u16 sPlayerAvatarGfxIds[][8];

static EWRAM_DATA struct SpriteTemplate sSpriteTemplateBase = {};
static EWRAM_DATA u8 gDisplayList[NUMBER_OF_COSTUMES] = {0};
static EWRAM_DATA u16 gGreyScalePaletteBuffer[0x10] = {0};
static EWRAM_DATA u8 selection = 0;
static EWRAM_DATA u8 sScrollBarState = 0;
static EWRAM_DATA u8 ListMode = 0;
static EWRAM_DATA u8 sMaxSelection = 0;
static EWRAM_DATA u8 sListPosition = 0;

// static declarations

static void CreateOverworldScrollBar(void);
static void UpdateSpritePositions(void);
static void HandleKeyPresses(u8 taskId);
static void UpdateBackgroundGraphics(void);
static void UpdateSlotNumbers(struct Sprite *sprite);
static void SpriteCallback_UpdateSpritePosition(struct Sprite *sprite);
static void TrainerSpriteCallback(struct Sprite *sprite);
static void CreateTrainerSprite(void);
static void SetSpriteTemplateParameters(void);
static void InitializeTextWindows(void);
static void UpdateCostumeNameAndDescription(void);
static void CreateNewScrollBarSlot(s8 slot);
static void CreateConfirmationMenu(void);
static void ProcessYesNoMenu(u8 taskId);
static void CheckIfSpriteIsAnimated(struct Sprite *sprite);
static void CloseMenuScreen(u8 taskId);
void UnlockCostumesByGender(u8 playerGender);
static void PlayFieldMoveAnimation(u16 graphicsId);
static u8 GetSpriteIdByXY(s16 x, s16 y);
static void CreateStandardCostumeList(void);
static void CreateCostumeListByGender(u8 playerGender);
static void CreateUnlockedCostumeList(void);
static void UpdateDisplayMode(void);
static void CreateDisplayList(void);
static void CreateListModeIndicator(void);
static void LoadCompressedObjectPaletteWithGreyscale(const struct CompressedSpritePalette *src);

extern void TintPalette_GrayScale(u16 *palette, u16 count);
extern void FieldEffectFreeGraphicsResources(struct Sprite *sprite);

//.rodata

static const u32 gGraphics_CostumeScreenBackground[] = INCBIN_U32("graphics/costume_screen/background.4bpp.lz");
static const u16 gPalette_CostumeScreenBackground[] = INCBIN_U16("graphics/costume_screen/background.gbapal");
static const u32 gTilemap_CostumeScreenBackground[] = INCBIN_U32("graphics/costume_screen/background_tilemap.bin.lz");

static const u32 gGraphics_CostumeMenuButtonBar[] = INCBIN_U32("graphics/costume_screen/button_bar.4bpp.lz");
static const u16 gPalette_CostumeMenuButtonBar[] = INCBIN_U16("graphics/costume_screen/button_bar.gbapal");
static const u32 gTilemap_CostumeMenuButtonBar[] = INCBIN_U32("graphics/costume_screen/button_bar_tilemap.bin.lz");

static const u32 gGraphics_ListModeIndicatorMale[] = INCBIN_U32("graphics/costume_screen/list_mode_indicator_male.4bpp.lz");
static const u32 gGraphics_ListModeIndicatorFemale[] = INCBIN_U32("graphics/costume_screen/list_mode_indicator_female.4bpp.lz");
static const u32 gGraphics_ListModeIndicatorUnlocked[] = INCBIN_U32("graphics/costume_screen/list_mode_indicator_unlocked.4bpp.lz");
static const u32 gPalette_ListModeIndicators[] = INCBIN_U32("graphics/costume_screen/list_mode_indicators.gbapal.lz");

static const u8 gText_MaleSymbol[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE} ♂");
static const u8 gText_FemaleSymbol[] = _("{COLOR RED}{SHADOW LIGHT_RED} ♀");
static const u8 gText_ChangeCostume[] = _("Change costume?");

static const u8 gText_UnableToChange[] = _("You can’t do that right now!");
static const u8 gText_UnableToChange_Cycling[] = _("You can’t change whilst cycling, you\nwill fall off!");
static const u8 gText_UnableToChange_Surfing[] = _("You can’t change whilst surfing, you\nwill get wet!");
static const u8 gText_UnableToChange_Diving[] = _("You can’t change whilst diving, you\nwill drown!");

static const u8 sFontColourTable[3] = {0, 1, 2};   // fgColour, bgColour and shadowColour // represents indices of chosen palette

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
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 2,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
   {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct OamData sOamData_CostumeSlots =
{
    .y = 0,                        // top of sprite
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,                      // .4bpp if 0, .8bpp if 1
    .shape = 0,                    // square, wide, tall
    .x = 0,                        // left of sprite
    .matrixNum = 0,
    .size = 2,                     // 0 = 8x8, 1 = 16x16, 2 = 32x32, 3 = 64x64 (if shape is square)
    .tileNum = 0,
    .priority = 0,                 // draw order, higher = drawn earlier
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOamData_TrainerSprite =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 9,
    .affineParam = 0,
};

static const struct OamData sOamData_ListModeIndicators =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 10,
    .affineParam = 0,
};

const struct CompressedSpriteSheet ListModeIndicators[3] =
{
// .data, .size, .tag
    gGraphics_ListModeIndicatorMale, 32, 10000,
    gGraphics_ListModeIndicatorFemale, 32, 10001,
    gGraphics_ListModeIndicatorUnlocked, 32, 10002,
};
const struct CompressedSpritePalette sListModeIndicatorsPalette = {gPalette_ListModeIndicators, 10000};

static const struct SpriteTemplate sSpriteTemplate_ListModeIndicators[3] = 
{
    10000, 10000, &sOamData_ListModeIndicators, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy,
    10001, 10000, &sOamData_ListModeIndicators, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy,
    10002, 10000, &sOamData_ListModeIndicators, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy,
};

static const struct WindowTemplate sWindowTemplate_CostumeMenu[] = 
{
    { // NAME_WINDOW
        .priority = 1,                    // bg layer
        .tilemapLeft = 1,                 // x position, in no. of tiles (8x8 pixels)
        .tilemapTop = 2,                  // y position
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,                   // initial tile number in vram? relative to .charBaseIndex of bgTemplate?
    },
    {// DESCRIPTION_WINDOW
        .priority = 1,
        .tilemapLeft = 1,
        .tilemapTop = 9,
        .width = 29,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 36,
    },
    {// YES_NO_WINDOW
        .priority = 2,
        .tilemapLeft = 22,
        .tilemapTop = 10,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 220,
    },
    {// CONFIRMATION_WINDOW
        .priority = 2,
        .tilemapLeft = 2,
        .tilemapTop = 10,
        .width = 15,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 260,
    },
    {// COSTUME_CHANGE_WINDOW
        .priority = 2,
        .tilemapLeft = 2,
        .tilemapTop = 10,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 320,
    },
};

// .text

void LoadBackgroundGraphics(void)
{
    LZ77UnCompVram(gGraphics_CostumeScreenBackground, (void *)VRAM);
    LoadPalette(gPalette_CostumeScreenBackground, 0x00, 0x20);
    LZ77UnCompVram(gTilemap_CostumeScreenBackground, (u16 *)BG_SCREEN_ADDR(1));

    LZ77UnCompVram(gGraphics_CostumeMenuButtonBar, (void *)(VRAM + 0x8000));
    LoadPalette(gPalette_CostumeMenuButtonBar, 0x10, 0x20);
    LZ77UnCompVram(gTilemap_CostumeMenuButtonBar, (u16 *)BG_SCREEN_ADDR(7));

    InitBgsFromTemplates(0, gBgTemplates_CostumeScreen, ARRAY_COUNT(gBgTemplates_CostumeScreen));
    ResetAllBgsCoordinates();
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

void VBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CostumeMenu_MainCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void CB2_CostumeMenu(void)
{
    switch (gMain.state)
    {
        case 0:
        default:
            SetVBlankCallback(NULL);
            ScanlineEffect_Stop();
            ResetTasks();
            ResetSpriteData();
            ResetPaletteFade();
            FreeAllSpritePalettes();
            DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
            gMain.state++;
            break;
        case 1:
            selection = 0;            //selection = gSaveBlock2Ptr->costume
            sScrollBarState = NONE;
            ListMode = LIST_STANDARD;
            LoadBackgroundGraphics();
            CreateDisplayList();
            CreateOverworldScrollBar();
            SetSpriteTemplateParameters();
            CreateTrainerSprite();
            InitializeTextWindows();
            UpdateCostumeNameAndDescription();
            gMain.state++;
            break;
        case 2:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            SetVBlankCallback(VBlankCallback);
            SetMainCallback2(CostumeMenu_MainCallback);
            CreateTask(HandleKeyPresses, 0);
            break;
    }
}

static void HandleKeyPresses(u8 taskId)
{
    if (sScrollBarState == NONE && !gPaletteFade.active)
    {
        if ((gMain.newAndRepeatedKeys & DPAD_RIGHT) && (selection != sMaxSelection - 1))
        {
            if (selection < sMaxSelection - 4)
            {
                CreateNewScrollBarSlot(4);
            }
            sScrollBarState = SCROLL_RIGHT;
            selection++;
            UpdateCostumeNameAndDescription();
            PlaySE(SE_Z_SCROLL);
        }
        if ((gMain.newAndRepeatedKeys & DPAD_LEFT) && (selection != 0))
        {
            if (selection > 3)
            {
                CreateNewScrollBarSlot(-4);
            }
            sScrollBarState = SCROLL_LEFT;
            selection--;
            UpdateCostumeNameAndDescription();
            PlaySE(SE_Z_SCROLL);
        }
        if ((gMain.newKeys & A_BUTTON) && (gSaveBlock2Ptr->costumeFlags[gDisplayList[selection]] == TRUE))
        {
            CreateConfirmationMenu();
            PlaySE(SE_SELECT);
            gTasks[taskId].func = ProcessYesNoMenu;
        }
        if (gMain.newKeys & (B_BUTTON | START_BUTTON) && !IsSEPlaying())
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            PlaySE(SE_PC_OFF);
            gTasks[taskId].func = CloseMenuScreen;
        }
        if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_T_KAMI);
//            UnlockCostumesByGender(MALE); //for debug purposes
//            UnlockCostumesByGender(FEMALE); //for debug purposes
            ResetSpriteData();
            FreeAllSpritePalettes();
            UpdateDisplayMode();
            CreateDisplayList();
            CreateOverworldScrollBar();
            CreateTrainerSprite();
            UpdateCostumeNameAndDescription();
        }
        else if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT | A_BUTTON))
        {
            PlaySE(SE_HAZURE);
        }
    }
}

static void CloseMenuScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

//-------------------------------
// Scrollbar
//-------------------------------

#define slotId data[0]
#define costumeId data[1]

static const u8 slotSize = 32;
static const s16 xPos_initial = 120;
static const s16 yPos = 136;

static void CreateOverworldScrollBar(void)
{
    s8 slot;
    u8 xPos;
    u16 displayedCostume;
    u8 spriteId;
    u8 maxSlot;
    u8 index;

    maxSlot = 3;
    if (sMaxSelection < 3)
    {
        maxSlot = sMaxSelection - 1;
    }

    for (slot = 0; slot <= maxSlot; slot++)
    {
        xPos = xPos_initial + (slot * slotSize);
        displayedCostume = gCostumes[gDisplayList[selection + slot]].overworld;
        spriteId = AddPseudoEventObject(displayedCostume, UpdateSlotNumbers, xPos, yPos, 0);
        gSprites[spriteId].slotId = slot;
        gSprites[spriteId].costumeId = gDisplayList[selection + slot];
        if (gSprites[spriteId].slotId == 0)
        {
            StartSpriteAnim(&gSprites[spriteId], 4);
        }
        if (gSaveBlock2Ptr->costumeFlags[gDisplayList[selection + slot]] == FALSE)
        {
            index = IndexOfSpritePaletteTag(gSprites[spriteId].template->paletteTag);
            CpuCopy16(&gPlttBufferUnfaded[0x100 + index * 16], gGreyScalePaletteBuffer, 32);
            TintPalette_GrayScale(gGreyScalePaletteBuffer, 16);
            LoadPalette(gGreyScalePaletteBuffer, 0x100 + index * 16, 32);
        }
    }
}

static void CreateNewScrollBarSlot(s8 slot)
{
    u8 spriteId;
    u16 displayedCostume;
    u8 index;

    displayedCostume = gCostumes[gDisplayList[selection + slot]].overworld;
    spriteId = AddPseudoEventObject(displayedCostume, UpdateSlotNumbers, xPos_initial + slot*slotSize, yPos, 0);
    gSprites[spriteId].slotId = slot;
    gSprites[spriteId].costumeId = gDisplayList[selection + slot];

    if (gSaveBlock2Ptr->costumeFlags[gDisplayList[selection + slot]] == FALSE)
    {
        index = IndexOfSpritePaletteTag(gSprites[spriteId].template->paletteTag);
        CpuCopy16(&gPlttBufferUnfaded[0x100 + index * 16], gGreyScalePaletteBuffer, 32);
        TintPalette_GrayScale(gGreyScalePaletteBuffer, 16);
        LoadPalette(gGreyScalePaletteBuffer, 0x100 + index * 16, 32);
    }
}

static void UpdateSlotNumbers(struct Sprite *sprite)
{
    if (sScrollBarState == SCROLL_RIGHT)
    {
        sprite->slotId--;
        CheckIfSpriteIsAnimated(sprite);
        sprite->callback = SpriteCallback_UpdateSpritePosition;
    }
    if (sScrollBarState == SCROLL_LEFT)
    {
        sprite->slotId++;
        CheckIfSpriteIsAnimated(sprite);
        sprite->callback = SpriteCallback_UpdateSpritePosition;
    }
}

static void CheckIfSpriteIsAnimated(struct Sprite *sprite)
{
    if (sprite->slotId != 0 && sprite->costumeId == gDisplayList[selection + sprite->slotId])
    {
        sprite->animCmdIndex = 0;
        sprite->animEnded = TRUE;
        sprite->animNum = 0;
    }
}
static void SpriteCallback_UpdateSpritePosition(struct Sprite *sprite)
{
    // slotId represents what slot within the scroll bar the sprite is in.
    // UpdateSlotNumbers() increments/decrements slotId depending on the 
    // button press in order for this callback to compare the current
    // position of the sprite to its next slot position

    if (sprite->pos1.x > (xPos_initial + sprite->slotId*slotSize))        //DPAD_RIGHT
    {
        sprite->pos1.x -= 4;
    }
    if (sprite->pos1.x < (xPos_initial + sprite->slotId*slotSize))        //DPAD_LEFT
    {
        sprite->pos1.x += 4;
    }
    if (sprite->pos1.x <= xPos_initial - (4*slotSize) || sprite->pos1.x >= xPos_initial + (4*slotSize))
    {
        FieldEffectFreeGraphicsResources(sprite);
    }
    else if (sprite->pos1.x == xPos_initial + sprite->slotId*slotSize)
    {
        if ((sprite->slotId == 0) && (sprite->costumeId == gDisplayList[selection]))
        {
            sprite->animNum = 4;
            sprite->animBeginning = TRUE;
            sprite->animEnded = FALSE;
        }
        sScrollBarState = NONE;
        sprite->callback = UpdateSlotNumbers;
    }
}

#undef slotId

//-------------------------------
// Trainer sprite
//-------------------------------

static void SetSpriteTemplateParameters(void)
{
    sSpriteTemplateBase.anims = gDummySpriteAnimTable;
    sSpriteTemplateBase.images = NULL;
    sSpriteTemplateBase.affineAnims = gDummySpriteAffineAnimTable;
    sSpriteTemplateBase.oam = &sOamData_TrainerSprite;
    sSpriteTemplateBase.callback = TrainerSpriteCallback;
}

static void CreateTrainerSprite(void)
{
    u8 spriteId;
    u16 displayedCostume = gCostumes[gDisplayList[selection]].trainerFront;

    sSpriteTemplateBase.tileTag =  gTrainerFrontPicTable[displayedCostume].tag;
    sSpriteTemplateBase.paletteTag = gTrainerFrontPicPaletteTable[displayedCostume].tag;

    LoadCompressedObjectPaletteWithGreyscale(&gTrainerFrontPicPaletteTable[displayedCostume]);
    LoadCompressedObjectPic(&gTrainerFrontPicTable[displayedCostume]);
    spriteId = CreateSprite(&sSpriteTemplateBase, 200, 40, 0);
    gSprites[spriteId].costumeId = gDisplayList[selection];
}

static void TrainerSpriteCallback(struct Sprite *sprite)
{
    if (sprite->costumeId != gDisplayList[selection])
    {
        FreeSpritePalette(sprite);
        FreeSpriteTiles(sprite);
        DestroySprite(sprite);
        CreateTrainerSprite();
    }
}

static void LoadCompressedObjectPaletteWithGreyscale(const struct CompressedSpritePalette *src)
{
    struct SpritePalette dest;

    LZ77UnCompWram(src->data, gGreyScalePaletteBuffer);
    if (gSaveBlock2Ptr->costumeFlags[gDisplayList[selection]] == FALSE)
    {
        TintPalette_GrayScale(gGreyScalePaletteBuffer, 16);
    }
    dest.data = (void*) gGreyScalePaletteBuffer;
    dest.tag = src->tag;
    LoadSpritePalette(&dest);
}

//-------------------------------
// Textboxes
//-------------------------------

static void InitializeTextWindows(void)
{
    InitWindows(sWindowTemplate_CostumeMenu);
    DeactivateAllTextPrinters();
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xf0, 0x20);
    LoadUserWindowBorderGfx(YES_NO_WINDOW, 211, 0xe0);
}

static void CreateTextbox(u8 windowId)
{
    FillWindowPixelBuffer(windowId, 0);
    PutWindowTilemap(windowId);
    AddTextPrinterParameterized3(windowId, 1, 0, 0, sFontColourTable, -1, gStringVar4);
    CopyWindowToVram(windowId, 3);
}

static void AddGenderSymbols(void)
{
    if (gCostumes[gDisplayList[selection]].gender == MALE)
    {
        StringAppend(gStringVar4, gText_MaleSymbol);
    }
    else if (gCostumes[gDisplayList[selection]].gender == FEMALE)
    {
        StringAppend(gStringVar4, gText_FemaleSymbol);
    }
}

static void AddText(const u8 *text, const u8 *locked)
{
    StringExpandPlaceholders(gStringVar4, text);
    if (gSaveBlock2Ptr->costumeFlags[gDisplayList[selection]] == FALSE)
    {
        StringExpandPlaceholders(gStringVar4, locked);
    }
}
static void UpdateCostumeNameAndDescription(void)
{
    AddText(gCostumes[gDisplayList[selection]].name, gText_CostumeName_Locked);
    AddGenderSymbols();
    CreateTextbox(NAME_WINDOW);
    AddText(gCostumes[gDisplayList[selection]].description, gText_CostumeDescription_Locked);
    CreateTextbox(DESCRIPTION_WINDOW);
}

static void CreateConfirmationMenu(void)
{
    FillWindowPixelBuffer(CONFIRMATION_WINDOW, 0);
    SetWindowBorderStyle(CONFIRMATION_WINDOW, FALSE, 211, 14);
    AddTextPrinterParameterized(CONFIRMATION_WINDOW, 1, gText_ChangeCostume, 0, 1, 0, NULL);
    PutWindowTilemap(CONFIRMATION_WINDOW);
    CopyWindowToVram(CONFIRMATION_WINDOW, 3);
    CreateYesNoMenu(&sWindowTemplate_CostumeMenu[2], 211, 14, 1);
}

static void GetUnableToChangeText(void)
{
    if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
    {
        StringExpandPlaceholders(gStringVar4, gText_UnableToChange_Cycling);
        return;
    }
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
    {
        StringExpandPlaceholders(gStringVar4, gText_UnableToChange_Surfing);
        return;
    }
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_UNDERWATER)
    {
        StringExpandPlaceholders(gStringVar4, gText_UnableToChange_Diving);
        return;
    }
    else
        StringExpandPlaceholders(gStringVar4, gText_UnableToChange);
}

static void CreateUnableToChangeTextbox(void)
{
    FillWindowPixelBuffer(COSTUME_CHANGE_WINDOW, 0);
    SetWindowBorderStyle(COSTUME_CHANGE_WINDOW, FALSE, 211, 14);
    GetUnableToChangeText();
    AddTextPrinterParameterized(COSTUME_CHANGE_WINDOW, 1, gStringVar4, 0, 1, 0, NULL);
    PutWindowTilemap(COSTUME_CHANGE_WINDOW);
    CopyWindowToVram(COSTUME_CHANGE_WINDOW, 3);
}

static void DestroyTextBox(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sub_8198070(COSTUME_CHANGE_WINDOW, TRUE);
        ClearWindowTilemap(COSTUME_CHANGE_WINDOW);
        gTasks[taskId].func = HandleKeyPresses;
    }
}

static void SanitiseCostumeId(void)
{
    if (gDisplayList[selection] <= 9) //ARRAY_COUNT(sPlayerAvatarGfxIds))
    {
        gSaveBlock2Ptr->costume = gDisplayList[selection];
        gSaveBlock2Ptr->playerGender = gCostumes[gDisplayList[selection]].gender;
    }
    else
    {
        gSaveBlock2Ptr->costume = 0;
        gSaveBlock2Ptr->playerGender = MALE;
    }
}

static void ProcessYesNoMenu(u8 taskId)
{
    switch (Menu_ProcessInputNoWrap_())
    {
        case 0: // Yes
            if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
            {
                PlayFanfare(MUS_ME_B_SMALL);
                SanitiseCostumeId();
                PlayFieldMoveAnimation(gCostumes[gDisplayList[selection]].fieldMove);
                sub_8198070(CONFIRMATION_WINDOW, FALSE); //from menu.c
                ClearWindowTilemap(CONFIRMATION_WINDOW);
                gTasks[taskId].func = HandleKeyPresses;
            }
            else
            {
                CreateUnableToChangeTextbox();
                gTasks[taskId].func = DestroyTextBox;
            }
            break;
        case 1:
        case -1: // No
            PlaySE(SE_SELECT);
            sub_8198070(CONFIRMATION_WINDOW, FALSE);
            ClearWindowTilemap(CONFIRMATION_WINDOW);
            gTasks[taskId].func = HandleKeyPresses;
            break;
    }
}

//-----------------------------
// Animate sprites
//-----------------------------

static u8 GetSpriteIdByXY(s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
        if ((gSprites[i].inUse) && (gSprites[i].pos1.x == x) && (gSprites[i].pos1.y == y))
            return i;
}

static void PlayFieldMoveAnimation(u16 graphicsId)
{
    const struct EventObjectGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 spriteId = GetSpriteIdByXY(xPos_initial, yPos);

    graphicsInfo = GetEventObjectGraphicsInfo(graphicsId);
    sprite = &gSprites[spriteId];
    sprite->images = graphicsInfo->images;
    sprite->anims = graphicsInfo->anims;
    sprite->costumeId = graphicsId;
    StartSpriteAnim(sprite, 0);
}

#undef costumeId
//----------------------------
// Debug
// ---------------------------

void UnlockCostumesByGender(u8 playerGender)
{
    u8 i;

    for (i = 0; i < NUMBER_OF_COSTUMES; i++)
        if (gCostumes[i].gender == playerGender)
        {
            gSaveBlock2Ptr->costumeFlags[i] = TRUE;
        }
}

bool8 UnlockCostumeByCostumeId(u8 costumeId)
{
    gSaveBlock2Ptr->costumeFlags[costumeId] = TRUE;
    return TRUE;
}
//----------------------------
// Filter system
// ---------------------------

static void CreateStandardCostumeList(void)
{
    u8 i;

    for (i = 0; i < NUMBER_OF_COSTUMES; i++)
        if ((gCostumes[i].hidden == FALSE) || (gSaveBlock2Ptr->costumeFlags[i] == TRUE))
        {
            gDisplayList[sListPosition] = i;
            sListPosition++;
            sMaxSelection++;
        }
}

static void CreateCostumeListByGender(u8 playerGender)
{
    u8 i;

    for (i = 0; i < NUMBER_OF_COSTUMES; i++)
        if ((gCostumes[i].gender == playerGender) && ((gCostumes[i].hidden == FALSE) || (gSaveBlock2Ptr->costumeFlags[i] == TRUE)))
        {
            gDisplayList[sListPosition] = i;
            sListPosition++;
            sMaxSelection++;
        }
}

static void CreateUnlockedCostumeList(void)
{
    u8 i;

    for (i = 0; i < NUMBER_OF_COSTUMES; i++)
        if (gSaveBlock2Ptr->costumeFlags[i] == TRUE)
        {
            gDisplayList[sListPosition] = i;
            sListPosition++;
            sMaxSelection++;
        }
}

static void UpdateDisplayMode(void)
{
    ListMode++;
    if (ListMode > LIST_UNLOCKED)
        {
            ListMode = LIST_STANDARD;
        }
}

static void CreateDisplayList(void)
{
    selection = 0;
    sMaxSelection = 0;
    sListPosition = 0;

    switch (ListMode)
    {
        case LIST_STANDARD:
        default:
            CreateStandardCostumeList();
            break;
        case LIST_MALE:
            CreateCostumeListByGender(MALE);
            break;
        case LIST_FEMALE:
            CreateCostumeListByGender(FEMALE);
            break;
        case LIST_UNLOCKED:
            CreateUnlockedCostumeList();
            break;
    }

    if (ListMode > LIST_STANDARD)
    {
       CreateListModeIndicator();
    } 
}

static void CreateListModeIndicator(void)
{
    u8 spriteId;

    LoadCompressedObjectPalette(&sListModeIndicatorsPalette);
    LoadCompressedObjectPic(&ListModeIndicators[ListMode - 1]);
    spriteId = CreateSprite(&sSpriteTemplate_ListModeIndicators[ListMode - 1], 202 + ListMode*8, 7, 0);
}
