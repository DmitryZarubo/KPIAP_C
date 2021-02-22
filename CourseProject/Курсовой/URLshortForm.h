#pragma once
#include "DatabaseForm.h"
#include "getLongURL_form.h"
namespace  урсовой1 {
	using namespace System::Data::SQLite;
	using namespace System::Text;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class URLshortForm : public System::Windows::Forms::Form
	{
	private:
	public:
		URLshortForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			//DATABASE = gcnew SQLiteConnection();
		
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~URLshortForm()
		{
			if (components)
			{
				delete components;
			}
	

		}
	private: System::Windows::Forms::TextBox^ textBox_shortURL;
	private: System::Windows::Forms::Button^ button_generateURL;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ textBox_OrigURL;

	private: System::Windows::Forms::GroupBox^ groupBox_OrigURL;




	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ getLongURLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showDatabaseToolStripMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox_ShortURL;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;




	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox_shortURL = (gcnew System::Windows::Forms::TextBox());
			this->button_generateURL = (gcnew System::Windows::Forms::Button());
			this->textBox_OrigURL = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_OrigURL = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox_ShortURL = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->getLongURLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showDatabaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox_OrigURL->SuspendLayout();
			this->groupBox_ShortURL->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox_shortURL
			// 
			this->textBox_shortURL->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_shortURL->Location = System::Drawing::Point(85, 53);
			this->textBox_shortURL->Name = L"textBox_shortURL";
			this->textBox_shortURL->ReadOnly = true;
			this->textBox_shortURL->Size = System::Drawing::Size(336, 32);
			this->textBox_shortURL->TabIndex = 1;
			// 
			// button_generateURL
			// 
			this->button_generateURL->Location = System::Drawing::Point(156, 133);
			this->button_generateURL->Name = L"button_generateURL";
			this->button_generateURL->Size = System::Drawing::Size(179, 30);
			this->button_generateURL->TabIndex = 1;
			this->button_generateURL->Text = L"Generate";
			this->button_generateURL->UseVisualStyleBackColor = true;
			this->button_generateURL->Click += gcnew System::EventHandler(this, &URLshortForm::button_generateURL_Click);
			// 
			// textBox_OrigURL
			// 
			this->textBox_OrigURL->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_OrigURL->Location = System::Drawing::Point(85, 95);
			this->textBox_OrigURL->Name = L"textBox_OrigURL";
			this->textBox_OrigURL->Size = System::Drawing::Size(336, 32);
			this->textBox_OrigURL->TabIndex = 0;
			// 
			// groupBox_OrigURL
			// 
			this->groupBox_OrigURL->Controls->Add(this->label3);
			this->groupBox_OrigURL->Controls->Add(this->button_generateURL);
			this->groupBox_OrigURL->Controls->Add(this->textBox_OrigURL);
			this->groupBox_OrigURL->Location = System::Drawing::Point(84, 52);
			this->groupBox_OrigURL->Name = L"groupBox_OrigURL";
			this->groupBox_OrigURL->Size = System::Drawing::Size(513, 203);
			this->groupBox_OrigURL->TabIndex = 3;
			this->groupBox_OrigURL->TabStop = false;
			this->groupBox_OrigURL->Text = L"Original URL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(85, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(147, 22);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Please enter your URL :";
			// 
			// groupBox_ShortURL
			// 
			this->groupBox_ShortURL->Controls->Add(this->label2);
			this->groupBox_ShortURL->Controls->Add(this->textBox_shortURL);
			this->groupBox_ShortURL->Location = System::Drawing::Point(84, 293);
			this->groupBox_ShortURL->Name = L"groupBox_ShortURL";
			this->groupBox_ShortURL->Size = System::Drawing::Size(512, 106);
			this->groupBox_ShortURL->TabIndex = 4;
			this->groupBox_ShortURL->TabStop = false;
			this->groupBox_ShortURL->Text = L"Short URL";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(85, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 22);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Your short URL:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"DIN Pro Regular", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->getLongURLToolStripMenuItem,
					this->showDatabaseToolStripMenuItem, this->helpToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(683, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// getLongURLToolStripMenuItem
			// 
			this->getLongURLToolStripMenuItem->Name = L"getLongURLToolStripMenuItem";
			this->getLongURLToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->getLongURLToolStripMenuItem->Text = L"Get Long URL";
			this->getLongURLToolStripMenuItem->Click += gcnew System::EventHandler(this, &URLshortForm::getLongURLToolStripMenuItem_Click);
			// 
			// showDatabaseToolStripMenuItem
			// 
			this->showDatabaseToolStripMenuItem->Name = L"showDatabaseToolStripMenuItem";
			this->showDatabaseToolStripMenuItem->Size = System::Drawing::Size(108, 20);
			this->showDatabaseToolStripMenuItem->Text = L"Show Database";
			this->showDatabaseToolStripMenuItem->Click += gcnew System::EventHandler(this, &URLshortForm::showDatabaseToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &URLshortForm::helpToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &URLshortForm::exitToolStripMenuItem_Click);
			// 
			// URLshortForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(683, 444);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox_ShortURL);
			this->Controls->Add(this->groupBox_OrigURL);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(699, 483);
			this->MinimumSize = System::Drawing::Size(699, 483);
			this->Name = L"URLshortForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"URL-shortener";
			this->Load += gcnew System::EventHandler(this, &URLshortForm::MyForm_Load);
			this->groupBox_OrigURL->ResumeLayout(false);
			this->groupBox_OrigURL->PerformLayout();
			this->groupBox_ShortURL->ResumeLayout(false);
			this->groupBox_ShortURL->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void getLongURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void showDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_generateURL_Click(System::Object^ sender, System::EventArgs^ e);
 private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}