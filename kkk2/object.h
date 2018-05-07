#include <fstream>
#include "iostream"
#pragma once
using namespace std;
class Object {
public:
	static int count;
	virtual void ToFile(std::ofstream&fout) = 0;
	virtual void ToStd(std::ostream&fout) = 0;
	virtual void read(ifstream&fin) = 0;
	friend std::ofstream& operator<<(std::ofstream&fout, Object* o);
	friend std::ifstream& operator>>(std::ifstream&fin, Object* o);
	friend std::ostream& operator<<(std::ostream&fout, Object* o);
	virtual ~Object() { Object::count--; };
};
