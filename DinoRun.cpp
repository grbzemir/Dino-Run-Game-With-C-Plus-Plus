#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>

#define dinoPozisyon 2
#define kaktusPozisyonu 74

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition; // Kordinatlari tutan degiskendir

int DinoY;
int hiz = 40;
int gameover = 0;

void gotoxy(int x , int y)

{

    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);

}


void setcursor(bool visible, DWORD size)

{

    if(size == 0)

        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;

    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;

    SetConsoleCursorInfo(console,&lpCursor);

}

void giris()

{

    system("cls");
    gameover = 0;
    gotoxy(3,2);
    cout<<"Score: ";

    for(int i=0;i<79;i++)

    {

        gotoxy(1+i,1);
        cout<<"B";
        gotoxy(1+i,25);
        cout<<"B";

    }

}

void HareketEtDino(int zipla = 0)

{

    static int ayak = 0;

    if(zipla == 0)

    DinoY = 0;

    else if(zipla == 2)

    DinoY--;
    
    else DinoY++;

    gotoxy(dinoPozisyon, 15 - DinoY);     cout<<"                 "; 
    gotoxy(dinoPozisyon, 16 - DinoY);     cout<<"         ÜÛßÛÛÛÛÜ";
    gotoxy(dinoPozisyon, 17 - DinoY);     cout<<"         ÛÛÛÛÛÛÛÛ";
    gotoxy(dinoPozisyon, 18 - DinoY);     cout<<"         ÛÛÛÛÛßßß";
    gotoxy(dinoPozisyon, 19 - DinoY);     cout<<" Û      ÜÛÛÛÛßßß ";
    gotoxy(dinoPozisyon, 20 - DinoY);     cout<<" ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ";
    gotoxy(dinoPozisyon, 21 - DinoY);     cout<<" ßÛÛÛÛÛÛÛÛÛÛÛ  ß ";
    gotoxy(dinoPozisyon, 22 - DinoY);     cout<<"   ßÛÛÛÛÛÛÛß     ";
    gotoxy(dinoPozisyon, 23 - DinoY);

    if (zipla == 1 || zipla == 2) 
  
    {

        cout<<"    ÛÛß ßÛ       ";
        gotoxy(2, 24 - DinoY);
        cout<<"    ÛÜ   ÛÜ      ";

    } 

	else if (ayak == 0) 
    
    {
        cout<<"    ßÛÛß  ßßß    ";
        gotoxy(2, 24 - DinoY); // Dinonun nerede olacagýný belirler
        cout<<"      ÛÜ         ";
        ayak = !ayak; // ayak degiskeni 0 ise 1, 1 ise 0 olur
    
    }

	else if (ayak == 1) 

    {
        cout<<"     ßÛÜ ßÛ      "; 
        gotoxy(2, 24 - DinoY); // Dinonun nerede olacagýný belirler
        cout<<"          ÛÜ     ";
        ayak = !ayak;

    }

    gotoxy(2,25 -DinoY);

    if(zipla == 0)

    {

     cout<<"BBBBBBBBBBBB";

    }

    else   

    {

        cout<<"                ";

    }

    Sleep(hiz);



}

void KaktusCiz()

{

    static int plantX = 0 ;
    static int score = 0;

    if(plantX == 56 && DinoY == 0)

    {
        
        score = 0;
        hiz = 40;
        gotoxy(36,8);
        cout<<"Game Over";
        getch();
        gameover = 1;


    }

    gotoxy(kaktusPozisyonu - plantX, 20);
    cout<<"| | ";
    gotoxy(kaktusPozisyonu - plantX, 21);
    cout<<"| | ";
    gotoxy(kaktusPozisyonu - plantX, 22);
    cout<<"|_| ";
    gotoxy(kaktusPozisyonu - plantX, 23);
    cout<<" | ";
    gotoxy(kaktusPozisyonu - plantX, 24);
    cout<<" | ";

    plantX++;

    if(plantX == 73)

    {
        plantX = 0;
        score++;
        gotoxy(11,2);
        cout<<"     ";
        gotoxy(11,2);
        cout<<score;

        if(hiz > 20)

        hiz--;

    }


}


void Oyna()

{ 

	system("cls");
    char ch;
    int i;
	giris();

    while (true) 
    
    {

        while (!kbhit()) 
        
        {
            if( gameover==1 )
            
            {

            	return;
			}

			HareketEtDino();
            KaktusCiz();
        
        }

        ch = getch();

        if (ch == 32) 
        
        {
        	i = 0;

            while( i < 12) 
            
            {
                HareketEtDino(1);
                KaktusCiz();
                i++;

            }


            while(i > 0) 
            
            {
                HareketEtDino(2);
                KaktusCiz();
                i--;

        	}
            
        }

		else if (ch == 'p'||ch=='P')

           getch();

		else if (ch == 27)

           break;

    }

}


void Bilgiler() 

{
	system("cls");
	cout<<"Bilgiler";
	cout<<"\n----------------";
	cout<<"\n1.Kaktus Uzerinden Atlamaya Calisin";
	cout<<"\n2.'Space' Zipmanizi Saglar";
	cout<<"\n3.'P' Basarsaniz Oyunu Durdurur";
	cout<<"\n4.'Esc' Basarsaniz Oyundan Cikar";
	cout<<"\n\nMenuye Donmek Icin Herhangi Bir Tusa Basiniz...";
	getch();

}


int main() 

{
    
    system("color 4");
    setcursor(0, 0);
    
    do
    
    {
		system("cls");
		gotoxy(10,5); 
        cout<<" -------------------------- "; 
		gotoxy(10,6); 
        cout<<" |        DINO RUN        | ";  
		gotoxy(10,7); 
        cout<<" -------------------------- ";
		gotoxy(10,9); 
        cout<<"1. Start Game";
		gotoxy(10,10); 
        cout<<"2. Instructions";	 
		gotoxy(10,11); 
        cout<<"3. Quit";
		gotoxy(10,13); 
        cout<<"Seciminiz: ";
		char secim = getche();
		
		if( secim=='1') 
        Oyna();

		else if( secim=='2') 
        Bilgiler();

		else if( secim=='3') 
        exit(0);
		
	}


    while(1);
    
	return 0;
}


