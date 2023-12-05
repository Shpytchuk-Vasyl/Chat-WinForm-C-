#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

int main() {
	try {
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Client::MyForm form;
		Application::Run(% form);
	}
	catch (...) {};
	return 0;
}
