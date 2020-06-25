#pragma once
namespace CppCLRWinformsProjekt {
	public ref class Good // класс товара
	{
	public:
		int Id;
		System::String^ GoodName ;
		double GivenPrice;
		System::DateTime GivenDate;
		double ActualPrice;
	};
}
