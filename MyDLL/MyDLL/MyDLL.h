// MyDLL.h

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

	public ref class MyTestPlugin:IPlugin
	{
	public:
		virtual void Launch(ListView^ MyList1, ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
		{
			try{                       //������ ����� try
				int flag = 0;
				auto selectedItem = MyList1->SelectedItems;
				selectedItem = nullptr;
				if (MyList1->SelectedItems->Count > 0){           //�������� �� ������� ��������� ��������� 
					selectedItem = MyList1->SelectedItems;        //������ ������ ���������
					flag = 0;
				}
				else
				{
					if (MyList2->SelectedItems->Count < 0) return;
					selectedItem = MyList2->SelectedItems;
					flag = 1;
				}

				for each (System::Windows::Forms::ListViewItem^ item in selectedItem)   //������ �� ��������� ���������
				{
					String^ name = "\\" + item->Text;         //���������� �����
					if (item->Text == "..")              //������� �������� �������� �� ������� ����
					{
						break;
					}
					if (flag == 0)
					{
						String ^source = textBox1->Text + name;
						String ^target = textBox1->Text + name + ".zip";
						if (item->Checked)            //���� �������� ������
						{
							System::IO::Compression::ZipFile::CreateFromDirectory(source, target);
						}
						else
						{
							ZipFile^ zip = gcnew ZipFile(target);
							//������������� ������� ������
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
						if (item->Checked)            //���� �������� ������
						{
							System::IO::Compression::ZipFile::CreateFromDirectory(source, target);
						}
						else
						{
							ZipFile^ zip = gcnew ZipFile(target);
							//������������� ������� ������
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
				MessageBox::Show(obj->Message);            //����� ��������� �� ������
			}
		}
	};
}
