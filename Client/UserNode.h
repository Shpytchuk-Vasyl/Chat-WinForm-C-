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
		  property int pictureIndex;
		  property String^ userName;
		  property Guna2CirclePictureBox^ photo;
		  property Label^ online;
		  property Label^ chatName;
		  property String^ password;
		  property bool isSelected;
		  property bool isMainUser;

	public: UserNode(String^ file);
	public: UserNode(String^ name, String^ passwor, int photoIndex, bool status);

	public: ~UserNode();
	
	

	private: System::Void mouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void mouseLeave(System::Object^ sender, System::EventArgs^ e);
	
	public:  ref class MyUserData {
	public:
		property int pictureIndex;
		property String^ userName;
		property String^ password;

		MyUserData() {}

		MyUserData(int _pictureIndex, String^ _userName, String^ _password) {
			pictureIndex = _pictureIndex;
			userName = _userName;
			password = _password;
		}

		// Метод для запису об'єкта в бінарний файл
		bool WriteToFile(String^ fileName) {
			try {
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
				BinaryWriter^ writer = gcnew BinaryWriter(fs);

			

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