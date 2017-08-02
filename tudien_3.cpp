#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>
#include <cstring>
#include <cstdlib>
using namespace std;

struct theloai{
	int matheloai;
	string tentheloai;
	vector<string> truong;
};

struct tu{
	string noidung_tu;             
	int matheloai_tu;
	vector<string> gttruong;  // gia tri truong
};
void putTheLoaiIntoStruct(){
	ifstream fin;
	fin.open("ds_theloai.txt");
	
	while (!fin.eof()){
		theloai tl;
		string ma_string, truong_string, str;

		getline(fin,ma_string);
		if (ma_string.empty()) break;               // neu khac rong thi tiep tuc
		tl.matheloai = atoi(ma_string.c_str());     // gan ma the loai

		getline(fin,tl.tentheloai);   		  // gan ten the loai

		getline(fin,truong_string);         // truong_string: ___;___;___; con str la mot truong: ____ trong do
		istringstream ss(truong_string);	// can phai getline 2 lan: lan 1 de lay toan bo line

  		while (getline(ss,str,';')){        // lan 2 de lay ra cac truong, bo vao vector
			tl.truong.push_back(str);        // gan cac truong
		}

		cout << tl.matheloai << endl;
		cout << tl.tentheloai << endl;
		for (int i = 0; i < tl.truong.size(); i++){
			cout << tl.truong[i] << ";";
		}
		cout << "\n";
		
 }
}
// ==========================================================================================================================
void timtu(string tukhoa);

// ==========================================================================================================================
void themtu(){
	tu t;
	
	cin.ignore();
	cout << "Nhap tu: ";
	cin >> t.noidung_tu;
	
	cout << "Nhap ma the loai: ";
	cin >> t.matheloai_tu;
}

// ==========================================================================================================================
void themtheloai(){
	theloai tl;
	int n, temp;     		    // n: so luong truong
	string tentruong;   // Xau luu gia tri tam thoi
	fstream f;

	// MA THE LOAI
 	while (1) {
    cout << "Nhap ma the loai: ";
    cin >> temp;

    if (cin.fail()) {
    	cout << "Nhap sai dinh dang! Hay nhap so nguyen.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // su dung ignore de >> ko trich xuat data tu stream nua
        continue; 				
    }
    else break;
	}
	tl.matheloai = temp;
	
	// TEN THE LOAI
	cin.ignore(); 					// ignore \n ma cin >> str da bo qua
	cout << "Nhap ten the loai: ";
	getline (cin, tl.tentheloai);
	
	// CAC TRUONG - THUOC TINH
 	while (1) {
    cout << "Nhap so truong cua '" << tl.tentheloai << "' : ";
    cin >> n;

    if (cin.fail()) {
    	cout << "Nhap sai dinh dang! Hay nhap so nguyen.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // su dung ignore de >> ko trich xuat data tu stream nua
        continue; 				
    }
    else break;
	}

 	cin.ignore();
	for (int i = 0; i < n; i++){
		cout << "Nhap ten truong thu " << i+1 << " : ";
		getline (cin, tentruong);
		tl.truong.push_back(tentruong);
	}
	
	// Ghi cau truc ra file
	f.open("ds_theloai.txt",ios::app);
	if (f.is_open()){
		f << tl.matheloai << endl;
		f << tl.tentheloai << endl;
		for (int i = 0; i < tl.truong.size(); i++){
			f << tl.truong[i] <<";";
		}
		f << "\n";
		f.close();
	}
}

// ==========================================================================================================================
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
		case '2':
			{
			system("cls");
			themtu();
			break;
		    }
		case '3':
			{
			system("cls");
			themtheloai();
			break;
		    }
		case '4':
			{
			system("cls");
			ifstream fin;
			putTheLoaiIntoStruct();
			break;
		    }
		default: cout << "Thoat menu! " << endl;
	}
	
	} while (choice != '9');


	return 0;
}
