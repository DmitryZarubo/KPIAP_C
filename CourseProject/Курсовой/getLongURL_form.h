#pragma once

namespace  урсовой2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ getLongURL_form
	/// </summary>
	public ref class getLongURL_form : public System::Windows::Forms::Form
	{
	public:
		getLongURL_form(void)
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
		~getLongURL_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox_ShortURL;
	private: System::Windows::Forms::Button^ button_GetLongURL;
	protected:

	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ getShortURLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showDatabaseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox_LongURL;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_shortURL;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_LongURLs;

	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;


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
			this->groupBox_ShortURL = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_shortURL = (gcnew System::Windows::Forms::TextBox());
			this->button_GetLongURL = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->getShortURLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showDatabaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox_LongURL = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_LongURLs = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_ShortURL->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox_LongURL->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_ShortURL
			// 
			this->groupBox_ShortURL->Controls->Add(this->label1);
			this->groupBox_ShortURL->Controls->Add(this->textBox_shortURL);
			this->groupBox_ShortURL->Controls->Add(this->button_GetLongURL);
			this->groupBox_ShortURL->Location = System::Drawing::Point(73, 43);
			this->groupBox_ShortURL->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->groupBox_ShortURL->Name = L"groupBox_ShortURL";
			this->groupBox_ShortURL->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->groupBox_ShortURL->Size = System::Drawing::Size(526, 201);
			this->groupBox_ShortURL->TabIndex = 0;
			this->groupBox_ShortURL->TabStop = false;
			this->groupBox_ShortURL->Text = L"Short URL";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(110, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Please, enter your short URL :";
			// 
			// textBox_shortURL
			// 
			this->textBox_shortURL->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_shortURL->Location = System::Drawing::Point(114, 102);
			this->textBox_shortURL->Name = L"textBox_shortURL";
			this->textBox_shortURL->Size = System::Drawing::Size(298, 32);
			this->textBox_shortURL->TabIndex = 0;
			this->textBox_shortURL->TabStop = false;
			// 
			// button_GetLongURL
			// 
			this->button_GetLongURL->Location = System::Drawing::Point(182, 142);
			this->button_GetLongURL->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->button_GetLongURL->Name = L"button_GetLongURL";
			this->button_GetLongURL->Size = System::Drawing::Size(155, 39);
			this->button_GetLongURL->TabIndex = 1;
			this->button_GetLongURL->Text = L"Get Long URL";
			this->button_GetLongURL->UseVisualStyleBackColor = true;
			this->button_GetLongURL->Click += gcnew System::EventHandler(this, &getLongURL_form::button_GetLongURL_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"DIN Pro Regular", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->getShortURLToolStripMenuItem,
					this->showDatabaseToolStripMenuItem, this->helpToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(683, 26);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// getShortURLToolStripMenuItem
			// 
			this->getShortURLToolStripMenuItem->Name = L"getShortURLToolStripMenuItem";
			this->getShortURLToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->getShortURLToolStripMenuItem->Text = L"Get Short URL";
			this->getShortURLToolStripMenuItem->Click += gcnew System::EventHandler(this, &getLongURL_form::getShortURLToolStripMenuItem_Click);
			// 
			// showDatabaseToolStripMenuItem
			// 
			this->showDatabaseToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"DIN Pro Regular", 9.749999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->showDatabaseToolStripMenuItem->Name = L"showDatabaseToolStripMenuItem";
			this->showDatabaseToolStripMenuItem->Size = System::Drawing::Size(108, 20);
			this->showDatabaseToolStripMenuItem->Text = L"Show Database";
			this->showDatabaseToolStripMenuItem->Click += gcnew System::EventHandler(this, &getLongURL_form::showDatabaseToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &getLongURL_form::helpToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &getLongURL_form::exitToolStripMenuItem_Click);
			// 
			// groupBox_LongURL
			// 
			this->groupBox_LongURL->Controls->Add(this->label2);
			this->groupBox_LongURL->Controls->Add(this->textBox_LongURLs);
			this->groupBox_LongURL->Location = System::Drawing::Point(73, 275);
			this->groupBox_LongURL->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->groupBox_LongURL->Name = L"groupBox_LongURL";
			this->groupBox_LongURL->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->groupBox_LongURL->Size = System::Drawing::Size(526, 134);
			this->groupBox_LongURL->TabIndex = 2;
			this->groupBox_LongURL->TabStop = false;
			this->groupBox_LongURL->Text = L"Long URL";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(110, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Your Long URL :";
			// 
			// textBox_LongURLs
			// 
			this->textBox_LongURLs->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_LongURLs->Location = System::Drawing::Point(114, 58);
			this->textBox_LongURLs->Name = L"textBox_LongURLs";
			this->textBox_LongURLs->ReadOnly = true;
			this->textBox_LongURLs->Size = System::Drawing::Size(298, 32);
			this->textBox_LongURLs->TabIndex = 2;
			// 
			// getLongURL_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(683, 444);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox_LongURL);
			this->Controls->Add(this->groupBox_ShortURL);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->MaximumSize = System::Drawing::Size(699, 483);
			this->MinimumSize = System::Drawing::Size(699, 483);
			this->Name = L"getLongURL_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"getLongURL_form";
			this->Load += gcnew System::EventHandler(this, &getLongURL_form::getLongURL_form_Load);
			this->groupBox_ShortURL->ResumeLayout(false);
			this->groupBox_ShortURL->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox_LongURL->ResumeLayout(false);
			this->groupBox_LongURL->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void getLongURL_form_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void getShortURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void showDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_GetLongURL_Click(System::Object^ sender, System::EventArgs^ e);
};
}
