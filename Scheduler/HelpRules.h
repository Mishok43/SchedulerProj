#pragma once

namespace Scheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ HelpRules
	/// </summary>
	public ref class HelpRules : public System::Windows::Forms::Form
	{
	public:
		HelpRules(void)
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
		~HelpRules()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(17, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(243, 283);
			this->label1->TabIndex = 0;
			this->label1->Text = L"—правка\r\nинформаци€\r\nвс€ка€\r\nа\r\nа\r\nа\r\n€\r\n€\r\n€\r\n€";
			// 
			// HelpRules
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 356);
			this->Controls->Add(this->label1);
			this->Name = L"HelpRules";
			this->Text = L"HelpRules";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
