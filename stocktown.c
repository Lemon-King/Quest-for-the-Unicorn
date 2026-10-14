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

void stock_town(byte town) {
  int i;
  int x,y;
  char flag;
  int  base;
  int  range;
  for (i=1; i<=60; i++) {
    for (x=1; x<=5; x++) player.monster[x][i].hp = 0;
    x = u_random(100) + 1;
    y = u_random(100) + 1;
    while (player.map[x][y] != 7 && player.map[x][y] != 15 &&
           player.map[x][y] != 1) {
      x = u_random(100) + 1;
      y = u_random(100) + 1;
      }
    flag = ' ';
    while (flag == ' ') {
      y = u_random(100);
      if (y <= 70) { base = 163; range = 20; }
      else {base = 127; range = 35; }
      player.monster[1][i] = monsters[base+u_random(range)];
      flag = '*';
      }
    player.monster[1][i].hp = u_random(player.monster[1][i].hp) + 1;
    player.monster[1][i].exp +=
      player.monster[1][i].exp_hp * player.monster[1][i].hp;
    player.monster[1][i].prev = player.map[x][y];
    player.map[x][y] = 0 - i;
    if (player.monster[1][i].sprite == 161)
      switch (u_random(28)) {
        case  0:strcpy(player.monster[1][i].name,"Sandy"); break;
        case  1:strcpy(player.monster[1][i].name,"Barbara"); break;
        case  2:strcpy(player.monster[1][i].name,"Valerie"); break;
        case  3:strcpy(player.monster[1][i].name,"Lisa"); break;
        case  4:strcpy(player.monster[1][i].name,"Susan"); break;
        case  5:strcpy(player.monster[1][i].name,"Carol"); break;
        case  6:strcpy(player.monster[1][i].name,"Vicki"); break;
        case  7:strcpy(player.monster[1][i].name,"Mariah"); break;
        case  8:strcpy(player.monster[1][i].name,"Amber"); break;
        case  9:strcpy(player.monster[1][i].name,"Larisa"); break;
        case 10:strcpy(player.monster[1][i].name,"Anne"); break;
        case 11:strcpy(player.monster[1][i].name,"Karen"); break;
        case 12:strcpy(player.monster[1][i].name,"Laura"); break;
        case 13:strcpy(player.monster[1][i].name,"Nina"); break;
        case 14:strcpy(player.monster[1][i].name,"Kathryn"); break;
        case 15:strcpy(player.monster[1][i].name,"Marisa"); break;
        case 16:strcpy(player.monster[1][i].name,"Janis"); break;
        case 17:strcpy(player.monster[1][i].name,"Melissa"); break;
        case 18:strcpy(player.monster[1][i].name,"Sara"); break;
        case 19:strcpy(player.monster[1][i].name,"Diane"); break;
        case 20:strcpy(player.monster[1][i].name,"Constance"); break;
        case 21:strcpy(player.monster[1][i].name,"Linda"); break;
        case 22:strcpy(player.monster[1][i].name,"Donna"); break;
        case 23:strcpy(player.monster[1][i].name,"Terri"); break;
        case 24:strcpy(player.monster[1][i].name,"Victoria"); break;
        case 25:strcpy(player.monster[1][i].name,"Gloria"); break;
        case 26:strcpy(player.monster[1][i].name,"Judith"); break;
        case 27:strcpy(player.monster[1][i].name,"Deanna"); break;
        }
    if (player.monster[1][i].sprite == 162)
      switch (u_random(25)) {
        case  0:strcpy(player.monster[1][i].name,"Mike"); break;
        case  1:strcpy(player.monster[1][i].name,"John"); break;
        case  2:strcpy(player.monster[1][i].name,"Edwin"); break;
        case  3:strcpy(player.monster[1][i].name,"George"); break;
        case  4:strcpy(player.monster[1][i].name,"Paul"); break;
        case  5:strcpy(player.monster[1][i].name,"Scotte"); break;
        case  6:strcpy(player.monster[1][i].name,"Stephen"); break;
        case  7:strcpy(player.monster[1][i].name,"David"); break;
        case  8:strcpy(player.monster[1][i].name,"Simon"); break;
        case  9:strcpy(player.monster[1][i].name,"Robert"); break;
        case 10:strcpy(player.monster[1][i].name,"Howard"); break;
        case 11:strcpy(player.monster[1][i].name,"Jack"); break;
        case 12:strcpy(player.monster[1][i].name,"Phil"); break;
        case 13:strcpy(player.monster[1][i].name,"Gary"); break;
        case 14:strcpy(player.monster[1][i].name,"Peter"); break;
        case 15:strcpy(player.monster[1][i].name,"Norman"); break;
        case 16:strcpy(player.monster[1][i].name,"Joseph"); break;
        case 17:strcpy(player.monster[1][i].name,"Thomas"); break;
        case 18:strcpy(player.monster[1][i].name,"Alan"); break;
        case 19:strcpy(player.monster[1][i].name,"Arthur"); break;
        case 20:strcpy(player.monster[1][i].name,"Walter"); break;
        case 21:strcpy(player.monster[1][i].name,"Matthew"); break;
        case 22:strcpy(player.monster[1][i].name,"Darren"); break;
        case 23:strcpy(player.monster[1][i].name,"Kenneth"); break;
        case 24:strcpy(player.monster[1][i].name,"Samuel"); break;
        }
    if (player.class == 7) {
      if (player.monster[1][i].sprite>162 && player.monster[1][i].sprite<176)
        if (u_random(100) < 80)
          player.monster[1][i].special -= 10;
      }
    }
  }
