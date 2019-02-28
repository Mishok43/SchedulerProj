#pragma once
#include "GlobalData.h"
#include "TeacherInfoForm.h"
#include "TagTextBox.h"
#include "HelpRules.h"

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
	private: System::Windows::Forms::Button^  buttonHelp;
	protected:
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonRemoveTag;
	private: System::Windows::Forms::Button^  buttonAddTag;
	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::DataGridView^  dataGridView;





	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  buttonExport;
	private: System::Windows::Forms::Button^  buttonImport;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  description;
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
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonRemoveTag = (gcnew System::Windows::Forms::Button());
			this->buttonAddTag = (gcnew System::Windows::Forms::Button());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->areRules = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tags = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->buttonImport = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonHelp
			// 
			this->buttonHelp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonHelp->Location = System::Drawing::Point(175, 237);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(34, 21);
			this->buttonHelp->TabIndex = 35;
			this->buttonHelp->Text = L"\?";
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &TeachersForm::buttonHelp_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(9, 234);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(651, 2);
			this->label5->TabIndex = 34;
			// 
			// textBox
			// 
			this->textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox->Location = System::Drawing::Point(12, 259);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox->Size = System::Drawing::Size(647, 107);
			this->textBox->TabIndex = 33;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 239);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 17);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Ограничения по тегам";
			// 
			// buttonRemoveTag
			// 
			this->buttonRemoveTag->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRemoveTag->Location = System::Drawing::Point(549, 201);
			this->buttonRemoveTag->Name = L"buttonRemoveTag";
			this->buttonRemoveTag->Size = System::Drawing::Size(111, 23);
			this->buttonRemoveTag->TabIndex = 31;
			this->buttonRemoveTag->Text = L"Удалить тег";
			this->buttonRemoveTag->UseVisualStyleBackColor = true;
			this->buttonRemoveTag->Click += gcnew System::EventHandler(this, &TeachersForm::buttonRemoveTag_Click);
			// 
			// buttonAddTag
			// 
			this->buttonAddTag->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAddTag->Location = System::Drawing::Point(433, 201);
			this->buttonAddTag->Name = L"buttonAddTag";
			this->buttonAddTag->Size = System::Drawing::Size(110, 23);
			this->buttonAddTag->TabIndex = 30;
			this->buttonAddTag->Text = L"Добавить тег";
			this->buttonAddTag->UseVisualStyleBackColor = true;
			this->buttonAddTag->Click += gcnew System::EventHandler(this, &TeachersForm::buttonAddTag_Click);
			// 
			// buttonRemove
			// 
			this->buttonRemove->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonRemove->Location = System::Drawing::Point(174, 201);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(75, 23);
			this->buttonRemove->TabIndex = 29;
			this->buttonRemove->Text = L"Удалить";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &TeachersForm::buttonRemove_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonEdit->Location = System::Drawing::Point(93, 201);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 28;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &TeachersForm::buttonEdit_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonAdd->Location = System::Drawing::Point(12, 201);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 27;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &TeachersForm::buttonAdd_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->name, this->description,
					this->areRules, this->tags
			});
			this->dataGridView->Location = System::Drawing::Point(12, 38);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView->Size = System::Drawing::Size(647, 157);
			this->dataGridView->TabIndex = 26;
			// 
			// name
			// 
			this->name->Frozen = true;
			this->name->HeaderText = L"Фамилия Имя Отчество";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->name->Width = 180;
			// 
			// description
			// 
			this->description->Frozen = true;
			this->description->HeaderText = L"Комментарии";
			this->description->Name = L"description";
			this->description->ReadOnly = true;
			this->description->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->description->Width = 120;
			// 
			// areRules
			// 
			this->areRules->Frozen = true;
			this->areRules->HeaderText = L"Огранич.";
			this->areRules->Name = L"areRules";
			this->areRules->ReadOnly = true;
			this->areRules->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->areRules->Width = 60;
			// 
			// tags
			// 
			this->tags->Frozen = true;
			this->tags->HeaderText = L"Теги";
			this->tags->Name = L"tags";
			this->tags->ReadOnly = true;
			this->tags->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tags->Width = 1000;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 25;
			this->textBox1->Text = L"Фильтр...";
			// 
			// buttonExport
			// 
			this->buttonExport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonExport->Location = System::Drawing::Point(566, 9);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(94, 23);
			this->buttonExport->TabIndex = 24;
			this->buttonExport->Text = L"Экспорт";
			this->buttonExport->UseVisualStyleBackColor = true;
			this->buttonExport->Click += gcnew System::EventHandler(this, &TeachersForm::buttonExport_Click);
			// 
			// buttonImport
			// 
			this->buttonImport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonImport->Location = System::Drawing::Point(466, 9);
			this->buttonImport->Name = L"buttonImport";
			this->buttonImport->Size = System::Drawing::Size(94, 23);
			this->buttonImport->TabIndex = 23;
			this->buttonImport->Text = L"Импорт";
			this->buttonImport->UseVisualStyleBackColor = true;
			this->buttonImport->Click += gcnew System::EventHandler(this, &TeachersForm::buttonImport_Click);
			// 
			// TeachersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 378);
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonRemoveTag);
			this->Controls->Add(this->buttonAddTag);
			this->Controls->Add(this->buttonRemove);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->buttonImport);
			this->Name = L"TeachersForm";
			this->Text = L"Преподаватели";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TeachersForm::TeachersForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &TeachersForm::TeachersForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	System::Void buttonImport_Click(System::Object^  sender, System::EventArgs^  e) {

		MainData.Teachers.setVal(Teacher::ExcelToTeachers("../TestData/professors.xls"));

		this->updateGrid();
	}
	System::Void buttonExport_Click(System::Object^  sender, System::EventArgs^  e) {
		Teacher::TeachersToExcel(MainData.Teachers.getVal(), "../TestData/professors.xls");
	}


	System::Void updateGrid()
	{
		this->dataGridView->Rows->Clear();

		MainData.TeachersFormList = MainData.Teachers.getVal();

		for (auto c = MainData.TeachersFormList.begin(); c != MainData.TeachersFormList.end(); ++c)
			this->dataGridView->Rows->Add((*c)->getParamRow());
	}

	System::Void TeachersForm_Load(System::Object^  sender, System::EventArgs^  e) {
		updateGrid();

		this->textBox->Text = "";
		vector<string> txt = MainData.TeacherTagRules.getText();
		for (int i = 0; i < txt.size(); i++)
			this->textBox->Text += gcnew System::String(txt[i].c_str()) + "\r\n";

	}
	System::Void buttonEdit_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataGridView->CurrentRow)
		{
			MainData.EditingTeacher = MainData.TeachersFormList[this->dataGridView->CurrentRow->Index];
			if (MainData.EditingTeacher != nullptr)
			{
				TeacherInfoForm ^ form = gcnew TeacherInfoForm;
				form->ShowDialog();

				this->updateGrid();
			}
		}



	}
	System::Void buttonRemove_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataGridView->CurrentRow)
		{
			int pos = this->dataGridView->CurrentRow->Index;
			Teacher* obj = MainData.TeachersFormList[pos];

			MainData.Teachers.erase(obj);
			MainData.TeachersFormList.erase(MainData.TeachersFormList.begin() + pos);
			this->dataGridView->Rows->RemoveAt(pos);


		}
	}
	System::Void buttonAddTag_Click(System::Object^  sender, System::EventArgs^  e) {

		int n = this->dataGridView->Rows->GetRowCount(DataGridViewElementStates::Selected);

		if (n > 0)
		{
			TagTextBox ^ box = gcnew TagTextBox;
			box->ShowDialog();

			if (!MainData.messageBoxInput.empty())
			{
				for (int i = 0; i < n; i++)
					MainData.TeachersFormList[this->dataGridView->SelectedRows[i]->Index]->addTag(MainData.messageBoxInput);

				this->updateGrid();
			}
		}
	}

	System::Void buttonRemoveTag_Click(System::Object^  sender, System::EventArgs^  e) {
		int n = this->dataGridView->Rows->GetRowCount(DataGridViewElementStates::Selected);

		if (n > 0)
		{
			TagTextBox ^ box = gcnew TagTextBox;
			box->ShowDialog();

			if (!MainData.messageBoxInput.empty())
			{
				for (int i = 0; i < n; i++)
					MainData.TeachersFormList[this->dataGridView->SelectedRows[i]->Index]->removeTag(MainData.messageBoxInput);

				this->updateGrid();
			}
		}
	}
	System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {

		MainData.EditingTeacher = new Teacher();

		MainData.TeachersFormList.push_back(MainData.EditingTeacher);
		MainData.Teachers.add(MainData.EditingTeacher);

		TeacherInfoForm ^ form = gcnew TeacherInfoForm;
		form->ShowDialog();


		this->updateGrid();
	}
	System::Void buttonHelp_Click(System::Object^  sender, System::EventArgs^  e) {
		HelpRules ^ form = gcnew HelpRules;
		form->ShowDialog();
	}
	System::Void TeachersForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		vector<string> v;

		cli::array<String^>^ lines = this->textBox->Text->Split(gcnew cli::array<String^> {"\n", "\r", "\r\n" }, StringSplitOptions::None);


		for (int i = 0; i < lines->Length; i++)
			v.push_back(msclr::interop::marshal_as<std::string>(lines->GetValue(i)->ToString()));

		MainData.TeacherTagRules.setText(v);
	}
};
}
