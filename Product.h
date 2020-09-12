#pragma once
namespace sizesAndKinds
{
	enum sizeOption : int
	{
		S = 1,
		M = 2,
		L = 3
	};
	enum dessertOption : int
	{
		waffle = 1,
		pancake = 2,
		cheesecake = 3
	};
	enum flavorOption : int
	{
		chocolate = 1,
		vanilla = 2,
		mixed = 3
	};
}

class Product
{
private:
	CString name;
	int id;
public:
	Product();
	Product(CString _name);
	virtual double getPrice() = 0;
	CString getName();
	void setName(CString _name);
	int getId();
};

