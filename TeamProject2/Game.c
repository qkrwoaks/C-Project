#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "object.h"

#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

//palySound 함수 이용 사운드 파일 재생

#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define Third_Run "C:\\Users\\user\\Downloads\\Music\\Lounge.wav"
#define Third_Run2 "C:\\Users\\user\\Downloads\\Lounge2.wav"
#define Rollin_RUN "C:\\Users\\user\\Downloads\\Rollin.wav"
#define HP_x 168
#define HP_y 1
#define MAX 30
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

char buffer[34];

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c) { CONSOLE_CURSOR_INFO CurInfo; switch (c) { case NOCURSOR: CurInfo.dwSize = 1; CurInfo.bVisible = FALSE; break; case SOLIDCURSOR: CurInfo.dwSize = 100; CurInfo.bVisible = TRUE; break; case NORMALCURSOR: CurInfo.dwSize = 20; CurInfo.bVisible = TRUE; break; } SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo); }

																						   
struct OBJECT
{
	short x;
	short y;
	short scene;
	int cnt;
	bool hit;
	bool active; 
};

struct OBJECT em;
struct OBJECT player;
struct OBJECT sprite;
struct OBJECT pepero;
struct OBJECT ppr_stick[MAX];
struct OBJECT rhino;
struct OBJECT frog;
struct OBJECT water[10];
struct OBJECT wizard;
struct OBJECT wand;
struct OBJECT vietnam[10];
struct OBJECT rollin[4];

// HP
void Hp(int hp)
{
	setColor(RED);
	switch (hp)
	{
	case 5:
		GotoXY(HP_x, HP_y);
		printf("♡♡♡♡♡");
		break;
	case 4:
		GotoXY(HP_x, HP_y);
		printf("  ♡♡♡♡");
		break;
	case 3:
		GotoXY(HP_x, HP_y);
		printf("    ♡♡♡");
		break;
	case 2:
		GotoXY(HP_x, HP_y);
		printf("      ♡♡");
		break;
	case 1:
		GotoXY(HP_x, HP_y);
		printf("        ♡");
		break;
	case 0:
		break;
	}
	setColor(WHITE);

}

void Hp_dlt()
{
	GotoXY(HP_x, HP_y);
	printf("          ");
}


// 게임 기본설정
void Game()
{
	system("mode con lines=50 cols=180");	
	setcursortype(NOCURSOR);
	srand(time(NULL));
	player.x = 100; // 플레이어 x
	player.y = 46;  // 플레이어 y
	player.hit = false;
}

// 플레이어 이동
void Player_Move(int game_scene)
{
	if (player.x != 0) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			player.x -= 2;
			if(game_scene == 5)
				player.active = true;
		}
	}
	if (player.x != 176) {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 플레이어 이동 
		{
			player.x += 2;
			if (game_scene == 5)
				player.active = true;
		}
	}
}

// 배경음악
void InGameMusic()
{
	PlaySound(TEXT(Third_Run), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//사운드 파일 위치, SND_ASYNC, SND_LOOP 세가지가 제일 중요
	//SND_ASYNC : 재생하면서 다음코드 실행
	//SND_LOOP : 반복재생
} 

// 음악 
void GameMusic()
{
	PlaySound(TEXT(Third_Run2), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}

// 롤린
void RollinMusic()
{
	PlaySound(TEXT(Rollin_RUN), NULL, SND_FILENAME | SND_ASYNC);
	//사운드 파일 위치, SND_ASYNC, SND_LOOP 세가지가 제일 중요
	//SND_ASYNC : 재생하면서 다음코드 실행
	//SND_LOOP : 반복재생
}

// 세이프 존
void Safe_Zone(int x, int y)
{
	GotoXY(x, y);
	printf("          ");
	GotoXY(x, y);
	setColor(GREEN);
	printf("Safe Zone");
	setColor(WHITE);
}

// 시작 메뉴  
void StartMenu()
{
	START:
	Wizard(10, 45);
	Frog(130, 45);
	int num = 0;
	int x = 55, y = 22;
	int num_x = 30 , num_y = 19;
	char ch = '\0';
	Title(16, 5);
	Menu(65, 21); 
	
	while (1)
	{
		Cursor_dlt(x, y);

		if (_kbhit())
		{
			ch = _getch();
			if (ch == UP && num != 0)
			{
				y -= 8;
				num -= 1;
				
			}
			else if (ch == DOWN && num != 2)
			{
				y += 8;
				num += 1;
			}
			else if (ch == SPACE)
			{
				if (num == 0)
				{
					system("cls");
					break;
				}
				else if (num == 1)
				{
					system("cls");

					Rank(68, 9);

					GotoXY(77, 47);
					printf("돌아가려면 누르시오(1)...");

					FILE* fp = fopen("test.txt", "r");    // hello.txt 파일을 읽기 모드로 열기.  
														   // 파일 포인터를 반환
					fgets(buffer, sizeof(buffer), fp);    // hello.txt에서 문자열을 읽음

					setColor(YELLOW);
					Number(num_x - 14, num_y, 11);
					for (int i = 0; i < 11; i++)
					{
						if (i == 4)
							num_x += 4;
						ABCD(num_x + (i* 12), num_y, buffer[i]);
					}
					setColor(GRAY);
					num_x -= 4;
					Number(num_x - 16, num_y + 12, 12);

					for (int i = 11; i < 22; i++)
					{
						if (i == 15)
							num_x += 4;
						ABCD(num_x + ((i - 11) * 12), num_y + 12, buffer[i]);

					}
					setColor(DAKR_YELLOW);
					num_x -= 4;
					Number(num_x - 16, num_y + 24, 13);

					for (int i = 22; i < 33; i++)
					{
						if (i == 26)
							num_x += 4;
						ABCD(num_x + ((i - 22) * 12), num_y + 24, buffer[i]);
						
					}
					setColor(WHITE);
					num_x -= 4;
					for (int i = 0; i < 3; i++) {
						ABCD(num_x + 48, num_y + (i * 12), ':');
					}

					fclose(fp);    // 파일 포인터 닫기



					while (1)
					{
						if (_kbhit())
						{
							ch = _getch();
							if (ch == '1')
							{
								system("cls");
								goto START;

							}						
						}
					}
				}
				else if (num == 2)
				{
					system("cls");
					exit(0);
				}
			}
		}
		Cursor(x, y);


		Sleep(20);
	}
}

// 게임오버 화면
void GameOver(int _score)
{
	system("cls");
	int j = 7;
	char name[10]; // 닉네임
	char last_name[3][5] = {'\0',};
	char str_sc[3][10];
	int _sc[3]; // 1,2,3 등 점수
	char sc[7];
	int ja = 1000000;
	char ch = '\0';
	int score[8] = {0,}; // 점수
	int nmg[3] = { 0, };
	char rs[3][9] = {'\0',};
	char rank[36] = { '\0', };
	int bug = 1;
	FILE* fp = fopen("test.txt", "r");    // hello.txt 파일을 읽기 모드로 열기.  
														   // 파일 포인터를 반환

	fgets(buffer, sizeof(buffer), fp);

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 7; i++)
		{ 
			sc[i] = buffer[i + 4 + j * 11]; 
		}
		for (int k = 0; k < 4; k++)
		{
			last_name[j][k] = buffer[k + j * 11];
		}

		_sc[j] = atoi(sc);
	}

	fclose(fp);    // 파일 포인터 닫기

	


	FILE* fp1 = fopen("test.txt", "w");
	
	GotoXY(80, 26);
	
	printf("Nickname을 입력하세요(※4글자 영어와 숫자만 가능) : ");
	scanf("%s", name);

	if (_sc[0] < _score)
	{
		_sc[2] = _sc[1];
		_sc[1] = _sc[0];
		_sc[0] = _score;
		strcpy(last_name[2], last_name[1]);
		strcpy(last_name[1], last_name[0]);
		strcpy(last_name[0], name);
	}
	else if (_sc[1] < _score)
	{
		_sc[2] = _sc[1];
		_sc[1] = _score;
		strcpy(last_name[2], last_name[1]);
		strcpy(last_name[1], name);
	}
	else if (_sc[2] < _score)
	{
		_sc[2] = _score;
		strcpy(last_name[2], name);
	}


	for (int i = 0; i < 3; i++)	{
		ja = 1000000;
		while (1){
			if (ja > _sc[i])
			{
				ja /= 10;
				nmg[i]++;
			}
			else
				break;
		}
	}
	for(int i = 0; i<3; i++)
		sprintf(str_sc[i], "%d", _sc[i]);    // %d를 지정하여 정수를 문자열로 저장
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < nmg[i]; j++)
		{
			strcat(rs[i], "0");
		}
		strcat(rs[i], str_sc[i]);
		printf("%s\n", rs[i]);
	}

	strcat(rank, last_name[0]);
	strcat(rank, rs[0]);

	strcat(rank, last_name[1]);
	strcat(rank, rs[1]);

	strcat(rank, last_name[2]);
	strcat(rank, rs[2]);

	fwrite(rank, strlen(rank), 1, fp1);

	fclose(fp1);    // 파일 포인터 닫기

	

	

	system("cls");
	GO(40, 3); // 게임오버 글씨

	//등급
	if (_score <= 500)
		ABCD(82, 35, 'f');
	else if (_score <= 1500)
		ABCD(82, 35, 'd');
	else if (_score <= 2500)
		ABCD(82, 35, 'c');
	else if (_score <= 5000)
		ABCD(82, 35, 'b');
	else if (_score <= 10000)
		ABCD(82, 35, 'a');
	else
		ABCD(82, 35, 's');

	// 점수
	while (_score != 0)
	{
		score[j] = _score % 10;
		_score /= 10;
		j--;
	}

	for (int i = 0; i < 8; i++) // 점수
	{
		Number(12 * (i + 4), 20, score[i]);
	}
	
	GotoXY(80, 45);
	printf("돌아가려면 누르시오(1)...");

	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == '1')
			{
				system("cls");
				break;
			}
		}
	}
}

// 플레이어 점프
void Jump(int* jump, int game_scene)
{
	static int jump_cnt = 0;

	if (*jump == 2)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			*jump = 1;
		}
	}
	if (*jump == 1)
	{	if(game_scene == 5)
			player.active = true;
		player.y -= 1;
		jump_cnt++;
		if (jump_cnt == 15)
		{
			*jump = 0;
			jump_cnt = 0;
		}
	}
	if (*jump == 0)
	{
		if(game_scene == 5)
			player.active = true;
		if (player.y >= 46)
		{
			*jump = 2;
		}
		player.y += 1;
	}

}

// 플레이어 히트 판정
void Player_Hit(int* hit_cnt)
{

	if (player.hit == true)
	{
		*hit_cnt += 1;
		setColor(RED);
		if (*hit_cnt == 17)
		{
			*hit_cnt = 0;
			player.hit = false;
		}
	}
}

// -----------------------------------------------------

// 사이다 씬 셋팅
void Sprite_Scene_Set(int* Game_Scene_cnt)
{
	sprite.active = true;
	sprite.scene = rand() % 2;
	if (sprite.scene == 0) // 왼쪽에서 생성
		sprite.x = 0;
	else if (sprite.scene == 1) // 오른쪽에서 생성
		sprite.x = 153;

	sprite.y = 40;
	*Game_Scene_cnt = 0;
}

// 빼빼로 씬 셋팅
void Pepero_Scene_Set(int* Game_Scene_cnt)
{
	pepero.x = 75;
	pepero.y = 0;
	pepero.active = true;
	pepero.hit = true;
	pepero.cnt = 0;
	for (int i = 0; i < 15; i++)
		ppr_stick[i].active = false;
	*Game_Scene_cnt = 0;
}

// 코뿔소 씬 셋팅
void Rhino_Scene_Set(int* Game_Scene_cnt)
{
	rhino.y = 47;
	rhino.x = 102;
	rhino.cnt = 0;
	em.x = 160;
	em.y = 40;
	rhino.active = false;
	*Game_Scene_cnt = 0;
}

// 개구마르 씬 셋팅
void Frog_Scene_Set(int* Game_Scene_cnt)
{
	em.x = 170;
	em.y = 40;
	em.active = false;
	frog.x = 140;
	frog.y = 47;
	*Game_Scene_cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		water[i].cnt = 0;
		water[i].scene = false;
		water[i].hit = true;
		if (i == 0)
		{
			water[i].hit = true;
			water[i].x = 140;
			water[i].y = 46;
			water[i].scene = true;
		}
		if (i == 1)
		{
			water[i].x = 140;
			water[i].y = 46;
		}
		else if (i == 2)
		{
			water[i].y = 47;
		}
	}
}

// 마법사 씬 셋팅
void Wizard_Scene_Set(int* Game_Scene_cnt)
{
	wizard.x = 2;
	wizard.y = 47;
	wizard.cnt = 0;
	wand.x = 38;
	wand.y = 45;
	wand.cnt = 0;
	em.x = 15;
	em.y = 42;
	em.active = true;
	*Game_Scene_cnt = 0;
}

// 베트남 씬 셋팅
void Vietnam_Scene_Set(int* Game_Scene_cnt)
{
	for (int i = 0; i < 9; i++)
	{
		vietnam[i].scene = 0;
		if (i % 2 == 0)
			vietnam[i].active = false;
		else
			vietnam[i].active = true;
		vietnam[i].hit = false;

	}
	vietnam[8].active = true;
	vietnam[8].x = 70;
	vietnam[8].y = 15;
	vietnam[0].cnt = 0;
	*Game_Scene_cnt = 0;
}

// 롤린 씬 셋팅
void Rollin_Scene_Set(int* Game_Scene_cnt)
{
	for (int i = 0; i < 4; i++) {
		rollin[i].x = 11 * (i + 1);
		rollin[i].y = 47;
		rollin[i].active = false;
		rollin[i].cnt = 0;
	}
	rollin[0].active = true;
	em.x = 15;
	em.y = 42;
	em.active = true;
	*Game_Scene_cnt = 0;
}

// -----------------------------------------------------

// 사이다 생성
void Sprite_Scene(long long cnt, int* hp, int* Game_Scene)
{
	Sprite_dlt(sprite.x, sprite.y);
	if (sprite.scene == 0)
		sprite.x += 3;
	else if (sprite.scene == 1)
		sprite.x -= 3;
	if (cnt % 8 == 0)
	{
		sprite.y += 1;
	}
	Sprite(sprite.x, sprite.y);

	if (sprite.y == 48 || sprite.x == 0 || sprite.x >= 155)
	{
		*Game_Scene = 0;
		Sprite_dlt(sprite.x, sprite.y);
	}
	if (sprite.active == true)
	{
		if (sprite.y >= player.y && sprite.y - 38 <= player.y)
		{
			if (sprite.x <= player.x && sprite.x + 20 >= player.x)
			{
				player.hit = true;
				*hp -= 1;
				sprite.active = false;
			}
		}
	}
}

// 빼빼로 생성
void Pepero_Scene(int cnt, int* hp)
{
	Pepero_dlt(pepero.x, pepero.y);

	if (cnt % 2 == 0)
	{
		if (pepero.y + 26 != 48)
			pepero.y += 1;
	}
	pepero.cnt += 1;

	if (pepero.hit == true)
	{
		if (pepero.x <= player.x && pepero.x + 30 >= player.x)
		{
			if (pepero.y <= player.y && pepero.y + 26 >= player.y)
			{
				*hp -= 1;
				player.hit = true;
				pepero.hit = false;
			}
		}
	}
	Pepero(pepero.x, pepero.y);

	if (pepero.cnt >= 80)
	{
		pepero.active = false;
		Pepero_dlt(pepero.x, pepero.y);
		pepero.cnt = 0;
	}
}

// 빼빼로 막대 생성
void Ppr_Stick_Scene(int* hp, int* Game_Scene)
{
	pepero.cnt += 1;
	for (int i = 0; i < 10; i++)
	{
		if (ppr_stick[i].active == false)
		{
			ppr_stick[i].x = rand() % 90 * 2;
			ppr_stick[i].y = 11;
			ppr_stick[i].active = true;
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (ppr_stick[i].active == true)
		{
			Ppr_stick_dlt(ppr_stick[i].x, ppr_stick[i].y);
			ppr_stick[i].y += 2;
			Ppr_stick(ppr_stick[i].x, ppr_stick[i].y);

			if (ppr_stick[i].y >= 47)
			{
				ppr_stick[i].active = false;
				Ppr_stick_dlt(ppr_stick[i].x, ppr_stick[i].y);
			}

			if (ppr_stick[i].x <= player.x && ppr_stick[i].x + 2 >= player.x || ppr_stick[i].x <= player.x + 2 && ppr_stick[i].x + 2 >= player.x + 2)
			{
				if (ppr_stick[i].y >= player.y && ppr_stick[i].y - 12 <= player.y)
				{
					*hp -= 1;
					player.hit = true;
				}
			}
		}

		if (pepero.cnt == 150)
		{
			Ppr_stick_dlt(ppr_stick[i].x, ppr_stick[i].y);
			*Game_Scene = 0;
		}
	}
}

// 코뿔소 생성
void Rhino_Scene( int cnt, int* Game_Scene, int* hp,int score)
{
	static int random = 0;
	static char ch = '\0';
	if (rhino.active == false)
	{
		Em_dlt(em.x, em.y);
		em.cnt++;
		Em(em.x, em.y);
		if (em.cnt == 70)
		{
			em.cnt = 0;
			rhino.active = true;
		}
	}

	if (rhino.active == true)
	{
		player.active = false;
		rhino.cnt++; // 시간 카운트


		Rhino_dlt(rhino.x, rhino.y);

		
		if (cnt % 2 == 0) // 코뿔소 이동
		{
			if (score <= 2500) // 난이도 조절
				rhino.x -= 2;
			else
				rhino.x -= 3;
			if (rhino.x <= 0)
			{
				Rhino_dlt(rhino.x, rhino.y);
				*Game_Scene = 0;
			}
		}
		if(random == 0)
			random = rand() % 26 + 97; // 랜덤으로 알파벳 설정

		ch = random;

		ABCD(85, 10, ch);

		ch = random - 32;

		if (GetAsyncKeyState(ch) & 0x8000)
		{
			ABCD_dlt(85, 10);
			if (rhino.x <= 97)
			{
				rhino.x += 15;
				random = rand() % 26 + 97; // 랜덤으로 알파벳 설정
			}
		}

		if (rhino.x <= player.x + 2 && rhino.x + 76 >= player.x + 2)
		{
			player.hit = true;
			*hp -= 1;
			if (rhino.x <= 90)
				rhino.x += 10;
			Player_dlt(player.x, player.y);
			if (player.x >= 6)
				player.x -= 6;
		}

		Rhino(rhino.x, rhino.y);

		if ( rhino.cnt == 200) // 코뿔소 삭제
		{
			ABCD_dlt(85, 10);
			GotoXY(85, 10);
			printf("     ");
			Rhino_dlt(rhino.x, rhino.y);
			*Game_Scene = 0;
		}
	}
}

// 개구마르
void Frog_Scene(int* Game_Scene, int* hp) {
	if (em.active == false) // 느낌표
	{
		Em_dlt(em.x, em.y);
		em.cnt++;
		Em(em.x, em.y);
		if (em.cnt == 100)
		{
			em.cnt = 0;
			em.active = true;
		}
	}
	else if (em.active == true) // 개구리 씬
	{
		Frog_dlt(frog.x, frog.y);

		if (frog.x <= player.x) // 개구마르 히트 판저
		{
			player.x -= 12; // 히트하면 뒤로 밀려남
			*hp -= 1;
			player.hit = true;
		}

		Frog(frog.x, frog.y); // 개구마르 생성

		if (water[0].scene == true) // 앞으로 발사
		{
			Water(water[0].x, water[0].y);
			water[0].x -= 4;
			if (water[0].x == 0) // 끝까지가면 삭제
			{
				water[0].scene = false;
				water[1].scene = true;
				Water_dlt(water[0].x, water[0].y);
			}
			if (water[0].hit == true) // 히트 판정 
			{
				if (water[0].x <= player.x)
				{
					if (water[0].y >= player.y - 1 && water[0].y - 5 <= player.y - 1)
					{
						water[0].hit = false;
						*hp -= 1;
						player.hit = true;
					}
				}
			}
		}
		else if (water[1].scene == true) // 두꺼운 물
		{
			if (water[1].cnt < 30) // Safe Zone
			{
				water[1].cnt++;

				Safe_Zone(3, 35);
			}
			if (water[1].cnt == 30) // 물발사 
			{

				Water2(water[1].x, water[1].y);
				water[1].x -= 4;
				if (water[1].x <= 4) // 끝까지가면 삭제
				{
					water[1].scene = false;
					water[2].scene = true;
					Water2_dlt(water[1].x, water[1].y);
					GotoXY(3, 35);
					printf("          ");
				}
			}
			if (water[1].hit == true) // 히트 판정 
			{
				if (water[1].x <= player.x)
				{
					*hp -= 1;
					player.hit = true;
					water[1].hit = false;
				}
			}
		}
		else if (water[2].scene == true) // 아래에서 올라옴
		{
			if (water[2].cnt < 100)
			{
				Em_dlt(em.x, 35);
				em.x = player.x;
				Em(em.x, 35);

				water[2].cnt++;
				if (water[2].cnt == 99)
				{
					water[2].x = player.x - 6;
				}

			}
			else
			{
				if (water[2].y != 2)
				{
					Water3(water[2].x, water[2].y);
					water[2].y -= 3;
					if (water[2].hit == true)
					{
						if (water[2].x <= player.x && water[2].x + 12 >= player.x || water[2].x <= player.x + 2 && water[2].x + 12 >= player.x + 2)
						{
							if (water[2].y <= player.y)
							{
								*hp -= 1;
								player.hit = true;
								water[2].hit = false;
							}
						}
					}
				}
				else
				{
					Water3_dlt(water[2].x, 47);
					*Game_Scene = 0;
					Frog_dlt(frog.x, frog.y);
				}
			}

		}


	}
}

// 지팡이 색상
int Wand_Color()
{
	int color = 9;
	color = rand() % 2 + 1;
	switch (color)
	{
	case 1:
		return GREEN;
	case 2:
		return RED;
	}
}

// 마법사 
void Wizard_Scene(int* hp, int* game_Scene)
{
	static int color = 0;
	int stmv_x = 65;
	int stmv_y = 15;



	if (em.active == true) 
	{
		Em_dlt(em.x, em.y);
		em.cnt++;
		Em(em.x, em.y);
		if (em.cnt == 100)
		{
			em.cnt = 0;
			em.active = false;
		}
	}
	else {

		if (wizard.cnt == 0) {
			Wizard(wizard.x, wizard.y);
			color = 9;
		}
		wizard.cnt++;


		if (wand.cnt == 50)
		{
			color = Wand_Color();

			for (int i = 0; i < 4; i++){
				ABCD_dlt(stmv_x + (i * 15), stmv_y);
			}

			wand.cnt = 0;
		}
		if (wizard.x <= player.x && wizard.x + 52 >= player.x)
		{
			player.hit = true;
			*hp -= 1;
			Player_dlt(player.x, player.y);
			player.x += 12;
		}
		Wand(wand.x, wand.y, color);

		// 기본 색 : 파랑
		// 빨간색 : 움직이면 대미지 
		// 초록색 : 안움직이면 대미지

		if (color == RED)
		{
			wand.cnt++;

			setColor(RED);
			ABCD(stmv_x, stmv_y, 's');
			ABCD(stmv_x + 15, stmv_y, 't');
			ABCD(stmv_x + 30, stmv_y, 'o');
			ABCD(stmv_x + 45, stmv_y, 'p');
			setColor(WHITE);

			if (player.active == true && wand.cnt >= 13)
			{
				if (player.hit == false)
				{
					player.hit = true;
					*hp -= 1;
				}
			}
		}
		else if (color == GREEN)
		{
			wand.cnt++;

			setColor(GREEN);
			ABCD(stmv_x, stmv_y, 'm');
			ABCD(stmv_x + 15, stmv_y, 'o');
			ABCD(stmv_x + 30, stmv_y, 'v');
			ABCD(stmv_x + 45, stmv_y, 'e');
			setColor(WHITE);

			if (player.active == false && wand.cnt >= 13)
			{
				if (player.hit == false)
				{
					player.hit = true;
					*hp -= 1;
				}
			}
		}
		else
		{
			wand.cnt++;
		}


		if (wizard.cnt == 400)
		{
			for (int i = 0; i < 4; i++) {
				ABCD_dlt(stmv_x + (i * 15), stmv_y);
			}
			
			*game_Scene = 0;
			Wizard_dlt(wizard.x, wizard.y);
		}


		player.active = false;
	}
}

// 베트남 
void Vietnam_Scene(int* hp, int* Game_Scene)
{
	vietnam[0].cnt++;
	for (int i = 0; i < 8; i++)
	{
		if (vietnam[i].hit == false)
		{
			
			vietnam[i].x = vietnam[8].x;
			vietnam[i].y = vietnam[8].y;
			
		}
	}
	if (vietnam[0].cnt <= 80)
	{
		Vietnam(61, 17);
		Star(vietnam[8].x, vietnam[8].y);
	}
	else {


		// 큰 별
		Star_dlt(vietnam[8].x, vietnam[8].y);


		if (vietnam[8].active == true)
			vietnam[8].x+=1;
		else
			vietnam[8].x-=1;

		if (vietnam[8].scene == 0)
			vietnam[8].y++;
		else
			vietnam[8].y--;

		if (vietnam[8].y == 47)
		{
			vietnam[8].scene = 1;
			vietnam[0].hit = true;
			vietnam[1].hit = true;
		}
		else if (vietnam[8].y == 9)
		{
			vietnam[8].scene = 0;
			vietnam[4].hit = true;
			vietnam[5].hit = true;
		}
		if (vietnam[8].x == 156)
		{
			vietnam[8].active = false;
			vietnam[2].hit = true;
			vietnam[3].hit = true;
		}
		else if (vietnam[8].x == 0)
		{
			vietnam[8].active = true;
			vietnam[6].hit = true;
			vietnam[7].hit = true;
		}

		Star(vietnam[8].x, vietnam[8].y);

		// 별 1
		if (vietnam[0].hit == true)
		{
			// 큰 별
			Star_dlt(vietnam[0].x, vietnam[0].y);


			if (vietnam[0].active == true)
				vietnam[0].x++;
			else
				vietnam[0].x-=1;

			if (vietnam[0].scene == 0)
				vietnam[0].y+=2;
			else
				vietnam[0].y-=1;

			if (vietnam[0].y >= 46)
			{
				vietnam[0].scene = 1;
				Map(0, 48);
			}
			else if (vietnam[0].y <= 9)
			{
				vietnam[0].scene = 0;		
			}
			if (vietnam[0].x == 156)
			{
				vietnam[0].active = false;
			}
			else if (vietnam[0].x <= 1)
			{
				vietnam[0].active = true;
			}

			Star(vietnam[0].x, vietnam[0].y);
		}
		// ---------------------------
		// 별 2
		if (vietnam[1].hit == true)
		{
			// 큰 별
			Star_dlt(vietnam[1].x, vietnam[1].y);


			if (vietnam[1].active == true)
				vietnam[1].x+=2;
			else
				vietnam[1].x-=2;

			if (vietnam[1].scene == 0)
				vietnam[1].y++;
			else
				vietnam[1].y -= 2;

			if (vietnam[1].y >= 47)
			{
				vietnam[1].scene = 1;
			}
			else if (vietnam[1].y == 9)
			{
				vietnam[1].scene = 0;
			}
			if (vietnam[1].x >= 155)
			{
				vietnam[1].active = false;
			}
			else if (vietnam[1].x == 1)
			{
				vietnam[1].active = true;
			}

			Star(vietnam[1].x, vietnam[1].y);
		}
		// -----------------------------
		// 별 3
		if (vietnam[2].hit == true)
		{
			// 큰 별
			Star_dlt(vietnam[2].x, vietnam[2].y);


			if (vietnam[2].active == true)
				vietnam[2].x+=2;
			else
				vietnam[2].x -= 1;

			if (vietnam[2].scene == 0)
				vietnam[2].y += 2;
			else
				vietnam[2].y -= 1;

			if (vietnam[2].y >= 46)
			{
				vietnam[2].scene = 1;
				Map(0, 48);
			}
			else if (vietnam[2].y <= 9)
			{
				vietnam[2].scene = 0;
			}
			if (vietnam[2].x >= 155)
			{
				vietnam[2].active = false;
			}
			else if (vietnam[2].x <= 1)
			{
				vietnam[2].active = true;
			}

			Star(vietnam[2].x, vietnam[2].y);
		}
		// -------------------------------
		// 별 4
		if (vietnam[3].hit == true)
		{
			GotoXY(vietnam[3].x, vietnam[3].y);
			printf("  ");

			if (vietnam[3].active == true)
				vietnam[3].x += 2;
			else
				vietnam[3].x--;

			if (vietnam[3].scene == 0)
				vietnam[3].y += 2;
			else
				vietnam[3].y -= 2;

			if (vietnam[3].y == 46)
				vietnam[3].scene = 1;
			else if (vietnam[3].y <= 2)
				vietnam[3].scene = 0;
			if (vietnam[3].x >= 177)
				vietnam[3].active = false;
			else if (vietnam[3].x <= 1)
				vietnam[3].active = true;

			GotoXY(vietnam[3].x, vietnam[3].y);
			printf("★");
		}
		// -------------------------------
		// 별 5
		if (vietnam[4].hit == true)
		{
			GotoXY(vietnam[4].x, vietnam[4].y);
			printf("  ");

			if (vietnam[4].active == true)
				vietnam[4].x += 1;
			else
				vietnam[4].x -= 2;

			if (vietnam[4].scene == 0)
				vietnam[4].y += 2;
			else
				vietnam[4].y -= 1;

			if (vietnam[4].y == 46)
				vietnam[4].scene = 1;
			else if (vietnam[4].y <= 2)
				vietnam[4].scene = 0;
			if (vietnam[4].x >= 177)
				vietnam[4].active = false;
			else if (vietnam[4].x <= 2)
				vietnam[4].active = true;

			GotoXY(vietnam[4].x, vietnam[4].y);
			printf("★");
		}
		// ----------------------
		// 별 6
		if (vietnam[5].hit == true)
		{
			GotoXY(vietnam[5].x, vietnam[5].y);
			printf("  ");

			if (vietnam[5].active == true)
				vietnam[5].x += 2;
			else
				vietnam[5].x -= 2;

			if (vietnam[5].scene == 0)
				vietnam[5].y += 2;
			else
				vietnam[5].y -= 1;

			if (vietnam[5].y == 46)
				vietnam[5].scene = 1;
			else if (vietnam[5].y <= 2)
				vietnam[5].scene = 0;
			if (vietnam[5].x >= 177)
				vietnam[5].active = false;
			else if (vietnam[5].x <= 2)
				vietnam[5].active = true;

			GotoXY(vietnam[5].x, vietnam[5].y);
			printf("★");
		}
		// ----------------------
		// 별 7
		if (vietnam[6].hit == true)
		{
			GotoXY(vietnam[6].x, vietnam[6].y);
			printf("  ");

			if (vietnam[6].active == true)
				vietnam[6].x += 2;
			else
				vietnam[6].x -= 1;

			if (vietnam[6].scene == 0)
				vietnam[6].y += 2;
			else
				vietnam[6].y -= 1;

			if (vietnam[6].y == 46)
				vietnam[6].scene = 1;
			else if (vietnam[6].y <= 2)
				vietnam[6].scene = 0;
			if (vietnam[6].x >= 177)
				vietnam[6].active = false;
			else if (vietnam[6].x <= 2)
				vietnam[6].active = true;

			GotoXY(vietnam[6].x, vietnam[6].y);
			printf("★");
		}
		// ----------------------
		// 별 8
		if (vietnam[7].hit == true)
		{
			GotoXY(vietnam[7].x, vietnam[7].y);
			printf("  ");

			if (vietnam[7].active == true)
				vietnam[7].x += 2;
			else
				vietnam[7].x -= 2;

			if (vietnam[7].scene == 0)
				vietnam[7].y += 2;
			else
				vietnam[7].y -= 2;

			if (vietnam[7].y == 46)
				vietnam[7].scene = 1;
			else if (vietnam[7].y <= 2)
				vietnam[7].scene = 0;
			if (vietnam[7].x >= 177)
				vietnam[7].active = false;
			else if (vietnam[7].x <= 2)
				vietnam[7].active = true;

			GotoXY(vietnam[7].x, vietnam[7].y);
			printf("★");
		}
		// 별 충돌판정
		for (int i = 0; i < 9; i++)
		{
			if (i <= 2 || i == 8) 
			{
				if (player.x >= vietnam[i].x && player.x <= vietnam[i].x + 22)
				{
					if (player.y <= vietnam[i].y && player.y >= vietnam[i].y - 9)
					{
						if (player.hit == false)
						{
							player.hit = true;
							*hp -= 1;
						}
					}
				}
			}
			else {
				if (player.x == vietnam[i].x || player.x + 1 == vietnam[i].x)
				{
					if (player.y - 1 == vietnam[i].y)
					{
						if (player.hit == false)
						{
							player.hit = true;
							*hp -= 1;
						}
					}
				}
			}
		}
		
		
		if (vietnam[0].cnt == 500)
		{
			for (int i = 0; i < 9; i++)
			{
				if (i <= 2 || i == 8)
				{
					Star_dlt(vietnam[i].x, vietnam[i].y);
				}
				else {
					GotoXY(vietnam[i].x, vietnam[i].y);
					printf("  ");
				}
			}
			*Game_Scene = 0;
		}

	}
}

// 롤린
void Rollin_Scene(int* hp, int* Game_Scene) {

	if (em.active == true)
	{
		Em_dlt(em.x, em.y);
		em.cnt++;
		Em(em.x, em.y);
		if (em.cnt == 70)
		{
			em.cnt = 0;
			em.active = false;
			Em_dlt(em.x, em.y);
			RollinMusic();
		}
	}
	else {

		rollin[1].cnt++; // 롤린 씬 카운트

		rollin[0].cnt++; // 에니메이션 카운트

		for (int i = 0; i < 4; i++)
		{
			Rollin_dlt(rollin[i].x, rollin[i].y);

			if (rollin[0].active == true) {

				rollin[i].x += 2;

				if (rollin[3].x >= player.x - 14 && rollin[2].cnt == 0)
					rollin[0].active = false;
				if (rollin[3].x >= 170) {
					rollin[0].active = false;
					rollin[1].active = true;
				}
			}
			else {
				if (rollin[1].cnt % 2 == 0)
					rollin[i].x -= 1;
				rollin[2].cnt++;
				if (rollin[2].cnt == 80)
					rollin[0].active = true;
			}

			if (rollin[1].active == true)
			{

				if (rollin[3].x == 152) {
					rollin[2].active = true;
					rollin[1].active = false;
				}
			}
			else if (rollin[2].active == true) {

				rollin[3].cnt++;
				if (rollin[3].cnt <= 20)
					rollin[0].x += 1;
				else if (rollin[3].cnt <= 40)
					rollin[1].x -= 1;
				else if (rollin[3].cnt <= 60)
					rollin[2].x += 1;
				else if (rollin[3].cnt <= 80)
					rollin[3].x -= 1;
				if (rollin[i].x <= 3) rollin[i].x += 1;
			}


			// 롤린 애니메이션
			if (rollin[0].cnt <= 8) {
				Rollin1(rollin[i].x, rollin[i].y);
			}
			else if (rollin[0].cnt <= 16) {
				Rollin2(rollin[i].x, rollin[i].y);
			}
			else if (rollin[0].cnt <= 24) {
				Rollin3(rollin[i].x, rollin[i].y);
			}
			else if (rollin[0].cnt <= 32) {
				Rollin2(rollin[i].x, rollin[i].y);
			}
			else
				rollin[0].cnt = 0;
		}



		// 롤린 충돌 판정
		for (int i = 0; i <= 4; i++)
		{
			if (player.x >= rollin[i].x && player.x <= rollin[i].x + 6)
			{
				if (player.y <= rollin[i].y && player.y >= rollin[i].y - 4)
				{
					if (player.hit == false)
					{
						player.hit = true;
						*hp -= 1;
					}
				}
			}
		}

		// 롤린 씬 끝내기
		if (rollin[1].cnt == 430)
		{
			for (int i = 0; i < 4; i++)
			{
				Rollin_dlt(rollin[i].x, rollin[i].y);
			}
			*Game_Scene = 0;
			GameMusic();
		}
	}
}

// 점수 
void Score(int* score,int cnt)
{
	if(cnt % 2 == 0)
		*score += 1;
	GotoXY(165, 2);
	printf("SCORE : %5d", *score);
}


int main()
{
	MENU:
	Game();
	StartMenu(); // 스타트 메뉴 		
	Map(0, 48); // 바닥
	InGameMusic(); // 배경 음악

	long long cnt = 1;
	int hp = 5; // 플레이어 HP
	int Game_Scene = 0; // 장애물 씬
	int last_Game_Scene = rand() % 7 + 1;
	int Game_Scene_cnt = 0; // 게임 씬 사이에 텀을 주기위해
	int hit_cnt = 0;
	int jump = 0;
	int score = 0;

	while (1)
	{
		Player_dlt(player.x, player.y); // 플레이어 제거

		Player_Move(Game_Scene); // 플레이어 이동 
		Jump(&jump, Game_Scene); // 플레이어 점프

		Player_Hit(&hit_cnt); // 플레이어가 맞으면 잠깐 빨강색으로 변함

		Player(player.x, player.y); // 플레이어 생성
		setColor(WHITE);

		// --------------
		//  게임 씬 설정 
		// --------------

		if (Game_Scene == 0)
		{
			Game_Scene_cnt++;
			if (Game_Scene_cnt == 70) // 게임 씬 사이에 대기 시간 
			{

				Game_Scene = rand() % 7 + 1;

				while (last_Game_Scene == Game_Scene) {
					Game_Scene = rand() % 7 + 1;
				}
				last_Game_Scene = Game_Scene;


				if (Game_Scene == 1) // 사이다 장애물 
				{
					Sprite_Scene_Set(&Game_Scene_cnt);
				}
				else if (Game_Scene == 2) // 빼빼로
				{
					Pepero_Scene_Set(&Game_Scene_cnt);
				}
				else if (Game_Scene == 3) // 코뿔소
				{
					Rhino_Scene_Set(&Game_Scene_cnt);
				}
				else if (Game_Scene == 4) // 개구마르
				{
					Frog_Scene_Set(&Game_Scene_cnt);
				}
				else if (Game_Scene == 5) // 검은 마법사
				{
					Wizard_Scene_Set(&Game_Scene_cnt);
				}
				else if (Game_Scene == 6) // 베이트남
				{
					Vietnam_Scene_Set(&Game_Scene_cnt);
				}
				else if (Game_Scene == 7) // 롤린
				{
					Rollin_Scene_Set(&Game_Scene_cnt);
				}
			}
		}

		// --------------
		//  게임 씬 생성
		// --------------

		if (Game_Scene == 1) // 사이다
		{
			Sprite_Scene(cnt, &hp, &Game_Scene); // 사이다 생성
		}
		else if (Game_Scene == 2) // 빼빼로
		{
			if (pepero.active == true) // 빼빼로 박스
			{
				Pepero_Scene(cnt, &hp);
			}
			else if (pepero.active == false) // 빼빼로 막대
			{
				Ppr_Stick_Scene(&hp, &Game_Scene);
			}
		}
		else if (Game_Scene == 3) // 코뿔소
		{
			Rhino_Scene(cnt, &Game_Scene, &hp,score);

		}
		else if (Game_Scene == 4) // 개구마르 
		{
			Frog_Scene(&Game_Scene, &hp);
		}
		else if (Game_Scene == 5) // 마법사
		{
			Wizard_Scene(&hp, &Game_Scene);
		}
		else if (Game_Scene == 6) // 비엣트남
		{
			Vietnam_Scene(&hp, &Game_Scene);
		}
		else if (Game_Scene == 7) // 롤린
		{
			Rollin_Scene(&hp, &Game_Scene);
		}


		//-------------
		// 플레이어 hp
		//------------- 

		Hp_dlt();

		Hp(hp);


		if (hp == 0) // 플레이어가 죽으면 break
			break;

		Score(&score, cnt); // 점수
		Sleep(25);
		cnt++;
	}

	PlaySound(NULL, 0, 0); // 죽으면 노래 끔
	GameOver(score);a
	goto MENU;

	return 0;
}	