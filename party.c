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

void party() {

  void party_show_top() {
    int  i;
    char buffer[80];
    gotoxy(24,1); textcolor(2);
    txt_write("  #  Name               Lvl     Hp");
    for (i=1; i<=5; i++) {
      gotoxy(25,i + 2); textcolor(14);
      sprintf(buffer,"%2d: ",i);
      txt_write(buffer);
      if (player.party[i].hp != 0) {
        txt_write(player.party[i].name);
        gotoxy(49,i+2);
        sprintf(buffer,"%2d    %3d",player.party[i].level,player.party[i].hp);
        txt_write(buffer);
        }
      else {
        txt_write("                                                  ");
        }
      }
    gotoxy(40,9); textcolor(14);
    txt_write("P");
    gotoxy(30,10); if (player.party[1].hp != 0) textcolor(14); else textcolor(8);
    txt_write("1");
    gotoxy(50,10); if (player.party[2].hp != 0) textcolor(14); else textcolor(8);
    txt_write("2");
    gotoxy(20,11); if (player.party[3].hp != 0) textcolor(14); else textcolor(8);
    txt_write("3");
    gotoxy(60,11); if (player.party[4].hp != 0) textcolor(14); else textcolor(8);
    txt_write("4");
    gotoxy(40,11); if (player.party[5].hp != 0) textcolor(14); else textcolor(8);
    txt_write("5");
    }

  void show_member(int member) {
    int  i;
    char key;
    char flag;
    char buffer[80];
    double cost;
  
    void show_stats() {
        textcolor(2);
        gotoxy(20,16); txt_write("Name   :");
        gotoxy(20,17); txt_write("Level  :");
        gotoxy(20,18); txt_write("Hp     :");
        gotoxy(20,19); txt_write("Mana   :");
        gotoxy(20,20); txt_write("Attack :");
        gotoxy(20,21); txt_write("Defense:");
        gotoxy(20,22); txt_write("Orders :");
        gotoxy(40,17); txt_write("Time      :");
        gotoxy(40,18); txt_write("Sleeping  :");
        gotoxy(40,19); txt_write("Scared    :");
        gotoxy(40,20); txt_write("Experience:");
        gotoxy(40,21); txt_write("Next Level:");
        textcolor(14);
        gotoxy(28,16); txt_write(player.party[member].name);
        sprintf(buffer,"%d",player.party[member].level);
        gotoxy(28,17); txt_write(buffer);
        sprintf(buffer,"%d",player.party[member].hp);
        gotoxy(28,18); txt_write(buffer);
        sprintf(buffer,"%d",player.party[member].mana);
        gotoxy(28,19); txt_write(buffer);
        sprintf(buffer,"%d",player.party[member].attack);
        gotoxy(28,20); txt_write(buffer);
        sprintf(buffer,"%d",player.party[member].defense);
        gotoxy(28,21); txt_write(buffer);
        gotoxy(28,22);
        if (player.party[member].special < 20)
          txt_write("Attack"); else txt_write("Evade ");
        gotoxy(51,17);
        if (player.party[member].time == 255)
          txt_write("Perm");
        else {
          sprintf(buffer,"%d      ",player.party[member].time);
          txt_write(buffer);
          }
         gotoxy(51,18);
        if (player.party[member].sleep == 0)
          txt_write("No "); else txt_write("Yes ");
         gotoxy(51,19);
        if (player.party[member].fear == 0)
          txt_write("No "); else txt_write("Yes ");
        gotoxy(51,20);
        sprintf(buffer,"%9.0f",player.party[member].exp);
        txt_write(buffer);
        gotoxy(51,21);
        sprintf(buffer,"%9.0f",needed(player.party[member].level+1));
        txt_write(buffer);
      }
    flag = ' ';
    for (i=16; i<=22; i++) {
      gotoxy(28,i);
      txt_write("                                                ");
      }
    while (flag == ' ') {
      flag = '*';
        show_stats();
      if (player.in_city == 'Y') {
        cost = (needed(player.party[member].level + 1) - player.party[member].exp);
        if (cost <= player.gold) {
          gotoxy(20,23);
          sprintf(buffer,"Training to next level will cost %.0f Gold",cost);
          txt_write(buffer);
          gotoxy(20,24); txt_write("Do you wish to train member ?");
          sprintf(buffer,"Gold=%.0f",player.gold);
          gotoxy(34,25); txt_write(buffer);
          key = ' ';
          while (key != 'Y' && key != 'N') {
            key = inkey();
            if (key == 'n') key = 'N';
            if (key == 'y') key = 'Y';
            }
          if (key == 'Y') {
            player.party[member].exp += cost + 1;
            player.party[member].level++;
            player.party[member].attack += 2;
            player.party[member].defense += 2;
            if (player.party[member].mana != 0)
              player.party[member].mana += 25;
            player.gold -= cost;
            player.party[member].hp = player.party[member].level * 9;
            party_show_top();
            show_stats();
            }
          }
        else
          flag = '*';
          gotoxy(20,23); txt_write("                                                  ");
          gotoxy(20,24); txt_write("                                                  ");
          gotoxy(20,25); txt_write("                                                  ");
        }
      }
    }

  int i=0,j=0;
  char temp;
  NPC_REC ptemp;
  char key;
  saveScreen();
  textmode(3); party_show_top();
  gotoxy(10,13); textcolor(3);
  txt_write("<D>ismiss, <1-5>Statistics, <C>hange order, <O>orders, <Q>uit");
  key = ' ';
  while (key != 'q') {
    key = inkey();
    switch (key) {
      case '1':if (player.party[1].hp != 0) show_member(1); break;
      case '2':if (player.party[2].hp != 0) show_member(2); break;
      case '3':if (player.party[3].hp != 0) show_member(3); break;
      case '4':if (player.party[4].hp != 0) show_member(4); break;
      case '5':if (player.party[5].hp != 0) show_member(5); break;
      case 'd':if (player.in_city == 'Y') {
                 gotoxy(20,14); textcolor(10);
                 txt_write("Dismiss who ?");
                 key = ' ';
                 while (key < '0' || key > '5') key = inkey();
                 if (key > '0') {
                   switch (key) {
                     case '1':player.party[1].hp = 0; break;
                     case '2':player.party[2].hp = 0; break;
                     case '3':player.party[3].hp = 0; break;
                     case '4':player.party[4].hp = 0; break;
                     case '5':player.party[5].hp = 0; break;
                     }
                   party_show_top();
                   }
                 gotoxy(20,14); textcolor(10);
                 txt_write("             ");
                 }
               break;
      case 'o':gotoxy(20,14); textcolor(10);
               txt_write("Change whos orders ?");
               key = ' ';
               while (key < '0' || key > '5') key = inkey();
               temp = key;
               gotoxy(20,14); textcolor(10);
               txt_write("                    ");
               gotoxy(20,14); textcolor(10);
               txt_write("<A>ttack, or <E>vade ?");
               key = ' ';
               while (key != 'a' && key != 'e') key = inkey();
               switch (temp) {
                 case '1':i = 1; break;
                 case '2':i = 2; break;
                 case '3':i = 3; break;
                 case '4':i = 4; break;
                 case '5':i = 5; break;
                 }
               switch (key) {
                 case 'a':if (player.party[i].special > 19)
                            player.party[i].special -= 10;
                          break;
                 case 'e':if (player.party[i].special < 20)
                            player.party[i].special += 10;
                 }
               gotoxy(20,14); textcolor(10);
               txt_write("                          ");
               break;
      case 'c':gotoxy(20,14); textcolor(10);
               txt_write("Change whos position ?");
               key = ' ';
               while (key < '0' || key > '5') key = inkey();
               temp = key;
               gotoxy(20,14); textcolor(10);
               txt_write("                      ");
               gotoxy(20,14); textcolor(10);
               txt_write("Change to what position ?");
               key = ' ';
               while (key < '0' || key > '5') key = inkey();
               gotoxy(20,14); textcolor(10);
               txt_write("                         ");
               switch (temp) {
                 case '1':j = 1; break;
                 case '2':j = 2; break;
                 case '3':j = 3; break;
                 case '4':j = 4; break;
                 case '5':j = 5; break;
                 }
               switch (key) {
                 case '1':i = 1; break;
                 case '2':i = 2; break;
                 case '3':i = 3; break;
                 case '4':i = 4; break;
                 case '5':i = 5; break;
                 }
               ptemp = player.party[i];
               player.party[i] = player.party[j];
               player.party[j] = ptemp;
               party_show_top();
               break;
      }
    }
  player.mount = 0; player.peg = 0;
  for (i=1; i<=5; i++) {
    if (player.party[i].hp > 0) {
      if (player.party[i].sprite == 133) player.peg = 1;
      if (player.party[i].sprite == 148) player.mount = 1;
      if (player.party[i].sprite == 131) player.mount = 1;
      if (player.party[i].sprite == 132) player.mount = 1;
      if (player.party[i].sprite == 138) player.mount = 1;
      if (player.party[i].sprite == 155) player.peg = 1;
      if (player.party[i].sprite == 159) player.peg = 1;
      if (player.peg == 1) player.mount = 1;
      }
    }
  restoreScreen();
/*  show_screen(); */
  }
