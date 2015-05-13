// UnZip.h

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Threading;
using namespace Ionic::Zip;
using namespace MyLibrary;

namespace MyDll {

	public ref class UnZipPlugin :IPlugin
	{
	public:
		String^ name = "UnZip";
		ListView^ MyList1;
		ListView^ MyList2;
		TextBox^ textBox1;
		TextBox^ textBox2;

	public:
		virtual void Init(ListView^ MyList1, ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2, ToolStripMenuItem^ pluginMenu)
		{
			auto items = pluginMenu->DropDownItems;
			for each(ToolStripMenuItem^ item in items)
				if (item->Text == name)
					return;

			this->MyList1 = MyList1;
			this->MyList2 = MyList2;
			this->textBox1 = textBox1;
			this->textBox2 = textBox2;
			ToolStripMenuItem^ newPlugin = gcnew ToolStripMenuItem();
			newPlugin->Text = name;
			newPlugin->Click += gcnew System::EventHandler(this, &MyDll::UnZipPlugin::Launch);
			pluginMenu->DropDownItems->Add(newPlugin);
		}
		virtual void Launch(Object^ e, EventArgs^ arg)
		{
			try{                       //начало блока try
				int flag = 0;
				auto selectedItem = MyList1->SelectedItems;
				selectedItem = nullptr;
				if (MyList1->SelectedItems->Count > 0){           //Проверка на наличие выбранных элементов 
					selectedItem = MyList1->SelectedItems;        //Запись списка элементов
					flag = 0;
				}
				else
				{
					if (MyList2->SelectedItems->Count < 0) return;
					selectedItem = MyList2->SelectedItems;
					flag = 1;
				}

				for each (System::Windows::Forms::ListViewItem^ item in selectedItem)   //проход по выбранным элементам
				{
					String^ name = "\\" + item->Text;         //переменная имени
					if (item->Text == "..")              //пропуск элемента перехода на уровень выше
					{
						break;
					}
					if (flag == 0)
					{
						String ^source = textBox1->Text + name;
						String ^target = textBox1->Text + "\\" + Path::GetFileNameWithoutExtension(source);
						if (Path::GetExtension(source) != ".zip" && Path::GetExtension(source) != ".rar")
							break;
						Compression::ZipFile::ExtractToDirectory(source, target);
					}
					else
					{
						String ^source = textBox2->Text + name;
						String ^target = textBox2->Text + "\\" + Path::GetFileNameWithoutExtension(source);
						if (Path::GetExtension(source) != ".zip" && Path::GetExtension(source) != ".rar")
							break;
						Compression::ZipFile::ExtractToDirectory(source, target);
					}
				}
			}
			catch (IOException^ obj)
			{
				MessageBox::Show(obj->Message);            //вывод сообщения об ошибке
			}
		}
	};
}
