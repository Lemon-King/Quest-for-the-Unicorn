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

void stats_do_damage(int dam) {
  stats.counts[STAT_DAMAGE] += dam;
  stats.counts[STAT_HITS]++;
  if (dam > stats.counts[STAT_HARDEST_HIT]) stats.counts[STAT_HARDEST_HIT] = dam;
  }


