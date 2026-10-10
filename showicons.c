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

int helpcol;
int helprow;
int maxcol;
int maxrow;

void show_icon_help(int tileNumber, char* desc) {
#ifdef ASCII
  int offset,toffset;
  offset = 60;
  toffset = 30;
  switch (helpcol) {
    case 0: offset = 60; toffset = 30; break;
    case 1: offset = 700; toffset = 230; break;
    case 2: offset = 1320; toffset = 430; break;
    }
  putimage(offset, helprow * 27 + 27 * 5,select_sprite(tileNumber),0);
  textcolor(14);
  outtextxy(toffset, 10*helprow+30, desc);
#else
  putimage(helpcol*200,helprow*30,select_sprite(tileNumber),0);
  outtextxy(helpcol*200+30,helprow*30+15,desc);
#endif
  helprow++;
  if (helprow == maxrow) {
    helprow = 0;
    helpcol++;
    if (helpcol == maxcol) {
#ifdef ASCII
      gotoxy(28,23); txt_write("Press any key to continue");
#else
      outtextxy(200, screen_height - 20, "Press any key to continue");
#endif
      inkey();
      clrscr();
      helpcol = 0;
      }
    }
  }

void show_icons() {
  maxcol = 3;
  maxrow = 16;
#ifndef ASCII
  maxcol = screen_width / 200;
  maxrow = (screen_height - 50) / 30;
#endif
  graphmode();
  helpcol = 0;
  helprow = 0;
  show_icon_help(1, "Plains");
  show_icon_help(2, "Forest");
  show_icon_help(3, "Mountains");
  show_icon_help(4, "Water");
  show_icon_help(5, "City");
  show_icon_help(6, "Swamp");
  show_icon_help(7, "Floor");
  show_icon_help(8, "Desert");
  show_icon_help(9, "Hills");
  show_icon_help(11, "Dungeon");
  show_icon_help(12, "Player Ship");
  show_icon_help(14, "Dock");
  show_icon_help(15, "Floor");
  show_icon_help(17, "Village");
  show_icon_help(20, "Tree");
  show_icon_help(21, "Wall");
  show_icon_help(22, "Closed Door");
  show_icon_help(23, "Open Door");
  show_icon_help(33, "Jammed Door");
  show_icon_help(24, "Down Stairs");
  show_icon_help(25, "Up Stairs");
  show_icon_help(28, "Merchant");
  show_icon_help(31, "Gateway");
  show_icon_help(35, "Player");
  show_icon_help(36, "Sleeping");
  show_icon_help(37, "Sound");
  show_icon_help(38, "Fire Wall");
  show_icon_help(39, "Water Wall");
  show_icon_help(40, "Disarmed Trap");
  show_icon_help(41, "Force Field");
  show_icon_help(42, "Phase Door");
  show_icon_help(43, "Light");
  show_icon_help(44, "Fire Res.");
  show_icon_help(45, "Giant Strength");
  show_icon_help(46, "Poisoned");
  show_icon_help(47, "Protection");
  show_icon_help(48, "Ethereal");
  show_icon_help(49, "Less Ethereal");
  show_icon_help(50, "Hasted");
  show_icon_help(51, "Edge Weapon");
  show_icon_help(52, "Pole Weapon");
  show_icon_help(53, "Bow");
  show_icon_help(54, "Crossbow");
  show_icon_help(55, "Armor");
  show_icon_help(56, "Helmet");
  show_icon_help(57, "Shield");
  show_icon_help(58, "Scroll");
  show_icon_help(61, "Potion");
  show_icon_help(69, "Boots");
  show_icon_help(70, "Necklace");
  show_icon_help(71, "Gem");
  show_icon_help(72, "Staff");
  show_icon_help(73, "Cloak");
  show_icon_help(74, "Ring");
  show_icon_help(75, "Crystal Ball");
  show_icon_help(76, "Horn");
  show_icon_help(77, "Cube");
  show_icon_help(78, "Book");
  show_icon_help(79, "Chest");
  show_icon_help(84, "Torch");
  show_icon_help(88, "Lore Book");
  show_icon_help(99, "Food");
  show_icon_help(215, "Gem");
  show_icon_help(237, "Metal Bar");
  show_icon_help(243, "Metal Ore");
  show_icon_help(315, "Altar");
  show_icon_help(319, "Runestone");
  show_icon_help(326, "Bandage");
  show_icon_help(329, "Unarmed Trap");
  show_icon_help(330, "Armed Trap");
  show_icon_help(332, "Figurine");
  show_icon_help(352, "Herb");
  show_icon_help(353, "Flare");

  show_icon_help(101, "Air Elemental");
  show_icon_help(102, "Insectoid");
  show_icon_help(103, "Rodent");
  show_icon_help(104, "Large Animal");
  show_icon_help(105, "Beholder Like");
  show_icon_help(107, "Blob");
  show_icon_help(108, "Roper");
  show_icon_help(109, "Bulette");
  show_icon_help(110, "Centipede Like");
  show_icon_help(111, "Fire Elemental");
  show_icon_help(112, "Water Elemental");
  show_icon_help(113, "Earth Elemental");
  show_icon_help(114, "Efreeti");
  show_icon_help(115, "Gargoyle Like");
  show_icon_help(116, "Gelatinous Cube");
  show_icon_help(117, "Griffon");
  show_icon_help(118, "Ghost Like");
  show_icon_help(119, "Harpy");
  show_icon_help(120, "Dog Like");
  show_icon_help(121, "Dwarf Like");
  show_icon_help(122, "Hydra");
  show_icon_help(123, "Orc Like");
  show_icon_help(124, "Lamia");
  show_icon_help(125, "Skeleton Like");
  show_icon_help(126, "Lizard");
  show_icon_help(127, "Manticore");
  show_icon_help(128, "Medusa");
  show_icon_help(129, "Mind Flayer");
  show_icon_help(130, "Minotaur");
  show_icon_help(131, "Horse Like");
  show_icon_help(132, "Unicorn");
  show_icon_help(133, "Pegasus");
  show_icon_help(134, "Frog");
  show_icon_help(135, "Giant");
  show_icon_help(136, "Mummy Like");
  show_icon_help(137, "Naga");
  show_icon_help(138, "Nightmare");
  show_icon_help(139, "Nymph Like");
  show_icon_help(140, "Sprite Like");
  show_icon_help(141, "Purple Worm");
  show_icon_help(142, "Scorpion");
  show_icon_help(143, "Snake Like");
  show_icon_help(144, "Sphinx");
  show_icon_help(145, "Spider");
  show_icon_help(146, "Umber Hulk");
  show_icon_help(147, "Will o Wisp");
  show_icon_help(148, "Centaur");
  show_icon_help(149, "DemoGorgon");
  show_icon_help(150, "Orcus");
  show_icon_help(151, "Succubus");
  show_icon_help(152, "Demon Like");
  show_icon_help(154, "Dragon");
  show_icon_help(161, "Female Humanoid");
  show_icon_help(162, "Male Humanoid");
  show_icon_help(163, "Fighter");
  show_icon_help(164, "Cleric");
  show_icon_help(165, "Wizard");
  show_icon_help(166, "Dark Magi");
#ifdef ASCII
   gotoxy(28,23); txt_write("Press any key to continue");
#else
  outtextxy(200, screen_height - 20, "Press any key to continue");
#endif
  inkey();
  show_screen();
  }

