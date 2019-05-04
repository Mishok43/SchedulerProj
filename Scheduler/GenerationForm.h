#pragma once
#include "GeneratedSchedule.h"
//#include <thread>

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	


	


	/// <summary>
	/// Сводка для GenerationForm
	/// </summary>
	public ref class GenerationForm : public System::Windows::Forms::Form
	{
	public:
		GenerationForm(void)
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
		~GenerationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  labelData;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonEnd;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::Button^  buttonExport;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labelData = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonEnd = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(311, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Пауза";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GenerationForm::button1_Click);
			// 
			// labelData
			// 
			this->labelData->AutoSize = true;
			this->labelData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelData->Location = System::Drawing::Point(9, 20);
			this->labelData->Name = L"labelData";
			this->labelData->Size = System::Drawing::Size(293, 17);
			this->labelData->TabIndex = 1;
			this->labelData->Text = L"Найдено 18446744073709551615 решений";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 67);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(396, 152);
			this->dataGridView1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Оптимальные решения:";
			// 
			// buttonEnd
			// 
			this->buttonEnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEnd->Location = System::Drawing::Point(12, 277);
			this->buttonEnd->Name = L"buttonEnd";
			this->buttonEnd->Size = System::Drawing::Size(397, 38);
			this->buttonEnd->TabIndex = 4;
			this->buttonEnd->Text = L"Выбрать решение";
			this->buttonEnd->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(9, 222);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Предпросмотр:";
			// 
			// comboBox
			// 
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Группы", L"Преподаватели", L"Аудитории" });
			this->comboBox->Location = System::Drawing::Point(12, 242);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(138, 24);
			this->comboBox->TabIndex = 6;
			// 
			// buttonExport
			// 
			this->buttonExport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExport->Location = System::Drawing::Point(156, 225);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(99, 41);
			this->buttonExport->TabIndex = 7;
			this->buttonExport->Text = L"Экспорт";
			this->buttonExport->UseVisualStyleBackColor = true;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Окна (студенты)";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 135;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Окна (препод.)";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 130;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Загруж. аудиторий";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 130;
			// 
			// GenerationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(421, 327);
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonEnd);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->labelData);
			this->Controls->Add(this->button1);
			this->Name = L"GenerationForm";
			this->Text = L"Поиск расписания";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GenerationForm::GenerationForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GenerationForm::GenerationForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
	}


	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		//this->labelData->Text = gcnew System::String(("PROCESS:"+to_string(Schedule.process[0])+" "+to_string(Schedule.process[1])+ " " + to_string(Schedule.process[2]) + " " + to_string(Schedule.process[3])+ " " + to_string(Schedule.process[4])+" SOLUTIONS: "+ to_string(Schedule.solutionsFound)).c_str());
		this->labelData->Text = gcnew System::String(("Found " + to_string(Schedule.solutionsFound)+" solutions").c_str());
	}
	private: System::Void GenerationForm_Load(System::Object^  sender, System::EventArgs^  e) {

		System::Windows::Forms::Timer ^ timer = gcnew System::Windows::Forms::Timer();
		timer->Interval = (100); // 10 secs
		timer->Tick += gcnew EventHandler(this,&GenerationForm::timer_Tick);
		timer->Start();





		//Schedule.generate(false);

		MessagePrinter^ printer1 = gcnew MessagePrinter();
		Thread^ thread1 = gcnew Thread(gcnew ThreadStart(printer1, &MessagePrinter::Print));
		//thread1->Name = "thread1";

		thread1->Start();
	}

	
private: System::Void GenerationForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	
	Schedule.onPause = false;
	Schedule.ending = true;
	while (!Schedule.doneEnding)
	{

	};


}
};




	
}
