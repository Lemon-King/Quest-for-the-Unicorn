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

void arena_party_heal(int healer) {
  int ch;
  int diff;
  int i;
  int n;
  char buffer[128];
  n = player.party[healer].mana;
  n /= 20;
  if (n < 2) n = 2;
  n = n / 2 + u_random(n/2);
  if (n < 1) n = 1;
  ch = 0;
  diff = get_mhp() - player.chp;
  for (i=1; i<6; i++) {
    if (player.party[i].hp > 0) {
      if ((player.party[i].level * 9 - player.party[i].hp) > diff) {
        ch = i;
        diff = player.party[i].level * 9 - player.party[i].hp;
        }
      }
    }
  if (ch == 0) {
    if (player.chp < get_mhp()) {
      do_heal(n,0);
      sprintf(buffer,"%s healed you for %d",player.party[healer].name,n);
      msg(buffer,10);
      }
    }
  else {
      if (player.party[ch].hp < player.party[ch].level * 9) {
      do_heal(n,ch);
      sprintf(buffer,"%s healed %s for %d",player.party[healer].name,player.party[ch].name,n);
      msg(buffer,10);
      }
    }
  }

