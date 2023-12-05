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
	if (!String::Equals(user->Text, Client::MyForm::pointer->user->userName)) {
		user->BorderColor = Color::Red;
		errorLabel->Text = "Incorrect name";
		return;
	}
	if (!String::Equals(password->Text, Client::MyForm::pointer->user->password)) {
		password->BorderColor = Color::Red;
		errorLabel->Text = "Incorrect password";
		return;
	}
	Client::MyForm::pointer->downloadChats();
	this->Close();
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
	CUser u(name.c_str(), userPassword.c_str(), 1);
	if (Client::MyForm::pointer->server->RegisterUser(u)) {
		Client::MyForm::pointer->user = gcnew Client::UserNode(user->Text, password->Text, 1, true, -1);
		this->Close();
	}
	else {
		user->BorderColor = Color::Red;
		password->BorderColor = Color::Red;
		errorLabel->Text = "User with this name is registered";
	}

}