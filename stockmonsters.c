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

void stock_monsters(int depth,int treasurex,int treasurey,MAP_TYPE* map,DUNGEON_MONSTERS* dmonsters) {
  int i,j;
  byte x,y;
  int  min,max;
  char flag;
  int  number;
  int  groupsize;
  int  friend;
  int  x1,y1;
  char mflag;
  double texp;
  int    mnst;
  int    scale;
  int    retries;
  int    bossscale;
  scale = get_monster_level_plus();
  texp = 0;
  friend = 5;
  min = (player.diff + player.d_level / 4) - 5;
  min = player.diff;
  if (min < 1) min = 1;
  if (min > 20) min = 20;
  max = player.diff + depth / 4;
  if (max < min) max = min;
  if (player.land_x == 16 && player.land_y == 28 &&
      player.d_level == bottom) {
    min = 99;
    max = 99;
    }
  number = player.diff / 4;
  if (number < 1) number = 1;
  if (number > 5) number = 5;
  if (player.effect[PE_NOARENA]) number = 1;
  for (i=1; i<=player.effect[PE_MCOUNT]; i++) {
    for (x=1; x<=5; x++) (*dmonsters)[x][i].hp = 0;
    mflag = ' ';
    retries = 200;
    while (mflag == ' ' && retries > 0) {
      x = u_random(96)+2; y = u_random(96)+2;
      if (i == 1 && treasurex >= 0 && retries > 100) {
        x = treasurex - 4 + u_random(9);
        y = treasurey - 4 + u_random(9);
        }
      if (x > 1 && x < 100 && y > 1 && y < 100) {
        if ((*map)[x][y] == currentFloor) mflag = '*';
        if ((*map)[x][y] == 2) mflag = '*';
        if ((*map)[x][y] == 9) mflag = '*';
        if ((*map)[x][y] == 1) mflag = '*';
        if (i == 1 && treasurex >= 0 && abs(treasurex-x) < 2 && abs(treasurey-y < 2)) mflag = ' ';
        }
      retries--;
      }
    (*map)[x][y] = 0-i;
    groupsize = number;
    if (i == 1 &&
        player.gateway != '*' &&
        treasurex >= 0 &&
        links[player.dungeon_number].numadds > 0) {
       groupsize = links[player.dungeon_number].numadds+1;
       }
    if (groupsize > 5) groupsize = 5;
    for (j=1; j<=groupsize; j++) {
      if (player.gateway == '*' && player.d_level == 5 && j == 1 && i == 1) {
        for (x1=x-2; x1<=x+2; x1++)
          for (y1=y-2; y1<=y+2; y1++)
            (*map)[x1][y1] = 41;
        (*map)[x][y] = 0-i;
        }
      bossscale = 0;
      flag = ' ';
      while (flag == ' ') {
        mnst = -1;
        if (player.gateway == '*' && player.d_level == 5 && j == 1 && i == 1) {
          mnst = get_linked_monster(90); /* Eshter */
          flag = '*';
          }
        else if (player.gateway != '*' && treasurex >= 0 && links[player.dungeon_number].boss > 0 && j == 1 && i == 1) {
          mnst = get_linked_monster(links[player.dungeon_number].boss);
          flag = '*';
          bossscale = 2;
          if (mnst < 0) {
            bossscale = 0;
            mnst = -1;
            flag = ' ';
            }
          }
        else if (player.gateway != '*' && treasurex >= 0 && links[player.dungeon_number].adds > 0 && j != 1 && i == 1) {
          mnst = get_linked_monster(links[player.dungeon_number].adds);
          bossscale = 1;
          flag = '*';
          if (mnst < 0) {
            flag = ' ';
            bossscale = 0;
            mnst = -1;
            }
          }
        else if (player.land_x == 16 && player.land_y == 28 &&
                 player.d_level == bottom) {
          mnst = get_linked_monster(91);   /* Dalek */
          flag = '*';
          }
        while (mnst < 0) {
          mnst = u_random(NO_OF_MONSTERS);
          if ((monsters[mnst].special2 & M2_NORND) != 0) mnst = -1;
          }
        (*dmonsters)[j][i] = monsters[mnst];
        if ((*dmonsters)[j][i].level >= min &&
            (*dmonsters)[j][i].level <= max) flag = '*';
        if (bossscale == 0 && (monsters[mnst].special2 & M2_BOSS) != 0) flag = ' ';
        if (j > 1) {
          if (((*dmonsters)[1][i].special & MS_FRIENDLY) == 0)
            if (((*dmonsters)[j][i].special & MS_FRIENDLY) == MS_FRIENDLY) flag = ' ';
          if (((*dmonsters)[1][i].special & MS_FRIENDLY) == MS_FRIENDLY)
            if (((*dmonsters)[j][i].special & MS_FRIENDLY) == 0) flag = ' ';
          }
        if (j < 2) {
          if (friend == 0 && ((*dmonsters)[1][i].special & MS_FRIENDLY) == MS_FRIENDLY && flag == '*')
            flag = ' ';
          if (friend > 0 && ((*dmonsters)[1][i].special & MS_FRIENDLY) == MS_FRIENDLY && flag == '*')
            friend--;
          }
        }
      if ((*dmonsters)[j][i].hp < 0) {
        (*dmonsters)[j][i].hp = -(*dmonsters)[j][i].hp;
        } else {
        (*dmonsters)[j][i].hp = (*dmonsters)[j][i].hp / 2 + u_random((*dmonsters)[j][i].hp / 2) + 1;
        }
      (*dmonsters)[j][i].exp += (*dmonsters)[j][i].exp_hp * (*dmonsters)[j][i].hp;
      if (((*dmonsters)[j][i].special & MS_FRIENDLY) == 0) texp += (*dmonsters)[j][i].exp;
      if (scale != 0) scale_monster(&((*dmonsters)[j][i]),scale);
      if (player.effect[PE_HEROIC] > 0) multiply_monster(&((*dmonsters)[j][i]),player.effect[PE_HEROIC]);
      if (bossscale != 0) scale_monster(&((*dmonsters)[j][i]),bossscale);
      if (dungeon_scaling == 'Y' && player.level > player.diff) scale_monster(&((*dmonsters)[j][i]),player.level - player.diff);
      (*dmonsters)[j][i].speed = -(*dmonsters)[j][i].speed;
      }
    }
  if (player.gateway == '*' && player.d_level == 5)
    for (i=2; i<=5; i++) (*dmonsters)[i][1].hp = 0;
  }

