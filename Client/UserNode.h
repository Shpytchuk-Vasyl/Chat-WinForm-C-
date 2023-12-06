#pragma once


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
	using namespace Guna::UI2::WinForms;

	ref class UserNode : public Guna2GradientPanel {
	public: property bool isRegistered;
	public: property int id;
	public: property int pictureIndex;
	public: property String^ userName;
		  property Guna2CirclePictureBox^ photo;
		  property Label^ online;
		  property Label^ chatName;
		  property String^ password;
		  property bool isSelected;

	public: UserNode(String^ file) {
		MyUserData^ data = gcnew MyUserData();
		isRegistered = data->ReadFromFile(file);
		id = data->id;
		pictureIndex = data->pictureIndex;
		userName = data->userName;
		password = data->password;
	}

	public: UserNode(String^ name, String^ passwor, int photoIndex, bool status, int user_id) : Guna2GradientPanel() {
		id = user_id;
		pictureIndex = photoIndex;
		userName = name;
		password = passwor;

		this->photo = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
		this->photo->BackColor = System::Drawing::Color::Transparent;
		this->photo->FillColor = System::Drawing::Color::Transparent;
		this->photo->Image = Image::FromFile("userPhotos/user" + photoIndex + ".png");
		this->photo->ImageRotate = 0;
		this->photo->Location = System::Drawing::Point(20, 20);
		this->photo->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
		this->photo->ShadowDecoration->Enabled = true;
		this->photo->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
		this->photo->Size = System::Drawing::Size(36, 36);
		this->photo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->photo->TabStop = false;
		this->photo->UseWaitCursor = true;


		this->online = (gcnew Label);
		this->online->AutoSize = true;
		this->online->BackColor = System::Drawing::Color::Transparent;
		this->online->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->online->ForeColor = System::Drawing::Color::Silver;
		this->online->Location = System::Drawing::Point(60, 40);
		this->online->Size = System::Drawing::Size(39, 17);
		this->online->Text = status ? "Online" : "Offline";
		this->online->UseWaitCursor = true;

		this->chatName = (gcnew Label);
		this->chatName->AutoSize = true;
		this->chatName->BackColor = System::Drawing::Color::Transparent;
		this->chatName->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->chatName->ForeColor = System::Drawing::Color::Silver;
		this->chatName->Location = System::Drawing::Point(60, 10);
		this->chatName->Size = System::Drawing::Size(42, 20);
		this->chatName->Text = name;


		this->BorderThickness = 2;
		this->Controls->Add(this->online);
		this->Controls->Add(this->chatName);
		this->Controls->Add(this->photo);
		this->CustomBorderColor = System::Drawing::Color::FromArgb(128, 36, 206);
		this->FillColor = System::Drawing::Color::FromArgb(23, 28, 41);
		this->FillColor2 = System::Drawing::Color::FromArgb(23, 28, 41);
		this->AutoSize = false;
		this->Location = System::Drawing::Point(3, 3);
		this->ShadowDecoration->Color = System::Drawing::Color::FromArgb(17, 22, 32);
		this->Size = System::Drawing::Size(200, 80);
		this->UseWaitCursor = true;

		this->MouseEnter += gcnew System::EventHandler(this, &UserNode::mouseEnter);
		this->MouseLeave += gcnew System::EventHandler(this, &UserNode::mouseLeave);

	}

	public: ~UserNode() {
			  MyUserData^ save = gcnew MyUserData(id, pictureIndex, userName, password);
			  save->WriteToFile("userData/user.bin");
	}
	
	

	private: System::Void mouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->FillColor = System::Drawing::Color::FromArgb(250, 48, 90);
		this->FillColor2 = System::Drawing::Color::FromArgb(128, 36, 206);
		this->ShadowDecoration->Color = Color::DeepPink;
	}
	private: System::Void mouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->FillColor = System::Drawing::Color::FromArgb(23, 28, 41);
		this->FillColor2 = System::Drawing::Color::FromArgb(23, 28, 41);
		this->ShadowDecoration->Color = Color::FromArgb(17, 22, 32);
	}

	public:  ref class MyUserData {
	public:
		property int id;
		property int pictureIndex;
		property String^ userName;
		property String^ password;

		MyUserData() {}

		MyUserData(int _id, int _pictureIndex, String^ _userName, String^ _password) {
			id = _id;
			pictureIndex = _pictureIndex;
			userName = _userName;
			password = _password;
		}

		// Метод для запису об'єкта в бінарний файл
		bool WriteToFile(String^ fileName) {
			try {
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
				BinaryWriter^ writer = gcnew BinaryWriter(fs);

				// Запис id
				writer->Write(id);

				// Запис pictureIndex
				writer->Write(pictureIndex);

				// Запис userName
				writer->Write(userName);

				// Запис password
				writer->Write(password);

				// Закриття потоків
				writer->Close();
				fs->Close();
				return true;
			}
			catch (IOException^ e) {
				Console::WriteLine("An error occurred while writing to the file: {0}", e->Message);
				return false;
			}
		}

		// Метод для зчитування об'єкта з бінарного файлу
		bool ReadFromFile(String^ fileName) {
			try {
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
				BinaryReader^ reader = gcnew BinaryReader(fs);

				// Зчитування id
				id = reader->ReadInt32();

				// Зчитування pictureIndex
				pictureIndex = reader->ReadInt32();

				// Зчитування userName
				userName = reader->ReadString();

				// Зчитування password
				password = reader->ReadString();

				// Закриття потоків
				reader->Close();
				fs->Close();
			}
			catch (IOException^ e) {
				return false;
			}
			return true;
		}
	};

	};

}