#include "getLongURL_form.h"
#include "URLshortForm.h"
#include "DatabaseForm.h"
#include "Data.h"

using namespace System;
using namespace Курсовой1;

System::Void Курсовой2::getLongURL_form::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Курсовой2::getLongURL_form::getShortURLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Курсовой1::URLshortForm^ shortURLform = gcnew Курсовой1::URLshortForm(); // создание формы
	this->Close();                            //закрытие текущей формы 
	shortURLform->Show();    //открытие следущей формы
	return System::Void();
}

System::Void Курсовой2::getLongURL_form::showDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Курсовой3::DatabaseForm^ Database_Form = gcnew Курсовой3::DatabaseForm();
	this->Close();
	Database_Form->Show();
}


System::Void Курсовой2::getLongURL_form::helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("   In this window, you are prompted to enter a short link and get a long URL by clicking on the \"Get Long URL\" button.\n\
    If you want to short another Long URL, please, go to  \"Get Short URL\" window.\n\
    If you want to see all saved URLs, then go to the \"Show Database\" window.", "About window", MessageBoxButtons::OK);
}

System::Void Курсовой2::getLongURL_form::button_GetLongURL_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		/*Создание соединения с базой данных и открытие ее*/
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
		/*Получение из текстбокса короткой ссылки и проверка его на коректность*/
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
		/*Создание запроса в базу данных на поиск ряда с такой короткой ссылкой и считывание ряда*/
		SQLiteCommand^ cmd = DATABASE->CreateCommand();
		cmd->CommandText = "SELECT * FROM URLs WHERE HashKey IN(\'"+searchKey+"\');";
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		/*Если считалось нормально то вывод на экран длинной ссылки*/
		if (reader->HasRows)
		{
			textBox_LongURLs ->Text = reader->GetValue(2)->ToString();
		}
		/*Если нет то сообщение об отсутствии ссылки*/
		else
		{
			MessageBox::Show("Unable to execute operation. \nThere is no such short URL in the database.", "Something went wrong....", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		/*закрытие соединения*/
		reader->Close();
		DATABASE->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Error" + e->ToString(), "Exception");
	}
	return System::Void();
}
