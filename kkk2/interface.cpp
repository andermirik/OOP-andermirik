#include "interface.h"
#include "container.h"
using namespace std;
#define EXIT(isExit) if((isExit)){cin.get();exit(-1);}


int NumStrs(string file) {
	ifstream inp(file);
	string s;
	int count = 0;
	while (getline(inp, s))
		count++;
	return count;
}

void Interface::Put(int num, int locale, char end) {
	cout << langs[locale][num-1] << end;
}

void Interface::SystemPut(int num, int locale, char end) {
	cout << sysMsgs[locale][num - 1] << end;
}

bool Interface::UploadFilesMemory()
{
	string rumsg;
	string enmsg;
	ifstream ruin;
	ifstream enin;
	bool result = true;
	ruin.exceptions(ifstream::failbit);
	enin.exceptions(ifstream::failbit);
	try {
		ruin.open(include_files[0]);
		enin.open(include_files[1]);
		int now = 0;
		while (!ruin.eof() && !enin.eof() && getline(ruin, rumsg) && getline(enin, enmsg))
		{
			if (now < COUNT_STRS_TRANSLETE) {
				langs[0][now] = rumsg;
				langs[1][now++] = enmsg;
			}
		}
		ruin.close();
		enin.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr << "unable to open file with translate" << endl;
		else if (lang_now == rus)
			cerr << "�� ������� ������� ���� � �������" << endl;
		result = false;
	}
	return result;
}
void Interface::Put(Range range, int locale)
{
	for (range.left; range.left <= range.right; range.left++)
		cout << langs[locale][range.left-1] << endl;
}
void Interface::cls() {
	system("cls");
}

void MsgInit() {
	sysMsgs[rus][0] = "������! ����� �� ���������� ��� ���������� ����� �� ���������";
	sysMsgs[eng][0] = "ERROR! File is no exist or count str's is no correct";
	sysMsgs[rus][1] = "��������: ";
	sysMsgs[eng][1] = "speed: ";
	sysMsgs[rus][2] = "������: ";
	sysMsgs[eng][2] = "height: ";
	sysMsgs[rus][3] = "����������: ";
	sysMsgs[eng][3] = "distance: ";
	sysMsgs[rus][4] = "���-�� ����������: ";
	sysMsgs[eng][4] = "num of pass: ";
	sysMsgs[rus][5] = "���-�� ������: ";
	sysMsgs[eng][5] = "num of screws: ";
	sysMsgs[rus][6] = "����� ����: ";
	sysMsgs[eng][6] = "capacity: ";
	sysMsgs[rus][7] = "���������� ����������: ";
	sysMsgs[eng][7] = "num of engines: ";
	sysMsgs[rus][8] = "�������: ";
	sysMsgs[eng][8] = "red: ";
	sysMsgs[rus][9] = "�������: ";
	sysMsgs[eng][9] = "green: ";
	sysMsgs[rus][10] = "�����: ";
	sysMsgs[eng][10] = "blue: ";
	sysMsgs[rus][11] = "���: ";
	sysMsgs[eng][11] = "weight: ";
	sysMsgs[rus][12] = "�����: ";
	sysMsgs[eng][12] = "method: ";
	sysMsgs[rus][13] = "�������� ���� ";
	sysMsgs[eng][13] = "edit field ";
	sysMsgs[rus][14] = "�������� ";
	sysMsgs[eng][14] = "operator ";
}

void Interface::Init(std::string config) {
	static int firstrun = 1;
	Interface::UseConfig(config);
	if (firstrun) {
		firstrun = 0;
		system("chcp 1251>nul");
		setlocale(0, "rus");
		MsgInit();
	}
	bool isExit = !Interface::CheckIncludeFiles();//���� ������������ ������ ��� ���-�� ����� �� ���������
	EXIT(isExit);
	isExit = !Interface::UploadFilesMemory();//���� �� ���� ������� ���� � ���������
	EXIT(isExit);
}

bool Interface::CheckIncludeFiles(string file) {
	bool result = true;
	int now = 0;
	if(file=="")
		for each (string file in include_files)
		{
			if (!fopen(file.c_str(), "r")) {
				Interface::Put(1, lang_now);
				cout << file << endl;
				
				result = false;
			}else
				if (NumStrs(file) < count_strs_all[now++]) {
					result = false;
					cout << file << endl;
					Interface::SystemPut(1,lang_now, ' ');
					cout<<"("<<NumStrs(file) << " < " << count_strs_all[now - 1]<<")";
			}
		}
	else 
		if(!fopen(file.c_str(), "r"))
			result = false;
	
	return result;
}

void Interface::PrintFile(int namefile, int locale, string path)
{
	ifstream fin;
	fin.exceptions(ios::failbit);
	try {
		if (path == "") 
			fin.open(include_files[namefile+2 + locale*3]);
		else
			fin.open(path);
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
			cerr << "unable to open file with config" << endl;
		else if (lang_now == rus)
			cerr << "�� ������� ������� ���� � ��������" << endl;

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
				Put(57, lang_now, ' '); //name:
				getline(cin, temp); 

				if (fopen(temp.c_str(), "r")) {
					if (NumStrs(temp) < count_strs_all[key - 49]) {
						SystemPut(1, lang_now, ' ');
						cout << "(" << NumStrs(temp)<< "<" <<count_strs_all[key-49]<<")\n";
					}
					else {
						include_files[key - 49] = temp;
						cout << "+" << endl;
						if (key == '1' || key == '2')
							EXIT(!UploadFilesMemory());
					}
				}
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
				cout <<"Fly: "<< Fly::count << endl;
				cout <<"Helicopter: "<< Helicopter::count<<endl;
				cout <<"Airplane: "<< Airplane::count<<endl;
				cout <<"ColoredHeli: "<< ColoredHeli::count<<endl;
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
				((Fly*)objFly)->readFields(
					Style::SPEED
					|Style::HEIGHT
					|Style::DISTANCE
					|Style::NUM_OF_PASS
				);
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
				((Helicopter*)objFly)->readFields(
					Style::SPEED
					| Style::HEIGHT
					| Style::DISTANCE
					| Style::NUM_OF_PASS 
					| Style::NUM_OF_SCREW 
					| Style::CAPACITY
				);
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
				Object*objFly = new Airplane(0, 0, 0, 0, 0, 0, 0);
				((Airplane*)objFly)->readFields(
					Style::SPEED
					| Style::HEIGHT
					| Style::DISTANCE
					| Style::NUM_OF_PASS 
					| Style::NUM_OF_ENGINES
					| Style::CAPACITY
					| Style::WEIGHT
				);
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
				((ColoredHeli*)objFly)->readFields(
					Style::SPEED
					| Style::HEIGHT
					| Style::DISTANCE
					| Style::NUM_OF_PASS
					| Style::NUM_OF_SCREW
					| Style::CAPACITY
					| Style::RED
					| Style::GREEN
					| Style::BLUE);
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
		if (lang_now == eng)
			cout << endl << "session saved" << endl;
		else if (lang_now == rus)
			cout << endl << "������ ���������" << endl;

	}
	else {
		if (lang_now == eng)
			cerr << endl << "session is clear" << endl;
		else if (lang_now == rus)
			cerr << endl << "������ �����" << endl;
	}
}