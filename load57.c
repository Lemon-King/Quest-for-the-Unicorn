/*
 *******************************************************************
 *** This software is copyright 1985-2014 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

#define NO_OF_MAPS_OLD       17

typedef struct {
  int    speed;
  int    number;
  int    hp;
  int    mana;
  int    level;
  int    attack;
  int    defense;
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
  } NPC_REC_OLD;

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
  char name[33];
  int    num_enchantments;
  int    enchantments[3];
  int    num_sockets;
  int    sockets[3];
  } OBJECT_REC_OLD;

typedef struct {
  int        region;
  int        rx;
  int        ry;
  int        cx;
  int        cy;
  double     mortgage;
  double     payment;
  double     interest;
  OBJECT_REC_OLD inventory[500];
  } HOUSE_OLD;

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
  OBJECT_REC_OLD invent[20];
  OBJECT_REC_OLD pack[33];
  byte      potion[9];
  byte      ring[9];
  byte      staff[13];
  int       effect[255];
  byte      oknow[1000];
  NPC_REC_OLD   monster[6][61];
  NPC_REC_OLD   party[6];
  int       align;
  char      in_city;
  byte      city;
  int       hp_count;
  int       mana_count;
  byte      spell[56];
  int       phase;
  byte      gen[5000];
  byte      lore[5000];
  OBJECT_REC_OLD pawn[10][11];
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
  OBJECT_REC_OLD map_objects[1000];
  OBJECT_REC_OLD hole[1000];
  HOUSE_OLD  houses[5];
  int        dungeon_number;
  char       quests[1000];
  int32_t    time_played;
  } PLAYER_REC_OLD;

PLAYER_REC_OLD old;

OBJECT_REC* find_item_by_name(char* name) {
  int i;
  i = 0;
  while (objects[i].otype <100) {
    if (strcmp(name,objects[i].name) == 0) return &(objects[i]);
    i++;
    }
  return NULL;
  }

void convertObject(OBJECT_REC* newObj,OBJECT_REC_OLD* oldObj) {
  int i;
  OBJECT_REC* item;
  newObj->link = oldObj->link;
  newObj->otype = oldObj->otype;
  newObj->user_hp = oldObj->user_hp;
  newObj->user_health = oldObj->user_health;
  newObj->effect = oldObj->effect;
  newObj->control = oldObj->control;
  newObj->control2 = oldObj->control2;
  newObj->weight = oldObj->weight;
  newObj->cost = oldObj->cost;
  newObj->level = oldObj->level;
  newObj->damage = oldObj->damage;
  newObj->sprite = oldObj->sprite;
  newObj->rarity = oldObj->rarity;
  newObj->plus = oldObj->plus;
  newObj->charges = oldObj->charges;
  newObj->costp = oldObj->costp;
  strcpy(newObj->name,oldObj->name);
  newObj->num_enchantments = oldObj->num_enchantments;
  for (i=0; i<3; i++) newObj->enchantments[i] = oldObj->enchantments[i];
  newObj->num_sockets = oldObj->num_sockets;
  for (i=0; i<3; i++) newObj->sockets[i] = oldObj->sockets[i];
  newObj->align = 0;
  if (newObj->otype != O_NONE) {
    item = find_item_by_name(newObj->name);
    if (item != NULL) {
      newObj->skill = item->skill;
      newObj->min_skill = item->min_skill;
      } else {
      newObj->skill = 0;
      newObj->min_skill = 0;
      if (newObj->otype == O_BOW) newObj->skill = SK_BOW;
      if (newObj->otype == O_EDGE) newObj->skill = SK_1HSWORD;
      if (newObj->otype == O_BLNT) newObj->skill = SK_MACE;
      if (newObj->otype == O_POLE) newObj->skill = SK_SPEAR;
      if (newObj->otype == O_WAND) newObj->skill = SK_MAGIC;
      if (newObj->otype == O_DAGR) newObj->skill = SK_DAGGER;
      }
    }
  }

void convertHouse(HOUSE* newHouse,HOUSE_OLD* oldHouse) {
  int i;
  newHouse->region = oldHouse->region;
  newHouse->rx = oldHouse->rx;
  newHouse->ry = oldHouse->ry;
  newHouse->cx = oldHouse->cx;
  newHouse->cy = oldHouse->cy;
  newHouse->mortgage = oldHouse->mortgage;
  newHouse->payment = oldHouse->payment;
  newHouse->interest = oldHouse->interest;
  for (i=0; i<500; i++) convertObject(&(newHouse->inventory[i]),&(oldHouse->inventory[i]));
  }

void convertNPC(NPC_REC* newNpc,NPC_REC_OLD* oldNpc) {
  int i;
  newNpc->speed = oldNpc->speed;
  newNpc->number = oldNpc->number;
  newNpc->hp = oldNpc->hp;
  newNpc->max_hp = newNpc->hp;
  newNpc->mana = oldNpc->mana;
  newNpc->level = oldNpc->level;
  newNpc->attack = oldNpc->attack;
  newNpc->defense = oldNpc->defense;
  newNpc->exp = oldNpc->exp;
  newNpc->exp_hp = oldNpc->exp_hp;
  newNpc->sprite = oldNpc->sprite;
  strcpy(newNpc->name,oldNpc->name);
  newNpc->time = oldNpc->time;
  newNpc->sleep = oldNpc->sleep;
  newNpc->fear = oldNpc->fear;
  newNpc->blind = oldNpc->blind;
  newNpc->confused = oldNpc->confused;
  newNpc->poison = oldNpc->poison;
  newNpc->prev = oldNpc->prev;
  newNpc->treasure = oldNpc->treasure;
  newNpc->special2 = 0;
  switch (oldNpc->special) {
    case 1: newNpc->special = 1; break;
    case 2: newNpc->special = 2; break;
    case 3: newNpc->special = 4; break;
    case 4: newNpc->special = 128; break;
    case 5: newNpc->special = 8; break;
    case 10: newNpc->special = 16; break;
    default: newNpc->special = 0; break;
    }
  i = 0;
  while (i < 9999 && monsters[i].speed < 900) {
    if (strcmp(monsters[i].name,oldNpc->name) == 0) {
      newNpc->mtype = monsters[i].mtype;
      i = 999999;
      }
    i++;
    }
  }

void convertPlayer() {
  int i;
  int x,y;
  OBJECT_REC tmp;
  strcpy(player.name,old.name);
  player.age = old.age;
  player.sex = old.sex;
  player.level = old.level;
  player.exp = old.exp;
  player.exp_next = old.exp_next;
  player.class = old.class;
  strcpy(player.title,old.title);
  player.race = old.race;
  for (i=0; i<7; i++) player.stat[i] = old.stat[i];
  player.mhp = old.mhp;
  player.chp = old.chp;
  player.health = old.health;
  player.mmana = old.mmana;
  player.cmana = old.cmana;
  for (i=0; i<11; i++) player.ability[i] = old.ability[i];
  player.x = old.x;
  player.y = old.y;
  player.map_x = old.map_x;
  player.map_y = old.map_y;
  for (x=0; x<101; x++) for (y=0; y<101; y++) player.map[x][y] = old.map[x][y];
  for (x=0; x<101; x++) for (y=0; y<101; y++) player.known[x][y] = old.known[x][y];
  player.region = old.region;
  for (i=0; i<17; i++) player.skill[i] = old.skill[i];
  player.skill[17] = player.skill[2];
  player.skill[18] = player.skill[2];
  player.skill[19] = player.skill[2];
  player.skill[20] = player.skill[4];
  player.skill[21] = player.skill[1];
  player.skill[22] = player.skill[3];
  player.skill[23] = player.skill[3];
  player.torch = old.torch;
  player.food = old.food;
  player.armour = old.armour;
  player.weapon = old.weapon;
  player.mount = old.mount;
  player.peg = old.peg;
  player.gold_coins = 0;
  player.adamantite_coins = 0;
  player.mithril_coins = 0;
  add_gold(old.gold);
  player.bank = old.bank;
  player.interest = old.interest;
  player.d_level = old.d_level;
  player.diff = old.diff;
  player.land_x = old.land_x;
  player.land_y = old.land_y;
  strcpy(player.d_name,old.d_name);
  player.day = old.day;
  player.month = old.month;
  player.min = old.min;
  player.hour = old.hour;
  for (i=0; i<20; i++) convertObject(&(player.invent[i]),&(old.invent[i]));
  for (i=0; i<33; i++) convertObject(&(player.pack[i]),&(old.pack[i]));
  for (i=0; i<9; i++) player.potion[i] = old.potion[i];
  for (i=0; i<9; i++) player.ring[i] = old.ring[i];
  for (i=0; i<13; i++) player.staff[i] = old.staff[i];
  for (i=0; i<255; i++) player.effect[i] = old.effect[i];
  for (x=0; x<6; x++) for (y=0; y<61; y++) convertNPC(&(player.monster[x][y]),&(old.monster[x][y]));
  for (i=0; i<6; i++) convertNPC(&(player.party[i]),&(old.party[i]));
  player.align = old.align;
  player.in_city = old.in_city;
  player.city = old.city;
  player.hp_count = old.hp_count;
  player.mana_count = old.mana_count;
  for (i=0; i<56; i++) player.xxxxx[i] = old.spell[i];
  for (i=56; i<256; i++) player.xxxxx[i] = 0;
  for (i=0; i<1000; i++) spellbook[i] = 0;
  for (i=0; i<256; i++) spellbook[i] = player.xxxxx[i];
  player.phase = old.phase;
  for (i=0; i<5000; i++) player.gen[i] = old.gen[i];
  for (i=0; i<5000; i++) player.lore[i] = old.lore[i];
  for (x=0; x<10; x++) for (y=0; y<11; y++) convertObject(&(player.pawn[x][y]),&(old.pawn[x][y]));
  for (i=0; i<11; i++) strcpy(player.fspell[i],old.fspell[i]);
  player.ship_x = old.ship_x;
  player.ship_y = old.ship_y;
  player.ship_r = old.ship_r;
  player.inship = old.inship;
  player.gateway = old.gateway;
  for (i=0; i<11; i++) player.tardis_x[i] = old.tardis_x[i];
  for (i=0; i<11; i++) player.tardis_y[i] = old.tardis_y[i];
  for (i=0; i<11; i++) player.tardis_r[i] = old.tardis_r[i];
  for (i=0; i<11; i++) strcpy(player.tardis_d[i],old.tardis_d[i]);
  player.cav_paid = old.cav_paid;
  for (i=0; i<1000; i++) convertObject(&(player.map_objects[i]),&(old.map_objects[i]));
  for (i=0; i<1000; i++) convertObject(&(player.hole[i]),&(old.hole[i]));
  for (i=0; i<5; i++) convertHouse(&(player.houses[i]),&(old.houses[i]));
  player.dungeon_number = old.dungeon_number;
  for (i=0; i<1000; i++) player.quests[i] = old.quests[i];
  player.time_played = old.time_played;
  tmp = player.invent[I_LHND];
  player.invent[I_LHND] = player.invent[I_RHND];
  player.invent[I_RHND] = tmp;
  player.effect[PE_DEPTH] = 10;
  }

void load57() {
  int i;
  int j;
  int x;
  int y;
  int save_file;
  int temp_file;
  int change_set;
  char buffer[20];
  char filename[64];
  char ver[40];
  KNOW_TYPE known;
#ifdef ANNIV
  int rebirth;
  rebirth = 0;
#endif

  strcpy(filename,loadname);
  strcat(filename,".sav");
  change_set = 0;
#ifdef MINGW
  save_file = open(filename,O_RDONLY | O_BINARY);
#else
  save_file = open(filename,O_RDONLY);
#endif
  if (save_file < 0) {
    printf("Fatal Error: Could not open %s\n",filename);
#ifdef ASCII
    restoreTerm();
#endif

    exit(1);
    }
  read(save_file,buffer,sizeof(buffer));
  strcpy(ver,"v5.7.0");
  if (strcmp(buffer,ver) != 0) {
    if (strcmp(buffer,"v5.2.2(HC)") == 0) change_set = 1;
    if (strcmp(buffer,"v5.4.0") == 0) change_set = 2;
    if (strcmp(buffer,"v5.5.0") == 0) change_set = 3;
    if (strcmp(buffer,"v5.6.0") == 0) change_set = 4;
    if (change_set == 0) {
      printf("Fatal Error: Incorrect version in save file, aborting.\n");
#ifdef ASCII
      restoreTerm();
#endif
      exit(1);
      }
    }
  read(save_file,&old,sizeof(PLAYER_REC_OLD));
  convertPlayer();
#ifdef MINGW
  temp_file = open("temp01.$$$",O_WRONLY | O_CREAT | O_TRUNC | O_BINARY,0660);
#else
  temp_file = open("temp01.$$$",O_WRONLY | O_CREAT | O_TRUNC,0660);
#endif
  if (temp_file < 0) {
    printf("Fatal Error: Could not open temp01.$$$\n");
#ifdef ASCII
    restoreTerm();
#endif
    exit(1);
    }
  for (i=1; i<=NO_OF_MAPS_OLD; i++) {
    read(save_file,&known,sizeof(KNOW_TYPE));
    lseek(temp_file,sizeof(KNOW_TYPE) * i,SEEK_SET);
    write(temp_file,&known,sizeof(KNOW_TYPE));
    }
  for (x=0; x<101; x++) for (y=0; y<101; y++) known[x][y] = 0;
  for (i=NO_OF_MAPS_OLD+1; i<=NO_OF_MAPS; i++) {
    lseek(temp_file,sizeof(KNOW_TYPE) * i,SEEK_SET);
    write(temp_file,&known,sizeof(KNOW_TYPE));
    }

  if (change_set > 0 && change_set <= 1) {
    for (i=0; i<255; i++) stats.counts[i] = 0;
    for (i=0; i<255; i++) stats.trophies[i] = 0;
    stats.num_trophies = 0;
    }
  else
    read(save_file,&stats,sizeof(STATS_REC));
  close(save_file);
  close(temp_file);
  for (i=1; i<20; i++)
    if (player.invent[i].otype != O_NONE) {
      j=0;
      while (j>=0) {
        if (strcmp(player.invent[i].name,objects[j].name) == 0)
            player.invent[i].link = objects[j].link;
        if (objects[j].otype > 200) j = -1;
          else j++;
        }
      }
  for (i=1; i<=32; i++)
    if (player.pack[i].otype != O_NONE) {
      j=0;
      while (j>=0) {
        if (strcmp(player.pack[i].name,objects[j].name) == 0)
            player.pack[i].link = objects[j].link;
        if (objects[j].otype > 200) j = -1;
          else j++;
        }
      }
  if (change_set == 3) {
    for (i=0; i<16; i++) player.skill[i] *= 100000;
    }
#ifdef ASCII
/*  unlink(filename); */
#endif  
#ifdef ANNIV
#include "./Anniv25/makechar.c"
#endif
  }

