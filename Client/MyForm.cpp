#pragma onse
#include "MyForm.h"
namespace Client {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Threading;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading::Tasks;


Void MyForm::onShow() {

	try {
		server = new ServerConnection();
		server->Connect(DEFAULT_IP, DEFAULT_PORT);
	}
	catch (std::exception er) {
		MessageBox::Show("Unable to connect to server", "Unable connection",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//UserNode::MyUserData(8, 1, "user 1","password").WriteToFile(userFile);
	user = gcnew UserNode(userFile);
	RegisterForm^ reg = gcnew RegisterForm();
	if (user->isRegistered) {
		reg->user->Text = user->userName;
		reg->password->Text = user->password;
	}

	reg->ShowDialog();
	if (reg->isUserCloseWindow) {
		throw std::exception("user close reqistration window");
	}
	profilePicture->Image = Image::FromFile(userPhoto + user->pictureIndex + ".png");;
	user->isMainUser = true;

}

System::Void MyForm::downloadChats() {
	std::string name;
	MarshalString(user->userName, name);
	CUser u(name.c_str(), "", user->pictureIndex);
	server->Start(u);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	reciver = new MailSlotsReciver(name);// хз чи тут , треба  буде затестити , не вникав 
	workerThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::threadReceivMessages));//// поки сюди
	//////////////////////////////////////////////////////////////////////////////////////////////

	std::vector<CChat> v = server->update();
	if (!v.empty()) {
		for (int i = 0; i < v.size(); i++) {
			if (String::Compare(gcnew String(v[i].getUser1().getName()), user->userName) == 0) {
				chatNodes->Add(
					gcnew ChatNode(
						gcnew String(v[i].getUser2().getName()),
						"",
						v[i].getUnread1(),
						v[i].getUser2().getPicture(),
						v[i].getUser2().getStatus(),
						v[i].getChatId()));
			}
			else {
				chatNodes->Add(
					gcnew ChatNode(
						gcnew String(v[i].getUser1().getName()),
						"",
						v[i].getUnread2(),
						v[i].getUser1().getPicture(),
						v[i].getUser1().getStatus(),
						v[i].getChatId()));
			}

		}


		SuspendLayout();

		// Конвертуємо ArrayList до array<ChatNode^>
		array<ChatNode^>^ chatNodesArray = gcnew array<ChatNode^>(chatNodes->Count);
		chatNodes->CopyTo(chatNodesArray);

		placeForChats->Controls->AddRange(chatNodesArray);
		ResumeLayout();

	}
}

System::Void MyForm::setCurrentChat(ChatNode^ node) {
	if (currentNode)
		currentNode->resetColor();
	currentNode = node;
	currentChatName->Text = node->chatName->Text;
	currentChatStatus->Text = node->online->Text;
	currentChatPicture->Image = Image::FromFile(userPhoto + node->picture + ".png");
	photoOtherUser->Image = Image::FromFile(userPhoto + node->picture + ".png");
	nameOtherUser->Text = node->chatName->Text;

	receiveMessagesRange();

	SuspendLayout();
	VScrollBarForMessages->BindingContainer = currentNode->messageView;
	placeForMessages->Controls->Clear();
	placeForMessages->Controls->Add(currentNode->messageView);
	ResumeLayout();
}

 System::Void MyForm::sendButton_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ message = sendText->Text;
	std::string msg;
	if (!String::IsNullOrEmpty(message) && currentNode != nullptr) {
		MarshalString(message, msg);
		if (server->sendMessage(CMessage(msg.c_str(), -1, currentNode->id))) {
			sendText->Text = "";
			currentNode->addMessage(gcnew MessageNode(message, true, user->pictureIndex));
		}
		else {
			MessageBox::Show("Unable to connect to server", "Unable connection",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}


void MyForm::MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

 Void MyForm::receiveMessagesRange() {
	std::vector<CMessage> v;
	int countCurrentMsg = currentNode->messageView->Controls->Count;
	array<MessageNode^>^ result;
	int newMsg = Int64::Parse(currentNode->countNewMessage->Text);
	v = server->getAllMessageFromChat(CChat(currentNode->id));
	if (v.size() > countCurrentMsg) {
		if (countCurrentMsg == 0) {
			int ten = (newMsg + 5 < v.size() ? newMsg + 5 : v.size());
			v = std::vector<CMessage>(v.begin(), v.begin() + ten);
			result = gcnew array<MessageNode^>(v.size());

		}
		else if (newMsg != 0) {
			v = std::vector<CMessage>(v.begin(), v.begin() + newMsg);
			result = gcnew array<MessageNode^>(v.size());

		}
		else {
			int ten = (countCurrentMsg + 10 < v.size() ? countCurrentMsg + 10 : v.size());
			v = std::vector<CMessage>(v.begin() + countCurrentMsg, v.begin() + ten);
			result = gcnew array<MessageNode^>(v.size());

		}
		for (size_t i = 0; i < v.size(); ++i) {
			result[i] = gcnew
				MessageNode(
					gcnew String(v[i].get_text().c_str()),
					v[i].get_is_my_msg(),
					v[i].get_is_my_msg() ? user->pictureIndex : currentNode->picture
				);
		}
		addMessagesToForm(result, newMsg == 0);
	}
}


System::Void MyForm::addMessagesToForm(array<MessageNode^>^ msg, bool isOld) {
	SuspendLayout();
	if (isOld) {
		List<Control^>^ oldControls = gcnew List<Control^>();
		for each (Control ^ control in currentNode->messageView->Controls) {
			oldControls->Add(control);//тут наче  ж збирались кожен раз перевантажувати ?
		}
		currentNode->messageView->Controls->Clear();
		for (size_t i = 0; i < msg->Length; ++i) {
			currentNode->addMessage(msg[i]);
		}
		currentNode->messageView->Controls->AddRange(oldControls->ToArray());
	}
	else {
		for (size_t i = 0; i < msg->Length; ++i) {
			currentNode->addMessage(msg[i]);
		}
	}
	ResumeLayout();
}

System::Void MyForm::CreateNewChat_Click(System::Object^ sender, System::EventArgs^ e) {
	UsersViewForm^ usersWievForm = gcnew UsersViewForm();
	usersWievForm->ShowDialog();
	if (usersWievForm->resultUser != nullptr) {
		array<ChatNode^>^ chatNodesArray = gcnew array<ChatNode^>(chatNodes->Count);
		chatNodes->CopyTo(chatNodesArray);
		for (size_t i = 0; i < chatNodes->Count; i++) {
			if (String::Equals(chatNodesArray[i]->chatName, usersWievForm->resultUser->userName)) {
				setCurrentChat(chatNodesArray[i]);
				return;
			}
		}
		std::string name;
		MarshalString(usersWievForm->resultUser->userName, name);
		if (server->addNewChat(CUser(name.c_str(), "", usersWievForm->resultUser->pictureIndex))) {
			ChatNode^ n = gcnew ChatNode(usersWievForm->resultUser->userName,
				"",
				0,
				usersWievForm->resultUser->pictureIndex,
				String::Equals(usersWievForm->resultUser->online, "Online"),
				-1);
			chatNodes->Insert(0, n);

			placeForChats->Controls->Clear();
			placeForChats->Controls->Add(n);
			placeForChats->Controls->AddRange(chatNodesArray);

			setCurrentChat(n);
		}
	}
}

 System::Void MyForm::threadReceivMessages() {
	try {
		while (true) {
			std::string msg;

			if (reciver->recive(msg)) {
				array<MessageNode^>^ arr = gcnew array<MessageNode^>(1);
				arr[0] = gcnew MessageNode(gcnew String(msg.c_str()), false, currentNode->picture);
				BeginInvoke(gcnew addMessagesToFormDelegate(this, &MyForm::addMessagesToForm), arr, false);
			}
			else {
				break;
			}
		}
	}
	catch (std::exception e) {
		printf("%s", e.what());
	};
}

 System::Void MyForm::maximizeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentNode != nullptr) {
		currentNode->messageView->AutoScroll = false;
		currentNode->messageView->Width = placeForMessages->Width;
	}
	if (this->WindowState == FormWindowState::Maximized) {

		this->WindowState == FormWindowState::Normal;
	}
	else {
		this->WindowState = FormWindowState::Normal;
	}
	if (currentNode != nullptr)
		for (size_t i = 0; i < currentNode->messageView->Controls->Count; i++)
		{
			currentNode->messageView->Controls->default[i]->Width = placeForMessages->Width;
		}
	if (currentNode != nullptr)
		currentNode->messageView->AutoScroll = true;

}

System::Void MyForm::logOutButton_Click(System::Object^ sender, System::EventArgs^ e) {
	placeForChats->Controls->Clear();
	chatNodes->Clear();
	currentNode = nullptr;
	placeForMessages->Controls->Clear();
	onShow();
}

}
