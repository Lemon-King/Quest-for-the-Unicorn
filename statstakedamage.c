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

void stats_take_damage(int dam) {
  stats.counts[STAT_DAMAGE_TAKEN] += dam;
  if (dam > stats.counts[STAT_HARDEST_TAKEN]) stats.counts[STAT_HARDEST_TAKEN] = dam;
  }


