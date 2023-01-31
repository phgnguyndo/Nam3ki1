#include <iomanip>
#define TB  '\xCD' // 205
#define LR  '\xBA' // 186
#define TL  '\xC9' // 201
#define TR  '\xBB' // 187
#define BL  '\xC8' // 200
#define BM	'\xCA'
#define TM	'\xCB'
#define ML	'\xCC'
#define MR	'\xB9'

#define tTR	'\xBF'
#define tBL	'\xC0'
#define tBR '\xD9'
#define tML '\xCC'
#define tMR '\xB9'
#define tCEN '\xC5'
#define tBM '\xC1'
#define tTM '\xC2'
#define BR  '\xBC' // 188 
#define BoxF  '\xDB' // 188
#define BoxL  '\xDC'
#define BoxU  '\xDF'
#define BoxLH char(257+220)
#define BoxRH char(257+221)
#define F1	'\xB0'
#define F2	'\xB1'
#define F3	'\xB2'
using namespace std;

void Box(string type, int dai, int rong, int x, int y, float ncolor, bool fill);
int chartbar(int x, int y, float percent ,int w, int delay , int color);

void Box(string type, int dai, int rong, int x, int y, int ncolor, bool fill){
	char BotL, BotR, TopL, TopR, ColR, ColL, LineT, LineB;
//	if(type =="thick" ){
//			BotL = BotR = TopL = TopR = ColR = ColL = BoxF;
//			LineT = BoxU;
//			LineB = BoxL;
//	}
 if(type =="thin" ){
			BotL= '\xC0';TopR='\xBF';
			LineT=LineB='\xC4';
			ColR=ColL='\xB3';
			TopL='\xDA';BotR='\xD9';
		}
	else if(type == "double"){
			BotL= BL;TopR=TR;
			LineT=LineB=TB;
			ColR=ColL=LR;
			TopL=TL;BotR=BR;
	} else {
			BotL = BotR = TopL = TopR = ColR = ColL = LineT = LineB = ' ';
	}
	
			
	 gotoxy(x,y);
	 TextColor(ncolor);
	 std::cout << TopL << std::setfill(char(LineT)) << std::setw(rong-1)  <<TopR<< std::endl;
	 for(int i =0; i < dai-2; i++)
	{
		gotoxy(x,y+1+i);
		std::cout <<ColL;
		if(fill) cout << std::setfill(' ') << std::setw(rong-1) ;
		else gotoxy(x+rong-1,y+1+i); 
		cout<<ColR;

	}
		gotoxy(x,y+dai-1);
	 	std::cout << BotL  << std::setfill(char(LineB)) << std::setw(rong-1) << BotR<< std::endl;
	 	TextColor(11);
		gotoxy(0,0);
}
int chartbar(int x, int y, float percent ,int w, int delay , int color){
	const int maxh = 29;
	float h = percent * maxh;
	int rh = (int(h/(maxh/10)) * (maxh/10));
	TextColor(color);
	gotoxy(x,y);
	for(int j = 0; j < w; j++){
			cout <<BoxU;
		}
	y--;
	for(int i = 0; i < int(rh-1); i++){
		gotoxy(x,y);
		for(int j = 0; j < w; j++){
			cout <<BoxL;
		}
		Sleep(delay/2);
		gotoxy(x,y);
		for(int j = 0; j < w; j++){
			cout <<BoxF;
		}
		y--;
		Sleep(delay/2);
	}
	int t = ((h - rh)/30)*1000;
	int temp[4] = {0,0,0,0};
	if(t <5){
	temp[0] = BoxL;
	}
	else if(t > 5 && t <=20)
	{
	temp[0] = BoxF;
	}
	else if(t > 20 && t <=45)
	{
	temp[0] = BoxF;
	temp[1] = BoxL;
	}
	else if(t > 45 && t <=55)
	{
	temp[0] = temp[1] = BoxF;
	}
	else if(t > 55 && t <=70)
	{
	temp[0] = temp[1] = BoxF;
	temp[2] = BoxL;
	}
	else if(t > 70 && t <=95)
	{
	temp[0] = temp[1] = temp[2] = BoxF;
	}
	else if(t > 95)
	{
	temp[0] = temp[1] = temp[2] = BoxF;
	temp[3] = BoxL; 
	}
	for(int i = 0; temp[i] != 0; i++, y--){
		gotoxy(x,y);
		for(int j = 0; j < w; j++)
				cout << char(temp[i]);
	}
	TextColor(7);
	return y;
}


