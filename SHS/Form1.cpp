#include "pch.h"
#include "Form1.h"
#include <string>
#include <queue>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

namespace CppCLRWinformsProjekt {

	void Form1::AddEntry(int id, String^ name, double givenPrice)
	{
		Good^ good = gcnew Good();

		good->Id = id;
		good->GoodName = name;
		good->ActualPrice = givenPrice - 50;
		good->GivenPrice = givenPrice;
		good->GivenDate = DateTime::Now;

		Goods->Enqueue(good);
	}

	void Form1::RemoveEntry(int id)
	{
		Queue^ tmp = gcnew Queue();

		for each (Good ^ good in Goods)
		{
			Good^ g = safe_cast<Good^>(good);
			if (g->Id != id) 
			{
				tmp->Enqueue(g);
				break;
			}
		}

		Goods = tmp;	
	}
}