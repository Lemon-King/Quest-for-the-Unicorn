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
#include "math.h"

void buy_house(int hnum) {
  double down;
  double ccost;
  double p;
  double a;
  double i;
  char   buffer[80];
  char   key;
  int    flag;
  int    j;

  void show_top() {
    textmode(3); gotoxy(33,1); textcolor(11);
    txt_write("Purchase House");
    textcolor(14);
    sprintf(buffer,"%.0f",forsale[hnum].price);
    gotoxy(24,3); txt_write("Price"); gotoxy(51,3); txt_write(buffer);
    sprintf(buffer,"%.0f",down);
    gotoxy(24,4); txt_write("Down Payment");  gotoxy(51,4); txt_write(buffer);
    sprintf(buffer,"%.0f",forsale[hnum].price-down);
    gotoxy(24,5); txt_write("Financed Amount");  gotoxy(51,5); txt_write(buffer);
    sprintf(buffer,"%.0f",a);
    gotoxy(24,6); txt_write("Monthly Payment");  gotoxy(51,6); txt_write(buffer);
    sprintf(buffer,"%.0f",ccost);
    gotoxy(24,7); txt_write("Closing Costs");  gotoxy(51,7); txt_write(buffer);
    sprintf(buffer,"%.0f",ccost+down);
    gotoxy(24,8); txt_write("Due at Closing");  gotoxy(51,8); txt_write(buffer);

    gotoxy(27,10); txt_write("1> Change Down Payment");
    gotoxy(27,11); txt_write("2> Purchase House");
    gotoxy(27,12); txt_write("0> Leave");
    gotoxy(30,13); txt_write("Option ?");
    textcolor(15); gotoxy(35,24);
    sprintf(buffer,"Gold = %.0f",player.gold);
    txt_write(buffer);
    }

  p = forsale[hnum].price;
  i = .005;
  a = p*((i*pow(1+i,360))/(pow(1+i,360)-1));
  ccost = forsale[hnum].price * 0.023;
  down = 0;
  show_top();
  key = ' ';
  while (key != '0') {
    key = inkey();
    if (key == '1') {
      gotoxy(27,15); textcolor(2); txt_write("New Down Payment: ");
      textcolor(15);
      p_read(buffer);
      sscanf(buffer,"%lf",&down);
      a = (p-down)*((i*pow(1+i,360))/(pow(1+i,360)-1));
      }
    if (key == '2') {
      if (ccost+down > player.gold) {
        gotoxy(27,15); textcolor(4); txt_write("You do not have enough gold ");
        delay(5000);
        }
      else {
        flag = -1;
        for (j=0; j<5; j++)
          if (flag == -1 && player.houses[j].region == 0) flag = j;
        if (flag < 0) {
          gotoxy(27,15); textcolor(4); txt_write("You already own the maximum number of houses ");
          delay(5000);
          }
        else {
          player.houses[flag].region = forsale[hnum].region;
          player.houses[flag].rx = forsale[hnum].rx;
          player.houses[flag].ry = forsale[hnum].ry;
          player.houses[flag].cx = forsale[hnum].cx;
          player.houses[flag].cy = forsale[hnum].cy;
          player.houses[flag].mortgage = forsale[hnum].price - down;
          player.houses[flag].interest = 0;
          player.houses[flag].payment = a;
          for (j=0; j<500; j++) player.houses[flag].inventory[j].otype = O_NONE;
          player.gold -= (down+ccost);
          player.map[forsale[hnum].cx][forsale[hnum].cy] = S_SOLD;
          key = '0';
          restoreScreen();
          show_spot(forsale[hnum].cx,forsale[hnum].cy);
          saveScreen();
          }
        }
      }
    show_top();
    }
  } /* void temple(char* name) */
