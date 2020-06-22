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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GoodName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GivenDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GivenPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ActualPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 214);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"Second Hand Shop";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		

		Good^ good = gcnew Good();
		
		good->Id = 1;
		good->GoodName = "Õîëîäèëüíèê";
		good->ActualPrice = 500;
		good->GivenPrice = 550;
		good->GivenDate = DateTime::Now;
		
	System:Queue^ goods = gcnew Queue();
		goods->Enqueue(good);
		int i = 0;
		while (goods->Count) // 0 ïðèíèìàåòñÿ çà false
		{
			Good^ g = safe_cast<Good^>(goods->Dequeue());

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
	};
}
