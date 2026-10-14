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

void show_scores() {
  int i;
  char key;
  int sc_file;
  char buffer[80];
  SCORE_REC scores;
  textmode(3);
  if (exist("unicorn.sco")) {
    sc_file = open("unicorn.sco",O_RDONLY);
    read(sc_file,&scores,sizeof(SCORE_REC));
    close(sc_file);
    }
  else { 
    strcpy(scores.legend_name[1],"Elan of Marduk");
    strcpy(scores.legend_title[1],"Lord");
    scores.legend_exp[1] = 836e3;
    strcpy(scores.legend_name[2],"Gawaine of Radon");
    strcpy(scores.legend_title[2],"Paladin");
    scores.legend_exp[2] = 3532e3;
    strcpy(scores.legend_name[3],"Jason Thornblade");
    strcpy(scores.legend_title[3],"Ranger Lord");
    scores.legend_exp[3] = 3841e3;
    strcpy(scores.legend_name[4],"Amber of the Vale");
    strcpy(scores.legend_title[4],"High Priestess");
    scores.legend_exp[4] = 1573e3;
    strcpy(scores.legend_name[5],"Kesthler of the Wood");
    strcpy(scores.legend_title[5],"The Great Druid");
    scores.legend_exp[5] = 38963515;
    strcpy(scores.legend_name[6],"Nina the Wise");
    strcpy(scores.legend_title[6],"Wizardess");
    scores.legend_exp[6] = 48083e3;
    strcpy(scores.legend_name[7],"Galter the Feared");
    strcpy(scores.legend_title[7],"Grandfather of Assassins");
    scores.legend_exp[7] = 277837e4;
    strcpy(scores.legend_name[8],"Rasper of Solat");
    strcpy(scores.legend_title[8],"Hierophant of the Cabal");
    scores.legend_exp[8] = 100769e4;
    strcpy(scores.legend_name[9],"Ramoon of Talgon");
    strcpy(scores.legend_title[9],"Cavalier");
    scores.legend_exp[9] = 39748460;
    strcpy(scores.legend_name[10],"Arslon");
    strcpy(scores.legend_title[10],"Grand Master of Flowers");
    scores.legend_exp[10] = 1494197000;
    strcpy(scores.legend_name[11],"Marduk");
    strcpy(scores.legend_title[11],"King of Halkanar");
    scores.legend_exp[11] = 1550292000;
    for (i=1; i<=11; i++) {
      scores.high_exp[i] = 0;
      strcpy(scores.high_name[i]," ");
      strcpy(scores.high_title[i]," ");
      }
    sc_file = open("unicorn.sco",O_WRONLY | O_CREAT | O_TRUNC,0660);
    write(sc_file,&scores,sizeof(SCORE_REC));
    close(sc_file);
    }
  textcolor(10); gotoxy(1,1); txt_write("Legends:"); textcolor(2);
  gotoxy(5,2); txt_write("Fighter    :");
  gotoxy(5,3); txt_write("Paladin    :");
  gotoxy(5,4); txt_write("Ranger     :");
  gotoxy(5,5); txt_write("Cleric     :");
  gotoxy(5,6); txt_write("Druid      :");
  gotoxy(5,7); txt_write("Wizard     :");
  gotoxy(5,8); txt_write("Assassin   :");
  gotoxy(5,9); txt_write("Hierophant :");
  gotoxy(5,10); txt_write("Cavalier   :");
  gotoxy(5,11); txt_write("Monk       :");
  gotoxy(5,12); txt_write("Noble      :");
  textcolor(10); gotoxy(1,14); txt_write("High Scores:"); textcolor(2);
  gotoxy(5,15); txt_write("Fighter    :");
  gotoxy(5,16); txt_write("Paladin    :");
  gotoxy(5,17); txt_write("Ranger     :");
  gotoxy(5,18); txt_write("Cleric     :");
  gotoxy(5,19); txt_write("Druid      :");
  gotoxy(5,20); txt_write("Wizard     :");
  gotoxy(5,21); txt_write("Assassin   :");
  gotoxy(5,22); txt_write("Hierophant :");
  gotoxy(5,23); txt_write("Cavalier   :");
  gotoxy(5,24); txt_write("Monk       :");
  gotoxy(5,25); txt_write("Noble      :");
  for (i=1; i<=11; i++) {
    if (score1 == i) textcolor(11); else textcolor(14);
    gotoxy(18,i+1);
    sprintf(buffer,"%10.0f",scores.legend_exp[i]);
    txt_write(buffer);
    gotoxy(30,i+1); txt_write(scores.legend_name[i]);
    gotoxy(55,i+1); txt_write(scores.legend_title[i]);
    }
  for (i=1; i<=11; i++) {
    if (score2 == i) textcolor(11); else textcolor(14);
    gotoxy(18,i+14);
    sprintf(buffer,"%10.0f",scores.high_exp[i]);
    txt_write(buffer);
    gotoxy(30,i+14); txt_write(scores.high_name[i]);
    gotoxy(55,i+14); txt_write(scores.high_title[i]);
    }
  key = 0;
  while (key != 13) key = inkey();
  }

