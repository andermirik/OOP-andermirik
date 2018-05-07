#include "Fly.h"

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
	out <<"num_of_screw: "<< num_of_screw << endl <<"capacity: "<< capacity << endl;
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
		cout << "num_of_screw: ";
		num_of_screw = Reader::Int();
	}
	if (args&Style::CAPACITY) {
		cout << "capacity: ";
		capacity = Reader::Int();
	}
}

void operator++(Helicopter& h)
{
	if(h.capacity<100)
		h.capacity += 1;
}

