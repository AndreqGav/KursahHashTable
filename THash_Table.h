#pragma once
#include <string>
#include<fstream>

using namespace std;

struct Tlt�m //������
{
	string data;
};

typedef int Tkey;

struct Node
{
	Tlt�m it�m;
	Tkey key;

	int status;//��������� 0-��������,1-������,-1 - ������
};

class THash_Table
{

private:
	//���-�� ��������� � �������
	int N;
	//��������� �� ������ �������
	Node *table;

	//���-�������
	int hashKey(Tkey key);
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
	void WriteTable(string fileName);
	//���������� ��-��
	bool Insert(Node node);
	//����� �� �����
	bool Find(Tkey key, Tlt�m &item);
	//�������� �� �����
	bool Delete(Tkey key);
	// �������u� ������� ���-�������
	int GetSize();
};