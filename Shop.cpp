#include"Shop.h"
#include"Manipulation.h"

Shop::Shop()
{
	Price = 0;
}

Shop::Shop(string N, string M, char T, int P, int A)
{
	Name = N;
	Mark = M;
	Type = T;
	Price = P;
	Amount = A;
}
string Shop::getName()
{
	return Name;
}

string Shop::getMark()
{
	return Mark;
}
Shop &Shop::operator [] (int i) //Перегрузка индексации для Shop
{
	return bs[i];
}

bool Shop::operator < (Shop Univers)//Оператор сравнения (для сортировки объекта)
{
	if (Mark < Univers.getMark()){
		return true;
	}
	else return false;
}

void *Shop::operator new(size_t size)
{
	void *p;
	cout << "Выделение памяти для объекта класса Shop\n";
	p = malloc(size);
	try
	{
		if (!p){
			bad_alloc ba;
			throw ba;
		}
	}
	catch (bad_alloc ba)
	{
		cout << "Ошибка при выделении памяти\n";
	}
}

void Shop::operator delete(void *p)
{
	cout << "Удаление объекта класса Shop\n";
	free(p);
}

void Shop::InputRecord() //throw (int) 
{
	int nBuf = 0;
	string countBuf;
	cout << Enter << NameInstruments;
	cin >> Name;
	int nSize = Name.length();
	for (int i = 0; i < nSize; i++){
		if (!isalpha(Name[i])){ throw 1; } //isalpha - проверяет аргумент Name[i] является ли он строчной или прописной буквой алфавита
	}
	cout << Enter << MarkInstruments;
	cin >> Mark;
	nSize = Mark.length();
	for (int i = 0; i < nSize; i++){
		if (!isalpha(Mark[i]) && !isdigit(Mark[i])){ throw 2; }
	}
	string sBufType;
	cout << Enter << "The type of instrument ('g' - Acoustic, 'c' - Electric): ";
	cin >> sBufType;
	if (sBufType.length() == 1){
		if ((sBufType[0] != 'g') && (sBufType[0] != 'c')){ throw 3; }
	}
	else throw 3;
	Type = sBufType[0];
	cout << Enter << PriceInstruments;
	cin >> countBuf;
	int x = countBuf.length();
	for (int i = 0; i < x; i++){
		if (!isdigit(countBuf[i])){
			throw 4;
		}
		Price = atoi(countBuf.c_str());//Преобразуем countBuf.c_str в целое значение типа int
	}
	cout << Enter << AmountInstruments;
	cin >> Amount;
	if (Amount < 0) throw LeftBoundException(" ***Error!*** Error left");//LeftBoundException
	if (Amount > 10) throw RightBoundException(" ***Error!*** A number of instrument in the ware house more than the allowable storage [1;10]");
	while (!(cin >> Amount) || (Amount = (int)Amount) < 1 || (Amount = (int)Amount) > 10){
		cout << "Incorrect number!" << endl;
		cin.clear();
		while (cin.get() != '\n');
	}
}


void Shop::ShowInfo(bool toFile)
{
	ofstream f_Out;
	if (toFile){
		cout << NameInstruments << Name << endl;
		f_Out << NameInstruments << Name << endl;
		cout << MarkInstruments << Mark << endl;
		f_Out << MarkInstruments << Mark << endl;
		if (Type == 'c'){
			cout << TypeInstruments << endl;
			f_Out << TypeInstruments << endl;
		}
		else{
			cout << TypeInstruments2 << endl;
			f_Out << TypeInstruments2 << endl;
		}
		cout << PriceInstruments << Price << endl;
		f_Out << PriceInstruments << Price << endl;
		cout << AmountInstruments << Amount << endl;
		f_Out << AmountInstruments << Amount << endl;
	}

	else{
		cout << NameInstruments << Name << endl;
		cout << NameInstruments << Mark << endl;
		if (Type == 'c'){
			cout << TypeInstruments << endl;
		}
		else{
			cout << TypeInstruments2 << endl;
		}
		cout << PriceInstruments << Price << endl;
		cout << AmountInstruments << Amount << endl;
	}
}

ostream &operator<<(ostream &stream, Shop &n)
{

	printf(" _______________________________________________________________________________________________________________________\n");
	printf("|The name of instrument|The mark of instrument|The type of instrument      |The price of instrument  |Quantity in stock|\n");
	printf("|______________________|______________________|____________________________|_________________________|_________________|\n");
	printf("|%-23s|%-23s|%-30s|%-25s|%-16s|\n", n.Name, n.Mark, n.Type, n.Price, n.Amount);
	printf("|______________________|______________________|____________________________|_________________________|_________________|\n");
	return stream;
}


Shop::~Shop()
{
}