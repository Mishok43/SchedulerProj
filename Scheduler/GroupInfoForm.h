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
	/// Сводка для GroupInfoForm
	/// </summary>
	public ref class GroupInfoForm : public System::Windows::Forms::Form
	{
	public:
		GroupInfoForm(void)
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
		~GroupInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label5;
	protected:
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxTags;
	private: System::Windows::Forms::TextBox^  textBoxDescription;
	private: System::Windows::Forms::TextBox^  textBoxSize;

	private: System::Windows::Forms::TextBox^  textBoxName;
	private: System::Windows::Forms::Label^  labelTags;
	private: System::Windows::Forms::Label^  labelDescription;
	private: System::Windows::Forms::Label^  labelSize;

	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::Button^  buttonDebug;
	private: System::Windows::Forms::Button^  buttonHelp;

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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxTags = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDescription = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSize = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelTags = (gcnew System::Windows::Forms::Label());
			this->labelDescription = (gcnew System::Windows::Forms::Label());
			this->labelSize = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->buttonDebug = (gcnew System::Windows::Forms::Button());
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(12, 171);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(651, 2);
			this->label5->TabIndex = 38;
			// 
			// textBox
			// 
			this->textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(18, 196);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(635, 107);
			this->textBox->TabIndex = 37;
			this->textBox->WordWrap = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(15, 176);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 17);
			this->label6->TabIndex = 36;
			this->label6->Text = L"Индивидуальные ограничения";
			// 
			// textBoxTags
			// 
			this->textBoxTags->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxTags->Location = System::Drawing::Point(138, 130);
			this->textBoxTags->Name = L"textBoxTags";
			this->textBoxTags->Size = System::Drawing::Size(400, 23);
			this->textBoxTags->TabIndex = 35;
			// 
			// textBoxDescription
			// 
			this->textBoxDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxDescription->Location = System::Drawing::Point(138, 100);
			this->textBoxDescription->Name = L"textBoxDescription";
			this->textBoxDescription->Size = System::Drawing::Size(400, 23);
			this->textBoxDescription->TabIndex = 34;
			// 
			// textBoxSize
			// 
			this->textBoxSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSize->Location = System::Drawing::Point(138, 60);
			this->textBoxSize->Name = L"textBoxSize";
			this->textBoxSize->Size = System::Drawing::Size(58, 23);
			this->textBoxSize->TabIndex = 33;
			// 
			// textBoxName
			// 
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxName->Location = System::Drawing::Point(138, 30);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(134, 23);
			this->textBoxName->TabIndex = 32;
			// 
			// labelTags
			// 
			this->labelTags->AutoSize = true;
			this->labelTags->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTags->Location = System::Drawing::Point(14, 130);
			this->labelTags->Name = L"labelTags";
			this->labelTags->Size = System::Drawing::Size(42, 17);
			this->labelTags->TabIndex = 31;
			this->labelTags->Text = L"Теги:";
			// 
			// labelDescription
			// 
			this->labelDescription->AutoSize = true;
			this->labelDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDescription->Location = System::Drawing::Point(14, 100);
			this->labelDescription->Name = L"labelDescription";
			this->labelDescription->Size = System::Drawing::Size(93, 17);
			this->labelDescription->TabIndex = 30;
			this->labelDescription->Text = L"Коментарии:";
			// 
			// labelSize
			// 
			this->labelSize->AutoSize = true;
			this->labelSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSize->Location = System::Drawing::Point(14, 60);
			this->labelSize->Name = L"labelSize";
			this->labelSize->Size = System::Drawing::Size(61, 17);
			this->labelSize->TabIndex = 29;
			this->labelSize->Text = L"Размер:";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelName->Location = System::Drawing::Point(14, 30);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(118, 17);
			this->labelName->TabIndex = 28;
			this->labelName->Text = L"Идентификатор:";
			// 
			// buttonDebug
			// 
			this->buttonDebug->Location = System::Drawing::Point(266, 174);
			this->buttonDebug->Name = L"buttonDebug";
			this->buttonDebug->Size = System::Drawing::Size(81, 21);
			this->buttonDebug->TabIndex = 44;
			this->buttonDebug->Text = L"DEBUG INFO";
			this->buttonDebug->UseVisualStyleBackColor = true;
			this->buttonDebug->Visible = false;
			this->buttonDebug->Click += gcnew System::EventHandler(this, &GroupInfoForm::buttonDebug_Click);
			// 
			// buttonHelp
			// 
			this->buttonHelp->Location = System::Drawing::Point(226, 174);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(34, 21);
			this->buttonHelp->TabIndex = 43;
			this->buttonHelp->Text = L"\?";
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &GroupInfoForm::buttonHelp_Click);
			// 
			// GroupInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 315);
			this->Controls->Add(this->buttonDebug);
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxTags);
			this->Controls->Add(this->textBoxDescription);
			this->Controls->Add(this->textBoxSize);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->labelTags);
			this->Controls->Add(this->labelDescription);
			this->Controls->Add(this->labelSize);
			this->Controls->Add(this->labelName);
			this->Name = L"GroupInfoForm";
			this->Text = L"Группы | Редактирование";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GroupInfoForm::GroupInfoForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GroupInfoForm::GroupInfoForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GroupInfoForm_Load(System::Object^  sender, System::EventArgs^  e) {

		this->textBoxName->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
		this->textBoxSize->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
		this->textBoxDescription->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
		this->textBoxTags->ReadOnly = GlobalData::Access == GlobalData::TEACHER;
		this->textBox->ReadOnly = GlobalData::Access == GlobalData::TEACHER;

		this->textBoxName->Text =
			gcnew System::String(MainData.EditingGroup->getName().c_str());
		this->textBoxSize->Text =
			gcnew System::String(to_string(MainData.EditingGroup->getSize()).c_str());
		this->textBoxDescription->Text =
			gcnew System::String(MainData.EditingGroup->getDescription().c_str());
		this->textBoxTags->Text =
			gcnew System::String(MainData.EditingGroup->getTagsAsString().c_str());

		this->textBox->Text = "";
		vector<string> txt = MainData.EditingGroup->getRules().getText();
		for (int i = 0; i < txt.size(); i++)
			this->textBox->Text += gcnew System::String(txt[i].c_str()) + "\r\n";

	}

	private: System::Void GroupInfoForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {


		e->Cancel = !trySave();
	}
private: System::Void buttonHelp_Click(System::Object^  sender, System::EventArgs^  e) {
	HelpRules ^ form = gcnew HelpRules;
	form->ShowDialog();

}
private: System::Void buttonDebug_Click(System::Object^  sender, System::EventArgs^  e) {
	trySave();
	Schedule.initRules();
	Schedule.debugOutput(dynamic_cast<ScheduleObject*>(MainData.EditingGroup), "../TestData/debug.xls");
}
bool trySave()
{
	if (String::IsNullOrEmpty(textBoxName->Text))
	{
		MessageBox::Show("Графа ИДЕНТИФИКАТОР: требуется непустая строка");
		return false;
	}

	if (!isPositiveInteger(msclr::interop::marshal_as<std::string>(textBoxSize->Text)))
	{
		MessageBox::Show("Графа РАЗМЕР: требуется целое положительное число");
		return false;
	}

	MainData.EditingGroup->setName(msclr::interop::marshal_as<std::string>(textBoxName->Text));
	MainData.EditingGroup->setSize(std::stoi(msclr::interop::marshal_as<std::string>(textBoxSize->Text)));
	MainData.EditingGroup->setDescription(msclr::interop::marshal_as<std::string>(textBoxDescription->Text));
	MainData.EditingGroup->setTagsFromString(msclr::interop::marshal_as<std::string>(textBoxTags->Text));


	vector<string> v;
	cli::array<String^>^ lines = this->textBox->Text->Split(gcnew cli::array<String^> {"\n", "\r", "\r\n" }, StringSplitOptions::None);
	for (int i = 0; i < lines->Length; i++)
		v.push_back(msclr::interop::marshal_as<std::string>(lines->GetValue(i)->ToString()));
	MainData.EditingGroup->getRules().setText(v);

	return true;
}
};
}
