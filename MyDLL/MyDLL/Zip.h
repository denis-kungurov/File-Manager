// Zip.h

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Threading;
using namespace Ionic::Zip;
using namespace MyLibrary;

namespace MyDll {

	public ref class ZipPlugin:IPlugin
	{
	public:
		String^ name = "Zip";
		String^ Pathes;
		String^ path;
		ListView^ MyList1;
		ListView^ MyList2;
		TextBox^ textBox1;
		TextBox^ textBox2;
		ToolStripMenuItem ^pluginsMenu;
		ToolStripMenuItem ^deletePluginMenu; 
		ToolStripItemCollection^ optionMenuItems;
		ContextMenuStrip ^contextMenuItem1;
		ContextMenuStrip ^contextMenuItem2;

	public:
		virtual String^ GetName()
		{
			return name;
		}

		virtual void Load(DeCom::ObjectToPlugin^ object)
		{
			deletePluginMenu = nullptr;
			optionMenuItems = object->optionsToolStripMenuItem->DropDownItems;
			for each(ToolStripMenuItem^ item in optionMenuItems){
				if (item->Text == "Plugins")
				{
					pluginsMenu = item;
				}
				if (item->Text == "Delete Plugin ...")
				{
					deletePluginMenu = item;
				}
			}
			if (deletePluginMenu == nullptr)
			{
				ToolStripMenuItem ^item = gcnew ToolStripMenuItem();
				item->Text = "Delete Plugin ...";
				optionMenuItems->Add(item);
				deletePluginMenu = item;
			}

			auto items = pluginsMenu->DropDownItems;
			for each(ToolStripMenuItem^ item in items)
				if (item->Text == name)
					return;

			this->MyList1 = object->MyList1;
			this->MyList2 = object->MyList2;
			this->textBox1 = object->textBox1;
			this->textBox2 = object->textBox2;
			this->Pathes = object->Pathes;
			this->path = object->Path;
			this->contextMenuItem1 = object->contextMenuStrip1;
			this->contextMenuItem2 = object->contextMenuStrip2;
			ToolStripMenuItem^ newPlugin = gcnew ToolStripMenuItem();
			newPlugin->Text = name;
			newPlugin->Click += gcnew System::EventHandler(this, &MyDll::ZipPlugin::Launch);
			pluginsMenu->DropDownItems->Add(newPlugin);
			ToolStripMenuItem^ deletePlugin = gcnew ToolStripMenuItem();
			deletePlugin->Text = name;
			deletePlugin->Click += gcnew System::EventHandler(this, &MyDll::ZipPlugin::UnLoad);
			deletePluginMenu->DropDownItems->Add(deletePlugin);

			ToolStripMenuItem^ newContextMenuItem1 = gcnew ToolStripMenuItem();
			ToolStripMenuItem^ newContextMenuItem2 = gcnew ToolStripMenuItem();
			newContextMenuItem1->Text = name;
			newContextMenuItem2->Text = name;
			newContextMenuItem1->Click += gcnew System::EventHandler(this, &MyDll::ZipPlugin::Launch);
			newContextMenuItem2->Click += gcnew System::EventHandler(this, &MyDll::ZipPlugin::Launch);
			contextMenuItem1->Items->Add(newContextMenuItem1);
			contextMenuItem2->Items->Add(newContextMenuItem2);
		}

		virtual void UnLoad(Object^ e, EventArgs^ arg)
		{
			for each(ToolStripMenuItem ^item in pluginsMenu->DropDownItems)
			{
				if (item->Text == name)
				{
					pluginsMenu->DropDownItems->Remove(item);
					break;
				}
			}
			for each(ToolStripMenuItem ^item in deletePluginMenu->DropDownItems)
			{
				if (item->Text == name)
				{
					deletePluginMenu->DropDownItems->Remove(item);
					if (deletePluginMenu->DropDownItems->Count == 0)
						optionMenuItems->Remove(deletePluginMenu);
					break;
				}
			}
			for each(ToolStripItem ^item in contextMenuItem1->Items)
			{
				if (item->Text == name)
				{
					contextMenuItem1->Items->Remove(item);
					break;
				}
			}
			for each(ToolStripItem ^item in contextMenuItem2->Items)
			{
				if (item->Text == name)
				{
					contextMenuItem2->Items->Remove(item);
					break;
				}
			}
			auto sr = gcnew StreamReader(Pathes);
			String ^str = sr->ReadToEnd();
			str = str->Replace(name + ":" + path + "\r\n", "");
			sr->Close();
			auto sw = gcnew StreamWriter(Pathes,false);
			sw->Write(str);
			sw->Close();
		}


		virtual void Launch(Object^ e, EventArgs^ arg)
		{
			Thread^ t1 = gcnew Thread(gcnew ThreadStart(this, &MyDll::ZipPlugin::DoTask));
			t1->IsBackground = true;
			t1->Start();
		}

		void DoTask()
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
						String ^target = textBox1->Text + name + ".zip";
						if (item->Checked)            //если является папкой
						{
							System::IO::Compression::ZipFile::CreateFromDirectory(source, target);
						}
						else
						{
							ZipFile^ zip = gcnew ZipFile(target);
							//Устанавливаем уровень сжатия
							zip->CompressionLevel = Ionic::Zlib::CompressionLevel::Default;
							zip->AddFile(source);
							zip->Save();
							zip = nullptr;
						}
					}
					else
					{
						String ^source = textBox2->Text + name;
						String ^target = textBox2->Text + name + ".zip";
						if (item->Checked)            //если является папкой
						{
							System::IO::Compression::ZipFile::CreateFromDirectory(source, target);
						}
						else
						{
							ZipFile^ zip = gcnew ZipFile(target);
							//Устанавливаем уровень сжатия
							zip->CompressionLevel = Ionic::Zlib::CompressionLevel::Default;
							zip->AddFile(source);
							zip->Save();
							zip = nullptr;
						}
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
