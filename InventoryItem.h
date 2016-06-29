#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace::System::Windows::Forms;
using namespace::Runtime::InteropServices;

class InventoryItem
{
public:

	//constructors
	InventoryItem();

	void ListRecords( char * );

	void InsertItem( int, int, double, double, char [], int, InventoryItem* );
	
	int CountItems();

	//Return value functions

	int GetInventoryNumber() const;
	int getManufacturerID() const;
	char* GetItemType( ) const;
	double GetPrice() const;
	double GetMarkup() const;
	int getQuantity() const;
	double getRetailPrice() const;
	InventoryItem* GetLink() const;

	//Set value functions
	void SetInventoryNumber( int );
	void SetManufacturerID( int );
	void SetQuantity( int);
	void SetLink( InventoryItem* );
	void SetPrice( double );
	void SetRetailPrice( double );
	void SetItemType(  char [] );
	void SetMarkup( double );

private:
	int InventoryNumber;
	int manufacturerID;
	double Price;
	double retailprice;
	double markup;
	int quantity;
	mutable char ItemType[35];
	InventoryItem* NextRecordPointer;


};
#endif