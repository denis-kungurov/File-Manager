#pragma once
#include "stdafx.h"
#include "Classes.h"

namespace DeCom 
{
    //����� ����������� �� ����� ���������� � ������
    void SupportFunctions::CopyDir(String^ FromDir, String^ ToDir)
    {
        auto dirs = Directory::GetDirectories(FromDir, "*", System::IO::SearchOption::AllDirectories); //��������� ������ ���� �����, ������� ��� ��������
        auto files = Directory::GetFiles(FromDir, "*.*", System::IO::SearchOption::AllDirectories); //��������� ������ ���� ������, ������� ����� � ���������
        if ( dirs->Length == 0 )  //���� ���������� ����� ����� ����
        {
            Directory::CreateDirectory(ToDir); //������ ���������� ����� � ��������� ����������
        }
        // First create all of the directories
        for each (String^ dirPath in dirs)                            //������ �� ������ �����
            Directory::CreateDirectory(dirPath->Replace(FromDir, ToDir));  //�������� ���� ����� � �������� � ����� ����������

        // Copy all the files
        for each (String^ newPath in files)                               //������ �� ������ ������
            File::Copy(newPath, newPath->Replace(FromDir, ToDir));     //����������� ������ �� ��� ����� � �������� � ����� ����������
    }
    //����� ����������� ������� �����
    double SupportFunctions::SizeOfDirectory(System::IO::DirectoryInfo ^dir)
    {
        try{
            auto AllFiles = dir->GetFiles("*", System::IO::SearchOption::AllDirectories);  //��������� ������ ���� ������, ������� ����� � ���������
            double size = 0;                                              //����������, ������� ����� ������� ������
            for each (auto file in AllFiles)                              //������ �� ������ ������
            {
                size += file->Length;                                     //���������� ������ ������� ����� � ������ � ����� �����
            } 
            return (size/1024);                                           //���������� �������� � ���������� (����/1024)
        } catch (System::UnauthorizedAccessException^ obj)
        {
            MessageBox::Show(obj->Message);
			return 0;
        }
    }
}