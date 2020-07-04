#pragma once
#include <string>

using namespace std;

class PriceListItem {
public:
	PriceListItem();
	PriceListItem(const string &itemName, const string &code, double prise, bool taxable);
	string getItemName();
	string getCode();
	double getPrice();
	bool isTaxable();
private:
	// any private member variables and methods go here
	// TO BE COMPLETED
	string name;
	string barcode;
	double price;
	bool taxStatus;
};
