#pragma once
#include "Rules.h"
#include "ScheduleObject.h"
#include "GlobalData.h"
#include "GeneratedSchedule.h"
#include "Excel/ExcelFormat.h"

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ScheduleForm
	/// </summary>
	public ref class ScheduleForm : public System::Windows::Forms::Form
	{
	public:
		ScheduleForm(void)
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
		~ScheduleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonGenerate;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::Button^  buttonExport;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  labelOutput;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::CheckBox^  checkBoxWeek;




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
			this->buttonGenerate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelOutput = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->checkBoxWeek = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// buttonGenerate
			// 
			this->buttonGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonGenerate->Location = System::Drawing::Point(12, 12);
			this->buttonGenerate->Name = L"buttonGenerate";
			this->buttonGenerate->Size = System::Drawing::Size(260, 46);
			this->buttonGenerate->TabIndex = 0;
			this->buttonGenerate->Text = L"Сгенерировать расписание";
			this->buttonGenerate->UseVisualStyleBackColor = true;
			this->buttonGenerate->Click += gcnew System::EventHandler(this, &ScheduleForm::buttonGenerate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 105);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Таблица:";
			// 
			// comboBox
			// 
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Группы", L"Преподаватели", L"Дисциплины", L"Аудитории" });
			this->comboBox->Location = System::Drawing::Point(94, 105);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(178, 24);
			this->comboBox->TabIndex = 2;
			// 
			// buttonExport
			// 
			this->buttonExport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExport->Location = System::Drawing::Point(15, 284);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(257, 31);
			this->buttonExport->TabIndex = 3;
			this->buttonExport->Text = L"Экспорт в .xls";
			this->buttonExport->UseVisualStyleBackColor = true;
			this->buttonExport->Click += gcnew System::EventHandler(this, &ScheduleForm::buttonExport_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(1, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(283, 2);
			this->label5->TabIndex = 39;
			// 
			// labelOutput
			// 
			this->labelOutput->AutoSize = true;
			this->labelOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelOutput->Location = System::Drawing::Point(12, 70);
			this->labelOutput->Name = L"labelOutput";
			this->labelOutput->Size = System::Drawing::Size(145, 17);
			this->labelOutput->TabIndex = 40;
			this->labelOutput->Text = L"Параметры таблицы";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 184);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 17);
			this->label2->TabIndex = 44;
			this->label2->Text = L"Конец:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 17);
			this->label3->TabIndex = 43;
			this->label3->Text = L"Начало:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker2->Location = System::Drawing::Point(94, 184);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(178, 23);
			this->dateTimePicker2->TabIndex = 42;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(94, 144);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(178, 23);
			this->dateTimePicker1->TabIndex = 41;
			// 
			// checkBoxWeek
			// 
			this->checkBoxWeek->AutoSize = true;
			this->checkBoxWeek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxWeek->Location = System::Drawing::Point(15, 226);
			this->checkBoxWeek->Name = L"checkBoxWeek";
			this->checkBoxWeek->Size = System::Drawing::Size(234, 21);
			this->checkBoxWeek->TabIndex = 45;
			this->checkBoxWeek->Text = L"Сгруппировать по дням недели";
			this->checkBoxWeek->UseVisualStyleBackColor = true;
			// 
			// ScheduleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 327);
			this->Controls->Add(this->checkBoxWeek);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->labelOutput);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonGenerate);
			this->Name = L"ScheduleForm";
			this->Text = L"ScheduleForm";
			this->Load += gcnew System::EventHandler(this, &ScheduleForm::ScheduleForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ScheduleForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void buttonGenerate_Click(System::Object^  sender, System::EventArgs^  e) {


	Schedule.InitRules();
	

	Schedule.Generate();



	
}
private: System::Void buttonExport_Click(System::Object^  sender, System::EventArgs^  e) {



}
};
}
