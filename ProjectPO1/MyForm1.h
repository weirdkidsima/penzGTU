#pragma once
#include "math.h"
#include "time.h"
#include "fstream"
#include "iostream"
#include "string"
#include "MyThread.h"

using namespace System::Threading; // ���������� ������������ ��� ��� ������ � ��������
using namespace std; // ������������ ��� ����������� ����������
using namespace System::Runtime::InteropServices; // ������������ ��� ��� ��������� ���-�������������� � �������������� ������ �� ������� ����������� ������ � ������ ��� �������� � �������� ������(����������)

namespace ProjectPO1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//

			BT = System::DateTime(); // �������� ������� ����� ������
			FT = System::DateTime(); // �������� ������� ����� �����
		}
	public:
		double	MaxX, // ������������ �������� ��������� �
			MinX, // ����������� �������� ��������� X
			MaxY, // ������������ �������� ��������� Y
			MinY, // ����������� �������� ��������� Y
			ShagX, // ��� ��������� ��������� X
			ShagY; // ��� ��������� ��������� Y
		int		NN, // ����������� �����
			I1, // ������� �����
			J1; // ������� �����
		double* PXT, // ������ ���������� X
			* PYT; // ������ �������� �������
		static double** PZT; // ������ �������� �������
		DateTime BT, // ����� ������ ��������
			FT; // ����� ��������� ��������
		TimeSpan STF; // ������������ ��������
		String^ FileN1,
			^ LineS1;
		const char* FileNameIn1;
		char* BufferChar1;
		ThreadWithState^ tstat; // ���������� ������� tstat ������ ThreadWithState
		Thread^ thred; // ���������� ������� thred ������ Thread

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

	public: void DoWork(int tNN, double* tXT, double* tYT, double** tZT)
	{
		int I2, J2; // �������� ������
		// ���� ��� ���������� �������
		for (I2 = 0; I2 <= tNN - 1; I2++) // ������� ���� �� ������� ������� �������� ������� tZT
		{
			for (J2 = 0; J2 <= tNN - 1; J2++) // ���������� ���� �� ��������� ����� ������� �������� ������� tZT
			{
				PZT[I2][J2] = 0.5 * (cos(2 * pow((PXT[I2] / 3), 3)) - log10(sin(PYT[J2])) + 1);
				if (Convert::ToInt32(I2) > (this->progressBar1->Value + this->progressBar1->Step))
				{
					// ���� ���������� ����� ����� ������ �������� ������ �������-��
					this->progressBar1->Value += this->progressBar1->Step; // �������-����� �������� ������ ���������
					this->progressBar1->Refresh(); // ���������� �������� ������ ���-������
					FT = DateTime::Now; // ���������� �������� �������� �������
					TimeSpan STF = FT - BT; // ���������� ��������� �������
					this->label12->Text = STF.ToString(); // ����� �������� ��������� ������� � ����� label12
					this->label12->Refresh(); // ���������� ����� label12
				} // ����� ������� if (Convert::ToInt32(I1) > (this->progressBar1->Value + this->progressBar1->Step))
			} // ����� ����� for (J2 = 1; J2 <= tNN - 1; J2++)
		} // ����� ����� for (I2 = 1; I2 <= tNN - 1; I2++)
		std::ofstream FileStreamOut1; // �������� ����� ��� �����
		std::string BufferString1; // ���������� BufferString ��� ������ �� ��������
		FileN1 = "E://AA.txt"; // ���������� ����� ����� ������
		FileNameIn1 = (const char*)(Marshal::StringToHGlobalAnsi(FileN1)).ToPointer(); // ����������� ������ FileN1 � FileNameIn1 � ������� ANSI
		FileStreamOut1.open(FileNameIn1, std::ios::out); // �������� ������ FileStreamOut1 ��� ������ � ����
		for (I2 = 0; I2 <= tNN - 1; I2++) // ������� ���� �� ������� ������� tZT
		{
			LineS1 = gcnew String(""); // �������� ������ LineS1
			for (J2 = 0; J2 <= tNN - 1; J2++) // ���������� ���� �� ��������� ����� ������� tZT
			{
				if (J2 < tNN - 1) // ��� ���� ��������� ������� tZT ����� ����������
				{
					LineS1 = LineS1 + tZT[I2][J2].ToString() + "; " + " X: " + PXT[I2].ToString() + " Y:" + PYT[J2].ToString() + ";\n";
				} // ����� ������� if (J2 < tNN - 1)
				if (J2 == tNN - 1) // ��� ���������� �������� ������� tZT
				{
					LineS1 = LineS1 + tZT[I2][J2].ToString() + "; " + " X: " + PXT[I2].ToString() + " Y:" + PYT[J2].ToString() + ";\n";
				} // ����� ������� if (J2 == tNN - 1)
			} // ����� ����� for (J2 = 1; J2 <= tNN - 1; J2++)
			BufferChar1 = new char[LineS1->Length]; // �������� ������� �������� BufferChar1
			BufferChar1 = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS1); // ��������� ����������� ������ LineS1 � ������ �������� BufferChar1
			FileStreamOut1.write(BufferChar1, LineS1->Length); // ����� ������� �������� Buff-erChar1 � �����
			Marshal::FreeHGlobal(IntPtr((void*)BufferChar1)); // ������������ ������, �������-��� ��� �������������� ������
		} // ����� ����� for (I2 = 1; I2 <= tNN - 1; I2++)
		FileStreamOut1.close(); // �������� ������ FileStreamOut1 ��� ������ � ����
		Marshal::FreeHGlobal(IntPtr((void*)FileNameIn1)); // ������������ ������, ���������� ��� �������������� ������
	}
	public: static void tcallRes(int cNN, double** cZT)
	{
		int I2, J2; // �������� ������
		String^ FileN2 = "", // ��� ����� ������
			^ LineS2 = ""; // ������ �� ����� ������
		const char* FileNameIn2; // ���������� ������ ��� ����� �����
		char* BufferChar2; // ���������� ������ ��� �����
		std::ofstream FileStreamOut2; // �������� ����� ��� �����
		std::string BufferString2; // ���������� BufferString ��� ������ �� ��������
		FileN2 = "E://bAA.txt"; // ���������� ����� ����� ������
		FileNameIn2 = (const char*)(Marshal::StringToHGlobalAnsi(FileN2)).ToPointer(); // ����������� ������ FileN1 � FileNameIn1 � ������� ANSI
		FileStreamOut2.open(FileNameIn2, std::ios::out); // �������� ������ FileStreamOut1 ��� ������ � ����
		for (I2 = 0; I2 <= cNN - 1; I2++) // ������� ���� �� ������� ������� �ZT
		{
			LineS2 = gcnew String(""); // �������� ������ LineS1
			for (J2 = 0; J2 <= cNN - 1; J2++) // ���������� ���� �� ��������� ����� ������� �ZT
			{
				if (J2 < cNN - 1) // ��� ���� ��������� ������� �ZT ����� ����������
				{
					LineS2 = LineS2 + cZT[I2][J2].ToString() + "; "; // ������������ ����-�� �� ���������� ������� �ZT
				} // ����� ������� if (J2 < �NN - 1)
				if (J2 == cNN - 1) // ��� ���������� �������� ������� �ZT
				{
					LineS2 = LineS2 + cZT[I2][J2].ToString() + "; " + " I2: " + I2.ToString() + " J2: " + J2.ToString() + ";\n"; // ������������ ������ �� ���������� ������� �ZT
				} // ����� ������� if (J2 == �NN - 1)
			} // ����� ����� for (J2 = 0; J2 <= �NN - 1; J2++)
			BufferChar2 = new char[LineS2->Length]; // �������� ������� �������� BufferChar2
			BufferChar2 = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS2); // �������������� ������ LineS1 � ������ �������� BufferChar2
			FileStreamOut2.write(BufferChar2, LineS2->Length); // ����� ������� �������� Buff-erChar2 � �����
			Marshal::FreeHGlobal(IntPtr((void*)BufferChar2)); // ������������ ������, �������-��� ��� �������������� ������
		} // ����� ����� for (I2 = 0; I2 <= �NN - 1; I2++)
		FileStreamOut2.close(); // �������� ������ FileStreamOut1 ��� ������ � ����
		Marshal::FreeHGlobal(IntPtr((void*)FileNameIn2)); // ������������ ������, ���������� ��� �������������� ������
		for (I2 = 0; I2 <= cNN - 1; I2++) // ������� ���� �� ������� ������� �ZT
		{
			for (J2 = 0; J2 <= cNN - 1; J2++) // ���������� ���� �� ��������� ����� ������� �ZT
			{
				MyForm1::PZT[I2][J2] = cZT[I2][J2]; // ����������� ������� cZT � ������ PZT
			} // ����� ����� for (J2 = 0; J2 <= �NN - 1; J2++)
		} // ����� ����� for (I2 = 0; I2 <= �NN - 1; I2++)
	}
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(22, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(22, 111);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"1";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(154, 29);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"5";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(154, 111);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"10";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(310, 29);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 4;
			this->textBox5->Text = L"10";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(310, 111);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 5;
			this->textBox6->Text = L"4";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 95);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"��������� �������� Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"��������� �������� X";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(151, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"�������� �������� X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(151, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"�������� �������� Y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(307, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(128, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"����������� ��������";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(307, 95);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(110, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"���������� �������";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(513, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"������";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(513, 36);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(595, 13);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"���������";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(595, 36);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(670, 13);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 13);
			this->label11->TabIndex = 16;
			this->label11->Text = L"�����������������";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(670, 36);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(788, 13);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 13);
			this->label13->TabIndex = 18;
			this->label13->Text = L"���������� �������";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(788, 36);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(41, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"0";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(496, 111);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(333, 23);
			this->progressBar1->TabIndex = 20;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(254, 187);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 21;
			this->button1->Text = L"������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(561, 187);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 22;
			this->button2->Text = L"�������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(933, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		BT = DateTime::Now; // ���������� �������� �������� �������
		this->label8->Text = BT.ToLongTimeString(); // ����� �������� ������� � ����� label8
		this->label8->Refresh(); // ���������� ����� label8
		MaxX = Convert::ToDouble(this->textBox3->Text); // ���� ������������� �������� �
		MinX = Convert::ToDouble(this->textBox1->Text); // ���� ������������ �������� �
		MaxY = Convert::ToDouble(this->textBox4->Text); // ���� ������������� �������� Y
		MinY = Convert::ToDouble(this->textBox2->Text); // ���� ������������ �������� Y
		NN = Convert::ToInt32(this->textBox5->Text); // ���� ����������� ��������
		this->progressBar1->Maximum = Convert::ToInt32(NN); // ������������ ������������� ���-����� ������ ���������
		this->progressBar1->Step = Convert::ToInt32(NN / 100); // ������������ ���� �������� ��-���� ���������
		this->progressBar1->Minimum = 0; // ������������ ������������ �������� ������ ���-������
		this->progressBar1->Value = 0; // ��������� �������� �������� ������ ��������� � 0
		PXT = new double[NN]; // ��������� ������ ��� ���������� �������
		PYT = new double[NN]; // ��������� ������ ��� �������� �������
		PZT = new double* [NN]; // ��������� ������ ��� ���������� ������� �������� �������
		ShagX = (MaxX - MinX) / (NN - 1); // ������������ ���� ��������� ��������� �
		ShagY = (MaxY - MinY) / (NN - 1); // ������������ ���� ��������� ��������� Y
		PXT[0] = MinX; // ������ �������� � ������� ���������� �
		PYT[0] = MinY; // ������ �������� � ������� ���������� Y
		// ���� ��� ������������ ������� ���������� �������
		for (I1 = 0; I1 <= NN - 1; I1++) // ������������ ������� ����������
		{
			if (I1 > 0) // ��� ��������� �������� ������� �� �������
			{
				PXT[I1] = PXT[I1 - 1] + ShagX; // ������������ ������� ���������� �
				PYT[I1] = PYT[I1 - 1] + ShagY; // ������������ ������� ���������� Y
			}
			PZT[I1] = new double[NN]; // ��������� ������ ��� �������� ��������� ����� ���-����� �������
			if (Convert::ToInt32(I1) > (this->progressBar1->Value + this->progressBar1->Step))
			{
				// ���� ���������� ����� ����� ������ �������� ������ ���������
				this->progressBar1->Value += this->progressBar1->Step; // ������������ �������� ������ ���������
				this->progressBar1->Refresh(); // ���������� �������� ������ ���������
				FT = DateTime::Now; // ���������� �������� �������� �������
				TimeSpan STF = FT - BT; // ���������� ��������� �������
				this->label12->Text = STF.ToString(); // ����� �������� ��������� ������� � ����� label12
				this->label12->Refresh(); // ���������� ����� label12
			} // ����� ������� if (Convert::ToInt32(I1) > (this->progressBar1->Value + this->progressBar1->Step))
		}
		this->progressBar1->Value = this->progressBar1->Maximum; // ������������ �������� ������ ���������
		tstat = gcnew ThreadWithState(NN, PXT, PYT, gcnew ThreadCallBack(tcallRes)); // �������� ������� tstat ������ ThreadWithState � �������� � ����������� ����������(NN, PXT, PYT)
		thred = gcnew Thread(gcnew ThreadStart(tstat, &ThreadWithState::ThreadDoWork)); // �������� ������� thred ������ Thread � ���������� � ���� ������ ThreadStart � ��������� ������� tstat � ������� ������� ThreadDoWork
		thred->Start(); // ������ ������ thred
		thred->Join(); // ������������ �������� ������ ��������� � �������� ���������� ������ thred
		delete[]PXT; // ������������ ������ ��� ���������� X
		delete[]PYT; // ������������ ������ ��� ���������� Y
		for (I1 = 0; I1 <= NN - 1; I1++)
		{
			delete[]PZT[I1];
		}
		delete[]PZT;
		FT = DateTime::Now; // ���������� �������� �������� �������
		this->label10->Text = FT.ToLongTimeString(); // ����� �������� ������� � ����� label10
		this->label10->Refresh(); // ���������� ����� label10
		TimeSpan STF = FT - BT; // ���������� ��������� �������
		this->label12->Text = STF.ToString(); // ����� �������� ��������� ������� � ����� label12
		this->label12->Refresh(); // ���������� ����� label12
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
