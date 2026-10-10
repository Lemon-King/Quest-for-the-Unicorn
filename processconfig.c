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

void process_config(char* name) {
  int i;
  FILE *file;
  char filename[1024];
  char *pChar;
  char line[1024];
  strcpy(filename,name);
  strcat(filename,".cfg");
  file = fopen(filename,"r");
  if (file == NULL) return;
  while (fgets(line,1000,file) != NULL) {
    for (i=0; i<strlen(line); i++) {
      if (line[i] < 32) line[i] = 0;
      }
    pChar = line;
    while (*pChar == ' ') pChar++;
    process_option(pChar);
    }
  }
