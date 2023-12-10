#include "RegisterForm.h"
#include "MyForm.h"

System::Void Client::RegisterForm::singIn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(user->Text)) {
		user->BorderColor = Color::Red;
		errorLabel->Text = "Incorrect name";
		return;
	}
	if (String::IsNullOrEmpty(password->Text)) {
		password->BorderColor = Color::Red;
		errorLabel->Text = "Incorrect password";
		return;
	}
	if (String::Equals(user->Text, Client::MyForm::pointer->user->userName)) {	
		if (!String::Equals(password->Text, Client::MyForm::pointer->user->password)) {
			password->BorderColor = Color::Red;
			errorLabel->Text = "Incorrect password";
			return;
		}
	}	

	std::string name;
	Client::MyForm::MarshalString(user->Text, name);
	std::vector<CUser> arr = Client::MyForm::pointer->server->getAllUsers(CUser(name.c_str(),"",-1));
	if (arr.size() == 0) {
		errorLabel->Text = "User with this name isn`t registered";
		return;
	}
	for (auto us : arr) {
		if (strcmp(name.c_str(), us.getName()) == 0) {
			std::string ps;
			Client::MyForm::MarshalString(password->Text, ps);
			if (strcmp(ps.c_str(), us.getPassword()) != 0) {
				password->BorderColor = Color::Red;
				errorLabel->Text = "Incorrect password";
				return;
			}
		
			Client::MyForm::pointer->user = gcnew Client::UserNode(user->Text, password->Text, picture, true);
			Client::MyForm::pointer->downloadChats();
			this->Close();
			return;
		}

		
	}
	user->BorderColor = Color::Red;
	errorLabel->Text = "User with this name isn`t registered";	
}


System::Void Client::RegisterForm::logIn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(user->Text)) {
		user->BorderColor = Color::Red;
		errorLabel->Text = "Incorrect name";
		return;
	}
	if (String::IsNullOrEmpty(password->Text)) {
		password->BorderColor = Color::Red;
		errorLabel->Text = "Incorrect password";
		return;
	}
	std::string name;
	Client::MyForm::MarshalString(user->Text, name);
	std::string userPassword;
	Client::MyForm::MarshalString(password->Text, userPassword);
	CUser u(name.c_str(), userPassword.c_str(), picture);
	if (Client::MyForm::pointer->server->RegisterUser(u)) {

		Client::MyForm::pointer->user = gcnew Client::UserNode(user->Text, password->Text, picture, true);
		this->Close();
	}
	else {
		user->BorderColor = Color::Red;
		password->BorderColor = Color::Red;
		errorLabel->Text = "User with this name is registered";
	}

}