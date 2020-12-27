#include <locale.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int returnWord(int mass[15]) {
    long long arr[8];//создаём массив из 8 элементов так как максимально 
    //возможное количество чисел для строки из 15 символов равно половине от её длины 
    int lastIndex = 0;//обнуляем индекс для запоминания последнего числа в массиве mass
    int indexArr = 0;//обнуляем индекс 
    for (int i = 0; i < 15; i++) {
        if (mass[i] == 0) {
            long long number = 0;//максимально возможно число содержит 14 символов, поэтому используем long long
            long long mul = 1;//разряд
            for (int j = i-1; j >= lastIndex; j--, mul *= 10)//собираем число
            {
                number += mass[j] * mul;// увеличиваем на число mul для записи цифры в разряд числа
            }
            arr[indexArr] = number;//сохраняем массив
            lastIndex = i+1;//увеличиваем индекс последнего 0
            indexArr++;//увеличиваем индекс массива arr
        }
    }
    cout << "(";
    for (int i = 0; i < indexArr; i++) //выводим результат
    {
        cout << arr[i];
        if (i != indexArr - 1) {
            cout << ", ";
        }
    }
    cout << ")  ";
    return 1;
}
int main()
{
    setlocale(LC_ALL, "Rus");//меняем язык консоли на русский
    int mass[4][15]; //массив с цифрами
   for (int i = 0; i < 4; i++) //заполняем массив
   {
        for (int j = 0; j < 14; j++) {
            cout << "Введите [" << i << "][" << j << "] цифру: ";
            int numEnter;
            cin >> numEnter;
            mass[i][j] = numEnter % 10;//если будет введено число 
            cout << "\n";
        }
        mass[i][14] = 0;//последний элемент всегда 0 
    }
    
    for (int i = 0; i < 4; i++) //вызываем функцию для каждого массива
    {
        returnWord(mass[i]);
    }
    
}
