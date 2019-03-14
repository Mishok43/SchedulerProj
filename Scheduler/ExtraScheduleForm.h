#pragma once
#include "GlobalData.h"

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ExtraScheduleForm
	/// </summary>
	public ref class ExtraScheduleForm : public System::Windows::Forms::Form
	{
	public:
		ExtraScheduleForm(void)
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
		~ExtraScheduleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonArrowGroups;
	private: System::Windows::Forms::TextBox^  textBoxGroups;
	private: System::Windows::Forms::ComboBox^  comboBoxGroups;
	private: System::Windows::Forms::ComboBox^  comboBoxTeachers;
	private: System::Windows::Forms::TextBox^  textBoxTeachers;


	private: System::Windows::Forms::Button^  buttonArrowTeachers;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBoxActivities;
	private: System::Windows::Forms::TextBox^  textBoxActivities;


	private: System::Windows::Forms::Button^  buttonArrowActivities;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBoxClassrooms;
	private: System::Windows::Forms::TextBox^  textBoxClassrooms;


	private: System::Windows::Forms::Button^  buttonArrowClassrooms;

	private: System::Windows::Forms::Label^  label5;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonArrowGroups = (gcnew System::Windows::Forms::Button());
			this->textBoxGroups = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxGroups = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxTeachers = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxTeachers = (gcnew System::Windows::Forms::TextBox());
			this->buttonArrowTeachers = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxActivities = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxActivities = (gcnew System::Windows::Forms::TextBox());
			this->buttonArrowActivities = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxClassrooms = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxClassrooms = (gcnew System::Windows::Forms::TextBox());
			this->buttonArrowClassrooms = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Отобразить в расписании:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(27, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Группы:";
			// 
			// buttonArrowGroups
			// 
			this->buttonArrowGroups->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonArrowGroups->Location = System::Drawing::Point(220, 65);
			this->buttonArrowGroups->Name = L"buttonArrowGroups";
			this->buttonArrowGroups->Size = System::Drawing::Size(34, 22);
			this->buttonArrowGroups->TabIndex = 62;
			this->buttonArrowGroups->Text = L"->";
			this->buttonArrowGroups->UseVisualStyleBackColor = true;
			this->buttonArrowGroups->Click += gcnew System::EventHandler(this, &ExtraScheduleForm::buttonArrowGroups_Click);
			// 
			// textBoxGroups
			// 
			this->textBoxGroups->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxGroups->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxGroups->Location = System::Drawing::Point(260, 63);
			this->textBoxGroups->Name = L"textBoxGroups";
			this->textBoxGroups->Size = System::Drawing::Size(307, 23);
			this->textBoxGroups->TabIndex = 63;
			// 
			// comboBoxGroups
			// 
			this->comboBoxGroups->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBoxGroups->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBoxGroups->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxGroups->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxGroups->FormattingEnabled = true;
			this->comboBoxGroups->Location = System::Drawing::Point(30, 65);
			this->comboBoxGroups->Name = L"comboBoxGroups";
			this->comboBoxGroups->Size = System::Drawing::Size(184, 24);
			this->comboBoxGroups->TabIndex = 64;
			this->comboBoxGroups->SelectedIndexChanged += gcnew System::EventHandler(this, &ExtraScheduleForm::comboBoxGroups_SelectedIndexChanged);
			// 
			// comboBoxTeachers
			// 
			this->comboBoxTeachers->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBoxTeachers->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBoxTeachers->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTeachers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxTeachers->FormattingEnabled = true;
			this->comboBoxTeachers->Location = System::Drawing::Point(30, 114);
			this->comboBoxTeachers->Name = L"comboBoxTeachers";
			this->comboBoxTeachers->Size = System::Drawing::Size(184, 24);
			this->comboBoxTeachers->TabIndex = 68;
			this->comboBoxTeachers->SelectedIndexChanged += gcnew System::EventHandler(this, &ExtraScheduleForm::comboBoxTeachers_SelectedIndexChanged);
			// 
			// textBoxTeachers
			// 
			this->textBoxTeachers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxTeachers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxTeachers->Location = System::Drawing::Point(260, 112);
			this->textBoxTeachers->Name = L"textBoxTeachers";
			this->textBoxTeachers->Size = System::Drawing::Size(307, 23);
			this->textBoxTeachers->TabIndex = 67;
			// 
			// buttonArrowTeachers
			// 
			this->buttonArrowTeachers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonArrowTeachers->Location = System::Drawing::Point(220, 114);
			this->buttonArrowTeachers->Name = L"buttonArrowTeachers";
			this->buttonArrowTeachers->Size = System::Drawing::Size(34, 22);
			this->buttonArrowTeachers->TabIndex = 66;
			this->buttonArrowTeachers->Text = L"->";
			this->buttonArrowTeachers->UseVisualStyleBackColor = true;
			this->buttonArrowTeachers->Click += gcnew System::EventHandler(this, &ExtraScheduleForm::buttonArrowTeachers_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(27, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(116, 17);
			this->label3->TabIndex = 65;
			this->label3->Text = L"Преподаватели:";
			// 
			// comboBoxActivities
			// 
			this->comboBoxActivities->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBoxActivities->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBoxActivities->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxActivities->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxActivities->FormattingEnabled = true;
			this->comboBoxActivities->Location = System::Drawing::Point(30, 164);
			this->comboBoxActivities->Name = L"comboBoxActivities";
			this->comboBoxActivities->Size = System::Drawing::Size(184, 24);
			this->comboBoxActivities->TabIndex = 72;
			this->comboBoxActivities->SelectedIndexChanged += gcnew System::EventHandler(this, &ExtraScheduleForm::comboBoxActivities_SelectedIndexChanged);
			// 
			// textBoxActivities
			// 
			this->textBoxActivities->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxActivities->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxActivities->Location = System::Drawing::Point(260, 162);
			this->textBoxActivities->Name = L"textBoxActivities";
			this->textBoxActivities->Size = System::Drawing::Size(307, 23);
			this->textBoxActivities->TabIndex = 71;
			// 
			// buttonArrowActivities
			// 
			this->buttonArrowActivities->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonArrowActivities->Location = System::Drawing::Point(220, 164);
			this->buttonArrowActivities->Name = L"buttonArrowActivities";
			this->buttonArrowActivities->Size = System::Drawing::Size(34, 22);
			this->buttonArrowActivities->TabIndex = 70;
			this->buttonArrowActivities->Text = L"->";
			this->buttonArrowActivities->UseVisualStyleBackColor = true;
			this->buttonArrowActivities->Click += gcnew System::EventHandler(this, &ExtraScheduleForm::buttonArrowActivities_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(27, 142);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 17);
			this->label4->TabIndex = 69;
			this->label4->Text = L"Дисциплины:";
			// 
			// comboBoxClassrooms
			// 
			this->comboBoxClassrooms->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBoxClassrooms->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBoxClassrooms->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxClassrooms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxClassrooms->FormattingEnabled = true;
			this->comboBoxClassrooms->Location = System::Drawing::Point(30, 212);
			this->comboBoxClassrooms->Name = L"comboBoxClassrooms";
			this->comboBoxClassrooms->Size = System::Drawing::Size(184, 24);
			this->comboBoxClassrooms->TabIndex = 76;
			this->comboBoxClassrooms->SelectedIndexChanged += gcnew System::EventHandler(this, &ExtraScheduleForm::comboBoxClassrooms_SelectedIndexChanged);
			// 
			// textBoxClassrooms
			// 
			this->textBoxClassrooms->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxClassrooms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxClassrooms->Location = System::Drawing::Point(260, 210);
			this->textBoxClassrooms->Name = L"textBoxClassrooms";
			this->textBoxClassrooms->Size = System::Drawing::Size(307, 23);
			this->textBoxClassrooms->TabIndex = 75;
			// 
			// buttonArrowClassrooms
			// 
			this->buttonArrowClassrooms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonArrowClassrooms->Location = System::Drawing::Point(220, 212);
			this->buttonArrowClassrooms->Name = L"buttonArrowClassrooms";
			this->buttonArrowClassrooms->Size = System::Drawing::Size(34, 22);
			this->buttonArrowClassrooms->TabIndex = 74;
			this->buttonArrowClassrooms->Text = L"->";
			this->buttonArrowClassrooms->UseVisualStyleBackColor = true;
			this->buttonArrowClassrooms->Click += gcnew System::EventHandler(this, &ExtraScheduleForm::buttonArrowClassrooms_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(27, 190);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 17);
			this->label5->TabIndex = 73;
			this->label5->Text = L"Аудитории:";
			// 
			// ExtraScheduleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(579, 261);
			this->Controls->Add(this->comboBoxClassrooms);
			this->Controls->Add(this->textBoxClassrooms);
			this->Controls->Add(this->buttonArrowClassrooms);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBoxActivities);
			this->Controls->Add(this->textBoxActivities);
			this->Controls->Add(this->buttonArrowActivities);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBoxTeachers);
			this->Controls->Add(this->textBoxTeachers);
			this->Controls->Add(this->buttonArrowTeachers);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBoxGroups);
			this->Controls->Add(this->textBoxGroups);
			this->Controls->Add(this->buttonArrowGroups);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"ExtraScheduleForm";
			this->Text = L"Дополнительные настройки таблицы";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ExtraScheduleForm::ExtraScheduleForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ExtraScheduleForm::ExtraScheduleForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ExtraScheduleForm_Load(System::Object^  sender, System::EventArgs^  e) {
		vector<string> groupsList;
		groupsList.push_back("Все");
		for (auto t : MainData.GroupTagRules.getMap())
			if (t.first != "Все")
				groupsList.push_back(t.first);

		for (auto s : Rules::Settings.nameMap[0])
			if (find(groupsList.begin(), groupsList.end(), s.first) == groupsList.end())
				groupsList.push_back(s.first);


		for (auto o: groupsList)
			comboBoxGroups->Items->Add(gcnew System::String(o.c_str()));

		comboBoxGroups->SelectedIndex = 0;
		if (MainData.GroupsToShow.find("Все") == MainData.GroupsToShow.end())
		{
			buttonArrowGroups->Text = "->";
		}
		else
			buttonArrowGroups->Text = "<-";
		textBoxGroups->Text = gcnew System::String(setToString(MainData.GroupsToShow).c_str());


		///

		vector<string> teachersList;
		teachersList.push_back("Все");
		for (auto t : MainData.TeacherTagRules.getMap())
			if (t.first != "Все")
				teachersList.push_back(t.first);

		for (auto s : Rules::Settings.nameMap[1])
			if (find(teachersList.begin(), teachersList.end(), s.first) == teachersList.end())
				teachersList.push_back(s.first);


		for (auto o : teachersList)
			comboBoxTeachers->Items->Add(gcnew System::String(o.c_str()));

		comboBoxTeachers->SelectedIndex = 0;
		if (MainData.TeachersToShow.find("Все") == MainData.TeachersToShow.end())
		{
			buttonArrowTeachers->Text = "->";
		}
		else
			buttonArrowTeachers->Text = "<-";
		textBoxTeachers->Text = gcnew System::String(setToString(MainData.TeachersToShow).c_str());

		//

		vector<string> activitiesList;
		activitiesList.push_back("Все");
		for (auto t : MainData.ActivityTagRules.getMap())
			if (t.first != "Все")
				activitiesList.push_back(t.first);

		for (auto s : Rules::Settings.nameMap[2])
			if (find(activitiesList.begin(), activitiesList.end(), s.first) == activitiesList.end())
				activitiesList.push_back(s.first);


		for (auto o : activitiesList)
			comboBoxActivities->Items->Add(gcnew System::String(o.c_str()));

		comboBoxActivities->SelectedIndex = 0;
		if (MainData.ActivitiesToShow.find("Все") == MainData.ActivitiesToShow.end())
		{
			buttonArrowActivities->Text = "->";
		}
		else
			buttonArrowActivities->Text = "<-";
		textBoxActivities->Text = gcnew System::String(setToString(MainData.ActivitiesToShow).c_str());

		//

		vector<string> classroomsList;
		classroomsList.push_back("Все");
		for (auto t : MainData.ClassroomTagRules.getMap())
			if (t.first != "Все")
				classroomsList.push_back(t.first);

		for (auto s : Rules::Settings.nameMap[3])
			if (find(classroomsList.begin(), classroomsList.end(), s.first) == classroomsList.end())
				classroomsList.push_back(s.first);


		for (auto o : classroomsList)
			comboBoxClassrooms->Items->Add(gcnew System::String(o.c_str()));

		comboBoxClassrooms->SelectedIndex = 0;
		if (MainData.ClassroomsToShow.find("Все") == MainData.ClassroomsToShow.end())
		{
			buttonArrowClassrooms->Text = "->";
		}
		else
			buttonArrowClassrooms->Text = "<-";
		textBoxClassrooms->Text = gcnew System::String(setToString(MainData.ClassroomsToShow).c_str());
	}
private: System::Void comboBoxGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	if (MainData.GroupsToShow.find(msclr::interop::marshal_as<std::string>(comboBoxGroups->SelectedItem->ToString())) == MainData.GroupsToShow.end())
	{
		buttonArrowGroups->Text = "->";
	}
	else
		buttonArrowGroups->Text = "<-";

}
private: System::Void buttonArrowGroups_Click(System::Object^  sender, System::EventArgs^  e) {

	if (buttonArrowGroups->Text == "->")
	{
		MainData.GroupsToShow.insert(msclr::interop::marshal_as<std::string>(comboBoxGroups->SelectedItem->ToString()));
		buttonArrowGroups->Text = "<-";
	}
	else
	{
		MainData.GroupsToShow.erase(msclr::interop::marshal_as<std::string>(comboBoxGroups->SelectedItem->ToString()));
		buttonArrowGroups->Text = "->";
	}
	textBoxGroups->Text = gcnew System::String(setToString(MainData.GroupsToShow).c_str());
}
private: System::Void ExtraScheduleForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

	if (MainData.GroupsToShow.empty())
		MainData.GroupsToShow = set<string>{ "Все" };

	if (MainData.TeachersToShow.empty())
		MainData.TeachersToShow = set<string>{ "Все" };

	if (MainData.ActivitiesToShow.empty())
		MainData.ActivitiesToShow = set<string>{ "Все" };

	if (MainData.ClassroomsToShow.empty())
		MainData.ClassroomsToShow = set<string>{ "Все" };
}
private: System::Void comboBoxTeachers_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (MainData.TeachersToShow.find(msclr::interop::marshal_as<std::string>(comboBoxTeachers->SelectedItem->ToString())) == MainData.TeachersToShow.end())
	{
		buttonArrowTeachers->Text = "->";
	}
	else
		buttonArrowTeachers->Text = "<-";
}
private: System::Void buttonArrowTeachers_Click(System::Object^  sender, System::EventArgs^  e) {

	if (buttonArrowTeachers->Text == "->")
	{
		MainData.TeachersToShow.insert(msclr::interop::marshal_as<std::string>(comboBoxTeachers->SelectedItem->ToString()));
		buttonArrowTeachers->Text = "<-";
	}
	else
	{
		MainData.TeachersToShow.erase(msclr::interop::marshal_as<std::string>(comboBoxTeachers->SelectedItem->ToString()));
		buttonArrowTeachers->Text = "->";
	}
	textBoxTeachers->Text = gcnew System::String(setToString(MainData.TeachersToShow).c_str());
}
private: System::Void comboBoxActivities_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	if (MainData.ActivitiesToShow.find(msclr::interop::marshal_as<std::string>(comboBoxActivities->SelectedItem->ToString())) == MainData.ActivitiesToShow.end())
	{
		buttonArrowActivities->Text = "->";
	}
	else
		buttonArrowActivities->Text = "<-";
}
private: System::Void buttonArrowActivities_Click(System::Object^  sender, System::EventArgs^  e) {
	if (buttonArrowActivities->Text == "->")
	{
		MainData.ActivitiesToShow.insert(msclr::interop::marshal_as<std::string>(comboBoxActivities->SelectedItem->ToString()));
		buttonArrowActivities->Text = "<-";
	}
	else
	{
		MainData.ActivitiesToShow.erase(msclr::interop::marshal_as<std::string>(comboBoxActivities->SelectedItem->ToString()));
		buttonArrowActivities->Text = "->";
	}
	textBoxActivities->Text = gcnew System::String(setToString(MainData.ActivitiesToShow).c_str());
}
private: System::Void comboBoxClassrooms_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (MainData.ClassroomsToShow.find(msclr::interop::marshal_as<std::string>(comboBoxClassrooms->SelectedItem->ToString())) == MainData.ClassroomsToShow.end())
	{
		buttonArrowClassrooms->Text = "->";
	}
	else
		buttonArrowClassrooms->Text = "<-";
}
private: System::Void buttonArrowClassrooms_Click(System::Object^  sender, System::EventArgs^  e) {
	if (buttonArrowClassrooms->Text == "->")
	{
		MainData.ClassroomsToShow.insert(msclr::interop::marshal_as<std::string>(comboBoxClassrooms->SelectedItem->ToString()));
		buttonArrowClassrooms->Text = "<-";
	}
	else
	{
		MainData.ClassroomsToShow.erase(msclr::interop::marshal_as<std::string>(comboBoxClassrooms->SelectedItem->ToString()));
		buttonArrowClassrooms->Text = "->";
	}
	textBoxClassrooms->Text = gcnew System::String(setToString(MainData.ClassroomsToShow).c_str());
}
};
}
