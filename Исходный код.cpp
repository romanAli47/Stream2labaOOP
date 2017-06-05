#include"Shop.h"
#include"WorkWithVector.h"
#include"Sorting.h"
//#include"Readf.h"
#include"Print.h"
#include"Manipulation.h"

int main()
{
	bool toFile(0);
	int i = 0;
	//Readf red;
	WorkWithVector wwv;
	Sorting sor;
	Print pr;
	int ccheck;
	//ccheck = new char[20];
	string stars = "***************";
	char CheckEXit = 'Yes';
	string ExitWords = "If you want to save the data,enter: 'y' ";
	setlocale(LC_ALL, "rus");
	FILE* fo;
	try
	{
		if ((fo = fopen("nyny.dat", "r+b")) == NULL){
			cout << "Создан файл для записи данных" << endl;
			if ((fo = fopen("nyny.dat", "w+b")) == NULL){
				cout << Error << endl;
				throw 2.2;
			}
		}
	}
	catch (double)
	{
		cout << endl << Error << "File not create***" << endl;
		_getch();
	}
	//_getch();
	system("cls");
	Shop Univer;
	char MenuChoice(0);
	//int n = ftell(fo) / sizeof(Univer);
	string CheckName;
	while (MenuChoice != '7'){
		pr.PrintMenu();
		char g(0) ;
		cin >> MenuChoice;

		switch (MenuChoice)
		{
		case '1':
			while (g != 'y'){
				try
				{
					fseek(fo, 0, SEEK_END);
					Univer.InputRecord();
					i++;
					wwv.InsertVector(Univer);
					fwrite(&Univer, sizeof(Univer), 1, fo);
					cout << "Press (y) buttan for continue" << endl;
				/*	if (ftell(fo) / sizeof(Univer))
					{
						cout << "Лимит деталей" << endl;
						_getch();
						break;
					}*/
					g = getch();
				}
				catch (int i)
				{
					if (i == 1){
						cout << endl << Error << endl << "The name " << ShouldConteinOnly << " letters!" << PleaseRepAgain << endl;
					}
					if (i == 2){
						cout << endl << Error << endl << "The mark of the instrument " << ShouldConteinOnly << " letters!" << PleaseRepAgain << endl;
					}
					if (i == 3){
						cout << endl << Error << endl << "This " << ShouldConteinOnly << "1 symbol - 'с' or  'g'!" << PleaseRepAgain << endl;
					}
					if (i == 4){
						cout << endl << Error << endl << "Put only number!" << PleaseRepAgain << endl;
					}
					_getch();
				}
				catch (LeftBoundException e)
				{
					cout << e.what() << endl;
					_getch();
				}

				catch (RightBoundException e)
				{
					cout << e.what() << endl;
					_getch();
				}
				catch (...)
				{
					cout << "Fatal error.";
					_getch();
					exit(1);
				}
				cout << endl;
			}
			cout << endl << "Loading is finished!" << PressAnyButtanForContinue;
			_getch();
			break;
		case '2':
			int n;
			system("cls");
			toFile = false;
			fseek(fo, 0, SEEK_END);
			n = ftell(fo) / sizeof(Univer);
			
			fseek(fo, 0, SEEK_SET);
			/*while ((n--) != 0)
			{*/

				fread(&Univer, sizeof(Univer), 1, fo);
				wwv.ShowVector(toFile);
		/*	}*/
			if (n == 0)
			{
				cout << "У вас нет ни одной записи" << endl;
				_getch();
				break;
			}
			cout << endl << PressAnyButtanForContinue;
			_getch();
			break;
		case '3':
				cout << Enter << NameInstruments;
				cin >> CheckName;
				wwv.SearchName(CheckName, toFile);
				cout << endl << PressAnyButtanForContinue;
				_getch();
				break;
		case '4':
			sor.SortByMark();//Сортировка по марке инструмента
			cout << endl << "***************" << endl << "Sort by mark: "
				<< endl << "***************" << endl;
			wwv.ShowVector(toFile);//Вывод хранилища на экран
			cout << endl << PressAnyButtanForContinue;
			_getch();
			break;
		case '5':
			wwv.ClearVector();//Функция очистки рабочей станции
			cout << endl << "Ready" << PressAnyButtanForContinue;
			_getch();
			break;
		case '6':
			cout << ExitWords << endl;
			ccheck = getch();
			if (ccheck == 'y')
			{

				toFile = true;
				wwv.ShowVector(toFile);
			}
			/*_getch();*/
			exit(0);
			break;
		default:
			cout << "Please,enter the number from'1' to '7'!";
			_getch();
			break;
		}
	}
	fclose(fo);
}






