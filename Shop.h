#pragma once
#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <conio.h>
#include <ostream>
#include <sstream>
#include <fstream>//для работы с файлами
#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstring>// со строками

using namespace std;

#ifndef __Shop_H__
#define __Shop_H__
class Shop;
typedef vector <Shop> Base;//Переименование типа - необязательно
//vector <Shop>::iterator index;//Определение итератора index (нужен для прямого доступа к элементам (методы begin() и end()))

class LeftBoundException : public exception
{
public: LeftBoundException(char *s) : exception(s) {}
};

class RightBoundException : public LeftBoundException
{
public: RightBoundException(char *s) : LeftBoundException(s) {}
};

class Shop
{
private:
	string Name;
	string Mark;
	char Type;
	int Price;
	int Amount;
protected:
	Base bs;
public:
	Shop();
	Shop(string N, string M, char T, int P, int K);
	string getName();
	void setMark(string);
	string getMark();
	void InputRecord(); //throw (int) 
	void ShowInfo(bool toFile);
	Shop &operator [] (int i);
	bool operator < (Shop Univers);
	void *operator new(size_t size);
	void operator delete(void *p);
	friend istream &operator>>(istream &stream, Shop &n);
	friend ostream &operator<<(ostream &stream, Shop &n);
	~Shop();
};
#endif//__Shop_H__
