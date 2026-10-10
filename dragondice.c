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

void dragon_dice() {
  double bet;
  byte dice[4];
  char buffer[80];
  int i,j,k = 0;
  double pay;
  clrscr();
  gotoxy(35,1); textcolor(12);
  txt_write("Dragon Dice");
  textcolor(14);
  gotoxy(34,10); txt_write("+---+---+---+");
  gotoxy(34,11); txt_write("|   |   |   |");
  gotoxy(34,12); txt_write("+---+---+---+");
  textcolor(15);
  gotoxy(6, 6); txt_write("Combination   Pays");
  gotoxy(6, 7); txt_write("1 6 6            2");
  gotoxy(6, 8); txt_write("2 6 6            3");
  gotoxy(6, 9); txt_write("3 6 6            4");
  gotoxy(6,10); txt_write("4 6 6            5");
  gotoxy(6,11); txt_write("5 6 6            6");
  gotoxy(6,12); txt_write("1 1 1            4");
  gotoxy(6,13); txt_write("2 2 2            8");
  gotoxy(6,14); txt_write("3 3 3           10");
  gotoxy(6,15); txt_write("4 4 4           12");
  gotoxy(6,16); txt_write("5 5 5           24");
  gotoxy(6,17); txt_write("6 6 6           36");
  bet = 1;
  while (bet != 0) {
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %d",get_gold());
    txt_write(buffer);
    gotoxy(27,3); textcolor(11);
    txt_write("Enter bet (0 to leave) ?               ");
    gotoxy(27,3); textcolor(11);
    txt_write("Enter bet (0 to leave) ? ");
    strcpy(buffer,"");
    readln(buffer);
    sscanf(buffer,"%lf",&bet);
    gotoxy(27,5); textcolor(10);
    txt_write("                                 ");
    textcolor(14);
    gotoxy(34,11); txt_write("|   |   |   |");
    if (bet != 0) {
      if (bet > 100) {
        gotoxy(27,5); textcolor(10);
        txt_write("The table limit is 100 gold");
        }
      else if (bet>get_gold()) {
        gotoxy(27,5); textcolor(10);
        txt_write("You do not have that much");
        }
      else {
        sub_gold(bet);
        textcolor(14); gotoxy(35,24);
        sprintf(buffer,"Gold = %d",get_gold());
        txt_write(buffer);
        for (i=1; i<=3; i++) {
          for (j=1; j<=u_random(50)+25; j++) {
            for (k=i; k<=3; k++) {
              dice[k] = u_random(6)+1;
              gotoxy(4*k+32,11); textcolor(15);
              sprintf(buffer,"%d",dice[k]);
              txt_write(buffer);
              }
            delay(10);
            }
          }
        if (dice[2]<dice[1]) {
          k = dice[1]; dice[1] = dice[2]; dice[2] = k;
          }
        if (dice[3]<dice[2]) {
          k = dice[2]; dice[2] = dice[3]; dice[3] = k;
          }
        if (dice[2]<dice[1]) {
          k = dice[1]; dice[1] = dice[2]; dice[2] = k;
          }
        pay = 0;
        if (dice[1] == 1 && dice[2] == 6 && dice[3] == 6) pay = 2;
        if (dice[1] == 2 && dice[2] == 6 && dice[3] == 6) pay = 3;
        if (dice[1] == 3 && dice[2] == 6 && dice[3] == 6) pay = 4;
        if (dice[1] == 4 && dice[2] == 6 && dice[3] == 6) pay = 5;
        if (dice[1] == 5 && dice[2] == 6 && dice[3] == 6) pay = 6;
        if (dice[1] == 1 && dice[2] == 1 && dice[3] == 1) pay = 4;
        if (dice[1] == 2 && dice[2] == 2 && dice[3] == 2) pay = 8;
        if (dice[1] == 3 && dice[2] == 3 && dice[3] == 3) pay = 10;
        if (dice[1] == 4 && dice[2] == 4 && dice[3] == 4) pay = 12;
        if (dice[1] == 5 && dice[2] == 5 && dice[3] == 5) pay = 24;
        if (dice[1] == 6 && dice[2] == 6 && dice[3] == 6) pay = 36;
        if (pay == 0) {
          gotoxy(27,5); textcolor(10);
          txt_write("Sorry!! you lost");
          }
        else {
          gotoxy(27,5); textcolor(10);
          sprintf(buffer,"You won %.0f Gold",bet * pay);
          txt_write(buffer);
          add_gold(bet * pay);
          }
        }
      }
    }
  } /* void dragon_dice() */
