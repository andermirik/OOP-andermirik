#pragma once
#include "object.h"
#include "Fly.h"
#include <string>
#include "globals.h"
#include "interface.h"
class ObjectList {
private:
	struct Node {
		Node() : next(NULL) { }
		Object* object;
		std::string type_name;
		Node * next;
	};
	
	Node* tail;
public:
	void Release();
	void DeleteLastItemByTag(string type);
	bool EditItemInPos(int pos);
	ObjectList() {};
	~ObjectList();
	void pushBack(Object* object);
	friend ostream& operator<<(ostream& output, ObjectList&container);
	friend ofstream& operator<<(ofstream& output, ObjectList&container);
	friend ifstream& operator>>(ifstream& output, ObjectList&container);
	void write(ofstream&);
	void read(ifstream&);
	Node * head;
};
