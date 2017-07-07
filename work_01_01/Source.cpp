#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <process.h>

#define _CRT_SECURE_NO_WARNINGS

/* Определение количества слов в тексте */
int get_word_count(char*);

/* получить все строки из файла */
void get_strings(char*);

/* вывести на экран */
void print_text(char*);

int get_word_count(char *buff)
{
	int word = 0;   // количество слов

	char *pstr;

	pstr = strtok(buff, " ,.-\n\t\"?«»...;:—*+");  // пока есть лексемы

	while (pstr != NULL)
	{
		if (strlen(pstr) >= 2)
		{
			word++;
		}

		pstr = strtok(NULL, " ,.-\n\t\"?«»...;:—*+");
	}

	return word;
}


void get_strings(char * InText)
{
	FILE* file;
	fopen_s(&file, "file.dat", "r");
	if (!file)
	{
		puts("Невозможно создать файл");
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
			printf("Длина строки %d больше 70 знаков - строка не будет принята в обработку\n", i + 1);
		}

		i++;
	}

	fclose(file);
}


void print_text(char * InText)
{
	puts("Исходный текст без строк, длина которых больше 70 символов\n");
	puts("--------------------------------------------------------------");

	printf("%s\n", InText);
}


void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Выделяем память и заполняем нулями
	char *buff = (char*)calloc(1000, sizeof(char));
	if (!buff)
		printf("Не хватает памяти");

	get_strings(buff);

	int count = strlen(buff);

	if (count <= 1000)
	{
		print_text(buff);
		printf("В тексте %d слов", get_word_count(buff));
	}

	else
	{
		puts("Длина текста больше 1000 символов");
	}

	puts("\n\nНажмите любую клавишу для выхода...");

	_getch();
}