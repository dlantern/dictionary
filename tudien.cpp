#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <algorithm>

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
// ==========================================================================================================================
//                                                                                                          LOWER
string lower(string s){
	string ans = s;
	transform(ans.begin(),ans.end(),ans.begin(),::tolower);
	return ans;
}

// ==========================================================================================================================
//                                                                                                	      TIM TU
void timtu(string tukhoa){
	ifstream fin, fin2;
	fin.open("ds_tu.txt");

	int flag = 0;

	while (!fin.eof()){

		tu t;
		string nd_tu, matl_tu, pre_vec;     // pre_vec: string truoc khi dua vao vector

		getline(fin,nd_tu);
		if (nd_tu.empty()) break;       // neu rong thi thoat vong while
		t.noidung_tu = nd_tu;          // gan noi dung tu

		getline(fin,matl_tu);
		t.matheloai_tu = atoi(matl_tu.c_str());         // gan ma the loai

		fin2.open("ds_theloai.txt");

		while (!fin2.eof()){        // Tim the loai tuong ung
			theloai tl;
			string ma_string, truong_string, str;

			getline(fin2,ma_string);
			if (ma_string.empty()) break;
			tl.matheloai = atoi(ma_string.c_str());

			getline(fin2,tl.tentheloai);

			getline(fin2,truong_string);
			istringstream ss(truong_string);	// can phai getline 2 lan: lan 1 de lay toan bo line

	  		while (getline(ss,str,';')){        // lan 2 de lay ra cac truong, bo vao vector
				tl.truong.push_back(str);
			}
			// --------------------------------------------- gan xong struct cho the loai


			if ( (tl.matheloai == t.matheloai_tu) && ((lower(tukhoa).compare(lower(t.noidung_tu)) ) == 0 )) {
				for (int i = 0; i < tl.truong.size(); i++){
					getline(fin,pre_vec);
					t.gttruong.push_back(pre_vec);
				}
				cout << "Tim thay tu " << tukhoa << ", thuoc the loai " << t.matheloai_tu << ", " << tl.tentheloai << endl;
				for (int i = 0; i < tl.truong.size(); i++)
					cout << tl.truong[i] << " : " << t.gttruong[i] << endl;

				flag = 1;
				break;
			}
		}
		if (flag != 0) break;
		fin2.close();
	}
	fin.close();
	if (flag == 0) cout << "Khong tim thay tu '" << tukhoa << "' !";
}

// ==========================================================================================================================
//                                                                                                      THEM TU
void themtu(){
	tu t;
	int temp;
	string giatritruong;
	fstream f;
	
	cin.ignore();
	cout << "Nhap tu: ";         
	getline(cin, t.noidung_tu);  // GAN TU
	
	while (1) {
	cout << "Nhap ma the loai cua tu: ";
	cin >> temp;

    if (cin.fail()) {
    	cout << "Nhap sai dinh dang! Hay nhap so nguyen.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // su dung ignore de >> ko trich xuat data tu stream nua
        continue;
    }

	// SO SANH MA THE LOAI VOI CAC MA DA CO
	int flag = 0;
	ifstream fin;
	fin.open("ds_theloai.txt");

	while (!fin.eof()){
		theloai tl;
		string ma_string, truong_string, str;

		getline(fin,ma_string);
		if (ma_string.empty()) break;               // neu khac rong thi tiep tuc
		tl.matheloai = atoi(ma_string.c_str());     // * gan ma the loai

		getline(fin,tl.tentheloai);   		  // * gan ten the loai

		getline(fin,truong_string);         // truong_string: ___;___;___; con str la mot truong: ____ trong do
		istringstream ss(truong_string);	// can phai getline 2 lan: lan 1 de lay toan bo line

  		while (getline(ss,str,';')){         // lan 2 de lay ra cac truong, bo vao vector
			tl.truong.push_back(str);        // * gan cac truong
		}
		
		if (temp == tl.matheloai){
  		flag = 1;                           // Neu ton tai ma tuong ung
		cout << "The loai: " << tl.tentheloai << endl;
		t.matheloai_tu = temp;              // GAN MA THE LOAI
  		
  		// NHAP GIA TRI CAC TRUONG
  		cin.ignore();
  		for (int i = 0; i < tl.truong.size(); i++){
  			cout << "Nhap gia tri cho truong '" << tl.truong[i] << "' : " ;
  			getline (cin,giatritruong);
  			t.gttruong.push_back(giatritruong);                 
		}
   		break;
		}
	}
	if (flag != 0) break;        // Neu trung voi ma the loai thi cho nhap tiep
	else {
		cout << "Khong ton tai ma the loai tuong ung!\n\n";
		continue;
		}
	}
	// Ghi cau truc ra file
	f.open("ds_tu.txt",ios::app);
	if (f.is_open()){
		f << t.noidung_tu << endl;
		f << t.matheloai_tu << endl;
		for (int i = 0; i < t.gttruong.size(); i++){
			f << t.gttruong[i] << endl;
		}
	}
	f.close();

}

// ==========================================================================================================================
//                                                                                                      THEM THE LOAI
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

	// SO SANH MA THE LOAI VOI CAC MA DA CO
	int flag = 0;
	ifstream fin;
	fin.open("ds_theloai.txt");
	
	while (!fin.eof()){
		theloai tl;
		string ma_string, truong_string, str;

		getline(fin,ma_string);
		if (ma_string.empty()) break;               // neu khac rong thi tiep tuc
		tl.matheloai = atoi(ma_string.c_str());     // * gan ma the loai

		getline(fin,tl.tentheloai);   		  // * gan ten the loai

		getline(fin,truong_string);         // truong_string: ___;___;___; con str la mot truong: ____ trong do
		istringstream ss(truong_string);	// can phai getline 2 lan: lan 1 de lay toan bo line

  		while (getline(ss,str,';')){         // lan 2 de lay ra cac truong, bo vao vector
			tl.truong.push_back(str);        // * gan cac truong
		}
		if (temp == tl.matheloai){
			cout << "Trung ma the loai. Hay nhap ma khac!\n\n";
			flag = 1;
			break;
		}
	}
	if (flag != 0) continue;        // Neu bi trung thi nhap lai
	break;
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
    break;
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
	}
	f.close();
}

// ==========================================================================================================================
//                                                                                              HIEN THI TU TRONG THE LOAI
void hienThiTheLoai(){
	
	int m, flag = 0;
	ifstream fin, fin2;
	
	while (1) {
	cout << "Nhap ma the loai muon hien thi: ";
	cin >> m;

    if (cin.fail()) {
    	cout << "Nhap sai dinh dang! Hay nhap so nguyen.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // su dung ignore de >> ko trich xuat data tu stream nua
        continue;
    }

	// SO SANH MA THE LOAI VOI CAC MA DA CO
	cout << "Tu thuoc the loai tren: ";
	fin.open("ds_tu.txt");

	while (!fin.eof()){

		tu t;
		string nd_tu, matl_tu, pre_vec;     // pre_vec: string truoc khi dua vao vector

		getline(fin,nd_tu);
		if (nd_tu.empty()) break;       // neu rong thi thoat vong while
		t.noidung_tu = nd_tu;          // gan noi dung tu

		getline(fin,matl_tu);
		t.matheloai_tu = atoi(matl_tu.c_str());         // gan ma the loai

		fin2.open("ds_theloai.txt");

		while (!fin2.eof()){        // Tim the loai tuong ung
			theloai tl;
			string ma_string, truong_string, str;

			getline(fin2,ma_string);
			if (ma_string.empty()) break;
			tl.matheloai = atoi(ma_string.c_str());

			getline(fin2,tl.tentheloai);

			getline(fin2,truong_string);
			istringstream ss(truong_string);	// can phai getline 2 lan: lan 1 de lay toan bo line

	  		while (getline(ss,str,';')){        // lan 2 de lay ra cac truong, bo vao vector
				tl.truong.push_back(str);
			}
			// --------------------------------------------- gan xong struct cho the loai

			if ( (tl.matheloai == t.matheloai_tu) && (t.matheloai_tu == m ) ) {
				for (int i = 0; i < tl.truong.size(); i++){
	 				getline(fin,pre_vec);
					t.gttruong.push_back(pre_vec);
				}
				cout << "\n" << t.noidung_tu;

				flag = 1;
				break;
			}
		}
		fin2.close();

	} // close while fin

	fin.close();
	if (flag != 0) break;        // Neu trung voi ma the loai thi cho nhap tiep
	else {
		cout << " khong co! \nKhong ton tai ma the loai tuong ung!\n\n";
		continue;
		}
	}
}

// ==========================================================================================================================
//                                                                                                   	CHINH SUA, XOA TU

void suaxoatu(string tukhoa){
	fstream fin, fin2;
	fin.open("ds_tu.txt");

	int flag = 0;

	while (!fin.eof()){

		tu t;
		string nd_tu, matl_tu, pre_vec;     // pre_vec: string truoc khi dua vao vector

		getline(fin,nd_tu);
		if (nd_tu.empty()) break;       // neu rong thi thoat vong while
		t.noidung_tu = nd_tu;          // gan noi dung tu

		getline(fin,matl_tu);
		t.matheloai_tu = atoi(matl_tu.c_str());         // gan ma the loai

		fin2.open("ds_theloai.txt");

		while (!fin2.eof()){        // Tim the loai tuong ung
			theloai tl;
			string ma_string, truong_string, str;

			char c;
			string tg, stg;         // tg: xau trung gian; stg: truong trung gian

			getline(fin2,ma_string);
			if (ma_string.empty()) break;
			tl.matheloai = atoi(ma_string.c_str());

			getline(fin2,tl.tentheloai);

			getline(fin2,truong_string);
			istringstream ss(truong_string);	// can phai getline 2 lan: lan 1 de lay toan bo line

	  		while (getline(ss,str,';')){        // lan 2 de lay ra cac truong, bo vao vector
				tl.truong.push_back(str);
			}
			// --------------------------------------------- da tim dc struct cho the loai:

			if ( (tl.matheloai == t.matheloai_tu) && ((lower(tukhoa).compare(lower(t.noidung_tu)) ) == 0 )) {
				for (int i = 0; i < tl.truong.size(); i++){
					getline(fin,pre_vec);
					t.gttruong.push_back(pre_vec);
				}
				cout << "Tim thay tu " << tukhoa << ", thuoc the loai " << t.matheloai_tu << ", " << tl.tentheloai << endl;
				cout << "Ban muon sua hay xoa tu? (s/x) ";
				cin >> c;
				switch (c)
				{
					case 's':
						{
							cout << "Tu cu: " << t.noidung_tu <<"\nSua thanh tu moi: ";
							cin.ignore();
							getline(cin, t.noidung_tu);

							cout << "Ma the loai cua tu cu: " << t.matheloai_tu <<"\nSua thanh ma the loai moi: ";
							cin.ignore();
							getline(cin, tg);
							t.matheloai_tu = atoi(tg.c_str());

							for (int i = 0; i < t.gttruong.size(); i++){
					  			cout << "Nhap gia tri cho truong '" << tl.truong[i] << "'  " << endl;
					  			cout << "Gia tri cu: " << t.gttruong[i] << "\nGia tri moi: " ;
					  			getline (cin,stg);
					  			t.gttruong[i] = stg;
							}

//							fin << t.noidung_tu << endl;
//							fin << t.matheloai_tu << endl;
//							for (int i = 0; i < t.gttruong.size(); i++){
//								fin << t.gttruong[i] << endl;
//							}
							break;
						}
					case 'x':
						{
							t.noidung_tu = "";

							t.matheloai_tu = 0;

							for (int i = 0; i < t.gttruong.size(); i++){
					  			t.gttruong[i] = "";

							}
							cout << "Da xoa!";
							break;
						}
					default:
						{
							cout << "Khong hop le!";
							break;
						}
				}

				flag = 1;
				break;
			}
		}
		fin2.close();

	}
	fin.close();
	if (flag == 0) cout << "Khong tim thay tu '" << tukhoa << "' !";
}


// ==========================================================================================================================
//                                                                                          XOA THE LOAI
void xoatheloai() {
	int temp;
	theloai tl;
	tu t;
	fstream f;

	cout << "\n\n\n\tDELETE THE LOAI";
	cout << "\n\nNhap ma the loai ban muon xoa : ";
	cin >> temp;
	f.open("ds_theloai.txt", ios::in | ios::out);
	fstream fp2;
	fp2.open("Temp.dat", ios::out);
	f.seekg(0, ios::beg);
	while (f.read((char*)&tl, sizeof(theloai)))
	{
		if (tl.matheloai != temp)
		{
			fp2.write((char*)&tl, sizeof(theloai));
		}
	}

	fp2.close();
	f.close();
	remove("ds_theloai.txt");
	rename("Temp.dat", "ds_theloai.txt");

	f.open("ds_tu.txt", ios::in | ios::out);
	fstream fp3;
	fp3.open("Temp.dat", ios::out);
	f.seekg(0, ios::beg);
	while (f.read((char*)&t, sizeof(tu)))
	{
		if (t.matheloai_tu != temp)
		{
			fp3.write((char*)&t, sizeof(tu));
		}
	}

	fp3.close();
	f.close();
	remove("ds_tu.txt");
	rename("Temp.dat", "ds_tu.txt");
	cout << "\n\n Deleted ..";
}


// ==========================================================================================================================
//                                                                                                   MENU
char menu()
{
	char choice;
    cout << "\n\n ==== Tu dien BKEncyclopedia ==== \n\n";
    cout << "\t|1| Tra cuu tu" << endl;
    cout << "\t|2| Them tu" << endl;
    cout << "\t|3| Them the loai" << endl;
    cout << "\t|4| Hien thi danh sach tu trong mot the loai" << endl;
    cout << "\t|5| Chinh sua, xoa mot tu" << endl;
    cout << "\t|6| Chinh sua, xoa mot the loai" << endl;
    cout << "\t|7| Thoat" << endl;
    cout << "\nLua chon thao tac tu 1-7: ";
    cin >> choice;
    return choice;
}

int main() {

	char choice;
	cout << " ____  _  __  ______                       _                      _ _" << endl;
	cout << "|  _ \\| |/ / |  ____|                     | |                    | (_)" << endl;;
	cout << "| |_) | ' /  | |__   _ __   ___ _   _  ___| | ___  _ __   ___  __| |_  __ _ " << endl;
	cout << "|  _ <|  <   |  __| | '_ \\ / __| | | |/ __| |/ _ \\| '_ \\ / _ \\/ _` | |/ _` |" << endl;
	cout << "| |_) | . \\  | |____| | | | (__| |_| | (__| | (_) | |_) |  __/ (_| | | (_| |" << endl;
	cout << "|____/|_|\\_\\ |______|_| |_|\\___|\\__, |\\___|_|\\___/| .__/ \\___|\\__,_|_|\\__,_|" << endl;
	cout << "                                 __/ |            | |                      " << endl;
	cout << "                                |___/             |_| " << endl;
	do{
	choice = menu();
	switch(choice)
	{
		case '1':
			{
			system("cls");
			string tukhoa;
  			cin.ignore();
			cout << "Nhap tu muon tim kiem: ";
			getline(cin,tukhoa);
			timtu(tukhoa);
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
			hienThiTheLoai();
			break;
		    }
		case '5':
			{
			system("cls");
			string tukhoa;
  			cin.ignore();
			cout << "Nhap tu ban muon chinh sua/xoa: ";
			getline(cin,tukhoa);
			suaxoatu(tukhoa);
			break;
		    }
		case '6':
			{
			system("cls");
			xoatheloai();
			break;
		    }

		default: cout << "Thoat menu! " << endl;
	}
	
	} while (choice != '7');

	return 0;
}
