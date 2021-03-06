#pragma once
#include "GlobalData.h"
#include "GroupInfoForm.h"
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
	/// ������ ��� GroupsForm
	/// </summary>
	public ref class GroupsForm : public System::Windows::Forms::Form
	{
	public:
		GroupsForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~GroupsForm()
		{
			if (components)
			{
				delete components;
			}
		}














	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  buttonHelp;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonRemoveTag;
	private: System::Windows::Forms::Button^  buttonAddTag;
	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::DataGridView^  dataGridView;






	private: System::Windows::Forms::Button^  buttonExport;
	private: System::Windows::Forms::Button^  buttonImport;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  size;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  description;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  areRules;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tags;





	protected:

	protected:


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->size = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->areRules = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tags = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonExport = (gcnew System::Windows::Forms::Button());
			this->buttonImport = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(331, 591);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"label4";
			// 
			// buttonHelp
			// 
			this->buttonHelp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonHelp->Location = System::Drawing::Point(324, 237);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(34, 21);
			this->buttonHelp->TabIndex = 35;
			this->buttonHelp->Text = L"\?";
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &GroupsForm::buttonHelp_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(9, 234);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(763, 2);
			this->label5->TabIndex = 34;
			// 
			// textBox
			// 
			this->textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(12, 259);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox->Size = System::Drawing::Size(759, 107);
			this->textBox->TabIndex = 33;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &GroupsForm::textBox_TextChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 239);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(310, 17);
			this->label1->TabIndex = 32;
			this->label1->Text = L"����������� ����� � ��������� �����������";
			// 
			// buttonRemoveTag
			// 
			this->buttonRemoveTag->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRemoveTag->Location = System::Drawing::Point(661, 201);
			this->buttonRemoveTag->Name = L"buttonRemoveTag";
			this->buttonRemoveTag->Size = System::Drawing::Size(111, 23);
			this->buttonRemoveTag->TabIndex = 31;
			this->buttonRemoveTag->Text = L"������� ���";
			this->buttonRemoveTag->UseVisualStyleBackColor = true;
			this->buttonRemoveTag->Click += gcnew System::EventHandler(this, &GroupsForm::buttonRemoveTag_Click);
			// 
			// buttonAddTag
			// 
			this->buttonAddTag->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAddTag->Location = System::Drawing::Point(545, 201);
			this->buttonAddTag->Name = L"buttonAddTag";
			this->buttonAddTag->Size = System::Drawing::Size(110, 23);
			this->buttonAddTag->TabIndex = 30;
			this->buttonAddTag->Text = L"�������� ���";
			this->buttonAddTag->UseVisualStyleBackColor = true;
			this->buttonAddTag->Click += gcnew System::EventHandler(this, &GroupsForm::buttonAddTag_Click);
			// 
			// buttonRemove
			// 
			this->buttonRemove->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonRemove->Location = System::Drawing::Point(174, 201);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(75, 23);
			this->buttonRemove->TabIndex = 29;
			this->buttonRemove->Text = L"�������";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &GroupsForm::buttonRemove_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonEdit->Location = System::Drawing::Point(93, 201);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 28;
			this->buttonEdit->Text = L"��������";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &GroupsForm::buttonEdit_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonAdd->Location = System::Drawing::Point(12, 201);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 27;
			this->buttonAdd->Text = L"��������";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &GroupsForm::buttonAdd_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->name, this->size,
					this->description, this->areRules, this->tags
			});
			this->dataGridView->Location = System::Drawing::Point(12, 38);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView->Size = System::Drawing::Size(759, 157);
			this->dataGridView->TabIndex = 26;
			// 
			// name
			// 
			this->name->Frozen = true;
			this->name->HeaderText = L"�������������";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->name->Width = 90;
			// 
			// size
			// 
			this->size->Frozen = true;
			this->size->HeaderText = L"������";
			this->size->Name = L"size";
			this->size->ReadOnly = true;
			this->size->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->size->Width = 60;
			// 
			// description
			// 
			this->description->Frozen = true;
			this->description->HeaderText = L"�����������";
			this->description->Name = L"description";
			this->description->ReadOnly = true;
			this->description->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// areRules
			// 
			this->areRules->Frozen = true;
			this->areRules->HeaderText = L"�������.";
			this->areRules->Name = L"areRules";
			this->areRules->ReadOnly = true;
			this->areRules->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->areRules->Width = 60;
			// 
			// tags
			// 
			this->tags->Frozen = true;
			this->tags->HeaderText = L"����";
			this->tags->Name = L"tags";
			this->tags->ReadOnly = true;
			this->tags->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tags->Width = 1000;
			// 
			// buttonExport
			// 
			this->buttonExport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonExport->Location = System::Drawing::Point(678, 9);
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(94, 23);
			this->buttonExport->TabIndex = 24;
			this->buttonExport->Text = L"�������";
			this->buttonExport->UseVisualStyleBackColor = true;
			this->buttonExport->Click += gcnew System::EventHandler(this, &GroupsForm::buttonExport_Click);
			// 
			// buttonImport
			// 
			this->buttonImport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonImport->Location = System::Drawing::Point(578, 9);
			this->buttonImport->Name = L"buttonImport";
			this->buttonImport->Size = System::Drawing::Size(94, 23);
			this->buttonImport->TabIndex = 23;
			this->buttonImport->Text = L"������";
			this->buttonImport->UseVisualStyleBackColor = true;
			this->buttonImport->Click += gcnew System::EventHandler(this, &GroupsForm::buttonImport_Click);
			// 
			// GroupsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 378);
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
			this->Controls->Add(this->buttonExport);
			this->Controls->Add(this->buttonImport);
			this->Controls->Add(this->label4);
			this->Name = L"GroupsForm";
			this->Text = L"������";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GroupsForm::GroupsForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GroupsForm::GroupsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void buttonImport_Click(System::Object^  sender, System::EventArgs^  e) {

			OpenFileDialog  ^ dialog = gcnew OpenFileDialog;
			dialog->Filter = "Excel Workbook (*.xls)|*.xls|All files (*.*)|*.*";
			dialog->FilterIndex = 0;
			dialog->RestoreDirectory = true;

			if (dialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				string path = msclr::interop::marshal_as<string>(dialog->FileName);

				MainData.Groups.setVal(Group::ExcelToGroups(path.c_str()));

				this->updateGrid();


				MainData.Activities.clear();
			}
		}
		System::Void buttonExport_Click(System::Object^  sender, System::EventArgs^  e) {

			SaveFileDialog  ^ dialog = gcnew SaveFileDialog;
			dialog->Filter = "Excel Workbook (*.xls)|*.xls|All files (*.*)|*.*";
			dialog->FilterIndex = 0;
			dialog->RestoreDirectory = true;

			if (dialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				string path = msclr::interop::marshal_as<string>(dialog->FileName);
				Group::GroupsToExcel(MainData.Groups.getVal(), path.c_str());
			}
		}


		System::Void updateGrid()
		{
			this->dataGridView->Rows->Clear();

			MainData.GroupsFormList = MainData.Groups.getVal();

			for (auto c = MainData.GroupsFormList.begin(); c != MainData.GroupsFormList.end(); ++c)
				this->dataGridView->Rows->Add((*c)->getParamRow());
		}

		System::Void GroupsForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->textBox->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
			this->buttonRemove->Enabled = GlobalData::Access == GlobalData::MANAGER;
			this->buttonAdd->Enabled = GlobalData::Access == GlobalData::MANAGER;
			this->buttonAddTag->Enabled = GlobalData::Access == GlobalData::MANAGER;
			this->buttonRemoveTag->Enabled = GlobalData::Access == GlobalData::MANAGER;
			this->buttonImport->Enabled = GlobalData::Access == GlobalData::MANAGER;
			if (GlobalData::Access == GlobalData::TEACHER)
				this->buttonEdit->Text = "�������";


			updateGrid();

			this->textBox->Text = "";
			vector<string> txt = MainData.GroupTagRules.getText();
			for (int i = 0; i < txt.size(); i++)
				this->textBox->Text += gcnew System::String(txt[i].c_str()) + "\r\n";

		}
		System::Void buttonEdit_Click(System::Object^  sender, System::EventArgs^  e) {
			trySave();
			if (this->dataGridView->CurrentRow)
			{
				MainData.EditingGroup = MainData.GroupsFormList[this->dataGridView->CurrentRow->Index];
				if (MainData.EditingGroup != nullptr)
				{
					GroupInfoForm ^ form = gcnew GroupInfoForm;
					form->ShowDialog();

					this->updateGrid();
				}
				Schedule.reset();
			}



		}
		System::Void buttonRemove_Click(System::Object^  sender, System::EventArgs^  e) {
			if (this->dataGridView->CurrentRow)
			{
				int pos = this->dataGridView->CurrentRow->Index;
				Group* obj = MainData.GroupsFormList[pos];

				MainData.Groups.erase(obj);
				MainData.GroupsFormList.erase(MainData.GroupsFormList.begin() + pos);
				this->dataGridView->Rows->RemoveAt(pos);

				Schedule.reset();
			}
		}
		System::Void buttonAddTag_Click(System::Object^  sender, System::EventArgs^  e) {

			int n = this->dataGridView->Rows->GetRowCount(DataGridViewElementStates::Selected);

			if (n > 0)
			{
				TagTextBox ^ box = gcnew TagTextBox;
				box->ShowDialog();

				if (!GlobalData::MessageBoxInput.empty())
				{
					for (int i = 0; i < n; i++)
						MainData.GroupsFormList[this->dataGridView->SelectedRows[i]->Index]->addTag(GlobalData::MessageBoxInput);

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

				if (!GlobalData::MessageBoxInput.empty())
				{
					for (int i = 0; i < n; i++)
						MainData.GroupsFormList[this->dataGridView->SelectedRows[i]->Index]->removeTag(GlobalData::MessageBoxInput);

					this->updateGrid();
				}
			}
		}
		System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {

			MainData.EditingGroup = new Group();

			MainData.GroupsFormList.push_back(MainData.EditingGroup);
			MainData.Groups.add(MainData.EditingGroup);

			GroupInfoForm ^ form = gcnew GroupInfoForm;
			form->ShowDialog();


			this->updateGrid();
			Schedule.reset();
		}
		System::Void buttonHelp_Click(System::Object^  sender, System::EventArgs^  e) {
			HelpRules ^ form = gcnew HelpRules;
			form->ShowDialog();
		}
		System::Void GroupsForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			
			trySave();
		}


		System::Void trySave()
		{
			vector<string> v;

			cli::array<String^>^ lines = this->textBox->Text->Split(gcnew cli::array<String^> {"\n", "\r", "\r\n" }, StringSplitOptions::None);


			for (int i = 0; i < lines->Length; i++)
				v.push_back(msclr::interop::marshal_as<std::string>(lines->GetValue(i)->ToString()));

			MainData.GroupTagRules.setText(v);
		}
private: System::Void textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//Schedule.reset();
}
};
}
