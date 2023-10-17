#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define colorr(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
int xa,xb,ya,yb;
long long last;
int f,mode,mode2,mode3;
int d[61][61]= {0};
int ra=0,rb=0;
int hang=0;
int lie=0;
int br;
int co1=0;
int co2=0;
int cok=0;
int coq=0;
int col=0;
int sp;
string start[5]= {{"1.Start"},{"2.Set"},{"3.About"},{"4.Acknowledgement"},{"5.Exit"}};
string thanks[10]= {{"Rainforests"},{"YPPAH"},{"KID2695"},{"秦屎皇"},{"Boranhoushen10"},{"ben090302"},{"66_66"},{"xiaofeng_and_xiaoyu"},{"G__G"},{"You"}};
string sett[6]= {{"1.Theme"},{"2.Brightness"},{"3.Time"},{"4.Speed"},{"5.Mode"},{"6.Size"}};
int movx[25]= {-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
int movy[25]= {-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};

void init() {
	sp=1;
	mode=1;
	mode2=mode3=0;
	last=1000;
	br=8;
	xa=2;
	xb=2;
	ya=2;
	yb=41;
	co1=2+8;
	co2=1+8;
	cok=8+8;
	coq=7+8;
	col=4+8;

}

void HideCursor() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}
void gotoxy(int x,int y) {
	COORD pos= {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}
void ccpp(const char* s, int color) { //COLORFUL_PRINT彩色输出 函数
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	colorr(color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
void cp(char s, int color) { //COLORFUL_PRINT彩色输出 函数
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	colorr(color);
	cout<<s;
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
void ccp(string ss,int color) {
	for(int i=0; i<ss.length(); i++) {
		cp(ss[i],color);
	}
}
void print(string s,int t) {
	for(int i=0; i<s.length(); i++) {
		cout<<s[i];
		Sleep(t);
	}
}

void nineprint(int y,int x,int wx,int wy) {
	for(int k=0; k<25; k++) {
		int jj=x+movx[k],ii=y+movy[k]*2;
		gotoxy(ii,jj);
		int i=wx+movx[k],j=wy+movy[k];
		if(i>=1&&i<=hang&&j>=1&&j<=lie) {
			if(i==xa&&j==ya) {
				ccpp("█",co1);
			} else if(i==xb&&j==yb) {
				ccpp("█",co2);
			} else if(i==1||i==hang) {
				ccpp("▓",coq);
			} else if(j==1||j==lie) {
				ccpp("▓",coq);
			} else if(d[i][j]==1&&mode2==0) ccpp("▓",coq);
			else if(d[i][j]==2&&mode==1) {
				ccpp("█",col);
			} else ccpp("█",cok);
		}

	}
}

void theme() {
	system("CLS");
	cout<<"Theme"<<endl;
	cout<<"1.Dark(Dark machine, cool!)"<<endl;
	cout<<"2.Old(At that time...)"<<endl;
	cout<<"3.Green(comfortable!)"<<endl;
	cout<<"4.Red(Hot,hot!)"<<endl;
	int whi;
	cin>>whi;
	if(whi==1) {
		co1=2+br;
		co2=1+br;
		cok=8+br;
		coq=7+br;
		col=4+br;
	} else if(whi==2) {
		co1=2+br;
		co2=1+br;
		cok=7+br;
		coq=6+br;
		col=4+br;
	} else if(whi==3) {
		co1=3+br;
		co2=1+br;
		cok=6+br;
		coq=2+br;
		col=4+br;
	} else if(whi==4) {
		co1=2+br;
		co2=1+br;
		cok=5+br;
		coq=4+br;
		col=3+br;
	}
}
void bri() {
	system("CLS");
	cout<<"Brightness:"<<endl;
	cout<<"1.bright"<<endl;
	cout<<"2.dark"<<endl;
	int ccc;
	cin>>ccc;
	if(ccc==1&&br==0) {
		br=8;
		co1+=br;
		co2+=br;
		cok+=br;
		coq+=br;
		col+=br;
	} else if(br==8) {
		co1-=br;
		co2-=br;
		cok-=br;
		coq-=br;
		col-=br;
		br=0;
	}
}
void la() {
	system("CLS");
	cout<<"Time: "<<last<<endl;
	cin>>last;
	return ;
}
void speed() {
	system("CLS");
	cout<<"Speed:(upper limit:3)"<<endl;
	cin>>sp;
	if(sp==1) {
		sp=5;
	} else if(sp==2) {
		sp=3;
	} else if(sp==3) {
		sp=1;
	}
	return ;
}
void Mode() {
	int whi;
	cout<<"Mod:"<<endl;
	cout<<"1.'+'."<<endl;
	cout<<"2.No '+'."<<endl;
	cin>>whi;
	if(whi==1) mode=1;
	else if(whi==2) mode=0;
	cout<<"1.Hide Wall"<<endl;
	cout<<"2.Nope!"<<endl;
	cin>>whi;
	if(whi==1) mode2=1;
	else if(whi==2) mode2=0;
	cout<<"1.Explore"<<endl;
	cout<<"2.Nope"<<endl;
	cin>>whi;
	if(whi==1) mode3=1;
	else if(whi==2) mode3=0;
	return ;
}

void window_size(){
//	system("CLS");
//	cout<<"Insert the window's size:";
	system("mode con cols=50 lines=30");
}

void Setting() {
	int accat=1;
	int FF=0;
	while(1) {
		Sleep(500);
		accat--;
		system("CLS");
		while(1) {
			gotoxy(0,0);
			cout<<"Set"<<endl;

			for(int i=0; i<6; i++) {
				ccp(sett[i],accat==i ? 14 : 15);
				cout<<endl;
			}
			cout<<accat+1<<endl;
			cout<<"Press ESC to exit."<<endl;
			int f=0;
			while(1) {
				Sleep(70);
				if(KEY_DOWN(VK_UP)) {
					accat=(accat-1+6)%6;
					break;
				}
				if(KEY_DOWN(VK_DOWN)) {
					accat=(accat+1+6)%6;
					break;
				}
				if(KEY_DOWN(VK_RETURN)) {
					f=1;
					break;
				}
				if(KEY_DOWN(VK_ESCAPE)) {
					f=1;
					FF=1;
					break;
				}
			}
			if(f==1) break;
		}
		if(FF==1) return ;
		Sleep(200);
		accat++;
		if(accat==1) {
			theme();
		}
		if(accat==2) {
			bri();
		}
		if(accat==3) {
			la();
		}
		if(accat==4) {
			speed();
		}
		if(accat==5) {
			Mode();
		}
		if(accat==6){
			window_size();
		}
	}
}

int main() {
	int whi;
	init();
	system("mode con cols=200 lines=200");
	system("title You catch and I run!");
start:
	xa=2;
	xb=2;
	ya=2;
	yb=41;
	system("CLS");
	cout<<"You catch and I run!"<<endl;
	Sleep(1000);
	int accat=1;
	while(1) {
		accat--;
		system("CLS");
		while(1) {
			gotoxy(0,0);
			cout<<"You catch and I run!"<<endl;

			for(int i=0; i<5; i++) {
				ccp(start[i],accat==i ? 14 : 15);
				cout<<endl;
			}
			cout<<accat+1<<endl;
			int f=0;
			while(1) {
				Sleep(70);
				if(KEY_DOWN(VK_UP)) {
					accat=(accat-1+5)%5;
					break;
				}
				if(KEY_DOWN(VK_DOWN)) {
					accat=(accat+1+5)%5;
					break;
				}
				if(KEY_DOWN(VK_RETURN)) {
					f=1;
					break;
				}
			}
			if(f==1) break;
		}
		accat++;
		if(accat==1) {
			system("CLS");
			break;
		} else if(accat==2) {
			Setting();
		} else if(accat==3) {
			system("CLS");
			cout<<"Name:张心博"<<endl;
			cout<<"Net Name:开心"<<endl;
			cout<<"Luogu account:张心博harry(547725)"<<endl;
			cout<<"WeChat:Harry(ZXB-2010Harry)"<<endl;
			cout<<"QQ:KAIXIN(2587706597)"<<endl;
			system("pause");
		} else if(accat==4) {
			system("CLS");
			cout<<"Acknowledgement:"<<endl<<endl;
			Sleep(500);
			for(int i=0; i<10; i++) {
				print(thanks[i],50);
				cout<<endl;
			}
			system("pause");
		} else {
			system("CLS");
			cout<<"BYE BYE!"<<endl;
			return 0;
		}
	}
	system("CLS");

	HideCursor();
	system("CLS");

//	cout<<"1.'@'run  2.'#'run"<<endl;
//	int who=0;
//	cin>>who;
//	Sleep(500);
//	system("CLS");

	system("CLS");
	cout<<"Map:"<<endl;
	cout<<"1.Maze"<<endl;
	cout<<"2.Factory"<<endl;
	cout<<"3.Empty"<<endl;
	cout<<"4.Confusion"<<endl;
	cout<<"5.Eight Diagram"<<endl;
	cout<<"6.Windmill"<<endl;
	cout<<"7.Symbols"<<endl;
	cout<<"8.Street_graffiti"<<endl;
	cout<<"9.KID2695"<<endl;
	cout<<"10.Pig"<<endl;
	cout<<"11.CZ's_segment_tree"<<endl;
	cout<<"12.Quartering"<<endl;
	cout<<"13.fission"<<endl;
	cout<<"14.crab" <<endl;
	cin>>whi;
	cout<<"ReEnter:";
	cin>>whi;
	if(whi==1) {
		freopen("maps/maze.text","r",stdin);
		last=1250;
	} else if(whi==2) {
		freopen("maps/factory.text","r",stdin);
		last=800;
	} else if(whi==3) {
		freopen("maps/empty.text","r",stdin);
	} else if(whi==4) {
		cout<<"This map is from @Rainforests(685825)."<<endl;
		freopen("maps/confusion.text","r",stdin);
		last=1250;
	} else if(whi==5) {
		cout<<"This map is from @YPPAH(570128)."<<endl;
		freopen("maps/Eight_Diagram.text","r",stdin);
		last=1250;
	} else if(whi==6) {
		cout<<"This map is from @Rainforests(685825)."<<endl;
		freopen("maps/windmill.text","r",stdin);
		last=1000;
	} else if(whi==7) {
		cout<<"This map is from @YPPAH(570128)."<<endl;
		freopen("maps/symbols.text","r",stdin);
		last=900;
	} else if(whi==8) {
		cout<<"This map is from @KID2695(544696)."<<endl;
		freopen("maps/Street_graffiti.text","r",stdin);
		last=1250;
	} else if(whi==9) {
		cout<<"This map is from @KID2695(544696)."<<endl;
		freopen("maps/KID2695.text","r",stdin);
		last=1000;
	} else if(whi==10) {
		cout<<"This map is from @YPPAH(570128)."<<endl;
		freopen("maps/pig.text","r",stdin);
		last=900;
	} else if(whi==11) {
		cout<<"This map is from @秦屎皇(536743)."<<endl;
		freopen("maps/CZ.text","r",stdin);
		last=1000;
	} else if(whi==12) {
		cout<<"This map is from @Boranhoushen10(685031)."<<endl;
		freopen("maps/Quartering.text","r",stdin);
		last=1000;
	} else if(whi==13) {
		cout<<"This map is from @ben093002(609092)."<<endl;
		freopen("maps/fission.text","r",stdin);
		last=1000;
	} else if(whi==14) {
		cout<<"This map is from @G__G(678115)."<<endl;
		freopen("maps/crab.text","r",stdin);
		last=1000;
	} else {
		cout<<"False"<<endl;
		Sleep(1000);
		return 0;
	}
	memset(d,0,sizeof(d));
	char cha;
	cin>>hang>>lie;
	for(int i=1; i<=hang; i++) { //读档
		for(int j=1; j<=lie; j++) {
			cin>>cha;
			if(cha!='@') {
				d[i][j]=1;
			}
			if(cha=='+'&&mode==1) {
				d[i][j]=2;
			} else if(cha=='+') {
				d[i][j]=0;
			}
//			else if(cha=='-'){
//				d[i][j]=3;
//			}
		}
	}
	freopen("CON","r",stdin);
	cout<<"ok!"<<endl;
	Sleep(1000);

//	else{
//		cout<<"False"<<endl;
//		Sleep(1000);
//		return 0;
//	}
	system("CLS");
	f=-1;
	yb=lie-1;
	gotoxy(0,0);
	if(!mode3) {
		for(int i=1; i<=hang; i++) {
			for(int j=1; j<=lie; j++) {
				gotoxy((j-1)*2,i-1);
				if(i==xa&&j==ya) {
					ccpp("█",co1);
				} else if(i==xb&&j==yb) {
					ccpp("█",co2);
				} else if(i==1||i==hang) {
					ccpp("▓",coq);
				} else if(j==1||j==lie) {
					ccpp("▓",coq);
				} else if(d[i][j]==1&&mode2==0) ccpp("▓",coq);
				else if(d[i][j]==2&&mode==1) {
					ccpp("█",col);
					if(((xa+1==i&&ya==j)||(xa-1==i&&ya==j)||(ya+1==j&&xa==i)||(ya-1==j&&xa==i))||((xb+1==i&&yb==j)||(xb-1==i&&yb==j)||(yb+1==j&&xb==i)||(yb-1==j&&xb==i))) {
						last-=10;
					}

				}
//				else if(s[i][j]==3) cout<<"-";
				else ccpp("█",cok);

			}
			cout<<endl;
		}
	} else {
		for(int i=1; i<=hang; i++) {
			for(int j=1; j<=lie; j++) {
				gotoxy((j-1)*2,i-1);
				if(i==1||i==hang) {
					ccpp("▓",coq);
				} else if(j==1||j==lie) {
					ccpp("▓",coq);
				} else {
					cout<<"  ";
				}
			}
			cout<<endl;
		}
	}
	while(last>0) { //游戏主体
		HideCursor();
		Sleep(50);
		if((xa==xb&&ya==yb)||((xa+1==xb&&ya==yb)||(xa-1==xb&&ya==yb)||(ya+1==yb&&xa==xb)||(ya-1==yb&&xa==xb))) {
			f=0;
		}
		gotoxy(0,0);
		for(int i=1; i<=hang; i++) {
			for(int j=1; j<=lie; j++) {
				/*	if(i==xa&&j==ya) {
						ccpp("█",co1);
					} else if(i==xb&&j==yb) {
						ccpp("█",co2);
					} else if(i==1||i==hang) {
						ccpp("▓",coq);
					} else if(j==1||j==lie) {
						ccpp("▓",coq);
					} else if(d[i][j]==1) ccpp("▓",coq);
					else*/
				if(d[i][j]==2&&mode==1) {
//						ccpp("█",col);
					if(((xa+1==i&&ya==j)||(xa-1==i&&ya==j)||(ya+1==j&&xa==i)||(ya-1==j&&xa==i))||((xb+1==i&&yb==j)||(xb-1==i&&yb==j)||(yb+1==j&&xb==i)||(yb-1==j&&xb==i))) {
						last-=10;
					}

				}
//				else if(s[i][j]==3) cout<<"-";
//					else ccpp("█",cok);

			}
//				cout<<endl;
		}
		gotoxy(0,hang);
		cout<<"Last time:";
		printf("%4d\n",last);

		ccpp("█",co2);
		cout<<"grasp";
		ccpp("█",co1);
		cout<<endl;
		cout<<"Wall:";
		ccpp("▓",coq);
		cout<<endl;
		cout<<"+:";
		ccpp("█",col);
		cout<<endl;
		if(f==0) {
			f++;
			break;
		} else if(f>0) {
			f--;
		} else {
			last--;
		}
		if(KEY_DOWN('W')&&d[xa-1][ya]==0) {
			ra++;
			if(ra==sp) {
				gotoxy((ya-1)*2,xa-1);
				ccpp("█",cok);
				xa--;
				ra=0;
				nineprint((ya-1)*2,xa-1,xa,ya);
			}
		}
		if(KEY_DOWN('S')&&d[xa+1][ya]==0) {
			ra++;
			if(ra==sp) {
				gotoxy((ya-1)*2,xa-1);
				ccpp("█",cok);
				xa++;
				ra=0;
				nineprint((ya-1)*2,xa-1,xa,ya);
			}
		}
		if(KEY_DOWN('A')&&d[xa][ya-1]==0) {
			ra++;
			if(ra==sp) {
				gotoxy((ya-1)*2,xa-1);
				ccpp("█",cok);
				ya--;
				ra=0;
				nineprint((ya-1)*2,xa-1,xa,ya);
			}
		}
		if(KEY_DOWN('D')&&d[xa][ya+1]==0) {
			ra++;
			if(ra==sp) {
				gotoxy((ya-1)*2,xa-1);
				ccpp("█",cok);
				ya++;
				ra=0;
				nineprint((ya-1)*2,xa-1,xa,ya);
			}
		}
		if(KEY_DOWN(VK_UP)&&d[xb-1][yb]==0) {
			rb++;
			if(rb==sp) {
				gotoxy((yb-1)*2,xb-1);
				ccpp("█",cok);
				xb--;
				rb=0;
				nineprint((yb-1)*2,xb-1,xb,yb);
			}
		}
		if(KEY_DOWN(VK_DOWN)&&d[xb+1][yb]==0) {
			rb++;
			if(rb==sp) {
				gotoxy((yb-1)*2,xb-1);
				ccpp("█",cok);
				xb++;
				rb=0;
				nineprint((yb-1)*2,xb-1,xb,yb);
			}
		}
		if(KEY_DOWN(VK_LEFT)&&d[xb][yb-1]==0) {
			rb++;
			if(rb==sp) {
				gotoxy((yb-1)*2,xb-1);
				ccpp("█",cok);
				yb--;
				rb=0;
				nineprint((yb-1)*2,xb-1,xb,yb);
			}
		}
		if(KEY_DOWN(VK_RIGHT)&&d[xb][yb+1]==0) {
			rb++;
			if(rb==sp) {
				gotoxy((yb-1)*2,xb-1);
				ccpp("█",cok);
				yb++;
				rb=0;
				nineprint((yb-1)*2,xb-1,xb,yb);
			}
		}
		if(KEY_DOWN(VK_SPACE)){
			Sleep(200);
			while(1){
				if(KEY_DOWN(VK_SPACE)) break;
			}
			Sleep(200);
		}
	}
	Sleep(1000);
	system("CLS");
	if(f==1) {
		ccpp("█",co2);
		cout<<" Win!"<<endl;
		cout<<"Last time:"<<last<<endl;
		Sleep(3000);
	} else {
		ccpp("█",co1);
		cout<<" Win!"<<endl;
		cout<<"Last time:"<<last<<endl;
		Sleep(3000);
	}
	system("CLS");
		cout<<"1.One more game"<<endl;
		cout<<"2.Exit the game"<<endl;
		int AA;
		cin>>AA;
		while(1) {
			if(AA==1) goto start;
			if(AA==2) {
				system("CLS");
				cout<<"BYE BYE!"<<endl;
				Sleep(1000);
				return 0;
			}
		}
	return 0;
}
/*
maze
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$@@@@@@@@$@@@@@@@@@@@@$@@@@@@@@@@@@@@@@@@$
$@@@@@@@@@@@@@@@$@@@@@@@@@@@@@@@@@@@@@@@@$
$$$$$@@@$$$$$$$$$$@@@$$$$$$$$$$@@@$$$$$$$$
$@@@@$@@@@@$@@@@@$@@@@@$@@@@@$@@@@@$@@@@@$
$@$@@@@@$@@@@@$@@@@@$@@@@@$@@@@@$@@@@@$@@$
$@$$$$$$$$$$$$$$$@@$$$$$$$$$$$$$$$$$$$$@@$
$@@@@@@@$@@@@@@@$@@$@@@@@@@@@@@@@@@@@@@@@$
$@@@$@@@$@@$@@@@@@@@@@@@@@$@@@@@$$$$$$@@@$
$@@@$@@@@@@$@@@@@@@@@@@@@@$@@@@@$@@@@@@@@$
$$$$$@@$$$$$$$$$$$$$$$$$$$$@@$@@$@@$$$$$@$
$@@@@@@@@@$@@@@@@@@$@@@@@@@@@@@@$@@@@@@@@$
$@@@@@@@@@@@@@@$@@@@@@@@@@@@@@@@$$$$$$@@@$
$$$$$$$$$$$@@@@$$$$$$$$$$$$$$$$$$$$$$$@@@$
$@@@@@@@@@$@@@@$@@@@@$@@@@@@@@@$@@@@@$@@@$
$@@@@@@@@@@@@@@@@@$@@@@@$@@@$@@@@@@$@@@$@$
$@@$@@@$$$$$$$$$$$$$$$$$$@@@$$$$$$$$$$$$$$
$@@$@@@@@$@@@@@$@@@@@$@@@@@@$@@@@@$@@@@@@$
$@@$@@$@@@@@$@@@@@$@@@@@$@@@@@$@@@@@@$@@@$
$@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$@@@$
$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/
/*
factory
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$
$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$
$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$
$@@@@@$$$$$$$$$$$$$$$@@$$$$$$$$$$$$$@@@@@$
$@@@@@$@@@@@@@@@@@@@@@@@@@@@@@@@@@@$@@@@@$
$@@@@@$@@@@@@@@@@@@@@@@@@@@@@@@@@@@$@@@@@$
$@@@@@$@@@@$$$$$$$$$$$$$$$$@@@@@@@@$@@@@@$
$@@@@@@@@@@$$$$$$$$$$$$$$$$@@@@@@@@@@@@@@$
$@@@@@@@@@@$$$$$@@@@@@@@@@@@@@@@@@@@@@@@@$
$@@@@@@@@@@$$$$$@@@@@@@@@@@@@@@@@@@@@@@@@$
$@@@@@@@@@@$$$$$@@@@@$$$$$$@@@@@@@@@@@@@@$
$@@@@@@@@@@$$$$$@@@@@$$$$$$@@@@@@@@@@@@@@$
$@@@@@@@@@@$$$$$@@@@@$$$$$$@@@@@@@@@@@@@@$
$@@@@@$@@@@$$$$$$@@@@$$$$$$@@@@@@@@$@@@@@$
$@@@@@$@@@@@@@@@@@@@@@@@@@@@@@@@@@@$@@@@@$
$@@@@@$@@@@@@@@@@@@@@@@@@@@@@@@@@@@$@@@@@$
$@@@@@$$$$$$$$$$$$$$$$$@@$$$$$$$$$$$@@@@@$
$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$
$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$
$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

*/

/*
Eight Diagram
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$@@@#@@@@#@@@@@#@@@@#@@@@@@@@###@@@@@#@@@$
$@@###@@@@#@@@#@@@@###@@@@@@#@@@#@@@###@@$
$@#####@@@@@@@@@@@#####@@@@@@@@@@@@#####@$
$@@@#@@@@@@@#@@@@@@@#@@@@@@@@###@@@@@#@@@$
$@@@@@@@@@#########@#@########@@@@@@@@@@@$
$@#@@#@@##@@@@@@@@#@@@@@@@@@#@##@@@@@#@#@$
$#@@@@###@@@@@@@@#@@@###@@@@@@@##@@@#@@@#$
$@#@@##@@@@@@@@#@@@@@###@@@@#@@@@#@@@#@#@$
$@@@@#@@@###@@@#@@@@@###@@@@#@@@@@#@@@@@@$
$@@#@@@@#@@@#@@@@#@@@@@@@@@#@@@@@@@@#@@@@$
$@@#@@@#@@@@@#@@@@#@#@#@@@#@@@@@#@@#@@@@@$
$@@@@@@@@@@@#@@@@@@@@@@@#@@#@@@#@@@@@@@@@$
$@#@##@@@@@#@@@@@@@###@@@@#@###@@@@#@#@#@$
$#@@@##@@@@#@@@@@@@###@@@@@#@@@@@@#@#@@@#$
$@#@#@@##@@@@@@@@@@###@@@#@@@@@@##@@@#@#@$
$@@@@@@@##@#@@@@@@@@@@@#@@@@@@@##@@@@@@@@$
$@@@#@@@@@@@@######@#@######@@@@@@@@@#@@@$
$@@###@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@###@@$
$@#####@@@@@@#@@@#@@@#@@@#@@@#@@@@@#####@$
$@@@#@@@@@@#@@@#@@@#@@@#@@@#@@@#@@@@@#@@@$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/
