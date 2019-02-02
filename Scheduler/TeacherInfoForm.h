#pragma once

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TeacherInfoForm
	/// </summary>
	public ref class TeacherInfoForm : public System::Windows::Forms::Form
	{
	public:
		TeacherInfoForm(void)
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
		~TeacherInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label7;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Идентификатор:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"emgrinkrug";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(108, 49);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"Гринкруг";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Фамилия:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(108, 101);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"Михайлович";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Отчество:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(108, 75);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 5;
			this->textBox4->Text = L"Ефим";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 78);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Имя:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label5
			// 
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(9, 138);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(651, 2);
			this->label5->TabIndex = 24;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(15, 163);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(635, 107);
			this->textBox5->TabIndex = 23;
			this->textBox5->Text = L"ВРЕМЯ(14:00-21:00)\r\nНЕ АУДИТОРИЯ(407)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(12, 143);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 17);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Индивидуальные ограничения";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(362, 47);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 23);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Список занятий";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(304, 101);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(346, 20);
			this->textBox6->TabIndex = 27;
			this->textBox6->Text = L"только_будни";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(264, 104);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Теги:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// TeacherInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 284);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"TeacherInfoForm";
			this->Text = L"Гринкруг Е.М.";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
