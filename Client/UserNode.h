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

		// ����� ��� ������ ��'���� � ������� ����
		bool WriteToFile(String^ fileName) {
			try {
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
				BinaryWriter^ writer = gcnew BinaryWriter(fs);

			

				// ����� pictureIndex
				writer->Write(pictureIndex);

				// ����� userName
				writer->Write(userName);

				// ����� password
				writer->Write(password);

				// �������� ������
				writer->Close();
				fs->Close();
				return true;
			}
			catch (IOException^ e) {
				Console::WriteLine("An error occurred while writing to the file: {0}", e->Message);
				return false;
			}
		}

		// ����� ��� ���������� ��'���� � �������� �����
		bool ReadFromFile(String^ fileName) {
			try {
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
				BinaryReader^ reader = gcnew BinaryReader(fs);


				// ���������� pictureIndex
				pictureIndex = reader->ReadInt32();

				// ���������� userName
				userName = reader->ReadString();

				// ���������� password
				password = reader->ReadString();

				// �������� ������
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