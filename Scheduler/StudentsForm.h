#pragma once

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для StudentsForm
	/// </summary>
	public ref class StudentsForm : public System::Windows::Forms::Form
	{
	public:
		StudentsForm(void)
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
		~StudentsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView;





	private: System::Windows::Forms::Button^  buttonImport;
	private: System::Windows::Forms::Button^  buttonExport;
	private: System::Windows::Forms::TextBox^  textBoxSearch;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  secondName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  patronymicName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  group;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  areRules;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tags;










	protected:

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
			this->buttonImport = (gcnew System::Windows::Forms::Button());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->secondName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->patronymicName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->areRules = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tags = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->secondName,
					this->firstName, this->patronymicName, this->group, this->areRules, this->tags
			});
			this->dataGridView->Location = System::Drawing::Point(16, 37);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowTemplate->ReadOnly = true;
			this->dataGridView->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView->Size = System::Drawing::Size(699, 257);
			this->dataGridView->TabIndex = 0;
			// 
			// buttonImport
			// 
			this->buttonImport->Location = System::Drawing::Point(536, 8);
			this->buttonImport->Name = L"buttonImport";
			this->buttonImport->Size = System::Drawing::Size(82, 23);
			this->buttonImport->TabIndex = 1;
			this->buttonImport->Text = L"Импорт";
			this->buttonImport->UseVisualStyleBackColor = true;
			this->buttonImport->Click += gcnew System::EventHandler(this, &StudentsForm::buttonImport_Click);
			// 
			// buttonExport
			// 
			this->buttonExport->Location = System::Drawing::Point(624, 8);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(75, 23);
			this->buttonExport->TabIndex = 2;
			this->buttonExport->Text = L"Экспорт";
			this->buttonExport->UseVisualStyleBackColor = true;
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSearch->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBoxSearch->Location = System::Drawing::Point(25, 10);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(179, 20);
			this->textBoxSearch->TabIndex = 3;
			this->textBoxSearch->Text = L"Фильтр...";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(97, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Изменить";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(178, 300);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(495, 300);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(106, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Добавить тег";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(607, 300);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(106, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Убрать тег";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// secondName
			// 
			this->secondName->Frozen = true;
			this->secondName->HeaderText = L"Фамилия";
			this->secondName->Name = L"secondName";
			this->secondName->ReadOnly = true;
			this->secondName->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// firstName
			// 
			this->firstName->Frozen = true;
			this->firstName->HeaderText = L"Имя";
			this->firstName->Name = L"firstName";
			this->firstName->ReadOnly = true;
			this->firstName->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// patronymicName
			// 
			this->patronymicName->Frozen = true;
			this->patronymicName->HeaderText = L"Отчество";
			this->patronymicName->Name = L"patronymicName";
			this->patronymicName->ReadOnly = true;
			this->patronymicName->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// group
			// 
			this->group->HeaderText = L"Группы";
			this->group->Name = L"group";
			// 
			// areRules
			// 
			this->areRules->HeaderText = L"Огранич.";
			this->areRules->Name = L"areRules";
			this->areRules->ReadOnly = true;
			this->areRules->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->areRules->Width = 80;
			// 
			// tags
			// 
			this->tags->HeaderText = L"Теги";
			this->tags->Name = L"tags";
			this->tags->ReadOnly = true;
			this->tags->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->tags->Width = 400;
			// 
			// StudentsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 328);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->buttonImport);
			this->Controls->Add(this->dataGridView);
			this->Name = L"StudentsForm";
			this->Text = L"Студенты";
			this->Load += gcnew System::EventHandler(this, &StudentsForm::StudentsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void StudentsForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
		//dataGridView->Rows->Add()
	}
	private: System::Void buttonImport_Click(System::Object^  sender, System::EventArgs^  e) {
	
		// Считываем данные 
	
	}
};
}
