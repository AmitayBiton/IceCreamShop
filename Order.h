#pragma once

#include "Product.h"
#include "Dessert.h"
#include "Frozen.h"
#include "IceCream.h"
#include "Yogurt.h"

#include <vector>

using namespace std;

class Order
{
private:
	vector<Product*> products;
	int OrderNumber;
	int ammount;

public:
	Order();
	double calculateTotalPrice();
	int getAmmount();
	int getOrderNumber();
	void addProduct(Product* prd);
	void removeProduct(Product* prd);
	Product* getProductById(int id);
	vector<Product*> getAllProducts();
};

