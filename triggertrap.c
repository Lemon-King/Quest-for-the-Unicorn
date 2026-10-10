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

void trigger_trap(int x,int y,int trap_type) {
  int dmg;
  int rx,ry;
  NPC_REC* monster;
  monster = get_monster(x,y);
  if (monster != NULL) monster->prev = 7;
  if (trap_type == 951 || trap_type == 952 || trap_type == 953) {        /* Small explosive trap */
    show_sprite(x-player.map_x,y-player.map_y,80);
    delay(delay_trap);
    show_spot(x,y);
    msg("Explosive trap triggered",12);
    dmg = 5 + u_random(4);
    monster = get_monster(x,y);
    if (monster != NULL) {
      monster->hp -= dmg;
      if (monster->hp <= 0) {
        dead_monster(monster,'Y',x,y);
        }
      }
    show_spot(x,y);
    }
  if (trap_type == 952 || trap_type == 953) {                            /* Large explosive trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 7 + u_random(6);
        if (monster != NULL) {
          monster->hp -= dmg;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 7 + u_random(6);
          msg("OUCH!!!",12);
          player.chp -= dmg;
          show_side();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 953) {                                               /* Huge explosive trap */
    for (rx=x-2; rx<=x+2; rx++)
      for (ry=y-2; ry<=y+2; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 9 + u_random(8);
        if (monster != NULL) {
          monster->hp -= dmg;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 7 + u_random(6);
          msg("OUCH!!!",12);
          player.chp -= dmg;
          show_side();
          }
      }
    delay(delay_trap);
    for (rx=x-2; rx<=x+2; rx++)
      for (ry=y-2; ry<=y+2; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 954) {                            /* Fire trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 10 + u_random(10);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= figure_damage(dmg,MS_FIRE_ATK,monster);
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 10 + u_random(10);
          msg("BURNING!!!",12);
          player.effect[PE_DOT] += dmg;
          show_side();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 955) {                            /* Frost trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 10 + u_random(10);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= figure_damage(dmg,MS_COLD_ATK,monster);
          monster->sleep = -dmg;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 10 + u_random(10);
          player.effect[PE_ROOT] += dmg;
          msg("ROOTED!!!",12);
          player.chp -= dmg;
          show_side();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 956) {                            /* Electric trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 10 + u_random(10);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= figure_damage(dmg,MS_ELEC_ATK,monster);
          monster->mana /= 2;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 10 + u_random(10);
          player.cmana /= 2;
          msg("ZAP!!!",12);
          player.chp -= dmg;
          show_side();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 957) {                            /* Sleep trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 5 + u_random(4);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= dmg;
          monster->sleep = dmg;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 5 + u_random(4);
          player.effect[PE_SLEEP] += dmg + player.diff + (player.d_level / 3);
          msg("SLEPT!!!",12);
          player.chp -= dmg;
          show_side();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 958) {                            /* Fear trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 5 + u_random(4);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= dmg;
          monster->fear += dmg;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 5 + u_random(4);
          player.effect[PE_FEAR] += dmg + player.diff + (player.d_level / 3);
          msg("SCARED!!!",12);
          player.chp -= dmg;
          show_side();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 959) {                            /* Blindness trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 5 + u_random(4);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= dmg;
          monster->blind += dmg;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 5 + u_random(4);
          player.effect[PE_BLIND] += dmg + player.diff + (player.d_level / 3);
          msg("BLIND!!!",12);
          player.chp -= dmg;
          show_side();
          show_map();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 960) {                            /* Poison trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 5 + u_random(4);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= dmg;
          monster->poison += dmg*5;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 5 + u_random(4);
          player.effect[PE_POISON] += dmg * 5;
          msg("POISONED!!!",12);
          player.chp -= dmg;
          show_side();
          show_map();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
  if (trap_type == 961) {                            /* Confusion trap */
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++) {
        monster = get_monster(rx,ry);
        show_sprite(rx-player.map_x,ry-player.map_y,80);
        dmg = 5 + u_random(4);
        if (rx == x && ry == y) dmg *= 2;
        if (monster != NULL) {
          monster->hp -= dmg;
          monster->confused += dmg;
          if (monster->hp <= 0) {
            dead_monster(monster,'Y',rx,ry);
            }
          }
        if (rx == player.x && ry == player.y) {
          dmg = 5 + u_random(4);
          player.effect[PE_CONFUSED] += dmg + player.diff + (player.d_level / 3);
          msg("CONFUSED!!!",12);
          player.chp -= dmg;
          show_side();
          show_map();
          }
      }
    delay(delay_trap);
    for (rx=x-1; rx<=x+1; rx++)
      for (ry=y-1; ry<=y+1; ry++)
        show_spot(rx,ry);
    }
    show_player();
  }

