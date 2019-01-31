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







	private: System::Windows::Forms::TextBox^  textBoxSearch;





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
			this->secondName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->patronymicName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->areRules = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tags = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
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
			// StudentsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 328);
			this->Controls->Add(this->textBoxSearch);
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
