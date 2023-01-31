#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x,int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos={x,y};	
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);	
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void hidecursor(bool appear)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = !appear;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void fullscreen(){
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

