#pragma once
#include "stdafx.h"
#include "Classes.h"

namespace DeCom
{
    //����� ���������� ListView
    void RenderActions::RenderFileList(ListView^ listView, TextBox^ tb, String^ defaultPath)
    {                
        listView->Items->Clear();      //�������� listView
        String^ path = defaultPath;      //���������� ����, �� �������� ����� ������� ������
        if (path != String::Empty)         //�������� �� ��������� ����
        {
            DirectoryInfo^ dir = gcnew DirectoryInfo(path);        //��������� ������ � ��������� ����������
            tb->Clear();                                //������� ����������� � textBox
            tb->Text = dir->FullName;                      //������ � textBox ���� � ����������
            auto files = dir->GetFiles();                  //��������� ������ ������
            auto dirs = dir->GetDirectories();             //��������� ������ �����
            int countdirs = dirs->Length;                     //����������� �����
            int countfiles = files->Length;              //����������� ������
            ListViewItem^ item = gcnew ListViewItem();//���������� �������� ���� ListViewItem
            item->ForeColor = Color::OrangeRed;         //��������� ����� ��� ����������� � ��������
            item->Checked = true;                  //������� ��������, ����� �����, ��� �� �������� ������
            item->Text = "..";                    //���� �����������
            listView->Items->Add(item);           //���������� �������� � listView
            for(int i = 0; i < countdirs; i++)                //�� ������
            {
                ListViewItem^ item = gcnew ListViewItem();          //���������� �������� ���� ListViewItem
                item->Text = dirs[i]->ToString();                   //���� �����������
                item->ForeColor = Color::OrangeRed;                //��������� ����� ��� ����������� � ��������
                item->Checked = true;                               //���������� ����������� ������ ��������
                listView->Items->Add(item);                        //���������� �������� � listView
            }
            for(int i = 0; i < countfiles; i++)            //�� ������
            {
                ListViewItem^ item = gcnew ListViewItem();
                item->Text = files[i]->ToString();                
                item->SubItems->Add( Math::Round(((double)files[i]->Length)/1024/1024,4).ToString() + " MB");  //������ ������� ����� �� ������ �������
                item->SubItems->Add(files[i]->CreationTime.ToString());                                  //������ ���� �������� � ������ �������
                item->ForeColor = Color::RoyalBlue;
                listView->Items->Add(item);
            }
        }
    }
    //����� ����������� � ������ ������� �����
    void RenderActions::Determine_Size(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {
        try{                       //������ ����� try
            int flag = 0;
            auto selectedItem = MyList1->SelectedItems;
            selectedItem = nullptr;
            if (MyList1->SelectedItems->Count > 0){           //�������� �� ������� ��������� ��������� 
                selectedItem = MyList1->SelectedItems;        //������ ������ ���������
                flag = 0;
            }else 
            {
                if (MyList2->SelectedItems->Count < 0) return;
                selectedItem = MyList2->SelectedItems;
                flag = 1;
            }

            for each (System::Windows::Forms::ListViewItem^ item in selectedItem)   //������ �� ��������� ���������
            {
                String^ name = "\\" + item->Text;         //���������� �����
                if ( item->Text == ".." )              //������� �������� �������� �� ������� ����
                {
                    break;
                }
                if(flag == 0)
                {
                    DirectoryInfo ^dir = gcnew DirectoryInfo(textBox1->Text + name);       
                    if (item->Checked)            //���� �������� ������
                    {
                        if( item->SubItems->Count > 1)              //���� ��� ���� ��������� ������ � ����� ��������
                        {
                            item->SubItems[1]->Text = Math::Round((SupportFunctions::SizeOfDirectory(dir))/1024,4).ToString() + " MB";  //���������� ����������� 
                            item->SubItems[2]->Text = dir->CreationTime.ToString();                                           //��� �������� ������� � ���� ��������
                        } else                                      //���� ��� �� ���� ���������
                        {
                            item->SubItems->Add(Math::Round((SupportFunctions::SizeOfDirectory(dir))/1024,4).ToString() + " MB");
                            item->SubItems->Add(dir->CreationTime.ToString());
                        }
                    }
                }
                else
                {
                    DirectoryInfo ^dir = gcnew DirectoryInfo(textBox2->Text + name);
                    if (item->Checked)
                    {
                        if( item->SubItems->Count > 1 ) 
                        {
                            item->SubItems[1]->Text = Math::Round((SupportFunctions::SizeOfDirectory(dir))/1024,4).ToString() + " MB";
                            item->SubItems[2]->Text = dir->CreationTime.ToString();
                        } else 
                        {
                            item->SubItems->Add(Math::Round((SupportFunctions::SizeOfDirectory(dir))/1024,4).ToString() + " MB");
                            item->SubItems->Add(dir->CreationTime.ToString());
                        }
                    }
                }
            }
        }catch(IOException^ obj)
        {
            MessageBox::Show(obj->Message);            //����� ��������� �� ������
        }
    }
};