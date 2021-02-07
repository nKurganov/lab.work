#include <locale.h>
#include <stdio.h>
#include <iostream>
#include <locale>
#include <conio.h>
#include <fstream>

using namespace std;
//Записи в линейном списке содержат ключевое поле типа int.
//Сформировать однонаправленный список.Удалить из него элемент с заданным номером, 
//добавить элемент с заданным номером;
//Вариант 1


struct point
{
    int data; //информационное поле
    point* next; //адресное поле

};

//создание списка
point* makePointList(int n)
{
    point* beg;//указатель на первый элемент
    point* p, * r;//вспомогательные указатели
    beg = new(point);//выделяем память под первый элемент
    cout << "Введите число: ";
    cin >> beg->data;//вводим значение информационного поля
    cout << "\n";
    beg->next = 0;//обнуляем адресное поле
    //ставим на этот элемент указатель p (последний элемент)
    p = beg;
    for (int i = 0; i < n - 1; i++)
    {
        r = new(point);//создаем новый элемент
        cout << "Введите число: ";
        cin >> r->data;
        cout << "\n";
        r->next = 0;
        p->next = r;//связываем p и r
        //ставим на r указатель p (последний элемент)
        p = r;

    }
    return beg;//возвращаем beg как результат функции
}

//подсчёт длины списка
int getLen(point* a) {
    int c=0;
    while (a != NULL) {
        c++;
        a = a->next;
    }
    return c;
}
//добавление числа num на место place

point* addToList(int num, int place, point* list) {
    point* temp, * p;
    p = list;//передаём в p list

    //создаём новую структуру 
    temp = new point; 
    temp->data = num;
    temp->next = NULL;
    int len = getLen(list);//получаем длину списка
    if (p == NULL) {
        return temp;//если список пуст возвращаем новый список
    }
    else if (place < len && place>0) {
        while (p->next != NULL)
        {
            if (place == 1)
            {
                //вставляем новый элемент между элементами i-1 и i
                temp->next = p->next;
                p->next = temp;
            }
            place--;
            p = p->next;
        }
        return list;
    }
    else if (place <= 0) {
        //вставляем в начало
        //сохраняем первый элемент в temp
        temp->next = list->next;
        temp->data = list->data;
        //меняем первый элемент
        list->data = num;
        //вставляем ссылку на следующий объект
        list->next = temp;
        return list;
    }
    else if (place >= len) {
        //вставляем в конец
        while (p->next != NULL)
        { 
            p = p->next;
        }//переходим до последнего элемента и добавляем новый
        p->next = new point;
        p->next->data = num;
        p->next->next = NULL;
    }
    return list;
    
}
//удаление из списка числа с индексом place
point* delFromList( int place, point* list) {
    point* p;
    p = list;
    int len = getLen(list);
    if (list == NULL) {
        return NULL;//возвращаем null если список пуст
    }
    else if (place < len-1 && place>0) {
        while (p->next != nullptr)//переходим к элементу с индексом i-1
        {
            if (place == 1)
            {
                p->next = p->next->next;// удаляем связь со следующим элементом
            }
            p = p->next;
            place--;
        }
    }
    else if (place == 0) {
        list = p->next;
    }
    else if (place >= len - 1) {
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        p->next = p->next->next;
    }
    return list;
}


void save(point* Head) {
    ofstream fout("save");
    if (fout)
    {
        point* temp = Head; //Объявляем указатель и изначально он указывает на начало

        while (temp != NULL) //Пока по адресу на начало хоть что-то есть
        {
            //Выводим все элементы структуры в файл
            fout << temp->data << endl; // Вывод цены
            temp = temp->next; //Указываем на следующий адрес из списка
        }
        fout.close();
    }
    else
        cout << "Error creating file!" << endl;
}
point* load(void) {
    fstream f;
    point* beg = new point;
    point* p;
    point* r;
    f.open("save", ios::in);//открываем поток для чтения
    int id = 1;//id для вывода номера
    do
    {
        //достаём данные
        if (id == 1) {
            f >> beg->data;
            beg->next = new point;
            p = beg;
            id = 0;
        }
        else {
            r = new(point);//создаем новый элемент
            f >> r->data;
            r->next = NULL;
            p->next = r;//связываем p и r
            //ставим на r указатель p (последний элемент)
            p = r;
        }
        if (f.eof())break;
        //выводим их
    } while (!f.eof());
    return delFromList(getLen(beg), beg);//возвращаем без последнего ошибочного элемента 
}
//удаляем список
void delList(point* list) {
    delete list;
}
//печать списка
void print_list(point* beg)
{
    point* p = beg;//начало списка
    int len = getLen(beg);
    if (len != 0) {
        while (p != 0)
        {
            cout << p->data << "\t";
            p = p->next;//переход к следующему элементу
        }
    }
    else {
        cout << "Список пуст";
    }
    cout << "\n";
}





int main() {
	setlocale(LC_ALL, "Rus");//меняем язык консоли на русский
	point* oneList;//односторонний список 
    int n;
    cout << "Размер списка: ";
    cin >> n;
    oneList = makePointList(n);
    
    print_list(oneList);

    cout << "Введите индекс элемента перед которым вставится новый элемент: ";
    cin >> n;
    int data = 0;
    cout << "Значение элемента: ";
    cin >> data;
    oneList = addToList(data, n, oneList);
    print_list(oneList);
    cout << "Элемент с каким номером удалить: ";
    cin >> n;
    oneList = delFromList( n, oneList);
    print_list(oneList);
    save(oneList);
    delList(oneList);
    oneList = load();
    system("pause");
	return 0;

}

