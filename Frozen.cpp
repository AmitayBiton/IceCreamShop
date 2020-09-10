#include "pch.h"
#include "Frozen.h"
using namespace sizesAndKinds;

Frozen::Frozen() : Product()
{
	cupSize = S;
}

Frozen::Frozen(Frozen& fr) : Product(fr.getName())
{
	this->cupSize = fr.cupSize;
}

Frozen::Frozen(CString _name, sizeOption _cupSize) : Product(_name)
{
	cupSize = _cupSize;
}

sizeOption Frozen::getCupSize()
{
	return cupSize;
}

void Frozen::setCupSize(sizeOption _cupSize)
{
	cupSize = _cupSize;
}