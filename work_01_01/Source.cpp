#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <process.h>

#define _CRT_SECURE_NO_WARNINGS

/* ����������� ���������� ���� � ������ */
int get_word_count(char*);

/* �������� ��� ������ �� ����� */
void get_strings(char*);

/* ������� �� ����� */
void print_text(char*);

int get_word_count(char *buff)
{
	int word = 0;   // ���������� ����

	char *pstr;

	pstr = strtok(buff, " ,.-\n\t\"?��...;:�*+");  // ���� ���� �������

	while (pstr != NULL)
	{
		if (strlen(pstr) >= 2)
		{
			word++;
		}

		pstr = strtok(NULL, " ,.-\n\t\"?��...;:�*+");
	}

	return word;
}


void get_strings(char * InText)
{
	FILE* file;
	fopen_s(&file, "file.dat", "r");
	if (!file)
	{
		puts("���������� ������� ����");
		return;
	}

	int i = 0;

	char* str = (char*)calloc(200, sizeof(char));;

	while (!feof(file))
	{
		fgets(str, 300, file);
		if (strlen(str) <= 70)
		{
			strcat(InText, str);
		}

		else
		{
			printf("����� ������ %d ������ 70 ������ - ������ �� ����� ������� � ���������\n", i + 1);
		}

		i++;
	}

	fclose(file);
}


void print_text(char * InText)
{
	puts("�������� ����� ��� �����, ����� ������� ������ 70 ��������\n");
	puts("--------------------------------------------------------------");

	printf("%s\n", InText);
}


void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// �������� ������ � ��������� ������
	char *buff = (char*)calloc(1000, sizeof(char));
	if (!buff)
		printf("�� ������� ������");

	get_strings(buff);

	int count = strlen(buff);

	if (count <= 1000)
	{
		print_text(buff);
		printf("� ������ %d ����", get_word_count(buff));
	}

	else
	{
		puts("����� ������ ������ 1000 ��������");
	}

	puts("\n\n������� ����� ������� ��� ������...");

	_getch();
}