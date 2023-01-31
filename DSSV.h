#include<fstream>
#include<string.h>

struct SV{
	string MaSV, HoTen, GioiTinh,Lop,Que,XL;
	int Ngay, Thang, Nam,MaSo;
	float Toan,Li,Hoa,DTB;	
};

struct Node{
	SV data;
	Node *next;
};

struct List{
	Node *first;
	Node *last;
};

void KhoiTaoDS(List &l){
	l.first=NULL;
	l.last=NULL;
}

Node* KhoiTaoNode(SV x){
	Node *p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
}
void ThemVaoDau(List &l,SV x){
	Node *p=KhoiTaoNode(x);
	if(l.first==NULL)
	   l.first=l.last=p;
    else{
    	p->next=l.first;
    	l.first=p;
	}
}
void ThemVaoCuoi(List &l, SV x){
	Node *p=KhoiTaoNode(x);
	if(l.first==NULL)
	   l.first=l.last=p;
    else
       {
       	l.last->next=p;
        l.last=p;
	   }
}
static int flag = 1;
void XoaNodeDau(List &l){
	Node *temp=l.first;
	if(l.first==NULL)
	   cout<<"khong co gi de xoa";
	else{
		temp=temp->next;
		l.first=temp;
	}
}
void XoaNodeCuoi(List &l){
	Node *temp=l.first;
	if(l.first==NULL){
		cout<<"Khong co gi de xoa";
	}	   
	else{		
	   	while(temp->next->next!=NULL){
		     temp=temp->next;
		   }
		   temp->next=NULL;
	   }
}
void XoaViTriBatKi(List &l, int pos){
	Node *temp=l.first;
	    if(temp->next==NULL){
	        XoaNodeDau(l);
	        return;
			}
	    if(pos==1){
	    	 XoaNodeDau(l);
	    	 return;
		}
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp->next==NULL){
			 cout<<"Vi tri xoa k hop le!";
				return;
			}			
		}
		temp->next=temp->next->next;
	}

void Xuat(Node* k, int y, int stt){	
	gotoxy(64,y);  cout<<left << setw(4) << setfill(' ')<<stt;
	gotoxy(71,y);	cout<<k->data.MaSV<< setw(4)<<k->data.MaSo;
	gotoxy(87,y);	cout<< setw(25)<<k->data.HoTen;
	gotoxy(116,y);	cout<<setw(3)<< setfill(' ')<<k->data.GioiTinh;
	gotoxy(130,y);	cout<< k->data.Ngay<<"/"<<k->data.Thang<<"/"<< setw(6)<<k->data.Nam;
	gotoxy(148,y);	cout<< setw(20)<< setfill(' ')<<k->data.Que;
	gotoxy(172,y);	cout<<setw(3)<<k->data.DTB;
	gotoxy(186,y);	cout<< setw(4)<<k->data.XL; cout << right;
}

void TableOutput(List l, int x, int y, Node* begin,int num){
	TextColor(11);
	Node *end, *temp;
	int tempy,i;
	int key, nextnum;
	do{
		if(flag == 0){
			return;
		}
	temp = begin;
	tempy = y;
	i = 18;
	nextnum = num;
	for(; i> 0; i-- ,tempy+=2, nextnum++){
		if(temp == NULL){			
		Box("empty", 2, 130, x+2,tempy,0,true);
	}else{
		Xuat(temp, tempy, nextnum);
	//	temp->HV.TableOutp( x, tempy, nextnum);
		temp = temp->next;
		}	
	}
	end = temp;
	do{
	key = getch();
	if (key==0 || key==224) key=getch();
	if(key == 75){
		if(num ==1)
		continue;
		return;
		}
    if(key == 77){
   		if(end == NULL)
   			continue;
       	TableOutput(l, x, y, end,nextnum);
		break;
	}
	if(key == 13)
       	break;
	if(key == 27) {
		flag=0;
		return;
		break;
	}
	}while(1);
	}while(1);
}
void Ghi_Lai_File(List &l){	
     ofstream outfile;
     outfile.open("DSSV.txt",ios::out);
	 Node *h=l.first;
	        outfile<<h->data.HoTen<<"/";	
	        outfile<<h->data.MaSV<<"/";
			outfile<<h->data.MaSo<<"/";
			outfile<<h->data.GioiTinh<<"/";
			outfile<<h->data.Que<<"/";
			outfile<<h->data.Lop<<"/";
			outfile<<h->data.Ngay<<",";
			outfile<<h->data.Thang<<",";
			outfile<<h->data.Nam<<",";
			outfile<<h->data.Toan<<",";
			outfile<<h->data.Li<<",";
			outfile<<h->data.Hoa<<",";
			outfile<<h->data.DTB<<",";
			outfile<<h->data.XL<<endl; 
		for(Node *k=l.first->next;k!=NULL;k=k->next){
			outfile<<" "<<k->data.HoTen<<"/";
			outfile<<k->data.MaSV<<"/";
			outfile<<k->data.MaSo<<"/";
			outfile<<k->data.GioiTinh<<"/";
			outfile<<k->data.Que<<"/";
			outfile<<k->data.Lop<<"/";
			outfile<<k->data.Ngay<<",";
			outfile<<k->data.Thang<<",";
			outfile<<k->data.Nam<<",";
			outfile<<k->data.Toan<<",";
			outfile<<k->data.Li<<",";
			outfile<<k->data.Hoa<<",";
			outfile<<k->data.DTB<<",";
			outfile<<k->data.XL<<endl; 
		}
	  
	outfile.close();
	l.first=NULL;
}

void Ghi_file(SV x){
     ofstream outfile;
     outfile.open("DSSV.txt", ios::app);	
		outfile<<" "<<x.HoTen<<"/";
		outfile<<x.MaSV<<"/";
		outfile<<x.MaSo<<"/";
		outfile<<x.GioiTinh<<"/";
		outfile<<x.Que<<"/";
		outfile<<x.Lop<<"/";
		outfile<<x.Ngay<<",";
		outfile<<x.Thang<<",";
		outfile<<x.Nam<<",";
		outfile<<x.Toan<<",";
		outfile<<x.Li<<",";
		outfile<<x.Hoa<<",";
		outfile<<x.DTB<<",";
		outfile<<x.XL<<endl; 
	  
	outfile.close();
}
void load_file(List &l){
	ifstream filein;
	filein.open("DSSV.txt",ios::in);//doc file
	SV x;
	int STT;
	while(filein.eof()==false){	
	getline(filein,x.HoTen,'/');
	getline(filein,x.MaSV,'/');
	//getline(filein,x.MaSo,'/');
	filein>>x.MaSo;
	filein.ignore();
	getline(filein,x.GioiTinh,'/');
	getline(filein,x.Que,'/');
	getline(filein,x.Lop,'/');
	
	filein>>x.Ngay;
	filein.ignore();
	filein>>x.Thang;
	filein.ignore();
	filein>>x.Nam;
	filein.ignore();
	filein>>x.Toan;
	filein.ignore(); //bo qua ,
	filein>>x.Li;
	filein.ignore();
	filein>>x.Hoa;
	filein.ignore();
	filein>>x.DTB;
	filein.ignore();
	getline(filein,x.XL);
	filein.ignore();
    
	//---them
	ThemVaoCuoi(l,x);
	}
	//-----
	filein.close();
}

