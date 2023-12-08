#pragma once
#include "MessageNode.h"
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
		property FlowLayoutPanel^ messageView;
		property int picture;
		property int id;

	public: ChatNode(String^ strChatName, String^ strLastMessage, int intCountNewMessage, int photoIndex, bool status, int id); 

	public: System::Void resetColor(); 

	public: System::Void addMessage(MessageNode^ msg);

	public: System::Void mouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	public: System::Void mouseEnter(System::Object^ sender, System::EventArgs^ e);

	public: System::Void mouseLeave(System::Object^ sender, System::EventArgs^ e);

	};

	
		
}
