
#define _CRT_SECURE_NO_WARNNINGS
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define H 20
#define W 40
int Snake[H][W], i, j, y, x, Speed =50, Gy, Tail, Head, Game, Cookie, score, a, b, Highscore, mode, mode2, map, fakespeed=5,musiclist=1,mc,mcplay=0,rainbow;
char pos, ch, menu, cho;
FILE *f;
sf::Music music;
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void gotoxy(short x, short y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void namegame()
{
	printf("\n\n\n\n\n\n\n");
	printf("\t\t \333\333\333\333\333\273 \333\333\333\333\333\333\333\273\333\333\333\333\333\333\333\273\333\333\273 \333\333\333\333\333\333\273 \333\333\333\273   \333\333\273    \333\333\333\333\333\333\333\273\333\333\333\273   \333\333\273 \333\333\333\333\333\273 \333\333\273  \333\333\273\333\333\333\333\333\333\333\273\n");
	printf("\t\t\333\333\311\315\315\333\333\273\333\333\311\315\315\315\315\274\333\333\311\315\315\315\315\274\333\333\272\333\333\311\315\315\315\315\274 \333\333\333\333\273  \333\333\272    \333\333\311\315\315\315\315\274\333\333\333\333\273  \333\333\272\333\333\311\315\315\333\333\273\333\333\272 \333\333\311\274\333\333\311\315\315\315\315\274\n");
	printf("\t\t\333\333\333\333\333\333\333\272\333\333\333\333\333\333\333\273\333\333\333\333\333\333\333\273\333\333\272\333\333\272  \333\333\333\273\333\333\311\333\333\273 \333\333\272    \333\333\333\333\333\333\333\273\333\333\311\333\333\273 \333\333\272\333\333\333\333\333\333\333\272\333\333\333\333\333\311\274 \333\333\333\333\333\273  \n");
	printf("\t\t\333\333\311\315\315\333\333\272\310\315\315\315\315\333\333\272\310\315\315\315\315\333\333\272\333\333\272\333\333\272   \333\333\272\333\333\272\310\333\333\273\333\333\272    \310\315\315\315\315\333\333\272\333\333\272\310\333\333\273\333\333\272\333\333\311\315\315\333\333\272\333\333\311\315\333\333\273 \333\333\311\315\315\274  \n");
	printf("\t\t\333\333\272  \333\333\272\333\333\333\333\333\333\333\272\333\333\333\333\333\333\333\272\333\333\272\310\333\333\333\333\333\333\311\274\333\333\272 \310\333\333\333\333\272    \333\333\333\333\333\333\333\272\333\333\272 \310\333\333\333\333\272\333\333\272  \333\333\272\333\333\272  \333\333\273\333\333\333\333\333\333\333\273\n");
	printf("\t\t\310\315\274  \310\315\274\310\315\315\315\315\315\315\274\310\315\315\315\315\315\315\274\310\315\274 \310\315\315\315\315\315\274 \310\315\274  \310\315\315\315\274    \310\315\315\315\315\315\315\274\310\315\274  \310\315\315\315\274\310\315\274  \310\315\274\310\315\274  \310\315\274\310\315\315\315\315\315\315\274");
	printf("\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n");
}
void Menu()
{
	printf("\t\t\t\t\t\t\tSTART GAME\n\n");
	printf("\t\t\t\t\t\t\t   MODE\n\n");
	printf("\t\t\t\t\t\t\t  CREDIT\n\n");
	printf("\t\t\t\t\t\t\t   EXIT");

}
void Menu2()
{
	system("cls");
	namegame();
	printf("\t\t\t\t\t\t\tMAP(IN PROGRESS)\n\n");
	printf("\t\t\t\t\t\t\tSPEED");
	Sleep(100);
}
void About()
{
	char cat = ' ';
	gotoxy(0, 0);
	system("cls");
	namegame();
	printf("\t\t\t\t\t\t\tASSIGN SANKE V2.0 BY WARRAWIT PATANAWANICH");
	while (1)
	{
		if (_kbhit())
			cat = _getch();
		if (cat == '\b')
			break;
	}
}
void speed()
{
	system("cls");
	namegame();
	printf("\t\t\t\t\t\t\tEnter 1-9\n\n");
	printf("\t\t\t\t\t\t\t     ");
	scanf("%d", &fakespeed);
	Speed = 100 - (fakespeed * 10);
	if (fakespeed == 10)
	{
		Speed = 10;
	}
}

void choose()
{
	int cat = 26;
	mode = 1;
	system("cls");
	namegame();
	Menu();
	gotoxy(50, 26);
	printf("%c", 175);
	while (1)
	{
		cho = ' ';
		if (_kbhit())
			cho = _getch();
		if (cho == 's' && mode != 4 && mode == 1)
		{
			gotoxy(50, 26);
			printf(" ");
			mode++;
			gotoxy(50, 28);
			printf("%c", 175);
			cat += 2;
		}
		else  if (cho == 's' && mode != 4 && mode == 2)
		{
			gotoxy(50, 28);
			printf(" ");
			mode++;
			gotoxy(50, 30);
			printf("%c", 175);
			cat += 2;
		}
		else if (cho == 's' && mode != 4 && mode == 3)
		{
			gotoxy(50, 30);
			printf(" ");
			mode++;
			gotoxy(50, 32);
			printf("%c", 175);
			cat += 2;
		}
		if (cho == 'w' && mode != 1 && mode == 4)
		{
			gotoxy(50, 32);
			printf(" ");
			mode--;
			gotoxy(50, 30);
			printf("%c", 175);
			cat -= 2;
		}
		else if (cho == 'w' && mode != 1 && mode == 3)
		{
			gotoxy(50, 30);
			printf(" ");
			mode--;
			gotoxy(50, 28);
			printf("%c", 175);
			cat -= 2;
		}
		else if (cho == 'w' && mode != 1 && mode == 2)
		{
			gotoxy(50, 28);
			printf(" ");
			mode--;
			gotoxy(50, 26);
			printf("%c", 175);
			cat -= 2;
		}
		if (cho == 13)
			break;
		gotoxy(50, cat);
		printf(" ");
		Sleep(100);
		gotoxy(50, cat);
		printf("%c", 175);
		Sleep(50);
	}
}
void choose2()
{
	mode2 = 1;
	gotoxy(50, 26);
	printf("%c", 175);
	while (1) {
		cho = ' ';
		if (_kbhit())
			cho = _getch();
		if (cho == 's' && mode2 != 2)
		{
			gotoxy(50, 26);
			printf(" ");
			mode2++;
			gotoxy(50, 28);
			printf("%c", 175);
		}
		if (cho == 'w' && mode2 != 1)
		{
			gotoxy(50, 28);
			printf(" ");
			mode2--;
			gotoxy(50, 26);
			printf("%c", 175);

		}
		if (cho == 13&&mode2 == 2)
		{
			speed();
			Menu2();
		}
		if (cho == '\b')
		{
			system("cls");
			namegame();
			Menu();
			choose();
			break;
		}
		Sleep(100);
	}
}

void ResetScreenPosition()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void SnakeInitialization()
{
	f = fopen("high.txt", "r");
	fscanf(f, "%d   ", &Highscore);
	fclose(f);
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			Snake[i][j] = 0;
		}
	}
	y = H / 2; x = W / 2; Head = 5; score = 0; Tail = 1; Cookie = 0; Gy = x; pos = 'd'; Game = 0;
	for (i = 0; i < Head; i++)
	{
		Gy++;
		Snake[y][Gy - Head] = i + 1;
	}
}
void TailRemove()
{
	for (i = 0; i < H; i++)
		for (j = 0; j < W; j++)
			if (Snake[i][j] == Tail)
				Snake[i][j] = 0;
	Tail++;
}

int getch_noblock()
{
	if (_kbhit())
		return _getch();
	else
		return -1;
}

void Random()
{
	a = 1 + rand() % 17;
	b = 1 + rand() % 37;
	if (Cookie == 0 && Snake[a][b] == 0)
	{
		Snake[a][b] = -1;
		Cookie = 1;
		//if (Speed > 10 && score != 0) Speed-=10;
	}

}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void Printall()
{
	rainbow++;
	printf(" SCORE: %d   HIGHSCORE: %d    SPEED : %d", score, Highscore, Speed);
	printf("\n");

	for (i = 0; i <= W + 1; i++)
	{
		if (Snake[i][j] == 0 && fakespeed == 10)
		{
			if (rainbow == 15)
				rainbow = 1;
			setcolor(rainbow, 0);
		}
		if (i == 0) printf("%c", 201);
		else if (i == W + 1) printf("%c", 187);
		else printf("%c", 205);
	}
	printf("\n");
	for (i = 0; i < H; i++)
	{
		printf("%c", 186);
		for (j = 0; j < W; j++)
		{
		   
			if (Snake[i][j] == 0)  printf(" ");
			if (Snake[i][j] > 0 && Snake[i][j] != Head)
				printf("%c", 176);
			if (Snake[i][j] == Head)

				printf("%c", 178);
			if (Snake[i][j] == -1)  printf("%c", 15);
			if (j == W - 1) printf("%c\n", 186);
		}
	}

	for (i = 0; i <= W + 1; i++)
	{

		if (i == 0) printf("%c", 200);
		else if (i == W + 1) printf("%c", 188);
		else printf("%c", 205);
	}
}

void GameOver()
{
	printf("\a");
	Sleep(1500);
	system("Cls");
	if (score>Highscore)
	{
		printf("\n\n                                NEW HIGHSCORE %d!!!\n\n", score);
		system("pause");
		f = fopen("high.txt", "w");
		fprintf(f, "%d   ", score);
		fclose(f);
	}
	system("Cls");
	printf("\n\n                                 GAME OVER!!! \n\n");
	printf("                                   SCORE: %d \n\n", score);
	printf("                   PRESS ENTER TO PLAY AGAIN OR ESC TO MENU... \n");

	while (1)
	{
		ch = getch_noblock();
		if (ch == 13)
		{
			Game = 0;
			SnakeInitialization();
			break;
		}
		else if (ch == 27)
		{  
			Game = 1;
			music.openFromFile("music/TEM Shop.flac");
			music.play();
			break;
		}
	}
	system("Cls");
}

void Position()
{
	ch = getch_noblock();
	ch = tolower(ch);
	if (((ch == 'd' || ch == 'a') || (ch == 'w' || ch == 's')) && (abs(pos - ch) > 5)) pos = ch;
	if (pos == 'd')
	{
		x++;
		if (x == W) x = 0;
		if (Snake[y][x] != 0 && Snake[y][x] != -1) GameOver();
		if (Snake[y][x] == -1)
		{
			Tail--;
			score = score + fakespeed;
			Cookie = 0;
		}
		Head++;
		Snake[y][x] = Head;
	}

	if (pos == 'a')
	{
		x--;
		if (x == -1) x = W - 1;
		if (Snake[y][x] != 0 && Snake[y][x] != -1) GameOver();
		if (Snake[y][x] == -1)
		{
			Tail--;
			Tail--;
			score = score + fakespeed;
			Cookie = 0;
		}
		Head++;
		Snake[y][x] = Head;
	}

	if (pos == 'w')
	{
		y--;
		if (y == -1) y = H - 1;
		if (Snake[y][x] != 0 && Snake[y][x] != -1) GameOver();
		if (Snake[y][x] == -1)
		{
			Tail--;
			Tail--;
			score = score + fakespeed;
			Cookie = 0;
		}
		Head++;
		Snake[y][x] = Head;
	}

	if (pos == 's')
	{
		y++;
		if (y == H) y = 0;
		if (Snake[y][x] != 0 && Snake[y][x] != -1) GameOver();
		if (Snake[y][x] == -1)
		{
			Tail--;
			Tail--;
			score = score + fakespeed;
			Cookie = 0;
		}
		Head++;
		Snake[y][x] = Head;
	}
}
void song()
{
		if (ch == '.' || ch == ',')
		{
				musiclist++;
				if (musiclist == 5)
					musiclist = 1;
			if (musiclist == 1)
			{
				system("color A");
				gotoxy(50, 0);
				printf("Hopes and Dreams           ");
				music.openFromFile("music/Hopes and Dreams.flac");
				music.play();
				gotoxy(0, 0);
			}
			else if (musiclist == 2)
			{
				system("color B");
				gotoxy(50, 0);
				printf("Tem Shop            ");
				music.openFromFile("music/Tem Shop.flac");
				music.play();
				gotoxy(0, 0);
			}
			else if (musiclist == 3)
			{
				system("color C");
				gotoxy(50, 0);
				printf("NGAHHHH!!          ");
				music.openFromFile("music/NGAHHH!!.flac");
				music.play();
				gotoxy(0, 0);
			}
			else if (musiclist == 4)
			{
				gotoxy(50, 0);
				printf("MEGALOVANIA           ");
				system("color D");
				music.openFromFile("music/MEGALOVANIA.flac");
				music.play();
				gotoxy(0, 0);
			}
		}
	}
int main()
{

	int ch = 0;
	hidecursor();
	system("MODE 120 ,40");
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	system("color A");
	music.setLoop(true);
	music.openFromFile("music/TEM Shop.flac");
	music.play();
	while (1)
	{
		choose();
		while (mode != 1) {

			if (mode == 2)
			{
				Menu2();
				choose2();
			}
			if (mode == 3)
			{
				About();
				choose();
			}
		if (mode == 4)
		{
			return 0;
		}
	}
		system("Cls");
		SnakeInitialization();
		music.openFromFile("music/Hopes and Dreams.flac");
		music.play();
		while (Game == 0)
		{
		
			
			song();
			Printall();
			Random();
			Position();
			TailRemove();
			Sleep(Speed);
			ResetScreenPosition();
		}
	}
	return 0;
}
