#include "ObjectList.h"



void ObjectList::pushBack(Object* object) {
	if (!head) {
		head = new Node;
		head->object = object;
		head->type_name = (string)(typeid(*object).name() + 6); // +6 ликвидирует "class "
		tail = head;
		return;
	}
	tail->next = new Node;
	tail = tail->next;
	tail->object = object;
	tail->type_name = (string)(typeid(*object).name() + 6); // +6 ликвидирует "class "
}

void ObjectList::read(ifstream &fin)
{
	Release();
	string type;
	Object* obj;
	while (!fin.eof()) {
		fin >> type;
		if (type == "")
			return;
		if (type == "Helicopter") {
			obj = new Helicopter(0, 0, 0, 0, 0, 0);
			fin >> obj;
		}
		else if (type == "Fly") {
			obj = new Fly(0, 0, 0, 0);
			fin >> obj;
		}
		else if (type == "Airplane") {
			obj = new Airplane(0, 0, 0, 0, 0, 0, 0);
			fin >> obj;
		}
		/*else if (type == "Color") {
			obj = new Color(0, 0, 0);
			fin >> obj;
		}*/
		else if (type == "ColoredHeli") {
			obj = new ColoredHeli(0, 0, 0, 0, 0, 0, 0, 0, 0);
			fin >> obj;
		}
		else {
			cerr << "Class " << type << " not found" << endl;;
			continue;
		}
		pushBack(obj);
		type = "";
	}
	
}

void ObjectList::write(ofstream &fout)
{
	Node * node = head;
	while (node) {
		fout << node->type_name << endl;
		fout << node->object << endl;
		node = node->next;
	}
}

ostream& operator<<(ostream& output, ObjectList& container) {
	if (!container.head) {
		Interface::Put(97);
		return output;
	}
	ObjectList::Node *node = container.head;
	while (node) {
		output << node->type_name << endl;
		output << node->object << endl;
		node = node->next;
	}
	return output;
}
void ObjectList::Release()
{
	if (!head)
		return;
	Node* prev = NULL;
	while (head->next) {
		prev = head;
		head = head->next;
		delete prev->object;
		delete prev;
	}
	delete head->object;	
	delete head;
	head = NULL;
}
void ObjectList::DeleteLastItemByTag(string type)
{
	if (!head)
		return;

	Node*before = NULL;
	Node * iterator = head;
	while (iterator->next) {
		if (iterator->next->type_name == type) {
			before = iterator;
		}
		iterator = iterator->next;
	}
	Node* temp;
	if (before) {
		temp = before->next;
		before->next = before->next->next;
		delete temp->object;
		delete temp;
	}
	else {
		if (head->type_name == type) {
			temp = head;
			head = head->next;
			delete temp->object;
			delete temp;
		}
	}
}
bool ObjectList::EditItemInPos(int pos)
{
	
	Node* now = NULL;
	bool isElement = false;
	if (pos > 0 && head) {

		int now_pos = 1;
		now = head;

		while (now) {
			if (now_pos == pos) {
				isElement = true;
				break;
			}
			now = now->next;
			++now_pos;
		}
	}
	else isElement = false;

	if (isElement&&now) {
		char key;
		Interface::cls();
		Interface::Put(92, lang_now, ' '); cout << now->type_name << endl;
		if (now->type_name == "Fly") {
			cout << "1."<<sysMsgs[lang_now][13]<< sysMsgs[lang_now][1] << endl;
			cout << "2." << sysMsgs[lang_now][13] << sysMsgs[lang_now][2] << endl;
			cout << "3." << sysMsgs[lang_now][13] << sysMsgs[lang_now][3] << endl;
			cout << "4." << sysMsgs[lang_now][13] << sysMsgs[lang_now][4] << endl;
			cout << "5."; Interface::Put(94); cout << endl;
			cout << "h." <<sysMsgs[lang_now][13] << sysMsgs[lang_now][12]; cout << "isFlying" << endl;
			Interface::Put(86);
			do {
				key = _getch();
				if (key == '1') {
					cout << endl;
					((Fly*)now->object)->readFields(Style::SPEED);
				}
				else if (key == '2') {
					cout << endl;
					((Fly*)now->object)->readFields(Style::HEIGHT);
				}
				else if (key == '3') {
					cout << endl;
					((Fly*)now->object)->readFields(Style::DISTANCE);
				}
				else if (key == '4') {
					cout << endl;
					((Fly*)now->object)->readFields(Style::NUM_OF_PASS);
				}
				else if (key == '5') {
					cout << endl;
					cout << now->object;
				}
				else if (key == 'c' || key == 'с') {
					Interface::DrawSlide(change_lang, demonstration);
				}
				else if (key == 'h'||key=='р') {
					cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					int hg = Reader::Int();
					
					cout << endl; Interface::Put(96, lang_now, ' '); cout << ((Fly*)now->object)->isFlying(hg) << endl;
				}
			} while (key != 'b'&&key != 'и');
		}
		else if (now->type_name == "Helicopter") {
			cout << "1." << sysMsgs[lang_now][13] << sysMsgs[lang_now][1] << endl;
			cout << "2." << sysMsgs[lang_now][13] << sysMsgs[lang_now][2] << endl;
			cout << "3." << sysMsgs[lang_now][13] << sysMsgs[lang_now][3] << endl;
			cout << "4." << sysMsgs[lang_now][13] << sysMsgs[lang_now][4] << endl;
			cout << "5." << sysMsgs[lang_now][13] << sysMsgs[lang_now][5] << endl;
			cout << "6." << sysMsgs[lang_now][13] << sysMsgs[lang_now][6] << endl;
			cout << "7."; Interface::Put(94); cout << endl;
			cout << "h."; Interface::Put(95, lang_now, ' '); cout << "isFlying" << endl;
			cout << "a."; Interface::Put(95, lang_now, ' '); cout << "AddFuel" << endl;
			cout << "~." << sysMsgs[lang_now][14] << "~" << endl;
			cout << "p." << sysMsgs[lang_now][14] << "++" << endl;
			Interface::Put(86);
			do {
				key = _getch();
				if (key == '1') {
					cout << endl;
					((Helicopter*)now->object)->readFields(Style::SPEED);
				}
				else if (key == '2') {
					cout << endl;
					((Helicopter*)now->object)->readFields(Style::HEIGHT);
				}
				else if (key == '3') {
					cout << endl;
					((Helicopter*)now->object)->readFields(Style::DISTANCE);
				}
				else if (key == '4') {
					cout << endl;
					((Helicopter*)now->object)->readFields(Style::NUM_OF_PASS);
				}
				else if (key == '5') {
					((Helicopter*)now->object)->readFields(Style::NUM_OF_SCREW);
				}
				else if (key == '6') {
					((Helicopter*)now->object)->readFields(Style::CAPACITY);
				}
				else if (key == '7') {
					cout << endl;
					cout << now->object;
				}
				else if (key == 'c' || key == 'с') {
					Interface::DrawSlide(change_lang, demonstration);
				}
				else if (key == 'h' || key == 'р') {
					cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					int hg = Reader::Int();
					cout << endl; Interface::Put(96, lang_now, ' '); cout << ((Helicopter*)now->object)->isFlying(hg) << endl;
				}
				else if (key == 'a' || key == 'а') {
					cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					int fuel = Reader::Int();
					cout << endl; Interface::Put(96, lang_now, ' '); cout << ((Helicopter*)now->object)->AddFuel(fuel) << endl;
				}
				else if (key == '~') {
					cout << ": ~" << endl;
					((Helicopter*)now->object)->operator~();
				}
				else if (key == 'p' || key == 'з') {
					cout << ": ++" << endl;
					Helicopter * h;
					h = ((Helicopter*)now->object);
					++(*h);
				}
			} while (key != 'b'&&key != 'и');
		}
		else if (now->type_name == "Airplane") {
			cout << "1." << sysMsgs[lang_now][13] << sysMsgs[lang_now][1] << endl;
			cout << "2." << sysMsgs[lang_now][13] << sysMsgs[lang_now][2] << endl;
			cout << "3." << sysMsgs[lang_now][13] << sysMsgs[lang_now][3] << endl;
			cout << "4." << sysMsgs[lang_now][13] << sysMsgs[lang_now][4] << endl;
			cout << "5." << sysMsgs[lang_now][13] << sysMsgs[lang_now][7] << endl;
			cout << "6." << sysMsgs[lang_now][13] << sysMsgs[lang_now][6] << endl;
			cout << "7." << sysMsgs[lang_now][13] << sysMsgs[lang_now][11] << endl;
			cout << "8."; Interface::Put(94); cout << endl;
			cout << "h."; Interface::Put(95, lang_now, ' '); cout << "isFlying" << endl;
			cout << "a."; Interface::Put(95, lang_now, ' '); cout << "AddFuel" << endl;
			cout << "~." << sysMsgs[lang_now][14] << "~" << endl;
			cout << "p." << sysMsgs[lang_now][14] << "++" << endl;
			Interface::Put(86);
			do {
				key = _getch();
				if (key == '1') {
					cout << endl;
					((Airplane*)now->object)->readFields(Style::SPEED);
				}
				else if (key == '2') {
					cout << endl;
					((Airplane*)now->object)->readFields(Style::HEIGHT);
				}
				else if (key == '3') {
					cout << endl;
					((Airplane*)now->object)->readFields(Style::DISTANCE);
				}
				else if (key == '4') {
					cout << endl;
					((Airplane*)now->object)->readFields(Style::NUM_OF_PASS);
				}
				else if (key == '5') {
					((Airplane*)now->object)->readFields(Style::NUM_OF_ENGINES);
				}
				else if (key == '6') {
					((Airplane*)now->object)->readFields(Style::CAPACITY);
				}
				else if (key == '7') {
					((Airplane*)now->object)->readFields(Style::WEIGHT);
				}
				else if (key == '8') {
					cout << endl;
					cout << now->object;
				}
				else if (key == 'c' || key == 'с') {
					Interface::DrawSlide(change_lang, demonstration);
				}
				else if (key == 'h' || key == 'р') {
					cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					int hg = Reader::Int();
					cout << endl; Interface::Put(96, lang_now, ' '); cout << ((Airplane*)now->object)->isFlying(hg) << endl;
				}
				else if (key == 'a' || key == 'а') {
					cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					int fuel = Reader::Int();
					cout << endl; Interface::Put(96, lang_now, ' '); cout << ((Airplane*)now->object)->AddFuel(fuel) << endl;
				}
				else if (key == '~') {
					cout << ": ~" << endl;
					((Airplane*)now->object)->operator~();
				}
				else if (key == 'p' || key == 'з') {
					cout << ": ++" << endl;
					Airplane * h;
					h = ((Airplane*)now->object);
					++(*h);
				}
			} while (key != 'b'&&key != 'и');
		}
		else if (now->type_name == "ColoredHeli") {
			cout << "1." << sysMsgs[lang_now][13] << sysMsgs[lang_now][1] << endl;
			cout << "2." << sysMsgs[lang_now][13] << sysMsgs[lang_now][2] << endl;
			cout << "3." << sysMsgs[lang_now][13] << sysMsgs[lang_now][3] << endl;
			cout << "4." << sysMsgs[lang_now][13] << sysMsgs[lang_now][4] << endl;
			cout << "5." << sysMsgs[lang_now][13] << sysMsgs[lang_now][5] << endl;
			cout << "6." << sysMsgs[lang_now][13] << sysMsgs[lang_now][6] << endl;
			cout << "7." << sysMsgs[lang_now][13] << sysMsgs[lang_now][8] << endl;
			cout << "8." << sysMsgs[lang_now][13] << sysMsgs[lang_now][9] << endl;
			cout << "9." << sysMsgs[lang_now][13] << sysMsgs[lang_now][10] << endl;
			cout << "0."; Interface::Put(94); cout << endl;
			cout << "h."; Interface::Put(95, lang_now, ' '); cout << "isFlying" << endl;
			cout << "a."; Interface::Put(95, lang_now, ' '); cout << "AddFuel" << endl;
			cout << "~."<< sysMsgs[lang_now][14] <<"~" << endl;
			cout << "p."<< sysMsgs[lang_now][14] <<"++" << endl;
			cout << "m."<< sysMsgs[lang_now][14] << "--" << endl;
			cout << "w."; Interface::Put(95, lang_now, ' '); cout << "WhatColor" << endl;
			Interface::Put(86);
			do {
				key = _getch();
				if (key == '1') {
					cout << endl;
					((ColoredHeli*)now->object)->readFields(Style::SPEED);
				}
				else if (key == '2') {
					cout << endl;
					((ColoredHeli*)now->object)->readFields(Style::HEIGHT);
				}
				else if (key == '3') {
					cout << endl;
					((ColoredHeli*)now->object)->readFields(Style::DISTANCE);
				}
				else if (key == '4') {
					cout << endl;
					((ColoredHeli*)now->object)->readFields(Style::NUM_OF_PASS);
				}
				else if (key == '5') {
					((ColoredHeli*)now->object)->readFields(Style::NUM_OF_SCREW);
				}
				else if (key == '6') {
					((ColoredHeli*)now->object)->readFields(Style::CAPACITY);
				}
				else if (key == '7') {
					((ColoredHeli*)now->object)->readFields(Style::RED);
				}
				else if (key == '8') {
					((ColoredHeli*)now->object)->readFields(Style::GREEN);
				}
				else if (key == '9') {
					((ColoredHeli*)now->object)->readFields(Style::BLUE);
				}
				else if (key == '0') {
					cout << endl;
					cout << now->object;
				}
				else if (key == 'c' || key == 'с') {
					Interface::DrawSlide(change_lang, demonstration);
				}
				else if (key == 'h' || key == 'р') {
					cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					int hg = Reader::Int();
					cout << endl; Interface::Put(96, lang_now, ' '); cout << ((ColoredHeli*)now->object)->isFlying(hg) << endl;
				}
				else if (key == 'a' || key == 'а') {
					cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					int fuel = Reader::Int();
					cout << endl; Interface::Put(96, lang_now, ' '); cout << ((ColoredHeli*)now->object)->AddFuel(fuel) << endl;
				}
				else if (key == '~') {
					cout << ": ~" << endl;
					((ColoredHeli*)now->object)->operator~();
				}
				else if (key == 'p' || key == 'з') {
					cout << ": ++" << endl;
					ColoredHeli * h;
					h = ((ColoredHeli*)now->object);
					++(*h);
				}
				else if (key == 'm' || key == 'ь') {
					cout << ": --" << endl;
					ColoredHeli * h;
					h = ((ColoredHeli*)now->object);
					--(*h);
				}
				else if (key == 'w' || key == 'ц') {
					((ColoredHeli*)now->object)->WhatColor();
					cout << endl;
				}
			} while (key != 'b'&&key != 'и');
		}
	}
	else {
		Interface::Put(91);
	}

	return isElement;
}
ObjectList::~ObjectList() {
	Release();
}

ofstream& operator<<(ofstream& output, ObjectList& container) {
	container.write(output);
	return output;
}

ifstream & operator>>(ifstream & input, ObjectList & container)
{
	container.read(input);
	return input;
}
