
#define ESC 	27
#define ENTER	13
#define UP 		72
#define DOWN	80
#define LEFT	75

#define tBL	'\xC0'
#define around '\x5E'
#define Doc '\xB3'
#define DocNho '\x7C'
#define Ngang '\xC4'
void Highlight(int line, int focus, int mcolor, int hcolor){
	if((line+1) == focus)
		TextColor(hcolor);
	else
		TextColor(mcolor);
}

void KhoaThongKe(int focus){
	int y=12;
    string KhoaTHK[]={ "[1]: Thong ke theo DTB",
	  	           "[2]: Thong ke theo hoc luc",
					};
					
        for(int v=0;v<2;v++){
        	Highlight(v,focus,14,11);
        	gotoxy(48,y+=2);
        	cout<<KhoaTHK[v];
		}
		Khoa=focus;	
}
void draw(){
	
	   int y=8;
       int x=76;
       int k=77,h=77,g=77,l=77,m=77;
       gotoxy(95,5);TextColor(6);
       cout<<"H1.1: Bieu do thong ke ket qua hoc tap hoc vien dai doi 156";
       
    for(int t=0;t<99;t++){
	    gotoxy(m++,9);TextColor(8);cout<<Ngang;
        gotoxy(k++,15);TextColor(8);cout<<Ngang;
        gotoxy(h++,21);TextColor(8);cout<<Ngang;
       	gotoxy(g++,27);TextColor(8);cout<<Ngang;	
    	gotoxy(l++,33);TextColor(8);cout<<Ngang;    	   	
	}
	for(int i=0;i<31;i++){
		gotoxy(75,y++);TextColor(14);cout<<Doc;		
	}
	for(int i=0;i<100;i++){
		gotoxy(x++,39);TextColor(14);cout<<Ngang;
	}
	gotoxy(75,39); cout<<tBL;
	gotoxy(95,41);TextColor(10);cout<<"Yeu";
	gotoxy(72,33);TextColor(10);cout<<"20%";
	gotoxy(112,41);TextColor(10);cout<<"Trung Binh";
	gotoxy(72,27);TextColor(10);cout<<"40%";
	gotoxy(135,41);TextColor(10);cout<<"Kha";
	gotoxy(72,21);TextColor(10);cout<<"60%";
	gotoxy(155,41);TextColor(10);cout<<"Gioi";
	gotoxy(72,15);TextColor(10);cout<<"80%";
	gotoxy(71,9);TextColor(10);cout<<"100%";
}

void ThucHienThongKe(List &l){
 draw();
      load_file(l);
      int gioi=0,kha=0,trungBinh=0,yeu=0,tongSo=0;
	for(Node* k=l.first;k!=NULL;k=k->next){
		if(k->data.DTB>=8) gioi++;
		if(k->data.DTB>=7 && k->data.DTB<8) kha++;
		if(k->data.DTB>=6 && k->data.DTB<7) trungBinh++;
		if(k->data.DTB<6) yeu++;
		tongSo++;
	}
	 float tiLeGioi=((float)gioi/(float)tongSo);
	 float tiLeKha=((float)kha/(float)tongSo);
     float tiLeTB=((float)trungBinh/(float)tongSo);
	 float tiLeYeu=((float)yeu/(float)tongSo);
		 
//	Box("thin",tiLeYeu,3,95,29-tiLeYeu+11,102,true);

    int a=chartbar(95,39,tiLeYeu,3,20,6);
	gotoxy(92,38);TextColor(6);cout<<yeu;
	

//	Box("thin",tiLeTB,3,115,40-tiLeTB,119,true);
    int b=chartbar(115,39,tiLeTB,3,20,7);
    gotoxy(111,38);TextColor(7);cout<<trungBinh;
	
	
//	Box("thin",tiLeKha,3,135,40-tiLeKha,204,true);
        int c=chartbar(135,39,tiLeKha,3,20,12);
	gotoxy(132,38);TextColor(12);cout<<kha;
	
//	Box("thin",tiLeGioi,3,155,40-tiLeGioi,153,true);
    int d=chartbar(155,39,tiLeGioi,3,20,9);
	gotoxy(152,38);TextColor(9);cout<<gioi;
	l.first=NULL;
				hidecursor(true);
				
				return;	
}


void ThongKe(List &l,int index){
	Box("thin",6,35,47,13,11,false);
    KhoaThongKe(index);
	int x;
	do{
		if(flag==0) return;
		x= 0;
		x = getch();
		if (x==0 || x==0xE0) x=getch();
		switch(x){
			case DOWN: 
				index++; 
				if(index == 3) index = 1;
				ThongKe(l,index);	
				break;
	       	case UP:
	       		index--;
				if(index == 0) index = 2;
				ThongKe(l,index);
				break;
			case ENTER:
			     flag=1; 
                 Box("thin",40,50,47,8,0,true);
			     ThucHienThongKe(l);		     
			     break;
			case ESC: 
		     	flag = 0;
			   Box("thin",45,150,47,4,0,true);		   
	   		   break;
		}
	}while (1);
}
