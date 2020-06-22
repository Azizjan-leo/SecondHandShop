#include "pch.h"
#include "Form1.h"
#include <string>
#include <queue>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

namespace CppCLRWinformsProjekt {


	Queue^ CppCLRWinformsProjekt::Form1::LoadList(Queue^ goods)
	{
		Good^ good = gcnew Good();

		good->Id = 1;
		good->GoodName = "Холодильник";
		good->ActualPrice = 500;
		good->GivenPrice = 550;
		good->GivenDate = DateTime::Now;

		goods->Enqueue(good);
		return goods;
	}
	void Form1::AddEntry(int id, Queue^ goods, String^ name, double givenPrice)
	{
		Good^ good = gcnew Good();

		good->Id = id;
		good->GoodName = name;
		good->ActualPrice = givenPrice - 50;
		good->GivenPrice = givenPrice;
		good->GivenDate = DateTime::Now;

		goods->Enqueue(good);
	}
	/*int CppCLRWinformsProjekt::Form1::AddEntry(Queue^ goods, String^ name, double givenPrice)
	{
		Good^ good = gcnew Good();

		good->Id = 2;
		good->GoodName = name;
		good->ActualPrice = givenPrice-50;
		good->GivenPrice = givenPrice;
		good->GivenDate = DateTime::Now;

		Queue^ goods = gcnew Queue();
		goods->Enqueue(good);
		return 1;
	}*/
}