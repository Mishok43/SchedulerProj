#pragma once
#include "GlobalData.h"
#include "HelpRules.h"
#include "GeneratedSchedule.h"


namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ActivityInfoForm
	/// </summary>
	public ref class ActivityInfoForm : public System::Windows::Forms::Form
	{
	public:
		ActivityInfoForm(void)
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
		~ActivityInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonDebug;
	protected:
	private: System::Windows::Forms::Button^  buttonHelp;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxTags;
	private: System::Windows::Forms::TextBox^  textBoxDescription;


	private: System::Windows::Forms::TextBox^  textBoxName;
	private: System::Windows::Forms::Label^  labelTags;
	private: System::Windows::Forms::Label^  labelDescription;
	private: System::Windows::Forms::Label^  labelTeacher;

	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::TextBox^  textBoxGroups;

	private: System::Windows::Forms::Label^  labelGroups;
	private: System::Windows::Forms::TextBox^  textBoxHours;


	private: System::Windows::Forms::Label^  labelHours;
	private: System::Windows::Forms::ComboBox^  comboBoxTeacher;
	private: System::Windows::Forms::Button^  buttonArrow;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;




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
			this->buttonDebug = (gcnew System::Windows::Forms::Button());
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxTags = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDescription = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelTags = (gcnew System::Windows::Forms::Label());
			this->labelDescription = (gcnew System::Windows::Forms::Label());
			this->labelTeacher = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->textBoxGroups = (gcnew System::Windows::Forms::TextBox());
			this->labelGroups = (gcnew System::Windows::Forms::Label());
			this->textBoxHours = (gcnew System::Windows::Forms::TextBox());
			this->labelHours = (gcnew System::Windows::Forms::Label());
			this->comboBoxTeacher = (gcnew System::Windows::Forms::ComboBox());
			this->buttonArrow = (gcnew System::Windows::Forms::Button());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// buttonDebug
			// 
			this->buttonDebug->Location = System::Drawing::Point(267, 233);
			this->buttonDebug->Name = L"buttonDebug";
			this->buttonDebug->Size = System::Drawing::Size(81, 21);
			this->buttonDebug->TabIndex = 55;
			this->buttonDebug->Text = L"DEBUG INFO";
			this->buttonDebug->UseVisualStyleBackColor = true;
			this->buttonDebug->Click += gcnew System::EventHandler(this, &ActivityInfoForm::buttonDebug_Click);
			// 
			// buttonHelp
			// 
			this->buttonHelp->Location = System::Drawing::Point(227, 233);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(34, 21);
			this->buttonHelp->TabIndex = 54;
			this->buttonHelp->Text = L"\?";
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &ActivityInfoForm::buttonHelp_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(12, 230);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(651, 2);
			this->label5->TabIndex = 53;
			// 
			// textBox
			// 
			this->textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(18, 255);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(635, 107);
			this->textBox->TabIndex = 52;
			this->textBox->WordWrap = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(15, 235);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 17);
			this->label6->TabIndex = 51;
			this->label6->Text = L"Индивидуальные ограничения";
			// 
			// textBoxTags
			// 
			this->textBoxTags->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxTags->Location = System::Drawing::Point(138, 189);
			this->textBoxTags->Name = L"textBoxTags";
			this->textBoxTags->Size = System::Drawing::Size(431, 23);
			this->textBoxTags->TabIndex = 50;
			// 
			// textBoxDescription
			// 
			this->textBoxDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxDescription->Location = System::Drawing::Point(138, 159);
			this->textBoxDescription->Name = L"textBoxDescription";
			this->textBoxDescription->Size = System::Drawing::Size(431, 23);
			this->textBoxDescription->TabIndex = 49;
			// 
			// textBoxName
			// 
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxName->Location = System::Drawing::Point(138, 30);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(284, 23);
			this->textBoxName->TabIndex = 47;
			// 
			// labelTags
			// 
			this->labelTags->AutoSize = true;
			this->labelTags->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTags->Location = System::Drawing::Point(14, 189);
			this->labelTags->Name = L"labelTags";
			this->labelTags->Size = System::Drawing::Size(42, 17);
			this->labelTags->TabIndex = 46;
			this->labelTags->Text = L"Теги:";
			// 
			// labelDescription
			// 
			this->labelDescription->AutoSize = true;
			this->labelDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDescription->Location = System::Drawing::Point(14, 159);
			this->labelDescription->Name = L"labelDescription";
			this->labelDescription->Size = System::Drawing::Size(93, 17);
			this->labelDescription->TabIndex = 45;
			this->labelDescription->Text = L"Коментарии:";
			// 
			// labelTeacher
			// 
			this->labelTeacher->AutoSize = true;
			this->labelTeacher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTeacher->Location = System::Drawing::Point(14, 60);
			this->labelTeacher->Name = L"labelTeacher";
			this->labelTeacher->Size = System::Drawing::Size(115, 17);
			this->labelTeacher->TabIndex = 44;
			this->labelTeacher->Text = L"Преподаватель:";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelName->Location = System::Drawing::Point(14, 30);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(76, 17);
			this->labelName->TabIndex = 43;
			this->labelName->Text = L"Название:";
			// 
			// textBoxGroups
			// 
			this->textBoxGroups->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxGroups->Location = System::Drawing::Point(138, 89);
			this->textBoxGroups->Name = L"textBoxGroups";
			this->textBoxGroups->Size = System::Drawing::Size(284, 23);
			this->textBoxGroups->TabIndex = 57;
			// 
			// labelGroups
			// 
			this->labelGroups->AutoSize = true;
			this->labelGroups->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGroups->Location = System::Drawing::Point(14, 89);
			this->labelGroups->Name = L"labelGroups";
			this->labelGroups->Size = System::Drawing::Size(61, 17);
			this->labelGroups->TabIndex = 56;
			this->labelGroups->Text = L"Группы:";
			// 
			// textBoxHours
			// 
			this->textBoxHours->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxHours->Location = System::Drawing::Point(137, 118);
			this->textBoxHours->Name = L"textBoxHours";
			this->textBoxHours->Size = System::Drawing::Size(58, 23);
			this->textBoxHours->TabIndex = 59;
			// 
			// labelHours
			// 
			this->labelHours->AutoSize = true;
			this->labelHours->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelHours->Location = System::Drawing::Point(13, 118);
			this->labelHours->Name = L"labelHours";
			this->labelHours->Size = System::Drawing::Size(47, 17);
			this->labelHours->TabIndex = 58;
			this->labelHours->Text = L"Часы:";
			// 
			// comboBoxTeacher
			// 
			this->comboBoxTeacher->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBoxTeacher->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBoxTeacher->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTeacher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxTeacher->FormattingEnabled = true;
			this->comboBoxTeacher->Location = System::Drawing::Point(138, 59);
			this->comboBoxTeacher->Name = L"comboBoxTeacher";
			this->comboBoxTeacher->Size = System::Drawing::Size(284, 24);
			this->comboBoxTeacher->TabIndex = 60;
			// 
			// buttonArrow
			// 
			this->buttonArrow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonArrow->Location = System::Drawing::Point(428, 91);
			this->buttonArrow->Name = L"buttonArrow";
			this->buttonArrow->Size = System::Drawing::Size(34, 22);
			this->buttonArrow->TabIndex = 61;
			this->buttonArrow->Text = L"->";
			this->buttonArrow->UseVisualStyleBackColor = true;
			this->buttonArrow->Click += gcnew System::EventHandler(this, &ActivityInfoForm::buttonArrow_Click);
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBoxGroup->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBoxGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxGroup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Location = System::Drawing::Point(468, 89);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(101, 24);
			this->comboBoxGroup->TabIndex = 62;
			this->comboBoxGroup->SelectedIndexChanged += gcnew System::EventHandler(this, &ActivityInfoForm::comboBoxGroup_SelectedIndexChanged);
			// 
			// ActivityInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 374);
			this->Controls->Add(this->comboBoxGroup);
			this->Controls->Add(this->buttonArrow);
			this->Controls->Add(this->comboBoxTeacher);
			this->Controls->Add(this->textBoxHours);
			this->Controls->Add(this->labelHours);
			this->Controls->Add(this->textBoxGroups);
			this->Controls->Add(this->labelGroups);
			this->Controls->Add(this->buttonDebug);
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxTags);
			this->Controls->Add(this->textBoxDescription);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->labelTags);
			this->Controls->Add(this->labelDescription);
			this->Controls->Add(this->labelTeacher);
			this->Controls->Add(this->labelName);
			this->Name = L"ActivityInfoForm";
			this->Text = L"ActivityInfoForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ActivityInfoForm::ActivityInfoForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ActivityInfoForm::ActivityInfoForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void ActivityInfoForm_Load(System::Object^  sender, System::EventArgs^  e) {


	this->textBoxName->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
	this->textBoxDescription->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
	this->textBoxHours->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
	this->textBoxTags->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
	this->textBox->ReadOnly = GlobalData::Access == GlobalData::TEACHER;

	this->comboBoxTeacher->Enabled = GlobalData::Access == GlobalData::MANAGER;
	this->comboBoxGroup->Enabled = GlobalData::Access == GlobalData::MANAGER;
	this->buttonArrow->Enabled = GlobalData::Access == GlobalData::MANAGER;

	GlobalData::TeachersFormList = MainData.Teachers.getVal();
	GlobalData::GroupsFormList = MainData.Groups.getVal();

	for (auto t : GlobalData::TeachersFormList)
		this->comboBoxTeacher->Items->Add(gcnew System::String(t->getName().c_str()));

	for (auto g : GlobalData::GroupsFormList)
		this->comboBoxGroup->Items->Add(gcnew System::String(g->getName().c_str()));




	this->textBoxName->Text =
		gcnew System::String(MainData.EditingActivity->getName().c_str());
	this->comboBoxTeacher->SelectedIndex = MainData.Teachers.getPos(MainData.EditingActivity->getTeacher());
	//this->textBoxTeacher->Text =
	//	gcnew System::String(MainData.EditingActivity->getTeacher()->getName().c_str());
	this->textBoxGroups->Text =
		gcnew System::String(MainData.EditingActivity->getGroupsAsString().c_str());
	this->textBoxGroups->ReadOnly = true;
	this->comboBoxGroup->SelectedIndex = 0;
	this->textBoxHours->Text =
		gcnew System::String(to_string(MainData.EditingActivity->getHours()).c_str());
	this->textBoxDescription->Text =
		gcnew System::String(MainData.EditingActivity->getDescription().c_str());
	this->textBoxTags->Text =
		gcnew System::String(MainData.EditingActivity->getTagsAsString().c_str());

	this->textBox->Text = "";
	vector<string> txt = MainData.EditingActivity->getRules().getText();
	for (int i = 0; i < txt.size(); i++)
		this->textBox->Text += gcnew System::String(txt[i].c_str()) + "\r\n";


	if (MainData.EditingActivity->getGroups().find(GlobalData::GroupsFormList[comboBoxGroup->SelectedIndex]) !=
		MainData.EditingActivity->getGroups().end())
		buttonArrow->Text = "->";
	else
		buttonArrow->Text = "<-";


}

	private: System::Void ActivityInfoForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {


		trySave();
	}
private: System::Void buttonHelp_Click(System::Object^  sender, System::EventArgs^  e) {
	HelpRules ^ form = gcnew HelpRules;
	form->ShowDialog();
}
private: System::Void buttonDebug_Click(System::Object^  sender, System::EventArgs^  e) {
	trySave();
	Schedule.initRules();
	Schedule.debugOutput(dynamic_cast<ScheduleObject*>(MainData.EditingActivity), "../TestData/debug.xls");
}
		 System::Void trySave()
		 {
			 MainData.EditingActivity->setName(msclr::interop::marshal_as<std::string>(textBoxName->Text));
			 //MainData.EditingActivity->setTeacher(msclr::interop::marshal_as<std::string>(textBoxTeacher->Text));
			 MainData.EditingActivity->setTeacher(msclr::interop::marshal_as<std::string>(comboBoxTeacher->Text));
			 //MainData.EditingActivity->setGroups(stringToSet(msclr::interop::marshal_as<std::string>(textBoxGroups->Text)));
			 MainData.EditingActivity->setHours(std::stoi(msclr::interop::marshal_as<std::string>(textBoxHours->Text)));
			 MainData.EditingActivity->setDescription(msclr::interop::marshal_as<std::string>(textBoxDescription->Text));
			 MainData.EditingActivity->setTagsFromString(msclr::interop::marshal_as<std::string>(textBoxTags->Text));


			 vector<string> v;
			 cli::array<String^>^ lines = this->textBox->Text->Split(gcnew cli::array<String^> {"\n", "\r", "\r\n" }, StringSplitOptions::None);
			 for (int i = 0; i < lines->Length; i++)
				 v.push_back(msclr::interop::marshal_as<std::string>(lines->GetValue(i)->ToString()));
			 MainData.EditingActivity->getRules().setText(v);
		 }
private: System::Void buttonArrow_Click(System::Object^  sender, System::EventArgs^  e) {
	if (buttonArrow->Text == "->")
	{
		MainData.EditingActivity->getGroups().erase(GlobalData::GroupsFormList[comboBoxGroup->SelectedIndex]);
		buttonArrow->Text = "<-";
	}
	else
	{
		MainData.EditingActivity->getGroups().insert(GlobalData::GroupsFormList[comboBoxGroup->SelectedIndex]);
		buttonArrow->Text = "->";
	}
		

	this->textBoxGroups->Text =
		gcnew System::String(MainData.EditingActivity->getGroupsAsString().c_str());
}

		 
private: System::Void comboBoxGroup_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (MainData.EditingActivity->getGroups().find(GlobalData::GroupsFormList[comboBoxGroup->SelectedIndex]) !=
		MainData.EditingActivity->getGroups().end())
		buttonArrow->Text = "->";
	else
		buttonArrow->Text = "<-";
}
};
}
