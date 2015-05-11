// IPlugin.h

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::IO::Compression;
using namespace System::Threading;
using namespace Ionic;

namespace MyLibrary {

	public interface class IPlugin
	{
		void Launch(ListView^ MyList1, ListView^ MyList2, TextBox^ textBox1, TextBox^ textBox2);
	};
}
