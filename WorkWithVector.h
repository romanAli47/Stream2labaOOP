#pragma once
#include"Shop.h"
class WorkWithVector : protected Shop
{
public:
	WorkWithVector();
	void InsertVector(Shop Univer);
	void ShowVector(bool toFile);//����� ��������� �� �����
	void SearchName(string SrchName, bool toFile);//����� ������ �� ������� ��������
	void ReadFromFile();//������� ���������� ���������� �� �����
	void ClearVector();//������� ������� ������� �������
	~WorkWithVector();
};

