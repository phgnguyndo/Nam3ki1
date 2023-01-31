#define ngangKep	'\xCD'

void XoaSV(List &l){
	int i=0;
	int maSo=NhapMaTK();
	Box("thin",5,60,95,12,0,true);
	for(Node *k=l.first;k!=NULL;k=k->next){
		         i++;
					if(k->data.MaSo==maSo){
						XoaViTriBatKi(l,i);	
						Ghi_Lai_File(l);
							flag=0;
							gotoxy(80,10);cout<<"XOA THANH CONG";
							getch();
							Box("thin",1,30,80,10,0,true);
							return;			        
					}
//					else{
//						    flag=0;
//							gotoxy(80,10);cout<<"KHONG TIM THAY";
//							getch();
//							Box("thin",1,30,80,10,0,true);
//							return;			        
//					}
	         }	         
	          	
}
void InRa(List l){
	Node *k=l.first;
	int i=1;
	TextColor(11);
	int y=9,x=65;
	gotoxy(x-1,y);cout<<i;
    gotoxy(x+7,y);cout<<k->data.MaSV<<k->data.MaSo;
    gotoxy(x+24,y);cout<<k->data.HoTen;
    gotoxy(x+51,y);cout<<k->data.GioiTinh;
    gotoxy(x+65,y);cout<<k->data.Ngay<<"/"<<k->data.Thang<<"/"<<k->data.Nam;
    gotoxy(x+86,y);cout<<k->data.Que;
    gotoxy(x+106,y);cout<<k->data.DTB;
    gotoxy(x+120,y);cout<<k->data.XL;
}


void NoiDungSua(List &l){
	Box("thin",14,35,105,14,11,false);
	int y=13,x=0;
	int index=1;
	string TT[]={
	     "[1]: Sua ho va ten",
		 "[2]: Sua gioi tinh ",
		 "[3]: Sua que quan ",
		 "[4]: Sua ngay sinh ",
		 "[5]: Sua thang sinh ",
		 "[6]: Sua nam sinh ",
	};
do{ 
	for(int i=0;i<6;i++){
		Highlight(i,index,14,11);
		gotoxy(107,y+=2);
		cout<<TT[i];
	};
	y=13;	
	x= 0;
	x = getch();
	if (x==0 || x==0xE0) x=getch();
	if(x== DOWN){
			index++; 
			if(index == 7) index = 1;
			continue;
			}
    else if(x== UP){
			index--; 
			if(index == 0) index = 6;
			continue;
			}
	else if(x==ENTER){
		flag=1;	
		break;
	}
	else if(x==ESC){
		flag=0;
		hidecursor(true);
		Box("thin",14,35,105,14,0,true);		
		return ;
	}			
	else continue;
}while (1);
	Khoa=index;

}



void SuaSV(List &l){
	List m;
	KhoiTaoDS(m);
	SV x;
    hidecursor(true);
	int ma=NhapMaTK();
	Box("thin",5,60,95,12,0,true);
		int t=62;
	for(Node *k=l.first;k!=NULL;k=k->next){
		if(k->data.MaSo==ma){
		    x=k->data;
			ThemVaoCuoi(m,x);
			VeKhungSua();
			InRa(m);
			NoiDungSua(l);
		switch(Khoa){
				case 1:{
					Box("thin",14,35,105,14,0,true);
					string tenMoi;
					Box("thin",3,50,100,12,11,false);
					TextColor(14);
					gotoxy(102,13);cout<<"Nhap ho ten moi: ";
					fflush(stdin);
					getline(cin,tenMoi);
					k->data.HoTen=tenMoi;
					Ghi_Lai_File(l);									    
					Box("thin",30,146,50,4,0,true);	
					flag=0;
					return;					
				
				}
				case 2:{
					Box("thin",14,35,105,14,0,true);
					string GTmoi;
					Box("thin",3,50,100,12,11,false);
					TextColor(14);
					gotoxy(102,13);cout<<"Nhap gioi tinh: ";
					fflush(stdin);
					getline(cin,GTmoi);
					k->data.GioiTinh=GTmoi;
					Ghi_Lai_File(l);									    
					Box("thin",30,146,50,4,0,true);	
					flag=0;
					return;						
				}
				case 3:{
					Box("thin",14,35,105,14,0,true);
					string queMoi;
					Box("thin",3,50,100,12,11,false);
					TextColor(14);
					gotoxy(102,13);cout<<"Nhap que: ";
					fflush(stdin);
					getline(cin,queMoi);
					k->data.Que=queMoi;
					Ghi_Lai_File(l);									    
					Box("thin",30,146,50,4,0,true);	
					flag=0;
					return;	
				}
				case 4:{
					Box("thin",14,35,105,14,0,true);
					int ngaySinh;
					Box("thin",3,50,100,12,11,false);
					TextColor(14);
					gotoxy(102,13);cout<<"Nhap ngay sinh: ";
					fflush(stdin);
					cin>>ngaySinh;
					k->data.Ngay=ngaySinh;
					Ghi_Lai_File(l);									    
					Box("thin",30,146,50,4,0,true);	
					flag=0;
					return;	
				}
				case 5:{
					Box("thin",14,35,105,14,0,true);
					int thangSinh;
					Box("thin",3,50,100,12,11,false);
					TextColor(14);
					gotoxy(102,13);cout<<"Nhap thang sinh: ";
					fflush(stdin);
					cin>>thangSinh;
					k->data.Thang=thangSinh;
					Ghi_Lai_File(l);									    
					Box("thin",30,146,50,4,0,true);	
					flag=0;
					return;	
				}
				case 6:{
					Box("thin",14,35,105,14,0,true);
					int namSinh;
					Box("thin",3,50,100,12,11,false);
					TextColor(14);
					gotoxy(102,13);cout<<"Nhap nam sinh: ";
					fflush(stdin);
					cin>>namSinh;
					k->data.Nam=namSinh;
					Ghi_Lai_File(l);									    
					Box("thin",30,146,50,4,0,true);	
					flag=0;
					return;	
				}
		}
//			getch();				    
//			Box("thin",8,146,50,4,0,true);	
//			flag=0;
//			return;
		}
//		else{
//			gotoxy(80,9);
//			cout<<"KHONG TIM THAY!";
//			flag=0;
//			getch();
//			Box("thin",15,60,47,4,0,true);	
//			return;		
//		}
	}
	        
}


