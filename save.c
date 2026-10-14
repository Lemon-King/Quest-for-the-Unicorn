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

void save() {
  int i;
  int save_file;
  int temp_file;
  KNOW_TYPE known;
  char filename[80];
  char buffer[20];
  gotoxy(1,1); textcolor(14);
  strcpy(filename,"");
  while (strlen(filename)<=1) {
    gotoxy(1,1); textcolor(14);
    txt_write("Filename to save under (No Extension) ?");
    readln(filename);
    }
  strcat(filename,".sav");
  save_file = open(filename,O_WRONLY | O_CREAT | O_TRUNC,0660);
  if (save_file < 0) {
    printf("Fatal Error: Could not open %s\n",filename);
    exit(1);
    }
  strcpy(buffer,VERSION);
  write(save_file,buffer,sizeof(buffer));
  write(save_file,&player,sizeof(PLAYER_REC));
  temp_file = open("temp01.$$$",O_RDONLY);
  if (temp_file < 0) {
    printf("Fatal Error: Could not open temp01.$$$\n");
    exit(1);
    }
  for (i=1; i<=NO_OF_MAPS; i++) {
    lseek(temp_file,sizeof(KNOW_TYPE) * i,SEEK_SET);
    read(temp_file,&known,sizeof(KNOW_TYPE));
    write(save_file,&known,sizeof(KNOW_TYPE));
    }
  close(save_file);
  close(temp_file);
  }

