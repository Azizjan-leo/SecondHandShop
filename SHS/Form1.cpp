#include "pch.h"
#include "Form1.h"
#include <string>
#include <queue>
#include <msclr\marshal_cppstd.h>
#include <fstream>

using namespace System;
using namespace msclr::interop;


namespace CppCLRWinformsProjekt {

	std::ostream& operator<<(std::ostream& os, Good^ good)
	{
		using namespace Runtime::InteropServices;
	
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(good->Id + " " + good->GoodName + " " + good->GivenDate + " " + good->GivenPrice)).ToPointer();
		std::string theStr = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));

		os << theStr;
		return os;
	}
	std::istream& operator>>(std::istream& is, Good^ good)
	{
		int id;
		std::string goodName, givenDate;
		double givenPrice;
		is >> id >> goodName >> givenDate >> givenPrice;
		
		String^ dateStr = gcnew String(givenDate.c_str());


		good->Id = id;
		good->GoodName = gcnew String(goodName.c_str());
		good->GivenDate = DateTime::Parse(dateStr);
		good->GivenPrice = givenPrice;
		return is;
	}
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
	void Form1::WriteData()
	{
		std::string path = "file.txt";
		std::fstream fs;
		fs.open(path, std::fstream::out);
		if (!fs.is_open())
		{
			return;
		}
		else
		{
			for each (Good ^ good in Goods)
			{
				fs << good << std::endl;
			}
		}
		fs.close();
	}
	void Form1::ReadData()
	{
		std::string path = "file.txt";
		std::fstream fs;
		fs.open(path, std::fstream::in);
		if (!fs.is_open())
		{
			return;
		}
		else
		{
			while (true)
			{
				Good^ good = gcnew Good();
				fs >> good;
				if (fs.eof())
				{
					break;
				}
				Goods->Enqueue(good);
			}
		}
		fs.close();
	}
}