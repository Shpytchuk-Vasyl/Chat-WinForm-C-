#include "UsersViewForm.h"
#include "MyForm.h"


 System::Void Client::UsersViewForm::searchText_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	 if (e->KeyChar == (char)Keys::Enter) {
		 std::vector<CUser> v;
		 try {
			 std::string userName;
			 Client::MyForm::MarshalString(searchUser->Text, userName);
			 v = MyForm::pointer->server->getAllUsers(CUser(userName.c_str(), "", -1));
		 } catch(std::exception e){
			 MessageBox::Show("Unable to connect to server", "Unable connection",
				 MessageBoxButtons::OK, MessageBoxIcon::Error);
			 return;
		 }
		 SuspendLayout();
		// placeForUsers->Controls->Clear();
		 for (int i = 0; i < v.size(); i++) {
			 placeForUsers->Controls->Add(gcnew UserNode(gcnew String(v[i].getName()), "", v[i].getPicture(), v[i].getStatus(), -1));
		 }
		 ResumeLayout();
	 }
}