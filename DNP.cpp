#include <iostream>
#include <windows.h>
#include <conio.h>
#include "DiChuyen.h" //gotoxy(x,y); TextColor(color)
#include "VeKhung.h"
#include "Function.h"
#define normalColor  13  			
#define focusColor	 112			
#define UP 		72
#define DOWN	80
#define ENTER	13 
#define ESC 	27

using namespace std;



void Line(){
	string line = "__________________________________________\n";
		cout << line << endl;
}

void TextMenu(int focus){
	int OpNum=6;
	int i=1;
	gotoxy(2,i++);
	TextColor(14);	
	cout <<         "__________________________________________"    << endl;
	gotoxy(2,i++);
	cout << 		"             DO NGUYEN PHUONG" 				    <<endl;
	gotoxy(2,i++);
	cout <<  		"       Lop Bao Dam An Toan Thong Tin" 				<<endl;		
	gotoxy(2,i++);																																															
	cout <<   	    "_________________[MENU]___________________"    << endl;
	gotoxy(2,i++);
	
	string 
	Options[OpNum]={"    [1]: Cap nhat danh sach              ",
				  	"    [2]: In danh sach                    ",
					"    [3]: Sap xep danh sach               ",
					"    [4]: Tim kiem                        ",
					"    [5]: Thong ke                        ",
					"    [6]: Thoat                           ",};
	cout << endl;  
	int j,t;
	char arrow = ' ';
	for(j=0,t=0; j<OpNum; j++,t+=2){
		gotoxy(3,6+t);
		Highlight(j,focus,14,11);
		if(j+1 == focus) arrow = '\xAF'; else arrow = ' ';
		cout<<  Options[j] << arrow << endl;
	}
	i=t+6;
	TextColor(14);	
	gotoxy(2,i++);
	Line();
	gotoxy(2,i++);
	cout <<"    [\x18]: Up        [Enter]: Select"<< endl;
	gotoxy(2,i++);
	cout <<"    [\x19]: Down      [Esc]  : Thoat"<< endl;
	gotoxy(2,i++);
	Line();
	gotoxy(0,0);
}

void Menu(List &l,int focus,SV a){
	hidecursor(true);
	int x;
	TextMenu(focus);
	do{
	x= 0;
	x = getch();
	if (x==0 || x==0xE0) x=getch();
	switch(x){
		case DOWN: 
			focus++; 
			if(focus == 7) focus = 1;
			Menu(l,focus,a);
			break;
       	case UP:
       		focus--;
			if(focus == 0) focus = 6;
			Menu(l,focus,a);
			break;
		case ENTER: 
	        flag =1;
			SixFunction(l,focus,a);
			break;
		case ESC: 
			system("cls");
			exit(0);
		}
	}while (1);
}

int main(){
	List l;
	List New;
	KhoiTaoDS(New);
	SV x;
	KhoiTaoDS(l);
    fullscreen();
	Box("double",32,46,0,0,11,false);
	Box("double",54,165,46,0,11,false);
	Menu(l,1,x);
	return 1;
}
