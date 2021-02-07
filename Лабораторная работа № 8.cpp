#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;
//Сформировать двоичный файл из элементов, заданной в варианте структуры, распечатать
//его содержимое, выполнить удаление и добавление элементов в соответствии со своим вариантом,
//используя для поиска удаляемых или добавляемых элементов функцию.Формирование, печать,
//добавление и удаление элементов оформить в виде функций. Предусмотреть сообщения об ошибках 
//при открытии файла и выполнении операций ввода / вывода.
//10. Вывести измененный файл на экран.
//Вариант 1
//Структура "Абитуриент":
//-фамилия, имя, отчество;
//-год рождения;
//-оценки вступительных экзаменов(3);
//-средний балл аттестата.
//Удалить элемент с указанным номером, добавить элемент после элемента с указанной фамилией.


struct Enrollee //структура учиника
{
    string Famil;//Фамилия
    string Imya;//Имя
    string Otch;//Отчество
    string birfDay;//дата рождения
    int marks[3];//оценки
    double avg;//средняя оценку
};
//удалить k-ый элемет из файла
void del_num(const char* filename, int k)
{
    fstream temp("temp", ios::out, ios::binary);//исходный файл
    fstream f(filename, ios::in, ios::binary);//вспомогательный файл
    Enrollee a;//буфер для чтения данных из файла
        //считываем данные из исходного файла в буфер
    int id = 1;
    do {
        f >> a.Famil;
        f >> a.Imya;
        f >> a.Otch;
        f >> a.birfDay;
        f >> a.marks[0];
        f >> a.marks[1];
        f >> a.marks[2];
        f >> a.avg;
        if (f.eof())break;
        if (id != k)//если номер записи не равен х
        {
            temp << a.Famil; temp << "\n";
            temp << a.Imya; temp << "\n";
            temp << a.Otch; temp << "\n";
            temp << a.birfDay; temp << "\n";
            temp << a.marks[0]; temp << "\n";
            temp << a.marks[1]; temp << "\n";
            temp << a.marks[2]; temp << "\n";
            temp << a.avg; temp << "\n";
        }
        id++;
    } while (!f.eof());
    f.close();//закрываем исходный файл
    temp.close(); //закрываем временный файл
    remove(filename);//удаляем исходный файл
    rename("temp", filename);//переименовываем временный файл
}
//добавить данные в файл перед структурой с индексом index
void add_in_num(const char* filename, struct Enrollee data,  string famil)
{
    fstream temp("temp", ios::out, ios::binary);//исходный файл
    fstream f(filename, ios::in, ios::binary);//вспомогательный файл
    Enrollee a;//буфер для чтения данных из файла
        //считываем данные из исходного файла в буфер
    int k = 0;
    do {
        //читанем данные из файла
        f >> a.Famil;
        f >> a.Imya;
        f >> a.Otch;
        f >> a.birfDay;
        f >> a.marks[0];
        f >> a.marks[1];
        f >> a.marks[2];
        f >> a.avg;
        if (f.eof())break;
        
        if (a.Famil == famil)//если нашли индекс вставляем данные
        {
            temp << data.Famil; temp << "\n";
            temp << data.Imya; temp << "\n";
            temp << data.Otch; temp << "\n";
            temp << data.birfDay; temp << "\n";
            temp << data.marks[0]; temp << "\n";
            temp << data.marks[1]; temp << "\n";
            temp << data.marks[2]; temp << "\n";
            temp << data.avg; temp << "\n";
        }
        temp << a.Famil; temp << "\n";
        temp << a.Imya; temp << "\n";
        temp << a.Otch; temp << "\n";
        temp << a.birfDay; temp << "\n";
        temp << a.marks[0]; temp << "\n";
        temp << a.marks[1]; temp << "\n";
        temp << a.marks[2]; temp << "\n";
        temp << a.avg; temp << "\n";
        k++;
    } while (!f.eof());
    f.close();//закрываем исходный файл
    temp.close(); //закрываем временный файл
    remove(filename);//удаляем исходный файл
    rename("temp", filename);//переименовываем временный файл
}
// запись в файл массива структур
void save(const char* filename, struct Enrollee* mas, int n)
{
    fstream f(filename, ios::out);//двунаправленный файловый поток
    for (int i = 0; i < n; i++)
    {
        //добавляем данные в файл
        f << mas[i].Famil; f << "\n";
        f << mas[i].Imya; f << "\n";
        f << mas[i].Otch; f << "\n";
        f << mas[i].birfDay; f << "\n";
        f << mas[i].marks[0]; f << "\n";
        f << mas[i].marks[1]; f << "\n";
        f << mas[i].marks[2]; f << "\n";
        f << mas[i].avg; f << "\n";
    }

    f.close();//закрытие потока
}

// загрузка из файла массива структур
void load(const char* filename)
{
    fstream f;
    Enrollee p;
    f.open(filename, ios::in);//открываем поток для чтения
    int id = 1;//id для вывода номера
    cout << "id" << "\t" << "Ф." << "\t" << "И." << "\t" << "О." << "\t" << "Д.Р." << "\t" << "О.1" << "\t" << "О.2" << "\t" << "О.3" << "\t" << "Ср.Оц." << "\n";
    do
    {
        //достаём данные
        f >> p.Famil;
        f >> p.Imya;
        f >> p.Otch;
        f >> p.birfDay;
        f >> p.marks[0];
        f >> p.marks[1];
        f >> p.marks[2];
        f >> p.avg;
        if (f.eof())break;
        
        //выводим их
        cout << id << "\t" << p.Famil<< "\t" <<p.Imya<< "\t" << p.Otch << "\t" << p.birfDay << "\t" << p.marks[0] << "\t" << p.marks[1] << "\t" << p.marks[2] << "\t" << p.avg << "\n";
        id++;
    } while (!f.eof());

    f.close();//закрытие потока
}


int main(void)
{
    setlocale(LC_ALL, "Ru");//меняем язык консоли на русский
    const char* filename = "studens.stud";
    Enrollee* mas;//динамический массив
    int n;
    while (true) {
        cout << "Введите кол-во данных:";
        cin >> n;
        mas = new Enrollee[n];//создаем динамический массив
        for (int i = 0; i < n; i++)
        {
            //ввод одного элемента типа person из стандартного потока cin
            cout << "Фамилию: ";

            cin >> mas[i].Famil;
            cout << "Имя: ";
            cin >> mas[i].Imya;
            cout << "Отчество: ";
            cin >> mas[i].Otch;
            cout << "Дата рождения: ";
            cin >> mas[i].birfDay;
            cout << "Оценка по предмету 1: ";
            cin >> mas[i].marks[0];
            cout << "Оценка по предмету 2: ";
            cin >> mas[i].marks[1];
            cout << "Оценка по предмету 3: ";
            cin >> mas[i].marks[2];
            mas[i].avg = (mas[i].marks[0] + mas[i].marks[1] + mas[i].marks[2]) / 3;
        }
        save(filename, mas, n);
        load(filename);

        cout << "Удалить из файла студента под номером k = ";
        cin >> n;
        del_num(filename, n);
        cout << "Введите фамилию студента перед которым нужно вставить нового студента: ";
        string fam = "";
        cin >> fam;
        Enrollee persone;//создаем динамический массив
        cout << "ФИО: ";
        //ввод одного элемента типа person из стандартного потока cin
        cout << "Фамилию: ";

        cin >> persone.Famil;
        cout << "Имя: ";
        cin >> persone.Imya;
        cout << "Отчество: ";
        cin >> persone.Otch;
        cout << "Дата рождения: ";
        cin >> persone.birfDay;
        cout << "Оценка по предмету 1: ";
        cin >> persone.marks[0];
        cout << "Оценка по предмету 2: ";
        cin >> persone.marks[1];
        cout << "Оценка по предмету 3: ";
        cin >> persone.marks[2];
        persone.avg = (persone.marks[0] + persone.marks[1] + persone.marks[2]) / 3;
        add_in_num(filename, persone, fam);
        load(filename);
    }
    return 0;
}
