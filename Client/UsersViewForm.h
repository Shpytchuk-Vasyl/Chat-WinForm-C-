#pragma once
#include "UserNode.h"
namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UsersViewForm
	/// </summary>
	public ref class UsersViewForm : public System::Windows::Forms::Form
	{
	public:
		UsersViewForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UsersViewForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel2;
	private: Guna::UI2::WinForms::Guna2TextBox^ searchText;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: Guna::UI2::WinForms::Guna2VScrollBar^ VScrollBarForUsers;

	private: Guna::UI2::WinForms::Guna2ControlBox^ exitButton;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->VScrollBarForUsers = (gcnew Guna::UI2::WinForms::Guna2VScrollBar());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->guna2Panel2 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->exitButton = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->searchText = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2Panel1->SuspendLayout();
			this->guna2Panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->guna2Panel1->Controls->Add(this->VScrollBarForUsers);
			this->guna2Panel1->Controls->Add(this->flowLayoutPanel1);
			this->guna2Panel1->Controls->Add(this->guna2Panel2);
			this->guna2Panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->guna2Panel1->Location = System::Drawing::Point(0, 0);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->Size = System::Drawing::Size(366, 718);
			this->guna2Panel1->TabIndex = 0;
			// 
			// VScrollBarForUsers
			// 
			this->VScrollBarForUsers->AutoRoundedCorners = true;
			this->VScrollBarForUsers->AutoScroll = true;
			this->VScrollBarForUsers->AutoSize = true;
			this->VScrollBarForUsers->BackColor = System::Drawing::Color::Transparent;
			this->VScrollBarForUsers->BindingContainer = this->flowLayoutPanel1;
			this->VScrollBarForUsers->BorderColor = System::Drawing::Color::Transparent;
			this->VScrollBarForUsers->BorderRadius = 4;
			this->VScrollBarForUsers->FillColor = System::Drawing::Color::Transparent;
			this->VScrollBarForUsers->InUpdate = false;
			this->VScrollBarForUsers->LargeChange = 10;
			this->VScrollBarForUsers->Location = System::Drawing::Point(356, 54);
			this->VScrollBarForUsers->Margin = System::Windows::Forms::Padding(0);
			this->VScrollBarForUsers->MaximumSize = System::Drawing::Size(10, 0);
			this->VScrollBarForUsers->Name = L"VScrollBarForUsers";
			this->VScrollBarForUsers->ScrollbarSize = 10;
			this->VScrollBarForUsers->Size = System::Drawing::Size(10, 664);
			this->VScrollBarForUsers->TabIndex = 20;
			this->VScrollBarForUsers->ThumbColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->VScrollBarForUsers->ThumbSize = 5;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 54);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 3, 10, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(366, 664);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// guna2Panel2
			// 
			this->guna2Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->guna2Panel2->Controls->Add(this->exitButton);
			this->guna2Panel2->Controls->Add(this->searchText);
			this->guna2Panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->guna2Panel2->Location = System::Drawing::Point(0, 0);
			this->guna2Panel2->Name = L"guna2Panel2";
			this->guna2Panel2->Size = System::Drawing::Size(366, 54);
			this->guna2Panel2->TabIndex = 0;
			// 
			// exitButton
			// 
			this->exitButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exitButton->FillColor = System::Drawing::Color::Transparent;
			this->exitButton->IconColor = System::Drawing::Color::White;
			this->exitButton->Location = System::Drawing::Point(307, 0);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(59, 51);
			this->exitButton->TabIndex = 19;
			// 
			// searchText
			// 
			this->searchText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchText->BorderColor = System::Drawing::Color::Transparent;
			this->searchText->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->searchText->DefaultText = L"";
			this->searchText->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->searchText->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->searchText->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->searchText->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->searchText->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->searchText->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->searchText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->searchText->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->searchText->Location = System::Drawing::Point(14, 9);
			this->searchText->Name = L"searchText";
			this->searchText->PasswordChar = '\0';
			this->searchText->PlaceholderText = L"Search";
			this->searchText->SelectedText = L"";
			this->searchText->Size = System::Drawing::Size(264, 36);
			this->searchText->TabIndex = 1;
			this->searchText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UsersViewForm::searchText_KeyPress);
			// 
			// UsersViewForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(366, 718);
			this->Controls->Add(this->guna2Panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"UsersViewForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->guna2Panel1->ResumeLayout(false);
			this->guna2Panel1->PerformLayout();
			this->guna2Panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion



	public: property UserNode^ resultUser;




private: System::Void searchText_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);

};
}
