#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "MyForm1.h"

namespace ProjectPO1 {

	using namespace std; // пространство имён стандартной библиотеки
	using namespace::System::Runtime::InteropServices; // для поддержки COM - взаимодействия и преобразования данных из оперативной памяти в формат для хранения и передачи данных
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::ifstream FileStreamInput; // входной поток
	std::ofstream FileStreamOutput; // выходной поток
	std::string BufferString; // переменная для временной работы со строками
	const char* FileNameIn; // символьный массив для имени файла
	char* BufferChar; // символьный массив для строк
	int i; // счётчик строк

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	public:
		MyForm1^ Mf1 = gcnew MyForm1;

		String^ FileN = ""; // имя файла
		String^ FileE = ""; // расширение файла
		String^ LineS = "";
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ решениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar1;
	public:
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ новыйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьКакToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ закрытьToolStripMenuItem;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новыйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьКакToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->закрытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->решениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->файлToolStripMenuItem,
					this->решениеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(748, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->новыйToolStripMenuItem,
					this->открытьToolStripMenuItem, this->сохранитьToolStripMenuItem, this->сохранитьКакToolStripMenuItem, this->закрытьToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// новыйToolStripMenuItem
			// 
			this->новыйToolStripMenuItem->Name = L"новыйToolStripMenuItem";
			this->новыйToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->новыйToolStripMenuItem->Text = L"Новый";
			this->новыйToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::новыйToolStripMenuItem_Click);
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripMenuItem_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripMenuItem_Click);
			// 
			// сохранитьКакToolStripMenuItem
			// 
			this->сохранитьКакToolStripMenuItem->Name = L"сохранитьКакToolStripMenuItem";
			this->сохранитьКакToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->сохранитьКакToolStripMenuItem->Text = L"Сохранить как...";
			this->сохранитьКакToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьКакToolStripMenuItem_Click);
			// 
			// закрытьToolStripMenuItem
			// 
			this->закрытьToolStripMenuItem->Name = L"закрытьToolStripMenuItem";
			this->закрытьToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->закрытьToolStripMenuItem->Text = L"Закрыть";
			this->закрытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::закрытьToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(0, 27);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(748, 412);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripProgressBar1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 442);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(748, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 22);
			// 
			// решениеToolStripMenuItem
			// 
			this->решениеToolStripMenuItem->Name = L"решениеToolStripMenuItem";
			this->решениеToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->решениеToolStripMenuItem->Text = L"Решение";
			this->решениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::решениеToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 467);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void новыйToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FileN = ""; // очищение имени файла
		richTextBox1->Clear(); // очищение текстового поля
		toolStripProgressBar1->Value = 0; // прогресс бар в 0
	}
	private: System::Void закрытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit(); // закрытие главного окна
	}
	private: System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->Filter = "Rtf files(*.rtf)|*.rtf|Txt files(*.txt)|*.txt"; //фильтры выбора файлов
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) // если нажата кнопка ок в открывшимся окне выбора
		{
			FileN = openFileDialog1->FileName; // получение имени
			FileE = openFileDialog1->FileName->Substring(openFileDialog1->FileName->Length - 3, 3); // получение расширения
			if ((FileE == "rtf") || (FileE == "Rtf") || (FileE == "RTF")) // если *.rtf
			{
				richTextBox1->LoadFile(FileN); // загрузка данных в текстовое поле
			}
			if ((FileE == "txt") || (FileE == "Txt") || (FileE == "TXT")) // если *.rtf
			{
				FileNameIn = (const char*)(Marshal::StringToHGlobalAnsi(FileN)).ToPointer(); // копирование имени файла в формате ANSI
				FileStreamInput.open(FileNameIn, std::ios::in); // открытие потока для чтения
				while (!FileStreamInput.eof()) // цикл до физического конца файла
				{
					std::getline(FileStreamInput, BufferString); // получение строки из потока
					LineS = gcnew String(BufferString.c_str()); // преобразование в String
					richTextBox1->Text = richTextBox1->Text + " " + LineS + "\n"; // загрузка строки в поле
				}
				FileStreamInput.close(); // закрытие потока чтения файла
				Marshal::FreeHGlobal(IntPtr((void*)FileNameIn)); // освобождение памяти от преобразования строки
			}
		}
	}
	private: System::Void сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		toolStripProgressBar1->Value = 0; // установка значения прогресс бара
		if (FileN == "") // если нет имкени файла
		{
			saveFileDialog1->Filter = "Rtf files(*.rtf)|*.rtf|Txt files(*.txt)|*.txt";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (saveFileDialog1->FilterIndex == 1) // если rtf
				{
					FileN = saveFileDialog1->FileName;
					richTextBox1->SaveFile(FileN); // сохранение файла с необходимым именем
				}
				if (saveFileDialog1->FilterIndex == 2) // если txt
				{
					FileN = saveFileDialog1->FileName;
					FileNameIn = (const char*)(Marshal::StringToHGlobalAnsi(FileN)).ToPointer();
					FileStreamOutput.open(FileNameIn, std::ios::out); // открытие потока записи
					i = 0;
					while (i < richTextBox1->Lines->Length) // до тех пор пока не кончились строки в поле
					{
						LineS = gcnew String(richTextBox1->Lines[i] + "\n"); // занесение символов в строку
						BufferChar = new char[LineS->Length]; // созданеие массива символов
						i++;
						BufferChar = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS);
						FileStreamOutput.write(BufferChar, LineS->Length); // вывод массива символов в поток
						Marshal::FreeHGlobal(IntPtr((void*)BufferChar)); // освобождение памяти
					}
					FileStreamOutput.close(); // закрытие потока
					Marshal::FreeHGlobal(IntPtr((void*)FileNameIn));
				}
			}
			else
			{
				if ((FileE == "rtf") || (FileE == "Rtf") || (FileE == "RTF"))
				{
					richTextBox1->SaveFile(FileN);
				}
				if ((FileE == "txt") || (FileE == "Txt") || (FileE == "TXT"))
				{
					FileNameIn = (const char*)(Marshal::StringToHGlobalAnsi(FileN)).ToPointer(); // копирование строки в формате ANSI
					FileStreamOutput.open(FileNameIn, std::ios::out); // открытие потока
					i = 0;
					while (i < richTextBox1->Lines->Length)
					{
						LineS = gcnew String(richTextBox1->Lines[i] + "\n");
						i++;
						BufferChar = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS);
						FileStreamOutput.write(BufferChar, LineS->Length);
						Marshal::FreeHGlobal(IntPtr((void*)BufferChar));
					}
					Marshal::FreeHGlobal(IntPtr((void*)FileNameIn));
				};
			}

		}
		toolStripProgressBar1->Value = 100;
	};
	private: System::Void сохранитьКакToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		toolStripProgressBar1->Value = 0;
		saveFileDialog1->Filter = "Rtf files(*.rtf)|*.rtf|Txt files(*.txt)|*.txt";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (saveFileDialog1->FilterIndex == 1)
			{
				FileN = saveFileDialog1->FileName;
				richTextBox1->SaveFile(FileN);
			}
			if (saveFileDialog1->FilterIndex == 2)
			{
				FileN = saveFileDialog1->FileName;
				FileNameIn = (const char*)(Marshal::StringToHGlobalAnsi(FileN)).ToPointer();
				FileStreamOutput.open(FileNameIn, std::ios::out);
				i = 0;
				while (i < richTextBox1->Lines->Length)
				{
					LineS = gcnew String(richTextBox1->Lines[i] + "\n");
					BufferChar = new char[LineS->Length];
					i++;
					BufferChar = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS);
					FileStreamOutput.write(BufferChar, LineS->Length);
					Marshal::FreeHGlobal(IntPtr((void*)BufferChar));
				}
				FileStreamOutput.close();
				Marshal::FreeHGlobal(IntPtr((void*)FileNameIn));
			}
		}
		toolStripProgressBar1->Value = 100;
	}
	private: System::Void решениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Mf1->Show();
	}
	};
};