#include "pch.h"
#include "FileHandler.h"
#include <string>



void FileHandler::exportOrderToFile(Order* orderToExportPtr, CString filePath)
{
	ofstream file;
	file.open(filePath);
	vector<Product*> allProducts = orderToExportPtr->getAllProducts();
	for (int i = 0; i < allProducts.size(); i++) 
	{
		if (allProducts[i]->getName() == "Ice Cream") 
		{
			file << "I,";
			sizeOption size = ((IceCream*)allProducts[i])->getCupSize();
			switch (size)
			{
			case 1:
				file << "1";
				break;
			case 2:
				file << "2";
				break;
			case 3:
				file << "3";
				break;
			}
			
			file << ',';
			flavorOption flavor = ((IceCream*)allProducts[i])->getFlavor();
			switch (flavor) 
			{
			case 1:
				file << "1";
				break;
			case 2:
				file << "2";
				break;
			case 3:
				file << "3";
				break;
			}
			file << '\n';
		}
		
		if (allProducts[i]->getName() == "Waffle" || allProducts[i]->getName() == "Pancake" || allProducts[i]->getName() == "CheeseCake")
		{
			file << "D,";
			sizeOption size = ((Dessert*)allProducts[i])->getSize();
			switch (size)
			{
			case 1:
				file << "1";
				break;
			case 2:
				file << "2";
				break;
			case 3:
				file << "3";
				break;
			}

			file << ',';
			dessertOption kind = ((Dessert*)allProducts[i])->getKind();
			switch (kind)
			{
			case 1:
				file << "1";
				break;
			case 2:
				file << "2";
				break;
			case 3:
				file << "3";
				break;
			}
			file << '\n';
		}

		if (allProducts[i]->getName() == "Frozen Yogurt")
		{
			file << "Y,";
			sizeOption size = ((Yogurt*)allProducts[i])->getCupSize();
			switch (size)
			{
			case 1:
				file << "1";
				break;
			case 2:
				file << "2";
				break;
			case 3:
				file << "3";
				break;
			}
			
			file << ',';
			
			if (((Yogurt*)allProducts[i])->hasAddon(_T("Oreo"))) 
			{
				file << "1";
			}
			else 
			{
				file << "0";
			}
			file << ',';

			if (((Yogurt*)allProducts[i])->hasAddon(_T("Sprinkles")))
			{
				file << "1";
			}
			else
			{
				file << "0";
			}
			file << ',';
			
			if (((Yogurt*)allProducts[i])->hasAddon(_T("Strawberries")))
			{
				file << "1";
			}
			else
			{
				file << "0";
			}
			file << ',';
			
			if (((Yogurt*)allProducts[i])->hasAddon(_T("Pineapple")))
			{
				file << "1";
			}
			else
			{
				file << "0";
			}
			
			file << '\n';
		}
	}
	file.close();
}

BOOL FileHandler::importFromFile(Order* MyOrder, CString filePath)
{
	ifstream file;
	file.open(filePath);
	if(!file)
	{
		return false;
	}
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			if (line[0] == 'I') 
			{
				CString name = _T("Ice Cream");
				sizeOption cupsize = S;
				flavorOption flavor = chocolate;
				
				//size validation
				if (line[2] == '2') {
					cupsize = M;
				}
				if (line[2] == '3') {
					cupsize = L;
				}

				//flavor validation
				if (line[4] == '2')
				{
					flavor = vanilla;
				}
				if (line[4] == '3')
				{
					flavor = mixed;
				}

				IceCream* ic = new IceCream(name,cupsize,flavor);
				MyOrder->addProduct(ic);
			}
			if (line[0] == 'D')
			{	
				sizeOption size = S;
				dessertOption kind = waffle;
				CString name = _T("Waffle");

				//size validation
				if (line[2] == '2') 
				{
					size = M;
				}
				if (line[2] == '3') 
				{
					size = L;
				}

				//kind validation
				if (line[4] == '2')
				{
					kind = pancake;
					name = _T("Pancake");
				}
				if (line[4] == '3')
				{
					kind = cheesecake;
					name = _T("CheeseCake");
				}

				Dessert* ds = new Dessert(name, kind, size);
				MyOrder->addProduct(ds);
			}
			if (line[0] == 'Y')
			{
				sizeOption cupsize = S;
				//size validation
				if (line[2] == '2') {
					cupsize = M;
				}
				if (line[2] == '3') {
					cupsize = L;
				}
				
				Yogurt* yo = new Yogurt();
				yo->setName(_T("Frozen Yogurt"));
				yo->setCupSize(cupsize);
				if (line[4] == '1') 
				{
					yo->addAddons(_T("Oreo"));
				}
				if (line[6] == '1')
				{
					yo->addAddons(_T("Sprinkles"));
				}
				if (line[8] == '1')
				{
					yo->addAddons(_T("Strawberries"));
				}
				if (line[10] == '1')
				{
					yo->addAddons(_T("Pineapple"));
				}

				MyOrder->addProduct(yo);
			}
		}
	}
	file.close();
	return true;
}