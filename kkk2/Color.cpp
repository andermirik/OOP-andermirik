#include"Fly.h"
Color::Color(int r, int g, int b)
{
	SetColor(r, g, b);
}


void Color::SetColor(int r, int g, int b)
{
	Red = r;
	Green = g;
	Blue = b;
}

void Color::ToFile(ofstream& fout)
{
	fout << Red << endl << Green << endl << Blue << endl;
}

void Color::ToStd(ostream& out)
{
	out <<"Red: "<< Red << endl << "Green: " << Green << endl <<"Blue: "<< Blue << endl;
}

void Color::read(ifstream& fin)
{
	fin >> Red >> Green >> Blue;
}

void Color::readFields(int args)
{
	if (args&Style::RED) {
		cout << "Red: ";
		Red = Reader::Int();
	}
	if (args&Style::GREEN) {
		cout << "Green: ";
		Green = Reader::Int();
	}
	if (args&Style::BLUE) {
		cout << "Blue: ";
		Blue = Reader::Int();
	}
}
