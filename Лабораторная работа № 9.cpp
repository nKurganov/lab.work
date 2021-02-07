#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;
//1. 	Ñîçäàòü òåêñòîâûé ôàéë F1 íå ìåíåå, ÷åì èç 10 ñòðîê è çàïèñàòü â íåãî èíôîðìàöèþ
//2. 	Âûïîëíèòü çàäàíèå.
//1) 	Ñêîïèðîâàòü â ôàéë F2 òîëüêî ÷åòíûå ñòðîêè èç F1.
//2) 	Ïîäñ÷èòàòü ðàçìåð ôàéëîâ F1 è F2(â áàéòàõ).

//ãåíåðàòîð ñëó÷àéíîé ñòðîêè
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
    setlocale(LC_ALL, "Rus");//ìåíÿåì ÿçûê êîíñîëè íà ðóññêèé
    const char f1[] = "F1";
    const char f2[] = "F2";
    fstream fl1_wr(f1, ios::out);//äâóíàïðàâëåííûé ôàéëîâûé ïîòîê
    for (int i = 0; i < 200; i++)
    {
        //äîáàâëÿåì äàííûå â ôàéë
        fl1_wr << GenerateAlphaNumStr_N(rand() % 40 + 20); fl1_wr << "\n";
    }
    fl1_wr.close();
    int k = 1;
    const int MAXLINE = 255; //ìàêñèìàëüíàÿ äëèíà ñòðîêè
    FILE* in, 	//èñõîäíûé ôàéë
        * out;	//ïðèíèìàþùèé ôàéë
    in = fopen(f1, "r");
    out = fopen(f2, "w");
    char buf[MAXLINE];	//ñòðîêà, ñ ïîìîùüþ êîòîðîé âûïîëíÿåòñÿ êîïèðîâàíèå
    //êîïèðîâàíèå ñòðîê îäíîãî ôàéëà â äðóãîé
    while (fgets(buf, MAXLINE, in) != NULL) {
        if(k%2==0)//åñëè íîìåð ñòðîêè ÷¸òíûé çàïèñûâàåì â ôàéë F2
            fputs(buf, out);
        k++;
    }
    fclose(in);
    fclose(out);
    in = fopen(f1, "r");
    int bytes;
    out = fopen(f2, "r");
    //âû÷èñëÿåì êîëè÷åñòâî áèòîâ ôàéëà f1 è f2 ïðè ïîìîùè ôóíêöèè getc è 
    //óâåëè÷èâàåì çíà÷åíèÿ bytes äî òåõ ïîð ïîêà ñèìâîë ñóùåñòâóåò 
    for (bytes = 0; getc(in) != EOF; ++bytes);
    printf("Ðàçìåð ôàéëà F1: %d áèòîâ\n", bytes);
    for (bytes = 0; getc(out) != EOF; ++bytes);
    printf("Ðàçìåð ôàéëà F2: %d áèòîâ\n", bytes);
    fclose(in);
    fclose(out);
}
