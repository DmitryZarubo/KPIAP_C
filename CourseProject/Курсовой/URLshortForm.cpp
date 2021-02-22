#include "URLshortForm.h"
#include "DatabaseForm.h"
#include "getLongURL_form.h"
#include "Data.h"

using namespace System::Data::SQLite;
using namespace System::Text;
using namespace System;
using namespace ��������1;



System::Void ��������1::URLshortForm::getLongURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	  ��������2:: getLongURL_form^ LongURLform = gcnew ��������2::getLongURL_form(); // �������� �����
    this->Close();                            //�������� ������� ����� 
    LongURLform->Show();    //�������� �������� �����
}

System::Void ��������1::URLshortForm::showDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	��������3::DatabaseForm^ Database_Form = gcnew ��������3::DatabaseForm(); //�������� ����� 
	    this->Close(); //�������� ������� �����
	    Database_Form->Show(); //�������� ���������� �����
}

System::Void ��������1::URLshortForm::helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	    MessageBox::Show("   In this window, you are prompted to enter a long link \
to insert it into the database and get a short URL by clicking on the \"Generate\" button.\n\
   Later, using the short URL, you can access the long link in the \"Get Long URL\" window.\n\
    If you want to see all saved URLs, then go to the \"Show Database\" window.","About window",  MessageBoxButtons::OK); //��������� ������
}

System::Void ��������1::URLshortForm::button_generateURL_Click(System::Object^ sender, System::EventArgs^ e)
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
		
		/*��������� �� ���������� ������ ��� ���������� � �������� �� ������������*/
		String^ searchLink = textBox_OrigURL->Text->ToString();
		String^ https = "https://";
		if ( !searchLink->Contains(https))
		{
			MessageBox::Show("Unable to shorten that link. \nIt is not a\
 valid URL.\nEnter URL through \"https://\".", "Something went wrong....", MessageBoxButtons::OK, MessageBoxIcon::Error);
			DATABASE->Close(); 
			return;
		}
		/*�������� �������� �� ���� ��� �������� �������*/
		if (searchLink->Contains("ZaruboShortener"))
		{
			MessageBox::Show("Unable to shorten that link. \nThat is already \
ZaruboShortener link.", "Something went wrong....", MessageBoxButtons::OK, MessageBoxIcon::Error);
			DATABASE->Close(); 
			return;
		}
		/*�������� ������� �� ����� � �������� ��� �� ���� � ������ ����, ��� �����*/
		SQLiteCommand^ cmd = DATABASE->CreateCommand();
		cmd->CommandText = "SELECT * FROM URLs  WHERE LongURL IN(\'" + searchLink + "\');";
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		/*�������� ����� �� ������������ ������ � ����, ���� ����� �� ������ ��� � �����*/
		if (reader->HasRows)
		{
			textBox_shortURL->Text = reader->GetValue(1)->ToString();
			reader->Close();
		}
		/*���� �� ����� �� �������� ������ ����� � ��������� ��� � ���� � ������ � �����*/
		else
		{
			reader->Close();
			SQLiteTransaction^ dbTrans = DATABASE->BeginTransaction();
			DATA::DataB input(DATA::convert_String_to_string(searchLink));
			cmd->CommandText = "INSERT INTO URLs (HashKey, LongURL) VALUES(\'" + DATA::convert_string_to_String(input.getHashKey()) + "\',\
\'" + DATA::convert_string_to_String(input.getValue()) + "\');";
				cmd->ExecuteNonQuery();
				textBox_shortURL->Text = DATA::convert_string_to_String(input.getHashKey());
				dbTrans->Commit();
		}
		/*�������� ����������*/
		DATABASE->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error" + e->ToString(), "Exception");
	}
}

System::Void ��������1::URLshortForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
