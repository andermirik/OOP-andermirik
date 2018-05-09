#include "Fly.h"
Airplane::Airplane(int Speed, int Distance, int NumOfPass, int Height, int NumOfScrew, int Capacity)
	: Fly(Speed, Distance, NumOfPass, Height)
{
	num_of_engines = NumOfScrew;
	capacity = Capacity;
	Airplane::count++;
	Fly::count--;
}

void Airplane::ToFile(ofstream & fout)
{
	Fly::ToFile(fout);
	fout << num_of_engines << endl << capacity << endl;
	
}


bool Airplane::AddFuel(int Fuel)
{
	if (capacity == 100)
		return true;
	capacity += Fuel;
	if (capacity > 100)
		capacity = 100;
	return false;
}

void Airplane::operator~()
{
	capacity = 0;
}

void Airplane::ToStd(ostream & out)
{
	Fly::ToStd(out);
	out <<"num_of_engines: "<< num_of_engines << endl <<"capacity: "<< capacity << endl;
}

void Airplane::read(ifstream & fin)
{
	Fly::read(fin);
	fin >> num_of_engines >> capacity;
}

void Airplane::readFields(int args)
{
	Fly::readFields(args);
	if (args&Style::NUM_OF_ENGINES) {
		cout << "num_of_engines: ";
		num_of_engines = Reader::Int();
	}
	if (args&Style::CAPACITY) {
		cout << "capacity: ";
		capacity = Reader::Int();
	}
}

void operator++(Airplane& h)
{
	if(h.capacity<100)
		h.capacity+=1;
}
