#pragma once
#include"Shop.h"
class WorkWithVector : protected Shop
{
public:
	WorkWithVector();
	void InsertVector(Shop Univer);
	void ShowVector(bool toFile);//Вывод хранилища на экран
	void SearchName(string SrchName, bool toFile);//Поиск записи по фамилии студента
	void ReadFromFile();//Функция извлечения информации из файла
	void ClearVector();//Функция очистки рабочей станции
	~WorkWithVector();
};

