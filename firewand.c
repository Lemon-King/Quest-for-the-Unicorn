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

void fire_wand(int damage) {
  int  x,y;
  int  i;
  char buffer[20];
  NPC_REC* monster;
  OBJECT_REC* weapon;
  target(100,0,-1);
  x = target_x;
  y = target_y;
  weapon = &(player.invent[I_RHND]);
  monster = get_monster(x,y);
  if (monster != NULL) {
    i = 10;
    i += 2 * (player.level - monster->level);
    if (i < -50) i = -50;
    i += get_hit() * 2.5;
    if (weapon != NULL) {
      if (is_weapon(weapon) && get_skill(weapon->skill) >= 5) i += get_skill(weapon->skill) / 2;
      if (is_weapon(weapon) && get_skill(weapon->skill) < 5) {
        if (get_skill(weapon->skill) == 0) i = (int)(i * 0.16);
        if (get_skill(weapon->skill) == 1) i = (int)(i * 0.32);
        if (get_skill(weapon->skill) == 2) i = (int)(i * 0.48);
        if (get_skill(weapon->skill) == 3) i = (int)(i * 0.64);
        if (get_skill(weapon->skill) == 4) i = (int)(i * 0.80);
        }
      }
    if (monster->fear > 0) i += 10;
    if (monster->sleep > 0) i += 75;
    if (u_random(100) < i) {
      clear_prompt();
      noise(1000,100);
      if (weapon != NULL) add_skill(weapon->skill,1);
        else add_skill(SK_MAGIC,1);
      if ((monster->special & MS_FRIENDLY) == MS_FRIENDLY) {
        player.align -= 20;
        monster->special -= MS_FRIENDLY;
        if (player.align < 0) player.align = 0;
        }
      if (in_sight(x,y) == '*') {
        show_sprite(x-player.map_x,y-player.map_y,100);
        delay(delay_hit);
        show_spot(x,y);
        }
      i = u_random(damage) + 1;
      if (u_random(100) < get_crit()) {
        i *= 2;
        stats.counts[STAT_CRITS]++;
        sprintf(buffer,"CRIT for %d",i);
        } else sprintf(buffer,"HIT for %d",i);
      msg(buffer,4);
      stats_do_damage(i);
      monster->hp -= i;
      i=monster->hp;
      if (i <= 0) {
        clear_prompt();
        dead_monster(monster,'Y',x,y);
        show_spot(x,y);
        if ((monster->special & MS_FRIENDLY) == MS_FRIENDLY) {
          player.align -= 20;
          if (player.align < 0) player.align = 0;
          }
        show_side();
        }

      }
    else {
      clear_prompt();
      prompt("Missed. . .");
      stats.counts[STAT_MISSES]++;
      }
    }
  }
