
#include<string.h>
#include "ThongKe.h"
#define ESC 	27
#define ENTER	13
#define UP 		72
#define DOWN	80
#define LEFT	75


void drawFrame(){
	int x=65,y=6;
	flag = 1;
	Box("double",5,136,60,4,8,false);
	TextColor(14);
    gotoxy(x-2,y);cout<<"STT";
    gotoxy(x+10,y);cout<<"MaSV";
    gotoxy(x+26,y);cout<<"Ho va ten";
    gotoxy(x+48,y);cout<<"Gioi tinh";
    gotoxy(x+65,y);cout<<"Ngay sinh";
    gotoxy(x+86,y);cout<<"Que quan";
    gotoxy(x+106,y);cout<<"DTB";
    gotoxy(x+118,y);cout<<"Xep loai";
    Box("double",40,136,60,8,8,false);
    gotoxy(195,8);TextColor(8);cout<<tMR;
    gotoxy(60,8);TextColor(8);cout<<tML;
    //----
}
void VeKhungSua(){
	hidecursor(true);
	int x=65,y=5;
	flag = 1;
	Box("double",4,136,60,4,8,false);
	TextColor(14);
    gotoxy(x-2,y);cout<<"STT";
    gotoxy(x+10,y);cout<<"MaSV";
    gotoxy(x+26,y);cout<<"Ho va ten";
    gotoxy(x+48,y);cout<<"Gioi tinh";
    gotoxy(x+65,y);cout<<"Ngay sinh";
    gotoxy(x+86,y);cout<<"Que quan";
    gotoxy(x+106,y);cout<<"DTB";
    gotoxy(x+118,y);cout<<"Xep loai";
    Box("double",5,136,60,7,8,false);
    gotoxy(195,7);TextColor(8);cout<<tMR;
    gotoxy(60,7);TextColor(8);cout<<tML;
}
int NhapMaTK(){
	int Ma;
	hidecursor(false);
	Box("thin",5,60,95,12,14,false);
	gotoxy(97,13);
	cout<<"Nhap ma so SV: ";
	//cin>>Ma;
	while(!cin.fail()){
	     	 cin>>Ma;
	     	 if(cin.fail()){
  	   		 cin.clear();
	     	cin.ignore();    	
	     	TextColor(4+8);
	     	gotoxy(150,13);
	     	cout<<"[!]";
			gotoxy(112,13);
			cout<<"                   ";TextColor(6);gotoxy(115,13);
	     	continue;
	     	  }
	     	  
	     	  gotoxy(82,2);
	     	  cout<<"   ";  
	     	  break;
		 }
		 hidecursor(true);
	return Ma;
}
string NhapTenTK(){
//	hidecursor(false);
	string Ten;
	Box("thin",5,60,95,12,14,false);
	gotoxy(97,13);
	cout<<"Nhap ten SV: ";
	fflush(stdin);
	getline(cin,Ten);
	return Ten;
}
string NhapLopTK(){
	string Ten;
	Box("thin",5,60,95,12,14,false);
	gotoxy(97,13);
	cout<<"Nhap lop SV: ";
	fflush(stdin);
	getline(cin,Ten);
	return Ten;
}
bool KhopTen(string name1, string name2){
	stringstream ss1(name1);
	stringstream ss2(name2);
	string n1[5];
	string n2[5];
	int i=0, j=0;
	while (ss1 >> n1[i]) 
        i++;
    while (ss2 >> n2[j]) 
    	j++;
    int x = 0;
    while(x==0&&i>=0&&j>=0){
    	if(j==0||i==0)
    	i=j=0;
    	x = _stricmp(n1[i].c_str(), n2[j].c_str());
    	i--;j--;
		}
	if(x==0)
	return 1;
	else return 0;    
}
void KhopDuLieu(List l){
	int maso;
	string Ten,Lop;
	List n;
	KhoiTaoDS(n);
	SV x;
	switch(Khoa){
		case 1:
		    maso=NhapMaTK();
		    for(Node *k=l.first;k!=NULL;k=k->next){
					if(k->data.MaSo==maso){
						x=k->data;
						ThemVaoCuoi(n,x);				        
					}
	         }          
	                    hidecursor(true);
	                    Box("thin",49,150,47,3,0,true);
	                    drawFrame();	
				        TableOutput(n, 60, 10, n.first, 1);	 
						flag=0; 
						Box("thin",50,150,47,3,0,true);	
	         break;
		
		case 2:
			Ten=NhapTenTK();
			for(Node *k=l.first;k!=NULL;k=k->next){
				if(KhopTen(k->data.HoTen,Ten)){
					x=k->data;
					ThemVaoCuoi(n,x);										
				}				
	        }       hidecursor(true);
	                Box("thin",49,150,47,3,0,true);
	                drawFrame();	
			        TableOutput(n, 60, 10, n.first, 1);
			        flag=0;
			        Box("thin",50,150,47,3,0,true);	
		break;
		
		case 3:
			Lop=NhapLopTK();
			for(Node *k=l.first;k!=NULL;k=k->next){
				if(KhopTen(k->data.Lop,Lop)){
					x=k->data;
					ThemVaoCuoi(n,x);										
				}				
	        }       hidecursor(true);
	                Box("thin",49,150,47,3,0,true);
	                drawFrame();	
			        TableOutput(n, 60, 10, n.first, 1);
			        flag=0;
			        Box("thin",50,150,47,3,0,true);	
		break;
	}
}
void TimKiemTuanTu(List &l){
	Box("thin",12,150,47,8,0,true);	
	load_file(l);
	KhopDuLieu(l);
}

void BatDauTK(List &l){
	switch(ThuatToan){
		case 1:TimKiemTuanTu(l);
		       break;
		case 2:TimKiemTuanTu(l);
		       break;      		       
	}
}
void ChonThuatToanTK(List &l){
	Box("thin",6,35,82,11,14,false);
	int y=10,x=0;
	int index=1;
	string TT[]={
	     "[1]: Tim kiem tuan tu",
		 "[2]: Tim kiem nhi phan ",
	};
do{ 
//    if(flag==0){
//    	hidecursor(true);
//    	Box("thin",10,50,47,10,0,true);		
//        return;
//	}
	for(int i=0;i<2;i++){
		Highlight(i,index,14,11);
		gotoxy(83,y+=2);
		cout<<TT[i];
	};
	y=10;	
	x= 0;
	x = getch();
	if (x==0 || x==0xE0) x=getch();
	if(x== DOWN){
			index++; 
			if(index == 3) index = 1;
			continue;
			}
    else if(x== UP){
			index--; 
			if(index == 0) index = 2;
			continue;
			}
	else if(x==ENTER){
		flag=1;	
		break;
	}
	else if(x==ESC){
		flag=0;
		hidecursor(true);
		Box("thin",10,100,47,10,0,true);		
		return ;
	}			
	else continue;
}while (1);
	ThuatToan=index;
	BatDauTK(l);	
	l.first=NULL;
}

void KhoaTimKiem(int focus){
	int y=10;
    string Arr[]={ "[1]: Tim kiem theo ma SV",
	  	           "[2]: Tim kiem theo ten",
	  	           "[3]: Tim kiem theo lop",
					};
					
        for(int v=0;v<3;v++){
        	Highlight(v,focus,14,11);
        	gotoxy(48,y+=2);
        	cout<<Arr[v];
		}
		Khoa=focus;		
}

void TimKiem(List &l,int index){
	Box("thin",8,35,47,11,11,false);
    KhoaTimKiem(index);
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
				TimKiem(l,index);	
				break;
	       	case UP:
	       		index--;
				if(index == 0) index = 3;
				TimKiem(l,index);
				break;
			case ENTER:
			     flag=1; 
			     ChonThuatToanTK(l);			     
			     break;
			case ESC: 
		     	flag = 0;
		     	hidecursor(true);
			   Box("thin",40,100,47,8,0,true);		   
	   		   break;
		}
	}while (1);
}
