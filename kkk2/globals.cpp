#include "globals.h"
#include "Fly.h"
/*std::string include_files[] = { "ru.txt", "en.txt", "config.txt", "rus_readme.txt", "rus_aboutme.txt", "rus_aboutprog.txt",
"eng_readme.txt", "eng_aboutme.txt", "eng_aboutprog.txt"};*/
int lang_now = rus;
std::string include_files[COUNT_FILES];
std::string config_path = "config.txt";
int Fly::count = 0;
int Helicopter::count = 0;
int Airplane::count = 0;
int ColoredHeli::count = 0;
string langs[2][COUNT_STRS_TRANSLETE];
int count_strs_all[8] = { COUNT_STRS_TRANSLETE, COUNT_STRS_TRANSLETE,13,3,28,22,3,32 };
string sysMsgs[2][COUNT_SYS_MSG];
