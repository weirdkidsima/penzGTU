#pragma once
#include "math.h" // ������ ��� ������ � ��������������� ���������
#include "time.h" // ������ ��� ������ � �������� � �����
#include <fstream>
#include <iostream>
#include <string>
namespace ProjectPO1
{
	using namespace System::Threading; // ���������� ������������ ��� ��� ������ � ������-��
	using namespace std; // ������������ ��� ����������� ����������
	using namespace System::Runtime::InteropServices; // ������������ ��� ��� ��������� ����������������� � �������������� ������ �� ������� ����������� ������ � ������ ��� �������� � �������� ������(����������)
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public delegate void ThreadCallBack(int cNN, double** cZT);
	public ref class ThreadWithState
	{
	private: int sNN; // ����������� ��������
	private: double* sXT, // ������ ���������� X
		* sYT, // ������ ���������� Y
		** sZT; // ������ �������� �������
		   // ����������� ������ ThreadWithState
	private: ThreadCallBack^ tcall;
	public: ThreadWithState(int zNN, double* zXT, double* zYT, ThreadCallBack^ tcallD)
	{
		sNN = zNN; sXT = zXT; sYT = zYT; // ���������� �������� ���������� ������ Thread-WithState
		tcall = tcallD; // �������� ������� tcall �� ������� tcallD
		sZT = new double* [sNN]; // ��������� ������ ��� ����������
		int I1; // �������� ������
		// ���� ��� ������������ ������� ������
		for (I1 = 0; I1 <= sNN - 1; I1++) // ������������ ������� ����������
		{
			sZT[I1] = new double[sNN]; // ��������� ������ ��� ������ ����������� ���-����� �������
		} // ����� ����� for (I1 = 0; I1 <= NN - 1; I1++)
	};
		  // ���������� �������� ������� (����� �������� � ������)
	public: void ThreadDoWork()
	{
		int I2, J2; // �������� ������
		String^ FileN1 = "", // ��� ����� ������
			^ LineS1 = ""; // ������ �� ����� ������
		const char* FileNameIn1; // ���������� ������ ��� ����� �����
		char* BufferChar1; // ���������� ������ ��� �����
		// ���� ��� ���������� �������
		for (I2 = 0; I2 <= sNN - 1; I2++) // ������� ���� �� ������� ������� tZT
		{
			for (J2 = 0; J2 <= sNN - 1; J2++) // ���������� ���� �� ��������� ����� ������� tZT
			{
				sZT[I2][J2] = 0.5 * (cos(2 * pow((sXT[I2] / 3), 3)) - log10(sin(sYT[J2])) + 1);
			} // ����� ����� for (J2 = 1; J2 <= tNN - 1; J2++)
		} // ����� ����� for (I2 = 1; I2 <= tNN - 1; I2++)
		std::ofstream FileStreamOut1; // �������� ����� ��� �����
		std::string BufferString1; // ���������� BufferString1 ��� ������ �� ��������
		FileN1 = "E://tAA.txt"; // ���������� ����� ����� ������
		FileNameIn1 = (const char*)(Marshal::StringToHGlobalAnsi(FileN1)).ToPointer(); // ����������� ������ FileN1 � FileNameIn1 � ������� ANSI
		FileStreamOut1.open(FileNameIn1, std::ios::out); // �������� ������ FileStreamOut1 ��� ������ � ����
		// ���� ������������ ����� �� ���������� ������� sZT
		for (I2 = 0; I2 <= sNN - 1; I2++) // ������� ���� �� ������� ������� sZT
		{
			LineS1 = gcnew String(""); // �������� ������ LineS1
			for (J2 = 0; J2 <= sNN - 1; J2++) // ���������� ���� �� ��������� ����� ������� sZT
			{
				if (J2 < sNN - 1) // ��� ���� ��������� ������� sZT ����� ��������-��
				{
					LineS1 = LineS1+ sXT[I2].ToString() + ":X " + sYT[J2].ToString() + ":Y " + sZT[I2][J2].ToString() + "; "; // �������-����� ������ �� ���������� ������� sZT
				} // ����� ������� if (J2 < sNN - 1)
				if (J2 == sNN - 1) // ��� ���������� �������� ������� sZT
				{
					LineS1 = LineS1 + sXT[I2].ToString() + ":X " + sYT[J2].ToString() + ":Y " + sZT[I2][J2].ToString() + "; "+ sZT[I2][J2].ToString() + "; " + " I2: " + I2.ToString() + " J2: " + J2.ToString() + ";\n"; // ������������ ������ �� ���������� ������� sZT
				} // ����� ������� if (J2 == sNN - 1)
			} // ����� ����� for (J2 = 0; J2 <= tNN - 1; J2++)
			BufferChar1 = new char[LineS1->Length]; // �������� ������� �������� Buff-erChar1
			BufferChar1 = (char*)(void*)Marshal::StringToHGlobalAnsi(LineS1); // ���-����������� ������ LineS1 � ������ �������� BufferChar1
			FileStreamOut1.write(BufferChar1, LineS1->Length); // ����� ������� �����-��� BufferChar1 � �����
			Marshal::FreeHGlobal(IntPtr((void*)BufferChar1)); // ������������ ������, ���������� ��� �������������� ������
		} // ����� ����� for (I2 = 0; I2 <= tNN - 1; I2++)
		FileStreamOut1.close(); // �������� ������ FileStreamOut1 ��� ������ � ����
		tcall(sNN, sZT);
		Marshal::FreeHGlobal(IntPtr((void*)FileNameIn1)); // ������������ ������, ����-������ ��� �������������� ������
		for (I2 = 0; I2 <= sNN - 1; I2++) // ���� ��� ������������ ������
		{
			delete[]sZT[I2]; // ������������ ������ ��� ����������
		} // ����� ����� for (I1 = 0; I1 <= NN - 1; I1++)
		delete[]sZT; // ������������ ������ ��� ������ ����������� �������� �������
	}
	};
} // ����� ������ MyThread.h
