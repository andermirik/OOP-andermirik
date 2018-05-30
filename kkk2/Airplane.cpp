#include "Fly.h"
#include "string"
Airplane::Airplane(int Speed, int Distance, int NumOfPass, int Height, int NumOfScrew, int Capacity, int Weight)
	: Fly(Speed, Distance, NumOfPass, Height)
{
	num_of_engines = NumOfScrew;
	capacity = Capacity;
	weight = Weight;
	Airplane::count++;
	Fly::count--;
}

void Airplane::ToFile(ofstream & fout)
{
	Fly::ToFile(fout);
	fout << num_of_engines << endl << capacity << endl<<weight<<endl;
	
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
	out << sysMsgs[lang_now][7] << num_of_engines << endl
		<< sysMsgs[lang_now][6] << capacity << endl
		<< sysMsgs[lang_now][11] << weight << endl;
}

void Airplane::read(ifstream & fin)
{
	Fly::read(fin);
	fin >> num_of_engines >> capacity>>weight;
}

void Airplane::readFields(int args)
{
	Fly::readFields(args);
	if (args&Style::NUM_OF_ENGINES) {
		cout << sysMsgs[lang_now][7];
		num_of_engines = Reader::Int();
	}
	if (args&Style::CAPACITY) {
		cout << sysMsgs[lang_now][6];
		capacity = Reader::Int();
	}
	if (args&Style::WEIGHT) {
		cout << sysMsgs[lang_now][11];
		weight = Reader::Int();
	}
}

void operator++(Airplane& h)
{
	if(h.capacity<100)
		h.capacity+=1;
}
