#include<iostream>
#include<fstream>
#include<stdio>

class code
{
	char a;
	int l;
public:
	void input(){
		cin>>a;}
	void display(){
		cout<<a;}
	void dispsav(){
		cout<<a<<"\t\t"<<l;}
	char getw(){
		return a;}
	int getl(){
		return l;}
	void givl1(){
		l=1;}
	void givl2(){
		l=2;}
};

code s;
fstream f,f1;
void save(){
	char c='Y';
	int u;
	cout<<"\n*>Previous Selected Option(1-Input Coding/Decoding Database)"<<endl;
	cout<<endl;

	cout<<"Select Info. to be entered:\n";
	cout<<"1-Level 1\n";
	cout<<"2-Level 2\n";
	cout<<"Enter Choice:";
	cin>>u;
	switch(u){
		case 1:
		f.open("lev1",ios::app|ios::binary);
		cout<<"Level 1 Selected";
		break;
		case 2:
		f.open("lev2",ios::app|ios::binary);
		cout<<"Level 2 Selected";
		break;
		default:
		cout<<"Wrong Choice";
		break;
	}
	cout<<endl;
	cout<<"Enter Alphabet"<<"\t"<<"Enter Code for this alphabet"<<endl;
	while(c=='y'||c=='Y'){   
		s.input();
		f.write((char*)&s,sizeof(s));
		cout<<"\t\t";
		s.input();
		f.write((char*)&s,sizeof(s));
		cout<<endl;
		cout<<endl<<"Want to add more?[y/n]:";
		cin>>c;
		}
f.close();
}


void display(){
	int u;int t=0;
	cout<<"*>Previous Selected Option(2-Display Coding/Decoding Database)"<<endl;
	cout<<endl;
	cout<<"Select Info. to be displayed:\n";
	cout<<"1-Level 1\n";
	cout<<"2-Level 2\n";
	cout<<"3-Saved Info\n";
	cout<<"Enter Choice:";
	cin>>u;
	cout<<"\n";
	switch (u){
		case 1:
		f.open("lev1",ios::in|ios::binary);
		cout<<"Level 1 Selected";
		break;
		case 2:
		f.open("lev2",ios::in|ios::binary);
		cout<<"Level 2 Selected";
	 	break;
		case 3:
		f.open("save",ios::in|ios::binary);
		cout<<"Saved Code\n";
		cout<<"Coded Alphabet"<<"\t"<<"Coded by Level"<<endl;
		while(f.read((char*)&s,sizeof(s))){
			cout<<t+1<<") ";
			s.dispsav();
			cout<<endl;
			t++;
			if(t%23==0 && t!=0 && t!=1)
				{cout<<"Press Enter To Veiw Next Page";
				getch();
				clrscr();
				}
			}
			f.close();
			break;
		default:
		cout<<"Wrong Choice";
		cout<<endl<<"Press Enter 1 Times To Get Back To Main Menu";
		break;
	}
	cout<<endl;
	if(u==1 || u==2)
	{cout<<"\n";
		cout<<"Alphabet"<<"\t"<<"Code for this alphabet:"<<endl;
		while(f.read((char*)&s,sizeof(s)))
		{cout<<t+1<<") ";
			s.display();
		f.read((char*)&s,sizeof(s));
		cout<<"\t"<<"\t";
		s.display();
		cout<<endl;
		t++;
		if(t%23==0 && t!=0 && t!=1)
			{cout<<"Press Enter To Veiw Next Page";
			getch();
			clrscr();}

		}
		}
	f.close();
	cout<<endl<<"Press Enter 1 Times To Get Back To Main Menu";
	}
void coding()
{int i=0;
char w[100];
int c;
f.open("lev1",ios::in|ios::binary);
f1.open("save",ios::out|ios::binary);
cout<<"*>Previous Selected Option(3-Code)"<<endl;
cout<<endl<<"IMPORTANT MESSASGE FOR USERS:!!!!WARNING!!!"<<endl;
cout<<"Please do not enter:\n-> '(Single qoutes)\n-> `(on the left of 1 no. key) \nwhile coading or decoding..As it may cause malfunctioning of program or wrong \ncode to appear and cause inconvinience\nTHANK YOU.....\n";
cout<<"Press enter to continue:";
getch();
cout<<endl<<endl;
cout<<"Enter Word to be coded:";
gets(w);
cout<<"\nEnter Level of Coding[1/2]:";
cin>>c;
z:
while(i<100 && w[i]!='\0')
     {f.read((char*)&s,sizeof(s));
       if(w[i]==' ')
	 {w[i]='~';
	  i++;
	  f.seekg(0,ios::beg);
	  goto z;
	 }
       else if(w[i]=='~')
	      {w[i]='|';
	       i++;
	       f.seekg(0,ios::beg);
	       goto z;
	      }
      else  if(w[i]=='|')
	      {w[i]='!';
	       i++;
	       f.seekg(0,ios::beg);
	       goto z;}
      else  if(w[i]=='!')
	      {w[i]=' ';
	       i++;
	       f.seekg(0,ios::beg);
	       goto z;}
      else  if(w[i]==s.getw())
       { f.read((char*)&s,sizeof(s));
	 w[i]=s.getw();
	 if(c==1)
	   {s.givl1();
	    f1.write((char*)&s,sizeof(s));}
	    i++;
	    f.seekg(0,ios::beg);
	    goto z;}
     else
     {f.seekg(sizeof(s),ios::cur);}

}
f.close();
if(c==1){
	cout<<"\nCoded Word[Level 1]="<<w;
	cout<<endl<<"Press Enter 2 Times To Get Back To Main Menu";
	f1.close();
	getch();
}
else if(c==2){
	i=0;
	f.open("lev2",ios::in|ios::binary);
	y:
	while(i<100 && w[i]!='\0')
		{f.read((char*)&s,sizeof(s));
			if(w[i]=='~')
			{w[i]='|';
			i++;
			f.seekg(0,ios::beg);
			goto y;}
	else if(w[i]=='|')
		{w[i]='!';
		i++;
		f.seekg(0,ios::beg);
		goto y;}
	else  if(w[i]=='!')
		{w[i]=' ';
		i++;
		f.seekg(0,ios::beg);
		goto y;}
		else  if(w[i]==' ')
			{w[i]='~';
			i++;
			f.seekg(0,ios::beg);
			goto y;}

	else if(w[i]==s.getw())
		{ f.read((char*)&s,sizeof(s));
		w[i]=s.getw();
		if(c==2)
		{s.givl2();
			f1.write((char*)&s,sizeof(s));}
			i++;
			f.seekg(0,ios::beg);
			goto y;}
	else
	{f.seekg(sizeof(s),ios::cur);}
	}

	cout<<"\nCoded Word[Level 2]="<<w;
	cout<<endl<<"Press Enter 2 Times To Get Back To Main Menu";
	f.close();
	f1.close();
	getch();
	}
}

void decode(){
	int o,cl,i=0;
	char w[100];
	cout<<"*>Previous Selected Option(4-Decode)"<<endl;
	cout<<endl;
	cout<<"Select Mode of Decoding:\n";
	cout<<"1-Enter Code\n";
	cout<<"2-Select From Previous Entries\n";
	cout<<"Enter Choice:-";
	cin>>o;
	cout<<"\n";
	switch(o){
		case 1:
	v:
	cout<<"Enter Code:";
	gets(w);
	cout<<"Enter Decoding Level:";
	cin>>cl;
if(cl==2){
   f.open("lev2",ios::in|ios::binary);
   f.seekg(3,ios::cur);
   z:
   while(i<100 && w[i]!='\0')
	{f.read((char*)&s,sizeof(s));
	 if(w[i]=='|')
	   {w[i]='~';
	   i++;
	   f.seekg(3,ios::beg);
	   goto z;
	}

	else if(w[i]=='!')
		{w[i]='|';
		i++;
		f.seekg(3,ios::beg);
		goto z;}

	else if(w[i]==' ')
		{w[i]='!';
		i++;
		f.seekg(3,ios::beg);
		goto z;}

	else  if(w[i]=='~')
		{w[i]=' ';
		i++;
		f.seekg(3,ios::beg);
		goto z;}
	else if(w[i]==s.getw())
		{f.seekg((-6),ios::cur);
		f.read((char*)&s,sizeof(s));
		w[i]=s.getw();
		i++;
		f.seekg(3,ios::beg);
		goto z;
		}
	else
		{f.seekg(3,ios::cur);}

	}
f.close();
}
i=0;
f.open("lev1",ios::in|ios::binary);
f.seekg(3,ios::cur);
y:
	while(i<15 && w[i]!='\0')
	     {
	      f.read((char*)&s,sizeof(s));
	       if(w[i]=='~')
		 {w[i]=' ';
		  i++;
		  f.seekg(3,ios::beg);
		  goto y;}


		else  if(w[i]=='|')
			{w[i]='~';
			i++;
			f.seekg(0,ios::beg);
			goto y;}

		else if(w[i]=='!')
			{w[i]='|';
			i++;
			f.seekg(0,ios::beg);
			goto y;}

		else  if(w[i]==' ')
			{w[i]='!';
			i++;
			f.seekg(0,ios::beg);
			goto y;}


		else if(w[i]==s.getw())
			{f.seekg((-6),ios::cur);
			f.read((char*)&s,sizeof(s));
			w[i]=s.getw();
			i++;
			f.seekg(3,ios::beg);
			goto y;
			}

		else
		{f.seekg(3,ios::cur);}

}
	f.close();
	cout<<"\n";
	cout<<"Decoded Words:"<<w;
	cout<<endl<<"Press Enter 2 Times To Get Back To Main Menu";
	getch();
	break;
	case 2:
	cout<<"\n";
	cout<<"Previous Entries are:-\n";
	cout<<"\n";
	f.open("save",ios::in|ios::binary);
	cout<<"Coded Alphabet"<<"\t"<<"Coded by Level"<<endl;
	while(f.read((char*)&s,sizeof(s)))
		{s.dispsav();
		cout<<endl; }
		f.close();
	cout<<"\n\nInput the code with level no.=\n";
	goto v;
	}
}
void main(){
	int ch;
	clrscr();
	gotoxy(33,6);
	{cout<<"!!!WELCOME!!!";}
	gotoxy(39,7);
	{cout<<"TO";}
	gotoxy(28,8);
	{cout<<"...THE KRYPTOGRAPHER....";}
	gotoxy(25,10);
	{cout<<"*>Press Any Key To View Main Menu";}
	gotoxy(45,20);
	{cout<<"BY:Adarsh Sethi";}
	getch();
	do{
	clrscr();
	cout<<"\t\t<*Main Men*>\n";
	cout<<"*>1-Input Coding/Decoding Database\n*>2-Display Coding/Decoding Database\n";
	cout<<"*>3-Code\n";
	cout<<"*>4-Decode\n";
	cout<<"*>5-To Exit\n";
	cout<<"Select Option:-";
	cin>>ch;
	switch(ch){
		 case 1:
		cout<<"\n";
		clrscr();
		save();
		getch();
		break;
		case 2:
		cout<<"\n";
		clrscr();
		display();
		getch();
		break;
		case 3:
		cout<<"\n";
		clrscr();
		coding();
		getch();
		break;
		case 4:
	cout<<"\n";
	clrscr();
	decode();
	getch();
	break;
	case 5:
	clrscr();
	gotoxy(28,8);
	{cout<<"...*******THANK YOU*******....";
	gotoxy(45,20);
	{cout<<"Please Press Enter!!";}
	getch();
	break;}
  }
   }
  while(ch!=5);
}
