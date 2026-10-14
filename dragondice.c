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
  bet = 1;
  while (bet != 0) {
    textcolor(14); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
    gotoxy(27,3); textcolor(11);
    txt_write("Enter bet (0 to leave) ?               ");
    gotoxy(27,3); textcolor(11);
    txt_write("Enter bet (0 to leave) ? ");
    readln(buffer);
    sscanf(buffer,"%lf",&bet);
    gotoxy(27,5); textcolor(10);
    txt_write("                         ");
    textcolor(14);
    gotoxy(34,11); txt_write("|   |   |   |");
    if (bet != 0) {
      if (bet>player.gold) {
        gotoxy(27,5); textcolor(10);
        txt_write("You do not have that much");
        }
      else {
        for (i=1; i<=3; i++) {
          for (j=1; j<=u_random(50)+25; j++) {
            k = u_random(6)+1;
            gotoxy(4*i+32,11); textcolor(15);
            sprintf(buffer,"%d",k);
            txt_write(buffer);
            delay(10);
            }
          dice[i] = k;
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
          player.gold = player.gold-bet;
          }
        else {
          gotoxy(27,5); textcolor(10);
          sprintf(buffer,"You won %.0f Gold",bet * pay);
          txt_write(buffer);
          player.gold = player.gold+bet*pay;
          }
        }
      }
    }
  } /* void dragon_dice() */
