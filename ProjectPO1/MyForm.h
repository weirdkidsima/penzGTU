#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "MyForm1.h"

namespace ProjectPO1 {

	using namespace std; // ������������ ��� ����������� ����������
	using namespace::System::Runtime::InteropServices; // ��� ��������� COM - �������������� � �������������� ������ �� ����������� ������ � ������ ��� �������� � �������� ������
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::ifstream FileStreamInput; // ������� �����
	std::ofstream FileStreamOutput; // �������� �����
	std::string BufferString; // ���������� ��� ��������� ������ �� ��������
	const char* FileNameIn; // ���������� ������ ��� ����� �����
	char* BufferChar; // ���������� ������ ��� �����
	int i; // ������� �����

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	public:
		MyForm1^ Mf1 = gcnew MyForm1;

		String^ FileN = ""; // ��� �����
		String^ FileE = ""; // ���������� �����
		String^ LineS = "";
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar1;
	public:
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;


	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(748, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->�����ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->���������ToolStripMenuItem, this->������������ToolStripMenuItem, this->�������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������ToolStripMenuItem_Click);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->������������ToolStripMenuItem->Text = L"��������� ���...";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
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
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
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
	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		FileN = ""; // �������� ����� �����
		richTextBox1->Clear(); // �������� ���������� ����
		toolStripProgressBar1->Value = 0; // �������� ��� � 0
	}
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit(); // �������� �������� ����
	}
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->Filter = "Rtf files(*.rtf)|*.rtf|Txt files(*.txt)|*.txt"; //������� ������ ������
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) // ���� ������ ������ �� � ����������� ���� ������
		{
			FileN = openFileDialog1->FileName; // ��������� �����
			FileE = openFileDialog1->FileName->Substring(openFileDialog1->FileName->Length - 3, 3); // ��������� ����������
			if ((FileE == "rtf") || (FileE == "Rtf") || (FileE == "RTF")) // ���� *.rtf
			{
				richTextBox1->LoadFile(FileN); // �������� ������ � ��������� ����
			}
			if ((FileE == "txt") || (FileE == "Txt") || (FileE == "TXT")) // ���� *.rtf
			{
				FileNameIn = (const char*)(Marshal::StringToHGlobalAnsi(FileN)).ToPointer(); // ����������� ����� ����� � ������� ANSI
				FileStreamInput.open(FileNameIn, std::ios::in); // �������� ������ ��� ������
				while (!FileStreamInput.eof()) // ���� �� ����������� ����� �����
				{
					std::getline(FileStreamInput, BufferString); // ��������� ������ �� ������
					LineS = gcnew String(BufferString.c_str()); // �������������� � String
					richTextBox1->Text = richTextBox1->Text + " " + LineS + "\n"; // �������� ������ � ����
				}
				FileStreamInput.close(); // �������� ������ ������ �����
				Marshal::FreeHGlobal(IntPtr((void*)FileNameIn)); // ������������ ������ �� �������������� ������
			}
		}
	}
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		toolStripProgressBar1->Value = 0; // ��������� �������� �������� ����
		if (FileN == "") // ���� ��� ������ �����
		{
			saveFileDialog1->Filter = "Rtf files(*.rtf)|*.rtf|Txt files(*.txt)|*.txt";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (saveFileDialog1->FilterIndex == 1) // ���� rtf
				{
					FileN = saveFileDialog1->FileName;
					richTextBox1->SaveFile(FileN); // ���������� ����� � ����������� ������
				}
				if (saveFileDialog1->FilterIndex == 2) // ���� txt
				{
					FileN = saveFileDialog1->FileName;
					FileNameIn = (const char*)(Marshal::StringToHGlobalAnsi(FileN)).ToPointer();
					FileStreamOutput.open(FileNameIn, std::ios::out); // �������� ������ ������
					i = 0;
					while (i < richTextBox1->Lines->Length) // �� ��� ��� ���� �� ��������� ������ � ����
					{
						LineS = gcnew String(richTextBox1->Lines[i] + "\n"); // ��������� �������� � ������
						BufferChar = new char[LineS->Length]; // ��������� ������� ��������
						i++;
						BufferChar = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS);
						FileStreamOutput.write(BufferChar, LineS->Length); // ����� ������� �������� � �����
						Marshal::FreeHGlobal(IntPtr((void*)BufferChar)); // ������������ ������
					}
					FileStreamOutput.close(); // �������� ������
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
					FileNameIn = (const char*)(Marshal::StringToHGlobalAnsi(FileN)).ToPointer(); // ����������� ������ � ������� ANSI
					FileStreamOutput.open(FileNameIn, std::ios::out); // �������� ������
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
	private: System::Void ������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Mf1->Show();
	}
	};
};