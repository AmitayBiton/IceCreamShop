#include "pch.h"
#include "Product.h"

Product::Product(CString _name)
{
	name = _name;
}

Product::Product()
{
	name = "";
}

void Product::setName(CString _name)
{
	name = _name;
}

CString Product::getName()
{
	return name;
}