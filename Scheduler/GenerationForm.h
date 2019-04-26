#pragma once
#include "GeneratedSchedule.h"
//#include <thread>

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	


	


	/// <summary>
	/// —водка дл€ GenerationForm
	/// </summary>
	public ref class GenerationForm : public System::Windows::Forms::Form
	{
	public:
		GenerationForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~GenerationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(83, 166);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GenerationForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(45, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(259, 201);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GenerationForm::button2_Click);
			// 
			// GenerationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"GenerationForm";
			this->Text = L"GenerationForm";
			this->Load += gcnew System::EventHandler(this, &GenerationForm::GenerationForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Schedule.generate(false);

		MessagePrinter^ printer1 = gcnew MessagePrinter();
		Thread^ thread1 = gcnew Thread(gcnew ThreadStart(printer1, &MessagePrinter::Print));
		//thread1->Name = "thread1";

		thread1->Start();
		
	}


	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		this->label1->Text = gcnew System::String(("PROCESS:"+to_string(Schedule.process[0])+" "+to_string(Schedule.process[1])+ " " + to_string(Schedule.process[2]) + " " + to_string(Schedule.process[3])+ " " + to_string(Schedule.process[4])+" SOLUTIONS: "+ to_string(Schedule.solutionsFound)).c_str());
	}
	private: System::Void GenerationForm_Load(System::Object^  sender, System::EventArgs^  e) {

		System::Windows::Forms::Timer ^ timer = gcnew System::Windows::Forms::Timer();
		timer->Interval = (100); // 10 secs
		timer->Tick += gcnew EventHandler(this,&GenerationForm::timer_Tick);
		timer->Start();
	}

	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};




	
}
