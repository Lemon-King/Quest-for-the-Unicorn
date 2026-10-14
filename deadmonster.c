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

void dead_monster(NPC_REC* mon,char tr) {
  int i;
  int lvl;
  if (mon->hp <= 0) {
    if (strcmp(mon->name,"Eshter") == 0) eshter();
    gain_exp(mon->exp);
/*    player.exp += mon->exp; */
    if (tr == 'Y' && mon->prev == 7) {
      i = u_random(100);
      if (i >=0 && i<=60) {
        lvl = mon->level;
        mon->prev = place_object(lvl) + 1000;
        }
      if (i >=61 && i<=80) mon->prev = 79;
      if (i >=81 && i<=99) mon->prev = 84;
      }
    player.map[player.x][player.y] = mon->prev;
    show_spot(player.x,player.y);
/*
    sprintf(buffer,"Exp=%.0f",mon->exp);
    msg(buffer,15);
*/
    if (mon->special > 9) {
      player.align -= 20;
      if (player.align < 0) player.align = 0;
      }
    show_side();
    }
  }

/*
void dead_monster(int mon,char tr) {
  int i;
  int lvl;
  char buffer[80];
  if (player.monster[1][mon].hp <= 0) {
    if (strcmp(player.monster[1][mon].name,"Eshter") == 0) eshter();
    player.exp += player.monster[1][mon].exp;
    if (tr == 'Y' && player.monster[1][mon].prev == 7) {
      i = u_random(100);
      if (i >=0 && i<=60) {

        lvl = player.monster[1][mon].level;
        player.monster[1][mon].prev = place_object(lvl) + 1000;
        }
      if (i >=61 && i<=80) player.monster[1][mon].prev = 79;
      if (i >=81 && i<=99) player.monster[1][mon].prev = 84;
      }
    player.map[player.x][player.y] = player.monster[1][mon].prev;
    show_spot(player.x,player.y);
    clear_prompt();
    sprintf(buffer,"Exp=%.0f",player.monster[1][mon].exp);
    msg(buffer,15);
    if (player.monster[1][mon].special > 9) {
      player.align -= 20;
      if (player.align < 0) player.align = 0;
      }
    show_side();
    }
  }
*/
