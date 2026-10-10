/*
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#define TC_LEVEL         1               /* For achieving a given level */
#define TC_FMOUNT        2               /* Obtaining a flying mount */
#define TC_TORCH         3               /* Having a given number of torches */
#define TC_STEPS         4               /* Steps taken */
#define TC_SLEEP         5               /* Hours slept */
#define TC_LGOLD         6               /* Gold looted */
#define TC_GOLD          7               /* Posessing looted */
#define TC_TYPE          8               /* Using a particular item type x times */
#define TC_ITEM          9               /* Using a particular item x times */
#define TC_COMN         10               /* Common loot picked up */
#define TC_RARE         11               /* Rare loot picked up */
#define TC_VRARE        12               /* Very Rare loot picked up */
#define TC_URARE        13               /* Ultra Rare loot picked up */
#define TC_LCLEAR       14               /* Dungeon levels cleared */
#define TC_HOUSE        15               /* Houses paid for */
#define TC_CRAFT        16               /* Crafting a given number of items */
#define TC_LORE         17               /* Learning all lore messages */
#define TC_MESG         18               /* Learning all general messages */
#define TC_SOCK         19               /* Number of items socketed */
#define TC_ENCH         20               /* Number of items enchanted */
#define TC_DRAGON       21               /* Slaying dragons */
#define TC_PICKT        22               /* Picking up a given item type */
#define TC_MSTAT        23               /* Stats maxed */
#define TC_FIRE         24               /* Using the fire command */
#define TC_PICKI        25               /* Picking up a particular item */
#define TC_TOXIC        26               /* Times poisoned */
#define TC_DEF          27               /* Defense value */
#define TC_DMGDN        28               /* Total damage done */
#define TC_DMGTK        29               /* Total damage taken */
#define TC_SOLD         30               /* Total items sold */
#define TC_TALK         31               /* Number of people talked to */
#define TC_CLASS        32               /* Classes taken */
#define TC_IDENT        33               /* Items identified */
#define TC_EQUIP        34               /* equiping the given items */
#define TC_PICKR        35               /* Picking up all items in a given range */
#define TC_ITEMR        36               /* Using all items in a given range */
#define TC_HKILL        37               /* Killing x monsters n levels above you */
#define TC_TRICK        38               /* Trick or treat while wearing all items in given range */
#define TC_DCLEAR       39               /* Fully clear a dungeon */
#define TC_QUESTS       40               /* All quests marked as complete */
#define TC_SKILL        41               /* Skill >= x */
#define TC_TROPHY       42               /* Have all trophies but this one */
#define TC_CARDS        43               /* Collect a set of trading cards */

typedef struct {
  int criteria_type;
  int control[8];
  char name[32];
  char desc[128];
  } TROPHY_REC;

#ifdef MAIN

TROPHY_REC trophies[] = {
  { TC_LEVEL,   {     10,      0,    0,    0,    0,    0,    0,    0, },   "Level 10",          "Achieving level 10" },                /* 0 */
  { TC_LEVEL,   {     20,      0,    0,    0,    0,    0,    0,    0, },   "Level 20",          "Achieving level 20" },                /* 1 */
  { TC_LEVEL,   {     30,      0,    0,    0,    0,    0,    0,    0, },   "Level 30",          "Achieving level 30" },                /* 2 */
  { TC_LEVEL,   {     40,      0,    0,    0,    0,    0,    0,    0, },   "Level 40",          "Achieving level 40" },                /* 3 */
  { TC_LEVEL,   {     50,      0,    0,    0,    0,    0,    0,    0, },   "Level 50",          "Achieving level 50" },                /* 4 */
  { TC_FMOUNT,  {      0,      0,    0,    0,    0,    0,    0,    0, },   "Flying High",       "Obtaining a flying mount" },          /* 5 */
  { TC_TORCH,   {   1000,      0,    0,    0,    0,    0,    0,    0, },   "Let there be light","Posessing 1,000 torches" },           /* 6 */
  { TC_STEPS,   {    1e7,      0,    0,    0,    0,    0,    0,    0, },   "Pedestrian",        "Taking 10,000,000 steps" },           /* 7 */
  { TC_SLEEP,   {   8760,      0,    0,    0,    0,    0,    0,    0, },   "Sleepy head",       "Sleeping 8,760 hours" },              /* 8 */
  { TC_LGOLD,   {    1e6,      0,    0,    0,    0,    0,    0,    0, },   "Greedy",            "Looting 1,000,000 gold" },            /* 9 */
  { TC_GOLD,    {    1e6,      0,    0,    0,    0,    0,    0,    0, },   "Millionaire",       "Posessing 1,000,000 gold" },          /* 10 */
  { TC_TYPE,    { O_ALCH,   1000,    4,    0,    0,    0,    0,    0, },   "Bottom's up",       "Drinking 1,000 alcoholic drinks" },   /* 11 */
  { TC_ITEM,    {  T_359,     25,    5,    0,    0,    0,    0,    0, },   "Gender Bender",     "Changing your sex 25 times" },        /* 12 */
  { TC_COMN,    {    1e4,      0,    0,    0,    0,    0,    0,    0, },   "Garbage Collector", "Picking up 10,000 common loots" },    /* 13 */
  { TC_RARE,    {      1,      0,    0,    0,    0,    0,    0,    0, },   "Eye for Treasure",  "Finding a rare" },                    /* 14 */
  { TC_VRARE,   {      1,      0,    0,    0,    0,    0,    0,    0, },   "Treasure Hunter",   "Finding a very rare" },               /* 15 */
  { TC_URARE,   {      1,      0,    0,    0,    0,    0,    0,    0, },   "Lucky!",            "Finding an ultra rare" },             /* 16 */
  { TC_DCLEAR,  {      1,      0,    0,    0,    0,    0,    0,    0, },   "Thorough",          "Fully clearing a dungeon" },          /* 17 */
  { TC_LCLEAR,  {    200,      0,    0,    0,    0,    0,    0,    0, },   "Exterminator",      "Fully clearing 200 levels" },         /* 18 */
  { TC_HOUSE,   {      1,      0,    0,    0,    0,    0,    0,    0, },   "Homeowner",         "Paying off a house"},                 /* 19 */
  { TC_HOUSE,   {      5,      0,    0,    0,    0,    0,    0,    0, },   "Landlord",          "Purchasing 5 houses"},                /* 20 */
  { TC_CRAFT,   {    100,      0,    0,    0,    0,    0,    0,    0, },   "Craftsman",         "Crafting 100 items"},                 /* 21 */
  { TC_LORE,    {      0,      0,    0,    0,    0,    0,    0,    0, },   "Lore Master",       "Learning all lore messages"},         /* 22 */
  { TC_MESG,    {      0,      0,    0,    0,    0,    0,    0,    0, },   "Librarian",         "Learning all general messages"},      /* 23 */
  { TC_SOCK,    {    100,      0,    0,    0,    0,    0,    0,    0, },   "Socketeer",         "Add 100 sockets to items"},           /* 24 */
  { TC_ENCH,    {    250,      0,    0,    0,    0,    0,    0,    0, },   "Enchanted",         "Add 250 enchants to items"},          /* 25 */
  { TC_DRAGON,  {   1000,      0,    0,    0,    0,    0,    0,    0, },   "Dragon Slayer",     "Slaying 1,000 dragons"},              /* 26 */
  { TC_TYPE,    { O_SCRL,   2500,   18,    0,    0,    0,    0,    0, },   "Avid Reader",       "Reading 2,500 scrolls"},              /* 27 */
  { TC_TYPE,    { O_POTN,   2500,   19,    0,    0,    0,    0,    0, },   "Embider",           "Drinking 2500 potions"},              /* 28 */
  { TC_TYPE,    { O_FOOD,   2500,   20,    0,    0,    0,    0,    0, },   "Glutton",           "Eating 2,500 meals"},                 /* 29 */
  { TC_PICKT,   { O_JEWL,   2000,   21,    0,    0,    0,    0,    0, },   "Rockhound",         "Picking up 2000 rocks"},              /* 30 */
  { TC_MSTAT,   {      6,      0,    0,    0,    0,    0,    0,    0, },   "Stat Whore",        "Maxing all base stats"},              /* 31 */
  { TC_FIRE,    {   2500,      0,    0,    0,    0,    0,    0,    0, },   "William Tell",      "Firing 2,500 arrows"},                /* 32 */
  { TC_PICKI,   {  T_104,    250,   23,    0,    0,    0,    0,    0, },   "Easter Bunny",      "Picking up 250 eggs"},                /* 33 */
  { TC_ITEM,    {  T_105,    100,   20,T_150,  100,   25,    0,    0, },   "Meat and Potatoes", "Eat 100 meats and 100 potatos"},      /* 34 */
  { TC_ITEM,    {  T_380,      2,   26,    0,    0,    0,    0,    0, },   "Adam and Eve",      "Eat 2 Apples of Ultimate Power"},     /* 35 */
  { TC_TOXIC,   {    500,      0,    0,    0,    0,    0,    0,    0, },   "Toxic",             "Being poisoned 500 times"},           /* 36 */
  { TC_DEF,     {    250,      0,    0,    0,    0,    0,    0,    0, },   "Tank",              "Have a defense of 250 or more"},      /* 37 */
  { TC_DMGDN,   {    1e7,      0,    0,    0,    0,    0,    0,    0, },   "Bringing the Pain", "Doing 10,000,000 damage"},            /* 38 */
  { TC_DMGTK,   {    1e6,      0,    0,    0,    0,    0,    0,    0, },   "Punching Bag",      "Taking 1,000,000 damage"},            /* 39 */
  { TC_SOLD,    {    1e4,      0,    0,    0,    0,    0,    0,    0, },   "Hawker",            "Sell 10,000 items"},                  /* 40 */
  { TC_TALK,    {   2000,      0,    0,    0,    0,    0,    0,    0, },   "Talkative",         "Talking to 2,000 people"},            /* 41 */
  { TC_CLASS,   {    100,      0,    0,    0,    0,    0,    0,    0, },   "Higher Learning",   "Taking 100 classes"},                 /* 42 */
  { TC_HKILL,   {      1,     10,    0,    0,    0,    0,    0,    0, },   "David vs Goliath",  "Kill a monster 10 levels higher"},    /* 43 */
  { TC_IDENT,   {    1e4,      0,    0,    0,    0,    0,    0,    0, },   "Appraiser",         "Identifing 10,000 items"},            /* 44 */
  { TC_PICKR,   {  T_266,  T_277,   40,    0,    0,    0,    0,    0, },   "Ring Collector",    "Collecting all 12 birthstone rings"}, /* 45 */
  { TC_ITEM,    {  T_265,    100,   41,T_278,  100,   42,    0,    0, },   "Luck of the Irish", "100 Green Beer, 100 CB and cabbage"}, /* 46 */
  { TC_EQUIP,   {  T_281,  T_282,T_283,T_284,T_285,    0,    0,   43, },   "Blushing Bride",    "Wearing all the bridal items"},       /* 47 */
  { TC_EQUIP,   {  T_286,  T_287,T_288,T_285,    0,    0,    0,   44, },   "Dashing Groom",     "Wearing all the groom items"},        /* 48 */
  { TC_PICKR,   {  T_300,  T_319,   45,    0,    0,    0,    0,    0, },   "Charmed!",          "Collecting all 20 charms"},           /* 49 */
  { TC_ITEMR,   {  T_320,  T_339,   46,    0,    0,    0,    0,    0, },   "Let the Sparks Fly","Using 20 different fireworks"},       /* 50 */
  { TC_PICKR,   {  T_360,  T_379,   47,    0,    0,    0,    0,    0, },   "Candyman",          "Collect all 20 Halloween candies"},   /* 51 */
  { TC_TRICK,   {  T_340,  T_351,T_352,   48,    0,    0,    0,    0, },   "Trick or Treat",    "Trick or treat in all 12 costumes"},  /* 52 */
  { TC_ITEM,    {  T_290,    100,   49,    0,    0,    0,    0,    0, },   "Gobble Gobble",     "Eating 100 turkey dinners"},          /* 53 */
  { TC_ITEM,    {  T_292,     20,   50,    0,    0,    0,    0,    0, },   "Unwrapped!",        "Open 20 Christmas presents"},         /* 54 */
  { TC_EQUIP,   {  T_293,  T_294,T_295,T_296,    0,    0,    0,   51, },   "Ho Ho Ho",          "Wearing a full Santa suit"},          /* 55 */
  { TC_ITEM,    {  T_297,     25,   52,    0,    0,    0,    0,    0, },   "Kissy Kissy",       "Charm 25 monsters using Mistletoe"},  /* 56 */
  { TC_ITEM,    {  T_298,    100,   53,    0,    0,    0,    0,    0, },   "Be My Valentine",   "Giving 100 candy hearts to monsters"},/* 57 */
  { TC_PICKI,   {  T_452,      4,   57,    0,    0,    0,    0,    0, },   "Lucky Charms",      "Picking up 4 four leaf clovers"},     /* 58 */
  { TC_QUESTS,  {      0,      0,    0,    0,    0,    0,    0,    0, },   "Completionist",     "Completing all dungeons"},            /* 59 */
  { TC_ITEMR,   {  T_481,  T_497,   58,    0,    0,    0,    0,    0, },   "Shape Shifter",     "Using all the figurines"},            /* 60 */
  { TC_MSTAT,   {      1,      0,    0,    0,    0,    0,    0,    0, },   "Determined",        "Maxing a base stats"},                /* 61 */
  { TC_ITEM,    {  T_499,   1000,   59,    0,    0,    0,    0,    0, },   "Field Medic",       "Using 1000 bandages" },               /* 62 */
  { TC_SKILL,   {      1,     99,    0,    0,    0,    0,    0,    0, },   "Master Archer",     "Maxing bow skill"},                   /* 63 */
  { TC_SKILL,   {      2,     99,    0,    0,    0,    0,    0,    0, },   "Master of Swords",  "Maxing 1h sword skill"},              /* 64 */
  { TC_SKILL,   {      3,     99,    0,    0,    0,    0,    0,    0, },   "Master of Spears",  "Maxing spear skill"},                 /* 65 */
  { TC_SKILL,   {      4,     99,    0,    0,    0,    0,    0,    0, },   "Master of Maces",   "Maxing mace skill"},                  /* 66 */
  { TC_SKILL,   {      5,     99,    0,    0,    0,    0,    0,    0, },   "Master Scout",      "Maxing scouting skill"},              /* 67 */
  { TC_SKILL,   {      6,     99,    0,    0,    0,    0,    0,    0, },   "Master Luinguist",  "Maxing language skill"},              /* 68 */
  { TC_SKILL,   {      7,     99,    0,    0,    0,    0,    0,    0, },   "Loremaster",        "Maxing lore skill"},                  /* 69 */
  { TC_SKILL,   {      8,     99,    0,    0,    0,    0,    0,    0, },   "Master Magician",   "Maxing magic skill"},                 /* 70 */
  { TC_SKILL,   {      9,     99,    0,    0,    0,    0,    0,    0, },   "Master Medic",      "Maxing healing skill"},               /* 71 */
  { TC_SKILL,   {     10,     99,    0,    0,    0,    0,    0,    0, },   "Master Alchemest",  "Maxing medicine skill"},              /* 72 */
  { TC_SKILL,   {     11,     99,    0,    0,    0,    0,    0,    0, },   "Riding Master",     "Maxing riding skill"},                /* 73 */
  { TC_SKILL,   {     12,     99,    0,    0,    0,    0,    0,    0, },   "Master Mariner",    "Maxing boating skill"},               /* 74 */
  { TC_SKILL,   {     13,     99,    0,    0,    0,    0,    0,    0, },   "Visionary",         "Maxing oracle skill"},                /* 75 */
  { TC_SKILL,   {     14,     99,    0,    0,    0,    0,    0,    0, },   "Silver Tongue Devil","Maxing charm skill"},                /* 76 */
  { TC_SKILL,   {     15,     99,    0,    0,    0,    0,    0,    0, },   "Survivalist",       "Maxing survival skill"},              /* 77 */
  { TC_SKILL,   {     16,     99,    0,    0,    0,    0,    0,    0, },   "Combat Specialist", "Maxing combat skill"},                /* 78 */
  { TC_SKILL,   {     17,     99,    0,    0,    0,    0,    0,    0, },   "Master of Daggers", "Maxing dagger skill"},                /* 79 */
  { TC_SKILL,   {     18,     99,    0,    0,    0,    0,    0,    0, },   "BIG swords!",       "Maxing 2h sword skill"},              /* 80 */
  { TC_SKILL,   {     19,     99,    0,    0,    0,    0,    0,    0, },   "Lumberjack",        "Maxing axe skill"},                   /* 81 */
  { TC_SKILL,   {     20,     99,    0,    0,    0,    0,    0,    0, },   "All Hail Flails",   "Maxing flail skill"},                 /* 82 */
  { TC_SKILL,   {     21,     99,    0,    0,    0,    0,    0,    0, },   "Crossbowman",       "Maxing crossbow skill"},              /* 83 */
  { TC_SKILL,   {     22,     99,    0,    0,    0,    0,    0,    0, },   "Pass the Fork",     "Maxing trident skill"},               /* 84 */
  { TC_SKILL,   {     23,     99,    0,    0,    0,    0,    0,    0, },   "BIG axes!",         "Maxing poleaxe skill"},               /* 85 */
  { TC_SKILL,   {     24,     99,    0,    0,    0,    0,    0,    0, },   "Master Hurler",     "Maxing thrown skill"},                /* 86 */
  { TC_ITEM,    {  T_047,     10,   60,    0,    0,    0,    0,    0, },   "Exit Stage Left",   "Using 10 scrolls of the sun" },       /* 87 */
  { TC_ITEM,    {  T_500,     25,   61,    0,    0,    0,    0,    0, },   "Snake Charmer",     "Using 25 scrolls snake summoning" },  /* 88 */
  { TC_ITEM,    {  T_501,    100,   62,    0,    0,    0,    0,    0, },   "Let Them Eat Cake", "Using 100 scrolls create food" },     /* 89 */
  { TC_TROPHY,  {      0,      0,    0,    0,    0,    0,    0,    0, },   "Get a Life!!!",     "Collecting all the trophies" },       /* 90 */
  { TC_TYPE,    { O_GACH,   1000,   64,    0,    0,    0,    0,    0, },   "Gotta Gacha",       "Opening 1000 gachas" },               /* 91 */
  { TC_CARDS,   {     63, 0xffffffff,0,    0,    0,    0,    0,    0, },   "Monster Collector", "Collecting all the monster cards"},   /* 92 */
  { TC_CARDS,   {     65, 0x00001fff,0,    0,    0,    0,    0,    0, },   "Class Collector",   "Collecting all the class cards"},     /* 93 */
  { TC_CARDS,   {     66, 0x0000ffff,0,    0,    0,    0,    0,    0, },   "Weapon Collector",  "Collecting all the weapon cards"},    /* 94 */
  { TC_CARDS,   {     67, 0x000003ff,0,    0,    0,    0,    0,    0, },   "Armor Collector",   "Collecting all the armor cards"},     /* 95 */
  { TC_CARDS,   {     68, 0x0000ffff,0,    0,    0,    0,    0,    0, },   "Item Collector",    "Collecting all the item cards"},      /* 96 */
  { TC_ITEM,    {  T_638,     15,   69,    0,    0,    0,    0,    0, },   "Living Dangerously","Use a Deck of Many Things 15 times" },/* 97 */
  { TC_PICKI,   {  T_638,      1,   70,    0,    0,    0,    0,    0, },   "The Gambler",       "Acquiring a Deck of Many Things"},    /* 98 */

  {     999,    {  T_298,    100,    0,    0,    0,    0,    0,    0, },   "Be My Valentine",   "Giving 100 candy hearts to monsters"},/*    */
  };

#else

extern TROPHY_REC trophies[];

#endif

