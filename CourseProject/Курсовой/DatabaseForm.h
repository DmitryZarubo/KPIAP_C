#pragma once
#include <cliext/vector>
namespace  урсовой3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cliext;

	/// <summary>
	/// —водка дл€ DatabaseForm
	/// </summary>
	public ref class DatabaseForm : public System::Windows::Forms::Form
	{
	public:
		DatabaseForm(void)
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
		~DatabaseForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ getShortURLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ getLongURLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox_Authorization;
	private: System::Windows::Forms::Button^ button_login;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_password;

	private: System::Windows::Forms::TextBox^ textBox_username;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label_LinksStored;
	private: System::Windows::Forms::Label^ label_info;

	private: System::Windows::Forms::DataGridView^ dataGridViewDatabase;

	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Label^ label_AuthorizeStatus;




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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->getShortURLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getLongURLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox_Authorization = (gcnew System::Windows::Forms::GroupBox());
			this->label_AuthorizeStatus = (gcnew System::Windows::Forms::Label());
			this->button_login = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->textBox_username = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_LinksStored = (gcnew System::Windows::Forms::Label());
			this->label_info = (gcnew System::Windows::Forms::Label());
			this->dataGridViewDatabase = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->groupBox_Authorization->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDatabase))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"DIN Pro Regular", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->getShortURLToolStripMenuItem,
					this->getLongURLToolStripMenuItem, this->helpToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(983, 26);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// getShortURLToolStripMenuItem
			// 
			this->getShortURLToolStripMenuItem->Name = L"getShortURLToolStripMenuItem";
			this->getShortURLToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->getShortURLToolStripMenuItem->Text = L"Get Short URL";
			this->getShortURLToolStripMenuItem->Click += gcnew System::EventHandler(this, &DatabaseForm::getShortURLToolStripMenuItem_Click);
			// 
			// getLongURLToolStripMenuItem
			// 
			this->getLongURLToolStripMenuItem->Name = L"getLongURLToolStripMenuItem";
			this->getLongURLToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->getLongURLToolStripMenuItem->Text = L"Get Long URL";
			this->getLongURLToolStripMenuItem->Click += gcnew System::EventHandler(this, &DatabaseForm::getLongURLToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &DatabaseForm::helpToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &DatabaseForm::exitToolStripMenuItem_Click);
			// 
			// groupBox_Authorization
			// 
			this->groupBox_Authorization->Controls->Add(this->label_AuthorizeStatus);
			this->groupBox_Authorization->Controls->Add(this->button_login);
			this->groupBox_Authorization->Controls->Add(this->label2);
			this->groupBox_Authorization->Controls->Add(this->label1);
			this->groupBox_Authorization->Controls->Add(this->textBox_password);
			this->groupBox_Authorization->Controls->Add(this->textBox_username);
			this->groupBox_Authorization->Location = System::Drawing::Point(12, 48);
			this->groupBox_Authorization->Name = L"groupBox_Authorization";
			this->groupBox_Authorization->Size = System::Drawing::Size(227, 245);
			this->groupBox_Authorization->TabIndex = 1;
			this->groupBox_Authorization->TabStop = false;
			this->groupBox_Authorization->Text = L"Authorization";
			// 
			// label_AuthorizeStatus
			// 
			this->label_AuthorizeStatus->AutoEllipsis = true;
			this->label_AuthorizeStatus->AutoSize = true;
			this->label_AuthorizeStatus->Location = System::Drawing::Point(6, 204);
			this->label_AuthorizeStatus->Name = L"label_AuthorizeStatus";
			this->label_AuthorizeStatus->Size = System::Drawing::Size(0, 22);
			this->label_AuthorizeStatus->TabIndex = 5;
			// 
			// button_login
			// 
			this->button_login->Location = System::Drawing::Point(75, 162);
			this->button_login->Name = L"button_login";
			this->button_login->Size = System::Drawing::Size(75, 33);
			this->button_login->TabIndex = 2;
			this->button_login->Text = L"login";
			this->button_login->UseVisualStyleBackColor = true;
			this->button_login->Click += gcnew System::EventHandler(this, &DatabaseForm::button_login_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"User Name :";
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(25, 126);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->PasswordChar = '*';
			this->textBox_password->Size = System::Drawing::Size(175, 30);
			this->textBox_password->TabIndex = 1;
			// 
			// textBox_username
			// 
			this->textBox_username->Location = System::Drawing::Point(25, 61);
			this->textBox_username->Name = L"textBox_username";
			this->textBox_username->Size = System::Drawing::Size(175, 30);
			this->textBox_username->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_LinksStored);
			this->groupBox1->Controls->Add(this->label_info);
			this->groupBox1->Controls->Add(this->dataGridViewDatabase);
			this->groupBox1->Location = System::Drawing::Point(245, 48);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(726, 455);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Database info";
			// 
			// label_LinksStored
			// 
			this->label_LinksStored->AutoSize = true;
			this->label_LinksStored->Location = System::Drawing::Point(188, 407);
			this->label_LinksStored->Name = L"label_LinksStored";
			this->label_LinksStored->Size = System::Drawing::Size(0, 22);
			this->label_LinksStored->TabIndex = 2;
			// 
			// label_info
			// 
			this->label_info->AutoSize = true;
			this->label_info->Location = System::Drawing::Point(11, 407);
			this->label_info->Name = L"label_info";
			this->label_info->Size = System::Drawing::Size(0, 22);
			this->label_info->TabIndex = 1;
			// 
			// dataGridViewDatabase
			// 
			this->dataGridViewDatabase->AllowUserToAddRows = false;
			this->dataGridViewDatabase->AllowUserToDeleteRows = false;
			this->dataGridViewDatabase->AllowUserToResizeColumns = false;
			this->dataGridViewDatabase->AllowUserToResizeRows = false;
			this->dataGridViewDatabase->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewDatabase->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDatabase->GridColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridViewDatabase->Location = System::Drawing::Point(6, 29);
			this->dataGridViewDatabase->Name = L"dataGridViewDatabase";
			this->dataGridViewDatabase->ReadOnly = true;
			this->dataGridViewDatabase->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
			this->dataGridViewDatabase->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridViewDatabase->Size = System::Drawing::Size(714, 366);
			this->dataGridViewDatabase->TabIndex = 0;
			// 
			// DatabaseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(983, 618);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox_Authorization);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"DIN Pro Cond", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->MaximumSize = System::Drawing::Size(999, 657);
			this->MinimumSize = System::Drawing::Size(999, 657);
			this->Name = L"DatabaseForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DatabaseForm";
			this->Load += gcnew System::EventHandler(this, &DatabaseForm::DatabaseForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox_Authorization->ResumeLayout(false);
			this->groupBox_Authorization->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDatabase))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DatabaseForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void getShortURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void getLongURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_login_Click(System::Object^ sender, System::EventArgs^ e);
private: DataTable^ fillDataTable(int& rows);
};
}
