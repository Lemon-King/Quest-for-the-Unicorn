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

void view(int floor) {
  char key,mflag;
  int  xdir,ydir;
  int  i = 0,x,y;
  key = get_dir(&xdir,&ydir);
  x = player.x;
  y = player.y;
  mflag = ' ';
  while (mflag == ' ') {
    x += xdir;
    y += ydir;
    if (player.map[x][y] != floor) mflag = '*';
    if (player.map[x][y] > 800 && player.map[x][y] < 899) mflag = ' ';
    if (player.map[x][y] == 15) mflag = ' ';
    }
  if (player.map[x][y] >= 600 && player.map[x][y] <= 699) msg("Forbidding",14);
  else if (player.map[x][y] >= 700 && player.map[x][y] <= 799) msg("Phase Door",14);
  else switch (player.map[x][y]) {
    case  1:msg("Plains",14); break;
    case  2:msg("Forest",14); break;
    case  3:msg("Mountains",14); break;
    case  4:msg("Water",14); break;
    case  5:msg("City",14); break;
    case  6:msg("Swamp",14); break;
    case  8:msg("Desert",14); break;
    case  9:msg("Hills",14); break;
    case 10:msg("Darkness",14); break;
    case 11:msg("Dungeon Entrance",14); break;
    case 12:msg("Your Ship",14); break;
    case 13:msg("Ship",14); break;
    case 14:msg("Dock",14); break;
    case 16:msg("Cactus",14); break;
    case 17:msg("Village",14); break;
    case 18:msg("Rock",14); break;
    case 19:msg("Pass",14); break;
    case 20:msg("Tree",14); break;
    case 21:msg("Wall",14); break;
    case 22:msg("Closed Door",14); break;
    case 23:msg("Open Door",14); break;
    case 24:msg("Down Stairs",14); break;
    case 25:msg("Up Stairs",14); break;
    case 26:msg("Chair",14); break;
    case 27:msg("Table",14); break;
    case 28:msg("Merchant",14); break;
    case 29:msg("Bed",14); break;
    case 30:msg("Shelves",14); break;
    case 31:msg("Gateway",14); break;
    case 32:msg("Gateway",14); break;
    case 33:msg("Jammed Door",14); break;
    case 36:msg("Sleeping",14); break;
    case 38:msg("Wall of Fire",14); break;
    case 39:msg("Wall of Water",14); break;
    case 40:msg("Disarmed Trap",14); break;
    case 41:msg("Forbidding",14); break;
    case 42:msg("Phase Door",14); break;
    case 79:msg("Gold",14); break;
    case 84:msg("Torch",14); break;
    case 99:msg("Food",14); break;
    case 176:msg("Rock",14); break;
    case 178:msg("Rock",14); break;
    }
  if (player.map[x][y] >= 1000) msg(get_name(&(player.map_objects[player.map[x][y] - 1000])),14);
  if (player.map[x][y] < 0 ||
      (player.map[x][y] > 299 && player.map[x][y] < 400) ||
      (player.map[x][y] > 399 && player.map[x][y] < 500)) {
    if (player.map[x][y] < 0) i = player.monster[1][0-player.map[x][y]].sprite;
    if (player.map[x][y] > 299 && player.map[x][y] < 400)
      i = player.party[player.map[x][y] - 300].sprite;
    if (player.map[x][y] > 399 && player.map[x][y] < 500)
      i = player.monster[player.map[x][y] - 400][a_mon].sprite;
    switch (i) {
      case  101:msg("Air Elemental",14); break;
      case  102:msg("Insectoid",14); break;
      case  103:msg("Rodent",14); break;
      case  104:msg("Large Animal",14); break;
      case  105:msg("Beholder Like",14); break;
      case  106:msg("Blob",14); break;
      case  107:msg("Blob",14); break;
      case  108:msg("Roper",14); break;
      case  109:msg("Bulette",14); break;
      case  110:msg("Centipede Type",14); break;
      case  111:msg("Fire Elemental",14); break;
      case  112:msg("Water Elemental",14); break;
      case  113:msg("Earth Elemental",14); break;
      case  114:msg("Efreeti",14); break;
      case  115:msg("Gargoyle Like",14); break;
      case  116:msg("Gelletanous Cube",14); break;
      case  117:msg("Griffon",14); break;
      case  118:msg("Ghost Like",14); break;
      case  119:msg("Harpy",14); break;
      case  120:msg("Dog Like",14); break;
      case  121:msg("Dwarf Like",14); break;
      case  122:msg("Hydra",14); break;
      case  123:msg("Orc Like",14); break;
      case  124:msg("Lamia",14); break;
      case  125:msg("Skeleton",14); break;
      case  126:msg("Lizard Like",14); break;
      case  127:msg("Manticore",14); break;
      case  128:msg("Medusa",14); break;
      case  129:msg("Mind Flayer",14); break;
      case  130:msg("Minotaur",14); break;
      case  131:msg("Horse Like",14); break;
      case  132:msg("Unicorn",14); break;
      case  133:msg("Pegasus",14); break;
      case  134:msg("Frog",14); break;
      case  135:msg("Giant",14); break;
      case  136:msg("Mummy Like",14); break;
      case  137:msg("Naga",14); break;
      case  138:msg("Nightmare",14); break;
      case  139:msg("Nymph Like",14); break;
      case  140:msg("Sprite Like",14); break;
      case  141:msg("Purple Worm",14); break;
      case  142:msg("Scorpian",14); break;
      case  143:msg("Snake Like",14); break;
      case  144:msg("Sphinx",14); break;
      case  145:msg("Spider",14); break;
      case  146:msg("Umber Hulk",14); break;
      case  147:msg("Will-o-Wisp",14); break;
      case  148:msg("Centaur",14); break;
      case  149:msg("Demogorgon",14); break;
      case  150:msg("Orcus",14); break;
      case  151:msg("Succubus",14); break;
      case  152:msg("Demon Like",14); break;
      case  153:msg("Dragon",14); break;
      case  154:msg("Dragon",14); break;
      case  155:msg("Dragon",14); break;
      case  156:msg("Dragon",14); break;
      case  157:msg("Dragon",14); break;
      case  158:msg("Dragon",14); break;
      case  159:msg("Dragon",14); break;
      case  160:msg("Dalek",14); break;
      case  161:msg("Female Humanoid",14); break;
      case  162:msg("Male Humanoid",14); break;
      case  163:msg("Fighter",14); break;
      case  164:msg("Cleric",14); break;
      case  165:msg("Wizard",14); break;
      case  166:msg("Dark Magi",14); break;
      }
    }
  }
