#pragma once
#include "Good.h"
#include <queue>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GoodName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GivenDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GivenPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ActualPrice;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ InputPriceTxt;
	private: System::Windows::Forms::TextBox^ InputNameTxt;
	private: System::Windows::Forms::Button^ addNewEntryBtn;










	




	protected:





	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		
	

		void InitializeComponent(void)
		{
			goods = gcnew Queue();
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GoodName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GivenDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GivenPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ActualPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->addNewEntryBtn = (gcnew System::Windows::Forms::Button());
			this->InputNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->InputPriceTxt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->dataGridView1->Location = System::Drawing::Point(12, 175);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(598, 150);
			this->dataGridView1->TabIndex = 0;
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
			this->GivenDate->ReadOnly = true;
			this->GivenDate->Width = 86;
			// 
			// GivenPrice
			// 
			this->GivenPrice->HeaderText = L"Given Price";
			this->GivenPrice->Name = L"GivenPrice";
			this->GivenPrice->ReadOnly = true;
			// 
			// ActualPrice
			// 
			this->ActualPrice->HeaderText = L"Actual Price";
			this->ActualPrice->Name = L"ActualPrice";
			this->ActualPrice->ReadOnly = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->InputPriceTxt);
			this->panel1->Controls->Add(this->InputNameTxt);
			this->panel1->Controls->Add(this->addNewEntryBtn);
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(337, 156);
			this->panel1->TabIndex = 1;
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
			// InputNameTxt
			// 
			this->InputNameTxt->Location = System::Drawing::Point(91, 3);
			this->InputNameTxt->Name = L"InputNameTxt";
			this->InputNameTxt->Size = System::Drawing::Size(100, 20);
			this->InputNameTxt->TabIndex = 1;
			// 
			// InputPriceTxt
			// 
			this->InputPriceTxt->Location = System::Drawing::Point(91, 29);
			this->InputPriceTxt->Name = L"InputPriceTxt";
			this->InputPriceTxt->Size = System::Drawing::Size(100, 20);
			this->InputPriceTxt->TabIndex = 2;
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Given price";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 337);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"Second Hand Shop";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: Queue^ LoadList(Queue^ goods);
		private: void AddEntry(int id, Queue^ goods, String^ name, double givenPrice);
		private: Queue^ goods;
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		
		int i = 0;
		int count = goods->Count;
		//dataGridView1->DataSource = NULL;
		dataGridView1->Rows->Clear();

		for each (Good^ good in goods)
		{
			Good^ g = safe_cast<Good^>(good);

			DataGridViewRow^ rowFullName = gcnew DataGridViewRow;
			DataGridViewCell^ celFullName = gcnew DataGridViewTextBoxCell;
			rowFullName->Cells->Add(celFullName);
			dataGridView1->Rows->Add(rowFullName);
			dataGridView1->Rows[i]->Cells[0]->Value = g->Id;
			dataGridView1->Rows[i]->Cells[1]->Value = g->GoodName;
			dataGridView1->Rows[i]->Cells[2]->Value = g->GivenDate;
			dataGridView1->Rows[i]->Cells[3]->Value = g->GivenPrice;
			dataGridView1->Rows[i]->Cells[4]->Value = g->ActualPrice;
			i++;
		}
	}

		   int b = 1;
	private: System::Void addNewEntryBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		AddEntry(b++, goods, InputNameTxt->Text, 100);
		Form1_Load(sender,e);
	}
};
}
