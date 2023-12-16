#pragma once
#include "math.h" // Модуль для работы с математическими функциями
#include "time.h" // Модуль для работы с временем и датой
#include <fstream>
#include <iostream>
#include <string>
namespace ProjectPO1
{
	using namespace System::Threading; // Объявление пространства имён для работы с потока-ми
	using namespace std; // Пространство имён стандартной библиотеки
	using namespace System::Runtime::InteropServices; // Пространство имён для поддержки СОМвзаимодействия и преобразования данных из формата оперативной памяти в формат для хранения и передачи данных(маршаллинг)
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public delegate void ThreadCallBack(int cNN, double** cZT);
	public ref class ThreadWithState
	{
	private: int sNN; // Размерность массивов
	private: double* sXT, // Массив аргументов X
		* sYT, // Массив аргументов Y
		** sZT; // Массив значений функций
		   // Конструктор класса ThreadWithState
	private: ThreadCallBack^ tcall;
	public: ThreadWithState(int zNN, double* zXT, double* zYT, ThreadCallBack^ tcallD)
	{
		sNN = zNN; sXT = zXT; sYT = zYT; // Присвоение значений переменным класса Thread-WithState
		tcall = tcallD; // Создание объекта tcall из объекта tcallD
		sZT = new double* [sNN]; // Выделение памяти для указателей
		int I1; // Счётчики циклов
		// Цикл для формирования массива данных
		for (I1 = 0; I1 <= sNN - 1; I1++) // Формирование массива аргументов
		{
			sZT[I1] = new double[sNN]; // Выделение памяти для второй размерности зна-чений функции
		} // Конец цикла for (I1 = 0; I1 <= NN - 1; I1++)
	};
		  // Вычисление значений функции (будет работать в потоке)
	public: void ThreadDoWork()
	{
		int I2, J2; // Счётчики циклов
		String^ FileN1 = "", // Имя файла данных
			^ LineS1 = ""; // Строка из файла данных
		const char* FileNameIn1; // Символьный массив для имени файла
		char* BufferChar1; // Символьный массив для строк
		// Цикл для вычисления функции
		for (I2 = 0; I2 <= sNN - 1; I2++) // Внешний цикл по строкам массива tZT
		{
			for (J2 = 0; J2 <= sNN - 1; J2++) // Внутренний цикл по элементам строк массива tZT
			{
				sZT[I2][J2] = 0.5 * (cos(2 * pow((sXT[I2] / 3), 3)) - log10(sin(sYT[J2])) + 1);
			} // Конец цикла for (J2 = 1; J2 <= tNN - 1; J2++)
		} // Конец цикла for (I2 = 1; I2 <= tNN - 1; I2++)
		std::ofstream FileStreamOut1; // Выходной поток для файла
		std::string BufferString1; // Переменная BufferString1 для работы со строками
		FileN1 = "E://tAA.txt"; // Извлечение имени файла данных
		FileNameIn1 = (const char*)(Marshal::StringToHGlobalAnsi(FileN1)).ToPointer(); // Копирование строки FileN1 в FileNameIn1 в формате ANSI
		FileStreamOut1.open(FileNameIn1, std::ios::out); // Открытие потока FileStreamOut1 для вывода в файл
		// Цикл формирования строк со значениями функции sZT
		for (I2 = 0; I2 <= sNN - 1; I2++) // Внешний цикл по строкам массива sZT
		{
			LineS1 = gcnew String(""); // Создание строки LineS1
			for (J2 = 0; J2 <= sNN - 1; J2++) // Внутренний цикл по элементам строк массива sZT
			{
				if (J2 < sNN - 1) // Для всех элементов массива sZT кроме последне-го
				{
					LineS1 = LineS1+ sXT[I2].ToString() + ":X " + sYT[J2].ToString() + ":Y " + sZT[I2][J2].ToString() + "; "; // Формиро-вание строки со значениями функции sZT
				} // Конец условия if (J2 < sNN - 1)
				if (J2 == sNN - 1) // Для последнего элемента массива sZT
				{
					LineS1 = LineS1 + sXT[I2].ToString() + ":X " + sYT[J2].ToString() + ":Y " + sZT[I2][J2].ToString() + "; "+ sZT[I2][J2].ToString() + "; " + " I2: " + I2.ToString() + " J2: " + J2.ToString() + ";\n"; // Формирование строки со значениями функции sZT
				} // Конец условия if (J2 == sNN - 1)
			} // Конец цикла for (J2 = 0; J2 <= tNN - 1; J2++)
			BufferChar1 = new char[LineS1->Length]; // Создание массива символов Buff-erChar1
			BufferChar1 = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS1); // Пре-образование строки LineS1 в массив символов BufferChar1
			FileStreamOut1.write(BufferChar1, LineS1->Length); // Вывод массива симво-лов BufferChar1 в поток
			Marshal::FreeHGlobal(IntPtr((void*)BufferChar1)); // Освобождение памяти, выделенной для преобразования строки
		} // Конец цикла for (I2 = 0; I2 <= tNN - 1; I2++)
		FileStreamOut1.close(); // Закрытие потока FileStreamOut1 для вывода в файл
		tcall(sNN, sZT);
		Marshal::FreeHGlobal(IntPtr((void*)FileNameIn1)); // Освобождение памяти, выде-ленной для преобразования строки
		for (I2 = 0; I2 <= sNN - 1; I2++) // Цикл для освобождения памяти
		{
			delete[]sZT[I2]; // Освобождение памяти для указателей
		} // Конец цикла for (I1 = 0; I1 <= NN - 1; I1++)
		delete[]sZT; // Освобождение памяти для первой размерности значений функции
	}
	};
} // Конец модуля MyThread.h
