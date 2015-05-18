#pragma once

namespace DeCom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ProcessingFrom
	/// </summary>
	public ref class ProcessingFrom : public System::Windows::Forms::Form
	{
	public:
		ProcessingFrom(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProcessingFrom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox;
	protected:
	private: System::Windows::Forms::ProgressBar^  progressBar;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// textBox
			// 
			this->textBox->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox->Location = System::Drawing::Point(12, 12);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->Size = System::Drawing::Size(260, 63);
			this->textBox->TabIndex = 0;
			this->textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(12, 95);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(260, 42);
			this->progressBar->TabIndex = 1;
			// 
			// ProcessingFrom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 149);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->textBox);
			this->Enabled = false;
			this->Name = L"ProcessingFrom";
			this->Text = L"ProcessingFrom";
			this->ResumeLayout(false);
			this->PerformLayout();
			this->Visible = false;
		}
#pragma endregion

	};
}
