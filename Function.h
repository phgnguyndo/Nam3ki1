#include<cmath>
//#include "CapNhat.h"
#include "DSSV.h"
#include "SapXep.h"
#include "TimKiem.h"
#include "capNhat.h"
#include <cstdlib>
#include <ctime>
#define ESC 	27
#define ENTER	13
#define UP 		72
#define DOWN	80
#define LEFT	75

void drawFrame();
void KiemTra(int ngay,int thang,int nam){
	switch(thang){
			case 1: case 3: case 5: case 7: case 8: case 10:  case 12:
				if(ngay<0 || ngay>31) cin.setstate(ios_base::failbit);
				break;
			case 4: case 6: case 9: case 11:
				if(ngay<0||ngay>30) cin.setstate(ios_base::failbit);
				break;
			case 2:
				 if(nam % 400 == 0 || (nam % 4 == 0 && !(nam % 100 == 0 ))){   
				  if(ngay<0||ngay>29) cin.setstate(ios_base::failbit);
 	 			     break;
				}
				 else{
				 	if(ngay<0||ngay>28) cin.setstate(ios_base::failbit);
				 	    break;
			    }
			}		
}
float DiemTB(float toan,float li,float hoa){
	float dTB=(toan+li+hoa)/3;
	dTB=round(dTB * 10) / 10;
	return dTB;
}
string XepLoai(float toan,float li,float hoa){
	string xl;
	float tb=(toan+li+hoa)/3;
	if(tb>=8){
		xl="Gioi";
		return xl;
	}
	else if(tb>=7&&tb<8){
		xl="Kha";
		return xl;
	}
    else if(tb<7&&tb>=6){
		xl="TB";
		return xl;
	}
	else if(tb<6){
		xl="Yeu";
		return xl;
	}
}
void NhapThongTin(List &l,SV x){    	
     int num;
     Box("thin",3,45,47,1,11,false); 
	     gotoxy(50,2); 
		 TextColor(14); 		  
	     cout<<"Nhap so SV muon them vao DS: "; 

//		 if(getch()==ESC){
//	     	flag=0;
//	     	hidecursor(true);
//	     	Box("thin",5,60,47,1,0,true);
//	     	return;
//		 }
		 cin >> noskipws;
	     while(!cin.fail()){
	     	 cin>>num;
	     	 if(cin.fail()||num<1){
  	   		 cin.clear();
	     	cin.ignore();    	
	     	TextColor(4+8);
	     	gotoxy(88,2);
	     	cout<<"[!]";
			gotoxy(78,2);
			cout<<"        ";TextColor(14);gotoxy(78,2);
	     	continue;
	     	  }
	     	  
	     	  gotoxy(82,2);
	     	  cout<<"   ";  
	     	  break;
		 }
	     cin >> skipws;
	     bool tf=true;
	     int t=1;
	     
	 do{
     	Box("thin",28,45,47,4,11,true);
	    gotoxy(50,6);
	    int i,j;
		
		string array[10]{ 
		          "Ho va ten: ",
				  "Lop: ",
				  "Gioi Tinh: ",
				  "Que quan: ",
				  "Nam Sinh: ",
				  "Thang sinh: ",
				  "Ngay sinh: ",
				  "Diem Toan: ",
				  "Diem Ly: ",
				  "Diem Hoa: ",	  
						};
		for(i = 6, j = 0; j< 10 ; i+=2, j++){
			Box("thin", 2, 40-2,50+2, i, 0,true);
			gotoxy(52,i);
			TextColor(14);
			cout << array[j];				
			switch(j+1){
				case 1:
					fflush(stdin);
					getline(cin,x.HoTen);
					break;
				case 2:
					fflush(stdin);
					getline(cin,x.Lop);
					break;
				case 3:
					cin>>x.GioiTinh;
					break;
				case 4:
					fflush(stdin);
					getline(cin,x.Que);
					break;
				case 5:
					cin >>x.Nam;
					if(x.Nam<0) cin.setstate(ios_base::failbit);
					break;
				case 6:
					cin>>x.Thang;
					if(x.Thang>12||x.Thang<0) cin.setstate(ios_base::failbit);
					break;
				case 7:
					cin>>x.Ngay;
					if(x.Ngay > 31||x.Ngay<0) cin.setstate(ios_base::failbit);
					KiemTra(x.Ngay,x.Thang,x.Nam);		
					break;					
				case 8:
					cin >>x.Toan;
					if(x.Toan > 10||x.Toan<0) cin.setstate(ios_base::failbit);
					break;
				case 9:
					cin >> x.Li;
					if(x.Li > 10||x.Li<0) cin.setstate(ios_base::failbit);
					break;
				case 10:
					cin >>x.Hoa;
					if(x.Hoa> 10||x.Hoa<0) cin.setstate(ios_base::failbit);
					break;
			}
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				TextColor(4+8);
				gotoxy(49,i);
				cout << "[!]";
				
				i-=2;j--;
				continue;
			}else
				 {
			 	TextColor(0);
				gotoxy(49,i);
				cout << "[!]";
				 }
		}
		
		float tb=DiemTB(x.Toan,x.Li,x.Hoa);
		x.DTB=tb;
		string xl=XepLoai(x.Toan,x.Li,x.Hoa);
		x.XL=xl;
		string Ma="KQHSVK";
		x.MaSV=Ma;	
		srand(time(NULL));
	    x.MaSo= rand() % (9000 - 3 + 1) + 3;
	    

		Ghi_file(x);
		Box("thin",35,45,47,1,0,true);
        t++;
    
	 }while(tf&&t<=num&&t>0);
}  


void InDS(List l){
	drawFrame();
	
	TextColor(6);
	gotoxy(100,49);cout<<"[\21]: Trang truoc";
	gotoxy(120,49);cout<<"[\20]: Trang tiep";
	gotoxy(140,49);cout<<"ESC: Thoat";
    //----
    load_file(l);
    gotoxy(70,12);
    TextColor(11);
    TableOutput(l, 60, 10, l.first, 1);   
}



void TextSX(int focus,List &l){
	int y=8;
    string Arr[]={ "[1]: Sap xep theo DTB ",
	  	           "[2]: Sap xep theo anphaB",
	  	           "[3]: Sap xep theo ma so",
	  	           "[4]: Sap xep theo lop",
					};
					 
        for(int v=0;v<4;v++){
        	Highlight(v,focus,14,11);
        	gotoxy(48,y+=2);
        	cout<<Arr[v];
		}
		Khoa=focus;
		l.first=NULL;
}
void ChonThuatToan(List &l){
	Box("thin",9,35,82,9,11,false);
	int y=8,x=0;
	int index=1;
	string TT[]={
	     "[1]: QuickSort",
		 "[2]: BubleSort ",
		 "[3]: InsertSort ",
		 "[4]: SelectionSort", 
	};
do{
	for(int i=0;i<4;i++){
		Highlight(i,index,14,11);
		gotoxy(83,y+=2);
		cout<<TT[i];
	};
	y=8;	
	x= 0;
	x = getch();
	if (x==0 || x==0xE0) x=getch();
	if(x== DOWN){
			index++; 
			if(index == 5) index = 1;
			continue;
			}
    else if(x== UP){
			index--; 
			if(index == 0) index = 4;
			continue;
			}
	else if(x==ENTER){
		flag=1;
		break;
	} 			
	else if(x==ESC){
		Box("thin",40,100,82,8,0,true);
		flag=0;
		return ;	
	}
			
	else continue;
}while (1);
	ThuatToan=index;
	XapXep(l.first,l.last,l);
	Box("thin",45,136,47,4,0,true);
		    drawFrame();
		    TextColor(6);
    gotoxy(100,49);cout<<"[\21]: Trang truoc";
   	gotoxy(120,49);cout<<"[\20]: Trang tiep";
	gotoxy(140,49);cout<<"ESC: Thoat";
    TableOutput(l, 60, 10, l.first, 1);
	l.first=NULL;//in 1 lan xong xoa list de in lan tiep theo	    
}

void SapXepDS(List &l,int index){
	Box("thin",9,35,47,9,11,false);
    TextSX(index,l);
	int x;
	do{
		if(flag==0) return;
	x= 0;
	x = getch();
	if (x==0 || x==0xE0) x=getch();
	switch(x){
		case DOWN: 
			index++; 
			if(index == 5) index = 1;
			SapXepDS(l,index);	
			break;
       	case UP:
       		index--;
			if(index == 0) index = 4;
			SapXepDS(l,index);
			break;
		case ENTER: 
		    flag=1;
	        load_file(l);
		    ChonThuatToan(l);	    		    
            break;
		case ESC: 
		    flag = 0;
		    Box("thin",49,160,47,2,0,true);			
            return;        
		}
	}while (1);
}

void Thoat(){
	system("cls");
	exit(0);
}
	
void KhoaCapNhat(int focus,List &l){
	int y=5;
    string Arr[]={ "[1]: Them SV vao DS ",
	  	           "[2]: Sua SV trong DS",
	  	           "[3]: Xoa SV khoi DS"
					};
					 
        for(int v=0;v<3;v++){
        	Highlight(v,focus,14,11);
        	gotoxy(48,y+=2);
        	cout<<Arr[v];
		}
		Khoa=focus;
		l.first=NULL;
}

void BatDauCapNhat(List &l,SV x){
	switch(Khoa){
		case 1: {
			hidecursor(false);
			NhapThongTin(l,x);
			break;
		}
		case 2:{
			SuaSV(l);
			break;
		}
		case 3:{
			XoaSV(l);
			break;
		}
	}
}
	
void CapNhatDS(List &l,int index,SV a){
	hidecursor(true);
	Box("thin",7,35,47,6,11,false);
    KhoaCapNhat(index,l);
	int x;
	do{
		if(flag==0) return;
	x= 0;
	x = getch();
	if (x==0 || x==0xE0) x=getch();
	switch(x){
		case DOWN: 
			index++; 
			if(index == 4) index = 1;
			CapNhatDS(l,index,a);	
			break;
       	case UP:
       		index--;
			if(index == 0) index = 3;
			CapNhatDS(l,index,a);
			break;
		case ENTER: 
		    flag=1;
		    Box("thin",10,60,47,4,0,true);	
	        load_file(l);
	        BatDauCapNhat(l,a);    		    
            break;
		case ESC: 
		    flag = 0;
		    Box("thin",10,60,47,4,0,true);			
            return;        
		}
	}while (1);
}	

void SixFunction(List &l,int focus,SV x){
	switch(focus){
		case 1:
			CapNhatDS(l,1,x);
			break;
		case 2:
			hidecursor(true);
			InDS(l);
			Box("thin",49,136,60,4,0,true);
			return;
		case 3:
			hidecursor(true);
			SapXepDS(l,1);	
			flag=0;	
            Box("thin",49,150,47,4,0,true);	
			return;		
		case 4:
			TimKiem(l,1);
			break;
		case 5:
			hidecursor(true);
			ThongKe(l,1);
			break;
		case 6:
			hidecursor(true);
			Thoat();
			break;
		defaul :
			break;			
	}
}


