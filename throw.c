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

int adjust_thrown_damage(int dmg) {
  int ret;
  double tmp;
  double wtmp;
  tmp = dmg;
  tmp *= (get_attack_power() / 100.0 + 1.0);
  wtmp = 1.0;
  if (get_skill(SK_THROWN) < 5) {
    if (get_skill(SK_THROWN) == 0) wtmp = 0.16;
    if (get_skill(SK_THROWN) == 1) wtmp = 0.32;
    if (get_skill(SK_THROWN) == 2) wtmp = 0.48;
    if (get_skill(SK_THROWN) == 3) wtmp = 0.64;
    if (get_skill(SK_THROWN) == 4) wtmp = 0.80;
    }
  if (get_skill(SK_THROWN) >= 5) wtmp = (get_skill(SK_THROWN) - 5) / 100.0 + 1.0;
  tmp *= wtmp;
  wtmp = (get_skill(SK_COMBAT) / 2) / 100.0 + 1.0;
  tmp *= wtmp;
  ret = tmp;
  return ret;
  }

void throw(char hnd) {
  int hand;
  int damage;
  byte key;
  hand = 0;
  if (hnd == 'L') hand = I_LHND;
  else if (hnd == 'R') hand = I_RHND;
  else {
    clear_prompt();
    prompt("<L>eft, or <R>ight hand ?");
    key = inkey();
    if (key == 'l' || key == 'L') hand = I_LHND;
    if (key == 'r' || key == 'R') hand = I_RHND;
    }
  if (player.invent[hand].otype == O_NONE) {
    msg("Hand is empty",14);
    return;
    }
  if (hand != 0) {
    if (player.invent[hand].otype == O_DAGR) damage = objects[1].damage * 4;
    else if (player.invent[hand].otype == O_THRN) {
      damage = adjust_thrown_damage(player.invent[hand].damage);
      if (player.invent[hand].charges > 0) {
        player.invent[hand].charges--;
        if (player.invent[hand].charges == 0) player.invent[hand].otype = O_NONE;
        }
      fire(damage,NULL);
      return;
      }
    else damage = 8;
    fire(damage,&(player.invent[hand]));
    if (hand == I_RHND) player.weapon = 0;
    player.invent[hand].otype = O_NONE;
    }
  } /* void throw() */

