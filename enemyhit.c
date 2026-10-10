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

  void enemy_hit(int x,int y) {
    int i;
    int hit;
    char buffer[20];
    char elem[20];
    int amt;
    NPC_REC* monster;
    monster = get_monster(x,y);
    if ((monster->special2 & M2_PACIFIED) != 0) return;
    i = 25;
    i += 2 * (monster->level - (player.level / 2));
    i = i - player.ability[2] * 4;
    i -= get_bonus(S_DDG) * 2;
    if (player.effect[PE_PROT] > 0) i -= player.effect[PE_APROT];
    if (player.effect[PE_SLEEP] > 0) i += 50;
    if (player.effect[PE_BLIND] > 0) i += 25;
    if (player.effect[PE_ROOT] > 0) i += 25;
    if (monster->blind > 0) i -= 25;
    if (monster->fear > 0) i -= 10;
    i -= u_random(get_dex() / 5);
    if (i < 10) i = 10;
    if (i > 90) i = 90;
    if (u_random(100) < get_dodge()) {
      msg("Dodged",7);
      i = 0;
      }
    clear_prompt();
    if (u_random(100) < i) {
      if (napping == '*') {
        player.effect[PE_SLEEP] = 0;
        napping = ' ';
        }
      strcpy(elem,"");
      show_sprite(player.x-player.map_x,player.y-player.map_y,80);
      delay(delay_hit);
      show_spot(player.x,player.y);
      show_player();
      noise(750,100);
      i = monster->attack;
      i = u_random(i) + 1;
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
      if ((monster->special & MS_ROOT) == MS_ROOT) {
        if (player.effect[PE_ROOT] == 0) {
                 hit = 50 + ((monster->level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Rooted!!!",9);
                   if (player.effect[PE_ROOT] == 0)
                     player.effect[PE_ROOT] = u_random(monster->level);
                   if (player.effect[PE_ROOT] < 0) player.effect[PE_ROOT] = 0;
                   show_player();
                   }
                   show_side();
                 }
          }
      if ((monster->special & MS_SLEEP) == MS_SLEEP) {
        if (!has_intrinsic(A_NOSL)  && player.effect[PE_SLEEP] == 0) {
                 hit = 50 + ((monster->level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (has_intrinsic(A_NOSL)) hit = 0;
                 if (has_intrinsic(A_RSSL) && u_random(100) < 50) hit = 0;
                 if (player.effect[PE_SLEEP] > 0) hit = 0;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Slept!!!",9);
                   amt = u_random(monster->level);
                   if (has_intrinsic(A_RSSL)) amt /= 2;
                   if (amt < 1) amt = 1;
                   player.effect[PE_SLEEP] = amt;
                   if (player.effect[PE_SLEEP] < 0) player.effect[PE_SLEEP] = 0;
                   show_player();
                   }
                   show_side();
                 }
          }
      if ((monster->special & MS_POISON) == MS_POISON) {
        if (!has_intrinsic(A_NOPS)) {
                 hit = 50 + ((monster->level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (has_intrinsic(A_NOPS)) hit = 0;
                 if (has_intrinsic(A_RSPS) && u_random(100) < 50) hit = 0;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Poisoned!!!",13);
                   stats.counts[STAT_POISONED]++;
                   amt = u_random(monster->attack) * 20;
                   if (has_intrinsic(A_RSPS)) amt /= 2;
                   if (amt < 1) amt = 1;
                   player.effect[PE_POISON] += amt;
                   if (player.effect[PE_POISON] < 0) player.effect[PE_POISON] = 0;
                   show_side();
                   }
                 }
        }
      if ((monster->special & MS_FEAR) == MS_FEAR) {
        if (!has_intrinsic(A_NOFR)) {
                 hit = 50 + ((monster->level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (has_intrinsic(A_NOFR)) hit = 0;
                 if (has_intrinsic(A_RSFR) && u_random(100) < 50) hit = 0;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Scared!!!",9);
                   amt = 5 + u_random(monster->level);
                   if (has_intrinsic(A_RSFR)) amt /= 2;
                   if (amt < 1) amt = 1;
                   player.effect[PE_FEAR] = amt;
                   if (player.effect[PE_FEAR] < 0) player.effect[PE_FEAR] = 0;
                   show_side();
                   }
                 }
        }
      if ((monster->special & MS_CONFUSION) == MS_CONFUSION) {
                 hit = 50 + ((monster->level - player.level) * 5) -
                            player.ability[5] * 2;
                 if (u_random(100) < hit) {
                   clear_prompt();
                   msg("Confused!!!",9);
                   player.effect[PE_CONFUSED] = 5 + u_random(monster->level);
                   if (player.effect[PE_CONFUSED] < 0) player.effect[PE_CONFUSED] = 0;
                   show_side();
                   }
        }
      if ((monster->special2 & M2_DRAIN) == M2_DRAIN && has_intrinsic(A_NDRN) == 0) {
                 if (u_random(100) < 10) {
                   clear_prompt();
                   msg("You feel weaker!!!",12);
                   player.level--;
                   player.chp -= 8;
                   player.mhp -= 8;
                   if (player.level <= 0) player.chp = 0;
                   show_side();
                   }
        }
      i = damage_reduction(i);
      if (i<1) i = 1;
      if ((monster->special & MS_DOT) == MS_DOT) {
        msg("DOT taken",12);
        player.effect[PE_DOT] += i;
        } else {
        sprintf(buffer,"OUCH! for %d%s",i,elem);
        msg(buffer,12);
        player.chp -= i;
        stats_take_damage(i);
        if (player.chp < 0) player.chp = 0;
        if (player.chp > 0 && u_random(10) == 5) add_skill(SK_SURVIVE,1);
        }
      show_side();
      }
    else {
      msg("Missed . . .",1);
      if (u_random(10) <= 5) add_skill(SK_COMBAT,1);
      noise(100,100);
      }
    } /* void enemy_hit(int x,int y) */

