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
	N = n; // ���������� ������ �������
	table = new Node[2 * N];
	// ���������������� ������
	for (int i = 0; i < 2 * N; ++i)
		table[i].status = 0;

	count_Items = 0;
}

bool THash_Table::Insert(Node node) // ������� �������
{
	if (count_Items >= N) // ���� ������� ���������
	{
		std::cerr << "������� �����������!" << endl;
		return false;
	}

	int hkey = hashKey(node.key); // �������� ������

	//��� ��������
	int i = 0;
	while (table[hkey].status == 1)//���� ������ ������ - ��������� ������
	{
		if (table[hkey].key == node.key) // ���� ������� � ����� ������ ��� ����
		{
			std::cerr <<  "������� � ������ " << node.key << " ��� ���������!" << endl;
			return false;
		}

		hkey = (hkey + c + d * i*i) % (2 * N); // ���� ����� �������� - �������� ������
		++i;
	}

	//��������� ������ �������
	node.status = 1;
	table[hkey] = node;

	count_Items++; // ��������� ������� ���������
	return true;
}

bool THash_Table::Find(Tkey key, Tlt�m &item) // ������� ������
{
	int hkey = hashKey(key); // �������� ������ �� ���-�������
	//��� ��������
	int i = 0;
	while (table[hkey].status != 0) // ���� �� ����� �� ������� ����
	{
		if (table[hkey].key == key && table[hkey].status == 1) { // ���� ����� ���� � �� �� �����
			item = table[hkey].it�m;
			return true;
		}
		hkey = (hkey + c + d * i*i) % (2 * N); // ���� �������� - ������� � ����. ��������
		++i;
	}
	return false;
}

bool THash_Table::Delete(Tkey key) // ������� ��������
{
	int hkey = hashKey(key);
	//��� ��������
	int i = 0;
	while (table[hkey].status != 0) // ���� �� ����� �� ������� ����
	{
		if (table[hkey].key == key && table[hkey].status == 1) // ���� ����� �������
		{
			table[hkey].status = -1;
			count_Items--;
			return true;
		}
		hkey = (hkey + c + d * i*i) % (2 * N); // ������ ���������� ����
		++i;
	}
	return false;
}

void THash_Table::initTable(string fileName) // ������������� ������� �� �����
{
	ifstream ifile(fileName); 
	Node node;
	while (!ifile.eof() && count_Items < N)
	{
		ifile >> node.it�m.data;
		ifile >> node.key;

		Insert(node);
	}
}

void THash_Table::WriteTable(string fileName) // ������ ������� � ����
{
	ofstream ofile(fileName);

	for (int i = 0; i < 2 * N; ++i)
	{
		if (table[i].status)
		{
			ofile << table[i].it�m.data << '\t';
			ofile << table[i].key << '\t';
			ofile << '\n';
		}
	}
}

int THash_Table::GetSize() // ��������� ������� �������
{// ������ ��������� ���-�� ��������� � ������� �����

	int count = 0; // 
	for (int i = 0; i < 2 * N; ++i)
	{
		if (table[i].status == 1)
			count++;
	}
	cout << "������: " << count << endl;
	cout << "��������: " << N - count << endl;

	return N;
}