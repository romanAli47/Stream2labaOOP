#include "Print.h"


Print::Print()
{
}


void Print::PrintMenu()//Ìåíş
{
	system("cls");
	cout << "         ********** Main menu **********" << endl;
	cout << "Press '1' to fill the storage from the keyboardû." << endl;
	//cout << "Press '2' to load information from a file." << endl;
	cout << "Press '2' to display the repository on screen." << endl;
	cout << "Press '3' to locate information on the name of instrument." << endl;
	cout << "Press '4' to sort the storage by brand of instrument." << endl;
	cout << "Press '5' for clearing the workstation." << endl;
	cout << "Press '6' to EXIT." << endl << endl;
	cout << "Your choose: ";
}

Print::~Print()
{
}
