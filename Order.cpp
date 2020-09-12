#include "pch.h"
#include "Order.h"

Order::Order()
{
	products = {};
	ammount = 0;
	OrderNumber = rand() % 10000;
}

double Order::calculateTotalPrice()
{
	int size = products.size(), i;
	double sum = 0;

	for (Product* prd : products)
	{
		sum += prd->getPrice();
	}
	return sum;
}

int Order::getAmmount()
{
	return ammount;
}

int Order::getOrderNumber()
{
	return OrderNumber;
}

void Order::addProduct(Product* prd)
{
	products.push_back(prd);
	ammount++;
}
void Order::removeProduct(Product* prd)
{
	products.erase(remove(products.begin(), products.end(), prd), products.end());
	ammount--;
}