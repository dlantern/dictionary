#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

struct theloai{
	int matheloai;
	string tentheloai;
	vector<string> truong;
};

struct tu{
	char tu[100];
	int matheloai_tu;
	vector<string> gttruong;  // gia tri truong
};

void timtu(string tukhoa);

void themtheloai(){
	theloai tl;
	int n;     		    // so luong truong
	string tentruong;   // Xau luu gia tri tam thoi
	fstream f;

	cout << "Nhap ma the loai: ";
	cin >> tl.matheloai;
	
	cin.ignore(); 	// ignore \n ma cin >> str da bo qua
	cout << "Nhap ten the loai: ";
	getline (cin, tl.tentheloai);
	
	cout << "Nhap so truong cua '" <<tl.tentheloai << "' : ";
	cin >> n;
	
	cin.ignore();
	for (int i = 0; i < n; i++){
		cout << "Nhap ten truong thu " << i+1 << " : ";
		getline (cin, tentruong);
		tl.truong.push_back(tentruong);
	}
	
	// Ghi cau truc ra file
	f.open("ds_theloai.txt",ios::app);
	f << tl.matheloai << endl;
	f << tl.tentheloai << endl;
	for (int i = 0; i < tl.truong.size(); i++){
		f << tl.truong[i] <<";";
	}
	f << "\n";
	f.close();
}

char menu()
{
char choice;
    cout << "\n ==== Tu dien BKEncyclopedia ==== \n\n";
    cout << "\t1. Tim tu" << endl;
    cout << "\t2. Them tu" << endl;
    cout << "\t3. Them the loai." << endl;
    cout << "\t4. Hien thi danh sach tu trong 1 the loai" << endl;
    cout << "\t5. Chinh sua tu" << endl;
    cout << "\t6. Chinh sua the loai." << endl;
    cout << "\t7. Xoa mot tu" << endl;
    cout << "\t8. Xoa mot the loai" << endl;
    cout << "\t9. Thoat" << endl;
    cout << "\nLua chon thao tac tu 1-9: ";
    cin >> choice;
    return choice;
}

int main() {

	char choice;
	cout << "------------ WELCOME! ------------";
	do{
	choice = menu();
	switch(choice)
	{
		case '1':
			{
			system("cls");
			string tukhoa;
			cout << "Nhap tu muon tim kiem: ";
			cin >> tukhoa;
			break;
			}

		case '3':
			{
			system("cls");
			themtheloai();
			break;
		    }
		default: cout << "Thoat menu! " << endl;
	}
	
	} while (choice != '9');


	return 0;
}
