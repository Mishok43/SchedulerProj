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
	private: System::Windows::Forms::Button^  buttonPause;
	protected:

	private: System::Windows::Forms::Label^  labelData;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonEnd;
	private: System::Windows::Forms::Label^  label2;



	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::Button^  buttonExport;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
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
			this->buttonPause = (gcnew System::Windows::Forms::Button());
			this->labelData = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonEnd = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->checkBoxWeek = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonPause
			// 
			this->buttonPause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPause->Location = System::Drawing::Point(311, 12);
			this->buttonPause->Name = L"buttonPause";
			this->buttonPause->Size = System::Drawing::Size(97, 32);
			this->buttonPause->TabIndex = 0;
			this->buttonPause->Text = L"Пауза";
			this->buttonPause->UseVisualStyleBackColor = true;
			this->buttonPause->Click += gcnew System::EventHandler(this, &GenerationForm::buttonPause_Click);
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
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 67);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(396, 177);
			this->dataGridView1->TabIndex = 2;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Окна/ден (студ.)";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column1->Width = 99;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Окна/ден (преп.)";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column2->Width = 99;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Дни/нед (студ.)";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column4->Width = 99;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Дни/нед (преп.)";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column5->Width = 99;
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
			this->buttonEnd->Location = System::Drawing::Point(12, 298);
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
			this->label2->Location = System::Drawing::Point(9, 247);
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
			this->comboBox->Location = System::Drawing::Point(12, 267);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(147, 24);
			this->comboBox->TabIndex = 6;
			// 
			// buttonExport
			// 
			this->buttonExport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExport->Location = System::Drawing::Point(309, 264);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(99, 28);
			this->buttonExport->TabIndex = 7;
			this->buttonExport->Text = L"Экспорт";
			this->buttonExport->UseVisualStyleBackColor = true;
			this->buttonExport->Click += gcnew System::EventHandler(this, &GenerationForm::buttonExport_Click);
			// 
			// checkBoxWeek
			// 
			this->checkBoxWeek->AutoSize = true;
			this->checkBoxWeek->Checked = true;
			this->checkBoxWeek->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxWeek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxWeek->Location = System::Drawing::Point(169, 269);
			this->checkBoxWeek->Name = L"checkBoxWeek";
			this->checkBoxWeek->Size = System::Drawing::Size(134, 21);
			this->checkBoxWeek->TabIndex = 46;
			this->checkBoxWeek->Text = L"По дням недели";
			this->checkBoxWeek->UseVisualStyleBackColor = true;
			// 
			// GenerationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(421, 344);
			this->Controls->Add(this->checkBoxWeek);
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonEnd);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->labelData);
			this->Controls->Add(this->buttonPause);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"GenerationForm";
			this->Text = L"Поиск расписания";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GenerationForm::GenerationForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GenerationForm::GenerationForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonPause_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (Schedule.onPause)
		{
			buttonPause->Text = L"Пауза";
		}
		else
		{
			buttonPause->Text = L"Продолжить";
		}
		
		Schedule.onPause = !Schedule.onPause;
	}


	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		//this->labelData->Text = gcnew System::String(("PROCESS:"+to_string(Schedule.process[0])+" "+to_string(Schedule.process[1])+ " " + to_string(Schedule.process[2]) + " " + to_string(Schedule.process[3])+ " " + to_string(Schedule.process[4]) + " " + to_string(Schedule.process[5])+" SOLUTIONS: "+ to_string(Schedule.solutionsFound)).c_str());
		this->labelData->Text = gcnew System::String(("Найдено " + to_string(Schedule.solutionsFound)+" решений").c_str());
	

		vector<array<float, SCHPARAMS>> z = Schedule.getSolutionsParams();
		for (int i = 0; i < z.size(); i++)
		{


			for (int j = 0; j < SCHPARAMS; j++)
				this->dataGridView1->Rows[i]->Cells[j]->Value = gcnew System::String(to_string(z[i][j]).c_str());
			/*cli::array<System::String^>^ a = gcnew cli::array<System::String^>(SCHPARAMS);
			for (int j = 0; j< SCHPARAMS; j++)
				//a[i] = StdToSys(getParam(i));
				a[j] = gcnew System::String(to_string(z[i][j]).c_str());

			this->dataGridView1->Rows->Add(a);*/

		}
	
	}
	private: System::Void GenerationForm_Load(System::Object^  sender, System::EventArgs^  e) {

		System::Windows::Forms::Timer ^ timer = gcnew System::Windows::Forms::Timer();
		timer->Interval = (100); // 10 secs
		timer->Tick += gcnew EventHandler(this,&GenerationForm::timer_Tick);
		timer->Start();

		this->comboBox->SelectedIndex = 0;


		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < MAXSOLUTIONS; i++)
		{
			cli::array<System::String^>^ a = gcnew cli::array<System::String^>(SCHPARAMS);
			for (int j = 0; j < SCHPARAMS; j++)
				a[j] = gcnew System::String(to_string(-1).c_str());

			this->dataGridView1->Rows->Add(a);
		}





		//Schedule.generate(false);

		ThreadHelper^ helper = gcnew ThreadHelper();
		Thread^ thread = gcnew Thread(gcnew ThreadStart(helper, &ThreadHelper::Run));
		
		thread->Start();
	}

	
private: System::Void GenerationForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	
	Schedule.onPause = false;
	Schedule.ending = true;
	while (!Schedule.doneEnding)
	{

	};


}
private: System::Void buttonExport_Click(System::Object^  sender, System::EventArgs^  e) {


	
	if (!this->dataGridView1->CurrentCell)
		return;
	
	int chosenIndex = this->dataGridView1->CurrentCell->RowIndex;

	//if (Schedule.getSolutionsParams()[chosenIndex][2] < 0)
	//	return;
	

	tm from = Rules::Settings.StartDate;

	tm to = Rules::dayToDate(Rules::Settings.Days);
	int k;
	switch (this->comboBox->SelectedIndex)
	{
	case 0: k = 0; break;
	case 1: k = 1; break;
	case 2: k = 3; break;
	}

	SaveFileDialog  ^ dialog = gcnew SaveFileDialog;
	dialog->Filter = "Excel Workbook (*.xls)|*.xls|All files (*.*)|*.*";
	dialog->FilterIndex = 0;
	dialog->RestoreDirectory = true;

	if (dialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		string path = msclr::interop::marshal_as<string>(dialog->FileName);
		Schedule.exportXls(chosenIndex, (RuleData::objtype)k, this->checkBoxWeek->Checked, Rules::dateToDay(from), Rules::dateToDay(to), path.c_str());
	}
	}
};




	
}
