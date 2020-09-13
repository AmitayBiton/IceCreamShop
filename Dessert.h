#pragma once
#include "Product.h"

using namespace sizesAndKinds;

class Dessert : public Product
{
private:
	dessertOption kind;
	sizeOption size;

public:
	Dessert();
	Dessert(Dessert& ds);
	Dessert(CString _name, dessertOption _kind, sizeOption _size);
	virtual double getPrice();
	sizeOption getSize();
	dessertOption getKind();
	void setSize(sizeOption _size);
	void setKind(dessertOption _kind);
};

