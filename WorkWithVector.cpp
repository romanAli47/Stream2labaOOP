#include "WorkWithVector.h"


WorkWithVector::WorkWithVector()
{
}
void WorkWithVector::InsertVector(Shop Univer)
{

	bs.push_back(Univer);//Добавление элементов в конец контейнера 
}


void WorkWithVector::ShowVector(bool toFile)//Вывод хранилища на экран
{


	int n = bs.size();
	if (n != 0){
		for (int j = 0; j < n; j++){
			cout << endl;
			bs[j].ShowInfo(toFile);
			cout << endl;
		}
	}
	else cout << endl << "Empty!";
}


void WorkWithVector::SearchName(string CheckName, bool toFile)//Поиск записи по фамилии студента
{

	toFile = true;
	int k = bs.size();
	bool isFinded = false;
	for (int l = 0; l < k; l++){
		if (CheckName == bs[l].getName()){
			bs[l].ShowInfo(true);
			isFinded = true;
		}
	}

	if (!isFinded){//Не нашли ну и ладно
		cout << "Nothing found!" << endl;
		_getch();
	}
	toFile = false;
}


void WorkWithVector::ClearVector()//Функция очистки рабочей станции
{
	int nVecSize = bs.size();
	if (nVecSize == 0){
		cout << endl << "Already empty!";
	}
	else bs.clear();
}


void WorkWithVector::ReadFromFile()//Функция извлечения информации из файла
{
	ifstream f_In;//файловый ввод
	FILE *fo;
	string bufName;
	string bufMark;
	char bufType;
	int bufPrice;
	int bufKolich;

	if (f_In.is_open()){
		while (!f_In.eof()){
			f_In >> bufName >> bufMark >> bufType >> bufPrice >> bufKolich;
			bs.push_back(Shop(bufName, bufMark, bufType, bufPrice, bufKolich));//Добавление элементов в конец контейнера 
		}
		cout << "All is well";
		_getch();
	}
	else{
		cout << "Output file is not open!";
		_getch();
	}
}


WorkWithVector::~WorkWithVector()
{
}
