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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  secondName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  patronymicName;
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
			this->areRules = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tags = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->secondName,
					this->firstName, this->patronymicName, this->areRules, this->tags
			});
			this->dataGridView->Location = System::Drawing::Point(16, 37);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(543, 150);
			this->dataGridView->TabIndex = 0;
			// 
			// secondName
			// 
			this->secondName->Frozen = true;
			this->secondName->HeaderText = L"Фамилия";
			this->secondName->Name = L"secondName";
			this->secondName->ReadOnly = true;
			// 
			// firstName
			// 
			this->firstName->Frozen = true;
			this->firstName->HeaderText = L"Имя";
			this->firstName->Name = L"firstName";
			this->firstName->ReadOnly = true;
			// 
			// patronymicName
			// 
			this->patronymicName->Frozen = true;
			this->patronymicName->HeaderText = L"Отчество";
			this->patronymicName->Name = L"patronymicName";
			this->patronymicName->ReadOnly = true;
			// 
			// areRules
			// 
			this->areRules->HeaderText = L"Огранич.";
			this->areRules->Name = L"areRules";
			this->areRules->ReadOnly = true;
			// 
			// tags
			// 
			this->tags->HeaderText = L"Теги";
			this->tags->Name = L"tags";
			this->tags->ReadOnly = true;
			// 
			// StudentsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 261);
			this->Controls->Add(this->dataGridView);
			this->Name = L"StudentsForm";
			this->Text = L"StudentsForm";
			this->Load += gcnew System::EventHandler(this, &StudentsForm::StudentsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void StudentsForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
		//dataGridView->Rows->Add()
	}
	};
}
