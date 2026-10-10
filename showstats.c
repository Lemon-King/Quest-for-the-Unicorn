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

void show_stats() {
  int key;
  char buffer[80];
  double d1,d2;
  struct timeval tim;
  gettimeofday(&tim,NULL);
  end_time = tim.tv_sec;
  textmode(3);
  textcolor(10); gotoxy(31,1); txt_write("Player Statistics:");

  textcolor(2); gotoxy(3,3); txt_write("Monsters Killed:");
  sprintf(buffer,"%d",stats.counts[STAT_MOBS_KILLED]);
  textcolor(14); gotoxy(26,3); txt_write(buffer);

  textcolor(2); gotoxy(3,4); txt_write("Gold Looted:");
  sprintf(buffer,"%d",stats.counts[STAT_GOLD_LOOTED]);
  textcolor(14); gotoxy(26,4); txt_write(buffer);

  textcolor(2); gotoxy(3,5); txt_write("Time Played:");
  convert_time(player.time_played+(end_time - start_time),buffer);
  textcolor(14); gotoxy(26,5); txt_write(buffer);

  textcolor(2); gotoxy(3,6); txt_write("Steps Taken:");
  sprintf(buffer,"%d",stats.counts[STAT_STEPS_TAKEN]);
  textcolor(14); gotoxy(26,6); txt_write(buffer);

  textcolor(2); gotoxy(3,7); txt_write("Hours Napped:");
  sprintf(buffer,"%d",stats.counts[STAT_HOURS_NAPPED]);
  textcolor(14); gotoxy(26,7); txt_write(buffer);

  textcolor(2); gotoxy(3,8); txt_write("Alcohol Consumed:");
  sprintf(buffer,"%d",stats.counts[STAT_ALCOHOL_DRANK]);
  textcolor(14); gotoxy(26,8); txt_write(buffer);

  d2 = stats.counts[STAT_COMMONS] + stats.counts[STAT_UNCOMMONS] +
       stats.counts[STAT_RARES] + stats.counts[STAT_VERY_RARES] +
       stats.counts[STAT_ULTRA_RARES];
  d1 = stats.counts[STAT_COMMONS];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(3,9); txt_write("Commons Picked Up:");
  sprintf(buffer,"%d",stats.counts[STAT_COMMONS]);
  textcolor(14); gotoxy(26,9); txt_write(buffer);
  sprintf(buffer,"(%5.2f%%)",d1);
  gotoxy(34,9); txt_write(buffer);

  d1 = stats.counts[STAT_UNCOMMONS];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(3,10); txt_write("Uncommons Picked Up:");
  sprintf(buffer,"%d",stats.counts[STAT_UNCOMMONS]);
  textcolor(14); gotoxy(26,10); txt_write(buffer);
  sprintf(buffer,"(%5.2f%%)",d1);
  gotoxy(34,10); txt_write(buffer);

  d1 = stats.counts[STAT_RARES];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(3,11); txt_write("Rares Picked Up:");
  sprintf(buffer,"%d",stats.counts[STAT_RARES]);
  textcolor(14); gotoxy(26,11); txt_write(buffer);
  sprintf(buffer,"(%5.2f%%)",d1);
  gotoxy(34,11); txt_write(buffer);

  d1 = stats.counts[STAT_VERY_RARES];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(3,12); txt_write("Very Rares Picked Up:");
  sprintf(buffer,"%d",stats.counts[STAT_VERY_RARES]);
  textcolor(14); gotoxy(26,12); txt_write(buffer);
  sprintf(buffer,"(%5.2f%%)",d1);
  gotoxy(34,12); txt_write(buffer);

  d1 = stats.counts[STAT_ULTRA_RARES];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(3,13); txt_write("Ultra Rares Picked Up:");
  sprintf(buffer,"%d",stats.counts[STAT_ULTRA_RARES]);
  textcolor(14); gotoxy(26,13); txt_write(buffer);
  sprintf(buffer,"(%5.2f%%)",d1);
  gotoxy(34,13); txt_write(buffer);

  textcolor(2); gotoxy(3,14); txt_write("Levels Cleared:");
  sprintf(buffer,"%d",stats.counts[STAT_LEVELS_CLEARED]);
  textcolor(14); gotoxy(26,14); txt_write(buffer);

  textcolor(2); gotoxy(3,15); txt_write("Dungeons Cleared:");
  sprintf(buffer,"%d",stats.counts[STAT_DUNGEON_CLEARED]);
  textcolor(14); gotoxy(26,15); txt_write(buffer);

  textcolor(2); gotoxy(3,16); txt_write("Scrolls Read:");
  sprintf(buffer,"%d",stats.counts[STAT_SCROLLS_READ]);
  textcolor(14); gotoxy(26,16); txt_write(buffer);

  textcolor(2); gotoxy(3,17); txt_write("Potions Drunk:");
  sprintf(buffer,"%d",stats.counts[STAT_POTIONS_DRUNK]);
  textcolor(14); gotoxy(26,17); txt_write(buffer);

  textcolor(2); gotoxy(3,18); txt_write("Meals Eaten:");
  sprintf(buffer,"%d",stats.counts[STAT_MEALS_EATEN]);
  textcolor(14); gotoxy(26,18); txt_write(buffer);

  textcolor(2); gotoxy(3,19); txt_write("Damage Dealt:");
  sprintf(buffer,"%d",stats.counts[STAT_DAMAGE]);
  textcolor(14); gotoxy(26,19); txt_write(buffer);

  textcolor(2); gotoxy(3,20); txt_write("Hardest Hit:");
  sprintf(buffer,"%d",stats.counts[STAT_HARDEST_HIT]);
  textcolor(14); gotoxy(26,20); txt_write(buffer);

  textcolor(2); gotoxy(3,21); txt_write("Damage Taken:");
  sprintf(buffer,"%d",stats.counts[STAT_DAMAGE_TAKEN]);
  textcolor(14); gotoxy(26,21); txt_write(buffer);

  textcolor(2); gotoxy(3,22); txt_write("Hardest Taken:");
  sprintf(buffer,"%d",stats.counts[STAT_HARDEST_TAKEN]);
  textcolor(14); gotoxy(26,22); txt_write(buffer);

  textcolor(2); gotoxy(43,3); txt_write("Items Sold:");
  sprintf(buffer,"%d",stats.counts[STAT_ITEMS_SOLD]);
  textcolor(14); gotoxy(66,3); txt_write(buffer);

  textcolor(2); gotoxy(43,4); txt_write("Gold from Sales:");
  sprintf(buffer,"%d",stats.counts[STAT_SOLD_GOLD]);
  textcolor(14); gotoxy(66,4); txt_write(buffer);

  textcolor(2); gotoxy(43,5); txt_write("Largest Sale:");
  sprintf(buffer,"%d",stats.counts[STAT_LARGEST_SALE]);
  textcolor(14); gotoxy(66,5); txt_write(buffer);

  textcolor(2); gotoxy(43,6); txt_write("Interest Earned:");
  sprintf(buffer,"%d",stats.counts[STAT_INTEREST]);
  textcolor(14); gotoxy(66,6); txt_write(buffer);

  textcolor(2); gotoxy(43,7); txt_write("Conversations:");
  sprintf(buffer,"%d",stats.counts[STAT_CONVERSATIONS]);
  textcolor(14); gotoxy(66,7); txt_write(buffer);

  textcolor(2); gotoxy(43,8); txt_write("Items Identified:");
  sprintf(buffer,"%d",stats.counts[STAT_ITEMS_IDENTED]);
  textcolor(14); gotoxy(66,8); txt_write(buffer);

  textcolor(2); gotoxy(43,9); txt_write("Trophies Collected:");
  sprintf(buffer,"%d",stats.num_trophies);
  textcolor(14); gotoxy(66,9); txt_write(buffer);

  d1 = stats.counts[STAT_HITS];
  d2 = stats.counts[STAT_HITS] + stats.counts[STAT_MISSES];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(43,10); txt_write("Total Hits:");
  sprintf(buffer,"%d",stats.counts[STAT_HITS]);
  textcolor(14); gotoxy(66,10); txt_write(buffer);
  sprintf(buffer,"(%3.0f%%)",d1);
  gotoxy(73,10); txt_write(buffer);

  d1 = stats.counts[STAT_CRITS];
  d2 = stats.counts[STAT_HITS];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(43,11); txt_write("Total Crits:");
  sprintf(buffer,"%d",stats.counts[STAT_CRITS]);
  textcolor(14); gotoxy(66,11); txt_write(buffer);
  sprintf(buffer,"(%3.0f%%)",d1);
  gotoxy(73,11); txt_write(buffer);

  d1 = stats.counts[STAT_MISSES];
  d2 = stats.counts[STAT_HITS] + stats.counts[STAT_MISSES];
  d1 = ( d2 > 0 ) ? (d1 / d2) * 100.0 : 0;
  textcolor(2); gotoxy(43,12); txt_write("Total Misses:");
  sprintf(buffer,"%d",stats.counts[STAT_MISSES]);
  textcolor(14); gotoxy(66,12); txt_write(buffer);
  sprintf(buffer,"(%3.0f%%)",d1);
  gotoxy(73,12); txt_write(buffer);

  textcolor(2); gotoxy(43,13); txt_write("Total Rebirths:");
  sprintf(buffer,"%d",player.effect[PE_REBIRTH]);
  textcolor(14);
  gotoxy(66,13); txt_write(buffer);

  textcolor(2); gotoxy(43,14); txt_write("Avg Dmg/Hit:");
  d1 = stats.counts[STAT_DAMAGE];
  d2 = stats.counts[STAT_HITS];
  if (d2 > 0) sprintf(buffer,"%.2lf",d1/d2);
  else sprintf(buffer,"%.2lf",(double)0);
  textcolor(14); gotoxy(66,14); txt_write(buffer);

  textcolor(2); gotoxy(43,15); txt_write("Items Crafted:");
  sprintf(buffer,"%d",stats.counts[STAT_ITEMS_CRAFTED]);
  textcolor(14); gotoxy(66,15); txt_write(buffer);

  textcolor(7);
  gotoxy(34,25); txt_write("<ESC> to exit");
  key = 0;
  while (key != 13 && key != 27) key = inkey();
  }

