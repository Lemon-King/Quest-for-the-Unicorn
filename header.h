#include <stdio.h>
#include <stdlib.h>
#ifdef UNIX
#include <unistd.h>
#include <strings.h>
#endif
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "librcs.h"

#ifdef LINK
#undef LINK
#endif

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

#ifndef _BYTE_
typedef unsigned char byte;
#endif

#ifndef _WORD_
typedef unsigned short word;
#endif

#define NO_OF_MAPS           17
#define NO_OF_SPRITES       200
#define NO_OF_MONSTERS      162
#define NUM_MSG               10
/*
#define NO_OF_OBJECTS       195
#define TOTAL_OBJECTS       195
#define NO_OF_LORE           54
#define TOTAL_LORE           95
*/
#define NO_OF_SPELLS        140
#define GAME          "UNICORN"
#define VERSION        "v5.2.1"

#define O_NONE                0
#define O_EDGE                1
#define O_ARMR                2
#define O_POTN                3
#define O_RING                4
#define O_WAND                5
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

#define I_LHND                1
#define I_RHND                2
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

#define SHOP_ALCH             1              /* Alchemist Shop */
#define SHOP_ARMR             2              /* Armour Shop */
#define SHOP_BOOK             3              /* Book Store */
#define SHOP_ROBE             4              /* Clothing Shop */
#define SHOP_JEWL             5              /* Jeweler */
#define SHOP_MAGC             6              /* Magic shops */
#define SHOP_WEAP             7              /* Weapons */
#define SHOP_FOOD             8              /* Provisions */

#define ITEM_SRATIONS         10000          /* link code for standard rations */

#define PE_POISON             0
#define PE_PROT               1
#define PE_APROT              2
#define PE_FIRE               3
#define PE_HASTE              4
#define PE_GIANT              5
#define PE_ETHER              6
#define PE_FEAR               7
#define PE_SLEEP              8
#define PE_LIGHT              9
#define PE_BLIND             10
#define PE_CONFUSED          11
#define PE_READLANG          12
#define PE_READLORE          13
#define PE_LEV               14

typedef char OUTSTRING[32];
typedef char STRING32[32];
typedef char STRING13[13];
typedef char STRING128[128];
typedef char MSTRING[128];
typedef int  MAP_TYPE[101][101];
typedef byte KNOW_TYPE[101][101];

typedef struct {
  char legend_name[12][33];
  char legend_title[12][33];
  double legend_exp[12];
  char high_name[12][33];
  char high_title[12][33];
  double high_exp[12];
  } SCORE_REC;

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
  } LINK_REC;

typedef struct {
  char  name[33];
  } REGION_REC;

typedef struct {
  int    speed;
  int    number;
  int    hp;
  int    mana;
  byte   level;
  byte   attack;
  byte   defense;
  double exp;
  double exp_hp;
  byte   special;
  int    sprite;
  char   name[16];
  byte   time;
  int    sleep;
  int    fear;
  int    blind;
  int    confused;
  int    poison;
  int    prev;
  int    treasure;
  } NPC_REC;

typedef struct {
  int  link;
  int  otype;
  int  user_hp;
  int  user_health;
  byte effect;
  int  control;
  byte align;
  byte weight;
  double cost;
  int    level;
  int    damage;
  int    sprite;
  int    rarity;
  int    plus;
  int    charges;
  double costp;
  char name[33];
  } OBJECT_REC;

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
  byte effect;
  int  control;
  byte allign;
  byte number;
  byte level;
  byte mana;
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
  int       skill[17];
  int       torch;
  int       food;
  int       armour;
  int       weapon;
  int       mount;
  int       peg;
  double    gold;
  double    bank;
  double    interest;
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
/*
  int       poison;
  int       prot;
  int       aprot;
  int       fire;
  int       haste;
  int       giant;
  int       ether;
  int       fear;
  int       sleep;
  int       light;
  int       blind;
  int       confused;
  int       read_lang;
  int       read_lore;
*/
  byte      oknow[1000];
  NPC_REC   monster[6][61];
  NPC_REC   party[6];
  int       align;
  char      in_city;
  byte      city;
  int       hp_count;
  int       mana_count;
  byte      spell[56];
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
  OBJECT_REC map_objects[1000];
  OBJECT_REC hole[1000];
  HOUSE      houses[5];
  int        dungeon_number;
  char       quests[1000];
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

LINK rcs_Display*       display;
LINK rcs_Window         window;
LINK rcs_Pixmap         screen;
LINK rcs_Pixmap         screenSave;


LINK char**             sprite[255];
LINK int                a_mon;
LINK char               soundon;
LINK int                h_count;
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
LINK char               graphics;
LINK char               messages[NUM_MSG][80];
LINK int                msg_clr[NUM_MSG];

LINK char               in_arena;
LINK byte               pixel;
LINK OBJECT_REC         shop_items[100];
LINK byte               n_shop_items;
LINK char               wizardmode;

LINK int                NO_OF_OBJECTS;
LINK int                TOTAL_OBJECTS;
LINK int                NO_OF_GENS;
LINK int                NO_OF_LORE;

LINK rcs_GC             colors[16];

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
extern void arena(int monster,int floor);

/* help.c */
extern void combat_help();
extern void dungeon_help();
extern void show_icons();
extern void upland_help();

/* mapmaint.c */
extern void arena_move_enemy(int x,int y);
extern void arena_move_party(int x,int y);
extern void make_map();
extern void move_enemy(int x,int y);
extern void move_snake(int x,int y,int floor);
extern void stock_monsters();
extern void stock_town(byte town);
extern void stock_treasure();

/* shops.c */
extern void dragon_dice();
extern void gamble();
extern void haggle(double price,OBJECT_REC item);
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
extern void special(byte whichone);

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
extern void putimage(int x,int y,char** img,int typ);
extern void putpixel(int x,int y,int clr);
extern int readkey();
extern void readln(char* buffer);
extern void p_read(char* buffer);
extern void restoreScreen();
extern void saveScreen();
extern void setcolor(int clr);
extern void setfillstyle(int st,int clr);
extern void settextstyle(int a,int b,int c);
extern void textmode(int mode);
extern void textcolor(int color);
extern void txt_write(char* buffer);
extern void txt_writeln(char* buffer);

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
extern void make_char();
extern void print_rec();

/* uinvent.c */
extern char* get_name(OBJECT_REC* item);
extern OBJECT_REC* inventory(OBJECT_REC* item);
extern char inv_valid(OBJECT_REC* item,int line);
extern void show_inventory(OBJECT_REC* item);
extern void compress();
extern void show_lore(int item);
extern OBJECT_REC* unpack();
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
extern void eshter();
extern int exist(char* filename);
extern int find_gen(char* search);
extern int find_lore(char* search);
extern char inkey();
extern void load(char* filename);
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
extern void show_scores();
extern int sqr(int n);
extern void teleport();
extern int trunc(double x);
extern int u_random(int range);
extern void u_randomize();

/* unisubs2.c */
extern void adjust_abilities();
extern void area9(int damage);
extern void area25(int damage);
extern void blind();
extern void clear_prompt();
extern void display_abilities();
extern void do_blink();
extern void do_sleep();
extern void drain(int damage);
extern void fear();
extern char get_dir(int* xdir,int* ydir);
extern char in_sight(int x,int y);
extern void missile(int damage);
extern void missile9(int damage);
extern void noise(int f,int d);
extern void prompt(char* display);
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
extern void touch(int damage);

/* unisubs3.c */
extern void area49(int damage);
extern void close_door();
extern void dart_trap();
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
extern void super(int damage);
extern void teleport_trap();
extern void view(int floor);

/* writefont.c */
extern void write_font(int x,int y,int color,char* line);

extern int check_intrinsic(OBJECT_REC obj,int intr);
extern int find_item_slot();
extern int has_intrinsic(int intr);
extern int intrinsic_count(int intr);
extern void get_shop_items(int otype1,int otype2,int otype3,int otype4,int rarity);
extern double item_cost(OBJECT_REC* item);
extern void shop(char* name,int shop_type);
extern int place_object(int level);
extern OBJECT_REC* find_linked_item(int lnk);
extern void dead_monster(NPC_REC* mon,char tr);
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
extern void gain_exp(double amt);
extern void show_quest();
