#include <stdio.h>		//standard c Library
#include "object.h"		//Structs gets declared in header, wich we call upon in object.c and use to define all the diffrent objects(interactables in game

OBJECT objs[] = {
	//7xLocations
	//Description			| tag					|loc |status|weight	| destination
   {"an old mine"			, "mine"				,NULL,NULL	,NULL	,NULL},
   {"a large cave"			, "cave"				,NULL,NULL	,NULL	,NULL},
   {"a dense forest"		, "forest"				,NULL,NULL	,NULL	,NULL},
   {"a cozy hut"			, "hut"					,NULL,NULL	,NULL	,NULL},
   {"a small Bedroom"		, "bedroom"				,NULL,NULL	,NULL	,NULL},
   {"a backyard with a chopping block", "backyard"	,NULL,NULL	,NULL	,NULL},
   {"a chaotic shed"		, "shed"				,NULL,NULL	,NULL	,NULL},

   //15xpathways: Description				| tag					| loc		|status	|weight	|destination
   {"the exit back to the cave"				, "exi_mine"			, mine		,NULL	,NULL	,cave	},
   {"the entrance of a mine"				, "ent_mine"			, cave		,NULL	,NULL	,mine	},
   {"the exit of the cave into a forest"	, "exi_cave"			, cave		,NULL	,NULL	,forest	},
   {"the entrance of a cave"				, "ent_cave"			, forest	,NULL	,NULL	,cave	},
   {"a hut"									, "exi_forest"			, forest	,NULL	,NULL	,hut	},
   {"an old door leading to the outside"	, "ent_forest"			, hut		,NULL	,NULL	,forest	},
   {"a door to the rest of the hut"			, "exi_bedroom"			, bedroom	,NULL	,NULL	,hut	},
   {"a door to a bedroom"					, "ent_bedroom"			, hut		,NULL	,NULL	,bedroom},
   {"a backdoor to the backyard"			, "exi_hut"				, hut		,NULL	,NULL	,backyard},
   {"a rusty old door of the hut"			, "ent_hut"				, backyard	,NULL	,NULL	,hut	},
   {"a path around the house into the forest","exi_backyard"		, backyard	,NULL	,NULL	,forest	},
   {"a path into a backyard"				, "ent_backyard"		, forest	,NULL	,NULL	,backyard},
   {"a large wooden door to the backyard"	, "exi_shed"			, shed		,NULL	,NULL	,backyard},
   {"a shed"								, "ent_shed"			, backyard	,NULL	,NULL	,shed	},
   {"a hole with some runes lying around it", "hole"				, shed		,NULL	,NULL	,NULL	},


   //29xItems that can be interactet with
   //Description			| tag			|loc		|status	|weight	|destination
   {"an old pickaxe"		, "pickaxe"		, forest	, 0		,	5	,NULL},
   {"a gold vein"			, "vein"		, mine		, 0		,	0	,NULL},
   {"an oven"				, "oven"		, hut		, 0		,	1	,NULL},
   {"pure Gold"				, "gold"		, NULL		, 0		,	5	,NULL},
   {"a bearded guard"		, "guard"		, cave		, 0		,	1	,NULL},
   {"a chest"				, "chest"		, hut		, 0		,	1	,NULL},
   {"a rusty sword"			, "sword"		, guard		, 0		,	4	,NULL},
   {"a sharp axe"			, "axe"			, backyard	, 0		,	5	,NULL},
   {"wood"					, "wood"		, NULL		, 0		,	5	,NULL},
   {"a bed"					, "bed"			, bedroom	, 0		,	1	,NULL},
   {"a wardrobe"			, "wardrobe"	, bedroom	, 0		,	1	,NULL},
   {"an old table"			, "table"		, bedroom	, 0		,	1	,NULL},
   {"a paper pile"			, "paper"		, table		, 0		,	4	,NULL},
   {"a small box"			, "box"			, NULL		, 0		,	5	,NULL},
   {"a small golden key"	, "key"			, chest		, 1		,	5	,NULL},
   {"a small note"			, "note"		, table		, 0		,	4	,NULL},
   {"keychain"				, "keychain"	, guard		, 0		,	4	,NULL},
   {"a heavy door"			, "door"		, guard		, 0		,	0	,NULL},
   {"an empty rack"			, "rack"		, shed		, 0		,	1	,NULL},
   {"an old picture of a young man","picture",table		, 0		,	4	,NULL},
   {"a rusty helmet"		, "helmet"		, chest		, 0		,	5	,NULL},
   {"a typical Bowler hat "	, "hat"			, wardrobe	, 0		,	4	,NULL},
   {"a juicy watermelon"	, "watermelon"	, fridge	, 0		,	5	,NULL},
   {"the peel of the watermelon", "peel"	, NULL		, 0		,	5	,NULL},
   {"a mystical rune"		, "rune"		, NULL		, 0		,	1	,NULL},
   {"an old fridge"			, "fridge"		, hut		, 0		,	1	,NULL},
   {"a compost heap"		, "heap"		, backyard	, 0		,	1	,NULL},
   {"a small rock"			, "rock"		, cave		, 0		,	5	,NULL},
   {"raw gold ore"			, "rawgold"		, NULL		, 0		,	5	,NULL},
																

   /*weight 0, NULL: an Object of the world(door, entrance ect.)
	* weight 1: too heavy
	* weight 2: open for special Objects(not yet implemented)
	* weight 4: private objects from guard for example
	* weight 5: Object can be picked up*/

	//Player information												 
	{"yourself"				, "yourself"	, cave		, 0	,	NULL,NULL}		 
};																	 
