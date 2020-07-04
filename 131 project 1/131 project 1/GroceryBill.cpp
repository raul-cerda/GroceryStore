#include "GroceryBill.h"
#include <iostream>
#include <fstream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	// To be completed
	shopList = priceList;
	tax = taxRate;
	total = 0.00;
	bill = new PriceListItem[1000];
	billNum = 0;
	quantities = new double[1000];
}


void GroceryBill::scanItem(string scanCode, double quantity) {
	// To be completed
	if (shopList->isValid(scanCode))
	{
		PriceListItem temp = shopList->getItem(scanCode);
		bill[billNum] = temp;
		quantities[billNum] = quantity;
		billNum++;
		if (temp.isTaxable())
			total += ((temp.getPrice() + (temp.getPrice() * (tax/100))) * quantity);
		else
			total += (temp.getPrice() * quantity);
	}
	else
		throw invalid_argument("Invalid barcode");
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// To be completed
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
	
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string code;
		double quantity;
		while (myfile >> code >> quantity) {
			// cout << code << " " << taxable << endl;
			scanItem(code, quantity);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	// To be completed
	return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	// To be completed
	for (int i = 0; i < billNum; i++)
	{
		if (bill[i].isTaxable())
			cout << bill[i].getItemName() << "     " << (bill[i].getPrice() + (bill[i].getPrice() * (tax / 100))) * quantities[i] << "   T" << endl;
		else
			cout << bill[i].getItemName() << "     " << bill[i].getPrice() * quantities[i] << endl;
	}
	cout << "Total     " << total << endl;
}