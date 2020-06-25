#pragma once
#include "Good.h"
#include <queue> // библиотека, хранящая необходимую структуру (очередь)

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ InputPriceTxt;
	private: System::Windows::Forms::TextBox^ InputNameTxt;
	private: System::Windows::Forms::Button^ addNewEntryBtn;
	private: System::Windows::Forms::Button^ DeleteBtn;
	private: Queue^ Goods = gcnew Queue(); // Очередь, в которой будут наши товары
	private: int index = 0; // Максимальный индекс. Дабы обеспечить правильный прирост id элементов
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GoodName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GivenDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GivenPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ActualPrice;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		
	

		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->InputPriceTxt = (gcnew System::Windows::Forms::TextBox());
			this->InputNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->addNewEntryBtn = (gcnew System::Windows::Forms::Button());
			this->DeleteBtn = (gcnew System::Windows::Forms::Button());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GoodName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GivenDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GivenPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ActualPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Id, this->GoodName,
					this->GivenDate, this->GivenPrice, this->ActualPrice
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(598, 168);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellEndEdit);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->InputPriceTxt);
			this->panel1->Controls->Add(this->InputNameTxt);
			this->panel1->Controls->Add(this->addNewEntryBtn);
			this->panel1->Location = System::Drawing::Point(12, 186);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(205, 92);
			this->panel1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Given price";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(50, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Name";
			// 
			// InputPriceTxt
			// 
			this->InputPriceTxt->Location = System::Drawing::Point(91, 29);
			this->InputPriceTxt->Name = L"InputPriceTxt";
			this->InputPriceTxt->Size = System::Drawing::Size(100, 20);
			this->InputPriceTxt->TabIndex = 2;
			// 
			// InputNameTxt
			// 
			this->InputNameTxt->Location = System::Drawing::Point(91, 3);
			this->InputNameTxt->Name = L"InputNameTxt";
			this->InputNameTxt->Size = System::Drawing::Size(100, 20);
			this->InputNameTxt->TabIndex = 1;
			// 
			// addNewEntryBtn
			// 
			this->addNewEntryBtn->Location = System::Drawing::Point(116, 55);
			this->addNewEntryBtn->Name = L"addNewEntryBtn";
			this->addNewEntryBtn->Size = System::Drawing::Size(75, 23);
			this->addNewEntryBtn->TabIndex = 0;
			this->addNewEntryBtn->Text = L"Add";
			this->addNewEntryBtn->UseVisualStyleBackColor = true;
			this->addNewEntryBtn->Click += gcnew System::EventHandler(this, &Form1::addNewEntryBtn_Click);
			// 
			// DeleteBtn
			// 
			this->DeleteBtn->Location = System::Drawing::Point(535, 186);
			this->DeleteBtn->Name = L"DeleteBtn";
			this->DeleteBtn->Size = System::Drawing::Size(75, 23);
			this->DeleteBtn->TabIndex = 2;
			this->DeleteBtn->Text = L"Delete";
			this->DeleteBtn->UseVisualStyleBackColor = true;
			this->DeleteBtn->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);
			// 
			// Id
			// 
			this->Id->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->Id->HeaderText = L"ID";
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			this->Id->Width = 43;
			// 
			// GoodName
			// 
			this->GoodName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->GoodName->HeaderText = L"Name";
			this->GoodName->Name = L"GoodName";
			this->GoodName->Width = 60;
			// 
			// GivenDate
			// 
			this->GivenDate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->GivenDate->HeaderText = L"Given Date";
			this->GivenDate->Name = L"GivenDate";
			this->GivenDate->Width = 86;
			// 
			// GivenPrice
			// 
			this->GivenPrice->HeaderText = L"Given Price";
			this->GivenPrice->Name = L"GivenPrice";
			// 
			// ActualPrice
			// 
			this->ActualPrice->HeaderText = L"Actual Price";
			this->ActualPrice->Name = L"ActualPrice";
			this->ActualPrice->ReadOnly = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 287);
			this->Controls->Add(this->DeleteBtn);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"Second Hand Shop";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Объявление функций
		private: void LoadTable(); // Загрузка ui-таблицы из очереди 
		private: void AddEntry(String^ name, double givenPrice); // Добавление нового товара
		private: void UpdateEntry(Good^ good); // Обновление товара
		private: void RemoveEntry(int id); // Удаление товара по Id
		private: void WriteData(); // Запись данных в файл
		private: void ReadData(); // Загрузка данных с файла
	/// <summary>
	/// Старт формы
	/// </summary>
	private: Void Form1_Load(Object^ sender, EventArgs^ e) {
		ReadData(); // загружае данные из файла в очередь
		LoadTable(); // обновляем таблицу на формее в соответствии с данными в очереди
	}
	/// <summary>
	/// Обработчик нажатия кнопки создания нового элемента
	/// </summary>
	private: Void addNewEntryBtn_Click(Object^ sender, EventArgs^ e) 
	{
		// Передаем функции добавления записи Название нового товара и его стартовую цену
		AddEntry(InputNameTxt->Text, Convert::ToDouble(InputPriceTxt->Text));
		// обновляем таблицу на формее в соответствии с данными в очереди
		LoadTable();
	}

	/// <summary>
	/// Обработчик кнопки удаления элементов
	/// </summary>
	private: Void btnDelete_Click(Object^ sender, EventArgs^ e)
	{
		for each (DataGridViewRow^ item  in dataGridView1->SelectedRows) // проходим по каждому выделенному элементу таблицы на форме
		{
			int id = Convert::ToInt32(item->Cells[0]->Value); // вытаскиваем id, который находится в первой ячейке
			RemoveEntry(id); // вызываем функцию удаления товара, передав ей id удаляемого элемента
			dataGridView1->Rows->RemoveAt(item->Index); // удаляем выбранную строку из таблицы
		}
	}
	/// <summary>
	/// Обработчик закрытия формы
	/// </summary>
	private: System::Void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		WriteData(); // вызываем функцию записи очереди в файл
	}

	/// <summary>
	/// Обработчик окончания редактирования ячейки в таблице на форме
	/// </summary>
	private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
		DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex]; // вытягиваем строку, которая редактировалась
	
		Good^ good = gcnew Good(); // создаем новый объект товара, в который записываем обновленные данные и id отредактированного товара
		good->Id = Convert::ToInt32(row->Cells[0]->Value); 
		good->GoodName = row->Cells[1]->Value->ToString();
		good->GivenDate = Convert::ToDateTime(row->Cells[2]->Value);
		good->GivenPrice = Convert::ToDouble(row->Cells[3]->Value);
	
		UpdateEntry(good); // вызываем функцию обновления записи
	}
};
}
