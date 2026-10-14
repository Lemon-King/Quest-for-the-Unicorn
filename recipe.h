#ifdef MAIN

/*  Obj   Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
RECIPE recipes[] = {
  /* Amulet of fire resistance */
  { T_022,T_023,T_024,T_025,T_026,T_027,T_028,    0,    0,    0,    0,    0 },
  /* Mithril Crossbow */
  { T_029,T_030,T_031,T_031,T_032,    0,    0,    0,    0,    0,    0,    0 },
  /* Flame Sword */
  { T_033,T_030,T_034,T_032,T_035,T_035,T_035,T_035,T_035,T_035,T_035,T_035 },
  /* Ring of Food Detection */
  { T_037,T_023,T_038,T_039,T_040,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Up Detection */
  { T_041,T_023,T_038,T_042,T_043,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Down Detection */
  { T_044,T_023,T_038,T_045,T_043,    0,    0,    0,    0,    0,    0,    0 },
  /* Sun Sword */
  { T_046,T_030,T_033,T_005,T_047,T_048,T_049,    0,    0,    0,    0,    0 },
  /* Ring of Experience Gain */
  { T_050,T_023,T_038,T_051,T_052,T_053,    0,    0,    0,    0,    0,    0 },
  /* Golden Shield */
  { T_054,T_030,T_055,T_056,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Mithril Shield */
  { T_057,T_030,T_055,T_032,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Golden Helm */
  { T_058,T_030,T_059,T_056,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Mithril Helm */
  { T_060,T_030,T_059,T_032,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Mithril Bar */
  { T_032,T_030,T_067,T_067,T_067,T_067,T_067,T_067,T_067,T_067,T_067,T_067 },
  /* Gold Bar */
  { T_056,T_030,T_062,T_062,T_062,T_062,T_062,T_062,T_062,T_062,T_062,T_062 },
  /* Silver Bar */
  { T_063,T_030,T_064,T_064,T_064,T_064,T_064,T_064,T_064,T_064,T_064,T_064 },
  /* Copper Bar */
  { T_065,T_030,T_066,T_066,T_066,T_066,T_066,T_066,T_066,T_066,T_066,T_066 },
  /* White Gold Bar */
  { T_068,T_030,T_056,T_063,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Cure Poison */
  { T_069,T_071,T_070,T_070,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Healing */
  { T_072,T_071,T_073,T_074,T_074,T_074,T_074,    0,    0,    0,    0,    0 },
  /* Potion of Xtra Healing */
  { T_075,T_071,T_073,T_076,T_076,T_076,T_076,    0,    0,    0,    0,    0 },
  /* Potion of Super Healing */
  { T_077,T_071,T_073,T_075,T_075,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Miracle Healing */
  { T_078,T_071,T_073,T_077,T_077,    0,    0,    0,    0,    0,    0,    0 },
  /* Mahrkaaf Solution */
  { T_079,T_071,T_073,T_078,T_078,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Cureall */
  { T_080,T_071,T_073,T_081,T_082,T_083,T_069,T_072,    0,    0,    0,    0 },
  /* Potion of Sight */
  { T_083,T_071,T_073,T_084,T_074,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Bravery */
  { T_082,T_071,T_073,T_085,T_074,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Clear Headedness */
  { T_081,T_071,T_073,T_086,T_074,    0,    0,    0,    0,    0,    0,    0 },
  /* Holy Water */
  { T_087,T_071,T_073,T_088,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Scroll of Enchant Weapon */
  { T_020,T_089,T_090,T_091,T_092,T_087,    0,    0,    0,    0,    0,    0 },
  /* Weapon Powder */
  { T_092,T_030,T_093,T_094,T_095,T_096,T_097,T_068,T_098,    0,    0,    0 },
  /* Scroll of Enchant Armour */
  { T_021,T_089,T_090,T_091,T_099,T_087,    0,    0,    0,    0,    0,    0 },
  /* Armour Powder */
  { T_099,T_030,T_055,T_100,T_101,T_059,T_068,T_098,    0,    0,    0,    0 },
  /* Protein Shake */
  { T_102,T_071,T_073,T_103,T_104,T_105,T_106,    0,    0,    0,    0,    0 },
  /* Fruit Punch */
  { T_107,T_071,T_073,T_108,T_109,T_110,T_111,    0,    0,    0,    0,    0 },
  /* Vegitable Juice */
  { T_112,T_071,T_073,T_113,T_114,T_115,T_116,    0,    0,    0,    0,    0 },
  /* Potion of Health */
  { T_117,T_071,T_073,T_102,T_107,T_112,    0,    0,    0,    0,    0,    0 },
  /* Potion of Extra Health */
  { T_118,T_071,T_073,T_117,T_117,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Fitness */
  { T_119,T_071,T_073,T_118,T_118,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Extra Fitness */
  { T_120,T_071,T_073,T_119,T_119,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Haleness */
  { T_121,T_071,T_073,T_120,T_120,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Nourishment */
  { T_122,T_023,T_038,T_123,T_025,T_124,T_121,T_121,    0,    0,    0,    0 },
  /* Pepper Spray */
  { T_125,T_071,T_073,T_116,T_126,T_127,    0,    0,    0,    0,    0,    0 },
  /* Platemail of the Archmagi */
  { T_128,T_030,T_100,T_129,T_021,    0,    0,    0,    0,    0,    0,    0 },
  /* Robe of Invincibility */
  { T_130,T_131,T_132,T_133,T_134,T_088,    0,    0,    0,    0,    0,    0 },
  /* Poison Spear */
  { T_135,    0,T_136,T_137,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Poison Dagger */
  { T_138,    0,T_093,T_137,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Poison Blade */
  { T_139,    0,T_140,T_137,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Robe of Many Colors */
  { T_141,T_131,T_142,T_143,T_144,    0,    0,    0,    0,    0,    0,    0 },
  /* Robe of White */
  { T_132,T_131,T_141,T_087,T_087,T_087,T_087,    0,    0,    0,    0,    0 },
  /* Honey Milk */
  { T_145,T_071,T_103,T_146,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Bread */
  { T_147,T_071,T_073,T_148,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* S.O.S. */
  { T_149,T_071,T_105,T_150,T_103,T_148,T_151,    0,    0,    0,    0,    0 },
  /* Stew */
  { T_153,T_071,T_105,T_150,T_115,T_152,T_148,T_073,    0,    0,    0,    0 },
  /* Steak Dinner */
  { T_155,T_071,T_105,T_150,T_151,T_113,T_152,T_154,T_106,    0,    0,    0 },
  /* Ring of Levitation */
  { T_156,T_023,T_038,T_157,T_158,    0,    0,    0,    0,    0,    0,    0 },
  /* Broom of Flying */
  { T_159,    0,T_160,T_157,T_161,T_088,    0,    0,    0,    0,    0,    0 },

  { 999,999,999,999,  0,  0,  0,  0,  0,  0, 0, 0 },   /* EOL */
  };

#else

extern RECIPE recipes[];

#endif

