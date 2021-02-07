#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;
//1. 	Создать текстовый файл F1 не менее, чем из 10 строк и записать в него информацию
//2. 	Выполнить задание.
//1) 	Скопировать в файл F2 только четные строки из F1.
//2) 	Подсчитать размер файлов F1 и F2(в байтах).

//генератор случайной строки
string GenerateAlphaNumStr_N(int n)
{
    static char randommmm[] =
    {
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g',
        'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', '1', '2', '3', '4',
        '5', '6', '7', '8', '9', '0'
    };

    string result;

    for (int i = 0; i < n; ++i)
        result += randommmm[rand() % 36 + 0];

    return result;
}
int main()
{
    setlocale(LC_ALL, "Rus");//меняем язык консоли на русский
    const char f1[] = "F1";
    const char f2[] = "F2";
    fstream fl1_wr(f1, ios::out);//двунаправленный файловый поток
    for (int i = 0; i < 200; i++)
    {
        //добавляем данные в файл
        fl1_wr << GenerateAlphaNumStr_N(rand() % 40 + 20); fl1_wr << "\n";
    }
    fl1_wr.close();
    int k = 1;
    const int MAXLINE = 255; //максимальная длина строки
    FILE* in, 	//исходный файл
        * out;	//принимающий файл
    in = fopen(f1, "r");
    out = fopen(f2, "w");
    char buf[MAXLINE];	//строка, с помощью которой выполняется копирование
    //копирование строк одного файла в другой
    while (fgets(buf, MAXLINE, in) != NULL) {
        if(k%2==0)//если номер строки чётный записываем в файл F2
            fputs(buf, out);
        k++;
    }
    fclose(in);
    fclose(out);
    in = fopen(f1, "r");
    int bytes;
    out = fopen(f2, "r");
    //вычисляем количество битов файла f1 и f2 при помощи функции getc и 
    //увеличиваем значения bytes до тех пор пока символ существует 
    for (bytes = 0; getc(in) != EOF; ++bytes);
    printf("Размер файла F1: %d битов\n", bytes);
    for (bytes = 0; getc(out) != EOF; ++bytes);
    printf("Размер файла F2: %d битов\n", bytes);
    fclose(in);
    fclose(out);
}