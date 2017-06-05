#pragma once
#include"Shop.h"
class Manipulation
{
public:
	Manipulation();
	friend ostream &NameInstruments(ostream &stream);
	friend ostream &MarkInstruments(ostream &stream);
	friend ostream &TypeInstruments(ostream &stream);
	friend ostream &TypeInstruments2(ostream &stream);
	friend ostream &PriceInstruments(ostream &stream);
	friend ostream &AmountInstruments(ostream &stream);

	friend ostream &Enter(ostream &stream);
	friend ostream &PleaseRepAgain(ostream &stream);
	friend ostream &ShouldConteinOnly(ostream &stream);
	friend ostream &PressAnyButtanForContinue(ostream &stream);
	friend ostream &Error(ostream &stream);
	~Manipulation();
};

