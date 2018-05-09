#pragma once
#define COUNT_FILES 8
#define COUNT_STRS_TRANSLETE 97
#include <iostream>
#include "object.h"
extern string langs[2][COUNT_STRS_TRANSLETE];
extern int count_strs_all[8];
extern int lang_now;
extern std::string config_path;
extern enum lang {
	rus,
	eng
};
extern enum namefile{
	aboutme,
	readme,
	aboutprog
};
extern enum slides{
	none=-1,
	start,
	change_lang,
	menu,
	edit_config,
	demonstration,
	fly,
	helicopter,
	airplane,
	color,
	coloredheli
};
namespace Style {
	extern enum style {
		SPEED          = 1 << 0,
		HEIGHT         = 1 << 1,
		DISTANCE       = 1 << 2,
		NUM_OF_PASS    = 1 << 3,
		NUM_OF_SCREW   = 1 << 4,
		CAPACITY       = 1 << 5,
		NUM_OF_ENGINES = 1 << 6,
		RED            = 1 << 7,
		GREEN          = 1 << 8,
		BLUE           = 1 << 9
	};
}
extern std::string include_files[COUNT_FILES];

/*
0: rus.txt  97
1: eng.txt  97
2: rus_readme.txt   13
3: rus_aboutme  3
4: rus_aboutprog  28
5: eng_readme  22 
6: eng_aboutme 3
7: eng_aboutprog 32

*/