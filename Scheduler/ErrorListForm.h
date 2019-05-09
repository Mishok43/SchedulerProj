#pragma once
#include "GeneratedSchedule.h"

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ErrorListForm
	/// </summary>
	public ref class ErrorListForm : public System::Windows::Forms::Form
	{
	public:
		ErrorListForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ErrorListForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView;
	protected:



	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errorPos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  errorText;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->errorPos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->errorText = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->errorPos,
					this->errorText
			});
			this->dataGridView->Location = System::Drawing::Point(17, 28);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView->Size = System::Drawing::Size(691, 247);
			this->dataGridView->TabIndex = 0;
			// 
			// errorPos
			// 
			this->errorPos->HeaderText = L"Расположение ошибки";
			this->errorPos->Name = L"errorPos";
			this->errorPos->ReadOnly = true;
			this->errorPos->Width = 300;
			// 
			// errorText
			// 
			this->errorText->HeaderText = L"Текст ошибки";
			this->errorText->Name = L"errorText";
			this->errorText->ReadOnly = true;
			this->errorText->Width = 1000;
			// 
			// buttonOK
			// 
			this->buttonOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonOK->Location = System::Drawing::Point(633, 281);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 1;
			this->buttonOK->Text = L"ОК";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &ErrorListForm::buttonOK_Click);
			// 
			// ErrorListForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 321);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->dataGridView);
			this->Name = L"ErrorListForm";
			this->Text = L"Синтаксические ошибки";
			this->Load += gcnew System::EventHandler(this, &ErrorListForm::ErrorListForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ErrorListForm_Load(System::Object^  sender, System::EventArgs^  e) {

		vector<pair<string, string>> v = Schedule.getErrors();


		this->dataGridView->Rows->Clear();

		for (auto c = v.begin(); c != v.end(); ++c)
		{
			cli::array<System::String^>^ a = gcnew cli::array<System::String^>(2);
			a[0] = gcnew System::String(c->first.c_str());
			a[1] = gcnew System::String(c->second.c_str());
			this->dataGridView->Rows->Add(a);
		}
			
	}
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
