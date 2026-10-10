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

/* ************************************************************* */
/* ***** Who - 0=player, >0=party member, <0=arena monster ***** */
/* ***** dmg is used if weapon is null                     ***** */
/* ***** Returns damage done to attacker as result of      ***** */
/* *****         attack                                    ***** */
/* ************************************************************* */

int meleehit(int who,OBJECT_REC* weapon,int dmg,NPC_REC* target,char hand) {
  int i;
  if (target != NULL && target->speed < 0) { target->speed = -target->speed; };
  if (target != NULL && (target->special2 & M2_PACIFIED) != 0) target->special2 -= M2_PACIFIED;
  if (who == 0) {
    i = 10;
    if (target->number >= 90) {
      target->level = player.level + 10;
      if (target->level < 30) target->level = 30;
      }
    i += 2 * (player.level - target->level);
    if (i < -50) i = -50;
    i += get_hit() * 2.5;
    i += get_skill(SK_COMBAT) / 2;
    if (weapon != NULL) {
      if (is_weapon(weapon) && weapon->otype != O_WAND && get_skill(weapon->skill) >= 5) i += get_skill(weapon->skill) / 2;
      if (is_weapon(weapon) && weapon->otype != O_WAND && get_skill(weapon->skill) < 5) {
        if (get_skill(weapon->skill) == 0) i = (int)(i * 0.16);
        if (get_skill(weapon->skill) == 1) i = (int)(i * 0.32);
        if (get_skill(weapon->skill) == 2) i = (int)(i * 0.48);
        if (get_skill(weapon->skill) == 3) i = (int)(i * 0.64);
        if (get_skill(weapon->skill) == 4) i = (int)(i * 0.80);
        }
      }
    if (target->fear > 0) i += 10;
    if (target->confused > 0) i += 10;
    if (target->sleep > 0) i += 75;
    if (i < 10) i = 10;
    if (i > 90) i = 90;
    if (triad_equipped() && fighting_final_boss(target)) i=100;
    clear_prompt();
    /* ********************************* */
    /* ***** Check and process hit ***** */
    /* ********************************* */
    if (u_random(100) < i) {
      if (is_weapon(weapon) && weapon->otype != O_WAND) {
        add_skill(weapon->skill,1);
        if (u_random(10) <= 5) add_skill(SK_COMBAT,1);
        }
      dmg = (hand == 'L' || hand == 'l') ? offhand_weapon() / 2 : get_weapon();
      if (is_weapon(weapon) && weapon->otype == O_WAND) dmg = weapon->weight;
      if (classes[player.class-1].flags & CF_MONK) {
        if (u_random(100) < player.level*2) {
          msg("Paralyzed!",14); noise(1000,100); delay(delay_hit);
          target->sleep = u_random(2*(player.level - target->level));
          show_spot(player.x,player.y);
          if (u_random(500) < player.level) {
            msg("Killed!",15); noise(1000,100); delay(delay_hit);
            target->hp = 0;
            }
          }
        }
      i = max_damage(weapon,target,dmg);
      i = (i != 0) ? u_random(i / 2) + 1 : 0;
      if (i > 0 && player.effect[PE_GIANT] > 0) i += (i / 2);
      if (triad_equipped() && fighting_final_boss(target)) {
        i = target->hp / 2;
        if (i < 20) i = 20;
        }
    
      aoe(player.x,player.y,E_DAMG,0,-i,0,0,0,-100);
      }
    else {
      msg("Miss . . .",9);
      stats.counts[STAT_MISSES]++;
      noise(200,100);
      }
    }
  return 0;
  }

