#include "pch.h"
#include "Form1.h"
#include <string>
#include <queue>
#include <fstream>
using namespace System::IO;

using namespace System;


namespace CppCLRWinformsProjekt {

	void Form1::LoadTable()
	{
		int i = 0; // для индексации 
		dataGridView1->Rows->Clear(); // очищаем таблицу

		for each (Good ^ g in Goods) // проходим по каждому элементу в очереди
		{
			DataGridViewRow^ rowFullName = gcnew DataGridViewRow; // создаем строку на таблице
			DataGridViewCell^ celFullName = gcnew DataGridViewTextBoxCell; // создаем ячейку на таблице
			rowFullName->Cells->Add(celFullName); // добавляем ячейку в строку
			dataGridView1->Rows->Add(rowFullName); // добавляем строку в таблицу
			// инициализируем каждую ячейку новой строки соответствующими данными текущего элемента очереди
			dataGridView1->Rows[i]->Cells[0]->Value = g->Id;
			dataGridView1->Rows[i]->Cells[1]->Value = g->GoodName;
			dataGridView1->Rows[i]->Cells[2]->Value = g->GivenDate;
			dataGridView1->Rows[i]->Cells[3]->Value = g->GivenPrice;
			dataGridView1->Rows[i]->Cells[4]->Value = g->ActualPrice;
			i++; // инкрементируем индексатор
		}
	}
	void Form1::AddEntry(String^ name, double givenPrice)
	{
		Good^ good = gcnew Good(); // создаем новый элемент

		good->Id = ++index; //его айдишник будет равен наибольшему id в очерди +1
		good->GoodName = name;
		good->ActualPrice = givenPrice; // по началу цена продажи равна оценочной цене товара
		good->GivenPrice = givenPrice;
		good->GivenDate = DateTime::Now; // записываем текущую дату

		Goods->Enqueue(good); // добавляем в очередь
	}

	void Form1::UpdateEntry(Good^ good)
	{
		Queue^ tmp = gcnew Queue(); // создаем временную очередь

		for each (Good ^ item in Goods) // проходим циклом по существующей очереди
		{
			if (item->Id == good->Id) // если id текущего элемента равен id изменяемого 
			{
				// вставляем в соответствующие поля текущего элемента значения из полученного объекта
				item->GoodName = good->GoodName;
				item->GivenDate = good->GivenDate;
				item->GivenPrice = good->GivenPrice;
			}
			Good^ g = item; // создаем временный объект на основе текущего
			tmp->Enqueue(g); // добавляем его во временную очередь
		}

		Goods = tmp; // присваиваем основной очереди значения из временной
	}

	void Form1::RemoveEntry(int id)
	{
		Queue^ tmp = gcnew Queue();// создаем временную очередь

		for each (Good ^ good in Goods) // проходим циклом по существующей очереди
		{
			Good^ g = good; // создаем временный объект на основе текущего элемента
			if (g->Id != id) // если его айдишник не равен полученному
			{
				tmp->Enqueue(g); // добавляем элемент в очередь
				break; // выходим из цикла
			}
		}

		Goods = tmp; // присваиваем основной очереди значения временной
	}
	void Form1::WriteData()
	{
		StreamWriter^ pwriter = gcnew StreamWriter("file.txt"); // открываем файл для записи
		int index = 0; // для максимального id

		for each (Good ^ good in Goods) // проходим циклом по всем элементам очереди
		{
			if (good->Id > index) // елси id текущего элемента больше максимального
				index = good->Id;  // присваиваем максимальному значение id текущего элемента
		}

		pwriter->WriteLine(index); // записываем значение максимального id в первую строку файла
		for each (Good ^ good in Goods) // проходим циклом по всем элементам очереди
		{
			// создаем строку выраающую объект и разделяющий поля этого объекта точкой с запятой
			String^ str = good->Id + ";" + good->GoodName + ";" + good->GivenDate + ";" + good->GivenPrice;
			pwriter->WriteLine(str); // записываыем созданную строку (1 объект = 1 строка)
		}
		pwriter->Close(); // закрываем файл для записи
	}
	void Form1::ReadData()
	{
		StreamReader^ din = nullptr; // создаем объект чтения
		try
		{
			din = gcnew StreamReader("file.txt"); // инициализируем его и в качестве параметра передаем название файла, который предстоит считать

			index = Int32::Parse(din->ReadLine()); // ссчитываем первую строку файла. это максимальный id. инициализируем его значением наш индексатор
		
			while (din->Peek() >= 0)  // пока есть что читать
			{
				String^ line = din->ReadLine(); // ссчитываем строку
				array<String^>^ parts = line->Split(';'); // создаем массив строк, содержащий значения полей объектов разделенных точкой с запятой


				Good^ good = gcnew Good(); // создаем новый объект товара

				// инициализируем его поля соответствующми сктроками
				good->Id = Int32::Parse(parts[0]);
				good->GoodName = parts[1];
				good->GivenDate = DateTime::Parse(parts[2]);
				good->GivenPrice = Double::Parse(parts[3]);

				// считаем разницу между текущей датой и датой получения товара в днях
				TimeSpan diff = DateTime::Now - good->GivenDate;
				int days = diff.Days;
				
				// инициализируем поле цены товара полем цены получения товара
				good->ActualPrice = good->GivenPrice;
				if (days > 15) // если товар у нас уже больше 15ти дней
				{
					// отнимаем от стоимости 5% изначальной стоимости и присваиваем это значение полю актуальная цена
					good->ActualPrice -= good->GivenPrice * 5 / 100;
				}

				if (days > 30) // если товар более 30 дней на нашем складе
				{
					// отнимаем от тестоимости ещё 10% изначальной стоимости и присваиваем это значение полю актуальная цена
					good->ActualPrice -= good->GivenPrice * 10 / 100; 
					
					// смотрим насколько больше тридцати дней товар лежит на нашемскладе и записываем это значение в переменную
					int bulgeDays = days - 30;

					if (bulgeDays > 0) // если товар лежит дольше 30 дней
					{
						if (bulgeDays > 60) // если дольше двух месяцев
							bulgeDays = 60; // считаем что лежал два месяца, так как товар не может быть уценён более чем на 75% 
											// (60 + 15, полученные в результате двух предшедствующих операций уценки)
						good->ActualPrice -= good->GivenPrice * bulgeDays / 100; // уцениваем товар на процент за кажды день
					}
				}
					

				Goods->Enqueue(good); // добавляем товар в очередь
			}
			din->Close(); // закрываем товар для чтения
		}
		catch (Exception^ e) {
			// а вдруг что?
		}
		finally
		{
			if (din != nullptr) // если операция закрытия файла для чтения не прошла успешно
				delete din; // обнуляем указатель, который не позволяет другим процессам открывать файл
		}
	}
}