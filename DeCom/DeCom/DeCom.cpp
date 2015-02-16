// DeCom.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Form1.h"

using namespace std;
using namespace DeCom;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    // Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false); 

    // Создание главного окна и его запуск
    Application::Run(gcnew Form1());

    /* DeCom::Form1 form;*/

    return 0;
}
