#pragma once

#include "vcclr.h"
#include "Classes.h"


namespace DeCom {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
	using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
	using namespace System::Net;
    using namespace System::IO;
	using namespace System::IO::Compression;
    using namespace System::Threading;
	using namespace Ionic;
    using namespace std;
	using namespace MyLibrary;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();    //Метод инициализации формы
        }
    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
        //Объявление переменных
    protected: 
        
    private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::TextBox^  textBox2;
    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::ListView^  MyList1;
    private: System::Windows::Forms::ListView^  MyList2;

    private: System::Windows::Forms::ColumnHeader^  columnHeader1;
    private: System::Windows::Forms::ColumnHeader^  columnHeader2;
    private: System::Windows::Forms::ColumnHeader^  columnHeader3;
    private: System::Windows::Forms::ColumnHeader^  columnHeader4;
    private: System::Windows::Forms::ColumnHeader^  columnHeader5;
    private: System::Windows::Forms::ColumnHeader^  columnHeader6;




    private: System::Windows::Forms::Button^  button_Copy;
    private: System::Windows::Forms::Button^  button_Replace;

    private: System::Windows::Forms::SplitContainer^  splitContainer1;
    private: System::Windows::Forms::SplitContainer^  splitContainer2;
    private: System::Windows::Forms::Button^  button_Delete;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  programToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pluginsToolStripMenuItem;


	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  updateToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  updateToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadPluginToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;







    private: System::ComponentModel::IContainer^  components;

    private:
        
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->MyList1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->MyList2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button_Copy = (gcnew System::Windows::Forms::Button());
			this->button_Replace = (gcnew System::Windows::Forms::Button());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->programToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pluginsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadPluginToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->updateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->updateToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->contextMenuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(2, -2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(296, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(3, -2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(299, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(309, -2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 20);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(315, -2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 20);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Browse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// MyList1
			// 
			this->MyList1->BackColor = System::Drawing::SystemColors::Desktop;
			this->MyList1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader5
			});
			this->MyList1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MyList1->FullRowSelect = true;
			this->MyList1->Location = System::Drawing::Point(0, 0);
			this->MyList1->Name = L"MyList1";
			this->MyList1->Size = System::Drawing::Size(386, 329);
			this->MyList1->TabIndex = 6;
			this->MyList1->UseCompatibleStateImageBehavior = false;
			this->MyList1->View = System::Windows::Forms::View::Details;
			this->MyList1->Enter += gcnew System::EventHandler(this, &Form1::MyList1_Enter);
			this->MyList1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Global_KeyDown);
			this->MyList1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::MyList1_MouseClick);
			this->MyList1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::MyList1_MouseDoubleClick);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Имя";
			this->columnHeader1->Width = 130;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Размер";
			this->columnHeader2->Width = 95;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Дата создания";
			this->columnHeader5->Width = 145;
			// 
			// MyList2
			// 
			this->MyList2->BackColor = System::Drawing::SystemColors::Desktop;
			this->MyList2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader3, this->columnHeader4,
					this->columnHeader6
			});
			this->MyList2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MyList2->FullRowSelect = true;
			this->MyList2->Location = System::Drawing::Point(0, 0);
			this->MyList2->Name = L"MyList2";
			this->MyList2->Size = System::Drawing::Size(388, 329);
			this->MyList2->TabIndex = 7;
			this->MyList2->UseCompatibleStateImageBehavior = false;
			this->MyList2->View = System::Windows::Forms::View::Details;
			this->MyList2->Enter += gcnew System::EventHandler(this, &Form1::MyList2_Enter);
			this->MyList2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Global_KeyDown);
			this->MyList2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::MyList2_MouseClick);
			this->MyList2->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::MyList2_MouseDoubleClick);
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Имя";
			this->columnHeader3->Width = 130;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Размер";
			this->columnHeader4->Width = 95;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Дата создания";
			this->columnHeader6->Width = 150;
			// 
			// button_Copy
			// 
			this->button_Copy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_Copy->Location = System::Drawing::Point(14, 397);
			this->button_Copy->Name = L"button_Copy";
			this->button_Copy->Size = System::Drawing::Size(75, 23);
			this->button_Copy->TabIndex = 9;
			this->button_Copy->Text = L"Копировать";
			this->button_Copy->UseVisualStyleBackColor = true;
			this->button_Copy->Click += gcnew System::EventHandler(this, &Form1::button_Copy_Click);
			// 
			// button_Replace
			// 
			this->button_Replace->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_Replace->Location = System::Drawing::Point(95, 397);
			this->button_Replace->Name = L"button_Replace";
			this->button_Replace->Size = System::Drawing::Size(91, 23);
			this->button_Replace->TabIndex = 10;
			this->button_Replace->Text = L"Переместить";
			this->button_Replace->UseVisualStyleBackColor = true;
			this->button_Replace->Click += gcnew System::EventHandler(this, &Form1::button_Replace_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->Location = System::Drawing::Point(14, 53);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->MyList1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->MyList2);
			this->splitContainer1->Size = System::Drawing::Size(778, 329);
			this->splitContainer1->SplitterDistance = 386;
			this->splitContainer1->TabIndex = 11;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer2->Location = System::Drawing::Point(14, 29);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->textBox1);
			this->splitContainer2->Panel1->Controls->Add(this->button1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->textBox2);
			this->splitContainer2->Panel2->Controls->Add(this->button2);
			this->splitContainer2->Size = System::Drawing::Size(778, 18);
			this->splitContainer2->SplitterDistance = 384;
			this->splitContainer2->TabIndex = 12;
			// 
			// button_Delete
			// 
			this->button_Delete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_Delete->Location = System::Drawing::Point(192, 397);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(75, 23);
			this->button_Delete->TabIndex = 13;
			this->button_Delete->Text = L"Удалить";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &Form1::button_Delete_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->programToolStripMenuItem,
					this->optionsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(804, 24);
			this->menuStrip1->TabIndex = 14;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// programToolStripMenuItem
			// 
			this->programToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->programToolStripMenuItem->Name = L"programToolStripMenuItem";
			this->programToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->programToolStripMenuItem->Text = L"Program";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->pluginsToolStripMenuItem,
					this->loadPluginToolStripMenuItem1
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// pluginsToolStripMenuItem
			// 
			this->pluginsToolStripMenuItem->Name = L"pluginsToolStripMenuItem";
			this->pluginsToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->pluginsToolStripMenuItem->Text = L"Plugins";
			// 
			// loadPluginToolStripMenuItem1
			// 
			this->loadPluginToolStripMenuItem1->Name = L"loadPluginToolStripMenuItem1";
			this->loadPluginToolStripMenuItem1->Size = System::Drawing::Size(149, 22);
			this->loadPluginToolStripMenuItem1->Text = L"Load Plugin ...";
			this->loadPluginToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::loadPluginToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->updateToolStripMenuItem });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(153, 48);
			// 
			// updateToolStripMenuItem
			// 
			this->updateToolStripMenuItem->Name = L"updateToolStripMenuItem";
			this->updateToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->updateToolStripMenuItem->Text = L"Update";
			this->updateToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::updateToolStripMenuItemRight_Click);
			// 
			// contextMenuStrip2
			// 
			this->contextMenuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->updateToolStripMenuItem1 });
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(113, 26);
			// 
			// updateToolStripMenuItem1
			// 
			this->updateToolStripMenuItem1->Name = L"updateToolStripMenuItem1";
			this->updateToolStripMenuItem1->Size = System::Drawing::Size(112, 22);
			this->updateToolStripMenuItem1->Text = L"Update";
			this->updateToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::updateToolStripMenuItemLeft_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(804, 449);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button_Delete);
			this->Controls->Add(this->splitContainer2);
			this->Controls->Add(this->button_Replace);
			this->Controls->Add(this->button_Copy);
			this->Controls->Add(this->splitContainer1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(820, 480);
			this->Name = L"Form1";
			this->Text = L"DeCom";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->contextMenuStrip2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

        //Обработка события загрузки формы
    private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)   
             {
                 RenderActions::RenderFileList(MyList1,textBox1);         //Вызов метода заполнения MyList1, MyList2
                 RenderActions::RenderFileList(MyList2,textBox2);         //списком файлов и папок
				 auto pluginsPathes = File::ReadAllLines(Directory::GetCurrentDirectory() + "\\" + "Plugins.txt");
				 List<String^>^ pluginsList = gcnew List<String^>(pluginsPathes);
				 for each(String^ path in pluginsList)
				 {
					 if ((String::IsNullOrEmpty(path) || String::IsNullOrWhiteSpace(path)) == false)
					 {
						 path = path->Remove(0, path->IndexOf(":") + 1);
						 ObjectToPlugin^ object = gcnew ObjectToPlugin(MyList1, MyList2, textBox1, textBox2, optionsToolStripMenuItem, contextMenuStrip1, contextMenuStrip2, path);
						 RenderActions::OpenDll(object);
					 }
				 }
             }
        //Обработка события нажатия кнопки "Browse" для MyList1
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
             {                
                 FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
                 fbd->ShowDialog();                   //Отображение окна выбора директории

                 String^ path = fbd->SelectedPath;      //получение выбранного пути
                 if (path != String::Empty)             //проверка на пустоту выбранного пути (выбран ли он)
                 {
                     MyList1->Items->Clear();                //Очистка MyList1 
                     RenderActions::RenderFileList(MyList1,textBox1,path);   //Вызов метода заполнения MyList1
                 }
             }
        //Обработка события нажатия кнопки "Browse" для MyList2
    private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
             {                
                 FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
                 fbd->ShowDialog();                      //Отображение окна выбора директории

                 String^ path = fbd->SelectedPath;         //получение выбранного пути
                 if (path != String::Empty)               //проверка на пустоту выбранного пути (выбран ли он)
                 {
                     MyList2->Items->Clear();               //Очистка MyList2
                     RenderActions::RenderFileList(MyList2,textBox2,path);   //Вызов метода заполнения MyList2
                 }
             }
        //Обработка события двойного нажатия на элемент из MyList1
    private: System::Void MyList1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
             {
                 ActionHandlers::DoubleClick_Action(MyList1,textBox1);  //вызов метода обработки данного события
             }
        //Обработка события двойного нажатия на элемент из MyList2
    private: System::Void MyList2_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
             {
                 ActionHandlers::DoubleClick_Action(MyList2,textBox2);           //вызов метода обработки данного события
             }
        //Обработка события нажатия кнопки "Копировать"
    private: System::Void button_Copy_Click(System::Object^  sender, System::EventArgs^  e) 
             {
                 ActionHandlers::CopyClick_Action(MyList1,MyList2,textBox1,textBox2);          //вызов метода обработки данного события
             }
        //Обработка события нажатия кнопки "Удалить"
    private: System::Void button_Delete_Click(System::Object^  sender, System::EventArgs^  e) 
             {
                 ActionHandlers::DeleteClick_Action(MyList1,MyList2,textBox1,textBox2);         //вызов метода обработки данного события
             }
        //Обработка события нажатия кнопки "Переместить"
    private: System::Void button_Replace_Click(System::Object^  sender, System::EventArgs^  e) 
             {
                 ActionHandlers::MoveClick_Action(MyList1,MyList2,textBox1,textBox2); //вызов метода обработки данного события
             }
        //Обработка события изменения состояния MyList1 на "активный"
    private: System::Void MyList2_Enter(System::Object^  sender, System::EventArgs^  e) 
             {
                 MyList1->SelectedItems->Clear();       //Очистка списка выбранных элементов для MyList1
             }
        //Обработка события  изменения состояния MyList2 на "активный"
    private: System::Void MyList1_Enter(System::Object^  sender, System::EventArgs^  e) 
             {
                 MyList2->SelectedItems->Clear();       //Очистка списка выбранных элементов для MyList2
             }
        //Обработка события нажатия клавиши
    private: System::Void Global_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
             {
                 if( e->KeyData == Keys::Space)       //проверка на нажатие клавишу Space
                 {
					 Thread^ t1 = gcnew Thread(gcnew ThreadStart(this, &DeCom::Form1::Set_Size));
					 t1->IsBackground = true;
                     t1->Start();//вызов метода установки размера
                 }
                 /*System::Action ^ action = gcnew Action(this, &Form1::Set_Size);

                 Thread^ mainT = Thread::CurrentThread;

                 Thread^ t1 = gcnew Thread(gcnew ThreadStart(this, &RenderActions::SizeOfDirectory));
                 t1->Start();*/
             }
			 delegate void MyDelegate();
        //Метод установки размера для папки
    private: System::Void Set_Size() 
             {
				 RenderActions::Determine_Size(MyList1,MyList2,textBox1,textBox2);  //вызов метода определения размера
             }
	private: System::Void loadPluginToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ AboutLibName;
		try
		{
			OpenFileDialog^ openFile = gcnew OpenFileDialog();
			openFile->Title = "Выберите файлы, которые необходимо заархивировать";

			if (openFile->ShowDialog() == ::DialogResult::OK)
			{
				AboutLibName = openFile->FileName;
			}
			else return;
		}
		catch (Exception^ ex) { MessageBox::Show("Ошибка во время выбора файлов для архивации, попробуйте еще раз! " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error); }
		
		ObjectToPlugin^ object = gcnew ObjectToPlugin(MyList1, MyList2, textBox1, textBox2, optionsToolStripMenuItem, contextMenuStrip1, contextMenuStrip2, AboutLibName);

		String ^name = RenderActions::OpenDll(object);
		auto sw = gcnew StreamWriter(Directory::GetCurrentDirectory() + "\\" + "Plugins.txt", true);
		sw->WriteLine(name + ":" + AboutLibName);
		sw->Close();
	}
	
	private: System::Void updateToolStripMenuItemRight_Click(System::Object^  sender, System::EventArgs^  e) {
		RenderActions::RenderFileList(MyList2, textBox2, textBox2->Text);
	}
	private: System::Void updateToolStripMenuItemLeft_Click(System::Object^  sender, System::EventArgs^  e) {
		RenderActions::RenderFileList(MyList1, textBox1, textBox1->Text);
	}

	private: System::Void MyList1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == ::MouseButtons::Right)       //проверка на нажатие
		{
			contextMenuStrip2->Show(Cursor->Position);
		}
	}
	private: System::Void MyList2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == ::MouseButtons::Right)       //проверка на нажатие
		{
			contextMenuStrip1->Show(Cursor->Position);
		}
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
private: System::Void MyList2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

