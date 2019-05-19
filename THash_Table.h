#pragma once
#include <string>
#include<fstream>

using namespace std;

struct Data
{
	//Имя,Фамилия
	string Name, FirstName;
	//Номер зачетки
	int key;
};

struct Node
{
	Data data;
	//Состояние 0-свободно,1-занято,-1 - удален
	int status;
};

class THash_Table
{
private:
	//Кол-во элементов в таблице
	int N;
	//Указатель на массив таблицы
	Node *table;

	//Хеш-Функция
	int hashKey(int key);
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
	void SaveTable(string fileName);
	//Добавление эл-та
	void insert(Data data);
	//Поиск по ключу
	Data* find(int key);
	//Удаление по ключу
	void del(int key);
};