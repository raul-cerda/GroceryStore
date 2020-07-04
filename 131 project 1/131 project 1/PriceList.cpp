#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;


PriceList::PriceList(){
	items = new PriceListItem[100000];
	numItems = 0;
}


// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
	// TO BE COMPLETED
	for (int i = 0; i < numItems; i++)
		if (code == items[i].getCode())
			return true;
	return false;
}

// return price, item name, taxable? as an PriceListItem object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	// TO BE COMPLETED
	for (int i = 0; i < numItems; i++)
	{
		if (code == items[i].getCode())
			return items[i];
	}
	throw invalid_argument("invalid code");
}

// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	// TO BE COMPLETED
	items[numItems] = PriceListItem(itemName, code, price, taxable);
	numItems++;
}

//copy cnstr
PriceList::PriceList(const PriceList &obj) {
	items = new PriceListItem[100000];
	numItems = obj.numItems;
	for (int i = 0; i < numItems; i++)
	{
		items[i] = obj.items[i];
	}
}

// destrctr
PriceList::~PriceList() {
	delete[] items;
}

//assignment operator
PriceList& PriceList::operator=(const PriceList &obj)
{
	if (this == &obj)
		return *this;
	items = new PriceListItem[100000];
	numItems = obj.numItems;
	for (int i = 0; i < numItems; i++)
	{
		items[i] = obj.items[i];
	}
	return *this;
}