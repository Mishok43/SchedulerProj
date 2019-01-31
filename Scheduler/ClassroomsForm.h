#pragma once

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ClassroomsForm
	/// </summary>
	public ref class ClassroomsForm : public System::Windows::Forms::Form
	{
	public:
		ClassroomsForm(void)
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
		~ClassroomsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView;
	protected:




	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  buttonExport;
	private: System::Windows::Forms::Button^  buttonImport;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  buttonAddTag;
	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  groupName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  groupSize;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  groupAreRules;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  groupTags;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->buttonImport = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonAddTag = (gcnew System::Windows::Forms::Button());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupSize = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupAreRules = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupTags = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->groupName,
					this->groupSize, this->groupAreRules, this->groupTags
			});
			this->dataGridView->Location = System::Drawing::Point(12, 38);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->Size = System::Drawing::Size(647, 157);
			this->dataGridView->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Фильтр...";
			// 
			// buttonExport
			// 
			this->buttonExport->Location = System::Drawing::Point(566, 9);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(94, 23);
			this->buttonExport->TabIndex = 5;
			this->buttonExport->Text = L"Экспорт";
			this->buttonExport->UseVisualStyleBackColor = true;
			// 
			// buttonImport
			// 
			this->buttonImport->Location = System::Drawing::Point(466, 9);
			this->buttonImport->Name = L"buttonImport";
			this->buttonImport->Size = System::Drawing::Size(94, 23);
			this->buttonImport->TabIndex = 4;
			this->buttonImport->Text = L"Импорт";
			this->buttonImport->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(549, 201);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 23);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Удалить тег";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// buttonAddTag
			// 
			this->buttonAddTag->Location = System::Drawing::Point(433, 201);
			this->buttonAddTag->Name = L"buttonAddTag";
			this->buttonAddTag->Size = System::Drawing::Size(110, 23);
			this->buttonAddTag->TabIndex = 12;
			this->buttonAddTag->Text = L"Добавить тег";
			this->buttonAddTag->UseVisualStyleBackColor = true;
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(174, 201);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(75, 23);
			this->buttonRemove->TabIndex = 11;
			this->buttonRemove->Text = L"Удалить";
			this->buttonRemove->UseVisualStyleBackColor = true;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Location = System::Drawing::Point(93, 201);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 10;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(12, 201);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 9;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(9, 234);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(651, 2);
			this->label5->TabIndex = 21;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(353, 292);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(307, 74);
			this->textBox3->TabIndex = 20;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 292);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(307, 74);
			this->textBox2->TabIndex = 19;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(350, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 17);
			this->label3->TabIndex = 18;
			this->label3->Text = L"ОБЯЗАТЕЛЬНО";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 265);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 17);
			this->label2->TabIndex = 17;
			this->label2->Text = L"ИСКЛЮЧЕНО";
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
			// groupName
			// 
			this->groupName->Frozen = true;
			this->groupName->HeaderText = L"Идентификатор";
			this->groupName->Name = L"groupName";
			this->groupName->ReadOnly = true;
			// 
			// groupSize
			// 
			this->groupSize->Frozen = true;
			this->groupSize->HeaderText = L"Вместимость";
			this->groupSize->Name = L"groupSize";
			this->groupSize->ReadOnly = true;
			// 
			// groupAreRules
			// 
			this->groupAreRules->Frozen = true;
			this->groupAreRules->HeaderText = L"Огранич.";
			this->groupAreRules->Name = L"groupAreRules";
			this->groupAreRules->ReadOnly = true;
			this->groupAreRules->Width = 60;
			// 
			// groupTags
			// 
			this->groupTags->Frozen = true;
			this->groupTags->HeaderText = L"Теги";
			this->groupTags->Name = L"groupTags";
			this->groupTags->ReadOnly = true;
			this->groupTags->Width = 500;
			// 
			// ClassroomsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 378);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->buttonAddTag);
			this->Controls->Add(this->buttonRemove);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->buttonImport);
			this->Name = L"ClassroomsForm";
			this->Text = L"Аудитории";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
