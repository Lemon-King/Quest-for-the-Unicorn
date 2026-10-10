#ifdef MAIN

#define CR_ANVIL     T_030
#define CR_QUILL     T_089
#define CR_INK       T_090
#define CR_HOTPL     T_071
#define CR_PLIER     T_023
#define CR_NEEDL     T_131

/*

typedef struct {
  int object;
  int craft_item;
  int object1;
  int object2;
  int object3;
  int object4;
  int object5;
  int object6;
  int object7;
  int object8;
  int object9;
  int object10;
  } RECIPE;
*/

/*  Obj   Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
RECIPE recipes[] = {
  /* Amulet of fire resistance */
  { T_022,T_023,T_024,T_025,T_026,T_027,T_028,    0,    0,    0,    0,    0 },
  /* Mithril Crossbow */
  { T_029,T_030,T_031,T_031,T_032,    0,    0,    0,    0,    0,    0,    0 },
  /* Holy Water */
  { T_087,T_071,T_073,T_088,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Pepper Spray */
  { T_125,T_071,T_073,T_116,T_126,T_127,    0,    0,    0,    0,    0,    0 },
  /* Poison Spear */
  { T_135,    0,T_136,T_137,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Broom of Flying */
  { T_159,    0,T_160,T_157,T_161,T_088,    0,    0,    0,    0,    0,    0 },

/* Armor */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Platemail of the Archmagi */
  { T_128,CR_ANVIL,T_100,T_129,T_021,    0,    0,    0,    0,    0,    0,    0 },

/* Robes */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Robe of Many Colors */
  { T_141,CR_NEEDL,T_142,T_143,T_144,    0,    0,    0,    0,    0,    0,    0 },
  /* Robe of White */
  { T_132,CR_NEEDL,T_141,T_087,T_087,T_087,T_087,    0,    0,    0,    0,    0 },
  /* Robe of Invincibility */
  { T_130,CR_NEEDL,T_132,T_133,T_134,T_088,    0,    0,    0,    0,    0,    0 },

/* Helms */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Golden Helm */
  { T_058,CR_ANVIL,T_059,T_056,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Mithril Helm */
  { T_060,CR_ANVIL,T_059,T_032,    0,    0,    0,    0,    0,    0,    0,    0 },

/* Shields */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Golden Shield */
  { T_054,CR_ANVIL,T_055,T_056,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Mithril Shield */
  { T_057,CR_ANVIL,T_055,T_032,    0,    0,    0,    0,    0,    0,    0,    0 },

/* Mats */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Mithril Bar */
  { T_032,CR_ANVIL,T_067,T_067,T_067,T_067,T_067,T_067,T_067,T_067,T_067,T_067 },
  /* Gold Bar */
  { T_056,CR_ANVIL,T_062,T_062,T_062,T_062,T_062,T_062,T_062,T_062,T_062,T_062 },
  /* Silver Bar */
  { T_063,CR_ANVIL,T_064,T_064,T_064,T_064,T_064,T_064,T_064,T_064,T_064,T_064 },
  /* Copper Bar */
  { T_065,CR_ANVIL,T_066,T_066,T_066,T_066,T_066,T_066,T_066,T_066,T_066,T_066 },
  /* Iron Bar */
  { T_529,CR_ANVIL,T_528,T_528,T_528,T_528,T_528,T_528,T_528,T_528,T_528,T_528 },
  /* Steel Bar */
  { T_530,CR_ANVIL,T_529,T_531,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* White Gold Bar */
  { T_068,CR_ANVIL,T_056,T_063,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Adamantite Bar */
  { T_169,CR_ANVIL,T_068,T_068,T_032,T_032,    0,    0,    0,    0,    0,    0 },
  /* Weapon Powder */
  { T_092,CR_ANVIL,T_093,T_094,T_095,T_096,T_097,T_068,T_098,    0,    0,    0 },
  /* Armour Powder */
  { T_099,CR_ANVIL,T_055,T_100,T_101,T_059,T_068,T_098,    0,    0,    0,    0 },

/* Throwing Stars */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Iron Throwing Star */
  { T_524,CR_ANVIL,T_523,T_529,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Steel Throwing Star */
  { T_525,CR_ANVIL,T_524,T_530,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Mithril Throwing Star */
  { T_526,CR_ANVIL,T_525,T_032,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Adamantite Throwing Star */
  { T_527,CR_ANVIL,T_526,T_169,    0,    0,    0,    0,    0,    0,    0,    0 },

/* Food */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Honey Milk */
  { T_145,CR_HOTPL,T_103,T_146,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Bread */
  { T_147,CR_HOTPL,T_073,T_148,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* S.O.S. */
  { T_149,CR_HOTPL,T_105,T_150,T_103,T_148,T_151,    0,    0,    0,    0,    0 },
  /* Stew */
  { T_153,CR_HOTPL,T_105,T_150,T_115,T_152,T_148,T_073,    0,    0,    0,    0 },
  /* Steak Dinner */
  { T_155,CR_HOTPL,T_105,T_150,T_151,T_113,T_152,T_154,T_106,    0,    0,    0 },
  /* Protein Shake */
  { T_102,CR_HOTPL,T_073,T_103,T_104,T_105,T_106,    0,    0,    0,    0,    0 },
  /* Fruit Punch */
  { T_107,CR_HOTPL,T_073,T_108,T_109,T_110,T_111,    0,    0,    0,    0,    0 },
  /* Vegitable Juice */
  { T_112,CR_HOTPL,T_073,T_113,T_114,T_115,T_116,    0,    0,    0,    0,    0 },
  /* Green Beer */
  { T_265,       0,T_263,T_264,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Corned Beef and Cabbage */
  { T_278,CR_HOTPL,T_279,T_280,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Mashed Potatoes */
  { T_289,CR_HOTPL,T_103,T_150,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Turkey Dinner */
  { T_290,CR_HOTPL,T_289,T_291,T_113,    0,    0,    0,    0,    0,    0,    0 },

/* Jewels */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Apprentice's Jewel */
  { T_170,CR_PLIER,T_169,T_171,T_172,    0,    0,    0,    0,    0,    0,    0 },
  /* Wizard's Jewel */
  { T_173,CR_PLIER,T_170,T_039,T_174,    0,    0,    0,    0,    0,    0,    0 },
  /* Mage's Jewel */
  { T_175,CR_PLIER,T_173,T_123,T_042,    0,    0,    0,    0,    0,    0,    0 },
  /* Arch-Mage's Jewel */
  { T_176,CR_PLIER,T_175,T_177,T_178,    0,    0,    0,    0,    0,    0,    0 },
  /* Jewel of Ability */
  { T_162,CR_PLIER,T_163,T_164,T_165,T_166,T_167,T_168,    0,    0,    0,    0 },

/* Scrolls  */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Scroll of Add Socket */
  { T_220,CR_QUILL,T_091,T_090,T_217,    0,    0,    0,    0,    0,    0,    0 },
  /* Scroll of Unsocket */
  { T_254,CR_QUILL,T_091,T_090,T_253,T_220,    0,    0,    0,    0,    0,    0 },
  /* Scroll of Disenchantment */
  { T_253,CR_QUILL,T_091,T_090,T_251,T_252,    0,    0,    0,    0,    0,    0 },
  /* Major STR Enchant */
  { T_221,CR_QUILL,T_091,T_090,T_124,    0,    0,    0,    0,    0,    0,    0 },
  /* Major DEX Enchant */
  { T_222,CR_QUILL,T_091,T_090,T_215,    0,    0,    0,    0,    0,    0,    0 },
  /* Major INT Enchant */
  { T_223,CR_QUILL,T_091,T_090,T_185,    0,    0,    0,    0,    0,    0,    0 },
  /* Major WIS Enchant */
  { T_224,CR_QUILL,T_091,T_090,T_208,    0,    0,    0,    0,    0,    0,    0 },
  /* Major CON Enchant */
  { T_225,CR_QUILL,T_091,T_090,T_048,    0,    0,    0,    0,    0,    0,    0 },
  /* Major CHR Enchant */
  { T_226,CR_QUILL,T_091,T_090,T_227,    0,    0,    0,    0,    0,    0,    0 },
  /* Scroll of Stats Enchant */
  { T_228,CR_QUILL,T_091,T_090,T_162,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor STR Enchant */
  { T_221,CR_QUILL,T_091,T_090,T_158,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor DEX Enchant */
  { T_230,CR_QUILL,T_091,T_090,T_235,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor INT Enchant */
  { T_231,CR_QUILL,T_091,T_090,T_237,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor WIS Enchant */
  { T_224,CR_QUILL,T_091,T_090,T_238,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor CON Enchant */
  { T_233,CR_QUILL,T_091,T_090,T_236,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor CHR Enchant */
  { T_234,CR_QUILL,T_091,T_090,T_239,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor Hit Enchant */
  { T_242,CR_QUILL,T_091,T_090,T_240,    0,    0,    0,    0,    0,    0,    0 },
  /* Major Hit Enchant */
  { T_243,CR_QUILL,T_091,T_090,T_241,    0,    0,    0,    0,    0,    0,    0 },
  /* Super Hit Enchant */
  { T_244,CR_QUILL,T_091,T_090,T_216,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor Mana Enchant */
  { T_245,CR_QUILL,T_091,T_090,T_172,    0,    0,    0,    0,    0,    0,    0 },
  /* Major Mana Enchant */
  { T_246,CR_QUILL,T_091,T_090,T_174,    0,    0,    0,    0,    0,    0,    0 },
  /* Super Mana Enchant */
  { T_247,CR_QUILL,T_091,T_090,T_042,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor Health Enchant */
  { T_248,CR_QUILL,T_091,T_090,T_171,    0,    0,    0,    0,    0,    0,    0 },
  /* Major Health Enchant */
  { T_249,CR_QUILL,T_091,T_090,T_039,    0,    0,    0,    0,    0,    0,    0 },
  /* Super Health Enchant */
  { T_250,CR_QUILL,T_091,T_090,T_123,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor Attack Enchant */
  { T_257,CR_QUILL,T_091,T_090,T_255,    0,    0,    0,    0,    0,    0,    0 },
  /* Major Attack Enchant */
  { T_258,CR_QUILL,T_091,T_090,T_256,    0,    0,    0,    0,    0,    0,    0 },
  /* Super Attack Enchant */
  { T_259,CR_QUILL,T_091,T_090,T_045,    0,    0,    0,    0,    0,    0,    0 },
  /* Minor Defense Enchant */
  { T_260,CR_QUILL,T_091,T_090,T_027,    0,    0,    0,    0,    0,    0,    0 },
  /* Major Defense Enchant */
  { T_261,CR_QUILL,T_091,T_090,T_026,    0,    0,    0,    0,    0,    0,    0 },
  /* Super Defense Enchant */
  { T_262,CR_QUILL,T_091,T_090,T_025,    0,    0,    0,    0,    0,    0,    0 },
  /* Scroll of Enchant Armour */
  { T_021,CR_QUILL,T_090,T_091,T_099,T_087,    0,    0,    0,    0,    0,    0 },
  /* Scroll of Enchant Weapon */
  { T_020,CR_QUILL,T_090,T_091,T_092,T_087,    0,    0,    0,    0,    0,    0 },
  /* Minor Spell Power Enchant */
  { T_478,CR_QUILL,T_091,T_090,T_476,    0,    0,    0,    0,    0,    0,    0 },
  /* Major Spell Power Enchant */
  { T_479,CR_QUILL,T_091,T_090,T_477,    0,    0,    0,    0,    0,    0,    0 },
  /* Super Spell Power Enchant */
  { T_480,CR_QUILL,T_091,T_090,T_472,    0,    0,    0,    0,    0,    0,    0 },

/* Potions  */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Potion of Health */
  { T_117,CR_HOTPL,T_073,T_102,T_107,T_112,    0,    0,    0,    0,    0,    0 },
  /* Potion of Extra Health */
  { T_118,CR_HOTPL,T_073,T_117,T_117,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Fitness */
  { T_119,CR_HOTPL,T_073,T_118,T_118,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Extra Fitness */
  { T_120,CR_HOTPL,T_073,T_119,T_119,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Haleness */
  { T_121,CR_HOTPL,T_073,T_120,T_120,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Cureall */
  { T_080,CR_HOTPL,T_073,T_081,T_082,T_083,T_069,T_072,    0,    0,    0,    0 },
  /* Potion of Sight */
  { T_083,CR_HOTPL,T_073,T_084,T_074,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Bravery */
  { T_082,CR_HOTPL,T_073,T_085,T_074,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Clear Headedness */
  { T_081,CR_HOTPL,T_073,T_086,T_074,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Cure Poison */
  { T_069,CR_HOTPL,T_070,T_070,T_643,T_647,    0,    0,    0,    0,    0,    0 },
  /* Potion of Healing */
  { T_072,CR_HOTPL,T_073,T_074,T_074,T_074,T_074,    0,    0,    0,    0,    0 },
  /* Potion of Xtra Healing */
  { T_075,CR_HOTPL,T_073,T_076,T_076,T_076,T_076,    0,    0,    0,    0,    0 },
  /* Potion of Super Healing */
  { T_077,CR_HOTPL,T_073,T_075,T_075,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion of Miracle Healing */
  { T_078,CR_HOTPL,T_073,T_077,T_077,    0,    0,    0,    0,    0,    0,    0 },
  /* Mahrkaaf Solution */
  { T_079,CR_HOTPL,T_073,T_078,T_078,    0,    0,    0,    0,    0,    0,    0 },

/* Rings  */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Socketed Ring */
  { T_217,CR_PLIER,T_038,T_056,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Double Socketed Ring */
  { T_218,CR_PLIER,T_217,T_056,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Triple Socketed Ring */
  { T_219,CR_PLIER,T_218,T_056,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Food Detection */
  { T_037,CR_PLIER,T_038,T_039,T_040,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Up Detection */
  { T_041,CR_PLIER,T_038,T_042,T_043,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Down Detection */
  { T_044,CR_PLIER,T_038,T_045,T_043,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Levitation */
  { T_156,CR_PLIER,T_038,T_157,T_158,    0,    0,    0,    0,    0,    0,    0 },
  /* Ring of Nourishment */
  { T_122,CR_PLIER,T_038,T_123,T_025,T_124,T_121,T_121,    0,    0,    0,    0 },
  /* Ring of Experience Gain */
  { T_050,CR_PLIER,T_038,T_051,T_052,T_053,    0,    0,    0,    0,    0,    0 },

/* Daggers */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Copper Dagger */
  { T_179,CR_ANVIL,T_093,T_065,T_065,    0,    0,    0,    0,    0,    0,    0 },
  /* Silver Dagger */
  { T_180,CR_ANVIL,T_179,T_063,T_063,T_063,    0,    0,    0,    0,    0,    0 },
  /* Gold Dagger */
  { T_181,CR_ANVIL,T_180,T_056,T_056,T_056,T_056,    0,    0,    0,    0,    0 },
  /* Mithril Dagger */
  { T_182,CR_ANVIL,T_181,T_032,T_032,T_032,T_032,T_032,    0,    0,    0,    0 },
  /* Adamantite Dagger */
  { T_183,CR_ANVIL,T_182,T_169,T_169,T_169,T_169,T_169,T_169,    0,    0,    0 },
  /* Dagger of Mystery */
  { T_184,CR_ANVIL,T_183,T_185,T_042,T_123,T_186,    0,    0,    0,    0,    0 },
  /* Poison Dagger */
  { T_138,       0,T_093,T_137,    0,    0,    0,    0,    0,    0,    0,    0 },

/* Swords */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Copper Sword */
  { T_187,CR_ANVIL,T_140,T_065,T_065,    0,    0,    0,    0,    0,    0,    0 },
  /* Silver Sword */
  { T_188,CR_ANVIL,T_187,T_063,T_063,T_063,    0,    0,    0,    0,    0,    0 },
  /* Gold Sword */
  { T_189,CR_ANVIL,T_188,T_056,T_056,T_056,T_056,    0,    0,    0,    0,    0 },
  /* Mithril Sword */
  { T_190,CR_ANVIL,T_189,T_032,T_032,T_032,T_032,T_032,    0,    0,    0,    0 },
  /* Adamantite Sword */
  { T_191,CR_ANVIL,T_190,T_169,T_169,T_169,T_169,T_169,T_169,    0,    0,    0 },
  /* Sword of the Titans */
  { T_192,CR_ANVIL,T_191,T_193,T_123,T_124,    0,    0,    0,    0,    0,    0 },
  /* Poison Blade */
  { T_139,       0,T_140,T_137,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Flame Sword */
  { T_033,CR_ANVIL,T_034,T_032,T_035,T_035,T_035,T_035,T_035,T_035,T_035,T_035 },
  /* Sun Sword */
  { T_046,CR_ANVIL,T_033,T_005,T_047,T_048,T_049,    0,    0,    0,    0,    0 },

/* Axes */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Copper Axe */
  { T_194,CR_ANVIL,T_200,T_065,T_065,    0,    0,    0,    0,    0,    0,    0 },
  /* Silver Axe */
  { T_195,CR_ANVIL,T_194,T_063,T_063,T_063,    0,    0,    0,    0,    0,    0 },
  /* Gold Axe */
  { T_196,CR_ANVIL,T_195,T_056,T_056,T_056,T_056,    0,    0,    0,    0,    0 },
  /* Mithril Axe */
  { T_197,CR_ANVIL,T_196,T_032,T_032,T_032,T_032,T_032,    0,    0,    0,    0 },
  /* Adamantite Axe */
  { T_198,CR_ANVIL,T_197,T_169,T_169,T_169,T_169,T_169,T_169,    0,    0,    0 },
  /* Axe of the Mountain Kings */
  { T_199,CR_ANVIL,T_198,T_193,T_048,T_123,    0,    0,    0,    0,    0,    0 },

/* Maces */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Copper Mace */
  { T_201,CR_ANVIL,T_207,T_065,T_065,    0,    0,    0,    0,    0,    0,    0 },
  /* Silver Mace */
  { T_202,CR_ANVIL,T_201,T_063,T_063,T_063,    0,    0,    0,    0,    0,    0 },
  /* Gold Mace */
  { T_203,CR_ANVIL,T_202,T_056,T_056,T_056,T_056,    0,    0,    0,    0,    0 },
  /* Mithril Mace */
  { T_204,CR_ANVIL,T_203,T_032,T_032,T_032,T_032,T_032,    0,    0,    0,    0 },
  /* Adamantite Mace */
  { T_205,CR_ANVIL,T_204,T_169,T_169,T_169,T_169,T_169,T_169,    0,    0,    0 },
  /* Mace of the Golden Temple */
  { T_206,CR_ANVIL,T_205,T_208,T_186,T_042,    0,    0,    0,    0,    0,    0 },

/* Bows */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Copper Bow */
  { T_209,CR_ANVIL,T_095,T_065,T_065,    0,    0,    0,    0,    0,    0,    0 },
  /* Silver Bow */
  { T_210,CR_ANVIL,T_209,T_063,T_063,T_063,    0,    0,    0,    0,    0,    0 },
  /* Gold Bow */
  { T_211,CR_ANVIL,T_210,T_056,T_056,T_056,T_056,    0,    0,    0,    0,    0 },
  /* Mithril Bow */
  { T_212,CR_ANVIL,T_211,T_032,T_032,T_032,T_032,T_032,    0,    0,    0,    0 },
  /* Adamantite Bow */
  { T_213,CR_ANVIL,T_212,T_169,T_169,T_169,T_169,T_169,T_169,    0,    0,    0 },
  /* Bow of the Golden Temple */
  { T_214,CR_ANVIL,T_213,T_215,T_216,T_045,    0,    0,    0,    0,    0,    0 },

/* Traps */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Small explosive trap */
  { T_456,CR_PLIER,T_454,T_455,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Large explosive trap */
  { T_457,CR_PLIER,T_454,T_455,T_458,    0,    0,    0,    0,    0,    0,    0 },
  /* Huge explosive trap */
  { T_459,CR_PLIER,T_454,T_455,T_458,T_458,T_458,    0,    0,    0,    0,    0 },
  /* Sleep trap */
  { T_463,CR_PLIER,T_454,T_455,T_458,T_468,    0,    0,    0,    0,    0,    0 },
  /* Confusion trap */
  { T_467,CR_PLIER,T_454,T_455,T_458,T_086,    0,    0,    0,    0,    0,    0 },
  /* Fear trap */
  { T_464,CR_PLIER,T_454,T_455,T_458,T_085,    0,    0,    0,    0,    0,    0 },
  /* Blindness trap */
  { T_465,CR_PLIER,T_454,T_455,T_458,T_084,    0,    0,    0,    0,    0,    0 },
  /* Poison trap */
  { T_466,CR_PLIER,T_454,T_455,T_458,T_137,    0,    0,    0,    0,    0,    0 },
  /* Fire trap */
  { T_460,CR_PLIER,T_454,T_455,T_458,T_470,    0,    0,    0,    0,    0,    0 },
  /* Cold trap */
  { T_461,CR_PLIER,T_454,T_455,T_458,T_471,    0,    0,    0,    0,    0,    0 },
  /* Electric trap */
  { T_462,CR_PLIER,T_454,T_455,T_458,T_469,    0,    0,    0,    0,    0,    0 },

/* Gems */
/*  Obj      Craft Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8 Item9 Item10 */
  /* Gem Scribe */
  { T_405,CR_ANVIL,T_131,T_023,T_090,    0,    0,    0,    0,    0,    0,    0 },

  /* Etched Amber */
  { T_381,CR_PLIER,T_405,T_042,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Amethyst */
  { T_382,CR_PLIER,T_405,T_045,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Ruby */
  { T_383,CR_PLIER,T_405,T_025,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Emerald */
  { T_384,CR_PLIER,T_405,T_123,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Saphire */
  { T_385,CR_PLIER,T_405,T_124,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Diamond */
  { T_387,CR_PLIER,T_405,T_386,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Pearl */
  { T_388,CR_PLIER,T_405,T_048,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Black Pearl */
  { T_389,CR_PLIER,T_405,T_185,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Obsidian */
  { T_390,CR_PLIER,T_405,T_208,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched White Obsidian */
  { T_391,CR_PLIER,T_405,T_227,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Quartz */
  { T_392,CR_PLIER,T_405,T_216,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Rose Quartz */
  { T_393,CR_PLIER,T_405,T_193,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Opal */
  { T_394,CR_PLIER,T_405,T_186,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Jade */
  { T_396,CR_PLIER,T_405,T_395,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Lapis Lazuli */
  { T_398,CR_PLIER,T_405,T_397,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Malachite */
  { T_400,CR_PLIER,T_405,T_399,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Onyx */
  { T_402,CR_PLIER,T_405,T_401,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Fire Opal */
  { T_404,CR_PLIER,T_405,T_403,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Topaz */
  { T_447,CR_PLIER,T_405,T_450,T_087,    0,    0,    0,    0,    0,    0,    0 },
  /* Etched Citrine */
  { T_473,CR_PLIER,T_405,T_472,T_087,    0,    0,    0,    0,    0,    0,    0 },

  /* Runed Amber */
  { T_406,CR_PLIER,T_405,T_381,T_087,T_246,    0,    0,    0,    0,    0,    0 },
  /* Runed Amethyst */
  { T_407,CR_PLIER,T_405,T_382,T_087,T_258,    0,    0,    0,    0,    0,    0 },
  /* Runed Ruby */
  { T_408,CR_PLIER,T_405,T_383,T_087,T_261,    0,    0,    0,    0,    0,    0 },
  /* Runed Emerald */
  { T_409,CR_PLIER,T_405,T_384,T_087,T_249,    0,    0,    0,    0,    0,    0 },
  /* Runed Saphire */
  { T_410,CR_PLIER,T_405,T_385,T_087,T_229,    0,    0,    0,    0,    0,    0 },
  /* Runed Diamond */
  { T_411,CR_PLIER,T_405,T_387,T_087,T_230,    0,    0,    0,    0,    0,    0 },
  /* Runed Pearl */
  { T_412,CR_PLIER,T_405,T_388,T_087,T_233,    0,    0,    0,    0,    0,    0 },
  /* Runed Black Pearl */
  { T_413,CR_PLIER,T_405,T_389,T_087,T_231,    0,    0,    0,    0,    0,    0 },
  /* Runed Obsidian */
  { T_414,CR_PLIER,T_405,T_390,T_087,T_232,    0,    0,    0,    0,    0,    0 },
  /* Runed White Obsidian */
  { T_415,CR_PLIER,T_405,T_391,T_087,T_234,    0,    0,    0,    0,    0,    0 },
  /* Runed Quartz */
  { T_416,CR_PLIER,T_405,T_392,T_087,T_243,    0,    0,    0,    0,    0,    0 },
  /* Runed Rose Quartz */
  { T_417,CR_PLIER,T_405,T_393,T_087,T_249,    0,    0,    0,    0,    0,    0 },
  /* Runed Opal */
  { T_418,CR_PLIER,T_405,T_394,T_087,T_249,    0,    0,    0,    0,    0,    0 },
  /* Runed Jade */
  { T_419,CR_PLIER,T_405,T_396,T_087,T_424,    0,    0,    0,    0,    0,    0 },
  /* Runed Lapis Lazuli */
  { T_420,CR_PLIER,T_405,T_398,T_087,T_014,    0,    0,    0,    0,    0,    0 },
  /* Runed Malachite */
  { T_421,CR_PLIER,T_405,T_400,T_087,T_426,    0,    0,    0,    0,    0,    0 },
  /* Runed Onyx */
  { T_422,CR_PLIER,T_405,T_402,T_087,T_427,    0,    0,    0,    0,    0,    0 },
  /* Runed Fire Opal */
  { T_423,CR_PLIER,T_405,T_404,T_087,T_428,    0,    0,    0,    0,    0,    0 },
  /* Runed Topaz */
  { T_448,CR_PLIER,T_405,T_447,T_087,T_428,    0,    0,    0,    0,    0,    0 },
  /* Runed Citrine */
  { T_474,CR_PLIER,T_405,T_473,T_087,T_014,    0,    0,    0,    0,    0,    0 },

  /* Arcane Amber */
  { T_429,CR_PLIER,T_405,T_406,T_087,T_247,    0,    0,    0,    0,    0,    0 },
  /* Arcane Amethyst */
  { T_430,CR_PLIER,T_405,T_407,T_087,T_259,    0,    0,    0,    0,    0,    0 },
  /* Arcane Ruby */
  { T_431,CR_PLIER,T_405,T_408,T_087,T_262,    0,    0,    0,    0,    0,    0 },
  /* Arcane Emerald */
  { T_432,CR_PLIER,T_405,T_409,T_087,T_250,    0,    0,    0,    0,    0,    0 },
  /* Arcane Saphire */
  { T_433,CR_PLIER,T_405,T_410,T_087,T_221,    0,    0,    0,    0,    0,    0 },
  /* Arcane Diamond */
  { T_434,CR_PLIER,T_405,T_411,T_087,T_222,    0,    0,    0,    0,    0,    0 },
  /* Arcane Pearl */
  { T_435,CR_PLIER,T_405,T_412,T_087,T_225,    0,    0,    0,    0,    0,    0 },
  /* Arcane Black Pearl */
  { T_436,CR_PLIER,T_405,T_413,T_087,T_223,    0,    0,    0,    0,    0,    0 },
  /* Arcane Obsidian */
  { T_437,CR_PLIER,T_405,T_414,T_087,T_224,    0,    0,    0,    0,    0,    0 },
  /* Arcane White Obsidian */
  { T_438,CR_PLIER,T_405,T_415,T_087,T_226,    0,    0,    0,    0,    0,    0 },
  /* Arcane Quartz */
  { T_439,CR_PLIER,T_405,T_416,T_087,T_244,    0,    0,    0,    0,    0,    0 },
  /* Arcane Rose Quartz */
  { T_440,CR_PLIER,T_405,T_417,T_087,T_250,    0,    0,    0,    0,    0,    0 },
  /* Arcane Opal */
  { T_441,CR_PLIER,T_405,T_418,T_087,T_250,    0,    0,    0,    0,    0,    0 },
  /* Arcane Jade */
  { T_442,CR_PLIER,T_405,T_419,T_087,T_425,    0,    0,    0,    0,    0,    0 },
  /* Arcane Lapis Lazuli */
  { T_443,CR_PLIER,T_405,T_420,T_087,T_014,    0,    0,    0,    0,    0,    0 },
  /* Arcane Malachite */
  { T_444,CR_PLIER,T_405,T_421,T_087,T_426,    0,    0,    0,    0,    0,    0 },
  /* Arcane Onyx */
  { T_445,CR_PLIER,T_405,T_422,T_087,T_427,    0,    0,    0,    0,    0,    0 },
  /* Arcane Fire Opal */
  { T_446,CR_PLIER,T_405,T_423,T_087,T_428,    0,    0,    0,    0,    0,    0 },
  /* Arcane Topaz */
  { T_449,CR_PLIER,T_405,T_448,T_087,T_428,    0,    0,    0,    0,    0,    0 },
  /* Arcane Citrine */
  { T_475,CR_PLIER,T_405,T_474,T_087,T_014,    0,    0,    0,    0,    0,    0 },

  /* Rainbow Gem, Small */
  { T_503,CR_PLIER,T_405,T_471,T_470,T_510,T_469,    0,    0,    0,    0,    0 },
  /* Rainbow Gem, Medium */
  { T_504,CR_PLIER,T_405,T_517,T_514,T_511,T_507,    0,    0,    0,    0,    0 },
  /* Rainbow Gem, Large */
  { T_505,CR_PLIER,T_405,T_518,T_515,T_512,T_508,    0,    0,    0,    0,    0 },
  /* Rainbow Gem, Huge */
  { T_506,CR_PLIER,T_405,T_519,T_516,T_513,T_509,    0,    0,    0,    0,    0 },

  /* Armor Deck */
  { T_623,       0,T_597,T_598,T_599,T_600,T_601,T_602,T_603,T_604,T_605,T_606 },
  /* Item Deck, Lower */
  { T_624,       0,T_607,T_608,T_609,T_610,T_611,T_612,T_613,T_614,    0,    0 },
  /* Item Deck, Upper */
  { T_625,       0,T_615,T_616,T_617,T_618,T_619,T_620,T_621,T_622,    0,    0 },
  /* Item Deck */
  { T_626,       0,T_624,T_625,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Weapon Deck, Lower */
  { T_627,       0,T_581,T_582,T_583,T_584,T_585,T_586,T_587,T_588,    0,    0 },
  /* Weapon Deck, Upper */
  { T_628,       0,T_589,T_590,T_591,T_592,T_593,T_594,T_595,T_596,    0,    0 },
  /* Weapon Deck */
  { T_629,       0,T_627,T_628,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Class Deck, Lower */
  { T_630,       0,T_568,T_569,T_570,T_571,T_572,T_573,T_574,T_575,T_576,    0 },
  /* Class Deck, Upper */
  { T_631,       0,T_577,T_578,T_579,T_580,    0,    0,    0,    0,    0,    0 },
  /* Class Deck */
  { T_632,       0,T_630,T_631,    0,    0,    0,    0,    0,    0,    0,    0 },
  /* Monster Deck, Part I */
  { T_633,       0,T_536,T_537,T_538,T_539,T_540,T_541,T_542,T_543,    0,    0 },
  /* Monster Deck, Part II */
  { T_634,       0,T_544,T_545,T_546,T_547,T_548,T_549,T_550,T_551,    0,    0 },
  /* Monster Deck, Part III */
  { T_635,       0,T_552,T_553,T_554,T_555,T_556,T_557,T_558,T_559,    0,    0 },
  /* Monster Deck, Part IV */
  { T_636,       0,T_560,T_561,T_562,T_563,T_564,T_565,T_566,T_567,    0,    0 },
  /* Monster Deck */
  { T_637,       0,T_633,T_634,T_635,T_635,    0,    0,    0,    0,    0,    0 },
  /* Deck of Many Things */
  { T_638,       0,T_623,T_626,T_629,T_632,T_637,    0,    0,    0,    0,    0 },

  /* Potion Minor Mana */
  { T_655,CR_HOTPL,T_663,T_073,T_644,T_650,    0,    0,    0,    0,    0,    0 },
  /* Potion Lesser Mana */
  { T_656,CR_HOTPL,T_655,T_655,T_646,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion Mana */
  { T_657,CR_HOTPL,T_656,T_656,T_653,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion Greater Mana */
  { T_658,CR_HOTPL,T_657,T_657,T_647,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion Greater Mana */
  { T_659,CR_HOTPL,T_658,T_658,T_654,    0,    0,    0,    0,    0,    0,    0 },

  /* Potion Minor Healing */
  { T_660,CR_HOTPL,T_663,T_073,T_640,T_643,    0,    0,    0,    0,    0,    0 },
  /* Potion Lesser Healing */
  { T_661,CR_HOTPL,T_660,T_660,T_646,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion Healing */
  { T_072,CR_HOTPL,T_661,T_661,T_653,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion Greater Healing */
  { T_075,CR_HOTPL,T_072,T_072,T_647,    0,    0,    0,    0,    0,    0,    0 },
  /* Potion Greater Healing */
  { T_662,CR_HOTPL,T_075,T_075,T_654,    0,    0,    0,    0,    0,    0,    0 },

  /* Potion Slow Poison */
  { T_070,CR_HOTPL,T_663,T_073,T_641,T_641,T_641,T_648,T_648,T_648,T_643,    0 },

  /* Potion of Sleep */
  { T_468,CR_HOTPL,T_663,T_073,T_651,T_651,T_651,    0,    0,    0,    0,    0 },

  /* Potion of Clairvoyance */
  { T_664,CR_HOTPL,T_663,T_073,T_642,T_650,T_645,    0,    0,    0,    0,    0 },

  /* Potion of Trap Location */
  { T_665,CR_HOTPL,T_663,T_073,T_649,T_649,T_649,T_652,T_652,T_652,    0,    0 },

  { 999,999,999,999,  0,  0,  0,  0,  0,  0, 0, 0 },   /* EOL */
  };

#else

extern RECIPE recipes[];

#endif

