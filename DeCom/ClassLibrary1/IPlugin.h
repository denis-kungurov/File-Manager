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
using namespace DeCom;

namespace MyLibrary {

	public interface class IPlugin
	{
		void Load(ObjectToPlugin^ object);
		void UnLoad(Object^ e, EventArgs^ arg);
		void Launch(Object^ e, EventArgs^ arg);
	};
}
