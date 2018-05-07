#include "interface.h"
#include "container.h"
using namespace std;
void Interface::Put(int num, int locale, char end) {
	string msg;
	ifstream fin;
	fin.exceptions(ifstream::failbit);
	try {
		switch (locale) {
		case rus:
			fin.open(include_files[0]);//ru.txt
			break;
		case eng:
			fin.open(include_files[1]);//"en.txt"
			break;
		}
		int now = 1;
		while (getline(fin, msg))
		{
			if (now++ == num)
			{
				cout << msg << end;
				break;
			}
		}
		fin.close();
	}
	catch (std::exception const& e) {
		if (locale == eng)
			cerr << "unable to open file with translate"<<endl;
		else if (locale == rus)
			cerr << "�� ������� ������� ���� � �������"<<endl;
		
	}
}
void Interface::Put(Range range, int locale)
{
	string msg;
	ifstream fin;
	fin.exceptions(ifstream::failbit);
	try {
		switch (locale) {
		case rus:
			fin.open(include_files[0]);//ru.txt
			break;
		case eng:
			fin.open(include_files[1]);//"en.txt"
			break;
		}
		int now = 1;
		while (getline(fin, msg))
		{
			if (now++ == range.left)
			{
				cout << msg << endl;
				for (now; now <= range.right && getline(fin, msg); now++) {
					cout << msg << endl;
				}
				break;
			}
			
		}
		fin.close();
	}
	catch (std::exception const& e) {
		if (locale == eng)
			cerr << "unable to open file with translate" << endl;
		else if (locale == rus)
			cerr << "�� ������� ������� ���� � �������" << endl;

	}
}
void Interface::cls() {
	system("cls");
}
void Interface::Init(std::string config) {
	#ifndef FIRSTRUN
		Interface::UseConfig(config);
		#define FIRSTRUN
		system("chcp 1251>nul");
		setlocale(0, "rus");
	#endif
		if (!Interface::CheckIncludeFiles())
			cin.get();
		Interface::cls();
}

bool Interface::CheckIncludeFiles() {
	bool result = true;
	for each (string file in include_files)
	{
		if (!fopen(file.c_str(), "r")) {
			Interface::Put(1, lang_now);
			cout << file << endl;
			result = false;
		}
	}
	return result;
}

void Interface::PrintFile(int namefile, int locale, string path)
{
	fstream fin;
	fin.exceptions(ios::failbit);
	try {
		if (path == "") {
			if (namefile == aboutme) {
				if (locale == rus)
					fin.open(include_files[3]);
				else if (locale == eng)
					fin.open(include_files[6]);
			}
			else if (namefile == readme) {
				if (locale == rus)
					fin.open(include_files[2]);
				else if (locale == eng)
					fin.open(include_files[5]);
			}
			else if (namefile == aboutprog) {
				if (locale == rus)
					fin.open(include_files[4]);
				else if (locale == eng)
					fin.open(include_files[7]);
			}
		}
		else fin.open(path);
		string temp;
		while (!fin.eof()) {
			getline(fin, temp);
			cout << temp<<endl;
		}
		
		fin.close();
	}
	catch (std::exception const& e) {
		if (locale == eng)
			cerr << "unable to open file" << endl;
		else if (locale == rus)
			cerr << "�� ������� ������� ����" << endl;

	}
}

void Interface::UseConfig(std::string config) {
	fstream fin;
	fin.exceptions(ios::failbit);
	try {
		fin.open(config);
		for(int i = 0; i<COUNT_FILES;i++){
			getline(fin, include_files[i]);
		}

		fin.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr << "unable to open file" << endl;
		else if (lang_now == rus)
			cerr << "�� ������� ������� ����" << endl;

	}
}

void Interface::DrawSlide(int slide, int back_slide) {
	char key;
	string temp;
	if (slide == start) {
		/*for (int i = 2; i <= 30; i++)
			Interface::Put(i, lang_now, '\n');*/
		Put(Range(2, 30));
		do {
			key = _getch();
			if (key == '1') {
				Interface::DrawSlide(change_lang, start);
				return;
			}
		} while (key != '2');
	}
	else if (slide == change_lang) {
		Interface::cls();
		/*for (int phrase = 31; phrase <= 33; phrase++)
			Interface::Put(phrase);*/
		Put(Range(31, 33));
		do {
			key = _getch();
			switch (key) {
			case '1':
				lang_now = rus;
				Interface::cls();
				break;
			case '2':
				lang_now = eng;
				Interface::cls();
				break;
			}
		} while (key != '1'&&key != '2');

		Interface::DrawSlide(back_slide, menu);
	}
	else if (slide == menu) {
		Interface::cls();
		/*for (int phrase = 34; phrase <= 42; phrase++)
			Interface::Put(phrase);*/
		Put(Range(34, 42));
		do {
			key = _getch();
			switch (key)
			{
			case '1':
				Interface::DrawSlide(edit_config, menu);
				return;
				break;
			case '2':
				Interface::SaveData();
				break;
			case '3':
				Interface::DrawSlide(change_lang, menu);
				return;
			case '4':
				Interface::DrawSlide(demonstration, menu);
				return;
			case '5':
				cout << endl << "---------------------------------" << endl;
				Interface::PrintFile(readme);
				cout << "---------------------------------" << endl;
				break;
			case'6':
				cout << endl << "---------------------------------" << endl;
				Interface::PrintFile(aboutme);
				cout << "---------------------------------" << endl;
				break;
			case'7':
				cout << endl << "---------------------------------" << endl;
				Interface::PrintFile(aboutprog);
				cout << "---------------------------------" << endl;
				break;
			case '8':
				Interface::LoadData();
				break;
			case 'r':
			case '�'://refresh
				Interface::DrawSlide(menu);
				return;
				break;
			}
		} while (key != 27);
	}
	else if (slide == edit_config) {
		Interface::cls();
		/*for (int phrase = 43; phrase <= 56; phrase++)
			Interface::Put(phrase);*/
		Put(Range(43, 56));
		do {
			key = _getch();
			if (key >= '1' && key <= '8') {
				cout << endl << endl;
				Put(57, lang_now, ' ');
				getline(cin, temp);

				if (fopen(temp.c_str(), "r"))
					include_files[key - 49] = temp;
				else Interface::Put(1);

			}
			else if (key == 's' || key == '�')
				Interface::SaveConfig();
			else if (key == 'c' || key == '�') {
				Interface::DrawSlide(change_lang, edit_config);
				return;
			}
		} while (key != 'd' && key != '�');

		Interface::DrawSlide(back_slide, menu);
	}
	else if (slide == demonstration) {
		Interface::cls();
		/*for (int phrase = 59; phrase <= 68; phrase++) 
			Interface::Put(phrase);*/
		Put(Range(59, 68));
		Interface::Put(87);
		Interface::Put(89);
		do {
			key = _getch();

			if (key == '1') {
				Interface::DrawSlide(fly, demonstration);
				return;
			}
			else if (key == '2') {
				Interface::DrawSlide(helicopter, demonstration);
				return;
			}
			else if (key == '3') {
				Interface::DrawSlide(airplane, demonstration);
				return;
			}
			else if (key == '4') {
				Interface::DrawSlide(coloredheli, demonstration);
				return;
			}
			else if (key == 'w' || key=='�') {
				cout << endl << ":                :\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				if (container.EditItemInPos(Reader::Int())) {//���� ����� ������� ����
					Interface::DrawSlide(demonstration, menu);//�������
					return;
				}
			}
			else if (key == 's' || key == '�') {
				cout <<endl<<container;
			}
			else if (key == 'c' || key == '�') {
				Interface::DrawSlide(change_lang, demonstration);
			}
			else if (key == 'o' || key == '�') {
				Interface::Put(88, lang_now, ' ');
				cout << Object::count << endl;
			}
			
		} while (key != 'b' && key != '�');
		
		Interface::DrawSlide(menu, menu);
		return;
	}
	else if (slide == fly) {
		
		do {
			Interface::cls();
			Interface::Put(70);
			Interface::Put(71);
			Interface::Put(84);
			Interface::Put(85);
			Interface::Put(86);
			
			key = _getch();
			
			if (key == '1') {
				Object*objFly = new Fly(0, 0, 0, 0);
				((Fly*)objFly)->readFields(Style::SPEED|Style::HEIGHT|Style::DISTANCE|Style::NUM_OF_PASS);
				container.pushBack(objFly);

			}
			else if (key == '2') {
				container.DeleteLastItemByTag("Fly");
			}
			else if (key == 'c' || key == '�') {
				Interface::DrawSlide(change_lang, demonstration);
			}

		} while (key != 'b'&&key != '�');
		Interface::DrawSlide(demonstration, back_slide);
		return;
	}
	else if (slide == helicopter) {

		do {
			Interface::cls();
			Interface::Put(73);
			Interface::Put(74);
			Interface::Put(84);
			Interface::Put(85);
			Interface::Put(86);

			key = _getch();

			if (key == '1') {
				Object*objFly = new Helicopter(0, 0, 0, 0, 0, 0);
				((Helicopter*)objFly)->readFields(Style::SPEED | Style::HEIGHT | Style::DISTANCE| Style::NUM_OF_PASS 
					| Style::NUM_OF_SCREW | Style::CAPACITY);
				container.pushBack(objFly);

			}
			else if (key == '2') {
				container.DeleteLastItemByTag("Helicopter");
			}
			else if (key == 'c' || key == '�') {
				Interface::DrawSlide(change_lang, demonstration);
			}

		} while (key != 'b'&&key != '�');
		Interface::DrawSlide(demonstration, back_slide);
		return;
	}
	else if (slide == airplane) {

		do {
			Interface::cls();
			Interface::Put(76);
			Interface::Put(77);
			Interface::Put(84);
			Interface::Put(85);
			Interface::Put(86);

			key = _getch();

			if (key == '1') {
				Object*objFly = new Airplane(0, 0, 0, 0, 0, 0);
				((Airplane*)objFly)->readFields(Style::SPEED | Style::HEIGHT | Style::DISTANCE | Style::NUM_OF_PASS 
					| Style::NUM_OF_ENGINES | Style::CAPACITY);
				container.pushBack(objFly);

			}
			else if (key == '2') {
				container.DeleteLastItemByTag("Airplane");
			}
			else if (key == 'c' || key == '�') {
				Interface::DrawSlide(change_lang, demonstration);
			}

		} while (key != 'b'&&key != '�');
		Interface::DrawSlide(demonstration, back_slide);
		return;
	}
	else if (slide == coloredheli) {

		do {
			Interface::cls();
			Interface::Put(73);
			Interface::Put(74);
			Interface::Put(84);
			Interface::Put(85);
			Interface::Put(86);

			key = _getch();

			if (key == '1') {
				Object*objFly = new ColoredHeli(0, 0, 0, 0, 0, 0, 0, 0, 0);
				((ColoredHeli*)objFly)->readFields(Style::SPEED | Style::HEIGHT | Style::DISTANCE | Style::NUM_OF_PASS
					| Style::NUM_OF_SCREW | Style::CAPACITY | Style::RED | Style::GREEN | Style::BLUE);
				container.pushBack(objFly);

			}
			else if (key == '2') {
				container.DeleteLastItemByTag("ColoredHeli");
			}
			else if (key == 'c' || key == '�') {
				Interface::DrawSlide(change_lang, demonstration);
			}

		} while (key != 'b'&&key != '�');
		Interface::DrawSlide(demonstration, back_slide);
		return;
	}
}


void Interface::SaveConfig() {
	ofstream fout;
	try {
		fout.exceptions(ios::badbit);
		fout.open(config_path);
		for each (string file in include_files)
		{
			fout << file << endl;
		}
		fout.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr << "unable to open file" << endl;
		else if (lang_now == rus)
			cerr << "�� ������� ������� ����" << endl;
	}
}

void Interface::LoadData()
{
	ifstream fin;
	fin.exceptions(ios::badbit);
	try {
		fin.open("data/data.txt");
		container.read(fin);
		Interface::Put(58);
		//cout << endl;
		//cout << container;
		fin.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr <<endl<< "unable to found last session" << endl;
		else if (lang_now == rus)
			cerr <<endl<< "�� ������� ����� ��������� ������" << endl;
	}
}

void Interface::SaveData()
{
	if (container.head) {
		ofstream fout("data/data.txt");
		fout << container;
		fout.close();
		if(lang_now == eng)
			cout << endl << "session saved"<<endl;
		else if (lang_now == rus) 
			cout << endl << "������ ���������"<<endl;
		
	}
	else {
		if (lang_now == eng)
			cerr << endl << "session is clear" << endl;
		else if (lang_now == rus)
			cerr << endl << "������ �����" << endl;
	}
}