/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

void stock_monsters() {
  int i,j;
  byte x,y;
  int  min,max;
  char flag;
  int  number;
  int  friend;
  int  x1,y1;
  char mflag;
  char n[80];
  double texp;
  int    mnst;
  prompt("Stocking Monsters...");
  texp = 0;
  friend = 5;
  min = (player.diff + player.d_level / 4) - 5;
  if (min < 1) min = 1;
  if (min > 20) min = 20;
  max = player.diff + player.d_level / 4;
  if (max < min) max = min;
  if (player.land_x == 16 && player.land_y == 28 &&
      player.d_level == bottom) {
    min = 99;
    max = 99;
    }
  number = player.diff / 4;
  if (number < 1) number = 1;
  if (number > 5) number = 5;
  for (i=1; i<=60; i++) {
/*
    sprintf(n,"Stocking Monsters...%d%%",(i*100)/60);
    prompt(n);
*/
    for (x=1; x<=5; x++) player.monster[x][i].hp = 0;
    mflag = ' ';
    while (mflag == ' ') {
      x = u_random(100); y = u_random(100);
      if (player.map[x][y] == 7) mflag = '*';
      if (player.map[x][y] == 2) mflag = '*';
      if (player.map[x][y] == 9) mflag = '*';
      if (player.map[x][y] == 1) mflag = '*';
      }
    player.map[x][y] = 0-i;
    for (j=1; j<=number; j++) {
      if (player.gateway == '*' && player.d_level == 5 && j == 1 && i == 1) {
        for (x1=x-2; x1<=x+2; x++)
          for (y1=y-2; y1<=y+2; y++)
            player.map[x1][y1] = 41;
        player.map[x][y] = 0-i;
        }
      flag = ' ';
      while (flag == ' ') {
        if (player.gateway == '*' && player.d_level == 5 && j == 1 && i == 1) {
          mnst = 184;
          flag = '*';
          }
        else if (player.land_x == 16 && player.land_y == 28 &&
                 player.d_level == bottom) {
          mnst = 183;
          flag = '*';
          }
        else
          mnst = u_random(NO_OF_MONSTERS);
        player.monster[j][i] = monsters[mnst];
        if (player.monster[j][i].level >= min &&
            player.monster[j][i].level <= max) flag = '*';
        if (j > 1) {
          if (player.monster[1][i].special < 10)
            if (player.monster[j][i].special > 9) flag = ' ';
          if (player.monster[1][i].special > 9)
            if (player.monster[j][i].special < 10) flag = ' ';
          }
        if (j < 2) {
          if (friend == 0 && player.monster[1][i].special > 9 && flag == '*')
            flag = ' ';
          if (friend > 0 && player.monster[1][i].special > 9 && flag == '*')
            friend--;
          }
        }
      player.monster[j][i].hp = u_random(player.monster[j][i].hp) + 1;
      player.monster[j][i].exp += player.monster[j][i].exp_hp * player.monster[j][i].hp;
      texp += player.monster[j][i].exp;
      }
    }
  if (player.gateway == '*' && player.d_level == 5)
    for (i=2; i<=5; i++) player.monster[i][1].hp = 0;
  sprintf(n,"Total Experience=%.0f",texp);
  prompt(n);
  }

