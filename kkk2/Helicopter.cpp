#include "Fly.h"
#include "string"
bool Helicopter::AddFuel(int Fuel)
{
	if (capacity == 100)
		return true;
	capacity += Fuel;
	if (capacity > 100)
		capacity = 100;
	return false;
}

Helicopter::Helicopter(int Speed, int Distance, int NumOfPass, int Height, int NumOfScrew, int Capacity)
	: Fly(Speed, Distance, NumOfPass, Height)
{
	num_of_screw = NumOfScrew;
	capacity = Capacity;
	Helicopter::count++;
	Fly::count--;
}

void Helicopter::ToFile(ofstream & fout)
{
	Fly::ToFile(fout);
	fout << num_of_screw << endl << capacity << endl;
}

void Helicopter::operator~()
{
	capacity = 0;
}

void Helicopter::ToStd(ostream & out)
{
	Fly::ToStd(out);
	out << sysMsgs[lang_now][5] << num_of_screw << endl
	<< sysMsgs[lang_now][6] << capacity << endl;
}

void Helicopter::read(ifstream & fin)
{
	Fly::read(fin);
	fin >> num_of_screw >> capacity;
}

void Helicopter::readFields(int args)
{
	Fly::readFields(args);
	if (args&Style::NUM_OF_SCREW) {
		cout << sysMsgs[lang_now][5];
		num_of_screw = Reader::Int();
	}
	if (args&Style::CAPACITY) {
		cout << sysMsgs[lang_now][6];
		capacity = Reader::Int();
	}
}

void operator++(Helicopter& h)
{
	if(h.capacity<100)
		h.capacity += 1;
}

