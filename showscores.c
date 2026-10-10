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


typedef struct {
  char legend_name[NUM_CLASSES+1][33];
  char legend_title[NUM_CLASSES+1][33];
  double legend_exp[NUM_CLASSES+1];
  char high_name[NUM_CLASSES+1][33];
  char high_title[NUM_CLASSES+1][33];
  double high_exp[NUM_CLASSES+1];
  } SCORE_REC_OLD;

typedef struct {
  char    name[33];
  double  exp;
  int     level;
  char    cause;
  byte    class;
  int32_t time_played;
  } SCORE_ENTRY_OLD;


void save_scores() {
  int i;
  int sc_file;
#ifdef MINGW
  sc_file = open("unicorn.sco",O_WRONLY | O_CREAT | O_TRUNC | O_BINARY,0660);
#else
  sc_file = open("unicorn.sco",O_WRONLY | O_CREAT | O_TRUNC,0660);
#endif
  score_version.version[0] = '6'; score_version.version[1] = '0'; score_version.version[2] = '1';
  write(sc_file,&score_version,sizeof(SCORE_VER));
  i = NUM_CLASSES;
  write(sc_file,&i,sizeof(i));
  for (i=0; i<NUM_CLASSES; i++) {
    write(sc_file,&(high_scores[i]),sizeof(SCORE_RECORD));
    write(sc_file,&(legend_scores[i]),sizeof(SCORE_RECORD));
    }
  write(sc_file,&num_hall_of_fame,sizeof(num_hall_of_fame));
  write(sc_file,&num_final_scores,sizeof(num_final_scores));
  for (i=0; i<num_hall_of_fame; i++)
    write(sc_file,&(hall_of_fame[i]),sizeof(SCORE_ENTRY));
  for (i=0; i<num_final_scores; i++)
    write(sc_file,&(final_scores[i]),sizeof(SCORE_ENTRY));
  close(sc_file);
  }

void clear_scores() {
  int i;
  for (i=0; i<NUM_CLASSES; i++) {
    strcpy(high_scores[i].name,"");
    strcpy(high_scores[i].title,"");
    high_scores[i].exp = 0.0;
    high_scores[i].mode = 'N';
    strcpy(legend_scores[i].name,"");
    strcpy(legend_scores[i].title,"");
    legend_scores[i].exp = 0.0;
    legend_scores[i].mode = 'N';
    }
  for (i=0; i<NUM_CLASSES; i++) {
    strcpy(legend_scores[i].name,default_scores[i].name);
    strcpy(legend_scores[i].title,default_scores[i].title);
    legend_scores[i].exp = default_scores[i].exp;
    legend_scores[i].mode = 'N';
    }
  for (i=0; i<MAX_HALL_OF_FAME; i++) {
    strcpy(hall_of_fame[i].name,"");
    hall_of_fame[i].exp = 0;
    hall_of_fame[i].level = 0;
    hall_of_fame[i].cause = ' ';
    hall_of_fame[i].class = 0;
    hall_of_fame[i].time_played = 0;
    hall_of_fame[i].mode = 'N';
    }
  for (i=0; i<MAX_FINAL_SCORES; i++) {
    strcpy(final_scores[i].name,"");
    final_scores[i].exp = 0;
    final_scores[i].level = 0;
    final_scores[i].cause = ' ';
    final_scores[i].class = 0;
    final_scores[i].time_played = 0;
    final_scores[i].mode = 'N';
    }
  }

void convert_600_to_new() {
  int i;
  clear_scores();
  for (i=0; i<12; i++) {
    strcpy(high_scores[i].name,scores_600.high_name[i+1]);
    strcpy(high_scores[i].title,scores_600.high_title[i+1]);
    high_scores[i].exp = scores_600.high_exp[i+1];
    high_scores[i].mode = scores_600.high_mode[i+1];
    strcpy(legend_scores[i].name,scores_600.legend_name[i+1]);
    strcpy(legend_scores[i].title,scores_600.legend_title[i+1]);
    legend_scores[i].exp = scores_600.legend_exp[i+1];
    legend_scores[i].mode = scores_600.legend_mode[i+1];
    }
  }

void load_old_scores() {
  int i;
  int sc_file;
  SCORE_REC_OLD scores_old;
  SCORE_ENTRY_OLD score_entry_old;
#ifdef MINGW
  sc_file = open("unicorn.sco",O_RDONLY | O_BINARY);
#else
  sc_file = open("unicorn.sco",O_RDONLY);
#endif
  read(sc_file,&scores_old,sizeof(SCORE_REC_OLD));
  scores_600.version[0] = '6'; scores_600.version[1] = '0'; scores_600.version[2] = '0';
  for (i=0; i<NUM_CLASSES-1; i++) {
    strcpy(scores_600.legend_name[i+1], scores_old.legend_name[i+1]);
    strcpy(scores_600.legend_title[i+1], scores_old.legend_title[i+1]);
    scores_600.legend_exp[i+1] = scores_old.legend_exp[i+1];
    scores_600.legend_mode[i+1] = 'N';
    }
  for (i=1; i<=11; i++) {
    strcpy(scores_600.high_name[i], scores_old.high_name[i]);
    strcpy(scores_600.high_title[i], scores_old.high_title[i]);
    scores_600.high_exp[i] = scores_old.high_exp[i];
    scores_600.high_mode[i] = 'N';
    }
  convert_600_to_new();
  read(sc_file,&num_hall_of_fame,sizeof(num_hall_of_fame));
  read(sc_file,&num_final_scores,sizeof(num_final_scores));
  for (i=0; i<num_hall_of_fame; i++) {
    read(sc_file,&score_entry_old,sizeof(SCORE_ENTRY_OLD));
    strcpy(hall_of_fame[i].name,score_entry_old.name);
    hall_of_fame[i].exp = score_entry_old.exp;
    hall_of_fame[i].level = score_entry_old.level;
    hall_of_fame[i].cause = score_entry_old.cause;
    hall_of_fame[i].class = score_entry_old.class;
    hall_of_fame[i].time_played = score_entry_old.time_played;
    hall_of_fame[i].mode = 'N';
    }
  for (i=0; i<num_final_scores; i++) {
    read(sc_file,&score_entry_old,sizeof(SCORE_ENTRY_OLD));
    strcpy(final_scores[i].name,score_entry_old.name);
    final_scores[i].exp = score_entry_old.exp;
    final_scores[i].level = score_entry_old.level;
    final_scores[i].cause = score_entry_old.cause;
    final_scores[i].class = score_entry_old.class;
    final_scores[i].time_played = score_entry_old.time_played;
    final_scores[i].mode = 'N';
    }
      close(sc_file);
  }

void load_scores() {
  int i;
  int count;
  int sc_file;
  clear_scores();
  if (exist("unicorn.sco")) {
#ifdef MINGW
    sc_file = open("unicorn.sco",O_RDONLY | O_BINARY);
#else
    sc_file = open("unicorn.sco",O_RDONLY);
#endif
    read(sc_file,&score_version,sizeof(SCORE_VER));
    if (score_version.version[0] == '6' && score_version.version[1] == '0' && score_version.version[2] == '0') {
      lseek(sc_file,0,SEEK_SET);
      read(sc_file,&scores_600,sizeof(SCORE_REC_600));
      convert_600_to_new();
      read(sc_file,&num_hall_of_fame,sizeof(num_hall_of_fame));
      read(sc_file,&num_final_scores,sizeof(num_final_scores));
      for (i=0; i<num_hall_of_fame; i++)
        read(sc_file,&(hall_of_fame[i]),sizeof(SCORE_ENTRY));
      for (i=0; i<num_final_scores; i++)
        read(sc_file,&(final_scores[i]),sizeof(SCORE_ENTRY));
      close(sc_file);
      }
    else if (score_version.version[0] == '6' && score_version.version[1] == '0' && score_version.version[2] == '1') {
      read(sc_file,&count,sizeof(count));
      for (i=0; i<count; i++) {
        read(sc_file,&(high_scores[i]),sizeof(SCORE_RECORD));
        read(sc_file,&(legend_scores[i]),sizeof(SCORE_RECORD));
        }
      read(sc_file,&num_hall_of_fame,sizeof(num_hall_of_fame));
      read(sc_file,&num_final_scores,sizeof(num_final_scores));
      for (i=0; i<num_hall_of_fame; i++)
        read(sc_file,&(hall_of_fame[i]),sizeof(SCORE_ENTRY));
      for (i=0; i<num_final_scores; i++)
        read(sc_file,&(final_scores[i]),sizeof(SCORE_ENTRY));
      close(sc_file);
      }
    else {
      close(sc_file);
      load_old_scores();
      }
    }
  else { 
    score_version.version[0] = '6'; score_version.version[1] = '0'; score_version.version[2] = '1';
    for (i=0; i<NUM_CLASSES; i++) {
      strcpy(legend_scores[i].name,default_scores[i].name);
      strcpy(legend_scores[i].title,default_scores[i].title);
      legend_scores[i].exp = default_scores[i].exp;
      legend_scores[i].mode = 'N';
      }
    for (i=0; i<NUM_CLASSES; i++) {
      high_scores[i].exp = 0;
      strcpy(high_scores[i].name," ");
      strcpy(high_scores[i].title," ");
      high_scores[i].mode = 'N';
      }
    for (i=0; i<MAX_HALL_OF_FAME; i++) {
      strcpy(hall_of_fame[i].name,"");
      hall_of_fame[i].exp = 0;
      hall_of_fame[i].level = 0;
      hall_of_fame[i].cause = ' ';
      hall_of_fame[i].class = 0;
      hall_of_fame[i].mode = 'N';
      }
    for (i=0; i<MAX_FINAL_SCORES; i++) {
      strcpy(final_scores[i].name,"");
      final_scores[i].exp = 0;
      final_scores[i].level = 0;
      final_scores[i].cause = ' ';
      final_scores[i].class = 0;
      final_scores[i].mode = 'N';
      }
    save_scores();
    }
}

void show_final_scores() {
  int i;
  int first;
  char key;
  char buffer[34];
  textmode(3);
  textcolor(10); gotoxy(32,1); txt_write("Hall of Legends:"); textcolor(2);
  gotoxy(1,2); txt_write(" Place   Name            Time                Class       Level           Exp");
  if (hall_position < 0) first = 0;
  if (hall_position > 9) first = hall_position - 4;
  if (hall_position >=0 && hall_position < 10) first = 0;
  if (first > MAX_HALL_OF_FAME-10) first = MAX_HALL_OF_FAME-10;
  for (i=0; i<10; i++) {
    if (hall_of_fame[i+first].exp > 0) {
      if (i+first == hall_position) textcolor(11); else textcolor(14);
      sprintf(buffer,"%5d",i+first+1);
      gotoxy(1,i+3); txt_write(buffer);
      gotoxy(10,i+3); txt_write(hall_of_fame[i+first].name);
      convert_time(hall_of_fame[i+first].time_played,buffer);
      gotoxy(28,i+3); txt_write(buffer);
      if (hall_of_fame[i+first].class > NUM_CLASSES) strcpy(buffer,"NONE");
        else strcpy(buffer,classes[hall_of_fame[i+first].class-1].name);
      gotoxy(46,i+3); txt_write(buffer);
      sprintf(buffer,"%d",hall_of_fame[i+first].level);
      gotoxy(61,i+3); txt_write(buffer);
      if (hall_of_fame[i+first].mode == 'H') textcolor(12);
      if (hall_of_fame[i+first].mode == 'E') textcolor(13);
      sprintf(buffer,"%12.0f",hall_of_fame[i+first].exp);
      gotoxy(65,i+3); txt_write(buffer);
      }
    }
  textcolor(10); gotoxy(30,13); txt_write("Hall of Remembrance:"); textcolor(2);
  gotoxy(1,14); txt_write(" Place   Name              Time              Class       Level           Exp");
  if (death_position < 0) first = 0;
  if (death_position > 9) first = death_position - 4;
  if (death_position >=0 && death_position < 10) first = 0;
  if (first > MAX_FINAL_SCORES-10) first = MAX_FINAL_SCORES-10;
  for (i=0; i<10; i++) {
    if (final_scores[i+first].exp > 0) {
      if (i+first == death_position) textcolor(11); else textcolor(14);
      if (i+first == score_position) {
        gotoxy(1,i+15); txt_write("*");
        }
      sprintf(buffer,"%5d",i+first+1);
      gotoxy(1,i+15); txt_write(buffer);
      if (i+first == score_position) {
        gotoxy(1,i+15); txt_write("*");
        }
      gotoxy(10,i+15); txt_write(final_scores[i+first].name);
      convert_time(final_scores[i+first].time_played,buffer);
      gotoxy(28,i+15); txt_write(buffer);
      if (final_scores[i+first].class > NUM_CLASSES) strcpy(buffer,"NONE");
        else strcpy(buffer,classes[final_scores[i+first].class-1].name);
      gotoxy(46,i+15); txt_write(buffer);
      sprintf(buffer,"%d",final_scores[i+first].level);
      gotoxy(61,i+15); txt_write(buffer);
      if (final_scores[i+first].mode == 'H') textcolor(12);
      if (final_scores[i+first].mode == 'E') textcolor(13);
      sprintf(buffer,"%12.0f",final_scores[i+first].exp);
      gotoxy(65,i+15); txt_write(buffer);
      }
    }
  key = 0;
  while (key != 13) key = inkey();
  }

void show_scores() {
  int i;
  char key;
  char buffer[80];
  textmode(3);
  textcolor(10); gotoxy(1,1); txt_write("High Scores:"); textcolor(2);
  for (i=0; i<NUM_CLASSES; i++) {
    gotoxy(5,2+i); txt_write(classes[i].name);
    gotoxy(16,2+i); txt_write(":");
    }
  for (i=0; i<NUM_CLASSES; i++) {
    if (score2-1 == i) textcolor(11); else textcolor(14);
    gotoxy(18,i+2);
    sprintf(buffer,"%10.0f",high_scores[i].exp);
    txt_write(buffer);
    gotoxy(30,i+2); txt_write(high_scores[i].name);
    gotoxy(55,i+2); txt_write(high_scores[i].title);
    }
  key = 0;
  while (key != 13) key = inkey();
  }


void show_legends() {
  int i;
  char key;
  char buffer[80];
  textmode(3);
  textcolor(10); gotoxy(1,1); txt_write("Legends:"); textcolor(2);
  for (i=0; i<NUM_CLASSES; i++) {
    gotoxy(5,2+i); txt_write(classes[i].name);
    gotoxy(16,2+i); txt_write(":");
    }
  for (i=0; i<NUM_CLASSES; i++) {
    if (score1-1 == i) textcolor(11); else textcolor(14);
    gotoxy(18,i+2);
    sprintf(buffer,"%10.0f",legend_scores[i].exp);
    txt_write(buffer);
    gotoxy(30,i+2); txt_write(legend_scores[i].name);
    gotoxy(55,i+2); txt_write(legend_scores[i].title);
    }
  key = 0;
  while (key != 13) key = inkey();
  }

