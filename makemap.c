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

void make_map(char dir) {
  int  i,j,x,y;
  int  upx,upy;
  int  downx,downy;
  byte floor;
  int  treasurex,treasurey;
  int see_stairs;
  int see_traps;
  OBJECT_REC* item;
  if (player.quests[player.dungeon_number] != 'Y') player.quests[player.dungeon_number] = 'E';
  see_stairs = (get_skill(SK_ORACLE) >= 10 && u_random(1000) < get_skill(SK_ORACLE)) ? -1 : 0;
  see_traps = (get_skill(SK_ORACLE) >= 10 && u_random(2000) < get_skill(SK_ORACLE)) ? -1 : 0;
  treasurex = -1;
  treasurey = -1;
  floor = 7;
  for (x=0; x<101; x++)
    for (y=0; y<101; y++) {
      player.map[x][y] = current_dungeon.level[player.d_level-1].map[x][y];
      player.known[x][y] = current_dungeon.level[player.d_level-1].known[x][y];
      }
  for (i=0; i<1000; i++)
    player.map_objects[i] = current_dungeon.level[player.d_level-1].objects[i];
  for (x=0; x<6; x++)
    for (y=0; y<61; y++) {
      player.monster[x][y] = current_dungeon.level[player.d_level-1].monsters[x][y];
      }
  treasurex = current_dungeon.treasurex;
  treasurey = current_dungeon.treasurey;
  upx = current_dungeon.level[player.d_level-1].upx;
  upy = current_dungeon.level[player.d_level-1].upy;
  downx = current_dungeon.level[player.d_level-1].downx;
  downy = current_dungeon.level[player.d_level-1].downy;
  if (player.d_level != player.effect[PE_DEPTH]) {
    treasurex = -1;
    treasurey = -1;
    }
  /* ***************************************************** */
  /* ***** Place dungeon treasure if on bottom level ***** */
  /* ***************************************************** */
  if (player.gateway != '*') {
    if (links[player.dungeon_number].treasure < 1000)
      if (player.d_level == player.effect[PE_DEPTH] && player.quests[player.dungeon_number] != 'Y') {
        x = treasurex;
        y = treasurey;
        for (i=x-1; i<=x+1; i++)
          for (j=y-1; j<=y+1; j++)
            player.map[i][j] = 41;
        item = find_linked_item(links[player.dungeon_number].treasure);
        if (item != NULL) {
          player.map_objects[0] = *item;
          player.map[x][y] = 1000;
          }
        }
    if (links[player.dungeon_number].treasure > 1000 && player.d_level == player.effect[PE_DEPTH]) {
      x = treasurex;
      y = treasurey;
      for (i=x-1; i<=x+1; i++)
        for (j=y-1; j<=y+1; j++)
          player.map[i][j] = 41;
      player.map[x][y] = links[player.dungeon_number].treasure + 1000;
      }
    }

/* ******************************************* */
/* ***** Check for existance of an altar ***** */
/* ******************************************* */
  if (u_random(100) == 10) {
    x = u_random(80) + 10;
    y = u_random(80) + 10;
    while (player.map[x][y] != floor) {
      x = u_random(80) + 10;
      y = u_random(80) + 10;
      }
    player.map[x][y] = 901;
    }

  if (dir == 'U') {
    player.x = downx;
    player.y = downy;
    }
  if (dir == 'D') {
    player.x = upx;
    player.y = upy;
    }
  if (player.gateway != '*' && Rcs_Random(25000) < get_skill(SK_ORACLE)) {
    for (x=1; x<=100; x++)
      for (y=1; y<=100; y++) {
        player.known[x][y] = 1;
        }
    }
  if (player.gateway == '*') {
    if (player.d_level == 1) {
      strcpy(player.d_name,"The Gateway");
      for (x=3; x<=98; x++)
        for (y=3; y<=98; y++)
          if (player.map[x][y] == 21) player.map[x][y] = 39;
      }
    if (player.d_level == 2) {
      strcpy(player.d_name,"The Gateway");
      for (x=3; x<=98; x++)
        for (y=3; y<=98; y++)
          if (player.map[x][y] == 21) player.map[x][y] = 38;
      }
    if (player.d_level == 3) {
      strcpy(player.d_name,"The Gateway");
      for (x=3; x<=98; x++)
        for (y=3; y<=98; y++)
          if (player.map[x][y] == 21) player.map[x][y] = 41;
      }
    if (player.d_level == 4) {
      player.diff = 30;
      strcpy(player.d_name,"Realm of Eshter");
      copyMap(&player.map,18);
      player.x = 78;
      player.y = 89;
      stock_monsters(player.d_level,-1,-1,&(player.map),&(player.monster));
      player.map_x = player.x-8;
      player.map_y = player.y-8;
      if (player.map_x<1) player.map_x = 1;
      if (player.map_y<1) player.map_y = 1;
      if (player.map_x>84) player.map_x = 84;
      if (player.map_y>84) player.map_y = 84;
      }
    if (player.d_level == 5) {
      strcpy(player.d_name,"Castle Eshter");
      }
    }
  }
