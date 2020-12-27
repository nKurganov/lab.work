﻿#include < locale.h >
#include < stdio.h >
#include <math.h>
#include <iostream>

using namespace std;


void FIOprint(string firstName, string lastName = "Имя", string patronymic = "Отчество") {
	string result = firstName + " ";
	if (lastName != "Имя") {
		result += lastName + " ";
	}
	if (patronymic != "Отчество") {
		result += patronymic + " ";
	}
	cout << result + "\n";
}


void minFromParams(unsigned char number, int n, ...) {
	int min = INT_MAX;
	int num;
	int* p = &n;//получаем список параметров
	
	while (number--) {
		if (*(p) < min)//сравниваем текущий параметр
		{
			min = *(p);//если он меньше минимума передаём 
		}
		p++;//перемещаемся на следующий параметр
	}
	cout<<"Минимальный параметр равен: "<< min <<"\n";
}

//перегрузка функция для тип int
double avgArrey(int mass[10]) {
	
	int sum = 0;
	for(int i = 0; i<10; i++) {//вычисляем сумму 10-ти элементов массива
		sum += mass[i]; 
	}
	return ((double)sum) / 10;//возвращаем среднее значение
}

//перегрузка функция для тип double
double avgArrey(double mass[10]) {

	double sum = 0;
	for (int i = 0; i < 10; i++) {//вычисляем сумму 10-ти элементов массива
		sum += mass[i]; 
	}
	return ((double)sum) / 10;//возвращаем среднее значение
}

//перегрузка функция для тип float
double avgArrey(char mass[10]) {

	char sum = 0;
	for (int i = 0; i < 10; i++) {//вычисляем сумму 10-ти элементов массива
		sum += mass[i]; 
	}
	return ((double)sum) / 10;//возвращаем среднее значение
}


template <typename T>//параметр T
//функция с параметром T, зависит от передаваемого параметра
double avgTArrey( T mass[10]) {

	T sum = 0;
	for (int i = 0; i < 10; i++) //вычисляем сумму 10-ти элементов массива
	{
		sum += mass[i];
	}
	
	return ((double)sum) / 10;//возвращаем среднее значение
}

//функция 3*sin(sqrt(x)) + 0.35*x - 3.8 = 0 выраженное через x
double func(double x) {
	return (-3.0 * sin(sqrt(x)) + 3.8)/0.35;
}

//функция для вычисления x методом итераций 
double calc(double (*f)(double), double a = 2, double b = 3, double e = 0.0001) {
	double x0 = a,  // Начальное приближение
		x1 = b;
	while(true)
	{
		x1 = f(x0);//вычисляем f(a)
		if (fabs(x1 - x0) < e) break;//проверяем 
		x0 = x1;
	}
	return x1;
}

int main() {
	setlocale(LC_ALL, "Rus");//меняем язык консоли на русский

	//Задание 1
	FIOprint("Иванов", "Иван", "Иванович");//параметры заданы явно
	FIOprint("Иванов");//параметры опущены
	FIOprint("Иванов", "Иван");//часть параметров задана явно, а часть опущена

	//Задание 2
	minFromParams(3, 2, -51, 5);//3 параметра
	minFromParams(2, 35, 0);//2 параметра
	minFromParams(1, 56);//1 параметр
	
	//задание 3
	double avg;//среднее число
	//массивы для вычислений
	int mass1[10] = {1,2,3,4,5,6,7,8,9,10};
	double mass2[10] = {1.562,834.23,672.26,322.623, 6236.623,2.3,55.622, 9923,25.523552355 };
	char mass3[10] = { 'f','s','h','F','q','G','в','2','9',';' };
	avg = avgArrey(mass1);
	cout << "Среднее арифметическое массива int: " << avg << "\n";
	avg = avgArrey(mass2);
	cout << "Среднее арифметическое массива double: " << avg << "\n";
	avg = avgArrey(mass3);
	cout << "Среднее арифметическое массива char: " << avg << "\n";
	//задание 4
	avg = avgTArrey(mass1);
	cout << "Среднее арифметическое массива int: " << avg << "\n";
	avg = avgTArrey(mass2);
	cout << "Среднее арифметическое массива double: " << avg << "\n";
	avg = avgTArrey(mass3);
	cout << "Среднее арифметическое массива char: " << avg << "\n";
	//задание 5
	cout << "Значение x = " << calc(&func);
	cout << "Исходные данные: 2.2985";
	return 0;
}
