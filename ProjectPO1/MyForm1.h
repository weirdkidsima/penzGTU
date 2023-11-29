#pragma once

#include "math.h" //мат. функции
#include "time.h" // дата и время
#include <iostream>
#include <fstream>
#include <string>

namespace ProjectPO1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;//пространство имён стандартной библиотеки
	using namespace System::Runtime::InteropServices; /// Пространство имён для поддержки СОМвзаимодействия и преобразования данных из формата оперативной памяти в формат для хранения и передачи данных(маршаллинг)


	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			BT = System::DateTime(); // Создание объекта Время начала процесса класса DateTime
			FT = System::DateTime(); // Создание объекта Время окончания процесса класса DateTime
		}

	public:
		double MaxX, // Максимальное значение аргумента Х
				MinX, // Минимальное значение аргумента X
				MaxY, // Максимальное значение аргумента Y
				MinY, // Минимальное значение аргумента Y
				ShagX, // Шаг изменения аргумента X
				ShagY; // шаг изменения аргумента X
		int		NN, // Размерность цикла
				I1; // Счётчик цикла
		double *PXT, // Массив аргументов X
				**PZT, // массив значений функций
				*PYT; // Массив значений функции Y
		DateTime BT, // Время начала процесса
				FT; // Время окончания процесса
		TimeSpan STF; // Длительность процесса

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Начальное значение X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Начальное занчение Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(140, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Конечное значение X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(140, 61);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Конечное значение Y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(417, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Начало";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(501, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Окончание";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(595, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(111, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Продолжительность";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(261, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(128, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Размерность массивов";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(261, 61);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(110, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Количество потоков";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(417, 32);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(501, 32);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(721, 9);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(110, 13);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Количество потоков";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(595, 32);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(13, 13);
			this->label13->TabIndex = 12;
			this->label13->Text = L"0";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(766, 32);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(13, 13);
			this->label14->TabIndex = 13;
			this->label14->Text = L"0";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(119, 20);
			this->textBox1->TabIndex = 14;
			this->textBox1->Text = L"1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(15, 87);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(119, 20);
			this->textBox2->TabIndex = 15;
			this->textBox2->Text = L"5";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(143, 32);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(112, 20);
			this->textBox3->TabIndex = 16;
			this->textBox3->Text = L"1";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(143, 87);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(112, 20);
			this->textBox4->TabIndex = 17;
			this->textBox4->Text = L"10";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(261, 32);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(128, 20);
			this->textBox5->TabIndex = 18;
			this->textBox5->Text = L"10";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(264, 87);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(107, 20);
			this->textBox6->TabIndex = 19;
			this->textBox6->Text = L"4";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(420, 87);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(286, 23);
			this->progressBar1->TabIndex = 20;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(153, 159);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Начать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(533, 159);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(834, 194);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
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
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		BT = DateTime::Now; // Извлечение текущего значения времени
		this->label10->Text = BT.ToLongTimeString(); // Вывод значения времени в метку label10
		this->label10->Refresh(); // Обновление метки label10
		// Формирование значений аргументов функции
		MaxX = Convert::ToDouble(this->textBox3->Text); // Ввод максимального значения Х
			MinX = Convert::ToDouble(this->textBox1->Text); // Ввод минимального значения Х
			MaxY = Convert::ToDouble(this->textBox4->Text); // Ввод максимального значения Y
			MinY = Convert::ToDouble(this->textBox2->Text); // Ввод минимального значения Y
			NN = Convert::ToInt32(this->textBox5->Text); // Ввод размерности массивов
			this->progressBar1->Maximum = Convert::ToInt32(NN); // Формирование максимального значения полосы прогресса
			this->progressBar1->Step = Convert::ToInt32(NN / 100);

		// Формирование шага значения полосы прогресса
			this->progressBar1->Minimum = 0; // Формирование минимального значения полосы прогресса
			this->progressBar1->Value = 0; // Установка текущего значения полосы прогресса в 0
			PXT = new double[NN]; // Выделение памяти для аргументов функции
			PYT = new double[NN]; // Выделение памяти для значений функции
			PZT = new double* [NN]; // выделение памяти для массива значений функций
			ShagX = (MaxX - MinX) / (NN - 1);// Формирование шага изменения аргумента Х
			ShagY = (MaxY - MinY) / (NN - 1); // формирование шага изменений функции Y
			PXT[0] = MinX; // Первое значение в массиве аргументов Х
		// Цикл для формирования массива аргументов функции
		I1 = 1; // Начальное значение счётчика цикла
		while (I1 < NN - 1) // Цикл по массиву аргументов
		{
			PXT[I1] = PXT[I1 - 1] + ShagX; // Формирование элементов массива аргументов
				if (Convert::ToInt32(I1) > (this->progressBar1->Value + this -> progressBar1->Step))
				{
					// Если количество шагов цикла больше значения полосы прогресса
						this->progressBar1->Value += this->progressBar1->Step;
					// Формирование значения полосы прогресса
					this->progressBar1->Refresh(); // Обновление значения полосы прогресса
						FT = DateTime::Now; // Извлечение текущего значения времени
						TimeSpan STF = FT - BT; // Вычисление интервала времени
						this->label11->Text = STF.ToString(); // Вывод значения интервала времени в метку label11
						this->label11->Refresh(); // Обновление метки label11
				} // Конец условия if (Convert::ToInt32(I1) > (this-> progressBar1->Value + this->progressBar1->Step))
				I1++; // Наращивание значения счётчика цикла
		} // Конец цикла while (I1 < NN - 1)
		this->progressBar1->Value = this->progressBar1->Maximum;
		// Формирование значения полосы прогресса
		// Цикл для вычисления функции
		this->progressBar1->Value = 0; // Установка текущего значения полосы прогресса в 0
			this->progressBar1->Refresh(); // Обновление значения полосы прогресса
			I1 = 0; // Начальное значение счётчика цикла
		while (I1 <= NN - 1) // Цикл по массиву аргументов
		{
			PYT[I1] = 0.5 * (cos(2 * pow((PXT[I1]/3),3)) - log10(sin(PXT[I1]))+1);
			if (Convert::ToInt32(I1) > (this->progressBar1->Value + this -> progressBar1->Step))
			{
				// Если количество шагов цикла больше значения полосы прогресса
					this->progressBar1->Value += this->progressBar1->Step;
				// Формирование значения полосы прогресса
				this->progressBar1->Refresh(); // Обновление значения полосы прогресса
					FT = DateTime::Now; // Извлечение текущего значения времени
					TimeSpan STF = FT - BT; // Вычисление интервала времени
					this->label11->Text = STF.ToString(); // Вывод значения интервала времени в метку label11
					this->label11->Refresh(); // Обновление метки label11
			} // Конец условия if (Convert::ToInt32(I1) > (this-> progressBar1->Value + this->progressBar1->Step))
			I1++; // Наращивание значения счётчика цикла
		} // Конец цикла while (I1 < NN - 1)

	FT = DateTime::Now; // Извлечение текущего значения времени
		this->label11->Text = FT.ToLongTimeString(); // Вывод значения времени в метку label11
		this->label11->Refresh(); // Обновление метки label11
	TimeSpan STF = FT - BT; // Вычисление интервала времени
		this->label13->Text = STF.ToString(); // Вывод значения интервала времени в метку label13
		this->label13->Refresh(); // Обновление метки label13
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}