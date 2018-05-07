#include "object.h"
std::ofstream& operator<<(std::ofstream&fout, Object* obj) {
	obj->ToFile(fout);
	return fout;
}

std::ifstream & operator>>(std::ifstream & fin, Object * o)
{
	o->read(fin);
	return fin;
}

std::ostream & operator<<(std::ostream & out, Object * obj)
{
	obj->ToStd(out);
	return out;
}

