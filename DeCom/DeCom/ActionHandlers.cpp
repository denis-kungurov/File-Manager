#pragma once
#include "stdafx.h"
#include "Classes.h"

namespace DeCom 
{
    //Обработка события двойного счелчка 
    void ActionHandlers::DoubleClick_Action(ListView^ MyList, TextBox^ textBox)
    {
        try{
            auto selectedItem = MyList->SelectedItems[0];           //берём первый выбранный элемент
            if (selectedItem->Checked)       //если элемент помечен
            {
                if(selectedItem->Text == ".." )            //если выбранный элемент ".."
                {
                    DirectoryInfo^ dir = gcnew DirectoryInfo(textBox->Text);   //получения данных о директории
                    textBox->Clear();                                       
                    if (dir->Parent)                                      //если есть родитель
                    {
                        String^ path = dir->Parent->FullName;              //получение пути к родителю
                        textBox->Text = path;                               
                        RenderActions::RenderFileList(MyList,textBox,textBox->Text);  //перерисовка listView для предыдущей директории
                    }
                    else                                                  //если нет родителя
                    {
                        textBox->Text = dir->FullName;
                    }

                }
                else
                {
                    RenderActions::RenderFileList(MyList,textBox,textBox->Text + "/" + selectedItem->Text);  //перерисовка listView для выбранной директории
                }
            }
            else       //если не помечен
            {
                System::Diagnostics::Process::Start(textBox->Text + "/" + selectedItem->Text);  //запускаем файл
            }
        }catch (System::UnauthorizedAccessException^ obj  )            //если не удалось открыть папку или файл
        {
            MessageBox::Show(obj->Message);                               //вывод сообщения
            DirectoryInfo^ dir = gcnew DirectoryInfo(textBox->Text);
            textBox->Clear();
            String^ path = dir->Parent->FullName;                           //возвращение в родительскую директорию
            textBox->Text = path;
            RenderActions::RenderFileList(MyList,textBox,textBox->Text);     //перерисовка listView
        }catch (System::ComponentModel::Win32Exception^ obj  )              //если была проблемма при запуске
        {
            MessageBox::Show(obj->Message);                    //сообщение о проблемме при запуске
        }
    };
    //Обработка события нажатия кнопки копирования
    void ActionHandlers::CopyClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {
        try{
            int flag = 0;
            ListView::SelectedListViewItemCollection^ selectedItem = nullptr;
            if (MyList1->SelectedItems->Count > 0){               //выделены ли элементы в MyList1
                selectedItem = MyList1->SelectedItems;            //присвоение списка выделенных элементов
                flag = 0;
            }else 
            {
                if (MyList2->SelectedItems->Count < 0) return;     //выход, если элементы не выделены
                selectedItem = MyList2->SelectedItems;
                flag = 1;
            }
            for each (System::Windows::Forms::ListViewItem^ item in selectedItem)     //проход по выделенным элементам
            {
                String^ name = "\\" + item->Text;              
                if (flag == 1){        //копирование из второй в первую директорию
                    if (item->Checked)                      //является ли папкой
                    {
                        SupportFunctions::CopyDir(textBox2->Text + name,textBox1->Text + name);   //копирование папки
                    } else
                    {
                        File::Copy(textBox2->Text + name,textBox1->Text + name);      //копирование файла
                    }
                }
                else {                  //копирование из первой во вторую директорию
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
                RenderActions::RenderFileList(MyList1,textBox1,textBox1->Text); //перерисовка listView
            }
            else {
                RenderActions::RenderFileList(MyList2,textBox2,textBox2->Text);
            }
        }catch(IOException^ obj)
        {
            MessageBox::Show(obj->Message);
        }
    }
    //Обработка события нажатия кнопки удаления
    void ActionHandlers::DeleteClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {                         //Всё аналогично обработке события нажатия кнопки копирования, но изспользуются функции удаления
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
                        Directory::Delete(textBox1->Text + name,true);   //вызов функции удаления папки
                    } else 
                    {
                        File::Delete(textBox1->Text + name);      //вызов функции удаления файла
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
    //Обработка события нажатия кнопки перемещения
    void ActionHandlers::MoveClick_Action(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {                    //Всё аналогично обработке события нажатия кнопки копирования, но изспользуются функции перемещения
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
                    Directory::Move(textBox1->Text + name,textBox2->Text + name);    //вызов функции удаления папки
                }
                else {
                    Directory::Move(textBox2->Text + name,textBox1->Text + name);    //вызов функции удаления папки
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