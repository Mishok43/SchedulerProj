#pragma once
#include "ParametersForm.h"
#include "StudentsForm.h"
#include "TeachersForm.h"
#include "ClassroomsForm.h"
#include "ActivitiesForm.h"
#include "ScheduleForm.h"



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
			this->buttonStudents->Location = System::Drawing::Point(12, 84);
			this->buttonStudents->Name = L"buttonStudents";
			this->buttonStudents->Size = System::Drawing::Size(260, 30);
			this->buttonStudents->TabIndex = 2;
			this->buttonStudents->Text = L"Студенты/Группы";
			this->buttonStudents->UseVisualStyleBackColor = true;
			this->buttonStudents->Click += gcnew System::EventHandler(this, &MainForm::buttonStudents_Click);
			// 
			// buttonTeachers
			// 
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
			this->buttonClassrooms->Location = System::Drawing::Point(12, 156);
			this->buttonClassrooms->Name = L"buttonClassrooms";
			this->buttonClassrooms->Size = System::Drawing::Size(260, 30);
			this->buttonClassrooms->TabIndex = 4;
			this->buttonClassrooms->Text = L"Аудитории";
			this->buttonClassrooms->UseVisualStyleBackColor = true;
			this->buttonClassrooms->Click += gcnew System::EventHandler(this, &MainForm::buttonClassrooms_Click);
			// 
			// buttonActivities
			// 
			this->buttonActivities->Location = System::Drawing::Point(12, 192);
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
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->saveToolStripMenuItem->Text = L"Сохранить";
			// 
			// saveAsToolStripMenuItem1
			// 
			this->saveAsToolStripMenuItem1->Name = L"saveAsToolStripMenuItem1";
			this->saveAsToolStripMenuItem1->Size = System::Drawing::Size(162, 22);
			this->saveAsToolStripMenuItem1->Text = L"Сохранить как...";
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
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MainForm";
			this->Text = L"Scheduler";
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void buttonParameters_Click(System::Object^  sender, System::EventArgs^  e) {
	ParametersForm ^ form = gcnew ParametersForm;
	form->ShowDialog();
}
private: System::Void buttonStudents_Click(System::Object^  sender, System::EventArgs^  e) {
	StudentsForm ^ form = gcnew StudentsForm;
	form->ShowDialog();
}
private: System::Void buttonTeachers_Click(System::Object^  sender, System::EventArgs^  e) {
	TeachersForm ^ form = gcnew TeachersForm;
	form->ShowDialog();
}
private: System::Void buttonClassrooms_Click(System::Object^  sender, System::EventArgs^  e) {
	ClassroomsForm ^ form = gcnew ClassroomsForm;
	form->ShowDialog();

	 
}
private: System::Void buttonActivities_Click(System::Object^  sender, System::EventArgs^  e) {
	ActivitiesForm ^ form = gcnew ActivitiesForm;
	form->ShowDialog();
}
private: System::Void buttonSchedule_Click(System::Object^  sender, System::EventArgs^  e) {
	ScheduleForm ^ form = gcnew ScheduleForm;
	form->ShowDialog();
}
};
}
