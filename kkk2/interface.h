#pragma once
#include<iostream>
#include "globals.h"
#include "windows.h"
#include <fstream>
#include "string"

#include "Reader.h"
struct Range;
class Interface {
public:
	static void Put(int number, int locale=lang_now, char end='\n');
	static void Put(Range r, int locale=lang_now);
	static void cls();
	static void Init(std::string config = config_path);
	static bool CheckIncludeFiles();
	static void PrintFile(int namefile, int locale = lang_now, std::string path="");
	static void UseConfig(std::string config);
	static void DrawSlide(int slide, int who = none);
	static void SaveConfig();
	static void LoadData();
	static void SaveData();
};

struct Range {
	int left;
	int right;
	Range(int left, int right) {
		this->left = left;
		this->right = right;
	}
};