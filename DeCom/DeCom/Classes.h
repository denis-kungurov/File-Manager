#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

namespace DeCom
{
    static class ActionHandlers{
    public:
        static void DoubleClick_Action (ListView^ MyList, TextBox^ textBox);
        static void CopyClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
        static void DeleteClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
        static void MoveClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
    };
    static class RenderActions{
    public:
        static void RenderFileList(ListView^ listView, TextBox^ tb, String^ defaultPath = "C:/");
        static void Determine_Size(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
    };
    static class SupportFunctions{
    public:
        static void CopyDir(String^ FromDir, String^ ToDir);
        static double SizeOfDirectory(System::IO::DirectoryInfo ^dir);
    };
}