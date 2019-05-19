#include "pch.h"
#include"THash_Table.h"
#include<fstream>
#include <iostream>

int THash_Table::hashKey(Tkey key)
{
	return key % N;
}

THash_Table::THash_Table(int n)
{
	N = n; // установить размер таблицы
	table = new Node[2 * N];
	// инициализировать данные
	for (int i = 0; i < 2 * N; ++i)
		table[i].status = 0;

	count_Items = 0;
}

bool THash_Table::Insert(Node node) // функция вставки
{
	if (count_Items >= N) // если таблица заполнена
	{
		std::cerr << "Таблица переполнена!" << endl;
		return false;
	}

	int hkey = hashKey(node.key); // получить индекс

	//шаг коллизии
	int i = 0;
	while (table[hkey].status == 1)//Пока ячейка занята - двигаемся дальше
	{
		if (table[hkey].key == node.key) // есди элемент с таким ключом уже есть
		{
			std::cerr <<  "Элемент с ключом " << node.key << " уже существет!" << endl;
			return false;
		}

		hkey = (hkey + c + d * i*i) % (2 * N); // если снова коллизия - изменить индекс
		++i;
	}

	//Заполняем ячейку массива
	node.status = 1;
	table[hkey] = node;

	count_Items++; // увеличить счетчки элементов
	return true;
}

bool THash_Table::Find(Tkey key, Tltеm &item) // функция поиска
{
	int hkey = hashKey(key); // получить инедкс из хеш-функции
	//шаг коллизии
	int i = 0;
	while (table[hkey].status != 0) // пока не дойдём до пустого поля
	{
		if (table[hkey].key == key && table[hkey].status == 1) { // если нашли ключ и он не удалён
			item = table[hkey].itеm;
			return true;
		}
		hkey = (hkey + c + d * i*i) % (2 * N); // если коллизия - перейти к след. элементу
		++i;
	}
	return false;
}

bool THash_Table::Delete(Tkey key) // функция удаления
{
	int hkey = hashKey(key);
	//шаг коллизии
	int i = 0;
	while (table[hkey].status != 0) // пока не дойдём до пустого поля
	{
		if (table[hkey].key == key && table[hkey].status == 1) // если нашли элемент
		{
			table[hkey].status = -1;
			count_Items--;
			return true;
		}
		hkey = (hkey + c + d * i*i) % (2 * N); // индекс следующего поля
		++i;
	}
	return false;
}

void THash_Table::initTable(string fileName) // Инициализация таблицы из файла
{
	ifstream ifile(fileName); 
	Node node;
	while (!ifile.eof() && count_Items < N)
	{
		ifile >> node.itеm.data;
		ifile >> node.key;

		Insert(node);
	}
}

void THash_Table::WriteTable(string fileName) // Запись таблицы в файл
{
	ofstream ofile(fileName);

	for (int i = 0; i < 2 * N; ++i)
	{
		if (table[i].status)
		{
			ofile << table[i].itеm.data << '\t';
			ofile << table[i].key << '\t';
			ofile << '\n';
		}
	}
}

int THash_Table::GetSize() // получение размера таблицы
{// заодно посчитаем кол-во свободных и занятых ячеек

	int count = 0; // 
	for (int i = 0; i < 2 * N; ++i)
	{
		if (table[i].status == 1)
			count++;
	}
	cout << "Занято: " << count << endl;
	cout << "Свободно: " << N - count << endl;

	return N;
}