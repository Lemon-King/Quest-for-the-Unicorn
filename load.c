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

void load(char* filename) {
  int i;
  int j;
  int save_file;
  int temp_file;
  char buffer[20];
  char ver[40];
  char *pChar;
  KNOW_TYPE known;
  strcat(filename,".sav");
  save_file = open(filename,O_RDONLY);
  if (save_file < 0) {
    printf("Fatal Error: Could not open %s\n",filename);
    exit(1);
    }
  read(save_file,buffer,sizeof(buffer));
  strcpy(ver,VERSION);
  pChar = strrchr(ver,'.');
  if (pChar != NULL) *pChar = 0;
  pChar = strrchr(buffer,'.');
  if (pChar != NULL) *pChar = 0;
  if (strcmp(buffer,ver) != 0) {
    printf("Fatal Error: Incorrect version in save file, aborting.\n");
    exit(1);
    }
  read(save_file,&player,sizeof(PLAYER_REC));
  temp_file = open("temp01.$$$",O_WRONLY | O_CREAT | O_TRUNC,0660);
  if (temp_file < 0) {
    printf("Fatal Error: Could not open temp01.$$$\n");
    exit(1);
    }
  for (i=1; i<=NO_OF_MAPS; i++) {
    read(save_file,&known,sizeof(KNOW_TYPE));
    lseek(temp_file,sizeof(KNOW_TYPE) * i,SEEK_SET);
    write(temp_file,&known,sizeof(KNOW_TYPE));
    }
  close(save_file);
  close(temp_file);
  for (i=1; i<=20; i++)
    if (player.invent[i].otype != O_NONE) {
      j=0;
      while (j>=0) {
        if (strcmp(player.invent[i].name,objects[j].name) == 0)
            player.invent[i].link = objects[j].link;
        if (objects[j].otype > 200) j = -1;
          else j++;
        }
      }
  for (i=1; i<=32; i++)
    if (player.pack[i].otype != O_NONE) {
      j=0;
      while (j>=0) {
        if (strcmp(player.pack[i].name,objects[j].name) == 0)
            player.pack[i].link = objects[j].link;
        if (objects[j].otype > 200) j = -1;
          else j++;
        }
      }
       
  }

