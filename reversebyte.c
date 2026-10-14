/*
 *******************************************************************
 *** This software is copyright 1985-2007 by Michael H Riley     ***
 *** You have permission to use, modify, copy, and distribute    ***
 *** this software so long as this copyright notice is retained. ***
 *** This software may not be used in commercial applications    ***
 *** without express written permission from the author.         ***
 *******************************************************************
*/

#include "header.h"

byte reverseByte(byte in) {
  byte ret;
  ret = ((in & 128) >> 7) | ((in & 64) >> 5) | ((in & 32) >> 3) |
        ((in & 16) >> 1)  | ((in & 8) << 1)  | ((in & 4) << 3)  |
        ((in & 2) << 5)   | ((in & 1) << 7);
  return ret;
  }

