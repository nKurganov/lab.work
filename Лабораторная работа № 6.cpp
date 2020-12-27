#include <iostream>
#include <cstring>.
#include <locale>

using namespace std;

bool check_polindrom(string word)

{
	int len = word.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
		setlocale(LC_ALL, "Rus");
		string str;
		
	cout << "Программа проверки слов на палиндром" << endl;
	cout << "Введите слово: ";
	cin >> str;
	if (check_polindrom(str))
	{
		cout << "Cлово \"" << str << "\" -  является палиндромом." << endl;
	}
	else
	{
		cout << "Cлово \"" << str << "\" -  не является палиндромом." << endl;
	}
	system("pause");
	return 0;
}