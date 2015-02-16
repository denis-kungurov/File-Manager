#pragma once
#include "stdafx.h"
#include "Classes.h"

namespace DeCom
{
    //Метод заполнения ListView
    void RenderActions::RenderFileList(ListView^ listView, TextBox^ tb, String^ defaultPath)
    {                
        listView->Items->Clear();      //очищения listView
        String^ path = defaultPath;      //переменная пути, из которого будут браться данные
        if (path != String::Empty)         //проверка на непустоту пути
        {
            DirectoryInfo^ dir = gcnew DirectoryInfo(path);        //получение данных о выбранной директории
            tb->Clear();                                //очистка содержимого в textBox
            tb->Text = dir->FullName;                      //запись в textBox пути к директории
            auto files = dir->GetFiles();                  //получение списка файлов
            auto dirs = dir->GetDirectories();             //получение списка папок
            int countdirs = dirs->Length;                     //колличество папок
            int countfiles = files->Length;              //колличество файлов
            ListViewItem^ item = gcnew ListViewItem();//переменная элемента типа ListViewItem
            item->ForeColor = Color::OrangeRed;         //установка цвета для содержимого в элементе
            item->Checked = true;                  //пометка элемента, чтобы знать, что он является папкой
            item->Text = "..";                    //ввод содержимого
            listView->Items->Add(item);           //добавление элемента в listView
            for(int i = 0; i < countdirs; i++)                //по папкам
            {
                ListViewItem^ item = gcnew ListViewItem();          //переменная элемента типа ListViewItem
                item->Text = dirs[i]->ToString();                   //ввод содержимого
                item->ForeColor = Color::OrangeRed;                //установка цвета для содержимого в элементе
                item->Checked = true;                               //добавление возможности выбора элемента
                listView->Items->Add(item);                        //добавление элемента в listView
            }
            for(int i = 0; i < countfiles; i++)            //по файлам
            {
                ListViewItem^ item = gcnew ListViewItem();
                item->Text = files[i]->ToString();                
                item->SubItems->Add( Math::Round(((double)files[i]->Length)/1024/1024,4).ToString() + " MB");  //запись размера файла во второй столбец
                item->SubItems->Add(files[i]->CreationTime.ToString());                                  //запись даты создания в третий столбец
                item->ForeColor = Color::RoyalBlue;
                listView->Items->Add(item);
            }
        }
    }
    //Метод определения и записи размера папки
    void RenderActions::Determine_Size(ListView^ MyList1,ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2)
    {
        try{                       //начало блока try
            int flag = 0;
            auto selectedItem = MyList1->SelectedItems;
            selectedItem = nullptr;
            if (MyList1->SelectedItems->Count > 0){           //Проверка на наличие выбранных элементов 
                selectedItem = MyList1->SelectedItems;        //Запись списка элементов
                flag = 0;
            }else 
            {
                if (MyList2->SelectedItems->Count < 0) return;
                selectedItem = MyList2->SelectedItems;
                flag = 1;
            }

            for each (System::Windows::Forms::ListViewItem^ item in selectedItem)   //проход по выбранным элементам
            {
                String^ name = "\\" + item->Text;         //переменная имени
                if ( item->Text == ".." )              //пропуск элемента перехода на уровень выше
                {
                    break;
                }
                if(flag == 0)
                {
                    DirectoryInfo ^dir = gcnew DirectoryInfo(textBox1->Text + name);       
                    if (item->Checked)            //если является папкой
                    {
                        if( item->SubItems->Count > 1)              //если уже были добавлены размер и время создания
                        {
                            item->SubItems[1]->Text = Math::Round((SupportFunctions::SizeOfDirectory(dir))/1024,4).ToString() + " MB";  //перезапись содержимого 
                            item->SubItems[2]->Text = dir->CreationTime.ToString();                                           //для столбцов размера и даты создания
                        } else                                      //если ещё не были добавлены
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
            MessageBox::Show(obj->Message);            //вывод сообщения об ошибке
        }
    }
};