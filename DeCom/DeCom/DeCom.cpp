// DeCom.cpp: ������� ���� �������.

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Form1.h"

using namespace std;
using namespace DeCom;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    // ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false); 

    // �������� �������� ���� � ��� ������
    Application::Run(gcnew Form1());

    /* DeCom::Form1 form;*/

    return 0;
}
