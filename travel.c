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

void travel(char* name) {
  char dest[9][33];
  int cost[9];
  int where[9];
  char flag;
  int  option;
  char buffer[80];
  int  i;
  char key;
  int  px,py;
  int  dx,dy;
  int  city;
  int  shipx,shipy;
  int  ndest;

  void new_town(int where) {
    int m_file;
    m_file = open("temp01.$$$",O_WRONLY);
    if (m_file < 0) {
      printf("Fatal Error: Could not open temp01.$$$\n");
      exit(1);
      }
    lseek(m_file,sizeof(KNOW_TYPE) * player.city,SEEK_SET);
    write(m_file,&(player.known),sizeof(KNOW_TYPE));
    close(m_file);

    player.region = links[where].region;
    player.city = links[where].diff;
    player.land_x = links[where].x;
    player.land_y = links[where].y;
    player.x = links[where].sx;
    player.y = links[where].sy;
    strcpy(player.d_name,links[where].name);
    copyMap(&player.map,player.city);
    m_file = open("temp01.$$$",O_RDONLY);
    if (m_file < 0) {
      printf("Fatal Error: Could not open temp01.$$$\n");
      exit(1);
      }
    lseek(m_file,sizeof(KNOW_TYPE) * player.city,SEEK_SET);
    read(m_file,&(player.known),sizeof(KNOW_TYPE));
    close(m_file);
    player.map_x = player.x-8;
    player.map_y = player.y-8;
    if (player.map_x<1) player.map_x = 1;
    if (player.map_y<1) player.map_y = 1;
    if (player.map_x>84) player.map_x = 84;
    if (player.map_y>84) player.map_y = 84;
    i = 0;
    while (i >= 0) {
      if (shops[i].shoptype != 999) {
        if (shops[i].region == player.region &&
            shops[i].rx == player.land_x &&
            shops[i].ry == player.land_y)
          player.map[shops[i].cx][shops[i].cy] = 520;
        i++;
        } else i = -1;
      }

    stock_town(player.city);
    } /* void new_town(int where) */

  int getPX(int r,int x) {
    return (((r - 1) % 4) * 100) + x;
    }

  int getPY(int r,int y) {
    return (((r - 1) / 4) * 100) + y;
    }


  shipx = -1;
  shipy = -1;
  i = 0;
  while (i >= 0) {
    if (tr_ships[i].map == player.city) {
      shipx = tr_ships[i].x;
      shipy = tr_ships[i].y;
      i = -99;
      }
    else if (tr_ships[i].map >= 99) i = -99;
      else i++;
    }
  city = -1;
  i = 0;
  while (city == -1) {
    if (links[i].typ < 99) {
      if (links[i].region == player.region &&
          links[i].x == player.land_x &&
          links[i].y == player.land_y) city = i;
      else i++;
      } else city = -2;
    }
  if (city < 0) return;
  px = getPX(player.region,player.land_x);
  py = getPY(player.region,player.land_y);
  i = 0;
  ndest = 1;
  while (i >= 0) {
    if (i != city) {
      if (links[i].typ == 5) {
        strcpy(dest[ndest],links[i].name);
        dx = getPX(links[i].region,links[i].x);
        dy = getPY(links[i].region,links[i].y);
        cost[ndest] = abs(dx-px)*3 + abs(dy-py)*3 + links[i].premium;
        where[ndest] = i;
        ndest++;
        }
      if (links[i].typ == 99) i = -1;
        else i++;
      } else i++;
    }

  textmode(3);
  textmode(3); gotoxy(27,1); textcolor(11);
  sprintf(buffer,"Welcome to %s",name);
  txt_write(buffer);
  textcolor(14);
  for (i=1; i<ndest; i++) {
    gotoxy(27,i+2);
    sprintf(buffer,"%2d> %s",i,dest[i]);
    txt_write(buffer);
    gotoxy(50,i+2);
    sprintf(buffer,"%4d",cost[i]);
    txt_write(buffer);
    }
  if (shipx >= 0)
    {
      sprintf(buffer,"%2d> Purchase a ship",ndest);
      gotoxy(27,ndest+2); txt_write(buffer);
      gotoxy(49,11); txt_write("2500");
    }
  textcolor(14); gotoxy(35,24); 
  sprintf(buffer,"Gold = %.0f",player.gold);
  txt_write(buffer);
  flag = ' ';
  while (flag == ' ') {
    textcolor(10); gotoxy(20,ndest+4);
    txt_write("Where would you like to travel to ? (0 to leave)        ");
    gotoxy(71,ndest+4);
    p_read(buffer);
    sscanf(buffer,"%d",&option);
    gotoxy(20,16);
    txt_write("                                           ");
    if (option == 0) flag = '*';
    if (option == ndest && (shipx >= 0)) {
      if (player.ship_r != 0) {
        gotoxy(20,ndest+6); textcolor(14);
        txt_write("You already own a ship!!");
        delay(1000);
        }
      else {
        if (player.gold<2500) {
          gotoxy(20,ndest+6); textcolor(14);
          txt_write("You can not afford a ship!!");
          delay(1000);
          }
        else {
          player.gold -= 2500;
          player.map[shipx][shipy] = 12;
          gotoxy(20,ndest+6); textcolor(14);
          txt_write("You will find you new ship in the harbor");
          textcolor(14); gotoxy(35,24); 
          sprintf(buffer,"Gold = %.0f             ",player.gold);
          txt_write(buffer);
          delay(1000);
          }
        }
      }
    if (option>=1 && option<ndest) {
      gotoxy(20,ndest+6); textcolor(14);
      sprintf(buffer,"A trip to %s will cost %d",dest[option],cost[option]);
      txt_write(buffer);
      gotoxy(20,ndest+7); txt_write("Do you wish to go ?");
      key = inkey();
      if (key == 'N' || key == 'n') {
        gotoxy(20,ndest+6); textcolor(14);
        txt_write("                                                  ");
        gotoxy(20,ndest+7); txt_write("                   ");
        }
      if (key == 'Y' || key == 'y') {
        if (cost[option]>player.gold) {
          gotoxy(20,ndest+8); textcolor(12);
          txt_write("You do not have enough gold for that trip!!");
          gotoxy(20,ndest+6); textcolor(14);
          txt_write("                                                  ");
          gotoxy(20,ndest+7); txt_write("                   ");
          }
        else {
          player.gold -= cost[option];
          flag = '#';
          }
        }
      }
    }
  if (flag == '#' && option>0) new_town(where[option]);
} /* void travel(char* name,int city) */
