#pragma once
#include "stdafx.h"
#include "Classes.h"

namespace DeCom 
{
    //Ìåòîä êîïèğîâàíèÿ èç îäíîé äèğåêòîğèè â äğóãóş
    void SupportFunctions::CopyDir(String^ FromDir, String^ ToDir)
    {
        auto dirs = Directory::GetDirectories(FromDir, "*", System::IO::SearchOption::AllDirectories); //ïîëó÷åíèå ñïèñêà âñåõ ïàïîê, âêëş÷àÿ âñå ïîäïàïêè
        auto files = Directory::GetFiles(FromDir, "*.*", System::IO::SearchOption::AllDirectories); //ïîëó÷åíèå ñïèñêà âñåõ ôàéëîâ, âêëş÷àÿ ôàéëû â ïîäïàïêàõ
        if ( dirs->Length == 0 )  //åñëè êîëè÷åñòâî ïàïîê ğàâíî íóëş
        {
            Directory::CreateDirectory(ToDir); //ñîçäà¸ì êîïèğóåìóş ïàïêó â óêàçàííîé äèğåêòîğèè
        }
        // First create all of the directories
        for each (String^ dirPath in dirs)                            //ïğîõîä ïî ñïèñêó ïàïîê
            Directory::CreateDirectory(dirPath->Replace(FromDir, ToDir));  //ñîçäàíèå âñåõ ïàïîê è ïîäïàïîê â íîâîé äèğåêòîğèè

        // Copy all the files
        for each (String^ newPath in files)                               //ïğîõîä ïî ñïèñêó ôàéëîâ
            File::Copy(newPath, newPath->Replace(FromDir, ToDir));     //êîïèğîâàíèå ôàéëîâ âî âñå ïàïêè è ïîäïàïêè â íîâîé äèğåêòîğèè
    }
    //Ìåòîä îïğåäåëåíèÿ ğàçìåğà ïàïêè
    double SupportFunctions::SizeOfDirectory(System::IO::DirectoryInfo ^dir)
    {
        try{
            auto AllFiles = dir->GetFiles("*", System::IO::SearchOption::AllDirectories);  //ïîëó÷åíèå ñïèñêà âñåõ ôàéëîâ, âêëş÷àÿ ôàéëû â ïîäïàïêàõ
            double size = 0;                                              //ïåğåìåííàÿ, êîòîğàÿ áóäåò õğàíèòü ğàçìåğ
            for each (auto file in AllFiles)                              //ïğîõîä ïî ñïèñêó ôàéëîâ
            {
                size += file->Length;                                     //ïğèáàâëÿåì ğàçìåğ êàæäîãî ôàéëà â áàéòàõ ê îáùåé ñóììå
            } 
            return (size/1024);                                           //âîçâğàùàåì çíà÷åíèå â êèáèáàéòàõ (áàéò/1024)
        } catch (System::UnauthorizedAccessException^ obj)
        {
            MessageBox::Show(obj->Message);
			return 0;
        }
    }
}