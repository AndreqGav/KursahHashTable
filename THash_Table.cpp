#include "pch.h"
#include"THash_Table.h"
#include<fstream>
#include <iostream>

int THash_Table::hashKey(int key)
{
	return key % N;
}

THash_Table::THash_Table(int n)
{
	N = n;
	table = new Node[2 * N];
	for (int i = 0; i < 2 * N; ++i)
		table[i].status = 0;

	count_Items = 0;
}

void THash_Table::insert(Data data)
{
	if (count_Items > N)
	{
		std::cerr << "������� �����������!" << endl;
		return;
	}
	if (find(data.key) != NULL)
	{
		std::cerr << "������� � ����� ������ ��� ���������!" << endl;
		return;
	}
	int hkey = hashKey(data.key);
	//��� ��������
	int i = 0;
	while (table[hkey].status == 1)//���� ������ ������ - ��������� ������
	{
		hkey = (hkey + c + d * i*i) % (2 * N);
		++i;
	}
	//��������� ������ �������
	table[hkey].data = data;
	table[hkey].status = 1;

	count_Items++;

}

Data* THash_Table::find(int key)
{
	int hkey = hashKey(key);
	//��� ��������
	int i = 0;
	while (table[hkey].status == 1)
	{
		if (table[hkey].data.key == key)
			return &table[hkey].data;
		hkey = (hkey + c + d * i*i) % (2 * N);
		++i;
	}
	return NULL;
}

void THash_Table::del(int key)
{
	int hkey = hashKey(key);
	//��� ��������
	int i = 0;
	while (table[hkey].status)
	{
		if (table[hkey].data.key == key)
		{
			table[hkey].status = -1;
			count_Items--;
			break;
		}
		hkey = (hkey + c + d * i*i) % (2 * N);
		++i;
	}
}

void THash_Table::initTable(string fileName)
{
	ifstream ifile(fileName);
	Data data;
	while (!ifile.eof() && count_Items < N)
	{
		ifile >> data.Name;
		ifile >> data.FirstName;
		ifile >> data.key;

		insert(data);
	}
}

void THash_Table::SaveTable(string fileName)
{
	ofstream ofile(fileName);

	for (int i = 0; i < 2 * N; ++i)
	{
		if (table[i].status)
		{
			ofile << table[i].data.Name << '\t';
			ofile << table[i].data.FirstName << '\t';
			ofile << table[i].data.key << '\t';
			ofile << '\n';
		}
	}
}