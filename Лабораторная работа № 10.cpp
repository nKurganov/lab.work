#include <iostream>
using namespace std;
//Написать программу, в которой создаются динамические массивы и  
//выполнить их обработку всоответствии со своим вариантом. 
//3. Порядок выполнения работы
//1. Ввести размер массива;
//2.Сформировать массив с помощью операции new или библиотечных функций malloc(calloc);
//3.Заполнить массив(можно с помощью датчика случайных чисел);
//4.Выполнить задание варианта, сформировать новый массив(ы) - результат(ы);
//5.Напечатать массив(ы) - результат(ы);
//6.Удалить динамические массивы с помощью операции delete или библиотечной функции free.

//Вариант 1.	
//Сформировать одномерный массив Удалить из него элемент с заданным номером, добавить элемент с заданным номером;
int main()
{
    setlocale(LC_ALL, "Rus");//меняем язык консоли на русский
    int n;
    cout << "Введите размер массива:"; cin >> n; cout << "\n";
    int* mass = new int[n];//создаем динамический массив
    //заполняем его
    for (int i = 0; i < n; i++) 
    {
        mass[i] = rand();
    }
    //выводим на экран
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << "\n";
    //создаем вспомогательный динамический массив в который будут записаны все элементы массива mass кроме k-того и уменьшаем n
    int* temp = new int[--n];
    int k = 0;
    cout << "Введите индекс удаляемого элемента:"; cin >> k; cout << "\n";
    //если k выходим за рамки от 0 до n, k присваиваем ближайший предел
    if (k >= n) {
        k = n - 1;
    }
    else if (k < 0) {
        k = 0;
    }
    //в temp переписываем все значения кроме k-того
    for (int i = 0; i < n; i++)
    {
        if (k > i)
            temp[i] = mass[i];
        else
            temp[i] = mass[i+1];
    }
   
    mass = temp;//передаем в mass temp
    //выводим mass на экран 
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << "\n";
    temp = new int[++n];//изменяем размер массива temp для добавления элемента
    k = 0;
    cout << "Введите индекс элемента перед которым вставить элемента:"; cin >> k; cout << "\n";
    //если k выходим за рамки от 0 до n, k присваиваем ближайший предел
    if (k >= n) {
        k = n - 1;
    }
    else if (k < 0) {
        k = 0;
    }
    //в temp переписываем все значения до k-того после вставляем k-тый
    // элемент когда i станет равен k и затем переписываем в temp значения mass с уменьшенным на 1 индексом
    for (int i = 0; i < n; i++)
    {
        if (k > i)
            temp[i] = mass[i];
        else if (k == i)
            temp[i] = rand();
        else
            temp[i] = mass[i - 1];
    }

    mass = temp;
    //выводим mass на экран 
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << "\n";
    free( mass);//удаляем mass и temp из памяти

    system("pause");

    return 0;

}
