#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<string.h>


using namespace std;
int main() {

    FILE  *fd,*fp,*ft,*fk;
    //FILE *fd, *fd1;

    char another, choice,chontruong;

struct theloai{
	int matheloai;
	char tentheloai[100];
	char truong1[1000],truong2[1000],truong3[1000];
};
struct danhsachtu{
	char tu[100];
	int xmatheloai;
	char xtruong1[1000],xtruong2[1000],xtruong3[1000];
};
	char xtu[100],xtentheloai[100];
	int tmatheloai;
    struct theloai e;
    struct danhsachtu d;
    long int recsize;
    long int xrecsize;

	fd=fopen("danhsach.txt","rb+");
	
	if (fd == NULL) {
        fd = fopen("danhsach.txt","wb+");

        if (fd==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }
	
    fp=fopen("users.txt","rb+");

    if (fp == NULL) {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }
    
	


 recsize = sizeof(e);
 xrecsize = sizeof(d);
// xrecsize = sizeof(d);
 
 while(1) {
     system("cls");

     cout << "\t\t=========== TRA TU DIEN ===========";
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout<<" \n\t\t\t======================";
     cout << "\n \t\t\t  1. Tim tu";
     cout << "\n \t\t\t  2. Them tu";
     cout << "\n \t\t\t  3. Them the loai";
     cout << "\n \t\t\t  4. Hien thi danh sach tu trong 1 the loai";
     cout << "\n \t\t\t  5. Chinh sua tu";
     cout << "\n \t\t\t  6. Xoa tu";
     cout << "\n \t\t\t  7. Sua 1 the loai";
     cout << "\n \t\t\t  8. Xoa the loai";
     cout << "\n \t\t\t  9. Thoat";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Ban chon 1 so :: ";
     fflush(stdin);
     choice = getche();
     switch(choice)
     {
     	
      case '1' ://Tim tu
            system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Nhap tu muon tim : ";
              fflush(stdin);
              gets(xtu);

            rewind(fd);
            int x = 0;
            rewind(fd);
            while (fread(&d,xrecsize,1,fd) == 1)
            {
                if (strcmp(d.tu,xtu) ==0)
                {
                cout << "\n";
	            cout <<"\nTu     :: " <<d.tu;
	            cout <<"\nMa the loai  :: "<<d.xmatheloai;
	            cout <<"\nTruong 1  :: "<<d.xtruong1;
	            cout <<"\nTruong 2   :: " <<d.xtruong2;
	            cout <<"\nTruong 3  :: "<<d.xtruong3;
	        	x=1;
	        
	            break;
                }
			}
			if(x==0){
				cout << "\n Khong tim thay tu ban can : ";	
			}
            cout << "\n Tim 1 tu khac? (Y/N) ";
                fflush(stdin);
                another = getchar();
                cin.ignore();
            }
            break;
	  
      case '2' ://Them tu
            fseek(fd,0,SEEK_END);
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                  system("cls");
                
                
                
                cout << "Nhap ma the loai : ";
                fflush(stdin);
                cin >> tmatheloai;
                cin.ignore();
                rewind(fp);
                int x =0;
                while (fread(&e,recsize,1,fp) == 1)
            	{
            		if(e.matheloai == tmatheloai){
            			
	                	d.xmatheloai = tmatheloai;
	                	cout << "Nhap tu :  ";
	                	gets(d.tu);	
	                	cout <<"\nNhap  "<<e.truong1;
	                	gets(d.xtruong1);
	                	cout <<"\nNhap  "<<e.truong2;
	                	gets(d.xtruong2);
	                	cout <<"\nNhap  "<<e.truong3;
	                	gets(d.xtruong3);
	                	fwrite(&d,xrecsize,1,fd);
	                	x++;
	                	break;
                	}
                	
            	}
            	if(x==0){
                		cout << "Chua co ma the loai ban nhap vao ! ";
                	}
                cout << "\n Them 1 tu nua? (Y/N) ";
                fflush(stdin);
                another = getchar();
                cin.ignore();
            }
            break;
            
        case '3' ://Them the loai
        	fseek(fp,0,SEEK_END);
        //	fseek(fd,0,SEEK_END);
            another ='Y';
            //nhan:
            while(another == 'Y' || another == 'y')
            {
                  system("cls");
                cout << "Nhap ma the loai : ";
                cin >> e.matheloai;
                cin.ignore();
                cout << "Nhap ten the loai : ";
		        gets(e.tentheloai);
		        cout << "Nhap truong 1    : ";
                gets(e.truong1);
		        cout << "Nhap truong 2   : ";
		        gets(e.truong2);
		        cout << "Nhap truong 3   : ";
		        gets(e.truong3);
		        fwrite(&e,recsize,1,fp);
//               int x = 0;
//               rewind(fp);
//               while(fread(&e,recsize,1,fp) == 1){
//               		if(e.matheloai == tmatheloai){
//               			x++;
//               			cout <<"\n Ma the loai da ton tai!";
//               			cout << "\n Them 1 tu nua? (Y/N) ";
//		                fflush(stdin);
//		                another = getchar();
//               		}
//               		if(x==0){
//						cout << "Nhap ten the loai : ";
//		                gets(e.tentheloai);
//		                cout << "Nhap truong 1    : ";
//		                gets(e.truong1);
//		                cout << "Nhap truong 2   : ";
//		                gets(e.truong2);
//		                cout << "Nhap truong 3   : ";
//		                gets(e.truong3);
//		                fwrite(&e,recsize,1,fp);
//		                break;
//					}
//               		
//			}
				
						
                cout << "\n Them 1 tu nua? (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
//        	fseek(fp,0,SEEK_END);
//            another ='Y';
//            while(another == 'Y' || another == 'y')
//            {
//                  system("cls");
////                cout << "Nhap tu : ";
//                fflush(stdin);
////                gets(e.tu);
//			//	cin.ignore();
//                cout << "Nhap ma the loai : ";
//                cin >>tmatheloai;
//                cin.ignore();
//                rewind(fp);
//                int x =0;
//            //    while (fread(&e,recsize,1,fp) == 1)
//            //	{
//            		//if(e.matheloai!=tmatheloai){
//            			e.matheloai == tmatheloai;
//            			cout << "Nhap ten the loai : ";
//		                gets(e.tentheloai);
//		                cout << "Nhap truong 1    : ";
//		                gets(e.truong1);
//		                cout << "Nhap truong 2   : ";
//		                gets(e.truong2);
//		                cout << "Nhap truong 3   : ";
//		                gets(e.truong3);
//		               // fseek(fd, xrecsize, SEEK_SET);
//		               // fread(&e,recsize,1,fp)==1;
//		                fseek(fp,  recsize, SEEK_CUR);
//		                fwrite(&e,recsize,1,fp);
//		                break;
////            		}
////					else{
////						cout<<"Ma the loai da ton tai!";
////					}	
////            	}
////            	if(x==0){
////            			
////            			
////            	}else{
////            		cout<<"Ma the loai da ton tai!";
////            	}
//            	
//                
//                cout << "\n Them 1 the loai nua? (Y/N) ";
//                fflush(stdin);
//                another = getchar();
//            }
//            break;
            
     case '4'://Hien thi danh sach tu trong 1 the loai
            system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Nhap ma the loai muon tim : ";
              fflush(stdin);
              cin >> tmatheloai;

            rewind(fd);
            int x = 0;
            while (fread(&d,xrecsize,1,fd) == 1)
            {
                if (d.xmatheloai == tmatheloai)
                {
                cout << "\n";
                cout <<"\nMa the loai  :: "<<d.xmatheloai;
	            cout <<"\nTu     :: " <<d.tu;
	            cout <<"\nTruong 1  :: "<<d.xtruong1;
	            cout <<"\nTruong 2   :: " <<d.xtruong2;
	            cout <<"\nTruong 3  :: "<<d.xtruong3;
	            x++;
                }
			}
			if(x == 0){
				cout<<"\nKhong co thong tin ve ma the loai nay ";	
			}
            cout << "\n Hien thi danh sach tu theo ma khac? (Y/N) ";
                fflush(stdin);
                another = getchar();
                cin.ignore();
            }
            break;
            
     case '5' ://Chinh sua tu
	 	system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Nhap tu muon sua : ";
              fflush(stdin);
              gets(xtu);
			  int x = 0;
            rewind(fd);
            while (fread(&d,xrecsize,1,fd) == 1)
            {
                if (strcmp(d.tu,xtu) ==0)
                {
                cout << "Nhap tu moi : ";
                fflush(stdin);
                gets(d.tu);
                cout << "Nhap truong 1    : ";
                gets(d.xtruong1);
                cout << "Nhap truong 2   : ";
                gets(d.xtruong2);
                cout << "Nhap truong 3   : ";
				gets(d.xtruong3);
                fseek(fd, - xrecsize, SEEK_CUR);
                fwrite(&d,xrecsize,1,fd);
                x++;
                break;
                }
			}
			if(x==0){
					cout<<"\nKhong tim thay tu ";
				}
            cout << "\n Sua 1 tu khac? (Y/N) ";
                fflush(stdin);
                another = getchar();
                cin.ignore();
            }
            break;
                
	 case '6'://Xoa tu
       system("cls");
           another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Nhap tu can xoa : ";
              fflush(stdin);
              gets(xtu);

              ft = fopen("temp.dat", "wb");
			  int x = 0;
              rewind(fd);
              while (fread (&d, xrecsize,1,fd) == 1)
				{
	                 if (strcmp(d.tu,xtu) !=0)
	                {
	                    fwrite(&d,xrecsize,1,ft);
	                    
	                }else {
	                	cout << "\n Da xoa thanh cong !";
						x ++;
						break;	
	                }
	            }
	            if(x == 0){
	            	cout << "\n Tu nay khong co trong danh sach!";	
				}
                fclose(fd);
                fclose(ft);
                remove("danhsach.txt");
                rename("temp.dat","danhsach.txt");

                fd=fopen("danhsach.txt","rb+");

                cout << "\n Xoa 1 tu khac? (Y/N) ";
                fflush(stdin);
                another = getchar();
                cin.ignore();
              }

              break;  
              
     case '7' ://Sua 1 the loai
     	system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Nhap ma the loai muon sua : ";
              //cin.ignore();
              fflush(stdin);
              cin >> tmatheloai;
			  int x = 0;
            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                if (e.matheloai == tmatheloai)
                {
                	//e.matheloai = tmatheloai;
	                cout << "Nhap ten the loai moi : ";
	                cin >> tmatheloai;
	                gets(e.tentheloai);
	                cout << "Nhap truong 1    : ";
	                gets(e.truong1);
	                cout << "Nhap truong 2   : ";
	                gets(e.truong2);
	                cout << "Nhap truong 3   : ";
					gets(e.truong3);
	                fseek(fp, recsize, SEEK_CUR);
	                fwrite(&e,recsize,1,fp);
	                x++;
	                break;
                }
			}
			if(x==0){
					cout<<"\nKhong tim thay the loai muon sua! ";
				}
            cout << "\n Sua 1 the loai khac? (Y/N) ";
                fflush(stdin);
                another = getchar();
                cin.ignore();
            }
            break;
//            system("cls");
//          another = 'Y';
//          while (another == 'Y'|| another == 'y')
//          {
//              cout << "\n Nhap ten the loai muon sua : ";
//              gets(xtentheloai);
//			int x = 0;
//            rewind(fp);
//            while (fread(&e,recsize,1,fp) == 1)
//            {
//                if (strcmp(e.tentheloai,xtentheloai) ==0)
//                {
//                cout << "Nhap ten the loai moi : ";
//                //cin >> e.tu;
//                fflush(stdin);
//                gets(e.tentheloai);
//                
//                
//                fseek(fp,  recsize, SEEK_CUR);
//                fwrite(&e,recsize,1,fp);
//                x++;
//                cout<<"\nDa sua ten the loai! ";
//                break;
//                }
//                
//            	
//			}
//			if(x==0){
//                	cout<<"\nKhong tim thay ma the loai! ";
//            	}
//            cout << "\n Sua 1 ten the loai khac? (Y/N) ";
//                fflush(stdin);
//                another = getchar();
//                cin.ignore();
//            }
//            break;
            
     case '8'://Xoa the loai
       system("cls");
           another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Nhap ma the loai can xoa : ";
              fflush(stdin);
              cin >> tmatheloai;
              ft = fopen("temp.dat", "wb");

              rewind(fp);
              int x=0;
              while (fread (&e, recsize,1,fp) == 1)
			  {
	                 if (e.matheloai != tmatheloai)
	                {
	                    fwrite(&e,recsize,1,ft);
	                }else{
	                	x++;
	                	break;
	                }
                }
                if(x==0){
                	cout << "\nMa ban nhap khong co trong danh sach!";
                }
                else {
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fd=fopen("danhsach.txt","rb+");
                
                ft = fopen("temp.dat", "wb");

              rewind(fd);
              while (fread (&d, xrecsize,1,fd) == 1)
			  {
	                 if (d.xmatheloai != tmatheloai)
	                {
	                    fwrite(&d,xrecsize,1,ft);
	                }
               }
			    fclose(fd);
                fclose(ft);
                remove("danhsach.txt");
                rename("temp.dat","danhsach.txt");

                fd=fopen("danhsach.txt","rb+");	
                cout << "\n Da xoa thanh cong!";
                }
                

                cout << "\n Xoa 1 the loai khac? (Y/N) ";
                fflush(stdin);
                another = getchar();
                cin.ignore();
              }
        break;
     
              case '9'://Thoat
              fclose(fp);
              cout << "\n\n";
              cout << "\t\t     THANK YOU !";
              cout << "\n\n";
              exit(0);
          }
     }
return 0;
}
