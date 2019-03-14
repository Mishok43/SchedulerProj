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
	/// Сводка для CheckPasswordBox
	/// </summary>
	public ref class CheckPasswordBox : public System::Windows::Forms::Form
	{
	public:
		CheckPasswordBox(void)
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
		~CheckPasswordBox()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::TextBox^  textBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonStudent;


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
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonStudent = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOK->Location = System::Drawing::Point(128, 58);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 32);
			this->buttonOK->TabIndex = 8;
			this->buttonOK->Text = L"ОК";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &CheckPasswordBox::buttonOK_Click);
			// 
			// textBox
			// 
			this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(12, 29);
			this->textBox->Name = L"textBox";
			this->textBox->PasswordChar = '*';
			this->textBox->Size = System::Drawing::Size(288, 23);
			this->textBox->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(9, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(298, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введите пароль менеджера/преподавателя";
			// 
			// buttonStudent
			// 
			this->buttonStudent->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonStudent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStudent->Location = System::Drawing::Point(209, 58);
			this->buttonStudent->Name = L"buttonStudent";
			this->buttonStudent->Size = System::Drawing::Size(91, 32);
			this->buttonStudent->TabIndex = 9;
			this->buttonStudent->Text = L"Я студент";
			this->buttonStudent->UseVisualStyleBackColor = true;
			this->buttonStudent->Click += gcnew System::EventHandler(this, &CheckPasswordBox::buttonStudent_Click);
			// 
			// CheckPasswordBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(312, 99);
			this->Controls->Add(this->buttonStudent);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"CheckPasswordBox";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Определение уровня доступа";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CheckPasswordBox::CheckPasswordBox_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CheckPasswordBox::CheckPasswordBox_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	int p = GlobalData::computeHash(msclr::interop::marshal_as<string>(textBox->Text).c_str());

	if (p == MainData.PassManager)
	{
		GlobalData::Access = GlobalData::MANAGER;
		GlobalData::MessageBoxBool = true;
		this->Close();
	}
	else if (p == MainData.PassTeacher)
	{
		GlobalData::Access = GlobalData::TEACHER;
		GlobalData::MessageBoxBool = true;
		this->Close();
	}
	else
	{
		MessageBox::Show("Неверный пароль");
	}
}

private: System::Void buttonStudent_Click(System::Object^  sender, System::EventArgs^  e) {
	GlobalData::Access = GlobalData::STUDENT;
	GlobalData::MessageBoxBool = true;
	this->Close();

}
private: System::Void CheckPasswordBox_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
}
private: System::Void CheckPasswordBox_Load(System::Object^  sender, System::EventArgs^  e) {
	GlobalData::MessageBoxBool = false;
}
};
}
