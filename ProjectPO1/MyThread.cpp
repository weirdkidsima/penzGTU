#include "MyThread.h" // Заголовочный модуль класса поток Содержимое модуля MyThread.h:
#pragma once
#include "math.h" // Модуль для работы с математическими функциями
#include "time.h" // Модуль для работы с временем и датой
#include <fstream>
#include <iostream>
#include <string>
namespace ProjectPO1
{
	using namespace System::Threading; // Объявление пространства имён для работы с потоками
	using namespace std; // Пространство имён стандартной библиотеки
	using namespace System::Runtime::InteropServices;// Пространство имён для поддержки СОМ взаимодействия и преобразования данных из формата оперативной памяти в формат для хранения и передачи данных(маршаллинг)
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
}