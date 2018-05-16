#pragma once
#include "object.h"
#include <fstream>
#include "globals.h"
#include "Reader.h"
class ColoredHeli;
class         Fly;
class  Helicopter;
class    Airplane;
class       Color;

class Fly: public Object {
protected:
	int speed;
	int height;
	int distance;
	int num_of_pass;
public:
	static int count;
	int GetDistance();
	int GetHeight();
	int GetNumOfPass();
	bool isFlying(int Height);
	Fly(int speed, int distance, int num_of_pass, int height);
	virtual ~Fly() {
		Fly::count--;
	}
	virtual void ToFile(ofstream &fout);
	virtual void ToStd(ostream &out);
	virtual void read(ifstream &fin);
	virtual void readFields(int args = 0);
};

class Helicopter : public Fly {
protected:
	int num_of_screw;
	int capacity;
public:
	static int count;
	virtual bool AddFuel(int Fuel);	
	Helicopter(int Speed, int Distance, int NumOfPass, int Height, int NumOfScrew, int Capacity);
	virtual ~Helicopter() { Helicopter::count--; Fly::count++; }
	virtual void ToFile(ofstream& fout);
	void operator~(); //сбросить топливо
	friend void operator++(Helicopter&);//заправить
	virtual void ToStd(ostream &out);
	virtual void read(ifstream &fin);
	virtual void readFields(int args = 0);
};

class Airplane : public  Fly {
protected:
	int num_of_engines;
	int capacity;
	int weight;
public:
	static int count;
	bool AddFuel(int Fuel);
	Airplane(int Speed, int Distance, int NumOfPass, int Height, int NumOfEngines, int Capacity, int Weight);
	virtual ~Airplane() { Airplane::count--; Fly::count++; }
	void ToFile(ofstream& fout);
	void operator~(); //сбросить топливо
	friend void operator++(Airplane&);//заправить
	void ToStd(ostream &out);
	void read(ifstream& fin);
	void readFields(int args = 0);
};

class Color{
	friend ColoredHeli;
protected:
	int Red;
	int Green;
	int Blue;
public:
	Color(int, int, int);
	virtual void WhatColor() = 0;
	void SetColor(int, int, int);
	void ToFile(ofstream&);
	virtual ~Color() {}
	void ToStd(ostream &out);
	void read(ifstream&);
	virtual void readFields(int args = 0);
};

class ColoredHeli :public Color, public Helicopter {
public:
	static int count;
	void ToFile(ofstream&);
	ColoredHeli(int Speed, int Distance, int NumOfPass, int Height, int NumOfScrew, int Capacity, int red, int green, int blue);
	void SetColor(int color);
	void ToStd(ostream &out);
	void read(ifstream&);
	void operator--();//ALLAH AKBAR
	void WhatColor();
	void readFields(int args = 0);
	~ColoredHeli() {
		ColoredHeli::count--;
		Helicopter::count++;
	}
};