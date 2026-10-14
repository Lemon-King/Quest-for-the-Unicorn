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

void show_icons() {
  char key;
  graphmode();
  putimage(0,0,select_sprite(1),0);       outtextxy(30,10,"Plains");
  putimage(0,30,select_sprite(2),0);      outtextxy(30,40,"Forest");
  putimage(0,60,select_sprite(3),0);      outtextxy(30,70,"Mountains");
  putimage(0,90,select_sprite(4),0);      outtextxy(30,100,"Water");
  putimage(0,120,select_sprite(5),0);     outtextxy(30,130,"City");
  putimage(0,150,select_sprite(6),0);     outtextxy(30,160,"Swamp");
  putimage(0,180,select_sprite(7),0);     outtextxy(30,190,"Floor");
  putimage(0,210,select_sprite(8),0);     outtextxy(30,220,"Desert");
  putimage(0,240,select_sprite(9),0);     outtextxy(30,250,"Hills");
  putimage(0,270,select_sprite(11),0);    outtextxy(30,280,"Dungeon");
  putimage(0,300,select_sprite(12),0);    outtextxy(30,310,"Player Ship");
  putimage(0,330,select_sprite(14),0);    outtextxy(30,340,"Dock");
  putimage(0,360,select_sprite(15),0);    outtextxy(30,370,"Floor");
  putimage(0,390,select_sprite(17),0);    outtextxy(30,400,"Village");
  putimage(0,420,select_sprite(20),0);    outtextxy(30,430,"Tree");
  putimage(0,450,select_sprite(21),0);    outtextxy(30,460,"Wall");
  putimage(200,0,select_sprite(22),0);    outtextxy(230,10,"Closed Door");
  putimage(200,30,select_sprite(23),0);   outtextxy(230,40,"Open Door");
  putimage(200,60,select_sprite(33),0);   outtextxy(230,70,"Jammed Door");
  putimage(200,90,select_sprite(24),0);   outtextxy(230,100,"Down Stairs");
  putimage(200,120,select_sprite(25),0);  outtextxy(230,130,"Up Stairs");
  putimage(200,150,select_sprite(28),0);  outtextxy(230,160,"Merchant");
  putimage(200,180,select_sprite(31),0);  outtextxy(230,190,"Gateway");
  putimage(200,210,select_sprite(35),0);  outtextxy(230,220,"Player");
  putimage(200,240,select_sprite(36),0);  outtextxy(230,250,"Sleeping");
  putimage(200,270,select_sprite(37),0);  outtextxy(230,280,"Sound"); 
  putimage(200,300,select_sprite(38),0);  outtextxy(230,310,"Fire Wall");
  putimage(200,330,select_sprite(39),0);  outtextxy(230,340,"Water Wall");
  putimage(200,360,select_sprite(40),0);  outtextxy(230,370,"Disarmed Trap");
  putimage(200,390,select_sprite(41),0);  outtextxy(230,400,"Force Field");
  putimage(200,420,select_sprite(42),0);  outtextxy(230,430,"Phase Door");
  putimage(200,450,select_sprite(43),0);  outtextxy(230,460,"Light");
  putimage(400,0,select_sprite(44),0);    outtextxy(430,10,"Fire Res.");
  putimage(400,30,select_sprite(45),0);   outtextxy(430,40,"Giant Strength");
  putimage(400,60,select_sprite(46),0);   outtextxy(430,70,"Poisoned");
  putimage(400,90,select_sprite(47),0);   outtextxy(430,100,"Protection");
  putimage(400,120,select_sprite(49),0);  outtextxy(430,130,"Ethereal");
  putimage(400,150,select_sprite(48),0);  outtextxy(430,160,"Less Ethereal");
  putimage(400,180,select_sprite(50),0);  outtextxy(430,190,"Hasted");
  putimage(400,210,select_sprite(51),0);  outtextxy(430,220,"Edge Weapon");
  putimage(400,240,select_sprite(52),0);  outtextxy(430,250,"Pole Weapon");
  putimage(400,270,select_sprite(53),0);  outtextxy(430,280,"Bow");
  putimage(400,300,select_sprite(54),0);  outtextxy(430,310,"Crossbow");
  putimage(400,330,select_sprite(55),0);  outtextxy(430,340,"Armour");
  putimage(400,360,select_sprite(56),0);  outtextxy(430,370,"Helmet");
  putimage(400,390,select_sprite(57),0);  outtextxy(430,400,"Shield");
  putimage(400,420,select_sprite(58),0);  outtextxy(430,430,"Scroll");
  putimage(400,450,select_sprite(61),0);  outtextxy(430,460,"Potion");
  key = inkey();
  graphmode();
  putimage(0,0,select_sprite(69),0);       outtextxy(30,10,"Boots");
  putimage(0,30,select_sprite(70),0);      outtextxy(30,40,"Necklace");
  putimage(0,60,select_sprite(71),0);      outtextxy(30,70,"Gem");
  putimage(0,90,select_sprite(72),0);      outtextxy(30,100,"Staff");
  putimage(0,120,select_sprite(73),0);     outtextxy(30,130,"Cloak");
  putimage(0,150,select_sprite(74),0);     outtextxy(30,160,"Ring");
  putimage(0,180,select_sprite(75),0);     outtextxy(30,190,"Crystal Ball");
  putimage(0,210,select_sprite(76),0);     outtextxy(30,220,"Horn");
  putimage(0,240,select_sprite(77),0);     outtextxy(30,250,"Cube");
  putimage(0,270,select_sprite(78),0);    outtextxy(30,280,"Book");
  putimage(0,300,select_sprite(79),0);    outtextxy(30,310,"Chest");
  putimage(0,330,select_sprite(84),0);    outtextxy(30,340,"Torch");
  putimage(0,360,select_sprite(88),0);    outtextxy(30,370,"Lore Book");
  putimage(0,390,select_sprite(99),0);    outtextxy(30,400,"Food");
  putimage(0,420,select_sprite(101),0);   outtextxy(30,430,"Air Elemental");
  putimage(0,450,select_sprite(102),0);   outtextxy(30,460,"Insectoid");
  putimage(200,0,select_sprite(103),0);   outtextxy(230,10,"Rodent");
  putimage(200,30,select_sprite(104),0);  outtextxy(230,40,"Large Animal");
  putimage(200,60,select_sprite(105),0);  outtextxy(230,70,"Beholder Like");
  putimage(200,90,select_sprite(106),0);  outtextxy(230,100,"Blob");
  putimage(200,120,select_sprite(108),0); outtextxy(230,130,"Roper");
  putimage(200,150,select_sprite(109),0); outtextxy(230,160,"Bulette");
  putimage(200,180,select_sprite(110),0); outtextxy(230,190,"Centipede Like");
  putimage(200,210,select_sprite(111),0); outtextxy(230,220,"Fire Elemental");
  putimage(200,240,select_sprite(112),0); outtextxy(230,250,"Water Elemental");
  putimage(200,270,select_sprite(113),0); outtextxy(230,280,"Earth Elemental");
  putimage(200,300,select_sprite(114),0); outtextxy(230,310,"Efreeti");
  putimage(200,330,select_sprite(115),0); outtextxy(230,340,"Gargoyle Like");
  putimage(200,360,select_sprite(116),0); outtextxy(230,370,"Gelatinous Cube");
  putimage(200,390,select_sprite(117),0); outtextxy(230,400,"Griffon");
  putimage(200,420,select_sprite(118),0); outtextxy(230,430,"Ghost Like");
  putimage(200,450,select_sprite(119),0); outtextxy(230,460,"Harpy");
  putimage(400,0,select_sprite(120),0);   outtextxy(430,10,"Dog Like");
  putimage(400,30,select_sprite(121),0);  outtextxy(430,40,"Dwarf Like");
  putimage(400,60,select_sprite(122),0);  outtextxy(430,70,"Hydra");
  putimage(400,90,select_sprite(123),0);  outtextxy(430,100,"Orc Like");
  putimage(400,120,select_sprite(124),0); outtextxy(430,130,"Lamia");
  putimage(400,150,select_sprite(125),0); outtextxy(430,160,"Skeleton Like");
  putimage(400,180,select_sprite(126),0); outtextxy(430,190,"Lizard");
  putimage(400,210,select_sprite(127),0); outtextxy(430,220,"Manticore");
  putimage(400,240,select_sprite(128),0); outtextxy(430,250,"Medusa");
  putimage(400,270,select_sprite(129),0); outtextxy(430,280,"Mind Flayer");
  putimage(400,300,select_sprite(130),0); outtextxy(430,310,"Minotaur");
  putimage(400,330,select_sprite(131),0); outtextxy(430,340,"Horse Like");
  putimage(400,360,select_sprite(132),0); outtextxy(430,370,"Unicorn");
  putimage(400,390,select_sprite(133),0); outtextxy(430,400,"Pegasus");
  putimage(400,420,select_sprite(134),0); outtextxy(430,430,"Frog");
  putimage(400,450,select_sprite(135),0); outtextxy(430,460,"Giant");
  key = inkey();
  graphmode();
  putimage(0,0,select_sprite(136),0);     outtextxy(30,10,"Mummy Like");
  putimage(0,30,select_sprite(137),0);    outtextxy(30,40,"Naga");
  putimage(0,60,select_sprite(138),0);    outtextxy(30,70,"Nightmare");
  putimage(0,90,select_sprite(139),0);    outtextxy(30,100,"Nymph Like");
  putimage(0,120,select_sprite(140),0);   outtextxy(30,130,"Sprite Like");
  putimage(0,150,select_sprite(141),0);   outtextxy(30,160,"Purple Worm");
  putimage(0,180,select_sprite(142),0);   outtextxy(30,190,"Scorpion");
  putimage(0,210,select_sprite(143),0);   outtextxy(30,220,"Snake Like");
  putimage(0,240,select_sprite(144),0);   outtextxy(30,250,"Sphinx");
  putimage(0,270,select_sprite(145),0);   outtextxy(30,280,"Spider");
  putimage(0,300,select_sprite(146),0);   outtextxy(30,310,"Umber Hulk");
  putimage(0,330,select_sprite(147),0);   outtextxy(30,340,"Will o Wisp");
  putimage(0,360,select_sprite(148),0);   outtextxy(30,370,"Centaur");
  putimage(0,390,select_sprite(149),0);   outtextxy(30,400,"DemoGorgon");
  putimage(0,420,select_sprite(150),0);   outtextxy(30,430,"Orcus");
  putimage(0,450,select_sprite(151),0);   outtextxy(30,460,"Succubus");
  putimage(200,0,select_sprite(152),0);   outtextxy(230,10,"Demon Like");
  putimage(200,30,select_sprite(154),0);  outtextxy(230,40,"Dragon");
  putimage(200,60,select_sprite(161),0);  outtextxy(230,70,"Female Humanoid");
  putimage(200,90,select_sprite(162),0);  outtextxy(230,100,"Male Humanoid");
  putimage(200,120,select_sprite(163),0); outtextxy(230,130,"Fighter");
  putimage(200,150,select_sprite(164),0); outtextxy(230,160,"Cleric");
  putimage(200,180,select_sprite(165),0); outtextxy(230,190,"Wizard");
  putimage(200,210,select_sprite(166),0); outtextxy(230,220,"Dark Magi");
  key = inkey();
  show_screen();
  }

