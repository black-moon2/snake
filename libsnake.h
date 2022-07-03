#pragma once// tranh xung dot thu vien khi chong file len nhau
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thu vien ho tro ve thoi gian thuc */ 

/*các hàm lam game có san copy tren mang*/
//=========Làm mat cai nhay an hien=======
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
// khoi tao kich thuc window hien ra
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
//===========ham doi mau chu========
void textcolor(int x) 
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
//==========ham dich chuyen con tro=========
void gotoxy(int x, int y) 
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}













