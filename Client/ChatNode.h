#pragma once
#include "MyForm.h"
namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Guna::UI2::WinForms;


	ref class ChatNode : public Guna2GradientPanel
	{
	public:
		property Guna2CirclePictureBox^ photo;
		property Label^ chatName;
		property Label^ lastMessage;
		property Label^ online;
		property Guna2CircleButton^ countNewMessage;
		property FlowLayoutPanel^  messageView;

	public:

		ChatNode(String^ strChatName, String^ strLastMessage, int intCountNewMessage, int photoIndex, bool status) : Guna2GradientPanel() {
			//System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->countNewMessage = (gcnew Guna::UI2::WinForms::Guna2CircleButton());
			this->countNewMessage->BackColor = System::Drawing::Color::Transparent;
			this->countNewMessage->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->countNewMessage->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->countNewMessage->DisabledState->FillColor = System::Drawing::Color::FromArgb(169,169, 169);
			this->countNewMessage->DisabledState->ForeColor = System::Drawing::Color::FromArgb(141,141, 141);
			this->countNewMessage->FillColor = System::Drawing::Color::Magenta;
			this->countNewMessage->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->countNewMessage->ForeColor = System::Drawing::Color::White;
			this->countNewMessage->Location = System::Drawing::Point(150, 30);
			this->countNewMessage->Name = "countNewMessage : " + strChatName;
			this->countNewMessage->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->countNewMessage->Size = System::Drawing::Size(30, 30);
			//this->countNewMessage->TabIndex = 20;
			this->countNewMessage->Text = intCountNewMessage.ToString();
			this->countNewMessage->UseWaitCursor = true;


			this->photo = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->photo->BackColor = System::Drawing::Color::Transparent;
			this->photo->FillColor = System::Drawing::Color::Transparent;
			this->photo->Image = Image::FromFile("userPhotos/user" + photoIndex + ".png");
			this->photo->ImageRotate = 0;
			this->photo->Location = System::Drawing::Point(20, 20);
			this->photo->Name = "photo : " + strChatName;
			this->photo->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->photo->ShadowDecoration->Enabled = true;
			this->photo->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->photo->Size = System::Drawing::Size(36, 36);
			this->photo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			//this->photo->TabIndex = 11;
			this->photo->TabStop = false;
			this->photo->UseWaitCursor = true;

			this->online = (gcnew Label);
			this->online->AutoSize = true;
			this->online->BackColor = System::Drawing::Color::Transparent;
			this->online->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->online->ForeColor = System::Drawing::Color::Silver;
			this->online->Location = System::Drawing::Point(150, 10);
			this->online->Name = L"online : " + strChatName;
			this->online->Size = System::Drawing::Size(39, 17);
			//this->online->TabIndex = 14;
			this->online->Text = status ? "Online" : "Offline";
			this->online->UseWaitCursor = true;




			this->lastMessage = (gcnew Label);
			this->lastMessage->AutoSize = true;
			this->lastMessage->BackColor = System::Drawing::Color::Transparent;
			this->lastMessage->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lastMessage->ForeColor = System::Drawing::Color::Gray;
			this->lastMessage->Location = System::Drawing::Point(60, 40);
			this->lastMessage->Name = L"lastMessage : " + strChatName;
			this->lastMessage->Size = System::Drawing::Size(50, 20);
			//this->lastMessage->TabIndex = 13;
			this->lastMessage->Text = strLastMessage;
			this->lastMessage->UseWaitCursor = true;


			this->chatName = (gcnew Label);
			this->chatName->AutoSize = true;
			this->chatName->BackColor = System::Drawing::Color::Transparent;
			this->chatName->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->chatName->ForeColor = System::Drawing::Color::Silver;
			this->chatName->Location = System::Drawing::Point(60, 10);
			this->chatName->Name = "chatName : " + strChatName;
			this->chatName->Size = System::Drawing::Size(42, 20);
			//this->chatName->TabIndex = 16;
			this->chatName->Text = strChatName;



			
			
			this->BorderThickness = 2;
			this->Controls->Add(this->countNewMessage);
			this->Controls->Add(this->online);
			this->Controls->Add(this->chatName);
			this->Controls->Add(this->lastMessage);
			this->Controls->Add(this->photo);
			this->CustomBorderColor = System::Drawing::Color::FromArgb(128,36, 206);
			this->FillColor = System::Drawing::Color::FromArgb(23,28,41);
			this->FillColor2 = System::Drawing::Color::FromArgb(23,28, 41);
			this->AutoSize = false;
			//this->Anchor = (AnchorStyles::Left | AnchorStyles::Top);
			this->Location = System::Drawing::Point(3, 3);
			this->Name = "ChatNode : " + strChatName;
			this->ShadowDecoration->Color = System::Drawing::Color::FromArgb(17, 22,32);
			this->Size = System::Drawing::Size(200, 80);
			this->UseWaitCursor = true;
		
			this->MouseEnter += gcnew System::EventHandler(this, &ChatNode::mouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &ChatNode::mouseLeave);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ChatNode::mouseClick);
		
		}

		private: System::Void mouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->FillColor = System::Drawing::Color::FromArgb(250, 48, 90);
			this->FillColor2 = System::Drawing::Color::FromArgb(128, 36, 206);
			MyForm::setCurrent(this);
		}

		public: System::Void resetColor() {
			this->FillColor = System::Drawing::Color::FromArgb(23, 28, 41);
			this->FillColor2 = System::Drawing::Color::FromArgb(23, 28, 41);
		}
	
		private: System::Void mouseEnter(System::Object^ sender, System::EventArgs^ e) {
			((Guna::UI2::WinForms::Guna2GradientPanel^)sender)->ShadowDecoration->Color = Color::DeepPink;
		}
		private: System::Void mouseLeave(System::Object^ sender, System::EventArgs^ e) {
			((Guna::UI2::WinForms::Guna2GradientPanel^)sender)->ShadowDecoration->Color = Color::FromArgb(17, 22, 32);

		}

	};
}
