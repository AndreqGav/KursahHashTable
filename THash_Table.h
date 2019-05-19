#pragma once
#include <string>
#include<fstream>

using namespace std;

struct Tltеm //Данные
{
	string data;
};

typedef int Tkey;

struct Node
{
	Tltеm itеm;
	Tkey key;

	int status;//Состояние 0-свободно,1-занято,-1 - удален
};

class THash_Table
{

private:
	//Кол-во элементов в таблице
	int N;
	//Указатель на массив таблицы
	Node *table;

	//Хеш-Функция
	int hashKey(Tkey key);
	//Определяем константы для квадратичного пробирования
	const int c = 3, d = 9;
	//Кол-во занесенных элементов в таблицу
	int count_Items;

public:
	//Конструктор
	THash_Table(int N);
	//Инициализация таблицы
	void initTable(string fileName);
	//Сохранение данных в файл
	void WriteTable(string fileName);
	//Добавление эл-та
	bool Insert(Node node);
	//Поиск по ключу
	bool Find(Tkey key, Tltеm &item);
	//Удаление по ключу
	bool Delete(Tkey key);
	// Полученuе размера хеш-таблицы
	int GetSize();
};