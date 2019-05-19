#include "pch.h"
#include <iostream>
#include "THash_Table.h"
#include <string>

using namespace std;

void testTable(THash_Table &table);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер таблицы: ";
	cin >> n;

	if (n <= 0)
	{
		cerr << "Некорректные данные";
		return -1;
	}

	THash_Table table = THash_Table(n);
	table.initTable("input.txt");

	testTable(table);
}

void testTable(THash_Table &table)
{
	cout << "Добавить/Удалить/Найти/Редактировать/Записать в файл/выйти? A/D/F/C/W/E" << endl; // add,delete,find,change,exit

	char answer;
	cin >> answer;

	answer = (char)toupper(answer);

	switch (answer)
	{
	case 'A':
	{
		string Name, FirstName;
		int key;
		cout << "Веддите: Имя Фамилия №зачетки" << endl;
		cin >> Name;
		cin >> FirstName;
		cin >> key;

		Data _data;

		_data.Name = Name;
		_data.FirstName = FirstName;
		_data.key = key;

		table.insert(_data);


		break;
	}
	case 'D':
	{
		int key;
		cout << "Веддите: №зачетки" << endl;
		cin >> key;

		table.del(key);
		break;
	}
	case 'F':
	{
		int key;
		cout << "Веддите: №зачетки" << endl;
		cin >> key;

		Data* _data;

		_data = table.find(key);

		if (_data != NULL) {
			cout << _data->Name << "  " << _data->FirstName << "  " << _data->key << endl;
		}
		else
		{
			cerr << "Ключ не найден!" << endl;
		}

		break;
	}
	case 'C':
	{

		int key;
		cout << "Веддите: №зачетки" << endl;
		cin >> key;

		Data* _data;

		_data = table.find(key);

		if (_data != NULL) {
			string Name, FirstName;
			cout <<"Исходный:  " << _data->Name << "  " << _data->FirstName << "  " << _data->key << endl;
			cout << "Введите новые данные: имя фамилия(или -, если оставить неизменным поле)" << endl;
			cin >> Name;
			cin >> FirstName;

			if (Name != "-")
			{
				_data->Name = Name;
			}
			if (FirstName != "-")
			{
				_data->FirstName = FirstName;
			}
		}
		else
		{
			cerr << "Ключ не найден!" << endl;
		}

		break;
	}
	case 'W':
	{
		string fileName;
		cout << "Введите имя файла:" << endl;
		cin >> fileName;

		table.SaveTable(fileName);

		break;
	}
	case 'E':
	{
		return;
		break;
	}
	default:
		cout << endl << endl;
		testTable(table);
		break;
	}

	cout << endl << endl;
	testTable(table);
}

