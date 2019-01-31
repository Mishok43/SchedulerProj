#pragma once

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TeachersForm
	/// </summary>
	public ref class TeachersForm : public System::Windows::Forms::Form
	{
	public:
		TeachersForm(void)
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
		~TeachersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  buttonExport;
	private: System::Windows::Forms::Button^  buttonImport;
	private: System::Windows::Forms::DataGridView^  dataGridView;



	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  buttonAddTag;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::TextBox^  textBox2;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  areRules;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tags;




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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->buttonImport = (gcnew System::Windows::Forms::Button());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->areRules = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tags = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonAddTag = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Фильтр...";
			// 
			// buttonExport
			// 
			this->buttonExport->Location = System::Drawing::Point(566, 12);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(94, 23);
			this->buttonExport->TabIndex = 5;
			this->buttonExport->Text = L"Экспорт";
			this->buttonExport->UseVisualStyleBackColor = true;
			// 
			// buttonImport
			// 
			this->buttonImport->Location = System::Drawing::Point(466, 12);
			this->buttonImport->Name = L"buttonImport";
			this->buttonImport->Size = System::Drawing::Size(94, 23);
			this->buttonImport->TabIndex = 4;
			this->buttonImport->Text = L"Импорт";
			this->buttonImport->UseVisualStyleBackColor = true;
			this->buttonImport->Click += gcnew System::EventHandler(this, &TeachersForm::buttonImport_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->name, this->areRules,
					this->tags
			});
			this->dataGridView->Location = System::Drawing::Point(12, 41);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->Size = System::Drawing::Size(647, 157);
			this->dataGridView->TabIndex = 6;
			// 
			// name
			// 
			this->name->Frozen = true;
			this->name->HeaderText = L"ФИО";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Width = 200;
			// 
			// areRules
			// 
			this->areRules->Frozen = true;
			this->areRules->HeaderText = L"Огранич.";
			this->areRules->Name = L"areRules";
			this->areRules->ReadOnly = true;
			this->areRules->Width = 60;
			// 
			// tags
			// 
			this->tags->Frozen = true;
			this->tags->HeaderText = L"Теги";
			this->tags->Name = L"tags";
			this->tags->ReadOnly = true;
			this->tags->Width = 500;
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(174, 204);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(75, 23);
			this->buttonRemove->TabIndex = 9;
			this->buttonRemove->Text = L"Удалить";
			this->buttonRemove->UseVisualStyleBackColor = true;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Location = System::Drawing::Point(93, 204);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 8;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(12, 204);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 7;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(549, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Удалить тег";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// buttonAddTag
			// 
			this->buttonAddTag->Location = System::Drawing::Point(433, 204);
			this->buttonAddTag->Name = L"buttonAddTag";
			this->buttonAddTag->Size = System::Drawing::Size(110, 23);
			this->buttonAddTag->TabIndex = 10;
			this->buttonAddTag->Text = L"Добавить тег";
			this->buttonAddTag->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(9, 234);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(651, 2);
			this->label5->TabIndex = 21;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(15, 259);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(635, 107);
			this->textBox2->TabIndex = 19;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 239);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 17);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Ограничения по тегам";
			// 
			// TeachersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 378);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->buttonAddTag);
			this->Controls->Add(this->buttonRemove);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->buttonImport);
			this->Controls->Add(this->textBox1);
			this->Name = L"TeachersForm";
			this->Text = L"Преподаватели";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonImport_Click(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridView->Rows->Add("Гринкруг Е.М.", "+", "только_будни");
		this->dataGridView->Rows->Add("Фомин С.С.", " ", "только_будни; не_утро");
		this->dataGridView->Rows->Add("Харламов А.А.", " ", "не_утро");
		this->dataGridView->Rows->Add("Звездина Н.В.", " ", "");
		this->dataGridView->Rows->Add("Авдошин С.М.", " ", "");
		this->dataGridView->Rows->Add("Ульянов М.В.", " ", "не_утро");
		this->dataGridView->Rows->Add("Приползина Н.В.", " ", "");

		this->textBox2->Text = "не_утро: НЕ ВРЕМЯ(9:00-12:00)\r\nтолько_будни: ДЕНЬНЕДЕЛИ(ПОНЕДЕЛЬНИК-ПЯТНИЦА)\r\nтолько_выходные: ДЕНЬНЕДЕЛИ(СУББОТА,ВОСКРЕСЕНЬЕ)";

	}
};
}
