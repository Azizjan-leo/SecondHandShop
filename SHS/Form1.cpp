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
		int i = 0; // ��� ���������� 
		dataGridView1->Rows->Clear(); // ������� �������

		for each (Good ^ g in Goods) // �������� �� ������� �������� � �������
		{
			DataGridViewRow^ rowFullName = gcnew DataGridViewRow; // ������� ������ �� �������
			DataGridViewCell^ celFullName = gcnew DataGridViewTextBoxCell; // ������� ������ �� �������
			rowFullName->Cells->Add(celFullName); // ��������� ������ � ������
			dataGridView1->Rows->Add(rowFullName); // ��������� ������ � �������
			// �������������� ������ ������ ����� ������ ���������������� ������� �������� �������� �������
			dataGridView1->Rows[i]->Cells[0]->Value = g->Id;
			dataGridView1->Rows[i]->Cells[1]->Value = g->GoodName;
			dataGridView1->Rows[i]->Cells[2]->Value = g->GivenDate;
			dataGridView1->Rows[i]->Cells[3]->Value = g->GivenPrice;
			dataGridView1->Rows[i]->Cells[4]->Value = g->ActualPrice;
			i++; // �������������� ����������
		}
	}
	void Form1::AddEntry(String^ name, double givenPrice)
	{
		Good^ good = gcnew Good(); // ������� ����� �������

		good->Id = ++index; //��� �������� ����� ����� ����������� id � ������ +1
		good->GoodName = name;
		good->ActualPrice = givenPrice; // �� ������ ���� ������� ����� ��������� ���� ������
		good->GivenPrice = givenPrice;
		good->GivenDate = DateTime::Now; // ���������� ������� ����

		Goods->Enqueue(good); // ��������� � �������
	}

	void Form1::UpdateEntry(Good^ good)
	{
		Queue^ tmp = gcnew Queue(); // ������� ��������� �������

		for each (Good ^ item in Goods) // �������� ������ �� ������������ �������
		{
			if (item->Id == good->Id) // ���� id �������� �������� ����� id ����������� 
			{
				// ��������� � ��������������� ���� �������� �������� �������� �� ����������� �������
				item->GoodName = good->GoodName;
				item->GivenDate = good->GivenDate;
				item->GivenPrice = good->GivenPrice;
			}
			Good^ g = item; // ������� ��������� ������ �� ������ ��������
			tmp->Enqueue(g); // ��������� ��� �� ��������� �������
		}

		Goods = tmp; // ����������� �������� ������� �������� �� ���������
	}

	void Form1::RemoveEntry(int id)
	{
		Queue^ tmp = gcnew Queue();// ������� ��������� �������

		for each (Good ^ good in Goods) // �������� ������ �� ������������ �������
		{
			Good^ g = good; // ������� ��������� ������ �� ������ �������� ��������
			if (g->Id != id) // ���� ��� �������� �� ����� �����������
			{
				tmp->Enqueue(g); // ��������� ������� � �������
				break; // ������� �� �����
			}
		}

		Goods = tmp; // ����������� �������� ������� �������� ���������
	}
	void Form1::WriteData()
	{
		StreamWriter^ pwriter = gcnew StreamWriter("file.txt"); // ��������� ���� ��� ������
		int index = 0; // ��� ������������� id

		for each (Good ^ good in Goods) // �������� ������ �� ���� ��������� �������
		{
			if (good->Id > index) // ���� id �������� �������� ������ �������������
				index = good->Id;  // ����������� ������������� �������� id �������� ��������
		}

		pwriter->WriteLine(index); // ���������� �������� ������������� id � ������ ������ �����
		for each (Good ^ good in Goods) // �������� ������ �� ���� ��������� �������
		{
			// ������� ������ ��������� ������ � ����������� ���� ����� ������� ������ � �������
			String^ str = good->Id + ";" + good->GoodName + ";" + good->GivenDate + ";" + good->GivenPrice;
			pwriter->WriteLine(str); // ����������� ��������� ������ (1 ������ = 1 ������)
		}
		pwriter->Close(); // ��������� ���� ��� ������
	}
	void Form1::ReadData()
	{
		StreamReader^ din = nullptr; // ������� ������ ������
		try
		{
			din = gcnew StreamReader("file.txt"); // �������������� ��� � � �������� ��������� �������� �������� �����, ������� ��������� �������

			index = Int32::Parse(din->ReadLine()); // ���������� ������ ������ �����. ��� ������������ id. �������������� ��� ��������� ��� ����������
		
			while (din->Peek() >= 0)  // ���� ���� ��� ������
			{
				String^ line = din->ReadLine(); // ���������� ������
				array<String^>^ parts = line->Split(';'); // ������� ������ �����, ���������� �������� ����� �������� ����������� ������ � �������


				Good^ good = gcnew Good(); // ������� ����� ������ ������

				// �������������� ��� ���� ��������������� ���������
				good->Id = Int32::Parse(parts[0]);
				good->GoodName = parts[1];
				good->GivenDate = DateTime::Parse(parts[2]);
				good->GivenPrice = Double::Parse(parts[3]);

				// ������� ������� ����� ������� ����� � ����� ��������� ������ � ����
				TimeSpan diff = DateTime::Now - good->GivenDate;
				int days = diff.Days;
				
				// �������������� ���� ���� ������ ����� ���� ��������� ������
				good->ActualPrice = good->GivenPrice;
				if (days > 15) // ���� ����� � ��� ��� ������ 15�� ����
				{
					// �������� �� ��������� 5% ����������� ��������� � ����������� ��� �������� ���� ���������� ����
					good->ActualPrice -= good->GivenPrice * 5 / 100;
				}

				if (days > 30) // ���� ����� ����� 30 ���� �� ����� ������
				{
					// �������� �� ����������� ��� 10% ����������� ��������� � ����������� ��� �������� ���� ���������� ����
					good->ActualPrice -= good->GivenPrice * 10 / 100; 
					
					// ������� ��������� ������ �������� ���� ����� ����� �� ����������� � ���������� ��� �������� � ����������
					int bulgeDays = days - 30;

					if (bulgeDays > 0) // ���� ����� ����� ������ 30 ����
					{
						if (bulgeDays > 60) // ���� ������ ���� �������
							bulgeDays = 60; // ������� ��� ����� ��� ������, ��� ��� ����� �� ����� ���� ������ ����� ��� �� 75% 
											// (60 + 15, ���������� � ���������� ���� ��������������� �������� ������)
						good->ActualPrice -= good->GivenPrice * bulgeDays / 100; // ��������� ����� �� ������� �� ����� ����
					}
				}
					

				Goods->Enqueue(good); // ��������� ����� � �������
			}
			din->Close(); // ��������� ����� ��� ������
		}
		catch (Exception^ e) {
			// � ����� ���?
		}
		finally
		{
			if (din != nullptr) // ���� �������� �������� ����� ��� ������ �� ������ �������
				delete din; // �������� ���������, ������� �� ��������� ������ ��������� ��������� ����
		}
	}
}