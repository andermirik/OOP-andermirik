#include "Fly.h"

int Fly::GetDistance()
{
	return distance;
}

int Fly::GetHeight()
{
	return height;
}

int Fly::GetNumOfPass()
{
	return num_of_pass;
}

bool Fly::isFlying(int Height)
{
	return (Height <= height && Height >= 10);

}

Fly::Fly(int speed, int distance, int num_of_pass, int height)
{
	this->speed = speed;
	this->distance = distance;
	this->num_of_pass = num_of_pass;
	this->height = height;
	Fly::count++;
}

void Fly::ToFile(ofstream & fout)
{
	fout << speed << endl << height << endl << distance << endl << num_of_pass << endl;
}

void Fly::ToStd(ostream & out)
{
	out<<"speed: " << speed << endl <<"height: "<< height << endl <<"distance: "<< distance << endl <<"num_of_pass: "<< num_of_pass << endl;
}

void Fly::read(ifstream & fin)
{
	fin >> speed >> height >> distance >> num_of_pass;
}

void Fly::readFields(int args)
{
	if (args&Style::SPEED) {
		cout << "speed: ";
		speed = Reader::Int();
	}
	if (args&Style::HEIGHT) {
		cout << "height: ";
		height = Reader::Int();
	}
	if (args&Style::DISTANCE) {
		cout << "distance: ";
		distance = Reader::Int();
	}
	if (args&Style::NUM_OF_PASS) {
		cout << "num_of_pass: ";
		num_of_pass = Reader::Int();
	}
}


void ColoredHeli::ToFile(ofstream &fout)
{
	Helicopter::ToFile(fout);
	Color::ToFile(fout);
}

ColoredHeli::ColoredHeli(int Speed, int Distance, int NumOfPass, int Height, int NumOfScrew, int Capacity,
	int red, int green, int blue)
	:Helicopter(Speed, Distance, NumOfPass, Height, NumOfScrew, Capacity), Color(red, green, blue)
{
	ColoredHeli::count++;
	Helicopter::count--;
}

void ColoredHeli::SetColor(int color) // 0xff00ff
{
	
	Red = (color & 0xff0000)>>16;
	Green = (color & 0xff00)>>8;
	Blue = color & 0xff;
}

void ColoredHeli::ToStd(ostream & out)
{
	Helicopter::ToStd(out);
	Color::ToStd(out);
}

void ColoredHeli::read(ifstream &fin)
{
	Helicopter::read(fin);
	Color::read(fin);
}

void ColoredHeli::operator--()
{
	cout << "ALLAH AKBAR!!!"<<endl;
	Fly::num_of_pass = 0;
}

void ColoredHeli::WhatColor()
{
	printf("(%d;%d;%d)", Red, Green, Blue);
}

void ColoredHeli::readFields(int args)
{
	Helicopter::readFields(args);
	Color::readFields(args);

}
