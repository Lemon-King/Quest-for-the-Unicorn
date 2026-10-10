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

void add_gold(int32_t g) {
  int32_t m;
  int32_t a;
  a = (g / 10000);
  g -= (a * 10000);
  m = (g / 100);
  g -= (m * 100);
  player.gold_coins += g;
  player.mithril_coins += m;
  player.adamantite_coins += a;
  }

void sub_gold(int32_t g) {
  player.gold_coins -= g;
  while (player.gold_coins < 0) {
    player.gold_coins += 100;
    player.mithril_coins--;
    }
  while (player.mithril_coins < 0) {
    player.mithril_coins += 100;
    player.adamantite_coins--;
    }
  if (player.gold_coins < 0 || player.mithril_coins < 0 || player.adamantite_coins < 0) {
    player.gold_coins = 0;
    player.mithril_coins = 0;
    player.adamantite_coins = 0;
    }
  }
