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

#ifdef ANNIV
#include "./Mhr/writewinner.c"
#endif

void final_score(char cause) {
  int i,j;
  if (player.effect[PE_HEROIC] < 0) return;
  death_position = -1;
  hall_position = -1;
  if (cause == 'W') {
#ifdef ANNIV
    write_winner();
#endif
    j=-1;
    for (i=0; i<MAX_HALL_OF_FAME; i++)
      if (player.time_played < hall_of_fame[i].time_played || hall_of_fame[i].time_played == 0) {
        j = i; i = MAX_HALL_OF_FAME+1;
        }
    if (j >= 0) {
      for (i=MAX_HALL_OF_FAME-1; i>j; i--)
        hall_of_fame[i] = hall_of_fame[i-1];
      hall_position = j;
      strcpy(hall_of_fame[j].name,player.name);
      hall_of_fame[j].exp = player.exp;
      hall_of_fame[j].level = player.level;
      hall_of_fame[j].cause = 'W';
      hall_of_fame[j].class = player.class;
      hall_of_fame[j].time_played = player.time_played;
      hall_of_fame[j].mode = 'N';
      if (player.effect[PE_HEROIC] == 2) hall_of_fame[j].mode = 'H';
      if (player.effect[PE_HEROIC] == 4) hall_of_fame[j].mode = 'E';
      num_hall_of_fame++;
      save_scores();
      }
    }
  else {
    j=-1;
    for (i=0; i<MAX_FINAL_SCORES; i++)
      if (player.exp > final_scores[i].exp) { j = i; i = MAX_FINAL_SCORES+1; }
    if (j >= 0) {
      for (i=MAX_FINAL_SCORES-1; i>j; i--)
        final_scores[i] = final_scores[i-1];
      death_position = j;
      strcpy(final_scores[j].name,player.name);
      final_scores[j].exp = player.exp;
      final_scores[j].level = player.level;
      final_scores[j].cause = cause;
      final_scores[j].class = player.class;
      final_scores[j].time_played = player.time_played;
      final_scores[j].mode = 'N';
      if (player.effect[PE_HEROIC] == 2) final_scores[j].mode = 'H';
      if (player.effect[PE_HEROIC] == 4) final_scores[j].mode = 'E';
      num_final_scores++;
      score_position = death_position;
      save_scores();
      }
    }
  }

void check_scores() {
  if (player.effect[PE_HEROIC] < 0) return;
  if (player.exp>high_scores[player.class-1].exp) {
      high_scores[player.class-1].exp = player.exp;
      strcpy(high_scores[player.class-1].name,player.name);
      strcpy(high_scores[player.class-1].title,player.title);
      score2 = player.class;
    }
  if (player.exp>legend_scores[player.class-1].exp) {
      legend_scores[player.class-1].exp = player.exp;
      strcpy(legend_scores[player.class-1].name,player.name);
      strcpy(legend_scores[player.class-1].title,player.title);
      score1 = player.class;
    }
  save_scores();
  }

