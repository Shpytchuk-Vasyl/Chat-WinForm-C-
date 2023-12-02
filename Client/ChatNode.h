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


	ref class MessageNode : public Guna2GradientPanel
	{
	public:
		property Guna2CirclePictureBox^ photo;
		property Label^ message;

		MessageNode(String^ text, bool isMy, int photoIndex) : Guna2GradientPanel() {



			this->photo = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->photo->BackColor = System::Drawing::Color::Transparent;
			this->photo->FillColor = System::Drawing::Color::Transparent;
			this->photo->Image = Image::FromFile("userPhotos/user" + photoIndex + ".png");
			this->photo->ImageRotate = 0;
			this->photo->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->photo->ShadowDecoration->Enabled = true;
			this->photo->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->photo->Size = System::Drawing::Size(36, 36);
			this->photo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->photo->TabStop = false;
			this->photo->UseWaitCursor = true;
			//this->photo->Location = System::Drawing::Point(20, 20);

			this->message = gcnew Label();
			this->message->AutoSize = true;
			this->message->BackColor = System::Drawing::Color::Transparent;
			this->message->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->message->ForeColor = System::Drawing::Color::White;
			this->message->Location = System::Drawing::Point(31, 26);
			this->message->Size = System::Drawing::Size(189, 23);
			this->message->TabIndex = 19;
			this->message->Text = text;
			if (isMy) {
				this->photo->Location = System::Drawing::Point(10, 10);
				this->message->Location = System::Drawing::Point(70, 10);
			}
			else {
				this->photo->Location = System::Drawing::Point(this->message->Size.Width - 10, 10);
				this->message->Location = System::Drawing::Point(10, 10);
			}
			this->BorderRadius = 15;

			this->Controls->Add(this->message);
			this->Controls->Add(this->photo);
			if (isMy) {
				this->Dock = System::Windows::Forms::DockStyle::Left;
				this->FillColor = System::Drawing::Color::FromArgb(255, 152, 93);
				this->FillColor2 = System::Drawing::Color::FromArgb(255, 61, 87);
			}
			else {
				this->Dock = System::Windows::Forms::DockStyle::Right;
				this->FillColor = System::Drawing::Color::FromArgb(250, 48, 90);
				this->FillColor2 = System::Drawing::Color::FromArgb(128, 36, 206);

			}
			this->Size = System::Drawing::Size(350, 80);



		}

	};





	
	
	
}
