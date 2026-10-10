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

void area49(int damage,int elem,int center_x,int center_y) { 
  char buffer[32];
  int  x,y;
  int  x1,y1;
  int  mon;
  int  i;
  x1 = center_x; y1 = center_y;
  if (x1<3) x1=3; else if (x1>97) x1 = 97;
  if (y1<3) y1=3; else if (y1>97) y1 = 97;
  for (x=x1-3; x<=x1+3; x++)
    for (y=y1-3; y<=y1+3; y++)
      if (player.map[x][y] < 0 || (player.map[x][y]>400 && player.map[x][y]<500)) {
        if (in_arena == 'Y') mon = player.map[x][y] - 400;
          else mon = player.map[x][y];
        if (mon < 0) mon = -mon;
        i = 90;
        if (in_arena == 'Y' && player.monster[mon][a_mon].special == 1) i = 0;
        if (in_arena != 'Y' && player.monster[1][mon].special == 1) i = 0;
        if (u_random(100) < i) {
          clear_prompt();
          noise(1000,100);
          prompt("HIT !!!"); 
          if (in_arena != 'Y' && player.monster[1][mon].special > 9) {
            player.align -= 20;
            player.monster[1][mon].special -= 10;
            if (player.align < 0) player.align = 0; 
            }
          if (in_arena == 'Y' && player.monster[mon][a_mon].special > 9) {
            player.align -= 20;
            player.monster[mon][a_mon].special -= 10;
            if (player.align < 0) player.align = 0;
            }
          if (in_sight(x,y) == '*') {
            show_sprite(x-player.map_x,y-player.map_y,80);
            delay(250);
            show_spot(x,y);
            }
          i = u_random(damage) + 1;
          if (u_random(100) < get_crit()) {
            i *= 2;
            stats.counts[STAT_CRITS]++;
            }
          if (in_arena == 'Y') i = figure_damage(i,elem,&(player.monster[mon][a_mon]));
            else  i = figure_damage(i,elem,&(player.monster[1][mon]));
          stats_do_damage(i);
          if (in_arena == 'Y') player.monster[mon][a_mon].hp -= i;
            else player.monster[1][mon].hp -= i;
          if (in_arena == 'Y') i=player.monster[mon][a_mon].hp;
            else i=player.monster[1][mon].hp;
          if (i <= 0) {
            clear_prompt();
            if (in_arena != 'Y') {
              sprintf(buffer,"Exp=%.0f",player.monster[1][mon].exp);
              prompt(buffer);
              player.exp += player.monster[1][mon].exp;
              player.map[x][y] = player.monster[1][mon].prev;
              }
            if (in_arena == 'Y') {
              sprintf(buffer,"Exp=%.0f",player.monster[mon][a_mon].exp);
              prompt(buffer);
              player.exp += player.monster[mon][a_mon].exp;
              player.map[x][y] = player.monster[mon][a_mon].prev;
              }
            show_spot(x,y);
            if (in_arena != 'Y' && player.monster[1][mon].special > 9) {
              player.align -= 20;
              if (player.align < 0) player.align = 0;
              }
            if (in_arena == 'Y' && player.monster[mon][a_mon].special > 9) {
              player.align -= 20;
              if (player.align < 0) player.align = 0;
              }
            show_side();
            }

          }
        else {
          clear_prompt();
          prompt("Fizzle. . .");
          stats.counts[STAT_MISSES]++;
          }
        }
  }
