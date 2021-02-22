#pragma once
#include "DatabaseForm.h"
#include"getLongURL_form.h"
#include "URLshortForm.h"
namespace Курсовой {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		MainMenuForm(void)
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
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainMenuForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button1->Location = System::Drawing::Point(0, 450);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(643, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"EXIT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainMenuForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button2->Location = System::Drawing::Point(0, 414);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(643, 36);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Show Database";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainMenuForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button3->Location = System::Drawing::Point(0, 378);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(643, 36);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Get Long URL";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainMenuForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button4->Location = System::Drawing::Point(0, 342);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(643, 36);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Get Short URL";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainMenuForm::button4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Location = System::Drawing::Point(12, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(619, 321);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Discribsion";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(100, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(491, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Hello, you are using ZaruboShortener Application. Let me explain what can you do."
				L" ";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->HideSelection = false;
			this->textBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBox1->Location = System::Drawing::Point(22, 60);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(569, 231);
			this->textBox1->TabIndex = 0;
			this->textBox1->TabStop = false;
			this->textBox1->Text = resources->GetString(L"textBox1.Text");
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(643, 486);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->MaximumSize = System::Drawing::Size(659, 525);
			this->MinimumSize = System::Drawing::Size(659, 525);
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Zarubo Shortener";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Курсовой1::URLshortForm^ form = gcnew Курсовой1::URLshortForm();
	this->Hide();
	form->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Курсовой2::getLongURL_form^ form = gcnew Курсовой2::getLongURL_form();
	this->Hide();
	form->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Курсовой3::DatabaseForm^ form = gcnew Курсовой3::DatabaseForm();
	this->Hide();
	form->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
