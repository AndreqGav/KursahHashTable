#pragma once
#include <string>
#include<fstream>

using namespace std;

struct Data
{
	//���,�������
	string Name, FirstName;
	//����� �������
	int key;
};

struct Node
{
	Data data;
	//��������� 0-��������,1-������,-1 - ������
	int status;
};

class THash_Table
{
private:
	//���-�� ��������� � �������
	int N;
	//��������� �� ������ �������
	Node *table;

	//���-�������
	int hashKey(int key);
	//���������� ��������� ��� ������������� ������������
	const int c = 3, d = 9;
	//���-�� ���������� ��������� � �������
	int count_Items;
public:
	//�����������
	THash_Table(int N);
	//������������� �������
	void initTable(string fileName);
	//���������� ������ � ����
	void SaveTable(string fileName);
	//���������� ��-��
	void insert(Data data);
	//����� �� �����
	Data* find(int key);
	//�������� �� �����
	void del(int key);
};