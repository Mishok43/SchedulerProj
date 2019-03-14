#pragma once
#include "GlobalData.h"
#include "GeneratedSchedule.h"

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ParametersForm
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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Label^  labelTitle;
	private: System::Windows::Forms::TextBox^  textBoxTitle;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

	private: cli::array<System::Windows::Forms::DateTimePicker^>^  dateTimePickerStart;
	private: cli::array<System::Windows::Forms::DateTimePicker^>^  dateTimePickerEnd;
	private: cli::array<System::Windows::Forms::Label^>^  labelN;

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
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->textBoxTitle = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(15, 74);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 23);
			this->dateTimePicker1->TabIndex = 0;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker2->Location = System::Drawing::Point(274, 74);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 23);
			this->dateTimePicker2->TabIndex = 1;
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTitle->Location = System::Drawing::Point(12, 25);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(76, 17);
			this->labelTitle->TabIndex = 2;
			this->labelTitle->Text = L"Заголовок";
			// 
			// textBoxTitle
			// 
			this->textBoxTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxTitle->Location = System::Drawing::Point(94, 22);
			this->textBoxTitle->Name = L"textBoxTitle";
			this->textBoxTitle->Size = System::Drawing::Size(380, 23);
			this->textBoxTitle->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Начало";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(271, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Конец";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Занятий в день";
			// 
			// numericUpDown
			// 
			this->numericUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown->Location = System::Drawing::Point(128, 112);
			this->numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown->Name = L"numericUpDown";
			this->numericUpDown->Size = System::Drawing::Size(53, 23);
			this->numericUpDown->TabIndex = 7;
			this->numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numericUpDown->ValueChanged += gcnew System::EventHandler(this, &ParametersForm::numericUpDown_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(157, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Начало";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(333, 146);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Конец";
			// 
			// ParametersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(486, 170);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numericUpDown);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxTitle);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"ParametersForm";
			this->Text = L"Параметры";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ParametersForm::ParametersForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ParametersForm::ParametersForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ParametersForm_Load(System::Object^  sender, System::EventArgs^  e) {




		this->dateTimePickerStart = gcnew cli::array<System::Windows::Forms::DateTimePicker^>(20);
		this->dateTimePickerEnd = gcnew cli::array<System::Windows::Forms::DateTimePicker^>(20);
		this->labelN = gcnew cli::array<Label^>(20);
		for (int i = 0; i < 20; i++)
		{
			this->labelN[i] = gcnew System::Windows::Forms::Label();
			this->labelN[i]->Text = "Занятие " + (i + 1) + ":";
			this->labelN[i]->AutoSize = true;
			this->labelN[i]->Location = System::Drawing::Point(12, 180 + i * 20);
			this->Controls->Add(labelN[i]);


			this->dateTimePickerStart[i] = gcnew System::Windows::Forms::DateTimePicker();
			this->dateTimePickerStart[i]->Location = System::Drawing::Point(12+120, 180 + i * 20);
			this->dateTimePickerStart[i]->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerStart[i]->Size = System::Drawing::Size(100, 23);
			this->dateTimePickerStart[i]->CustomFormat = "HH:mm";
			this->dateTimePickerStart[i]->Value = DateTime(2029, 5, 3, Rules::Settings.ActivityStartTime[i]/60, Rules::Settings.ActivityStartTime[i]%60, 0);
			this->dateTimePickerStart[i]->ShowUpDown = true;

			this->dateTimePickerStart[i]->Enabled = GlobalData::Access == GlobalData::MANAGER;

			this->dateTimePickerEnd[i] = gcnew System::Windows::Forms::DateTimePicker();
			this->dateTimePickerEnd[i]->Location = System::Drawing::Point(12 + 300, 180 + i * 20);
			this->dateTimePickerEnd[i]->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerEnd[i]->Size = System::Drawing::Size(100, 23);
			this->dateTimePickerEnd[i]->CustomFormat = "HH:mm";
			this->dateTimePickerEnd[i]->Value = DateTime(2019, 5, 3, Rules::Settings.ActivityEndTime[i] / 60, Rules::Settings.ActivityEndTime[i] % 60, 0);
			this->dateTimePickerEnd[i]->ShowUpDown = true;

			this->dateTimePickerEnd[i]->Enabled = GlobalData::Access == GlobalData::MANAGER;

			this->Controls->Add(dateTimePickerStart[i]);
			this->Controls->Add(dateTimePickerEnd[i]);
		}

		this->textBoxTitle->Text = gcnew System::String(MainData.Title.c_str());

		this->textBoxTitle->Enabled = GlobalData::Access == GlobalData::MANAGER;

		this->dateTimePicker1->Value = DateTime(Rules::Settings.StartDate.tm_year + 1900, Rules::Settings.StartDate.tm_mon+1, Rules::Settings.StartDate.tm_mday);
		this->dateTimePicker2->Value = DateTime(Rules::Settings.StartDate.tm_year + 1900, Rules::Settings.StartDate.tm_mon + 1, Rules::Settings.StartDate.tm_mday).AddDays(Rules::Settings.Days);

		this->dateTimePicker1->Enabled = GlobalData::Access == GlobalData::MANAGER;
		this->dateTimePicker2->Enabled = GlobalData::Access == GlobalData::MANAGER;

		this->numericUpDown->Value = Rules::Settings.ActivitiesPerDay;

		this->numericUpDown->Enabled = GlobalData::Access == GlobalData::MANAGER;

		this->updateSize();




		

	}
	private: System::Void ParametersForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		
		MainData.Title = msclr::interop::marshal_as<std::string>(this->textBoxTitle->Text);
		
		int year = this->dateTimePicker1->Value.Year;
		int month = this->dateTimePicker1->Value.Month;
		int day = this->dateTimePicker1->Value.Day;

		Rules::Settings.StartDate.tm_year = year - 1900;
		Rules::Settings.StartDate.tm_mon = month - 1;
		Rules::Settings.StartDate.tm_mday = day;

		Rules::Settings.Days = ((this->dateTimePicker2->Value) - (this->dateTimePicker1->Value)).TotalDays;
	
		Rules::Settings.ActivitiesPerDay = (int)this->numericUpDown->Value;


		for (int i = 0; i < 20; i++)
		{
			Rules::Settings.ActivityStartTime[i] = 
				this->dateTimePickerStart[i]->Value.Hour * 60 + 
				this->dateTimePickerStart[i]->Value.Minute;

			Rules::Settings.ActivityEndTime[i] =
				this->dateTimePickerEnd[i]->Value.Hour * 60 +
				this->dateTimePickerEnd[i]->Value.Minute;
		}


		Schedule.reset();
	}
	private: System::Void numericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		this->updateSize();
	}
	private: System::Void updateSize()
	{
		this->Size = System::Drawing::Size(502, 200+20+20*(int)numericUpDown->Value);
	}
};
}
