#pragma once
#include "ParametersForm.h"
#include "StudentsForm.h"
#include "GroupsForm.h"
#include "TeachersForm.h"
#include "ClassroomsForm.h"
#include "ActivitiesForm.h"
#include "ScheduleForm.h"
#include "CheckPasswordBox.h"
#include "SetPasswordBox.h"


namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonParameters;
	private: System::Windows::Forms::Button^  buttonStudents;
	private: System::Windows::Forms::Button^  buttonTeachers;
	private: System::Windows::Forms::Button^  buttonClassrooms;


	private: System::Windows::Forms::Button^  buttonActivities;

	protected:

	protected:






	private: System::Windows::Forms::Button^  buttonSchedule;

	private: System::Windows::Forms::MenuStrip^  menuStrip;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem1;






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
			this->buttonParameters = (gcnew System::Windows::Forms::Button());
			this->buttonStudents = (gcnew System::Windows::Forms::Button());
			this->buttonTeachers = (gcnew System::Windows::Forms::Button());
			this->buttonClassrooms = (gcnew System::Windows::Forms::Button());
			this->buttonActivities = (gcnew System::Windows::Forms::Button());
			this->buttonSchedule = (gcnew System::Windows::Forms::Button());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonParameters
			// 
			this->buttonParameters->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonParameters->Location = System::Drawing::Point(12, 48);
			this->buttonParameters->Name = L"buttonParameters";
			this->buttonParameters->Size = System::Drawing::Size(260, 30);
			this->buttonParameters->TabIndex = 1;
			this->buttonParameters->Text = L"Параметры";
			this->buttonParameters->UseVisualStyleBackColor = true;
			this->buttonParameters->Click += gcnew System::EventHandler(this, &MainForm::buttonParameters_Click);
			// 
			// buttonStudents
			// 
			this->buttonStudents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStudents->Location = System::Drawing::Point(12, 84);
			this->buttonStudents->Name = L"buttonStudents";
			this->buttonStudents->Size = System::Drawing::Size(260, 30);
			this->buttonStudents->TabIndex = 2;
			this->buttonStudents->Text = L"Группы";
			this->buttonStudents->UseVisualStyleBackColor = true;
			this->buttonStudents->Click += gcnew System::EventHandler(this, &MainForm::buttonStudents_Click);
			// 
			// buttonTeachers
			// 
			this->buttonTeachers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonTeachers->Location = System::Drawing::Point(12, 120);
			this->buttonTeachers->Name = L"buttonTeachers";
			this->buttonTeachers->Size = System::Drawing::Size(260, 30);
			this->buttonTeachers->TabIndex = 3;
			this->buttonTeachers->Text = L"Преподаватели";
			this->buttonTeachers->UseVisualStyleBackColor = true;
			this->buttonTeachers->Click += gcnew System::EventHandler(this, &MainForm::buttonTeachers_Click);
			// 
			// buttonClassrooms
			// 
			this->buttonClassrooms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClassrooms->Location = System::Drawing::Point(12, 192);
			this->buttonClassrooms->Name = L"buttonClassrooms";
			this->buttonClassrooms->Size = System::Drawing::Size(260, 30);
			this->buttonClassrooms->TabIndex = 4;
			this->buttonClassrooms->Text = L"Аудитории";
			this->buttonClassrooms->UseVisualStyleBackColor = true;
			this->buttonClassrooms->Click += gcnew System::EventHandler(this, &MainForm::buttonClassrooms_Click);
			// 
			// buttonActivities
			// 
			this->buttonActivities->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonActivities->Location = System::Drawing::Point(12, 156);
			this->buttonActivities->Name = L"buttonActivities";
			this->buttonActivities->Size = System::Drawing::Size(260, 30);
			this->buttonActivities->TabIndex = 5;
			this->buttonActivities->Text = L"Дисциплины";
			this->buttonActivities->UseVisualStyleBackColor = true;
			this->buttonActivities->Click += gcnew System::EventHandler(this, &MainForm::buttonActivities_Click);
			// 
			// buttonSchedule
			// 
			this->buttonSchedule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSchedule->Location = System::Drawing::Point(12, 230);
			this->buttonSchedule->Name = L"buttonSchedule";
			this->buttonSchedule->Size = System::Drawing::Size(260, 44);
			this->buttonSchedule->TabIndex = 6;
			this->buttonSchedule->Text = L"Расписание";
			this->buttonSchedule->UseVisualStyleBackColor = true;
			this->buttonSchedule->Click += gcnew System::EventHandler(this, &MainForm::buttonSchedule_Click);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(285, 24);
			this->menuStrip->TabIndex = 7;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem1
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->newToolStripMenuItem->Text = L"Создать";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->openToolStripMenuItem->Text = L"Открыть";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->saveToolStripMenuItem->Text = L"Сохранить";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem1
			// 
			this->saveAsToolStripMenuItem1->Name = L"saveAsToolStripMenuItem1";
			this->saveAsToolStripMenuItem1->Size = System::Drawing::Size(162, 22);
			this->saveAsToolStripMenuItem1->Text = L"Сохранить как...";
			this->saveAsToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::saveAsToolStripMenuItem1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(285, 286);
			this->Controls->Add(this->buttonSchedule);
			this->Controls->Add(this->buttonActivities);
			this->Controls->Add(this->buttonClassrooms);
			this->Controls->Add(this->buttonTeachers);
			this->Controls->Add(this->buttonStudents);
			this->Controls->Add(this->buttonParameters);
			this->Controls->Add(this->menuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Scheduler";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void buttonParameters_Click(System::Object^  sender, System::EventArgs^  e) {
	ParametersForm ^ form = gcnew ParametersForm;
	form->ShowDialog();
}
private: System::Void buttonStudents_Click(System::Object^  sender, System::EventArgs^  e) {
	GroupsForm ^ form = gcnew GroupsForm;
	form->ShowDialog();

	update();
}
private: System::Void buttonTeachers_Click(System::Object^  sender, System::EventArgs^  e) {
	TeachersForm ^ form = gcnew TeachersForm;
	form->ShowDialog();

	update();
}
private: System::Void buttonClassrooms_Click(System::Object^  sender, System::EventArgs^  e) {
	ClassroomsForm ^ form = gcnew ClassroomsForm;
	form->ShowDialog();

	update();
}
private: System::Void buttonActivities_Click(System::Object^  sender, System::EventArgs^  e) {
	ActivitiesForm ^ form = gcnew ActivitiesForm;
	form->ShowDialog();

	update();
}
private: System::Void buttonSchedule_Click(System::Object^  sender, System::EventArgs^  e) {
	ScheduleForm ^ form = gcnew ScheduleForm;
	form->ShowDialog();
}


private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	GlobalData::Access = GlobalData::MANAGER;
	GlobalData::Path = "";

	MainData = GlobalData();
	Activity::GlobalGroups = MainData.Groups;
	Activity::GlobalTeachers = MainData.Teachers;
	Schedule = GeneratedSchedule();

	update();
}

private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	OpenFileDialog  ^ dialog = gcnew OpenFileDialog;
	dialog->Filter = "schedule files (*.sch)|*.sch|All files (*.*)|*.*";
	dialog->FilterIndex = 0;
	dialog->RestoreDirectory = true;

	if (dialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		GlobalData::Path = msclr::interop::marshal_as<string>(dialog->FileName);


		ifstream in(GlobalData::Path);
		in >> MainData;
		Activity::GlobalGroups = MainData.Groups;
		Activity::GlobalTeachers = MainData.Teachers;
		in >> Schedule;
		in.close();


		CheckPasswordBox ^ check = gcnew CheckPasswordBox;
		check->ShowDialog();

		if (!GlobalData::MessageBoxBool)
		{
			MainData = GlobalData();
			Schedule = GeneratedSchedule();
			return;
		}

		update();
	}


	
}

private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	if (GlobalData::Path.empty())
		saveAsToolStripMenuItem1_Click(sender, e);
	else
	{
		ofstream out(GlobalData::Path);
		out << MainData;
		out << Schedule;
		out.close();
	}
	
}

private: System::Void saveAsToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {


	string oldManagerPass = MainData.PassManager;
	string oldTeacherPass = MainData.PassTeacher;
	if (GlobalData::Access == GlobalData::MANAGER)
	{
		SetPasswordForm ^ saveBox = gcnew SetPasswordForm;
		saveBox->ShowDialog();

		if (!GlobalData::MessageBoxBool)
			return;
	}
	

	


	SaveFileDialog  ^ dialog = gcnew SaveFileDialog;
	dialog->Filter = "schedule files (*.sch)|*.sch|All files (*.*)|*.*";
	dialog->FilterIndex = 0;
	dialog->RestoreDirectory = true;

	if (dialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		GlobalData::Path = msclr::interop::marshal_as<string>(dialog->FileName);

		ofstream out(GlobalData::Path);
		out << MainData;
		out << Schedule;
		out.close();

	}
	else
	{
		MainData.PassManager = oldManagerPass;
		MainData.PassTeacher = oldTeacherPass;
	}



}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	GlobalData::Access = GlobalData::MANAGER;
	update();
}
private: System::Void update()
{
	if (GlobalData::Access == GlobalData::STUDENT)
	{
		this->buttonParameters->Enabled = false;
		this->buttonStudents->Enabled = false;
		this->buttonTeachers->Enabled = false;
		this->buttonActivities->Enabled = false;
		this->buttonClassrooms->Enabled = false;
		this->buttonSchedule->Enabled = Schedule.isGenerated();
		
	}
	else
	{
		this->buttonParameters->Enabled = true;
		this->buttonStudents->Enabled = true;
		this->buttonTeachers->Enabled = true;
		this->buttonActivities->Enabled = (!MainData.Groups.isEmpty() && !MainData.Teachers.isEmpty());
		this->buttonClassrooms->Enabled = true;
		this->buttonSchedule->Enabled = (!MainData.Groups.isEmpty() && !MainData.Teachers.isEmpty() && !MainData.Activities.isEmpty() && !MainData.Classrooms.isEmpty());
	}
	


}

};
}
