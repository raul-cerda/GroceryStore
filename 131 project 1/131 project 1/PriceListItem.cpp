#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName, const string &code, double prise, bool taxable) {
	// TO BE COMPLETED
	name = itemName;
	barcode = code;
	price = prise;
	taxStatus = taxable;
}

//default constructor
PriceListItem::PriceListItem() {
	// TO BE COMPLETED
	name = "tempName";
	barcode = "tempCode";
	price = 0.00;
	taxStatus = false;
}

//accessor methods
string PriceListItem::getItemName() {
	// TO BE COMPLETED
	return name;
}

string PriceListItem::getCode() {
	// TO BE COMPLETED
	return barcode;
}

double PriceListItem::getPrice() {
	// TO BE COMPLETED
	return price;
}

bool PriceListItem::isTaxable() {
	// TO BE COMPLETED
	return taxStatus;
}

