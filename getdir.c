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

char get_dir(int* xdir,int* ydir) {
  char key;
  char flag;
  clear_prompt();
  prompt("Dir ?");
  flag = ' ';
  while (flag == ' ') {
    flag = '*';
    key = inkey();
    if (key < '1') flag = ' ';
    if (key > '9') flag = ' ';
    if (key == '5') flag = ' ';
    }
  *xdir = 0;
  *ydir = 0;
  switch (key) {
    case '2':*ydir = 1; break;
    case '8':*ydir = -1; break;
    case '6':*xdir = 1; break;
    case '4':*xdir = -1; break;
    case '7':*xdir = -1; *ydir = -1; break;
    case '9':*xdir = 1; *ydir = -1; break;
    case '1':*xdir = -1; *ydir = 1; break;
    case '3':*xdir = 1; *ydir = 1; break;
    }
  return key;
  }

