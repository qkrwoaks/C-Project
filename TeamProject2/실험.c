#include <stdio.h>
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS 


int main()
{
	char name[20];
	FILE* fp = fopen("test.txt", "w"); //test������ w(����) ���� ����

	for (int i = 0; i < 5; i++) {
		scanf("%s",name);
		fputs(name, fp); //���ڿ� �Է�
		fputs("\n", fp);
	}
	fputs("end", fp);

	fclose(fp); //���� ������ �ݱ�


	return 0;

}
