#pragma once
#include "GlobalData.h"

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ParametersForm
	/// </summary>
	public ref class ParametersForm : public System::Windows::Forms::Form
	{
	public:
		ParametersForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ParametersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	protected:
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(12, 64);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 0;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(274, 64);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 1;
			// 
			// ParametersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(486, 261);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Name = L"ParametersForm";
			this->Text = L"ѕараметры";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ParametersForm::ParametersForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ParametersForm::ParametersForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ParametersForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//DateTime v = this->dateTimePicker1->Value;
		//DateTime^ v = gcnew DateTime(MainData.StartDate);
		this->dateTimePicker1->Value = DateTime(MainData.StartDate.tm_year+1900, MainData.StartDate.tm_mon+1, MainData.StartDate.tm_mday);
		this->dateTimePicker2->Value = DateTime(MainData.StartDate.tm_year + 1900, MainData.StartDate.tm_mon + 1, MainData.StartDate.tm_mday).AddDays(MainData.Days);

	}
	private: System::Void ParametersForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		int year = this->dateTimePicker1->Value.Year;
		int month = this->dateTimePicker1->Value.Month;
		int day = this->dateTimePicker1->Value.Day;

		MainData.StartDate.tm_year = year - 1900;
		MainData.StartDate.tm_mon = month - 1;
		MainData.StartDate.tm_mday = day;

		MainData.Days = ((this->dateTimePicker2->Value) - (this->dateTimePicker1->Value)).TotalDays;
	}
	};
}
