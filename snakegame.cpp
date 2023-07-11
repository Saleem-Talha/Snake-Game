////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        //3rd semester project
                                        //2 player snake game
                                        //having full screen window
										//3 maps
										//saves highest score of each map
							//made by:Anila salman (210985)   ,,, Ammar Younis(210955) ,,, Saleem Talha (210973)
										 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<windows.h>
#include<conio.h>
#include <fstream>



using namespace std;
int height=42;
int width=150;

int gameover=0,counter,gameover2=0,choice,counter2;
int lflag=0,rflag=0,uflag=0,dflag=0;
int lflag2=0,rflag2=0,uflag2=0,dflag2=0;
short fcount;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class node{
	public:
	int nx,ny;
	node* next;
	node* back;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Snake
{	
	
	int x,y,fx,fy,x2,y2;
	char playername[50],playername2[50];;
	
	 node *head=NULL;
	 node *head2=NULL;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void gotoxy(int x,int y)
	{
		COORD pos={x,y};                                                                  //x and y axis
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);                
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void nameandscore()
	{
		gotoxy(152,0);
		textcolour(10);
		cout<<" Score Board";
		textcolour(2);
		gotoxy(152,2);
		cout<<playername<<"'s SCORE = "<<counter*100;
	  
		    textcolour(5);
			gotoxy(152,4);
			cout<<playername2<<"'s SCORE = "<<counter2*100;
			textcolour(6);
			gotoxy(152,6);
			cout<<"Remained Fruit :";
			
			gotoxy(168,6);
			cout<<fcount;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void highscore(){
	gotoxy(152,25);
		textcolour(10);
		cout<<" HIGHEST SCORE";
    int scoree;
	string name;	
	////////////////////////////////////////
	if(choice==1){ 
	
	ifstream in("level1.txt",ios::in);
	for(int i=0;i<1;i++){
	in>>name;
	in>>scoree;
	}
	in.close();
	    textcolour(5);
		gotoxy(153,26);
     cout<<"Name:  "<<name;
     textcolour(5);
	 gotoxy(153,27);
     cout<<"Score: "<<scoree;}
    //////////////////////////////////// 
     if(choice==2){
     	int scoree;
	string name;	
	ifstream in("level2.txt",ios::in);

	for(int i=0;i<1;i++){
	in>>name;
	in>>scoree;
	}
	in.close();
	    textcolour(5);
		gotoxy(153,26);
     cout<<"Name:  "<<name;
     textcolour(5);
	 gotoxy(153,27);
     cout<<"Score: "<<scoree;
	 }
	 //////////////////////////////////
	 if(choice==3){
	 	int scoree;
	string name;	
	ifstream in("level3.txt",ios::in);

	for(int i=0;i<1;i++){
	in>>name;
	in>>scoree;
	}
	in.close();
	    textcolour(5);
		gotoxy(153,26);
     cout<<"Name:  "<<name;
     textcolour(5);
	 gotoxy(153,27);
     cout<<"Score: "<<scoree;
	 }
	//////////////////////////////////
}
					
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void textcolour(int k)
	{
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,k);	
	}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public:	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void window()
	{
		if(choice!=1)
		textcolour(4);                                                   //RED BOARDERS
		else
		textcolour(1);                                                  //BLUE BOARDERS
			for(int i=0;i<=width;i++)
		{
			gotoxy(i,0);
			cout<<"Û";
			gotoxy(i,height);
			cout<<"Û";
		}
	
		for(int i=0;i<=height;i++)
		{
			gotoxy(0,i);
			cout<<"Û";
			gotoxy(width,i);
			cout<<"Û";
		}
	}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void window3()
	{
		textcolour(4);                                                   //RED BOARDERS
		                                                 
			for(int i=0;i<=width;i++)
		{
			gotoxy(i,0);
			cout<<"Û";
			gotoxy(i,height);
			cout<<"Û";
		}
	
		for(int i=0;i<=height;i++)
		{
			gotoxy(0,i);
			cout<<"Û";
			gotoxy(width,i);
			cout<<"Û";
		}
			for(int i=30;i<=35;i++)            //low left
		{
			gotoxy(30,i);
			cout<<"Û";
			gotoxy(i,35);
			cout<<"Û";
		}
			for(int i=10;i<=15;i++)         //high left
		{
			gotoxy(30,i);
			cout<<"Û";
			gotoxy(i+20,10);
			cout<<"Û";
		}
			for(int i=30;i<=35;i++)  //high right
		{
			gotoxy(96,i-20);
			cout<<"Û";
			gotoxy(i+60,10);
			cout<<"Û";
		}
			for(int i=30;i<=35;i++)  //low right
		{
			gotoxy(96,i);
			cout<<"Û";
			gotoxy(i+60,35);
			cout<<"Û";
		}
	}		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void drawlist( node *h,int k)
	{
		textcolour(k);
		node *ptr;
		ptr=h;
		while(ptr!=NULL)
		{
			gotoxy(ptr->nx,ptr->ny);
			cout<<"Û";
			ptr=ptr->next;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	void destroylist( node *h)
	{
		node *ptr;
		ptr=h;
		while(ptr!=NULL)
		{
			gotoxy(ptr->nx,ptr->ny);
			cout<<" ";
			ptr=ptr->next;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void draw()
	{
		
		drawlist(head,2);
		drawlist(head2,5);
		gotoxy(fx,fy);
		textcolour(4);
		cout<<"@";
		Sleep(70);
		destroylist(head);
		destroylist(head2);
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void resetflag()
	{
		uflag=0;
		dflag=0;
		lflag=0;
		rflag=0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void resetflag2()
	{
		uflag2=0;
		dflag2=0;
		lflag2=0;
		rflag2=0;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void play()
	{
		int h;
		char ch;
		if(kbhit())
		{	
			
			ch=getch();
			h=ch;
			switch(h)
			{
				case 72:if(dflag!=1){resetflag();uflag=1;}
				break;
				case 80:if(uflag!=1){resetflag();dflag=1;}
				break;
				case 75:if(rflag!=1){resetflag();lflag=1;}
				break;
				case 77:if(lflag!=1){resetflag();rflag=1;}
				break;
				
				case 119:if(dflag2!=1){resetflag2();uflag2=1;}
				break;
				case 115:if(uflag2!=1){resetflag2();dflag2=1;}
				break;
				case 97:if(rflag2!=1){resetflag2();lflag2=1;}
				break;
				case 100:if(lflag2!=1){resetflag2();rflag2=1;}
				break;
				
				case 27:{
				system("pause");
				system("cls");
				if(choice==1){ 	window(); highscore();	nameandscore();			}
				if(choice==2){ 	window(); highscore();	nameandscore();			}
				if(choice==3){ 	window3(); highscore();		nameandscore();		}
					break;
				}
				default:break;
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void box(int m1,int n1,int m2,int n2)
	{
			for(int i=m1;i<=m2;i++)
		{
			gotoxy(i,n1);
			cout<<"//";
			gotoxy(i,n2);
			cout<<"//";
		}
		
		for(int i=n1;i<=n2;i++)
		{
			gotoxy(m1,i);
			cout<<"//";
			gotoxy(m2,i);
			cout<<"//";
		}	
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void welcome()
	{
		textcolour(2);                                       //0 black,2 green dark, 4 red,5 pulple ,10 bright green etc
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
		textcolour(10);
		gotoxy(width/2-20,height/2-10);
		cout<<"*** WELCOME TO SNAKE GAME  *** ";
		textcolour(9);
		gotoxy(width/2-18,height/2-2);
		cout<<"Press 1 For level 1:Open border \n";
		gotoxy(width/2-18,height/2-1);
		cout<<"Press 2 For level 2:Closed border  \n";
		gotoxy(width/2-18,height/2);
		cout<<"Press 3 For level 3:Closed border and blocks \n";
		gotoxy(width/2-18,height/2+1);
		cin>>choice;
		system("cls");
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void welcome2()
	{
		textcolour(5);
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
		textcolour(6);
		gotoxy(width/2-18,height/2-3);
		cout<<"WELCOME TO SNAKE GAME MULTIPLAYER MODE ";
		textcolour(8);
		gotoxy(width/2-13,height/2);
		cout<<"Enter Player1 Name : ";
		gotoxy(width/2-13,height/2+2);
		cout<<"Enter Player2 Name : ";
		gotoxy(width/2+7,height/2);
		cin>>playername;
		gotoxy(width/2+7,height/2+2);
		cin>>playername2;
		system("cls");
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	char end()
	{
		
		char c;
		gotoxy(width/2-5,height/2-4);
		cout<<"GAME OVER \n";
		textcolour(5);
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
		
		textcolour(1);
		gotoxy(width/2-15,height/2-2);
		cout<<playername<<" You Scored : "<<counter*100;
	
			gotoxy(width/2-15,height/2);
			cout<<playername2<<" You Scored : "<<counter2*100;
			textcolour(4);
			if(gameover!=0)                                                            //hit it self
			{
				gotoxy(width/2-15,height/2+2);
				cout<<playername<<" has lost !";
			}
			else
			{
				gotoxy(width/2-15,height/2+2);
				cout<<playername2 <<" has lost !";	
			}
			if(fcount==0)                                        //fruite counter =0
			{
				textcolour(4);
				gotoxy(width/2-15,height/2+2);
				if(counter>counter2)
				{
					cout<<playername<<" has WON !";
				}
				else
				{
					cout<<playername2<<" has WON !";
				}
			}
		
		textcolour(6);
		gotoxy(width/2-15,height/2+4);
		cout<<"Want To Play Again ? (Y/N) : ";
		cin>>c;
		///////////////////////////////////////////////
		if(choice==1){
	int score;
	string str;	
	ifstream in("level1.txt",ios::in);

	in>>str;
	in>>score;
	
	in.close();
	 
    if((counter*100)>score){
  	
		ofstream out ("level1.txt",ios::out);
		out<<playername<<"\n";
		out<<counter*100<<"\n";
		
		
		out.close();
	}
	 if((counter2*100)>score){
  	
		ofstream out ("level1.txt",ios::out);
		out<<playername2<<"\n";
		out<<counter*100<<"\n";
		
		
		out.close();
	}}
	/////////////////////////////////////////////////
		if(choice==2){
	int score;
	string str;	
	ifstream in("level2.txt",ios::in);

	in>>str;
	in>>score;
	
	in.close();
	 
    if((counter*100)>score){
  	
		ofstream out ("level2.txt",ios::out);
		out<<playername<<"\n";
		out<<counter*100<<"\n";
		
		
		out.close();
	}
	 if((counter2*100)>score){
  	
		ofstream out ("level2.txt",ios::out);
		out<<playername2<<"\n";
		out<<counter*100<<"\n";
		
		
		out.close();
	}}
	///////////////////////////////////////////////
		if(choice==3){
	int score;
	string str;	
	ifstream in("level3.txt",ios::in);

	in>>str;
	in>>score;
	
	in.close();
	 
    if((counter*100)>score){
  	
		ofstream out ("level3.txt",ios::out);
		out<<playername<<"\n";
		out<<counter*100<<"\n";
		
		
		out.close();
	}
	 if((counter2*100)>score){
  	
		ofstream out ("level3.txt",ios::out);
		out<<playername2<<"\n";
		out<<counter*100<<"\n";
	////////////////////////////////////////////
		
		out.close();
	}}
		system("cls");
		return c;
		
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void run()
	{
		if(uflag==1)
		y--;
		else if(dflag==1)
		y++;
		else if(lflag==1)
		x--;
		else if(rflag==1)
		x++;
		
		
			if(uflag2==1)
		y2--;
		else if(dflag2==1)
		y2++;
		else if(lflag2==1)
		x2--;
		else if(rflag2==1)
		x2++;
	
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void dolist( node *h,int pp,int qq)
	{
		 node *ptr,*prev;
		ptr=h;
		prev=h;
	
		while(ptr->next!=NULL)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		while(prev!=h)
		{
			ptr->nx=prev->nx;
			ptr->ny=prev->ny;
			prev=prev->back;
			ptr=ptr->back;
		}
		ptr->nx=prev->nx;
		ptr->ny=prev->ny;
		prev->nx=pp;
		prev->ny=qq;
	}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	void drawagain()
	{
		if(x==width)
		{
			x=1;
		}
		if(x==0)
		{
			x=width-1;
		}
		if(y==0)
		{
			y=height-1;
		}
		if(y==height)
		{
			y=1;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void drawagain2()
	{
		if(x2==width)
		{
			x2=1;
		}
		if(x2==0)
		{
			x2=width-1;
		}
		if(y2==0)
		{
			y2=height-1;
		}
		if(y2==height)
		{
			y2=1;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void generatefruit()
	{
			label1:
			fx=rand()%width;
			if(fx==0||fx==width)
			goto label1;
			label2:
			fy=rand()%height;
			if(fy==0||fy==height)
			goto label2;
			if(choice==3){
				for(int i=30;i<=35;i++)            //low left
		{
			if(fx==30 && fy==i)
			goto label1;
			if(fx==i && fy==35)
			goto label1;
		}
			for(int i=10;i<=15;i++)         //high left
		{
			if(fx==30 && fy==i)
			goto label1;
			if(fx==(i+20) && fy==10)
			goto label1;
		}
			for(int i=30;i<=35;i++)  //high right
		{
			if(fx==96 && fy==(i-20))
			goto label1;
			if(x==(i+60) && fy==10)
			goto label1;
		}
			for(int i=30;i<=35;i++)  //low right
		{
			if(fx==96&&fy==i)
			goto label1;
			if(fx==(i+60)&& fy==35)
			goto label1;
		}
			}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void checkfcount()
	{
		if(fcount==0)
		{
			gameover=1;
			gameover2=1;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void setup()
	{   
	   int xx,yy;
	   xx=rand()%width/2;
	   yy=rand()%height/2;
		counter=0;
		gameover=0;
		window();
		resetflag();
		nameandscore();
		head=new node;
		head->nx=xx;
		head->ny=yy;
		head->next=NULL;
		head->back=NULL;
		x=xx;
		y=yy;
		label1: 
		fx=rand()%width;
		if(fx==0||fx==width)
		goto label1;
		label2:
		fy=rand()%height;
		if(fy==0||fy==height)
		goto label2;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void setup2()
	{   
	    int xx2,yy2;
	    xx2=rand()%width/2+5;
	    yy2=rand()%height/2+5;
		resetflag2();
		gameover2=0;
		counter2=0;
		textcolour(10);
		textcolour(2);                                       //0 black,2 green dark, 4 red,5 pulple ,10 bright green etc
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
     	gotoxy(width/2-18,height/2+1);
		cout<<"Select the number of fruits: ";
		cin>>fcount;
		system("cls");
		head2=new node;
		head2->nx=xx2;               //snake start point
		head2->ny=yy2;             
		head2->next=NULL;
		head2->back=NULL;
		x2=xx2;                         //snake points
		y2=yy2;
		
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	void setup31()
	{    
	     int xx,yy;
		counter=0;
		gameover=0;
		window();
		resetflag();
		nameandscore();
		head=new node;
		head->nx=xx;
		head->ny=yy;
		head->next=NULL;
		head->back=NULL;
		x=xx;
		y=yy;
		label1: 
		fx=rand()%width;
		if(fx==0||fx==width)
		goto label1;
		label2:
		fy=rand()%height;
		if(fy==0||fy==height)
		goto label2;
	}		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void setup32()
	{   
	    int xx2,yy2;
	    xx2=rand()%width/2+5;
	    yy2=rand()%height/2+5;
		resetflag2();
		gameover2=0;
		counter2=0;
		textcolour(10);
		textcolour(2);                                       //0 black,2 green dark, 4 red,5 pulple ,10 bright green etc
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
     	gotoxy(width/2-18,height/2+1);
		cout<<"Select the number of fruits: ";
		cin>>fcount;
		system("cls");
		head2=new node;
		head2->nx=xx2;               //snake start point
		head2->ny=yy2;             
		head2->next=NULL;
		head2->back=NULL;
		x2=xx2;                         //snake points
		y2=yy2;
		
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void checkup()
	{                                                        //hit wall die
		if(choice==2 )         
		{
			if(x==width||x==0){
			gameover=1;}	
			if(y==height||y==1){
			gameover=1;}                      //kharab kar raha hy ..first time dead kar dyta..y ki value
		
		}
		drawagain();
		
	    node *h;
	    
		h=head->next;
		
		while(h!=NULL)
		{
			if(x==h->nx&&y==h->ny)                                       //hit it self
			{
				gameover=1;
				break;
			}
			h=h->next;
		
		}
	  node *h2;
	    
		h2=head2->next;
		
		while(h2!=NULL)
		{
			if(x==h2->nx&&y==h2->ny)                                       //other hit it self
			{
				gameover=1;
				break;
			}
			h2=h2->next;
		
		}
	
		if(x==fx&&y==fy)
		{
			
				fcount--;
				checkfcount();
			
			 node *t,*ptr,*prev;
			t=new node;
			t->next=NULL;
			t->back=NULL;
				ptr=head;
				prev=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;		
				}
				ptr->next=t;
				t->back=ptr;
				generatefruit();
			counter++;
			nameandscore();
		}
			dolist(head,x,y);
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
	void checkup2()
	{          	
	if(choice==2)
		{
			if(x2==width||x2==0)
			gameover2=1;	
			if(y2==height||y2==0)
			gameover2=1;
		}                                    //die on count of fruits
		drawagain2(); 
		 node *h;
	
		h=head2->next;
	
		while(h!=NULL)
		{                                                        //hit itself
			if(x2==h->nx&&y2==h->ny)
			{
				gameover2=1;
				break;
			}
	
			h=h->next;
		}
	 node *h2;
	
		h2=head->next;
	
		while(h2!=NULL)
		{
			if(x2==h2->nx&&y2==h2->ny)                   ///hit by other
			{
				gameover2=1;
				break;
			}
	
			h2=h2->next;
		}
	
		if(x2==fx&&y2==fy)
		{
			fcount--;
			checkfcount();
		    node *t,*ptr,*prev;
			t=new node;
			t->next=NULL;
			t->back=NULL;
				ptr=head2;
				prev=head2;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;		
				}
				ptr->next=t;
				t->back=ptr;
				generatefruit();
				counter2++;
				nameandscore();
		}
			dolist(head2,x2,y2);
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	void checkup31()
	{                                                        //hit wall die
		
		
			if(x==width||x==0)
			gameover=1;	
			if(y==height||y==0)
			gameover=1;
		
		drawagain();
			for(int i=30;i<=35;i++)            //low left
		{
			if(x==30 && y==i)
			gameover=1;
			if(x==i && y==35)
			gameover=1;
		}
			for(int i=10;i<=15;i++)         //high left
		{
			if(x==30 && y==i)
			gameover=1;
			if(x==(i+20) && y==10)
			gameover=1;
		}
			for(int i=30;i<=35;i++)  //high right
		{
			if(x==96 && y==(i-20))
			gameover=1;
			if(x==(i+60) && y==10)
			gameover=1;
		}
			for(int i=30;i<=35;i++)  //low right
		{
			if(x==96&&y==i)
			gameover=1;
			if(x==(i+60)&& y==35)
			gameover=1;
		}
	    node *h;
		h=head->next;
		while(h!=NULL)
		{
			if(x==h->nx&&y==h->ny)                                       //hit it self
			{
				gameover=1;
				break;
			}
			h=h->next;
		}
	
		if(x==fx&&y==fy)
		{
			
				fcount--;
				checkfcount();
				
			 node *t,*ptr,*prev;
			t=new node;
			t->next=NULL;
			t->back=NULL;
				ptr=head;
				prev=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;		
				}
				ptr->next=t;
				t->back=ptr;
				generatefruit();
			counter++;
			nameandscore();
		}
			dolist(head,x,y);
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void checkup32()
	{          	

			if(x2==width||x2==0)
			gameover2=1;	
			if(y2==height||y2==0)
			gameover2=1;
		                                    //die on hiting the wals
		drawagain2(); 
			for(int i=30;i<=35;i++)            //low left
		{
			if(x2==30 && y2==i)
			gameover2=1;
			if(x2==i && y2==35)
			gameover2=1;
		}
			for(int i=10;i<=15;i++)         //high left
		{
			if(x2==30 && y2==i)
			gameover=1;
			if(x2==(i+20) && y2==10)
			gameover2=1;
		}
			for(int i=30;i<=35;i++)  //high right
		{
			if(x2==96 && y2==(i-20))
			gameover2=1;
			if(x2==(i+60) && y2==10)
			gameover2=1;
		}
			for(int i=30;i<=35;i++)  //low right
		{
			if(x2==96&&y2==i)
			gameover2=1;
			if(x2==(i+60)&& y2==35)
			gameover2=1;
		}
		 node *h;
	
		h=head2->next;
	
		while(h!=NULL)
		{                                                        //hit itself
			if(x2==h->nx&&y2==h->ny)
			{
				gameover2=1;
				break;
			}
	
			h=h->next;
		}
	 node *h2;
	
		h2=head->next;
	
		while(h2!=NULL)
		{
			if(x2==h2->nx&&y2==h2->ny)                   ///hit by other
			{
				gameover2=1;
				break;
			}
	
			h2=h2->next;
		}
	
		if(x2==fx&&y2==fy)
		{
			fcount--;
			checkfcount();
			
		    node *t,*ptr,*prev;
			t=new node;
			t->next=NULL;
			t->back=NULL;
				ptr=head2;
				prev=head2;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;		
				}
				ptr->next=t;
				t->back=ptr;
				generatefruit();
				counter2++;
				nameandscore();
		}
			dolist(head2,x2,y2);
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
	void game1()
	{                
		char ch;
		welcome2();
		do{
			setup2();
			setup();
			window();
			highscore();
			while(gameover!=1&&gameover2!=1)
			{
				draw();
				play();
				run();
				checkup();
				checkup2();
			}ch=end();
		}while(ch=='y'||ch=='Y');
		
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void game2()////done 
	{
		
		char ch;
		welcome2();
		do{
	
			setup2();
			setup();
			window();
			highscore();
		while(gameover!=1&&gameover2!=1)
			{
				draw();
				play();
				run();
				checkup();
				checkup2();
			}ch=end();
		}while(ch=='y'||ch=='Y');
	}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	void game3()        //board created but hit on those points not done
	{
		char ch;
		welcome2();
		do{
	
			setup32();
			setup31();
			window3();
			highscore();
		while(gameover!=1&&gameover2!=1)
			{
				draw();
				play();
				run();
				checkup31();
				checkup32();
			}ch=end();
		}while(ch=='y'||ch=='Y');
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()

{
	Snake s;
	s.welcome();
	if(choice==1)
	{
		s.game1();
	}
	if(choice==2)
	{
		s.game2();
	}
	if(choice==3){
		s.game3();
	}
	system("exit");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

