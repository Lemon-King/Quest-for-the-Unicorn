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
#include <sys/types.h>

u_int32_t taps;
u_int32_t reg;

void Shift(int count) {
  int i;
  u_int32_t tmp;
  for (i = 0; i < count; i++) {
    tmp = (reg & taps);
    tmp = (tmp & 0xffff) ^ ((tmp >> 16) & 0xffff);
    tmp = (tmp & 0xff) ^ ((tmp >> 8) & 0xff);
    tmp = (tmp & 0xf) ^ ((tmp >> 4) & 0xf);
    tmp = (tmp & 0x3) ^ ((tmp >> 2) & 0x3);
    tmp = (tmp & 0x1) ^ ((tmp >> 1) & 0x1);
    tmp <<= 31;
    reg >>= 1;
    reg |= tmp;
    if (reg == 0) reg = 0x08000000;
    if (reg == 0xffffffff) reg = 0x08000000;
    }
  }

void Rcs_Seed(u_int32_t s) {
  reg = s;
/*
#ifdef DEBUG
  sprintf(debugbuffer,"Rcs_Seed: Seed = %ld\n",s);
  debugLog(debugbuffer);
#endif
*/
  taps = ((1 << 24) | (1 << 21) | (1 << 2) | (1 << 0));
  Shift(32);
  }

int Rcs_Random(int range) {
  int ret;
  ret = (reg & 0x7fffffff) % range;
  Shift(33);
/*
#ifdef DEBUG
  sprintf(debugbuffer,"Rcs_Random: Random = %d\n",ret);
  debugLog(debugbuffer);
#endif
*/
  return ret;
  }
