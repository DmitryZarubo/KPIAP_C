#include "getLongURL_form.h"
#include "URLshortForm.h"
#include "DatabaseForm.h"
#include "Data.h"

using namespace System;
using namespace ��������1;

System::Void ��������2::getLongURL_form::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void ��������2::getLongURL_form::getShortURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	��������1::URLshortForm^ shortURLform = gcnew ��������1::URLshortForm(); // �������� �����
	this->Close();                            //�������� ������� ����� 
	shortURLform->Show();    //�������� �������� �����
	return System::Void();
}

System::Void ��������2::getLongURL_form::showDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	��������3::DatabaseForm^ Database_Form = gcnew ��������3::DatabaseForm();
	this->Close();
	Database_Form->Show();
}


System::Void ��������2::getLongURL_form::helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("   In this window, you are prompted to enter a short link and get a long URL by clicking on the \"Get Long URL\" button.\n\
    If you want to short another Long URL, please, go to  \"Get Short URL\" window.\n\
    If you want to see all saved URLs, then go to the \"Show Database\" window.", "About window", MessageBoxButtons::OK);
}

System::Void ��������2::getLongURL_form::button_GetLongURL_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		/*�������� ���������� � ����� ������ � �������� ��*/
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
		/*��������� �� ���������� �������� ������ � �������� ��� �� �����������*/
		String^ searchKey = textBox_shortURL->Text->ToString();
		String^ https = "https://";
		if (!searchKey->Contains(https))
		{
			MessageBox::Show("Unable to execute operation. \nIt is not a valid short URL key.\
\nEnter URL through \"https://\".", "Something went wrong....", MessageBoxButtons::OK, MessageBoxIcon::Error);
			DATABASE->Close(); 
			return;
		}
		if (!searchKey->Contains("ZaruboShortener"))
		{
			MessageBox::Show("Unable to shorten that link. \nThat isn\'t \
ZaruboShortener link.", "Something went wrong....", MessageBoxButtons::OK, MessageBoxIcon::Error);
			DATABASE->Close();
			return;
		}
		/*�������� ������� � ���� ������ �� ����� ���� � ����� �������� ������� � ���������� ����*/
		SQLiteCommand^ cmd = DATABASE->CreateCommand();
		cmd->CommandText = "SELECT * FROM URLs WHERE HashKey IN(\'"+searchKey+"\');";
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		/*���� ��������� ��������� �� ����� �� ����� ������� ������*/
		if (reader->HasRows)
		{
			textBox_LongURLs ->Text = reader->GetValue(2)->ToString();
		}
		/*���� ��� �� ��������� �� ���������� ������*/
		else
		{
			MessageBox::Show("Unable to execute operation. \nThere is no such short URL in the database.", "Something went wrong....", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		/*�������� ����������*/
		reader->Close();
		DATABASE->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error" + e->ToString(), "Exception");
	}
	return System::Void();
}
