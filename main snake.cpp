//CODE GAME RAN SAN MOI BY NGUYEN TRAN VINH
//==cac thu vien==
#include <windows.h>
#include <Windows.h>
#include <iostream>
#include <conio.h> // use getch,kbhit
#include <fstream> // flie
#include <unistd.h>// use sleep
#include <string.h>// use getline
#include <cstring>//use strcpy
#include <cctype>// use tolower
#include <iomanip>// use setw
#include "libsnake.h"

//==dinh nghia==
#define fla speed  // toc do ran 
#define m 6 // hien thi mau thuc an  
#define colorht 10// hien thi mau  diem
#define mauran 1// hien thi mau ran
#define maukhung 4 // hien thi mau khung
using namespace std;

/* huong doi tuong */
int speed;
int kt;
int diem = 1;
string name;
class khunghinh
{
private:
	int map[200][200];
	int x, y;
public:
	khunghinh()// khoi tao 0 tham so
	{
		x = 30;
		y = 50;
	}
	void taokhung()
	{
		int i, j;
		for (i = 1; i <= x; i++)
		{
			for (j = 1; j <= y; j++)
			{
				if (i == 1 || i == x || j == 1 || j == y)
					map[i][j] = 3;
				else
					map[i][j] = 0;
 
			}
		}
	}
	void hienthikhung()
	{
		int i, j;
		textcolor(3);//doi mau chu
		gotoxy(60, 11);
		cout << "DIEM : ";
		gotoxy(68, 11);
		textcolor(colorht);
		cout << diem;
		textcolor(3);
		gotoxy(60, 13);
		cout << "______________________________________" ;
		gotoxy(60, 14);
		cout << "DIEU KHIEN GAME BANG: CAC PHIM MUI TEN" ;
		gotoxy(60, 15);
		cout << "PRESS 'p' TO PAUSE GAME" ;
		gotoxy(60, 16);
		cout << "PRESS 'o' TO OUT GAME" ;
		gotoxy(60, 18);
		cout << "<-CODE BY NGUYEN TRAN VINH->";
		gotoxy(60, 20);
		cout << "GVHD: LE QUOC ANH" ;
		gotoxy(1, 1);
		
		for (j = 1; j <= y; j++)
		{
			textcolor(maukhung);
			cout << "*"; // tuong ngang
		}
		cout << endl;
		for (i = 2; i < x; i++)
		{
			for (j = 1; j <= y; j++)
			{
				if (map[i][j] == 3)
					cout << "*"; // tuong doc
				else
					cout << ' ';
			}
			cout << endl;
		}
		for (j = 1; j <= y; j++)
			cout << "*";// tuong ngang
	}
	void truyen(int x1, int y1, int v)
	{
		map[x1][y1] = v;
	}
	int getvt(int x2, int y2)
	{
		return map[x2][y2];
	}
	
	void taothucan()
	{
		int r;
		do
		{
			int tx = rand() % 28 + 3;// random môi
			int ty = rand() % 48 + 3;
			if (getvt(tx, ty) == 0)
			{
				truyen(tx, ty, 2);
				textcolor(m);
				gotoxy(ty, tx);
				cout << (char)3;
				kt = 1;
				r = 0;
			}
			else
				r = 1;
		} while (r == 1);
	}
};
class Stack
{
private:
	pair<int, int> d[1500]; // luu tru 2 muc khac nhau nhung cx 1 thuc the
	int dau;
public:
	Stack()
	{
		dau = 0;
	}
	void themdau(int x, int y)
	{
		d[dau].first = x;
		d[dau].second = y;
		dau++;
	}
	void xoa()
	{
		for (int i = 0; i < dau; i++)
		{
			d[i].first = d[i + 1].first;
			d[i].second = d[i + 1].second;
		}
		dau--;
	}
	int getxc()
	{
		return d[0].first;
	}
	int getyc()
	{
		return d[0].second;
	}
 
};
class conran : public khunghinh
{
private:
	int xd;
	int yd;
	Stack ran;
public:
	conran() //vi tri ran ban dau
	{
		xd = 15;
		yd = 25;
	}
	void vedot(int x, int y) // ve dôt dau
	{
		gotoxy(y, x);
		textcolor(mauran);
		cout << "O";
 
	}
	void xoadot(int x, int y) //xóa dot cuoi
	{
		gotoxy(y, x);
		cout << " ";
		truyen(x, y, 0);
 
	}
	void khoitaoran()
	{
		conran();
		vedot(xd, yd); // dau
		ran.themdau(xd, yd);
		truyen(xd, yd, 1);
		taothucan();
	}
	void game()
	{
		system("cls");
		gotoxy(15,5);
		textcolor(3);
		cout << "Choose snake speed level (1 - 5): ";// toc do ran tang dan
		int t;
		cin >> t;
		speed = 600 - t * 100; // toc do ran
		system("cls");
		textcolor(14);
		gotoxy(45,10);
		cout << "Ready!\n";
		Sleep(500);
		for (int i = 3; i > 0; i--)
		{
			gotoxy(47, 11);
			cout << i << "          ";
			Sleep(700);
		}
		gotoxy(46, 11);
		cout << "GO!";
		Sleep(1000);
		hienthikhung();
	}
	void showendgame()// xuat hien khi ran dead
    {
        Sleep(500);
	    string name;
	    gotoxy(20, 34);
	    textcolor(colorht);
	    cout << "                   NHAP TEN CUA BAN: " ;
	    cin>>name;
	    gotoxy(20, 35);
	    cout << "________________ THANK YOU FOR PLAYING GAME ______________" << endl;
	    gotoxy(20, 37);
	    cout << "     ________________ DIEM CUA BAN : " << diem << " ______________";
	    // tao file ghi
	    ofstream fileout;
	    fileout.open("score.text",ios::out );
	    fileout<<name<<setw(2)<<diem;
	    fileout.close(); // dong de do ton dung lg va thong bao da su dung xong file
	    exit(0);
	}
	int len()
	{
		Sleep(fla);// toc do ran
		if (kt == 0)
			taothucan();
		xd--;
		ran.themdau(xd, yd);
		vedot(xd, yd);
		if (getvt(xd, yd) == 2)
		{
			kt = 0;
			cout << "\a"; // tao tieng khi an qua
			diem++;
			textcolor(colorht);
			gotoxy(68, 11);
			cout << diem;
		}
		else if (getvt(xd, yd) == 3)
		{
			showendgame();
		}
		else
		{
			xoadot(ran.getxc(), ran.getyc());// khong them
			ran.xoa();
		}
		truyen(xd, yd, 1);
	}
	int xuong()
	{
		Sleep(fla);
		if (kt == 0)
			taothucan();
		xd++;
		ran.themdau(xd, yd);
		vedot(xd, yd);
		if (getvt(xd, yd) == 2)
		{
 
			kt = 0;
			cout << "\a";//
			diem++;
			textcolor(colorht);
			gotoxy(68, 11);
			cout << diem;
 
		}
		else if (getvt(xd, yd) == 3)
		{
			showendgame();
		}
		else
		{
			xoadot(ran.getxc(), ran.getyc());
			ran.xoa();
		}
		truyen(xd, yd, 1);
	}
	int trai()
	{
 
		Sleep(fla);
		if (kt == 0)
			taothucan();
		yd--;
		ran.themdau(xd, yd);
		vedot(xd, yd);
		if (getvt(xd, yd) == 2)
		{
 
			kt = 0;
			cout << "\a";
			diem++;
			textcolor(colorht);
			gotoxy(68, 11);
			cout << diem;
		}
		else if (getvt(xd, yd) == 3)
		{
			showendgame();
		}
		else
		{
			xoadot(ran.getxc(), ran.getyc());
			ran.xoa();
		}
		truyen(xd, yd, 1);
	}
	int phai()
	{
		Sleep(fla);
		if (kt == 0)
			taothucan();
		yd++;
		ran.themdau(xd, yd);
		vedot(xd, yd);
		if (getvt(xd, yd) == 2)
		{
			cout << "\a";
			kt = 0;
			diem++;
			textcolor(colorht);
			gotoxy(68, 11);
			cout << diem;
		}
		else if (getvt(xd, yd) == 3)
		{
		    	showendgame();
		}
		else
		{
			xoadot(ran.getxc(), ran.getyc());
			ran.xoa();
		}
		truyen(xd, yd, 1);
	}

};
class dieukhien: public conran
{
private:
public:
	void menu()
    {
    system("cls");// system("cls") xoa du lieu cu
    gotoxy(38,4);
    textcolor(10);
	cout << "WELCOME TO SANKE GAME!\n";
	textcolor(6);
	gotoxy(22,6);
    cout << "*************************MENU**************************\n";
    gotoxy(22,7);
    cout << "**                  1. START GAME.                   **\n";
    gotoxy(22,8);
    cout << "**                  2. RULE.                         **\n";// luat
    gotoxy(22,9);
    cout << "**                  3. RECENT SCORES.                **\n";//diem so gan day
    gotoxy(22,10);
    cout << "**                  0. OUT GAME.                     **\n";
    gotoxy(22,11);
    cout << "*******************************************************\n";
    textcolor(6);
    gotoxy(22,14);
    cout << "Your choice: ";
	int option;
	cin >> option;
	if (option == 1)
	{
		Beep(440,500);
		game();
	}else if (option == 2)
	{
		Beep(440,500);
		system("cls");
		textcolor(3);
		cout << "\n\n\t\tDung 4 phim mui ten de dieu khien con ran, *dam dau zo tuong la chet\n "<< endl;
		cout << "\t\tBam 'p' de dung game va 'o' de thoat game \n"<< endl;
		cout << "\t\tBam enter de quay lai "<< endl;
		char enter ;
		while(1)
		{
			enter = getch();
			if(enter == 13)
				break;
		}
		menu();
    }else if (option == 3) 
	{
		Beep(440,500);
		system("cls");
		textcolor(3);
		cout << "\n\n\t\t   NGUOI MOI CHOI GAN DAY LA : \n "<< endl;//  
		//
		ifstream filein;
		filein.open("score.text",ios::in);
		char diem[60];
		filein.getline(diem,60);
        filein>>diem;
        gotoxy(35,5);
        cout<<diem<<endl;
		filein.close();
		//
		cout << "\n\t\t   NHAN 1 DE MUON TAT CA XOA DIEM GAN DAY VA QUAY LAI MENU  \n "<< endl;
		cout << "\t\t   NHAN 2 DE QUAY LAI MENU"<< endl;
		cout << "\n\n\t\t     Your choice: ";
		int n;
		cin>>n;
		if (n == 1)
	    {
	    	system("cls");
	    	ofstream fileout;
	        fileout.open("score.text",ios::out| ios::trunc );
	        fileout<<"";
	        fileout.close();
			menu();
	    }else if(n==2){
	    	menu();
		}
    }else if (option == 0) {
        exit(0);}
    }
    
    void startgame()
	{
		system("cls");
		menu();
		khoitaoran();
		while (1)
	{
		if (_kbhit() != 0) //xac dinh xem phim da nhan hay chua
		{
			int l = getch();
			switch (l)
			{
			case 72:
				while (_kbhit() == 0)
				{
					len();
				}
				break;
			case 80:
				while (_kbhit() == 0)
				{
					xuong();
				}
				break;
			case 75:
				while (_kbhit() == 0)
				{
					trai();
				}
				break;
			case 77:
				while (_kbhit() == 0)
				{
					phai();
				}
				break;
			case 112:  // nhan p de dung
				getch();
				break;	
			case 111:  // nhan o de thoat game ngay
				exit(0);
				break;		
			}
		}
	}
	}
	
};
//============================================
int main()
{
	resizeConsole(820,700); // chinh console
	ShowCur(0);
	dieukhien a;
	a.taokhung();
	a.startgame();
	
	getch();
	return 0;
}
