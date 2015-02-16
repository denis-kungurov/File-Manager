#pragma once
#include "stdafx.h"
#include "Classes.h"

namespace DeCom 
{
    //��������� ������� �������� ������� 
    void ActionHandlers::DoubleClick_Action(ListView^ MyList, TextBox^ textBox)
    {
        try{
            auto selectedItem = MyList->SelectedItems[0];           //���� ������ ��������� �������
            if (selectedItem->Checked)       //���� ������� �������
            {
                if(selectedItem->Text == ".." )            //���� ��������� ������� ".."
                {
                    DirectoryInfo^ dir = gcnew DirectoryInfo(textBox->Text);   //��������� ������ � ����������
                    textBox->Clear();                                       
                    if (dir->Parent)                                      //���� ���� ��������
                    {
                        String^ path = dir->Parent->FullName;              //��������� ���� � ��������
                        textBox->Text = path;                               
                        RenderActions::RenderFileList(MyList,textBox,textBox->Text);  //����������� listView ��� ���������� ����������
                    }
                    else                                                  //���� ��� ��������
                    {
                        textBox->Text = dir->FullName;
                    }

                }
                else
                {
                    RenderActions::RenderFileList(MyList,textBox,textBox->Text + "/" + selectedItem->Text);  //����������� listView ��� ��������� ����������
                }
            }
            else       //���� �� �������
            {
                System::Diagnostics::Process::Start(textBox->Text + "/" + selectedItem->Text);  //��������� ����
            }
        }catch (System::UnauthorizedAccessException^ obj  )            //���� �� ������� ������� ����� ��� ����
        {
            MessageBox::Show(obj->Message);                               //����� ���������
            DirectoryInfo^ dir = gcnew DirectoryInfo(textBox->Text);
            textBox->Clear();
            String^ path = dir->Parent->FullName;                           //����������� � ������������ ����������
            textBox->Text = path;
            RenderActions::RenderFileList(MyList,textBox,textBox->Text);     //����������� listView
        }catch (System::ComponentModel::Win32Exception^ obj  )              //���� ���� ��������� ��� �������
        {
            MessageBox::Show(obj->Message);                    //��������� � ��������� ��� �������
        }
    };
    //��������� ������� ������� ������ �����������
    void ActionHandlers::CopyClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {
        try{
            int flag = 0;
            ListView::SelectedListViewItemCollection^ selectedItem = nullptr;
            if (MyList1->SelectedItems->Count > 0){               //�������� �� �������� � MyList1
                selectedItem = MyList1->SelectedItems;            //���������� ������ ���������� ���������
                flag = 0;
            }else 
            {
                if (MyList2->SelectedItems->Count < 0) return;     //�����, ���� �������� �� ��������
                selectedItem = MyList2->SelectedItems;
                flag = 1;
            }
            for each (System::Windows::Forms::ListViewItem^ item in selectedItem)     //������ �� ���������� ���������
            {
                String^ name = "\\" + item->Text;              
                if (flag == 1){        //����������� �� ������ � ������ ����������
                    if (item->Checked)                      //�������� �� ������
                    {
                        SupportFunctions::CopyDir(textBox2->Text + name,textBox1->Text + name);   //����������� �����
                    } else
                    {
                        File::Copy(textBox2->Text + name,textBox1->Text + name);      //����������� �����
                    }
                }
                else {                  //����������� �� ������ �� ������ ����������
                    if (item->Checked)
                    {
                        SupportFunctions::CopyDir(textBox1->Text + name,textBox2->Text + name);
                    } else
                    {
                        File::Copy(textBox1->Text + name,textBox2->Text + name);
                    }
                }
            }
            if(flag != 0){
                RenderActions::RenderFileList(MyList1,textBox1,textBox1->Text); //����������� listView
            }
            else {
                RenderActions::RenderFileList(MyList2,textBox2,textBox2->Text);
            }
        }catch(IOException^ obj)
        {
            MessageBox::Show(obj->Message);
        }
    }
    //��������� ������� ������� ������ ��������
    void ActionHandlers::DeleteClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {                         //�� ���������� ��������� ������� ������� ������ �����������, �� ������������� ������� ��������
        try{
            int flag = 0;
            auto selectedItem = MyList1->SelectedItems;
            selectedItem = nullptr;
            if (MyList1->SelectedItems->Count > 0){
                selectedItem = MyList1->SelectedItems;
                flag = 0;
            }else 
            {
                if (MyList2->SelectedItems->Count < 0) return;
                selectedItem = MyList2->SelectedItems;
                flag = 1;
            }
            for each (System::Windows::Forms::ListViewItem^ item in selectedItem)
            {
                String^ name = "\\" + item->Text;
                if (flag == 0){
                    if (item->Checked)
                    {
                        Directory::Delete(textBox1->Text + name,true);   //����� ������� �������� �����
                    } else 
                    {
                        File::Delete(textBox1->Text + name);      //����� ������� �������� �����
                    }
                }
                else {
                    if (item->Checked)
                    {
                        Directory::Delete(textBox2->Text + name,true);
                    } else 
                    {
                        File::Delete(textBox2->Text + name);
                    }
                }
            }
            if(!flag){
                RenderActions::RenderFileList(MyList1,textBox1,textBox1->Text);
            }
            else {
                RenderActions::RenderFileList(MyList2,textBox2,textBox2->Text);
            }
        }catch(IOException^ obj)
        {
            MessageBox::Show(obj->Message);
        }catch(UnauthorizedAccessException^ obj)
        {
            MessageBox::Show(obj->Message);
        }
    }
    //��������� ������� ������� ������ �����������
    void ActionHandlers::MoveClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {                    //�� ���������� ��������� ������� ������� ������ �����������, �� ������������� ������� �����������
        try{
            int flag = 0;
            auto selectedItem = MyList1->SelectedItems;
            selectedItem = nullptr;
            if (MyList1->SelectedItems->Count > 0){
                selectedItem = MyList1->SelectedItems;
                flag = 0;
            }else 
            {
                if (MyList2->SelectedItems->Count < 0) return;
                selectedItem = MyList2->SelectedItems;
                flag = 1;
            }
            for each (System::Windows::Forms::ListViewItem^ item in selectedItem)
            {
                String^ name = "\\" + item->Text;
                if (flag == 0){
                    Directory::Move(textBox1->Text + name,textBox2->Text + name);    //����� ������� �������� �����
                }
                else {
                    Directory::Move(textBox2->Text + name,textBox1->Text + name);    //����� ������� �������� �����
                }
            }
            RenderActions::RenderFileList(MyList1,textBox1,textBox1->Text);
            RenderActions::RenderFileList(MyList2,textBox2,textBox2->Text);

        }catch(IOException^ obj)
        {
            MessageBox::Show(obj->Message);
        }
    }
}