#pragma once
namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Guna::UI2::WinForms;

	ref class MessageNode : public Guna2GradientPanel
	{
	public:
		property Guna2CirclePictureBox^ photo;
		property Label^ message;

		MessageNode(String^ text, bool isMy, int photoIndex);

	};
}