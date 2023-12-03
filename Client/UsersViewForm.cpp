#include "UsersViewForm.h"
#include "MyForm.h"


 System::Void Client::UsersViewForm::searchText_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	 if (e->KeyChar == (char)Keys::Enter) {
		 std::vector<CUser> v = MyForm::pointer->server->getAllUsers(CUser("55", "", 1));
		 SuspendLayout();
		 for (int i = 0; i < v.size(); i++) {
			 flowLayoutPanel1->Controls->Add(gcnew UserNode(gcnew String(v[i].getName()), 1, false, i));
		 }
		 ResumeLayout();
	 }
}