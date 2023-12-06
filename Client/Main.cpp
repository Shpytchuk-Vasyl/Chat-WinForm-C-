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
	catch (std::exception e) {
		printf("%s", e.what());
	};
	return 0;
}
