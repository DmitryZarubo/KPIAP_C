#include "getLongURL_form.h"
#include "URLshortForm.h"
#include "DatabaseForm.h"
#include "Data.h"

using namespace System;
using namespace ��������1;


System::Void ��������3::DatabaseForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void ��������3::DatabaseForm::getShortURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	��������1::URLshortForm^ shortURLform = gcnew ��������1::URLshortForm(); // �������� �����
	this->Close();                            //�������� ������� ����� 
	shortURLform->Show();    //�������� �������� �����
}

System::Void ��������3::DatabaseForm::getLongURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	��������2::getLongURL_form^ LongURLform = gcnew ��������2::getLongURL_form(); // �������� �����
	this->Close();                            //�������� ������� ����� 
	LongURLform->Show();    //�������� �������� �����
}

System::Void ��������3::DatabaseForm::helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("   In this window, you are able to look through the database, but you need to authorize before it.\
 Please, enter User Name and Password and press \"login\" button.\n\
   You can access the long link in the \"Get Long URL\" window.\n\
    If you want to add another long URL, then go to the \"Get Short URL\" window.", "About window", MessageBoxButtons::OK);
}

System::Void ��������3::DatabaseForm::button_login_Click(System::Object^ sender, System::EventArgs^ e)
{	
	String^ UserName = textBox_username->Text;
	String^ Password = textBox_password->Text;
	if (UserName == "root" && Password == "12345")
	{
		label_AuthorizeStatus->ForeColor = Color::ForestGreen;
		label_AuthorizeStatus->Text = "* Access granted";
		int StoredLinks;
		DataTable^ table = fillDataTable(StoredLinks);
		dataGridViewDatabase->DataSource = table;
		dataGridViewDatabase->TopLeftHeaderCell->Value = "Data";
		for (int i = 0; i < StoredLinks ; i++)
			dataGridViewDatabase->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridViewDatabase->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridViewDatabase->AutoResizeColumnHeadersHeight();
		label_LinksStored->Text = StoredLinks.ToString();
		label_info->Text="Links stored in the database :";

	}
	else {
		label_AuthorizeStatus->ForeColor = Color::DarkRed;
			label_AuthorizeStatus->Text = "* Wrong password or username";
			DataTable^ table = gcnew DataTable();
			dataGridViewDatabase->DataSource = table;
			label_LinksStored->Text = "";
			label_info->Text = "";
	}

	return System::Void();
}

DataTable^ ��������3::DatabaseForm::fillDataTable(int& rows)
{
	DataTable^ table;
	try
	{/*�������� ���������� � ����� ������ � �������� ��*/
		SQLiteConnection^ DATABASE = gcnew SQLiteConnection();
		String^ filename = "DatabaseURLs.db";

		DATABASE->ConnectionString = "Data Source=\"" + filename + "\"";
		DATABASE->Open();
		
		SQLiteCommand^ cmd1 = DATABASE->CreateCommand();
		cmd1->CommandText = "CREATE TABLE IF NOT EXISTS\"URLs\" (\
				\"id\"	INTEGER,\
				\"HashKey\"	TEXT NOT NULL UNIQUE,\
				\"LongURL\"	TEXT NOT NULL UNIQUE,\
				PRIMARY KEY(\"id\" AUTOINCREMENT)\
				);";
		cmd1->ExecuteNonQuery();
		SQLiteCommand^ cmd = DATABASE->CreateCommand();
		cmd->CommandText = "SELECT HashKey, LongURL FROM URLs;";
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		//����������
		DataColumn^ column; //������� �������
		DataRow^ row; //������ �������

		//������� ������� ������	
		table = gcnew DataTable();

		//������ �������� ��������
		vector<String^>^ nameColumns = gcnew vector<String^>();

		//�������� ������ � ��������
		for (int i = 0; i < reader->FieldCount; i++) {
			nameColumns->push_back(reader->GetName(i)->ToString());
			column = gcnew DataColumn(nameColumns->at(i), String::typeid);
			table->Columns->Add(column);
		}

		//��������� �� ������ ������
		while (reader->Read()) {
			//��������� ������� �������
			row = table->NewRow();
			//� ������ ������ ��������� �� ���� ��������
			for (int i = 0; i < reader->FieldCount; i++) {
				//��������� �������� ������� � row
				row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
			}
			table->Rows->Add(row);
		}
		rows = table->Rows->Count;
		DATABASE->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
	}
	return table;
}
