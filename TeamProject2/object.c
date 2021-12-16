// 게임 오브젝트

#include <stdio.h>
#include <windows.h>

void GotoXY(int _x, int _y){
	COORD pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//색상
enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

// 콘솔 텍스트 색상 변경해주는 함수
void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

// 타이틀
void Title(int x, int y)
{
	setColor(VIOLET);
	GotoXY(x, y - 1);
	printf("                            ■                         ■                                        ■            ■          ■                        ■");
	GotoXY(x, y);
	printf("  ■      ■          ■    ■         ■■■■■■    ■                  ■■■■■■■■■    ■    ■■■■■■■■■  ■        ■■■■■■    ■");
	GotoXY(x, y + 1); 
	printf("■■      ■          ■    ■         ■        ■    ■                      ■      ■        ■          ■■■        ■                  ■    ■");
	GotoXY(x, y + 2);
	printf("  ■      ■■■■■■■    ■■■     ■        ■    ■                      ■      ■        ■        ■      ■      ■                  ■    ■");
	GotoXY(x, y + 3);
	printf("  ■      ■          ■    ■         ■        ■    ■                      ■      ■        ■        ■      ■      ■■■              ■    ■");
	GotoXY(x, y + 4);
	printf("  ■      ■          ■    ■         ■        ■    ■                      ■      ■        ■        ■      ■      ■                  ■    ■");
	GotoXY(x, y + 5);
	printf("  ■      ■■■■■■■    ■         ■■■■■■    ■                  ■■■■■■■■■    ■          ■■■        ■                  ■    ■");
	GotoXY(x, y + 6);
	printf("  ■                        ■                         ■                                        ■                        ■                        ■");
	GotoXY(x, y + 7);
	printf("  ■          ■                             ■■■■■■                                        ■                        ■                        ■");
	GotoXY(x, y + 8);
	printf("  ■          ■                             ■        ■");
	GotoXY(x, y + 9);
	printf("  ■          ■                             ■        ■");
	GotoXY(x, y + 10);
	printf("■■■        ■■■■■■■■               ■■■■■■");
	setColor(WHITE);

}

// 메뉴
void Cursor_dlt(int x, int y)
{
	GotoXY(x, y);
	printf("  ");
	GotoXY(x, y + 1);
	printf("    ");
	GotoXY(x, y + 2);
	printf("     ");
	GotoXY(x, y + 3);
	printf("    ");
	GotoXY(x, y + 4);
	printf("  ");
}
void Cursor(int x, int y)
{
	GotoXY(x, y);
	printf("@@");
	GotoXY(x, y + 1);
	printf(" @@@");
	GotoXY(x, y + 2);
	printf("   @@");
	GotoXY(x, y + 3);
	printf(" @@@");
	GotoXY(x, y + 4);
	printf("@@");
}

void Menu(int x, int y)
{
	setColor(VIOLET);
	GotoXY(x, y);
	printf("■■■■■  ■■■■■    ■■■    ■■■■■  ■■■■■");
	GotoXY(x, y + 1);
	printf("■      ■  ■  ■  ■  ■■  ■■  ■      ■  ■  ■  ■");
	GotoXY(x, y + 2);
	printf("■■■          ■      ■      ■  ■■■■■      ■");
	GotoXY(x, y + 3);
	printf("    ■■■      ■      ■■■■■  ■■            ■");
	GotoXY(x, y + 4);
	printf("■      ■      ■      ■      ■  ■  ■■        ■");
	GotoXY(x, y + 5);
	printf("■■■■■      ■      ■      ■  ■     ■■     ■");
	GotoXY(x, y + 6);
	printf("");
	GotoXY(x, y + 7);
	printf("");
	GotoXY(x, y + 8);
	printf("■■■■■    ■■■    ■      ■  ■    ■■");
	GotoXY(x, y + 9);
	printf("■      ■  ■■  ■■  ■■    ■  ■  ■■");
	GotoXY(x, y + 10);
	printf("■■■■■  ■      ■  ■■■  ■  ■■■");
	GotoXY(x, y + 11);
	printf("■■        ■■■■■  ■  ■■■  ■■■");
	GotoXY(x, y + 12);
	printf("■  ■■    ■      ■  ■    ■■  ■  ■■");
	GotoXY(x, y + 13);
	printf("■    ■■  ■      ■  ■      ■  ■    ■■");
	GotoXY(x, y + 14);
	printf("");
	GotoXY(x, y + 15);
	printf("");
	GotoXY(x, y + 16);
	printf("■■■■■  ■      ■  ■■■  ■■■■■");
	GotoXY(x, y + 17);
	printf("■          ■■  ■■    ■        ■");
	GotoXY(x, y + 18);
	printf("■■■■      ■■■      ■        ■");
	GotoXY(x, y + 19);
	printf("■■■■        ■        ■        ■");
	GotoXY(x, y + 20);
	printf("■            ■  ■      ■        ■");
	GotoXY(x, y + 21);
	printf("■■■■■  ■      ■  ■■■      ■");
	setColor(WHITE);
}

// 게임오버 
void GO(int x, int y)
{
	GotoXY(x, y);
	printf("□□□□□    □□□    □      □  □□□□□        □□□    □      □  □□□□□  □□□□□");
	GotoXY(x, y + 1);
	printf("□      □  □□  □□  □□  □□  □              □□  □□  □      □  □          □      □");
	GotoXY(x, y + 2);
	printf("□          □      □  □□□□□  □□□□        □      □  □      □  □□□□    □□□□□");
	GotoXY(x, y + 3);
	printf("□  □□□  □□□□□  □  □  □  □□□□        □      □  □□  □□  □□□□    □□");
	GotoXY(x, y + 4);
	printf("□      □  □      □  □  □  □  □              □□  □□    □□□    □          □  □□");
	GotoXY(x, y + 5);	
	printf("□□□□□  □      □  □      □  □□□□□        □□□        □      □□□□□  □    □□");
}

// 랭킹
void Rank(int x, int y)
{
	GotoXY(x, y - 5);
	printf("■■■■■    ■■■    ■      ■  ■    ■■");
	GotoXY(x, y - 4);
	printf("■      ■  ■■  ■■  ■■    ■  ■  ■■");
	GotoXY(x, y - 3);
	printf("■■■■■  ■      ■  ■■■  ■  ■■■");
	GotoXY(x, y - 2);
	printf("■■        ■■■■■  ■  ■■■  ■■■");
	GotoXY(x, y - 1);
	printf("■  ■■    ■      ■  ■    ■■  ■  ■■");
	GotoXY(x, y);
	printf("■    ■■  ■      ■  ■      ■  ■    ■■");
}

// 숫자
void Number(int x, int y, int num)
{
	switch (num)
	{
	case 11:
		GotoXY(x, y - 5);
		printf("  ■■");
		GotoXY(x, y - 4);
		printf("    ■");
		GotoXY(x, y - 3);
		printf("    ■");
		GotoXY(x, y - 2);
		printf("    ■");
		GotoXY(x, y - 1);
		printf("    ■");
		GotoXY(x, y );
		printf("  ■■■  ■");
		break;
	case 12:
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("      ■■");
		GotoXY(x, y - 2);
		printf("    ■■");
		GotoXY(x, y - 1);
		printf("  ■■");
		GotoXY(x, y);
		printf("■■■■■  ■");
		break;
	case 13:
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("    ■■■");
		GotoXY(x, y - 2);
		printf("    ■■■");
		GotoXY(x, y - 1);
		printf("■      ■");
		GotoXY(x, y);
		printf("■■■■■  ■");
		break;
	case 0:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□      □");
		GotoXY(x, y + 2);
		printf("□      □");
		GotoXY(x, y + 3);
		printf("□      □");
		GotoXY(x, y + 4);
		printf("□      □");
		GotoXY(x, y + 5);
		printf("□□□□□");
		break;
	case 1:
		GotoXY(x, y);
		printf("  □□");
		GotoXY(x, y + 1);
		printf("    □");
		GotoXY(x, y + 2);
		printf("    □");
		GotoXY(x, y + 3);
		printf("    □");
		GotoXY(x, y + 4);
		printf("    □");
		GotoXY(x, y + 5);
		printf("  □□□");
		break;
	case 2:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□      □");
		GotoXY(x, y + 2);
		printf("      □□");
		GotoXY(x, y + 3);
		printf("    □□");
		GotoXY(x, y + 4);
		printf("  □□");
		GotoXY(x, y + 5);
		printf("□□□□□");
		break;
	case 3:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□      □");
		GotoXY(x, y + 2);
		printf("    □□□");
		GotoXY(x, y + 3);
		printf("    □□□");
		GotoXY(x, y + 4);
		printf("□      □");
		GotoXY(x, y + 5);
		printf("□□□□□");
		break;
	case 4:
		GotoXY(x, y);
		printf("    □□");
		GotoXY(x, y + 1);
		printf("  □□□");
		GotoXY(x, y + 2);
		printf("□□  □");
		GotoXY(x, y + 3);
		printf("□    □");
		GotoXY(x, y + 4);
		printf("□□□□□");
		GotoXY(x, y + 5);
		printf("      □");
		break;
	case 5:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□");
		GotoXY(x, y + 2);
		printf("□□□□□");
		GotoXY(x, y + 3);
		printf("        □");
		GotoXY(x, y + 4);
		printf("      □□");
		GotoXY(x, y + 5);
		printf("□□□□");
		break;
	case 6:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□");
		GotoXY(x, y + 2);
		printf("□□□□□");
		GotoXY(x, y + 3);
		printf("□      □");
		GotoXY(x, y + 4);
		printf("□      □");
		GotoXY(x, y + 5);
		printf("□□□□□");
		break;
	case 7:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□      □");
		GotoXY(x, y + 2);
		printf("      □□");
		GotoXY(x, y + 3);
		printf("    □□");
		GotoXY(x, y + 4);
		printf("    □");
		GotoXY(x, y + 5);
		printf("    □");
		break;
	case 8:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□      □");
		GotoXY(x, y + 2);
		printf("□      □");
		GotoXY(x, y + 3);
		printf("□□□□□");
		GotoXY(x, y + 4);
		printf("□      □");
		GotoXY(x, y + 5);
		printf("□□□□□");
		break;
	case 9:
		GotoXY(x, y);
		printf("□□□□□");
		GotoXY(x, y + 1);
		printf("□      □");
		GotoXY(x, y + 2);
		printf("□      □");
		GotoXY(x, y + 3);
		printf("□□□□□");
		GotoXY(x, y + 4);
		printf("        □");
		GotoXY(x, y + 5);
		printf("□□□□□");
		break;
	}
}



	
// ABCD
void ABCD(int x, int y, char s) {
	switch (s)
	{
	case':':
		GotoXY(x, y - 5);
		printf("");
		GotoXY(x, y - 4);
		printf("●");
		GotoXY(x, y - 3);
		printf("");
		GotoXY(x, y - 2);
		printf("");
		GotoXY(x, y - 1);
		printf("●");
		GotoXY(x, y);
		printf("");
		break;
	case 's':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■■■");
		GotoXY(x, y - 2);
		printf("    ■■■");
		GotoXY(x, y - 1);
		printf("        ■");
		GotoXY(x, y);
		printf("■■■■■");
		break;
	case 'a':
		GotoXY(x, y - 5);
		printf("  ■■■");
		GotoXY(x, y - 4);
		printf("■■  ■■");
		GotoXY(x, y - 3);
		printf("■      ■");
		GotoXY(x, y - 2);
		printf("■■■■■");
		GotoXY(x, y - 1);
		printf("■      ■");
		GotoXY(x, y);
		printf("■      ■");
		break;

	case 'b':
		GotoXY(x, y - 5);
		printf("■■■■");
		GotoXY(x, y - 4);
		printf("■    ■");
		GotoXY(x, y - 3);
		printf("■    ■");
		GotoXY(x, y - 2);
		printf("■■■■■");
		GotoXY(x, y - 1);
		printf("■      ■");
		GotoXY(x, y);
		printf("■■■■■");
		break;
	case 'c':
		GotoXY(x, y - 5);
		printf("  ■■■■");
		GotoXY(x, y - 4);
		printf("■■    ■");
		GotoXY(x, y - 3);
		printf("■");
		GotoXY(x, y - 2);
		printf("■");
		GotoXY(x, y - 1);
		printf("■■    ■");
		GotoXY(x, y);
		printf("  ■■■■");
		break;
	case 'd':
		GotoXY(x, y - 5);
		printf("■■■■");
		GotoXY(x, y - 4);
		printf("■    ■■");
		GotoXY(x, y - 3);
		printf("■      ■");
		GotoXY(x, y - 2);
		printf("■      ■");
		GotoXY(x, y - 1);
		printf("■    ■■");
		GotoXY(x, y);
		printf("■■■■");
		break;
	case'e':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■");
		GotoXY(x, y - 3);
		printf("■■■■");
		GotoXY(x, y - 2);
		printf("■■■■");
		GotoXY(x, y - 1);
		printf("■");
		GotoXY(x, y);
		printf("■■■■■");
		break;
	case 'f':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■");
		GotoXY(x, y - 3);
		printf("■■■■");
		GotoXY(x, y - 2);
		printf("■■■■");
		GotoXY(x, y - 1);
		printf("■");
		GotoXY(x, y);
		printf("■");
		break;
	case 'g':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■");
		GotoXY(x, y - 2);
		printf("■  ■■■");
		GotoXY(x, y - 1);
		printf("■      ■");
		GotoXY(x, y);
		printf("■■■■■");
		break;
	case 'h':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■■■■■");
		GotoXY(x, y - 2);
		printf("■■■■■");
		GotoXY(x, y - 1);
		printf("■      ■");
		GotoXY(x, y);
		printf("■      ■");
		break;
	case 'i':
		GotoXY(x, y - 5);
		printf("  ■■■");
		GotoXY(x, y - 4);
		printf("    ■");
		GotoXY(x, y - 3);
		printf("    ■");
		GotoXY(x, y - 2);
		printf("    ■");
		GotoXY(x, y - 1);
		printf("    ■");
		GotoXY(x, y);
		printf("  ■■■");
		break;
	case 'j':
		GotoXY(x, y - 5);
		printf("    ■■■");
		GotoXY(x, y - 4);
		printf("        ■");
		GotoXY(x, y - 3);
		printf("        ■");
		GotoXY(x, y - 2);
		printf("■      ■");
		GotoXY(x, y - 1);
		printf("■■  ■■");
		GotoXY(x, y);
		printf("  ■■■");
		break;
	case 'k':
		GotoXY(x, y - 5);
		printf("■    ■■");
		GotoXY(x, y - 4);
		printf("■  ■■");
		GotoXY(x, y - 3);
		printf("■■■");
		GotoXY(x, y - 2);
		printf("■■■");
		GotoXY(x, y - 1);
		printf("■  ■■");
		GotoXY(x, y);
		printf("■    ■■");
		break;
	case 'l':
		GotoXY(x, y - 5);
		printf("■");
		GotoXY(x, y - 4);
		printf("■");
		GotoXY(x, y - 3);
		printf("■");
		GotoXY(x, y - 2);
		printf("■");
		GotoXY(x, y - 1);
		printf("■");
		GotoXY(x, y);
		printf("■■■■■");
		break;
	case 'm':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■■  ■■");
		GotoXY(x, y - 3);
		printf("■■■■■");
		GotoXY(x, y - 2);
		printf("■  ■  ■");
		GotoXY(x, y - 1);
		printf("■  ■  ■");
		GotoXY(x, y);
		printf("■      ■");
		break;
	case 'n':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■■    ■");
		GotoXY(x, y - 3);
		printf("■■■  ■");
		GotoXY(x, y - 2);
		printf("■  ■■■");
		GotoXY(x, y - 1);
		printf("■    ■■");
		GotoXY(x, y);
		printf("■      ■");
		break;
	case 'o':
		GotoXY(x, y - 5);
		printf("  ■■■");
		GotoXY(x, y - 4);
		printf("■■  ■■");
		GotoXY(x, y - 3);
		printf("■      ■");
		GotoXY(x, y - 2);
		printf("■      ■");
		GotoXY(x, y - 1);
		printf("■■  ■■");
		GotoXY(x, y);
		printf("  ■■■");
		break;
	case 'p':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■      ■");
		GotoXY(x, y - 2);
		printf("■■■■■");
		GotoXY(x, y - 1);
		printf("■");
		GotoXY(x, y);
		printf("■");
		break;
	case 'q':
		GotoXY(x, y - 5);
		printf("  ■■■");
		GotoXY(x, y - 4);
		printf("■■  ■■");
		GotoXY(x, y - 3);
		printf("■      ■");
		GotoXY(x, y - 2);
		printf("■  ■  ■");
		GotoXY(x, y - 1);
		printf("■■  ■");
		GotoXY(x, y);
		printf("  ■■  ■");
		break;
	case 'r':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■■■■■");
		GotoXY(x, y - 2);
		printf("■■");
		GotoXY(x, y - 1);
		printf("■  ■■");
		GotoXY(x, y);
		printf("■    ■■");
		break;
	case 't':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("■  ■  ■");
		GotoXY(x, y - 3);
		printf("    ■");
		GotoXY(x, y - 2);
		printf("    ■");
		GotoXY(x, y - 1);
		printf("    ■");
		GotoXY(x, y);
		printf("    ■");
		break;
	case 'u':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■      ■");
		GotoXY(x, y - 2);
		printf("■      ■");
		GotoXY(x, y - 1);
		printf("■■  ■■");
		GotoXY(x, y);
		printf("  ■■■");
		break;
	case 'v':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■      ■");
		GotoXY(x, y - 2);
		printf("■■  ■■");
		GotoXY(x, y - 1);
		printf("  ■■■");
		GotoXY(x, y);
		printf("    ■");
		break;
	case 'w':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■  ■  ■");
		GotoXY(x, y - 3);
		printf("■  ■  ■");
		GotoXY(x, y - 2);
		printf("■  ■  ■");
		GotoXY(x, y - 1);
		printf("■■■■■");
		GotoXY(x, y);
		printf("  ■  ■");
		break;
	case 'x':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■■  ■■");
		GotoXY(x, y - 3);
		printf("  ■■■");
		GotoXY(x, y - 2);
		printf("    ■");
		GotoXY(x, y - 1);
		printf("  ■  ■");
		GotoXY(x, y);
		printf("■      ■");
		break;
	case 'y':
		GotoXY(x, y - 5);
		printf("■      ■");
		GotoXY(x, y - 4);
		printf("■      ■");
		GotoXY(x, y - 3);
		printf("■■  ■■");
		GotoXY(x, y - 2);
		printf("  ■■■");
		GotoXY(x, y - 1);
		printf("    ■");
		GotoXY(x, y);
		printf("    ■");
		break;
	case 'z':
		GotoXY(x, y - 5);
		printf("■■■■■");
		GotoXY(x, y - 4);
		printf("      ■■");
		GotoXY(x, y - 3);
		printf("    ■■");
		GotoXY(x, y - 2);
		printf("  ■■");
		GotoXY(x, y - 1);
		printf("■■");
		GotoXY(x, y);
		printf("■■■■■");
		break;
	case '0':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□      □");
		GotoXY(x, y - 3);
		printf("□      □");
		GotoXY(x, y - 2);
		printf("□      □");
		GotoXY(x, y - 1);
		printf("□      □");
		GotoXY(x, y);
		printf("□□□□□");
		break;
	case '1':
		GotoXY(x, y - 5);
		printf("  □□");
		GotoXY(x, y - 4);
		printf("    □");
		GotoXY(x, y - 3);
		printf("    □");
		GotoXY(x, y - 2);
		printf("    □");
		GotoXY(x, y - 1);
		printf("    □");
		GotoXY(x, y);
		printf("  □□□");
		break;
	case '2':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□      □");
		GotoXY(x, y - 3);
		printf("      □□");
		GotoXY(x, y - 2);
		printf("    □□");
		GotoXY(x, y - 1);
		printf("  □□");
		GotoXY(x, y);
		printf("□□□□□");
		break;
	case '3':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□      □");
		GotoXY(x, y - 3);
		printf("    □□□");
		GotoXY(x, y - 2);
		printf("    □□□");
		GotoXY(x, y - 1);
		printf("□      □");
		GotoXY(x, y );
		printf("□□□□□");
		break;
	case '4':
		GotoXY(x, y - 5);
		printf("    □□");
		GotoXY(x, y - 4);
		printf("  □□□");
		GotoXY(x, y - 3);
		printf("□□  □");
		GotoXY(x, y - 2);
		printf("□    □");
		GotoXY(x, y - 1);
		printf("□□□□□");
		GotoXY(x, y);
		printf("      □");
		break;
	case '5':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□");
		GotoXY(x, y - 3);
		printf("□□□□□");
		GotoXY(x, y - 2);
		printf("        □");
		GotoXY(x, y - 1);
		printf("      □□");
		GotoXY(x, y);
		printf("□□□□");
		break;
	case '6':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□");
		GotoXY(x, y - 3);
		printf("□□□□□");
		GotoXY(x, y - 2);
		printf("□      □");
		GotoXY(x, y - 1);
		printf("□      □");
		GotoXY(x, y);
		printf("□□□□□");
		break;
	case '7':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□      □");
		GotoXY(x, y - 3);
		printf("      □□");
		GotoXY(x, y - 2);
		printf("    □□");
		GotoXY(x, y - 1);
		printf("    □");
		GotoXY(x, y );
		printf("    □");
		break;
	case '8':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□      □");
		GotoXY(x, y - 3);
		printf("□      □");
		GotoXY(x, y - 2);
		printf("□□□□□");
		GotoXY(x, y -1 );
		printf("□      □");
		GotoXY(x, y );
		printf("□□□□□");
		break;
	case '9':
		GotoXY(x, y - 5);
		printf("□□□□□");
		GotoXY(x, y - 4);
		printf("□      □");
		GotoXY(x, y - 3);
		printf("□      □");
		GotoXY(x, y - 2);
		printf("□□□□□");
		GotoXY(x, y - 1);
		printf("        □");
		GotoXY(x, y);
		printf("□□□□□");
		break;
	default:
		break;
	}
}

void ABCD_dlt(int x, int y) {
	GotoXY(x, y - 5);
	printf("          ");
	GotoXY(x, y - 4);
	printf("          ");
	GotoXY(x, y - 3);
	printf("          ");
	GotoXY(x, y - 2);
	printf("          ");
	GotoXY(x, y - 1);
	printf("          ");
	GotoXY(x, y);
	printf("          ");
}
//---------------
// 오브젝트
//---------------

// 빼빼로 막대
void Ppr_stick(int x, int y)
{
	setColor(YELLOW);
	GotoXY(x, y - 12);
	printf("■");
	GotoXY(x, y - 11);
	printf("■");
	GotoXY(x, y - 10);
	printf("■");
	GotoXY(x, y - 9);
	printf("■");
	setColor(DAKR_YELLOW);
	GotoXY(x, y - 8);
	printf("■");
	GotoXY(x, y - 7);
	printf("■");
	GotoXY(x, y - 6);
	printf("■");
	GotoXY(x, y - 5);
	printf("■");
	GotoXY(x, y - 4);
	printf("■");
	GotoXY(x, y - 3);
	printf("■");
	GotoXY(x, y - 2);
	printf("■");
	GotoXY(x, y - 1);
	printf("■");
	GotoXY(x, y);
	printf("■");
	setColor(WHITE);
}

void Ppr_stick_dlt(int x, int y)
{
	GotoXY(x, y - 12);
	printf("  ");
	GotoXY(x, y - 11);
	printf("  ");
	GotoXY(x, y - 10);
	printf("  ");
	GotoXY(x, y - 9);
	printf("  ");
	GotoXY(x, y - 8);
	printf("  ");
	GotoXY(x, y - 7);
	printf("  ");
	GotoXY(x, y - 6);
	printf("  ");
	GotoXY(x, y - 5);
	printf("  ");
	GotoXY(x, y - 4);
	printf("  ");
	GotoXY(x, y - 3);
	printf("  ");
	GotoXY(x, y - 2);
	printf("  ");
	GotoXY(x, y - 1);
	printf("  ");
	GotoXY(x, y);
	printf("  ");
}

// 빼빼로 박스
void Pepero(int x, int y)
{
	setColor(RED);
	GotoXY(x, y);
	printf("■■■■■■■■■■■■■■■");
	GotoXY(x, y + 1);
	printf("■                          ■");
	GotoXY(x, y + 2);
	printf("■                 @   @    ■");
	GotoXY(x, y + 3);
	printf("■    @   @@   @   @   @    ■");
	GotoXY(x, y + 4);
	printf("■    @@@@@@@@@@   @@@@@    ■");
	GotoXY(x, y + 5);
	printf("■    @   @@   @   @   @    ■");
	GotoXY(x, y + 6);
	printf("■    @@@@@@@@@@   @   @    ■");
	GotoXY(x, y + 7);
	printf("■                 @   @    ■");
	GotoXY(x, y + 8);
	printf("■                          ■");
	GotoXY(x, y + 9);
	printf("■                 @   @    ■");
	GotoXY(x, y + 10);
	printf("■    @   @@   @   @   @    ■");
	GotoXY(x, y + 11);
	printf("■    @@@@@@@@@@   @@@@@    ■");
	GotoXY(x, y + 12);
	printf("■    @   @@   @   @   @    ■");
	GotoXY(x, y + 13);
	printf("■    @@@@@@@@@@   @   @    ■");
	GotoXY(x, y + 14);
	printf("■                 @   @    ■");
	GotoXY(x, y + 15);
	printf("■                          ■");
	GotoXY(x, y + 16);
	printf("■     @@@@@@@@@@@@@@@      ■");
	GotoXY(x, y + 17);
	printf("■                   @      ■");
	GotoXY(x, y + 18);
	printf("■     @@@@@@@@@@@@@@@      ■");
	GotoXY(x, y + 19);
	printf("■     @                    ■");
	GotoXY(x, y + 20);
	printf("■     @@@@@@@@@@@@@@@      ■");
	GotoXY(x, y + 21);
	printf("■            @             ■");
	GotoXY(x, y + 22);
	printf("■            @             ■");
	GotoXY(x, y + 23);
	printf("■    @@@@@@@@@@@@@@@@@     ■");
	GotoXY(x, y + 24);
	printf("■                          ■");
	GotoXY(x, y + 25);
	printf("■■■■■■■■■■■■■■■");
	setColor(WHITE);
}

void Pepero_dlt(int x, int y)
{
	GotoXY(x, y);
	printf("                              ");
	GotoXY(x, y + 1);
	printf("                              ");
	GotoXY(x, y + 2);
	printf("                              ");
	GotoXY(x, y + 3);
	printf("                              ");
	GotoXY(x, y + 4);
	printf("                              ");
	GotoXY(x, y + 5);
	printf("                              ");
	GotoXY(x, y + 6);
	printf("                              ");
	GotoXY(x, y + 7);
	printf("                              ");
	GotoXY(x, y + 8);
	printf("                              ");
	GotoXY(x, y + 9);
	printf("                              ");
	GotoXY(x, y + 10);
	printf("                              ");
	GotoXY(x, y + 11);
	printf("                              ");
	GotoXY(x, y + 12);
	printf("                              ");
	GotoXY(x, y + 13);
	printf("                              ");
	GotoXY(x, y + 14);
	printf("                              ");
	GotoXY(x, y + 15);
	printf("                              ");
	GotoXY(x, y + 16);
	printf("                              ");
	GotoXY(x, y + 17);
	printf("                              ");
	GotoXY(x, y + 18);
	printf("                              ");
	GotoXY(x, y + 19);
	printf("                              ");
	GotoXY(x, y + 20);
	printf("                              ");
	GotoXY(x, y + 21);
	printf("                              ");
	GotoXY(x, y + 22);
	printf("                              ");
	GotoXY(x, y + 23);
	printf("                              ");
	GotoXY(x, y + 24);
	printf("                              ");
	GotoXY(x, y + 25);
	printf("                              ");
}

// 사이다
void Sprite(int x, int y)
{
	GotoXY(x, y - 38);
	printf("      ■■■■");
	GotoXY(x, y - 37);
	printf("      ■    ■");
	GotoXY(x, y - 36);
	printf("      ■    ■");
	GotoXY(x, y - 35);
	printf("     ■■■■■");
	GotoXY(x, y - 34);
	printf("      ■    ■");
	GotoXY(x, y - 33);
	printf("      ■    ■");
	GotoXY(x, y - 32);
	printf("     ■      ■");
	GotoXY(x, y - 31);
	printf("    ■        ■");
	GotoXY(x, y - 30);
	printf("   ■          ■");
	GotoXY(x, y - 29);
	printf("  ■            ■");
	GotoXY(x, y - 28);
	printf(" ■              ■");
	GotoXY(x, y - 27);
	printf("■■■■■■■■■■");
	GotoXY(x, y - 26);
	printf("■                ■");
	GotoXY(x, y - 25);
	printf("■                ■");
	GotoXY(x, y - 24);
	printf("■      SPRITE    ■");
	GotoXY(x, y - 23);
	printf("■                ■");
	GotoXY(x, y - 22);
	printf("■                ■");
	GotoXY(x, y - 21);
	printf("■                ■");
	GotoXY(x, y - 20);
	printf("■                ■");
	GotoXY(x, y - 19);
	printf("■                ■");
	GotoXY(x, y - 18);
	printf("■■■■■■■■■■");
	GotoXY(x, y - 17);
	printf(" ■              ■");
	GotoXY(x, y - 16);
	printf(" ■              ■");
	GotoXY(x, y - 15);
	printf("  ■            ■");
	GotoXY(x, y - 14);
	printf("  ■            ■");
	GotoXY(x, y - 13);
	printf("   ■          ■");
	GotoXY(x, y - 12);
	printf("   ■          ■");
	GotoXY(x, y - 11);
	printf("  ■            ■");
	GotoXY(x, y - 10);
	printf(" ■              ■");
	GotoXY(x, y - 9);
	printf("■                ■");
	GotoXY(x, y - 8);
	printf("■                ■");
	GotoXY(x, y - 7);
	printf("■                ■");
	GotoXY(x, y - 6);
	printf(" ■              ■");
	GotoXY(x, y - 5);
	printf(" ■              ■");
	GotoXY(x, y - 4);
	printf("  ■            ■");
	GotoXY(x, y - 3);
	printf("   ■■  ■  ■■");
	GotoXY(x, y - 2);
	printf("   ■■■■■■■");
	GotoXY(x, y - 1);
	printf("    ■   ■   ■");
	GotoXY(x, y);
}

void Sprite_dlt(int x, int y)
{
	GotoXY(x, y - 38);
	printf("              ");
	GotoXY(x, y - 37);
	printf("              ");
	GotoXY(x, y - 36);
	printf("              ");
	GotoXY(x, y - 35);
	printf("               ");
	GotoXY(x, y - 34);
	printf("                ");
	GotoXY(x, y - 33);
	printf("                ");
	GotoXY(x, y - 32);
	printf("                  ");
	GotoXY(x, y - 31);
	printf("                   ");
	GotoXY(x, y - 30);
	printf("                    ");
	GotoXY(x, y - 29);
	printf("                     ");
	GotoXY(x, y - 28);
	printf("                      ");
	GotoXY(x, y - 27);
	printf("                      ");
	GotoXY(x, y - 26);
	printf("                       ");
	GotoXY(x, y - 25);
	printf("                       ");
	GotoXY(x, y - 24);
	printf("                       ");
	GotoXY(x, y - 23);
	printf("                       ");
	GotoXY(x, y - 22);
	printf("                       ");
	GotoXY(x, y - 21);
	printf("                     ");
	GotoXY(x, y - 20);
	printf("                     ");
	GotoXY(x, y - 19);
	printf("                     ");
	GotoXY(x, y - 18);
	printf("                     ");
	GotoXY(x, y - 17);
	printf("                     ");
	GotoXY(x, y - 16);
	printf("                    ");
	GotoXY(x, y - 15);
	printf("                    ");
	GotoXY(x, y - 14);
	printf("                    ");
	GotoXY(x, y - 13);
	printf("                   ");
	GotoXY(x, y - 12);
	printf("                   ");
	GotoXY(x, y - 11);
	printf("                    ");
	GotoXY(x, y - 10);
	printf("                     ");
	GotoXY(x, y - 9);
	printf("                      ");
	GotoXY(x, y - 8);
	printf("                      ");
	GotoXY(x, y - 7);
	printf("                      ");
	GotoXY(x, y - 6);
	printf("                     ");
	GotoXY(x, y - 5);
	printf("                     ");
	GotoXY(x, y - 4);
	printf("                  ");
	GotoXY(x, y - 3);
	printf("                 ");
	GotoXY(x, y - 2);
	printf("                 ");
	GotoXY(x, y - 1);
	printf("                ");
	GotoXY(x, y);

}

// 플레이어
void Player(int x, int y)
{
	GotoXY(x, y);
	printf("■■");
	GotoXY(x, y - 1);
	printf("■■");
}

void Player_dlt(int x, int y)
{
	GotoXY(x, y);
	printf("    ");
	GotoXY(x, y - 1);
	printf("    ");
}


// 코뿔소

void Rhino(int x, int y)
{
	setColor(DARK_GRAY);
	GotoXY(x, y - 16);
	printf("                                                            ■■■");
	GotoXY(x, y - 15);
	printf("                            ■■    ■■■■■        ■■■      ■■");
	GotoXY(x, y - 14);
	printf("              ■          ■    ■■          ■■■■                ■■");
	GotoXY(x, y - 13);
	printf("            ■  ■      ■      ■                                        ■");
	GotoXY(x, y - 12);
	printf("            ■  ■    ■                                                    ■");
	GotoXY(x, y - 11);
	printf("              ■  ■ ■                                                     ■");
	GotoXY(x, y - 10);
	printf("              ■    ■                                                      ■");
	GotoXY(x, y - 9);
	printf("            ■                                                            ■");
	GotoXY(x, y - 8);
	printf("      ■■■                                                              ■");
	GotoXY(x, y - 7);
	printf("■      ■      ■                                                          ■");
	GotoXY(x, y - 6);
	printf("  ■      ■          ■      ■                                            ■");
	GotoXY(x, y - 5);
	printf("    ■■■            ■      ■                    ■            ■      ■");
	GotoXY(x, y - 4);
	printf("      ■■      ■  ■      ■      ■            ■■        ■■        ■");
	GotoXY(x, y - 3);
	printf("          ■■■  ■      ■  ■      ■■    ■■    ■    ■  ■        ■");
	GotoXY(x, y - 2);
	printf("                    ■  ■      ■  ■    ■■        ■    ■    ■    ■");
	GotoXY(x, y - 1);
	printf("                  ■    ■    ■    ■              ■    ■    ■      ■");
	GotoXY(x, y);
	printf("                  ■■■■    ■■■■              ■■■■    ■■■■");
	setColor(WHITE);
}

void Rhino_dlt(int x, int y)
{
	GotoXY(x, y - 16);
	printf("                                                                  ");
	GotoXY(x, y - 15);
	printf("                                                                      ");
	GotoXY(x, y - 14);
	printf("                                                                          ");
	GotoXY(x, y - 13);
	printf("                                                                            ");
	GotoXY(x, y - 12);
	printf("                                                                              ");
	GotoXY(x, y - 11);
	printf("                                                                              ");
	GotoXY(x, y - 10);
	printf("                                                                              ");
	GotoXY(x, y - 9);
	printf("                                                                            ");
	GotoXY(x, y - 8);
	printf("                                                                            ");
	GotoXY(x, y - 7);
	printf("                                                                              ");
	GotoXY(x, y - 6);
	printf("                                                                              ");
	GotoXY(x, y - 5);
	printf("                                                                            ");
	GotoXY(x, y - 4);
	printf("                                                                            ");
	GotoXY(x, y - 3);
	printf("                                                                            ");
	GotoXY(x, y - 2);
	printf("                                                                          ");
	GotoXY(x, y - 1);
	printf("                                                                          ");
	GotoXY(x, y);
	printf("                                                                        ");
}

// 개루마르
void Frog(int x, int y)
{
	GotoXY(x, y - 18);
	printf("■■■");
	GotoXY(x, y - 17);
	printf("      ■");
	setColor(DARK_GRAY);
	GotoXY(x, y - 18);
	printf("        ■■■");
	GotoXY(x, y - 17);
	printf("      ■");
	setColor(BLUE);
	printf("■");
	setColor(YELLOW);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■    ■■■");
	GotoXY(x, y - 16);
	printf("      ■");
	setColor(YELLOW);
	printf("■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■■");
	setColor(YELLOW);
	printf("■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 15);
	printf("      ■");
	setColor(YELLOW);
	printf("■");
	setColor(BLACK);
	printf("■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(YELLOW);
	printf("■■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 14);
	printf("    ■");
	setColor(GRAY);
	printf("■");
	setColor(YELLOW);
	printf("■");
	setColor(BLACK);
	printf("■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(YELLOW);
	printf("■");
	setColor(BLACK);
	printf("■");
	setColor(YELLOW);
	printf("■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(DARK_GRAY);
	printf("■■");
	GotoXY(x, y - 13);
	printf("  ■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(YELLOW);
	printf("■");
	setColor(DARK_BLUE);
	printf("■■");
	setColor(GRAY);
	printf("■");
	setColor(YELLOW);
	printf("■");
	setColor(BLACK);
	printf("■");
	setColor(YELLOW);
	printf("■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 12);
	printf("  ■");
	setColor(SKYBLUE);
	printf("■");
	setColor(WHITE);
	printf("■■");
	setColor(BLUE);
	printf("■");
	setColor(DARK_BLUE);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(SKYBLUE);
	printf("■");
	setColor(YELLOW);
	printf("■■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 11);
	printf("    ■");
	setColor(GRAY);
	printf("■■■■■");
	setColor(SKYBLUE);
	printf("■■");
	setColor(YELLOW);
	printf("■");
	setColor(SKYBLUE);
	printf("■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 10);
	printf("    ■");
	setColor(GRAY);
	printf("■");
	setColor(DARK_SKYBLUE);
	printf("■■");
	setColor(WHITE);
	printf("■■");
	setColor(SKYBLUE);
	printf("■■■■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 9);
	printf("      ■");
	setColor(GRAY);
	printf("■■");
	setColor(SKYBLUE);
	printf("■■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■■■");
	setColor(WHITE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 8);
	printf("        ■■");
	setColor(GRAY);
	printf("■■■■■");
	setColor(WHITE);
	printf("■");
	setColor(WHITE);
	printf("■");
	setColor(WHITE);
	printf("■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 7);
	printf("        ■");
	setColor(SKYBLUE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	setColor(GRAY);
	printf("■■■■");
	setColor(WHITE);
	printf("■");
	setColor(GRAY);
	printf("■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 6);
	printf("      ■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■■");
	setColor(GRAY);
	printf("■■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 5);
	printf("  ■■");
	setColor(WHITE);
	printf("■■");
	setColor(GRAY);
	printf("■■");
	setColor(SKYBLUE);
	printf("■");
	setColor(WHITE);
	printf("■■");
	setColor(GRAY);
	printf("■■");
	setColor(BLUE);
	printf("■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 4);
	printf("■");
	setColor(WHITE);
	printf("■■■");
	setColor(GRAY);
	printf("■");
	setColor(BLUE);
	printf("■■");
	setColor(DARK_GRAY);
	printf("■");
	setColor(SKYBLUE);
	printf("■■■");
	setColor(BLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 3);
	printf("  ■■");
	setColor(WHITE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■■■  ■■■");
	setColor(SKYBLUE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(BLUE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 2);
	printf("      ■■            ■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 1);
	printf("                      ■");
	setColor(WHITE);
	printf("■");
	setColor(GRAY);
	printf("■");
	setColor(WHITE);
	printf("■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y);
	printf("                        ■■■■");
	setColor(WHITE);
}

void Frog_dlt(int x, int y)
{
	GotoXY(x, y - 18);
	printf("                                  ");
	GotoXY(x, y - 17);
	printf("                                  ");
	GotoXY(x, y - 16);
	printf("                                  ");
	GotoXY(x, y - 15);
	printf("                                  ");
	GotoXY(x, y - 14);
	printf("                                  ");
	GotoXY(x, y - 13);
	printf("                                    ");
	GotoXY(x, y - 12);
	printf("                                    ");
	GotoXY(x, y - 11);
	printf("                                    ");
	GotoXY(x, y - 10);
	printf("                                    ");
	GotoXY(x, y - 9);
	printf("                                    ");
	GotoXY(x, y - 8);
	printf("                                    ");
	GotoXY(x, y - 7);
	printf("                                    ");
	GotoXY(x, y - 6);
	printf("                                    ");
	GotoXY(x, y - 5);
	printf("                                    ");
	GotoXY(x, y - 4);
	printf("                                    ");
	GotoXY(x, y - 3);
	printf("                                    ");
	GotoXY(x, y - 2);
	printf("                                    ");
	GotoXY(x, y - 1); 
	printf("                                    ");
	GotoXY(x, y);
	printf("                                     ");
}

// 바닥
void Map(int x, int y)
{
	GotoXY(x, y);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}

void Map_dlt(int x, int y)
{
	printf("                                                                                                                                           ");
}

// 느낌표
void Em(int x, int y)
{
	setColor(RED);
	GotoXY(x, y - 6);
	printf("■");
	GotoXY(x, y - 5);
	printf("■");
	GotoXY(x, y - 4);
	printf("■");
	GotoXY(x, y - 3);
	printf("■");
	GotoXY(x, y - 2);
	printf("■");
	GotoXY(x, y - 1);
	printf("  ");
	GotoXY(x, y);
	printf("●");
	setColor(WHITE);
}

void Em_dlt(int x, int y)
{
	GotoXY(x, y - 6);
	printf("  ");
	GotoXY(x, y - 5);
	printf("  ");
	GotoXY(x, y - 4);
	printf("  ");
	GotoXY(x, y - 3);
	printf("  ");
	GotoXY(x, y - 2);
	printf("  ");
	GotoXY(x, y - 1);
	printf("  ");
	GotoXY(x, y);
	printf("  ");
}

// 물 
void Water(int x, int y)
{
	setColor(BLUE);
	GotoXY(x, y - 5);
	printf("■■");
	GotoXY(x, y - 4);
	printf("■■");
	GotoXY(x, y - 3);
	printf("■■");
	GotoXY(x, y - 2);
	printf("■■");
	GotoXY(x, y - 1);
	printf("■■");
	GotoXY(x, y);
	printf("■■");
	setColor(WHITE);
}

void Water_dlt(int x, int y)
{
	GotoXY(x, y - 5);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 4);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 3);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 2);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 1);
	printf("                                                                                                                                            ");
	GotoXY(x, y);
	printf("                                                                                                                                            ");
}

// 물 2
void Water2(int x, int y)
{
	setColor(BLUE);
	GotoXY(x, y - 11);
	printf("■■");
	GotoXY(x, y - 10);
	printf("■■");
	GotoXY(x, y - 9);
	printf("■■");
	GotoXY(x, y - 8);
	printf("■■");
	GotoXY(x, y - 7);
	printf("■■");
	GotoXY(x, y - 6);
	printf("■■");
	GotoXY(x, y - 5);
	printf("■■");
	GotoXY(x, y - 4);
	printf("■■");
	GotoXY(x, y - 3);
	printf("■■");
	GotoXY(x, y - 2);
	printf("■■");
	GotoXY(x, y - 1);
	printf("■■");
	GotoXY(x, y);
	printf("■■");
	setColor(WHITE);
}

void Water2_dlt(int x, int y)
{
	GotoXY(x, y - 11);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 10);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 9);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 8);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 7);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 6);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 5);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 4);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 3);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 2);
	printf("                                                                                                                                            ");
	GotoXY(x, y - 1);
	printf("                                                                                                                                            ");
	GotoXY(x, y);
	printf("                                                                                                                                            ");
}

// 물 3
void Water3(int x, int y)
{
	setColor(BLUE);
	GotoXY(x, y - 2);
	printf("■■■■■■");
	GotoXY(x, y - 1);
	printf("■■■■■■");
	GotoXY(x, y);
	printf("■■■■■■");
	setColor(WHITE);
}

void Water3_dlt(int x, int y)
{
	GotoXY(x, y - 45);
	printf("            ");
	GotoXY(x, y - 44);
	printf("            ");
	GotoXY(x, y - 43);
	printf("            ");
	GotoXY(x, y - 42);
	printf("            ");
	GotoXY(x, y - 41);
	printf("            ");
	GotoXY(x, y - 40);
	printf("            ");
	GotoXY(x, y - 39);
	printf("            ");
	GotoXY(x, y - 38);
	printf("            ");
	GotoXY(x, y - 37);
	printf("            ");
	GotoXY(x, y - 36);
	printf("            ");
	GotoXY(x, y - 35);
	printf("            ");
	GotoXY(x, y - 34);
	printf("            ");
	GotoXY(x, y - 33);
	printf("            ");
	GotoXY(x, y - 32);
	printf("            ");
	GotoXY(x, y - 31);
	printf("            ");
	GotoXY(x, y - 30);
	printf("            ");
	GotoXY(x, y - 29);
	printf("            ");
	GotoXY(x, y - 28);
	printf("            ");
	GotoXY(x, y - 27);
	printf("            ");
	GotoXY(x, y - 26);
	printf("            ");
	GotoXY(x, y - 25);
	printf("            ");
	GotoXY(x, y - 24);
	printf("            ");
	GotoXY(x, y - 23);
	printf("            ");
	GotoXY(x, y - 22);
	printf("            ");
	GotoXY(x, y - 21);
	printf("            ");
	GotoXY(x, y - 20);
	printf("            ");
	GotoXY(x, y - 19);
	printf("            ");
	GotoXY(x, y - 18);
	printf("            ");
	GotoXY(x, y - 17);
	printf("            ");
	GotoXY(x, y - 16);
	printf("            ");
	GotoXY(x, y - 15);
	printf("            ");
	GotoXY(x, y - 14);
	printf("            ");
	GotoXY(x, y - 13);
	printf("            ");
	GotoXY(x, y - 12);
	printf("            ");
	GotoXY(x, y - 11);
	printf("            ");
	GotoXY(x, y - 10);
	printf("            ");
	GotoXY(x, y - 9);
	printf("            ");
	GotoXY(x, y - 8);
	printf("            ");
	GotoXY(x, y - 7);
	printf("            ");
	GotoXY(x, y - 6);
	printf("            ");
	GotoXY(x, y - 5);
	printf("            ");
	GotoXY(x, y - 4);
	printf("            ");
	GotoXY(x, y - 3);
	printf("            ");
	GotoXY(x, y - 2);
	printf("            ");
	GotoXY(x, y - 1);
	printf("            ");
	GotoXY(x, y);
	printf("            ");
}

// 마법사
void Wizard(int x, int y)
{
	GotoXY(x, y - 26);
	setColor(DARK_GRAY);
	printf("        ■■");
	GotoXY(x, y - 25);
	setColor(DARK_GRAY);
	printf("      ■■");
	setColor(DARK_VOILET);
	printf("■");
	setColor(DARK_GRAY);
	printf("■■");
	GotoXY(x, y - 24);
	setColor(DARK_GRAY);
	printf("          ■");
	setColor(DARK_VOILET);
	printf("■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 23);
	setColor(DARK_GRAY);
	printf("          ■");
	setColor(DARK_VOILET);
	printf("■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 22);
	setColor(DARK_GRAY);
	printf("            ■");
	setColor(VIOLET);
	printf("■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 21);
	setColor(DARK_GRAY);
	printf("            ■");
	setColor(VIOLET);
	printf("■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 20);
	setColor(DARK_GRAY);
	printf("            ■");
	setColor(VIOLET);
	printf("■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 19);
	setColor(DARK_GRAY);
	printf("            ■");
	setColor(VIOLET);
	printf("■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 18);
	setColor(DARK_GRAY);
	printf("          ■");
	setColor(VIOLET);
	printf("■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 17);
	setColor(DARK_GRAY);
	printf("        ■");
	setColor(VIOLET);
	printf("■■■■■■■■■");
	setColor(DARK_GRAY);
	printf("■■");
	GotoXY(x, y - 16);
	setColor(DARK_GRAY);
	printf("    ■■");
	setColor(VIOLET);
	printf("■■■■■■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 15);
	setColor(DARK_GRAY);
	printf("  ■");
	setColor(VIOLET);
	printf("■■■■■■■■■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 14);
	setColor(DARK_GRAY);
	printf("■");
	setColor(VIOLET);
	printf("■■■■■■■■■■■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 13);
	printf("  ■■■■■");
	setColor(VIOLET);
	printf("■■■■■■■■");
	setColor(DARK_GRAY);
	printf("■■■■");
	GotoXY(x, y - 12);
	setColor(DARK_GRAY);
	printf("        ■");
	setColor(WHITE);
	printf("■");
	setColor(DARK_GRAY);
	printf("■■■■■■■■■");
	GotoXY(x, y - 11);
	setColor(DARK_GRAY);
	printf("        ■");
	setColor(WHITE);
	printf("■■");
	setColor(YELLOW);
	printf("■");
	setColor(BLACK);
	printf("■■");
	setColor(YELLOW);
	printf("■■■");
	setColor(BLACK);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 10);
	setColor(DARK_GRAY);
	printf("        ■");
	setColor(WHITE);
	printf("■■");
	setColor(YELLOW);
	printf("■");
	setColor(BLACK);
	printf("■■");
	setColor(YELLOW);
	printf("■■■");
	setColor(BLACK);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 9);
	setColor(DARK_GRAY);
	printf("        ■");
	setColor(WHITE);
	printf("■■■");
	setColor(YELLOW);
	printf("■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 8);
	setColor(DARK_GRAY);
	printf("        ■");
	setColor(WHITE);
	printf("■■■■■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 7);
	setColor(DARK_GRAY);
	printf("          ■");
	setColor(WHITE);
	printf("■■■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 6);
	setColor(DARK_GRAY);
	printf("        ■■■");
	setColor(DARK_GRAY);
	printf("■");
	setColor(WHITE);
	printf("■■■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 5);
	setColor(DARK_GRAY);
	printf("        ■■■");
	setColor(DARK_VOILET);
	printf("■■");
	setColor(WHITE);
	printf("■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 4);
	setColor(DARK_GRAY);
	printf("      ■");
	setColor(DARK_VOILET);
	printf("■");
	setColor(VIOLET);
	printf("■■■■");
	setColor(WHITE);
	printf("■■■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 3);
	setColor(DARK_GRAY);
	printf("      ■");
	setColor(BLACK);
	printf("■■■■■■");
	setColor(WHITE);
	printf("■■■");
	setColor(BLACK);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 2);
	setColor(DARK_GRAY);
	printf("      ■");
	setColor(DARK_VOILET);
	printf("■");
	setColor(VIOLET);
	printf("■■■■");
	setColor(BLACK);
	printf("■");
	setColor(WHITE);
	printf("■■■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y - 1);
	setColor(DARK_GRAY);
	printf("      ■");
	setColor(DARK_VOILET);
	printf("■■■");
	setColor(VIOLET);
	printf("■■");
	setColor(BLACK);
	printf("■■");
	setColor(WHITE);
	printf("■");
	setColor(BLACK);
	printf("■");
	setColor(DARK_GRAY);
	printf("■");
	GotoXY(x, y);
	setColor(DARK_GRAY);
	printf("        ■■■■■■■■■■");
}

void Wizard_dlt(int x, int y)
{
	GotoXY(x, y - 26);
	printf("                                                    ");
	GotoXY(x, y - 25);
	printf("                                                    ");
	GotoXY(x, y - 24);
	printf("                                                    ");
	GotoXY(x, y - 23);
	printf("                                                    ");
	GotoXY(x, y - 22);
	printf("                                                    ");
	GotoXY(x, y - 21);
	printf("                                                    ");
	GotoXY(x, y - 20);
	printf("                                                    ");
	GotoXY(x, y - 19);
	printf("                                                    ");
	GotoXY(x, y - 18);
	printf("                                                    ");
	GotoXY(x, y - 17);
	printf("                                                    ");
	GotoXY(x, y - 16);
	printf("                                                    ");
	GotoXY(x, y - 15);
	printf("                                                    ");
	GotoXY(x, y - 14);
	printf("                                                    ");
	GotoXY(x, y - 13);
	printf("                                                    ");
	GotoXY(x, y - 12);
	printf("                                                    ");
	GotoXY(x, y - 11);
	printf("                                                    ");
	GotoXY(x, y - 10);
	printf("                                                    ");
	GotoXY(x, y - 9);
	printf("                                                    ");
	GotoXY(x, y - 8);
	printf("                                                    ");
	GotoXY(x, y - 7);
	printf("                                                    ");
	GotoXY(x, y - 6);
	printf("                                                    ");
	GotoXY(x, y - 5);
	printf("                                                    ");
	GotoXY(x, y - 4);
	printf("                                                    ");
	GotoXY(x, y - 3);
	printf("                                                    ");
	GotoXY(x, y - 2);
	printf("                                                    ");
	GotoXY(x, y - 1);
	printf("                                                    ");
	GotoXY(x, y);
	printf("                                                    ");
}

// 지팡이
void Wand(int x, int y,int color)
{
	GotoXY(x, y - 20);
	setColor(DARK_SKYBLUE);
	printf("      ■■");
	GotoXY(x, y - 19);
	printf("    ■");
	setColor(color);
	printf("■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	GotoXY(x, y - 18);
	setColor(DARK_SKYBLUE);
	printf("  ■");
	setColor(color);
	printf("■■■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	GotoXY(x, y - 17);
	setColor(DARK_SKYBLUE);
	printf("■");
	setColor(color);
	printf("■■■■■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	GotoXY(x, y - 16);
	setColor(DARK_SKYBLUE);
	printf("  ■");
	setColor(color);
	printf("■■■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	GotoXY(x, y - 15);
	setColor(DARK_SKYBLUE);
	printf("    ■");
	setColor(color);
	printf("■■");
	setColor(DARK_SKYBLUE);
	printf("■");
	GotoXY(x, y - 14);
	printf("      ■■");
	GotoXY(x, y - 13);
	printf("       ■");
	GotoXY(x, y - 12);
	setColor(YELLOW);
	printf("    ■■■■");
	GotoXY(x, y - 11);
	printf("      ■■");
	GotoXY(x, y - 10);
	printf("    ■■■■");
	GotoXY(x, y - 9);
	setColor(DAKR_YELLOW);
	printf("      ■■");
	GotoXY(x, y - 8);
	printf("      ■■");
	GotoXY(x, y - 7);
	printf("      ■■");
	GotoXY(x, y - 6);
	printf("      ■■");
	GotoXY(x, y - 5);
	printf("      ■■");
	GotoXY(x, y - 4);
	printf("      ■■");
	GotoXY(x, y - 3);
	printf("      ■■");
	GotoXY(x, y - 2);
	printf("      ■■");
	GotoXY(x, y - 1);
	printf("      ■■");
	GotoXY(x, y);
	printf("      ■■");
	setColor(WHITE);
}

// 별
void Star(int x, int y)
{
	setColor(YELLOW);
	GotoXY(x, y - 9);
	printf("          ■");
	GotoXY(x, y - 8);
	printf("        ■■■");
	GotoXY(x, y - 7);
	printf("      ■■■■■");
	GotoXY(x, y - 6);
	printf("■■■■■■■■■■■");
	GotoXY(x, y - 5);
	printf("■■■■■■■■■■■");
	GotoXY(x, y - 4);
	printf("  ■■■■■■■■■");
	GotoXY(x, y - 3);
	printf("    ■■■■■■■");
	GotoXY(x, y - 2);
	printf("    ■■■■■■■");
	GotoXY(x, y - 1);
	printf("    ■■■  ■■■");
	GotoXY(x, y);
	printf("    ■■      ■■");
	setColor(WHITE);
}

void Star_dlt(int x, int y)
{
	GotoXY(x, y - 9);
	printf("            ");
	GotoXY(x, y - 8);
	printf("              ");
	GotoXY(x, y - 7);
	printf("                ");
	GotoXY(x, y - 6);
	printf("                      ");
	GotoXY(x, y - 5);
	printf("                      ");
	GotoXY(x, y - 4);
	printf("                    ");
	GotoXY(x, y - 3);
	printf("                  ");
	GotoXY(x, y - 2);
	printf("                  ");
	GotoXY(x, y - 1);
	printf("                  ");
	GotoXY(x, y);
	printf("                  ");
}

// 베트남 국기
void Vietnam(int x, int y)
{
	setColor(RED);
	GotoXY(x, y - 13);
	printf("■■■■■■■■■■■■■■■■■■■■");
	GotoXY(x, y - 12);
	printf("■                                    ■");
	GotoXY(x, y - 11);
	printf("■                                    ■");
	GotoXY(x, y - 10);
	printf("■                                    ■");
	GotoXY(x, y - 9);
	printf("■                                    ■");
	GotoXY(x, y - 8);
	printf("■                                    ■");
	GotoXY(x, y - 7);
	printf("■                                    ■");
	GotoXY(x, y - 6);
	printf("■                                    ■");
	GotoXY(x, y - 5);
	printf("■                                    ■");
	GotoXY(x, y - 4);
	printf("■                                    ■");
	GotoXY(x, y - 3);
	printf("■                                    ■");
	GotoXY(x, y - 2);
	printf("■                                    ■");
	GotoXY(x, y - 1);
	printf("■                                    ■");
	GotoXY(x, y);
	printf("■■■■■■■■■■■■■■■■■■■■");
}

// 롤린 
void Rollin1(int x, int y) {
	GotoXY(x, y - 4);
	printf("  ■");
	GotoXY(x, y - 3);
	printf("■■■");
	GotoXY(x, y - 2);
	printf("  ■");
	GotoXY(x, y - 1);
	printf(" ■");
	GotoXY(x, y);
	printf("■  ■");
}
void Rollin2(int x, int y) {
	GotoXY(x, y - 4);
	printf("  ■");
	GotoXY(x, y - 3);
	printf("■■■");
	GotoXY(x, y - 2);
	printf("  ■");
	GotoXY(x, y - 1);
	printf("  ■");
	GotoXY(x, y);
	printf("■  ■");
}
void Rollin3(int x, int y) {
	GotoXY(x, y - 4);
	printf("  ■");
	GotoXY(x, y - 3);
	printf("■■■");
	GotoXY(x, y - 2);
	printf("  ■");
	GotoXY(x, y - 1);
	printf("   ■");
	GotoXY(x, y);
	printf("■  ■");
}
void Rollin_dlt(int x, int y)
{
	GotoXY(x, y - 4);
	printf("    ");
	GotoXY(x, y - 3);
	printf("      ");
	GotoXY(x, y - 2);
	printf("    ");
	GotoXY(x, y - 1);
	printf("     ");
	GotoXY(x, y);
	printf("      ");
}