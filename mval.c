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

int mval(STRING13 instr) {
  int i,j;
  int add;
  j = 0;
  for (i=0; i<strlen(instr); i++) {
    add = -1;
    switch(instr[i]) {
      case '0':add = 0; break;
      case '1':add = 1; break;
      case '2':add = 2; break;
      case '3':add = 3; break;
      case '4':add = 4; break;
      case '5':add = 5; break;
      case '6':add = 6; break;
      case '7':add = 7; break;
      case '8':add = 8; break;
      case '9':add = 9; break;
      }
    if (add >= 0) {
      j *= 10;
      j += add;
      }
    }
  return j;
  }

