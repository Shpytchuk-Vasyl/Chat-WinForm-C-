#pragma once
namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class ChatNode : public Object
	{
	public:
		property String^ ChatName;
		property int NewMessagesCount;
		property String^ UserProfilePicture; // ���� ��� URL �� ���� �����������

		ChatNode(String^ chatName, int newMessagesCount, String^ userProfilePicture)
		{
			ChatName = chatName;
			NewMessagesCount = newMessagesCount;
			UserProfilePicture = userProfilePicture;

			// �������������� ������� ����� ��� ������������ ������� �����
			UpdateNodeView();
		}

		void UpdateNodeView()
		{
			// ������������ ������ ����� � ����������� ������� ����� ����������
			// ������������ ���������� �����������, ���� ���� �
			if (!String::IsNullOrEmpty(UserProfilePicture))
			{
			}
		}

		virtual String^ ToString() override
		{
			// ������������ ToString ��� ListBox ��� �������� �����������
			return String::Format("{0} ({1})", ChatName, NewMessagesCount);
		}
	};
}
