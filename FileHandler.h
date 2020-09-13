#pragma once
#include <string>
#include<istream>
#include<fstream>


#include"Product.h"
#include"Dessert.h"
#include"Frozen.h"
#include"IceCream.h"
#include"Yogurt.h"
#include"Order.h"

using namespace std;

class FileHandler
{
public:
	static void exportOrderToFile(Order* orderToExportPtr,CString filePath);
	static BOOL importFromFile(Order* MyOrder, CString filePath);
};

