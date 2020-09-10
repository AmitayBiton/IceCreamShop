#pragma once
#include "Product.h"
using namespace sizesAndKinds;

class Frozen : public Product
{
private:
	sizeOption cupSize;
public:
	Frozen();
	Frozen(Frozen& fr);
	Frozen(CString _name, sizeOption _cupSize);
	sizeOption getCupSize();
	void setCupSize(sizeOption _cupSize);
	virtual double getPrice() = 0;
};