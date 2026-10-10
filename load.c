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

typedef struct {
  int          num_levels;
  int          dungeon_number;
  MAP_TYPE     maps[10];
  KNOW_TYPE    known[10];
  DUNGEON_MONSTERS monsters[10];
  DUNGEON_OBJECTS  objects[10];
  int          upx[10];
  int          upy[10];
  int          downx[10];
  int          downy[10];
  int          treasurex;
  int          treasurey;
  } DUNGEON_6_2;

DUNGEON_6_2            current_dungeon_6_2;

void load() {
  int i;
  int j;
  int k;
  int x,y;
  int save_file;
  int temp_file;
  int change_set;
  char buffer[20];
  char filename[64];
  char ver[40];
  KNOW_TYPE known;
#ifdef ANNIV
  unsigned short checkcode;
  unsigned short savedcode;
#endif

  change_set = 0;
  strcpy(filename,loadname);
  strcat(filename,".sav");
  strcpy(backupname,loadname);
  strcat(backupname,".bak");
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
  strcpy(ver,VERSION);
  if (strcmp(buffer,"v5.2.2(HC)") == 0) change_set = 1;
  if (strcmp(buffer,"v5.4.0") == 0) change_set = 2;
  if (strcmp(buffer,"v5.5.0") == 0) change_set = 3;
  if (strcmp(buffer,"v5.6.0") == 0) change_set = 4;
  if (strcmp(buffer,"v5.7.0") == 0) change_set = 5;
  if (strcmp(buffer,"v6.0.0") == 0) change_set = 6;
  if (strcmp(buffer,"v6.1.0") == 0) change_set = 7;
  if (strcmp(buffer,"v6.2.0") == 0) change_set = 8;
  if (strcmp(buffer,"v6.3.0") == 0) change_set = 9;
  if (change_set == 0) {
    printf("Fatal Error: Incorrect version in save file, aborting.\n");
#ifdef ASCII
    restoreTerm();
#endif
    exit(1);
    }
  if (change_set > 0 && change_set <= 5) {
    close(save_file);
    load57();
    return;
    }
  read(save_file,&player,sizeof(PLAYER_REC));
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
  for (i=1; i<=NO_OF_MAPS; i++) {
    read(save_file,&known,sizeof(KNOW_TYPE));
    lseek(temp_file,sizeof(KNOW_TYPE) * i,SEEK_SET);
    write(temp_file,&known,sizeof(KNOW_TYPE));
    }
  read(save_file,&stats,sizeof(STATS_REC));
  if (change_set == 8) {
    stats.counts[STAT_DUNGEON_CLEARED] = 0;
    read(save_file,&current_dungeon_6_2,sizeof(DUNGEON_6_2));
    current_dungeon.num_levels = current_dungeon_6_2.num_levels;
    current_dungeon.dungeon_number = current_dungeon_6_2.dungeon_number;
    current_dungeon.treasurex = current_dungeon_6_2.treasurex;
    current_dungeon.treasurey = current_dungeon_6_2.treasurey;
    for (i=0; i<10; i++) {
      current_dungeon.level[i].upx = current_dungeon_6_2.upx[i];
      current_dungeon.level[i].upy = current_dungeon_6_2.upy[i];
      current_dungeon.level[i].downx = current_dungeon_6_2.downx[i];
      current_dungeon.level[i].downy = current_dungeon_6_2.downy[i];
      for (j=0; j<1000; j++) current_dungeon.level[i].objects[j] = current_dungeon_6_2.objects[i][j];
      for (j=0; j<6; j++)
        for (k=0; k<61; k++) current_dungeon.level[i].monsters[j][k] = current_dungeon_6_2.monsters[i][j][k];
      for (y=0; y<101; y++)
        for (x=0; x<101; x++) {
          current_dungeon.level[i].known[x][y] = current_dungeon_6_2.known[i][x][y];
          current_dungeon.level[i].map[x][y] = current_dungeon_6_2.maps[i][x][y];
          }
      current_dungeon.level[i].cleared = check_level_cleared(i);
      }
    }
  if (change_set >= 9) {
    read(save_file,&current_dungeon,sizeof(DUNGEON));
    }
  if (change_set >= 8) {
    read(save_file,&gear_manager,sizeof(GEAR_MANAGER));
    read(save_file,&spellbook,sizeof(SPELLBOOK));
    }
  close(save_file);
  close(temp_file);
#ifdef ANNIV
  if (skipcheck != 'Y') {
    savedcode = player.effect[254];
    player.effect[254] = 0;
    checkcode = crc((unsigned char*)(&player),sizeof(PLAYER_REC),0);
    if (checkcode != savedcode && savedcode != 0) {
      printf("Could not load file, possibly corrupted\r\n");
      printf("%d <> %d\r\n",checkcode,player.effect[254]);
      exit(1);
      }
  }
#endif
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
  if (player.effect[PE_DEPTH] <= 1) player.effect[PE_DEPTH] = 10;
  if (downgrade_depth >1 && downgrade_depth < player.effect[PE_DEPTH]) player.effect[PE_DEPTH] = downgrade_depth;
  if (downgrade_arena == 'Y') player.effect[PE_NOARENA] = 1;
  if (player.effect[PE_MCOUNT] < 10) player.effect[PE_MCOUNT] = 60;
#ifdef HC
  if (player.effect[PE_HEROIC] >= 0) {
     unlink(backupname);
     rename(filename,backupname);
     }
#endif
  if (change_set < 8) {
    player.effect[PE_WORLDSEED] = u_random(2000000000);
    if (player.d_level > 0) {
      build_dungeon(7,player.dungeon_number);
      player.x = current_dungeon.level[player.d_level-1].upx;
      player.y = current_dungeon.level[player.d_level-1].upy;
      load_level();
      }
    for (i=0; i<10; i++) {
      strcpy(gear_manager[i].main_hand,"");
      strcpy(gear_manager[i].off_hand,"");
      strcpy(gear_manager[i].neck_1,"");
      strcpy(gear_manager[i].neck_2,"");
      strcpy(gear_manager[i].shield,"");
      strcpy(gear_manager[i].armor,"");
      strcpy(gear_manager[i].ring_l1,"");
      strcpy(gear_manager[i].ring_l2,"");
      strcpy(gear_manager[i].ring_r1,"");
      strcpy(gear_manager[i].ring_r2,"");
      strcpy(gear_manager[i].cloak,"");
      strcpy(gear_manager[i].boots,"");
      strcpy(gear_manager[i].helm,"");
      }
    for (i=0; i<1000; i++) spellbook[i] = 0;
    for (i=0; i<255; i++) spellbook[i] = player.xxxxx[i];
    }
  for (i=1; i<20; i++) {
    if (strcasecmp(player.invent[i].name,"cube of force") == 0) {
      player.invent[i].effect = E_SPCL;
      player.invent[i].control = 99;
      }
    if (player.invent[i].otype != 0) {
      for (j=0; j<player.invent[i].num_sockets; j++) {
        if (player.invent[i].sockets[j] == S_CLD) player.invent[i].sockets[j] += 5;
        if (player.invent[i].sockets[j] == S_FIR) player.invent[i].sockets[j] += 5;
        if (player.invent[i].sockets[j] == S_ELC) player.invent[i].sockets[j] += 5;
        if (player.invent[i].sockets[j] == S_ARC) player.invent[i].sockets[j] += 5;
        }
      for (j=0; j<player.invent[i].num_enchantments; j++) {
        if (player.invent[i].enchantments[j] == S_CLD) player.invent[i].enchantments[j] += 5;
        if (player.invent[i].enchantments[j] == S_FIR) player.invent[i].enchantments[j] += 5;
        if (player.invent[i].enchantments[j] == S_ELC) player.invent[i].enchantments[j] += 5;
        if (player.invent[i].enchantments[j] == S_ARC) player.invent[i].enchantments[j] += 5;
        }
      }
    }
  for (i=0; i<33; i++) {
    if (strcasecmp(player.pack[i].name,"cube of force") == 0) {
      player.pack[i].control = E_SPCL;
      player.pack[i].effect = 99;
      }
    if (player.pack[i].otype != 0) {
      for (j=0; j<player.pack[i].num_sockets; j++) {
        if (player.pack[i].sockets[j] == S_CLD) player.pack[i].sockets[j] += 5;
        if (player.pack[i].sockets[j] == S_FIR) player.pack[i].sockets[j] += 5;
        if (player.pack[i].sockets[j] == S_ELC) player.pack[i].sockets[j] += 5;
        if (player.pack[i].sockets[j] == S_ARC) player.pack[i].sockets[j] += 5;
        }
      for (j=0; j<player.pack[i].num_enchantments; j++) {
        if (player.pack[i].enchantments[j] == S_CLD) player.pack[i].enchantments[j] += 5;
        if (player.pack[i].enchantments[j] == S_FIR) player.pack[i].enchantments[j] += 5;
        if (player.pack[i].enchantments[j] == S_ELC) player.pack[i].enchantments[j] += 5;
        if (player.pack[i].enchantments[j] == S_ARC) player.pack[i].enchantments[j] += 5;
        }
      }
    }
  }

