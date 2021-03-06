#include < locale.h >
#include < stdio.h >
#include <iostream>

using namespace std;
//Лабораторная работа № 4
//1) Сформировать одномерный массив целых чисел, используя датчик случайных чисел.
//2) Распечатать полученный массив.
//3) Удалить элемент с номером К.
//4) Добавить после каждого четного элемента массива эле - мент со значением 0.
//5) Распечатать полученный массив.

int main() {
	setlocale(LC_ALL, "Rus");//меняем язык консоли на русский
	const int massSize = 300;// максимальный размер массива
	int k, num;// k - удаляемый элемент массива, num - размер массива который вводит пользователь
	int numArrey[massSize];//выделяем память под этот массив
	while (true)//для удобства проверки выполняем все операции в цикле
	{
		cout << "Введите размерность массива: ";
		cin >> num;
		if (0 < num < massSize) //если введённая длина массива находится в пределах от 1 до 300
		{
			cout << "\n[";
			for (int i = 0; i < num; i++) {
				numArrey[i] = rand() % 100 -50 ;//записываем в i элемент массива случайное число от -50	 до 100
				cout << numArrey[i] << " ";//выводим элемент массива
			}
			cout << "]\n"<< endl;
			cout << "Введите индекс элемента массива который необходимо удалить - ";
			cin >> k;//получаем k элемент, который нужно удалить
			for (int i = 0; i < num - 1; i++)// перебираем все элементы массива numArrey 
			{
				if(i >= k) //если нашли i Больше либо равен k то сдвигаем массив на 1 элемент
				{
					numArrey[i] = numArrey[i + 1];// заменяем текущий элемент на следующий
				}
			}
			numArrey[num-1] = 0;// последний элемент удаляем(обнуляем)
			num--;//уменьшаем размер массива на единицу
			cout << endl;
			cout << "\n[";
			for (int i = 0; i < num; i++)// перебираем все элементы массива numArrey 
			{
				if (numArrey[i] % 2 == 0) // если элемент массива чётный 
				{
					for (int j = num; j > i+1; j--)// сдвигаем массива на 1 вперёд
					{
						numArrey[j] = numArrey[j-1];
					}
					numArrey[i+1] = 0;// вставляем 0 как следующий элемент 
					i++;//увеличиваем индекс чтобы не обращаться к вставленному числу
					num++;//увеличиваем размер
				}
			}
			for (int i = 0; i < num; i++)// выводим массива
			{
				cout << numArrey[i] << " ";
			}
			cout << "]\n" << endl;
		}
		else {
			cout << "Введите размерность массива: ";
		}
	}
	return 0;
}
