#include "WorkWithVector.h"


WorkWithVector::WorkWithVector()
{
}
void WorkWithVector::InsertVector(Shop Univer)
{

	bs.push_back(Univer);//���������� ��������� � ����� ���������� 
}


void WorkWithVector::ShowVector(bool toFile)//����� ��������� �� �����
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


void WorkWithVector::SearchName(string CheckName, bool toFile)//����� ������ �� ������� ��������
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

	if (!isFinded){//�� ����� �� � �����
		cout << "Nothing found!" << endl;
		_getch();
	}
	toFile = false;
}


void WorkWithVector::ClearVector()//������� ������� ������� �������
{
	int nVecSize = bs.size();
	if (nVecSize == 0){
		cout << endl << "Already empty!";
	}
	else bs.clear();
}


void WorkWithVector::ReadFromFile()//������� ���������� ���������� �� �����
{
	ifstream f_In;//�������� ����
	FILE *fo;
	string bufName;
	string bufMark;
	char bufType;
	int bufPrice;
	int bufKolich;

	if (f_In.is_open()){
		while (!f_In.eof()){
			f_In >> bufName >> bufMark >> bufType >> bufPrice >> bufKolich;
			bs.push_back(Shop(bufName, bufMark, bufType, bufPrice, bufKolich));//���������� ��������� � ����� ���������� 
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
