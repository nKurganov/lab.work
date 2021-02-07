#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;
//1. 	������� ��������� ���� F1 �� �����, ��� �� 10 ����� � �������� � ���� ����������
//2. 	��������� �������.
//1) 	����������� � ���� F2 ������ ������ ������ �� F1.
//2) 	���������� ������ ������ F1 � F2(� ������).

//��������� ��������� ������
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
    setlocale(LC_ALL, "Rus");//������ ���� ������� �� �������
    const char f1[] = "F1";
    const char f2[] = "F2";
    fstream fl1_wr(f1, ios::out);//��������������� �������� �����
    for (int i = 0; i < 200; i++)
    {
        //��������� ������ � ����
        fl1_wr << GenerateAlphaNumStr_N(rand() % 40 + 20); fl1_wr << "\n";
    }
    fl1_wr.close();
    int k = 1;
    const int MAXLINE = 255; //������������ ����� ������
    FILE* in, 	//�������� ����
        * out;	//����������� ����
    in = fopen(f1, "r");
    out = fopen(f2, "w");
    char buf[MAXLINE];	//������, � ������� ������� ����������� �����������
    //����������� ����� ������ ����� � ������
    while (fgets(buf, MAXLINE, in) != NULL) {
        if(k%2==0)//���� ����� ������ ������ ���������� � ���� F2
            fputs(buf, out);
        k++;
    }
    fclose(in);
    fclose(out);
    in = fopen(f1, "r");
    int bytes;
    out = fopen(f2, "r");
    //��������� ���������� ����� ����� f1 � f2 ��� ������ ������� getc � 
    //����������� �������� bytes �� ��� ��� ���� ������ ���������� 
    for (bytes = 0; getc(in) != EOF; ++bytes);
    printf("������ ����� F1: %d �����\n", bytes);
    for (bytes = 0; getc(out) != EOF; ++bytes);
    printf("������ ����� F2: %d �����\n", bytes);
    fclose(in);
    fclose(out);
}