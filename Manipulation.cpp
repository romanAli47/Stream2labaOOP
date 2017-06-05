#include "Manipulation.h"


Manipulation::Manipulation()
{
}

ostream &NameInstruments(ostream &stream)
{
	stream << "The name of instrument: ";
	return stream;
}

ostream &MarkInstruments(ostream &stream)
{
	stream << "The mark of instrument: ";
	return stream;
}

ostream  &TypeInstruments(ostream &stream)
{
	stream << "The type of instrument: electric ";
	return stream;
}
ostream &TypeInstruments2(ostream &stream)
{
	stream << "The type of instrument: acoustic ";
	return stream;
}

ostream &PriceInstruments(ostream &stream)
{
	stream << "The price of instrument: ";
	return stream;
}

ostream &AmountInstruments(ostream &stream)
{
	stream << "Quantity in stock: ";
	return stream;
}

ostream &Enter(ostream &stream)
{
	stream << "Enter ";
	return stream;
}

ostream &PressAnyButtanForContinue(ostream &stream)
{
	stream << "Press any buttan for continue...";
	return stream;
}

ostream &PleaseRepAgain(ostream &stream)
{
	stream << " Please, repeat again.";
	return stream;
}

ostream &Error(ostream &stream)
{
	stream << "***ERROR!***";
	return stream;
}

ostream &ShouldConteinOnly(ostream &stream)
{
	stream << "should contein only ";
	return stream;
}

Manipulation::~Manipulation()
{
}
