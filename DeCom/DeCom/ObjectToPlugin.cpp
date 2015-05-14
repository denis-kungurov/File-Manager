#include "stdafx.h"
#include "Classes.h"
using namespace DeCom;


ObjectToPlugin::ObjectToPlugin(){}

ObjectToPlugin::ObjectToPlugin(ListView^ myList1, ListView^ myList2, TextBox^ textB1, TextBox^ textB2, ToolStripMenuItem^ optionsTSMI, ContextMenuStrip^ contextMS1, ContextMenuStrip^ contextMS2, String ^path){
	MyList1 = myList1;
	MyList2 = myList2;
	textBox1 = textB1;
	textBox2 = textB2;
	optionsToolStripMenuItem = optionsTSMI;
	contextMenuStrip1 = contextMS1;
	contextMenuStrip2 = contextMS2;
	Path = path;
}
