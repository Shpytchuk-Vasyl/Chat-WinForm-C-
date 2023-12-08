#include "UsersViewForm.h"
#include "MyForm.h"
namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	System::Void UsersViewForm::searchText_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == (char)Keys::Enter) {
			std::vector<CUser> v;
			try {
				std::string userName;
				Client::MyForm::MarshalString(searchUser->Text, userName);
				v = MyForm::pointer->server->getAllUsers(CUser(userName.c_str(), "", -1));
			}
			catch (std::exception e) {
				MessageBox::Show("Unable to connect to server", "Unable connection",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			SuspendLayout();
			placeForUsers->Controls->Clear();
			for (int i = 0; i < v.size(); i++) {
				UserNode^ node = gcnew UserNode(gcnew String(v[i].getName()), "", v[i].getPicture(), v[i].getStatus());
				node->MouseClick += gcnew  System::Windows::Forms::MouseEventHandler(this, &UsersViewForm::mouseClick);

				placeForUsers->Controls->Add(node);
			}
			ResumeLayout();
		}
	}
	 
	System::Void UsersViewForm::mouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		resultUser = (UserNode^)sender;
		this->Close();
	}
}