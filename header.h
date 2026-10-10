/*
  int          cleared[10];
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#ifdef UNIX
#include <unistd.h>
#include <strings.h>
#endif
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <fcntl.h>

#ifdef WIN32
#include <windows.h>
#endif

#ifdef LINK
#undef LINK
#endif

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

#ifdef MINGW
typedef uint32_t u_int32_t;
#endif

#ifndef _BYTE_
typedef unsigned char byte;
#endif

#ifndef _WORD_
typedef unsigned short word;
#endif

#define PATH_MAX             10
#define NUM_CLASSES          13
#define NO_OF_MAPS           50
#define NO_OF_SPRITES       200
int     NO_OF_MONSTERS;
#define ARENA_SIZE_X          15
#define ARENA_SIZE_Y          15
#define MESSAGE_HEIGHT        12


/*
#define NO_OF_OBJECTS       195
#define TOTAL_OBJECTS       195
#define NO_OF_LORE           54
#define TOTAL_LORE           95
#define NO_OF_SPELLS        215
*/
#define GAME          "UNICORN"
#define VERSION        "v6.3.0"
#define RECIPE_BASE        4000
#define NPC_DIV              10

#define MAX_HALL_OF_FAME   1000
#define MAX_FINAL_SCORES  10000
#define HEAL_TIME           500

#define CF_MONK         (1 << 0)                 /*     1  must check monk_weapon() for armor and weapons levels */
#define CF_CASTER       (1 << 1)                 /*     2  Class selects a spell when character is created */
#define CF_NOBLE        (1 << 2)                 /*     4  Gains 10,000 gp per level */
#define CF_ROGUE        (1 << 3)                 /*     8  Class character becomes if they turn evil */
#define CF_CAVALIER     (1 << 4)                 /*    16  Receives cavalier pay of 1,000 gp per level per year */
#define CF_PALADIN      (1 << 5)                 /*    32  Palidin attributes, improved Heal command */
#define CF_HIER         (1 << 9)                 /*   512  Hierophant druid */
#define CF_DRUID        (1 << 10)                /*  1024  For interactions with the druidic temple */
#define CF_INITIAL      (1 << 11)                /*  2048  Available as an initial class */

#define MS_AMAGIC             (1 << 0)
#define MS_SLEEP              (1 << 1)
#define MS_POISON             (1 << 2)
#define MS_FEAR               (1 << 3)
#define MS_FRIENDLY           (1 << 4)
#define MS_APHYSICAL          (1 << 5)
#define MS_CONFUSION          (1 << 6)
#define MS_FIRE_ATK           (1 << 7)
#define MS_COLD_ATK           (1 << 8)
#define MS_RANGED             (1 << 9)
#define MS_HEALER             (1 << 10)
#define MS_BLINK              (1 << 11)
#define MS_ELEC_ATK           (1 << 12)
#define MS_ARCN_ATK           (1 << 13)
#define MS_FLY                (1 << 14)
#define MS_MOUNT              (1 << 15)
#define MS_EQUIP              (1 << 16)
#define MS_MOVED              (1 << 17)
#define MS_TALKED             (1 << 18)
#define MS_EVADE              (1 << 19)
#define MS_ROOT               (1 << 20)
#define MS_PSIONIC            (1 << 21)
#define MS_DOT                (1 << 22)
#define MS_RFIRE              (1 << 23)
#define MS_RCOLD              (1 << 24)
#define MS_RELEC              (1 << 25)
#define MS_RARCN              (1 << 26)
#define MS_IFIRE              (1 << 27)
#define MS_ICOLD              (1 << 28)
#define MS_IELEC              (1 << 29)
#define MS_IARCN              (1 << 30)
#define MS_JOIN               (1 << 31)

#define M2_REF_PHYS           (1 << 0)
#define M2_REF_MAGIC          (1 << 1)
#define M2_REF_FIRE           (1 << 2)
#define M2_REF_COLD           (1 << 3)
#define M2_REF_ELEC           (1 << 4)
#define M2_REF_ARCN           (1 << 5)
#define M2_PACIFIED           (1 << 6)
#define M2_BOSS               (1 << 7)
#define M2_CITY               (1 << 8)                 /* Can appear in cities */
#define M2_NORND              (1 << 9)                 /* Do not allow monster as random selection */
#define M2_DRAIN              (1 << 10)                /* Chance to drain level when hits */

#define MT_HUMANOID           1
#define MT_BEAST              2
#define MT_DEMON              3
#define MT_DRAGON             4
#define MT_UNDEAD             5
#define MT_ELEMENTAL          6
#define MT_GIANT              7

#define SP_BLNK               1
#define SP_PROT               2
#define SP_TCH                3
#define SP_MSSL               4
#define SP_SLEP               6
#define SP_SPCL               7
#define SP_FEAR               8
#define SP_MSL9               9
#define SP_BLND              10
#define SP_AR25              11
#define SP_DRN               12
#define SP_AR49              13
#define SP_VLA               14
#define SP_ENCH              15

#define SK_BOW                1
#define SK_1HSWORD            2
#define SK_SPEAR              3
#define SK_MACE               4
#define SK_SCOUT              5
#define SK_LANG               6
#define SK_LORE               7
#define SK_MAGIC              8
#define SK_HEAL               9
#define SK_MED               10
#define SK_RIDE              11
#define SK_BOAT              12
#define SK_ORACLE            13
#define SK_CHARM             14
#define SK_SURVIVE           15
#define SK_COMBAT            16
#define SK_DAGGER            17
#define SK_2HSWORD           18
#define SK_AXE               19
#define SK_FLAIL             20
#define SK_CROSSBOW          21
#define SK_TRIDENT           22
#define SK_POLEAXE           23
#define SK_THROWN            24


#define O_NONE                0
#define O_EDGE                1
#define O_ARMR                2
#define O_POTN                3
#define O_RING                4
#define O_STFF                5
#define O_FOOD                6
#define O_MISC                7
#define O_SCRL                8
#define O_NECK                9
#define O_ROBE               10
#define O_BOOT               11
#define O_HELM               12
#define O_SHLD               13
#define O_BOOK               14
#define O_POLE               15
#define O_BOW                16
#define O_ONCE               17
#define O_SMWP               18
#define O_JEWL               19
#define O_PROJ               20         /* projected energy weapon */
#define O_DAGR               21         /* throwable daggers */
#define O_CRFT               22         /* Crafting items */
#define O_ALCH               23         /* Alchoholic drink */
#define O_BLNT               24         /* Blunt weapons */
#define O_WAND               25         /* Wand weapons */
#define O_CONS               26         /* Miscellaneous consumables */
#define O_TRAP               27         /* Usable Traps */
#define O_HAND               28         /* Must be held in a hand to function */
#define O_THRN               29         /* Charged throwable */
#define O_CARD               30         /* Collectable Card */
#define O_GACH               31         /* Gachas */

#define C_FGHT                1
#define C_PALD                2
#define C_RANG                3
#define C_CLRC                4
#define C_DRUD                5
#define C_MAGE                6
#define C_ASSN                7
#define C_HIER                8
#define C_CVLR                9
#define C_MONK               10
#define C_NOBL               11

#define I_RHND                1
#define I_LHND                2
#define I_LSHL                3
#define I_RSHL                4
#define I_NCK1                5
#define I_NCK2                6
#define I_BLTL                7
#define I_BLTR                8
#define I_BLTF                9
#define I_BLTB               10
#define I_SHLD               11
#define I_ARMR               12
#define I_RNG1               13
#define I_RNG2               14
#define I_RNG3               15
#define I_RNG4               16
#define I_ROBE               17
#define I_BOOT               18
#define I_HELM               19

/* Object effects */
#define E_NONE                0
#define E_HEAL                1
#define E_ARMR                2
#define E_ATCK                3
#define E_FEAR                4
#define E_SLEP                5
#define E_TELE                6              /* ???? */
#define E_SPCL                7
#define E_POSN                8
#define E_BLES                9
#define E_PROT               10
#define E_INTR               11
#define E_INHT               12              /* increase to hit */
#define E_DAMG               13              /* cause damage */
#define E_ITEM               14              /* summon an item */
#define E_MANA               15              /* restore mana */
#define E_SOCK               16              /* Item can be placed in a socket */
#define E_ENCH               17              /* Enchant an item */
#define E_MUTA               18              /* Item is mutable */
#define E_LGCY               19              /* Legacy item */
#define E_TEMP               20              /* Temporarity effect, ctl=PE_, dmg=length */
#define E_WGHT               21              /* Allow for increased weight carrying */
#define E_TRAP               22              /* Settable trap */
#define E_RSPL               23              /* Random spell scroll, ct1=min spell level, ct2=max spell level */
#define E_SPEL               24              /* Specific spell scroll, ct1=spell, ct2=spell control */
#define E_LGND               25              /* Mutable legendary */

/* Socket effects */
#define S_STR               100
#define S_DEX               200
#define S_INT               300
#define S_WIS               400
#define S_CON               500
#define S_CHR               600
#define S_MAN               700
#define S_HPS               800
#define S_ATP               900
#define S_DEF              1000
#define S_HIT              1100
#define S_HPR              1200              /* HP regeneration */
#define S_MNR              1300              /* Mana regeneration */
#define S_ALL              1400              /* All base stats */
#define S_EXP              1500              /* Increase Experience Gained */
#define S_MGF              1600              /* Increase Magic Find */
#define S_MAG              1700              /* Increase Hp/Mana */
#define S_MGR              1800              /* Resistance to magic damage */
#define S_MLV              1900              /* Increase Monster Level */
#define S_CRT              2000              /* Increase critical chance */
#define S_DDG              2100              /* Increase dodge */
#define S_FIR              2200              /* Elemental fire */
#define S_CLD              2300              /* Elemental cold */
#define S_ELC              2400              /* Elemental electrical */
#define S_ARC              2500              /* Elemental arcane */
#define S_SPP              2600              /* Increase spell power */
#define S_ELE              2700              /* Resist any elemental attack, Same as A_RELE */
#define S_RPS              2800              /* Resist poison */
#define S_IPS              2900              /* Immune poison */
#define S_FCE              3000              /* S_FIR+S_CLD+S_ELC+S_ARC */
#define S_BOW              3100
#define S_1HSWORD          3200
#define S_SPEAR            3300
#define S_MACE             3400
#define S_SCOUT            3500
#define S_LANG             3600
#define S_LORE             3700
#define S_MAGIC            3800
#define S_HEAL             3900
#define S_MED              4000
#define S_RIDE             4100
#define S_BOAT             4200
#define S_ORACLE           4300
#define S_CHARM            4400
#define S_SURVIVE          4500
#define S_COMBAT           4600
#define S_DAGGER           4700
#define S_2HSWORD          4800
#define S_AXE              4900
#define S_FLAIL            5000
#define S_CROSSBOW         5100
#define S_TRIDENT          5200
#define S_POLEAXE          5300
#define S_THROWN           5400

#define S_MAX_ENCH         31                /* Highest socket effect for applying random enchants */

/* Intrinsic effects */
#define A_NOSL                1              /* No sleep */
#define A_NOPS                2              /* No poison */
#define A_RSFR                3              /* Resist Fear */
#define A_LEV                 4              /* Levitation */
#define A_SPLV                5              /* Speed and Levitation */
#define A_SRCH                6              /* Auto Search */
#define A_SPD                 7              /* speed */
#define A_HEAL                8              /* Faster hp recovery */
#define A_REFL                9              /* Reflect energy */
#define A_RFIR               10              /* Resist Fire */
#define A_RELE               11              /* Resist any elemental attack */
#define A_XRAY               12              /* xray vision */
#define A_GSEE               13              /* See inside gateway */
#define A_MANA               14              /* Reduces mana cost */
#define A_NOFR               15              /* No Fear */
#define A_TRAP               16              /* Autodetect Traps */
#define A_IDNT               17              /* Auto Identification */
#define A_CURS               18              /* Detect Curse */
#define A_NPHL               19              /* Increased hp recovery while napping */
#define A_DTFD               20              /* Autodetect food */
#define A_DTUP               21              /* Autodetect up stairs */
#define A_DTDN               22              /* Autodetect down stairs */
#define A_DEXP               23              /* Double Experience Gain */
#define A_IEXP               24              /* Increased Experience Gain */
#define A_RDLR               25              /* Read Lore */
#define A_RDLN               26              /* Read Language */
#define A_RALL               27              /* Read All */
#define A_GACT               28              /* Activate gateway */
#define A_GATE               29              /* Allow gateway to be seen */
#define A_TARD               30              /* Tardis */
#define A_COMP               31              /* Compass */
#define A_FOOD               32              /* Removes need for food */
#define A_BOAT               33              /* Travel on water */
#define A_FLY                34              /* Upland flight */
#define A_FCNG               35              /* Negate force field damage */
#define A_RCLD               36              /* Resist cold */
#define A_RELC               37              /* Resist Electric */
#define A_RDRK               38              /* Resist Dark */
#define A_RPSI               39              /* Resist Psionic */
#define A_RSSL               40              /* Resist sleep */
#define A_RSPS               41              /* Resist poison */
#define A_WATER              42              /* walk on water */
#define A_NDRN               43              /* Prevents drain level effect */
#define A_INFRA              44              /* Infravision */

#define SHOP_ALCH             1              /* Alchemist Shop */
#define SHOP_ARMR             2              /* Armour Shop */
#define SHOP_BOOK             3              /* Book Store */
#define SHOP_ROBE             4              /* Clothing Shop */
#define SHOP_JEWL             5              /* Jeweler */
#define SHOP_MAGC             6              /* Magic shops */
#define SHOP_WEAP             7              /* Weapons */
#define SHOP_FOOD             8              /* Provisions */
#define SHOP_CRFT            17              /* Crafting */
#define SHOP_SPEL            18              /* Spells */
#define SHOP_RECP            19              /* Recipes */

#define ITEM_SRATIONS         10000          /* link code for standard rations */

/* Player temporary effects */
#define PE_POISON             0              /* time player is poisoned */
#define PE_PROT               1              /* Time that player is protected */
#define PE_APROT              2
#define PE_FIRE               3              /* Time player is protected from fire */
#define PE_HASTE              4              /* Time player is hasted */
#define PE_GIANT              5              /* Time player has giant strength */
#define PE_ETHER              6              /* Time player is ethereal */
#define PE_FEAR               7              /* Time player is feared */
#define PE_SLEEP              8              /* Time player is slept */
#define PE_LIGHT              9              /* Time player has light */
#define PE_BLIND             10              /* Time player is blinded */
#define PE_CONFUSED          11              /* Time player is confused */
#define PE_READLANG          12              /* Time player can read languagees */
#define PE_READLORE          13              /* Time player can read lore */
#define PE_LEV               14              /* Time player is levitated */
#define PE_COLD              15              /* Time player has cold resistance */
#define PE_ELEC              16              /* Time player has electric resistance */
#define PE_ARCN              17              /* Time player has arcane resistance */
#define PE_ROOT              18              /* Time player is rooted */
#define PE_MIND              19              /* Time player is shielded from scionic attacks */
#define PE_DOT               20              /* Damage over time */
#define PE_HEROIC            21              /* Heroic mode */
#define PE_DEPTH             22              /* Dungeon depth */
#define PE_REBIRTH           23              /* Holds rebirth count */
#define PE_POLYMORPH         24              /* Monster polymorphed into */
#define PE_POLYTIME          25              /* Time remaining in polymorph */
#define PE_INVIS             26              /* Player cannot be seen */
#define PE_HCOUNT            29              /* Time til next healing */
#define PE_COMPASS           30              /* Compass Target */
#define PE_NOARENA           31              /* When nonzero will not make multi-monster groups */
#define PE_MCOUNT            32              /* Number of monsters that will spawn on level */
#define PE_DUNGEON           33              /* Dungeon number, used by sun stone */
#define PE_DLEVEL            34              /* Dungeon level, used by sun stone */
#define PE_WORLDSEED         35              /* World seed */

#define STAT_MOBS_KILLED       0              /* Core */
#define STAT_GOLD_LOOTED       1              /* Core */
#define STAT_STEPS_TAKEN       2              /* Core */
#define STAT_HOURS_NAPPED      3              /* Core */
#define STAT_ALCOHOL_DRANK     4              /* Core */
/*
#define STAT_SEX_CHANGE        5
*/
#define STAT_COMMONS           6              /* Core */
#define STAT_UNCOMMONS         7              /* Core */
#define STAT_RARES             8              /* Core */
#define STAT_VERY_RARES        9              /* Core */
#define STAT_ULTRA_RARES      10              /* Core */
#define STAT_LEVELS_CLEARED   11              /* Core */
#define STAT_DUNGEON_CLEARED  12              /* Core */
#define STAT_ITEMS_CRAFTED    14              /* Core */
#define STAT_SOCKETS_ADDED    15              /* Core */
#define STAT_ENCHANTMENTS     16              /* Core */
#define STAT_DRAGONS          17              /* Core */
#define STAT_SCROLLS_READ     18              /* Core */
#define STAT_POTIONS_DRUNK    19              /* Core */
#define STAT_MEALS_EATEN      20              /* Core */
/*
#define STAT_ROCK_HOUND       21
*/
#define STAT_ARROWS_FIRED     22              /* Core */
/*
#define STAT_EGGS_FOUND       23
#define STAT_MEAT_EATEN       24
#define STAT_POTATOS_EATEN    25
#define STAT_APPLEUP_EATEN    26
*/
#define STAT_POISONED         27              /* Core */
#define STAT_DAMAGE           28              /* Core */
#define STAT_HARDEST_HIT      29              /* Core */
#define STAT_DAMAGE_TAKEN     30              /* Core */
#define STAT_HARDEST_TAKEN    31              /* Core */
#define STAT_ITEMS_SOLD       32              /* Core */
#define STAT_SOLD_GOLD        33              /* Core */
#define STAT_LARGEST_SALE     34              /* Core */
#define STAT_INTEREST         35              /* Core */
#define STAT_CONVERSATIONS    36              /* Core */
#define STAT_ITEMS_IDENTED    37              /* Core */
#define STAT_CLASSES_TAKEN    38              /* Core */
#define STAT_HARD_MOB         39              /* Core */
/*
#define STAT_BSTONE_RINGS     40
#define STAT_GREEN_BEERS      41
#define STAT_CORNED_BEEF      42
#define STAT_BRIDE            43
#define STAT_GROOM            44
#define STAT_CHARMS           45
#define STAT_FIREWORKS        46
#define STAT_CANDY            47
#define STAT_COSTUMES         48
#define STAT_TURKEY_DINNERS   49
#define STAT_PRESENTS_OPENED  50
#define STAT_SANTA            51
#define STAT_MISTLETOE        52
#define STAT_CANDY_HEARTS     53
#define STAT_CLOVERS          57
*/
#define STAT_HITS             54
#define STAT_MISSES           55
#define STAT_CRITS            56
/*
#define STAT_FIGURINES_USED   58
#define STAT_BANDAGES_USED    59
#define STAT_SUN_SCROLLS_USED 60
#define STAT_SNAKE_SCROLLS    61
#define STAT_FOOD_SCROLLS     62
#define STAT_MONSTER_CARDS    63
#define STAT_GACHA            64
#define STAT_CLASS_CARDS      65
#define STAT_WEAPON_CARDS     66
#define STAT_ARMOR_CARDS      67
#define STAT_ITEM_CARDS       68
#define STAT_USE_DECK         69
#define STAT_GET_DECK         70
*/

#define M_NONE                 0
#define M_MAGIC                1
#define M_BOW                  2
#define M_PHYSICAL             3

#define CLR_BLACK              0
#define CLR_BLUE               1
#define CLR_GREEN              2
#define CLR_CYAN               3
#define CLR_RED                4
#define CLR_PURPLE             5
#define CLR_BROWN              6
#define CLR_GRAY               7
#define CLR_DARKGRAY           8
#define CLR_LIGHTBLUE          9
#define CLR_LIGHTGREEN        10
#define CLR_LIGHTCYAN         11
#define CLR_LIGHTRED          12
#define CLR_LIGHTPURPLE       13
#define CLR_YELLOW            14
#define CLR_WHITE             15

typedef char OUTSTRING[32];
typedef char STRING32[32];
typedef char STRING13[13];
typedef char STRING128[128];
typedef char MSTRING[128];
typedef int  MAP_TYPE[101][101];
typedef byte KNOW_TYPE[101][101];
typedef int  SPELLBOOK[1000];

typedef struct {
  int    item;
  int    percent;
  } HUNTING_ITEMS;

typedef struct {
  int    class;
  int    level;
  int    trait;
  } TRAITS;

typedef struct {
  char* name;
  int   stat_adjust[6];
  int    fixed_skill[4];
  int    fixed_skill_range[4];
  int    flags;
  int    aging;
  } RACE_REC;

typedef struct {
  char*  name;
  int    stat_adjust[6];
  double first_exp;
  double next_exp;
  int    initial_inv_slot[4];
  int    initial_inv_item[4];
  int    hitdie;
  int    mana;
  int    becomes_caster;
  int    random_skill[3];
  int    random_skill_range;
  int    fixed_skill[4];
  int    fixed_skill_range[4];
  int    flags;
  int    skill_table;
  int    level_skills[4];
  int    spell_group;
  int    hp_regen;
  int    weapon_affinity;
  } CLASS_REC;

typedef struct {
  int    from;
  int    level;
  int    to;
  } CLASS_CHANGE_REC;

typedef struct {
  int    class;
  int    level;
  char*  male;
  char*  female;
  } TITLE_REC;

typedef struct {
  int32_t counts[255];
  int  trophies[255];
  int  num_trophies;
  } STATS_REC;

typedef struct {
  char version[3];
  } SCORE_VER;

typedef struct {
  char version[3];
  char legend_name[12+1][33];
  char legend_title[12+1][33];
  double legend_exp[12+1];
  char legend_mode[12+1];
  char high_name[12+1][33];
  char high_title[12+1][33];
  double high_exp[12+1];
  char high_mode[12+1];
  } SCORE_REC_600;

typedef struct {
  char name[33];
  char title[33];
  double exp;
  char mode;
  } SCORE_RECORD;

typedef struct {
  char   name[33];
  double exp;
  int    level;
  char   cause;
  byte   class;
  int32_t   time_played;
  char   mode;
  } SCORE_ENTRY;

typedef struct {
  char*  name;
  char*  title;
  double exp;
  } DEFAULT_SCORE_REC;

typedef struct {
  int  link;
  byte region;
  char message[256];
  } MESSAGE;

typedef struct {
  int  shoptype;
  int  region;
  int  rx;
  int  ry;
  int  cx;
  int  cy;
  char name[40];
  } SHOP_REC;

typedef struct {
  int region;
  int x;
  int y;
  int level;
  int map;
  } PREDEF_MAP;

typedef struct {
  int quest;
  int message;
  } COMPASS;

typedef struct {
  int map;
  int x;
  int y;
  } TR_SHIP_REC;

typedef struct {
  int  quest;
  int  region;
  int  x;
  int  y;
  int  typ;
  int  diff;
  char name[33];
  int  treasure;
  int  premium;
  int  sx;
  int  sy;
  int  boss;
  int  adds;
  int  numadds;
  } LINK_REC;

typedef struct {
  char  name[33];
  } REGION_REC;

typedef struct {
  int    speed;
  int    number;
  int    hp;
  int    max_hp;
  int    mana;
  int    level;
  int    attack;
  int    defense;
  double exp;
  double exp_hp;
  unsigned int    special;
  unsigned int    special2;
  int    sprite;
  int    mtype;
  char   name[16];
  int    time;
  int    sleep;         /* -sleep is rooted, +sleep is sleeping */
  int    fear;
  int    blind;
  int    confused;
  int    poison;
  int    prev;
  int    treasure;
  } NPC_REC;

typedef struct {       /* this is used for setting character stats with transformations */
  int    number;
  int    strength;
  int    dexterity;
  int    intelligence;
  int    wisdom;
  int    constitution;
  int    charisma;
  } NPC_STATS;

typedef struct {
  int  link;
  int  otype;
  int  user_hp;
  int  user_health;
  byte effect;
  int  control;
  int  control2;
  byte weight;
  double cost;
  int    level;
  int    damage;
  int    sprite;
  int    rarity;
  int    plus;
  int    charges;
  double costp;
  int    align;
  int    skill;                  /* controlling skill */
  int    min_skill;              /* minimum skill to use */
  char name[60];
  int    num_enchantments;
  int    enchantments[3];
  int    num_sockets;
  int    sockets[3];
  } OBJECT_REC;

typedef struct {
  char  main_hand[60];
  char  off_hand[60];
  char  neck_1[60];
  char  neck_2[60];
  char  shield[60];
  char  armor[60];
  char  ring_l1[60];
  char  ring_l2[60];
  char  ring_r1[60];
  char  ring_r2[60];
  char  cloak[60];
  char  boots[60];
  char  helm[60];
  } GEAR_SET;

typedef GEAR_SET GEAR_MANAGER[10];

typedef struct {
  int object;
  int craft_item;
  int object1;
  int object2;
  int object3;
  int object4;
  int object5;
  int object6;
  int object7;
  int object8;
  int object9;
  int object10;
  } RECIPE;

typedef struct {
  byte user_hp;
  byte user_health;
  int  effect;
  int  control;
  byte allign;
  int number;
  byte level;
  byte mana;
  unsigned int  special;
  byte for_sale;
  char name[26];
  } SPELL_REC;

typedef struct {
  int        region;
  int        rx;
  int        ry;
  int        cx;
  int        cy;
  double     mortgage;
  double     payment;
  double     interest;
  OBJECT_REC inventory[500];
  } HOUSE;

typedef struct {
  int        region;
  int        rx;
  int        ry;
  int        cx;
  int        cy;
  double     price;
  } FORSALE;

typedef struct {
  int        citynum;
  int        region;
  int        rx;
  int        ry;
  } CITY_NUMBER;

typedef NPC_REC DUNGEON_MONSTERS[6][61];
typedef OBJECT_REC DUNGEON_OBJECTS[1000];

typedef struct {
  MAP_TYPE         map;
  KNOW_TYPE        known;
  DUNGEON_MONSTERS monsters;
  DUNGEON_OBJECTS  objects;
  int              upx;
  int              upy;
  int              downx;
  int              downy;
  int              cleared;
  } DUNGEON_LEVEL;

typedef struct {
  int          num_levels;
  int          dungeon_number;
  DUNGEON_LEVEL level[10];
  int          treasurex;
  int          treasurey;
  } DUNGEON;

typedef struct {
  char      name[21];
  byte      age;
  char      sex;
  word      level;
  double    exp;
  double    exp_next;
  byte      class;
  char      title[26];
  byte      race;
  int       stat[7];
  int       mhp;
  int       chp;
  byte      health;
  int       mmana;
  int       cmana;
  int       ability[11];
  int       x;
  int       y;
  int       map_x;
  int       map_y;
  MAP_TYPE  map;
  KNOW_TYPE known;
  int       region;
  int       skill[31];
  int       torch;
  int       food;
  int       armour;
  int       weapon;
  int       mount;
  int       peg;
  int32_t      gold_coins;
  int32_t      mithril_coins;
  int32_t      adamantite_coins;
  int32_t      bank;
  int32_t      interest;
  byte      d_level;
  byte      diff;
  byte      land_x;
  byte      land_y;
  char      d_name[31];
  byte      day;
  byte      month;
  byte      min;
  byte      hour;
  OBJECT_REC invent[20];
  OBJECT_REC pack[33];
  byte      potion[9];
  byte      ring[9];
  byte      staff[13];
  int       effect[255];
  DUNGEON_MONSTERS monster;
/*  NPC_REC   monster[6][61]; */
  NPC_REC   party[6];
  int       align;
  char      in_city;
  byte      city;
  int       hp_count;
  int       mana_count;
  byte      xxxxx[256];
  int       phase;
  byte      gen[5000];
  byte      lore[5000];
  OBJECT_REC pawn[10][11];
  STRING32  fspell[11];
  int       ship_x;
  int       ship_y;
  int       ship_r;
  char      inship;
  char      gateway;
  byte      tardis_x[11];
  byte      tardis_y[11];
  byte      tardis_r[11];
  STRING32  tardis_d[11];
  char      cav_paid;
  DUNGEON_OBJECTS map_objects;
/*  OBJECT_REC map_objects[1000]; */
  OBJECT_REC hole[1000];
  HOUSE      houses[5];
  int        dungeon_number;
  char       quests[1000];
  int32_t       time_played;
  } PLAYER_REC;

LINK PLAYER_REC         player;

#include "spells.h"
#include "world.h"
#include "lore.h"
#include "gen.h"
#include "objects.h"
#include "monsters.h"
#include "maps.h"
#include "recipe.h"
#include "races.h"
#include "classes.h"
#include "trophies.h"


/* LINK char**             sprite[255]; */
LINK DUNGEON            current_dungeon;
LINK GEAR_MANAGER       gear_manager;
LINK SPELLBOOK          spellbook;
LINK int                a_mon;
LINK char               soundon;
LINK int                bottom;
LINK int                word_counter;
LINK char               clair;
LINK int                snakes;
LINK int                inv_item;
LINK char               napping;
LINK int                exitf;
LINK byte               dc;
LINK char               combat_mode;
LINK int                mod_exit;
LINK byte               score1;
LINK byte               score2;
LINK char              exit_flag;
LINK char               restock;
LINK char               loadname[80];
LINK char               backupname[80];
LINK char               graphics;
LINK char               messages[60][80];
LINK int                msg_clr[60];
LINK STATS_REC          stats;
LINK int                recipe_start;
LINK int                heroicMode;
LINK char               in_arena;
LINK byte               pixel;
LINK OBJECT_REC         shop_items[1000];
LINK int                n_shop_items;
LINK char               wizardmode;
LINK int                NO_OF_OBJECTS;
LINK int                TOTAL_OBJECTS;
LINK int                NO_OF_GENS;
LINK int                NO_OF_LORE;
LINK int                recipe_count;
LINK int                num_spells;
LINK SCORE_ENTRY        hall_of_fame[MAX_HALL_OF_FAME];
LINK SCORE_ENTRY        final_scores[MAX_FINAL_SCORES];
LINK SCORE_REC_600      scores_600;
LINK SCORE_VER          score_version;
LINK SCORE_RECORD       high_scores[NUM_CLASSES];
LINK SCORE_RECORD       legend_scores[NUM_CLASSES];
LINK int                num_hall_of_fame;
LINK int                num_final_scores;
LINK char               debugMSG[256];
LINK int                hall_position;
LINK int                death_position;
LINK char               no_color;
LINK int                target_x;
LINK int                target_y;
LINK double             dir_x;
LINK double             dir_y;
LINK int                currentFloor;
LINK int                lastFloor;
LINK int                offset_x,offset_y;
LINK int                trophy_count;
LINK int32_t               start_time;
LINK int32_t               end_time;
LINK struct tm          date;
LINK int                score_position;
LINK int                path_x[PATH_MAX];
LINK int                path_y[PATH_MAX];
LINK int                best_path;
LINK int                dungeon_floor;
LINK int                dungeon_wall;
LINK OBJECT_REC         in_air;
LINK char               buffer[64];
LINK char               debugbuffer[255];
LINK char               skipcheck;
LINK char               in_upland;
LINK char               show_keys;
LINK OBJECT_REC*        item_to_use;
LINK char               auto_pickup_gold;
LINK char               auto_pickup_torch;
LINK char               auto_open_doors;
LINK char               auto_bump_walls;
LINK int                drop_x;
LINK int                drop_y;
LINK char               use_from_ground;
LINK char               no_arena;
LINK int                downgrade_depth;
LINK char               downgrade_arena;
LINK int                run_x;
LINK int                run_y;
LINK char               dungeon_scaling;
LINK int                monster_count;
LINK char               party_combat_mode;
LINK int                delay_ranged;
LINK int                delay_hit;
LINK int                delay_trap;
LINK int                last_target_x;
LINK int                last_target_y;
LINK char               used_sunstone;
LINK int                col;
LINK int                row;
LINK char               auto_target;
LINK int                levelCleared;
LINK int                screen_width;
LINK int                screen_height;
LINK int                TEXT_GRID_WIDTH;
LINK int                TEXT_GRID_HEIGHT;
LINK int                smap_offset_x;
LINK int                smap_offset_y;
LINK int                tile_width;
LINK int                tile_height;
LINK int                TILES_X;
LINK int                TILES_Y;
LINK int                NUM_MSG;
LINK int                text_offset_x;
LINK int                text_offset_y;
LINK int                showStats;
LINK char               fkey_mode;
LINK char               macros[10][1024];
LINK char               currentMacro[1024];


#ifdef DEBUG
LINK int                debug_tab;
#endif


/* advance.c */
extern void advancement();
extern void advance_stat();
extern void skills1();
extern void skills2();
extern void skills3();
extern void skills4();
extern void skills5();
extern void skills6();
extern void skills7();

/* cave.c */
extern void cave();

/* combat.c */
extern void arena(int monster,int floor,int barriers,int srcx,int srcy);

/* help.c */
extern void combat_help();
extern void dungeon_help();
extern void show_icons();
extern void upland_help();

/* mapmaint.c */
extern void arena_move_enemy(int x,int y);
extern void arena_move_party(int x,int y);
extern void make_map(char dir);
extern void move_enemy(int x,int y);
extern void move_snake(int x,int y,int floor);
extern void stock_monsters(int depth,int treasurex,int treasurey,MAP_TYPE* map,DUNGEON_MONSTERS* monsters);
extern void stock_town(byte town);
extern void stock_treasure();

/* shops.c */
extern void dragon_dice();
extern void gamble();
extern int haggle(double price,OBJECT_REC item);
extern void cavalier(char* name);
extern void library(char* name);
extern void mounts(char* name);
extern void non_magic_weapons(char* name);
extern void pawn(char* name, byte city);
extern void provisions(char* name);
extern void school(char* name);
extern void tavern(char* name);
extern void temple(char* name);
extern void travel(char* name);
extern void bank(char* name);

/* specials.c */
extern void display_scroll();
extern void perform_effect(OBJECT_REC* obj);
extern void special(int whichone,OBJECT_REC* item);
extern void special8();
extern void special9();
extern void special14();
extern void special22();
extern void special31(int max);
extern void special43();
extern void special53();
extern void special55();
extern void special61();
extern void special62();
extern void special63();
extern void special68();
extern void special69();
extern void special70();
extern void special71();
extern void special77();
extern void special80();
extern void special81();

/* terminal.c */
extern void bar(int x1,int y1,int x2,int y2);
extern void clrscr();
extern void delay(int time);
extern void draw(int x1,int y1,int x2,int y2,int clr);
extern void gotoxy(int x,int y);
extern void graphmode();
extern void init_graph();
extern int keypressed();
extern void outtextxy(int x,int y,char* buffer);
extern void outtextxyclr(int x,int y,char* buffer);
extern void outtext_xy(int x,int y,char* buffer);
extern void putimage(int x,int y,char** img,int typ);
extern void putpixel(int x,int y,int clr);
extern int readkey();
extern void readln(char* buffer);
extern int p_read(char* buffer);
extern void restoreScreen();
extern void saveScreen();
extern void setcolor(int clr);
extern void setfillstyle(int st,int clr);
extern void settextstyle(int a,int b,int c);
extern void textmode(int mode);
extern void textcolor(int color);
extern void txt_write(char* buffer);
extern void txt_writeln(char* buffer);
extern int restoreTerm();
extern void open_display();
extern void close_display();
extern void plot(int x,int y,int clr);
extern void flush();

/* uchar.c */
extern char* fix_name(STRING32 name);
extern char* fix_ability(int ability);
extern char* get_sex();
extern char* get_race();
extern char* get_class();
extern char* get_health();
extern char* get_align();
extern char* yes_no(int input);
extern char* show_health();
extern char* show_align();
extern char* show_int(int n);
extern char* show_flt(double n);
extern void disp_char();
extern void make_char(int rebirth);
extern void print_rec();

/* uinvent.c */
extern char* get_name(OBJECT_REC* item);
extern OBJECT_REC* inventory(OBJECT_REC* item);
extern char inv_valid(OBJECT_REC* item,int line);
extern void show_inventory(OBJECT_REC* item);
extern void compress();
extern void show_lore(int item);
extern OBJECT_REC* unpack(int slot);
extern void do_exchange(OBJECT_REC* item,int line);
extern void pack_item(OBJECT_REC* item,int line);


/* upland.c */
extern void up_land();
extern void stock_encounter();
extern void check_encounter();
extern void take_time();

/* usprites.c */
extern void show_sprite(int x,int y,int sprt);
extern void read_sprites();
extern char** select_sprite(int n);

/* uspells.c */
extern byte has_spell(int check);
extern int check_spell_1(char* spell_name,int level,int allign,int first);
extern int get_spell_name(int column,int search,int level,int allign);
extern int castspell(int spell_num);
extern void new_spell();

/* unisubs.c */
extern void upper(char* buffer);
extern void check_monk_weapon();
extern void check_noble();
extern void check_scores();
extern void copyMap(MAP_TYPE* dest,int num);
extern void decode(char* buffer);
extern void winner();
extern int exist(char* filename);
extern int find_gen(char* search);
extern int find_lore(char* search);
extern char inkey();
extern void load();
extern void load57();
extern void make_c();
extern void make_h();
extern void make_n();
extern char* make_str(int value);
extern int mana_cost(int mana);
extern int mval(STRING13 instr);
extern double needed(int x);
extern void new_pawn();
extern byte reverseByte(byte in);
extern void save();
extern void show_number();
extern void save_scores();
extern void load_scores();
extern void show_scores();
extern void show_final_scores();
extern void final_score(char cause);
extern int sqr(int n);
extern void teleport();
extern int rcs_trunc(double x);
extern int u_random(int range);
extern void u_randomize();

/* unisubs2.c */
extern void adjust_abilities();
extern void area9(int damage,int elem,int center_x,int center_y);
extern void area25(int damage,int elem,int center_x,int center_y);
extern void area49(int damage,int elem,int center_x,int center_y);
extern void blind();
extern void clear_prompt();
extern void display_abilities();
extern void do_blink();
extern void do_sleep();
extern void drain(int damage,int elem);
extern void fear(int radius);
extern char get_dir(int* xdir,int* ydir);
extern char in_sight(int x,int y);
extern void missile(int damage,int elem,int radius);
extern void noise(int f,int d);
extern void prompt(char* display);
extern void promptNS(char* display);
extern void r_missile(int damage);
extern void remove_land_player();
extern void remove_player();
extern void show_headings();
extern void show_land();
extern void show_land_player();
extern void show_map();
extern void show_player();
extern void show_screen();
extern void show_side();
extern void show_sm_land();
extern void show_sm_map();
extern void show_spot(int x,int y);
extern void title();
extern void touch(int damage,int elem);

/* unisubs3.c */
extern void close_door();
extern void dart_trap();
extern void fire_trap();
extern void discover();
extern void enemy_missile(int ex,int ey);
extern void fire(int damage,OBJECT_REC* weapon);
extern void go_bottom();
extern void go_down();
extern void go_ship();
extern void go_up();
extern void healing();
extern void lock_door();
extern void nap();
extern void open_door();
extern void pack_it(int floor);
extern void party();
extern void poison_trap();
extern void say_word();
extern void show_log();
extern void sleep_trap();
extern void super(int damage,int elem);
extern void teleport_trap();
extern void view(int floor);

/* writefont.c */
extern void write_font(int x,int y,int color,char* line);

extern int check_intrinsic(OBJECT_REC obj,int intr);
extern int find_item_slot();
extern int has_intrinsic(int intr);
extern int intrinsic_count(int intr);
extern void get_shop_items(int otype1,int otype2,int otype3,int otype4,int otype5,int otyp6,int rarity);
extern double item_cost(OBJECT_REC* item);
extern void shop(char* name,int shop_type);
extern int place_object(int level);
extern OBJECT_REC* find_linked_item(int lnk);
extern void dead_monster(NPC_REC* mon,char tr,int x,int y);
extern void show_messages();
extern void msg(char* message,int color);
extern void crafting();
extern void wizard();
extern void show_gen(int item);
extern void show_message(char* message);
extern void buy_house(int hnum);
extern void new_month();
extern void auto_detect();
extern void house_inventory(int hnum);
extern void gain_exp(double amt,int who);
extern void show_quest();
extern void new_game();
extern void convert_time(int32_t t,char* buffer);
extern void debugLog(char* msg);
extern void show_stats();

extern void check_trophies();
extern void show_trophies();

extern void recipe_string(int num,char* buffer);

/* charattributes.c */
extern int get_base_str();
extern int get_base_dex();
extern int get_base_con();
extern int get_base_int();
extern int get_base_wis();
extern int get_base_chr();
extern int get_base_mmana();
extern int get_base_mhp();
extern int get_base_weapon();
extern int get_base_armour();
extern int get_str();
extern int get_dex();
extern int get_con();
extern int get_int();
extern int get_wis();
extern int get_chr();
extern int get_mmana();
extern int get_mhp();
extern int get_weapon();
extern int get_armour();
extern int get_hpr();
extern int get_manar();
extern int get_hit();
extern double get_exp_multiplier();
extern int get_magic_find();
extern double get_magic_resistance();
extern int get_monster_level_plus();
extern int get_crit();

extern void stats_do_damage(int dam);
extern void stats_take_damage(int dam);
extern void scale_monster(NPC_REC* monster, int scale);
extern void charmmonster();
extern void set_title();
extern void make_assassin();
extern int check_class_change(int class);

extern void data_card(OBJECT_REC* it);
extern char* base_name(char* buffer,OBJECT_REC* item);

extern int get_skill(int num);
extern void add_skill(int skill,int num);
extern void show_gain(int g);
extern int get_bonus(int typ);
extern void fire_wand(int damage);
extern void enchant(int ench,int limit);
extern void show_legends();
extern void mutable(OBJECT_REC* it);
extern void itemColor(OBJECT_REC* item);
extern int passable(int x,int y,char monstPass);
extern int los(int x1,int y1,int x2,int y2,char monstPass);
extern void activate(int x,int y);
extern char adjust_map();
extern int compass(int suggest);
extern void level_legacy(OBJECT_REC* item);
extern int mutable_enchant();
extern void check_level_legacy();
extern void player_attack_defense();
extern int max_damage(OBJECT_REC* weapon,NPC_REC* target,int base);
extern int has_socket(int intr);
extern int figure_damage(int damage,int elem,NPC_REC* monster);
extern int get_weight();
extern int get_max_weight();
extern void blind_trap();
extern void root_trap();
extern void multiply_monster(NPC_REC* monster, int scale);
extern int can_see();
extern void target(int sprt,int stop_st_target,int show_path);
extern int find_path(int start_x,int start_y,int end_x,int end_y,int count);
extern char fear_dir(int start_x,int start_y,int end_x,int end_y);
extern int set_trap(int n);
extern void arena_party_heal(int healer);
extern void trigger_trap(int x,int y,int trap_type);
extern NPC_REC* get_monster(int x,int y);
extern void do_heal(int amount,int who);
extern int is_weapon(OBJECT_REC* item);
extern int meleehit(int who,OBJECT_REC* weapon,int dmg,NPC_REC* target,char hand);
extern OBJECT_REC* get_item(int x,int y);
extern void thrown_potion(OBJECT_REC* item,int x,int y);
extern void aoe(int cx,int cy,int effect,int control,int damage,int element,int range,int mtype,int toHit);
extern void use_item();
extern char valid_move(int x,int y);
extern void fire_weapon();
extern void do_get();
extern void throw(char hnd);
extern void cast_spell(int number);
extern int get_spell_power();
extern int get_attack_power();
extern char* effect(int e,int c,char* buffer);
extern void get_attribute_name(char* buffer,int ench);
extern int has_trophy(int num);
extern int get_dodge();
extern void show_f_keys();
extern void get_shop_spells(int level);
extern void show_spell(int num,int ox,int oy,int line);
extern void transcribe();
extern void mutable_set_name(OBJECT_REC* it);
extern int32_t get_gold();
extern int32_t get_coins();
extern void add_gold(int32_t g);
extern void sub_gold(int32_t g);
extern int can_be_seen();
extern void enemy_hit(int x,int y);
extern void mutable_legendary(OBJECT_REC* item);
extern int get_dungeon(int n);
extern int get_linked_msg(int n);
extern void use_compass();
extern int get_linked_monster(int n);
extern void mapgen_old(int floor);
extern void mapgen(int depth,int floor,int* treasurex,int* treasurey,
                   int *upx, int *upy, int *downx, int *downy,
                   MAP_TYPE* map,KNOW_TYPE* known);
extern int damage_reduction(int n);
extern int magic_adjust(int n);
extern void check_mount();
extern int reduce_damage(int damage,int element);
extern int get_city();
extern double buy_price(double price);
extern int triad_equipped();
extern int fighting_final_boss(NPC_REC* mon);
extern int offhand_weapon();
extern void show_time();
extern void process_config(char* name);
extern int process_option(char* pChar);
extern int can_drop(int destx,int desty,char check_inair);
extern int in_room(int x,int y);
extern void light_room();
extern void char_sheet_labels(char showall);
extern void char_sheet_data();
extern void show_skills();
extern void check_autos();
extern void Rcs_Seed(u_int32_t s);
extern void Shift(int count);
extern int Rcs_Random(int range);
extern void build_dungeon(int floor,int dn);
extern void save_level();
extern void load_level();
extern void save_gear(char weapons_only,int slot);
extern void load_gear(char weapons_only,int slot);
extern char item_dir(int item);
extern void help_item(char* msg,int col_width,int num_rows,int indent);
extern void convert_recipe(OBJECT_REC* item);
extern void sort_shop_items();
extern void get_shop_recipes();
extern int check_level_cleared();
extern void pit_trap();
extern void miniMap();
extern void fkey_pressed(int n);
extern void shift_fkey_pressed(int n);
extern void alt_fkey_pressed(int n);
extern void ctrl_fkey_pressed(int n);
extern int unbuffer();

#ifdef ANNIV
extern unsigned short crc(unsigned char *s, int len, unsigned short crcval);
#endif

