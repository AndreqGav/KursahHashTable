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

	testTable(table); // функция для тестирования таблицы
}

void testTable(THash_Table &table)
{
	cout << "Добавить/Удалить/Найти/Получть размер/Записать в файл/выйти? A/D/F/S/W/E" << endl; // add,delete,find,exit

	char answer;
	cin >> answer;

	answer = (char)toupper(answer); // преобразовать в старший регистр

	switch (answer)
	{
	case 'A': // добавление элемента
	{
		Node node;
		int key;
		cout << "Веддите: данные ключ" << endl;
		cin >> node.itеm.data;
		cin >> node.key;

		if (table.Insert(node)) {
			cout << "Элемент " << node.itеm.data << " успешно добавлен" << endl;
		}
		else
		{
			cout << "Ошибка добавления!" << endl;
		}
		break;
	}
	case 'D': // удаление элемента
	{
		Tkey key;
		cout << "Веддите: ключ" << endl;
		cin >> key;

		if (table.Delete(key))
		{
			cout << "Элемент с ключом " << key << " успешно удален" << endl;
		}
		else
		{
			cout << "Невозможно удалить элемент с ключом " << key << endl;
		}
		break;
	}
	case 'F': // посик жлемента по ключу
	{
		Tkey key;
		cout << "Веддите: ключ" << endl;
		cin >> key;

		Tltеm item;

		if (table.Find(key, item)) {
			cout <<"Элемент: " << item.data << endl;
		}
		else
		{
			cerr << "Ключ не найден!" << endl;
		}

		break;
	}
	case 'W': // запись таблицы в текствый файл
	{
		string fileName;
		cout << "Введите имя файла(с расширением):" << endl;
		cin >> fileName;

		table.WriteTable(fileName);

		break;
	}
	case 'S': // получение размера таблицы
	{
		cout << "Размер: " << table.GetSize() << endl;
		break;
	}

	case 'E': // выход из тестируемой функции
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

