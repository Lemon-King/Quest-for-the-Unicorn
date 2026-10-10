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

void enemy_missile(int ex,int ey) {
  char flag;
  int  x,y;
  double  fx,fy;
  double xdir,ydir;
  NPC_REC* monster;
  char elem[20];
  char buffer[60];
  int  ring;
  int  i,j;
  monster = get_monster(ex,ey);
  if (monster == NULL) return;
  run_x = 0; run_y = 0;
  xdir = player.x - ex;
  ydir = player.y - ey;
  if (abs(player.x - ex) >= abs(player.y - ey)) {
    ydir = ydir / abs(xdir);
    if (xdir > 0) xdir = 1;
    if (xdir < 0) xdir = -1;
    } else {
    xdir = xdir / abs(ydir);
    if (ydir > 0) ydir = 1;
    if (ydir < 0) ydir = -1;
    }
  fx = ex + 0.5;
  fy = ey + 0.5;
  flag = ' ';
  while (flag == ' ') {
    fx += xdir;
    fy += ydir;
    x = fx;
    y = fy;
    if (in_sight(x,y) == '*') {
      show_sprite(x-player.map_x,y-player.map_y,100);
      delay(delay_ranged);
      show_spot(x,y);
      }
    if (player.map[x][y] == 21 || player.map[x][y] == 22) flag = '*';
    if (player.map[x][y] == 38) flag = '*';
    if (player.map[x][y] == 39) flag = '*';
    if (player.map[x][y] == 3) flag = '*';
    if (player.map[x][y] >= 600 && player.map[x][y] < 700) flag = '*';
    if (x == player.x && y == player.y) flag = '*';
    }
  if (x == player.x && y == player.y) {
    i = 50;
    i += 2 * (monster->level - (player.level / 2));
    if (i > 90) i = 90;
    if (i < 10) i = 10;
    i -= get_bonus(S_DDG) * 2;
    if (i > 90) i = 90;
    if (i < 10) i = 10;
    if (u_random(100) < get_dodge()) {
      msg("Dodged",7);
      i = 0;
      }
    if (u_random(100) < i) {
      if (napping == '*') {
        player.effect[PE_SLEEP] = 0;
        napping = ' ';
        }
      strcpy(elem,"");
      clear_prompt();
      noise(1000,100);
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(delay_hit);
        show_spot(x,y);
        show_player();
        }
      ring = 0;
      for (j=1; j<=19; j++) {
        if (player.invent[j].otype != O_NONE &&
            player.invent[j].effect == E_INTR &&
            player.invent[j].control == A_REFL) { ring = j; j=99; }
        }
      if (ring == 0) {
        i = u_random(monster->mana / 4 + 1);
        if ((monster->special & MS_FIRE_ATK) == MS_FIRE_ATK) {
          if (has_intrinsic(A_RFIR) || has_intrinsic(A_RELE) || player.effect[PE_FIRE] > 0) i /= 2;
          i = reduce_damage(i,S_FIR);
          strcpy(elem," fire ");
          }
        if ((monster->special & MS_COLD_ATK) == MS_COLD_ATK) {
          if (has_intrinsic(A_RCLD) || has_intrinsic(A_RELE) || player.effect[PE_COLD] > 0) i /= 2;
          i = reduce_damage(i,S_CLD);
          strcpy(elem," cold ");
          }
        if ((monster->special & MS_ELEC_ATK) == MS_ELEC_ATK) {
          if (has_intrinsic(A_RELC) || has_intrinsic(A_RELE) || player.effect[PE_ELEC] > 0) i /= 2;
          i = reduce_damage(i,S_ELC);
          strcpy(elem," electric ");
          }
        if ((monster->special & MS_ARCN_ATK) == MS_ARCN_ATK) {
          if (has_intrinsic(A_RDRK) || player.effect[PE_ARCN] > 0) i /= 2;
          i = reduce_damage(i,S_ARC);
          strcpy(elem," arcane ");
          }
        if ((monster->special & MS_PSIONIC) == MS_PSIONIC) {
          if (has_intrinsic(A_RPSI) || player.effect[PE_MIND]) i /= 4;
          strcpy(elem," psionic ");
          }
        i = magic_adjust(i);
        if (u_random(100) < (20+player.ability[5] * 20)) i /= 2;
        sprintf(buffer,"ZAP for %d%s",i,elem);
        msg(buffer,12);
        stats_take_damage(i);
        player.chp -= i;
        show_player();
        }
      if (ring != 0) {
        r_missile(monster->mana / 4 + 1);
        i = get_skill(8) + (player.level - monster->level);
        i += player.ability[10] * 5;
        if (i > 0) i = 75 + i;
        if (i > 98) i = 98;
        if (i < 0) {
          player.invent[ring].otype = O_NONE;
          clear_prompt();
          prompt("Ring Melted!!!");
          }
        if (u_random(101) > i) {
          player.invent[ring].otype = O_NONE;
          clear_prompt();
          prompt("Ring Melted!!!");
          }
        }
      show_player();
      show_side();
      }
    else {
      clear_prompt();
      prompt("Fizzle. . .");
      show_player();
      }
    }
  }
