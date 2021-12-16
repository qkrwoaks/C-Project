#include <stdio.h>
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS 


int main()
{
	char name[20];
	FILE* fp = fopen("test.txt", "w"); //test파일을 w(쓰기) 모드로 열기

	for (int i = 0; i < 5; i++) {
		scanf("%s",name);
		fputs(name, fp); //문자열 입력
		fputs("\n", fp);
	}
	fputs("end", fp);

	fclose(fp); //파일 포인터 닫기


	return 0;

}
