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
		property String^ UserProfilePicture; // Шлях або URL до фото користувача

		ChatNode(String^ chatName, int newMessagesCount, String^ userProfilePicture)
		{
			ChatName = chatName;
			NewMessagesCount = newMessagesCount;
			UserProfilePicture = userProfilePicture;

			// Використовуйте власний метод для налаштування вигляду вузла
			UpdateNodeView();
		}

		void UpdateNodeView()
		{
			// Встановлення тексту вузла з урахуванням кількості нових повідомлень
			// Встановлення зображення користувача, якщо воно є
			if (!String::IsNullOrEmpty(UserProfilePicture))
			{
			}
		}

		virtual String^ ToString() override
		{
			// Перевизначте ToString для ListBox для власного відображення
			return String::Format("{0} ({1})", ChatName, NewMessagesCount);
		}
	};
}
