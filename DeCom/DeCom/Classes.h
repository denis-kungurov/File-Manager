#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Reflection;
using namespace MyLibrary;

namespace DeCom
{
	public ref class ObjectToPlugin
	{
	public:
		String ^Pathes = Directory::GetCurrentDirectory() + "\\" + "Plugins.txt";
		String ^Path;
		ListView^ MyList1;
		ListView^ MyList2;
		TextBox^ textBox1;
		TextBox^ textBox2;
		ToolStripMenuItem^ optionsToolStripMenuItem;
		ContextMenuStrip^ contextMenuStrip1;
		ContextMenuStrip^ contextMenuStrip2;
	public:
		ObjectToPlugin();
		ObjectToPlugin(ListView^ myList1, ListView^ myList2, TextBox^ textB1, TextBox^ textB2, ToolStripMenuItem^ optionsTSMI, ContextMenuStrip^ contextMS1, ContextMenuStrip^ contextMS2, String^ path);
	};

    static class ActionHandlers{
    public:
        static void DoubleClick_Action (ListView^ MyList, TextBox^ textBox);
        static void CopyClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
        static void DeleteClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
		static void RenameClick_Action(ListView^ MyList1, ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2, String^ newName);
        static void MoveClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
    };
	static class RenderActions{
    public:
        static void RenderFileList(ListView^ listView, TextBox^ tb, String^ defaultPath = "C:/");
        static void Determine_Size(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
		static String^ OpenDll(ObjectToPlugin ^object);
    };
	static class SupportFunctions{
    public:
        static void CopyDir(String^ FromDir, String^ ToDir);
        static double SizeOfDirectory(System::IO::DirectoryInfo ^dir);
    };
}