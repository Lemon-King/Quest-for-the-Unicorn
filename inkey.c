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

char inkey() {
  char key;
/*  while (keypressed() == 0) ; */
  key = readkey();
  if (key == 0 && keypressed() != 0) {
      key = readkey();
      switch (key) {
        case 'H': key = '8'; break;
        case 'P': key = '2'; break;
        case 'K': key = '4'; break;
        case 'M': key = '6'; break;
        case 'G': key = '7'; break;
        case 'I': key = '9'; break;
        case 'O': key = '1'; break;
        case 'Q': key = '3'; break;
        case ';': key = 33+128; break;
        case '<': key = 64+128; break;
        case '=': key = 35+128; break;
        case '>': key = 36+128; break;
        case '?': key = 37+128; break;
        case '@': key = 94+128; break;
        case 'A': key = 38+128; break;
        case 'B': key = 42+128; break;
        case 'C': key = 40+128; break;
        case 'D': key = 41+128; break;
        case 'T': key = 201; break;
        case 'U': key = 202; break;
        case 'V': key = 203; break;
        case 'W': key = 204; break;
        case 'X': key = 205; break;
        case 'Y': key = 206; break;
        case 'Z': key = 207; break;
        case '[': key = 208; break;
        case '\\': key = 209; break;
        case ']': key = 210; break;
        }
    }
  return key;
  }

