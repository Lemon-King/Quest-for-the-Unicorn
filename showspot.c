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

void show_spot(int x,int y) {
  if (x < 1 || y < 1 || x > 100 || y > 100) return;
  if (in_sight(x,y) != '*') return;
  if (can_see() == 0) {
    show_sprite(x-player.map_x,y-player.map_y,10);
    return;
    }
  if (player.known[x][y] == 0) {
    show_sprite(x-player.map_x,y-player.map_y,10);
    return;
    }
  if (player.map[x][y] >= 1000 && player.map[x][y] < 2000) {
    show_sprite(x-player.map_x,y-player.map_y,7);
      show_sprite(x-player.map_x,y-player.map_y,player.map_objects[player.map[x][y]-1000].sprite);
    }
  else if (player.map[x][y] > 2000) {
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,88);
    }
  else if (player.map[x][y] < 0) {
    if (player.monster[1][0-player.map[x][y]].sleep == 0) {
      show_sprite(x-player.map_x,y-player.map_y,7);
      show_sprite(x-player.map_x,y-player.map_y,
                  player.monster[1][0-player.map[x][y]].sprite);
      }
    else
      show_sprite(x-player.map_x,y-player.map_y,36);
    }
  else if (player.map[x][y]>300 && player.map[x][y]<400) {
    if (player.party[player.map[x][y]-300].sleep == 0)
      show_sprite(x-player.map_x,y-player.map_y,
                  player.party[player.map[x][y]-300].sprite);
    else
      show_sprite(x-player.map_x,y-player.map_y,36);
    }
  else if (player.map[x][y]>400 && player.map[x][y]<500)
    if (player.monster[player.map[x][y]-400][a_mon].sleep == 0)
      show_sprite(x-player.map_x,y-player.map_y,
                  player.monster[player.map[x][y]-400][a_mon].sprite);
    else
      show_sprite(x-player.map_x,y-player.map_y,36);
  else if (player.map[x][y] == 40) {
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,40);
    }
  else if (player.map[x][y] == 79) {
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,79);
    }
  else if (player.map[x][y] == 84) {
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,84);
    }
  else if (player.map[x][y] == S_SALE) {
    show_sprite(x-player.map_x,y-player.map_y,S_GRASS);
    show_sprite(x-player.map_x,y-player.map_y,S_SALE);
    }
  else if (player.map[x][y] == S_SOLD) {
    show_sprite(x-player.map_x,y-player.map_y,S_GRASS);
    show_sprite(x-player.map_x,y-player.map_y,S_SOLD);
    }
  else if (player.map[x][y] == 143) {
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,342);
    }
  else if (player.map[x][y] == 901) {                 // Altar
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,315);
    }
  else if (player.map[x][y] == 902) {                 // Used Altar
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,316);
    }
  else if (player.map[x][y] >= 903 && player.map[x][y] <= 910) {                 // Runestones
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,player.map[x][y]-586);
    }
  else if (player.map[x][y] >= 950 && player.map[x][y] <= 970) {                 // Traps
    show_sprite(x-player.map_x,y-player.map_y,7);
    show_sprite(x-player.map_x,y-player.map_y,330);
    }
  else show_sprite(x-player.map_x,y-player.map_y,player.map[x][y]);
  }

