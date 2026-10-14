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

void check_scores() {
  int sc_file;
  SCORE_REC scores;
  if (exist("unicorn.sco")) {
    sc_file = open("unicorn.sco",O_RDONLY);
    read(sc_file,&scores,sizeof(SCORE_REC));
    close(sc_file);
    if (player.exp>scores.high_exp[player.class]) {
        scores.high_exp[player.class] = player.exp;
        strcpy(scores.high_name[player.class],player.name);
        strcpy(scores.high_title[player.class],player.title);
        score2 = player.class;
      }
    if (player.exp>scores.legend_exp[player.class]) {
        scores.legend_exp[player.class] = player.exp;
        strcpy(scores.legend_name[player.class],player.name);
        strcpy(scores.legend_title[player.class],player.title);
        score1 = player.class;
      }
    sc_file = open("unicorn.sco",O_WRONLY);
    write(sc_file,&scores,sizeof(SCORE_REC));
    close(sc_file);
    }
  }

