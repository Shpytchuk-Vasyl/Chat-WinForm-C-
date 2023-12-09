#pragma once
#include "ServerConnection.h"
#include "ChatNode.h"
#include <msclr/marshal_cppstd.h>
#include "UsersViewForm.h"
#include "MailSlotsReciver.h"
#include "RegisterForm.h"

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


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		
		MyForm(void)
		{
			InitializeComponent();
			pointer = this;
			chatNodes = gcnew ArrayList();
			onShow();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				if (server != nullptr) {
					server->finishWork();
					server = nullptr;
					user->~UserNode();
					user = nullptr;
				}
				delete components;
				//if (server) delete server;
			}
		}
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel2;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel_top;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel4;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel5;
	private: Guna::UI2::WinForms::Guna2Button^ CreateNewChat;
	private: Guna::UI2::WinForms::Guna2Button^ logOutButton;


	private: Guna::UI2::WinForms::Guna2Button^ guna2Button4;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button3;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button2;
	private: Guna::UI2::WinForms::Guna2VScrollBar^ VScrollBarChats;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel8;
	private: System::Windows::Forms::FlowLayoutPanel^ placeForChats;
    private: Guna::UI2::WinForms::Guna2DragControl^ guna2DragControl1;
    private: Guna::UI2::WinForms::Guna2ControlBox^ minimizeButton;
    private: Guna::UI2::WinForms::Guna2ControlBox^ maximizeButton;
    private: Guna::UI2::WinForms::Guna2ControlBox^ exitButton;
    private: Guna::UI2::WinForms::Guna2ShadowForm^ guna2ShadowForm1;
    private: Guna::UI2::WinForms::Guna2CirclePictureBox^ profilePicture;
    private: Guna::UI2::WinForms::Guna2CircleProgressBar^ guna2CircleProgressBar2;
    private: Guna::UI2::WinForms::Guna2CircleProgressBar^ guna2CircleProgressBar1;
    private: Guna::UI2::WinForms::Guna2CirclePictureBox^ photoOtherUser;
    private: System::Windows::Forms::Label^ nameOtherUser;
    private: Guna::UI2::WinForms::Guna2CircleButton^ sendButton;
    private: Guna::UI2::WinForms::Guna2TextBox^ searchText;
    private: Guna::UI2::WinForms::Guna2TextBox^ sendText;
    private: System::Windows::Forms::Label^ currentChatStatus;
    private: System::Windows::Forms::Label^ currentChatName;
    private: Guna::UI2::WinForms::Guna2CirclePictureBox^ currentChatPicture;
    public: Guna::UI2::WinForms::Guna2Panel^ placeForMessages;
	private: Guna::UI2::WinForms::Guna2VScrollBar^ VScrollBarForMessages;
	private: System::Windows::Forms::Timer^ timerUpdateChats;



	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->logOutButton = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button4 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button3 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button2 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->CreateNewChat = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->profilePicture = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->guna2Panel2 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->minimizeButton = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->maximizeButton = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->exitButton = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->nameOtherUser = (gcnew System::Windows::Forms::Label());
			this->guna2CircleProgressBar2 = (gcnew Guna::UI2::WinForms::Guna2CircleProgressBar());
			this->guna2CircleProgressBar1 = (gcnew Guna::UI2::WinForms::Guna2CircleProgressBar());
			this->photoOtherUser = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->guna2Panel_top = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->currentChatStatus = (gcnew System::Windows::Forms::Label());
			this->currentChatName = (gcnew System::Windows::Forms::Label());
			this->currentChatPicture = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->searchText = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2Panel4 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->VScrollBarChats = (gcnew Guna::UI2::WinForms::Guna2VScrollBar());
			this->placeForChats = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->guna2Panel5 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel8 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->sendButton = (gcnew Guna::UI2::WinForms::Guna2CircleButton());
			this->sendText = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2DragControl1 = (gcnew Guna::UI2::WinForms::Guna2DragControl(this->components));
			this->guna2ShadowForm1 = (gcnew Guna::UI2::WinForms::Guna2ShadowForm(this->components));
			this->placeForMessages = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->VScrollBarForMessages = (gcnew Guna::UI2::WinForms::Guna2VScrollBar());
			this->timerUpdateChats = (gcnew System::Windows::Forms::Timer(this->components));
			this->guna2Panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePicture))->BeginInit();
			this->guna2Panel2->SuspendLayout();
			this->guna2CircleProgressBar2->SuspendLayout();
			this->guna2CircleProgressBar1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoOtherUser))->BeginInit();
			this->guna2Panel_top->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentChatPicture))->BeginInit();
			this->guna2Panel4->SuspendLayout();
			this->guna2Panel5->SuspendLayout();
			this->guna2Panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->guna2Panel1->Controls->Add(this->logOutButton);
			this->guna2Panel1->Controls->Add(this->guna2Button4);
			this->guna2Panel1->Controls->Add(this->guna2Button3);
			this->guna2Panel1->Controls->Add(this->guna2Button2);
			this->guna2Panel1->Controls->Add(this->CreateNewChat);
			this->guna2Panel1->Controls->Add(this->profilePicture);
			this->guna2Panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->guna2Panel1->Location = System::Drawing::Point(0, 0);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->Size = System::Drawing::Size(72, 590);
			this->guna2Panel1->TabIndex = 0;
			// 
			// logOutButton
			// 
			this->logOutButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->logOutButton->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->logOutButton->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->logOutButton->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->logOutButton->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->logOutButton->FillColor = System::Drawing::Color::Transparent;
			this->logOutButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->logOutButton->ForeColor = System::Drawing::Color::White;
			this->logOutButton->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->logOutButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logOutButton.Image")));
			this->logOutButton->Location = System::Drawing::Point(0, 540);
			this->logOutButton->Name = L"logOutButton";
			this->logOutButton->Size = System::Drawing::Size(72, 48);
			this->logOutButton->TabIndex = 5;
			this->logOutButton->Click += gcnew System::EventHandler(this, &MyForm::logOutButton_Click);
			// 
			// guna2Button4
			// 
			this->guna2Button4->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button4->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button4->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2Button4->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2Button4->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2Button4->ForeColor = System::Drawing::Color::White;
			this->guna2Button4->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->guna2Button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button4.Image")));
			this->guna2Button4->Location = System::Drawing::Point(0, 241);
			this->guna2Button4->Name = L"guna2Button4";
			this->guna2Button4->Size = System::Drawing::Size(72, 45);
			this->guna2Button4->TabIndex = 4;
			// 
			// guna2Button3
			// 
			this->guna2Button3->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button3->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button3->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2Button3->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2Button3->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2Button3->ForeColor = System::Drawing::Color::White;
			this->guna2Button3->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->guna2Button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button3.Image")));
			this->guna2Button3->Location = System::Drawing::Point(0, 190);
			this->guna2Button3->Name = L"guna2Button3";
			this->guna2Button3->Size = System::Drawing::Size(72, 45);
			this->guna2Button3->TabIndex = 3;
			// 
			// guna2Button2
			// 
			this->guna2Button2->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button2->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button2->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2Button2->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2Button2->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2Button2->ForeColor = System::Drawing::Color::White;
			this->guna2Button2->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->guna2Button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button2.Image")));
			this->guna2Button2->Location = System::Drawing::Point(0, 139);
			this->guna2Button2->Name = L"guna2Button2";
			this->guna2Button2->Size = System::Drawing::Size(72, 45);
			this->guna2Button2->TabIndex = 2;
			// 
			// CreateNewChat
			// 
			this->CreateNewChat->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->CreateNewChat->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->CreateNewChat->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->CreateNewChat->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->CreateNewChat->FillColor = System::Drawing::Color::Transparent;
			this->CreateNewChat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->CreateNewChat->ForeColor = System::Drawing::Color::White;
			this->CreateNewChat->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->CreateNewChat->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CreateNewChat.Image")));
			this->CreateNewChat->Location = System::Drawing::Point(0, 88);
			this->CreateNewChat->Name = L"CreateNewChat";
			this->CreateNewChat->Size = System::Drawing::Size(72, 45);
			this->CreateNewChat->TabIndex = 1;
			this->CreateNewChat->Click += gcnew System::EventHandler(this, &MyForm::CreateNewChat_Click);
			// 
			// profilePicture
			// 
			this->profilePicture->FillColor = System::Drawing::Color::Transparent;
			this->profilePicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"profilePicture.Image")));
			this->profilePicture->ImageRotate = 0;
			this->profilePicture->Location = System::Drawing::Point(18, 18);
			this->profilePicture->Name = L"profilePicture";
			this->profilePicture->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->profilePicture->ShadowDecoration->CustomizableEdges->BottomLeft = false;
			this->profilePicture->ShadowDecoration->CustomizableEdges->BottomRight = false;
			this->profilePicture->ShadowDecoration->CustomizableEdges->TopLeft = false;
			this->profilePicture->ShadowDecoration->CustomizableEdges->TopRight = false;
			this->profilePicture->ShadowDecoration->Enabled = true;
			this->profilePicture->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->profilePicture->Size = System::Drawing::Size(36, 36);
			this->profilePicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->profilePicture->TabIndex = 0;
			this->profilePicture->TabStop = false;
			// 
			// guna2Panel2
			// 
			this->guna2Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->guna2Panel2->Controls->Add(this->minimizeButton);
			this->guna2Panel2->Controls->Add(this->maximizeButton);
			this->guna2Panel2->Controls->Add(this->exitButton);
			this->guna2Panel2->Controls->Add(this->nameOtherUser);
			this->guna2Panel2->Controls->Add(this->guna2CircleProgressBar2);
			this->guna2Panel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->guna2Panel2->Location = System::Drawing::Point(1044, 0);
			this->guna2Panel2->Name = L"guna2Panel2";
			this->guna2Panel2->Size = System::Drawing::Size(267, 590);
			this->guna2Panel2->TabIndex = 1;
			// 
			// minimizeButton
			// 
			this->minimizeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minimizeButton->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MinimizeBox;
			this->minimizeButton->FillColor = System::Drawing::Color::Transparent;
			this->minimizeButton->IconColor = System::Drawing::Color::White;
			this->minimizeButton->Location = System::Drawing::Point(119, 3);
			this->minimizeButton->Name = L"minimizeButton";
			this->minimizeButton->Size = System::Drawing::Size(45, 29);
			this->minimizeButton->TabIndex = 20;
			// 
			// maximizeButton
			// 
			this->maximizeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->maximizeButton->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MaximizeBox;
			this->maximizeButton->FillColor = System::Drawing::Color::Transparent;
			this->maximizeButton->IconColor = System::Drawing::Color::White;
			this->maximizeButton->Location = System::Drawing::Point(168, 3);
			this->maximizeButton->Name = L"maximizeButton";
			this->maximizeButton->Size = System::Drawing::Size(45, 29);
			this->maximizeButton->TabIndex = 19;
			this->maximizeButton->Click += gcnew System::EventHandler(this, &MyForm::maximizeButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exitButton->FillColor = System::Drawing::Color::Transparent;
			this->exitButton->IconColor = System::Drawing::Color::White;
			this->exitButton->Location = System::Drawing::Point(219, 3);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(45, 29);
			this->exitButton->TabIndex = 18;
			// 
			// nameOtherUser
			// 
			this->nameOtherUser->AutoSize = true;
			this->nameOtherUser->BackColor = System::Drawing::Color::Transparent;
			this->nameOtherUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nameOtherUser->ForeColor = System::Drawing::Color::Silver;
			this->nameOtherUser->Location = System::Drawing::Point(121, 243);
			this->nameOtherUser->Name = L"nameOtherUser";
			this->nameOtherUser->Size = System::Drawing::Size(58, 22);
			this->nameOtherUser->TabIndex = 16;
			this->nameOtherUser->Text = L"User2";
			// 
			// guna2CircleProgressBar2
			// 
			this->guna2CircleProgressBar2->Animated = true;
			this->guna2CircleProgressBar2->Controls->Add(this->guna2CircleProgressBar1);
			this->guna2CircleProgressBar2->FillColor = System::Drawing::Color::Transparent;
			this->guna2CircleProgressBar2->FillThickness = 3;
			this->guna2CircleProgressBar2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2CircleProgressBar2->ForeColor = System::Drawing::Color::White;
			this->guna2CircleProgressBar2->Location = System::Drawing::Point(68, 49);
			this->guna2CircleProgressBar2->Minimum = 0;
			this->guna2CircleProgressBar2->Name = L"guna2CircleProgressBar2";
			this->guna2CircleProgressBar2->ProgressColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->guna2CircleProgressBar2->ProgressColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(61)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->guna2CircleProgressBar2->ProgressThickness = 3;
			this->guna2CircleProgressBar2->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CircleProgressBar2->Size = System::Drawing::Size(160, 160);
			this->guna2CircleProgressBar2->TabIndex = 9;
			this->guna2CircleProgressBar2->Text = L"guna2CircleProgressBar2";
			this->guna2CircleProgressBar2->Value = 40;
			// 
			// guna2CircleProgressBar1
			// 
			this->guna2CircleProgressBar1->Animated = true;
			this->guna2CircleProgressBar1->BackColor = System::Drawing::Color::Transparent;
			this->guna2CircleProgressBar1->Controls->Add(this->photoOtherUser);
			this->guna2CircleProgressBar1->FillColor = System::Drawing::Color::Transparent;
			this->guna2CircleProgressBar1->FillThickness = 3;
			this->guna2CircleProgressBar1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2CircleProgressBar1->ForeColor = System::Drawing::Color::White;
			this->guna2CircleProgressBar1->Location = System::Drawing::Point(5, 5);
			this->guna2CircleProgressBar1->Minimum = 0;
			this->guna2CircleProgressBar1->Name = L"guna2CircleProgressBar1";
			this->guna2CircleProgressBar1->ProgressColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->guna2CircleProgressBar1->ProgressColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2CircleProgressBar1->ProgressThickness = 3;
			this->guna2CircleProgressBar1->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CircleProgressBar1->Size = System::Drawing::Size(150, 150);
			this->guna2CircleProgressBar1->TabIndex = 8;
			this->guna2CircleProgressBar1->Text = L"guna2CircleProgressBar1";
			this->guna2CircleProgressBar1->Value = 33;
			// 
			// photoOtherUser
			// 
			this->photoOtherUser->BackColor = System::Drawing::Color::Transparent;
			this->photoOtherUser->FillColor = System::Drawing::Color::Transparent;
			this->photoOtherUser->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"photoOtherUser.Image")));
			this->photoOtherUser->ImageRotate = 0;
			this->photoOtherUser->Location = System::Drawing::Point(10, 8);
			this->photoOtherUser->Name = L"photoOtherUser";
			this->photoOtherUser->ShadowDecoration->Color = System::Drawing::Color::Transparent;
			this->photoOtherUser->ShadowDecoration->CustomizableEdges->BottomLeft = false;
			this->photoOtherUser->ShadowDecoration->CustomizableEdges->BottomRight = false;
			this->photoOtherUser->ShadowDecoration->CustomizableEdges->TopLeft = false;
			this->photoOtherUser->ShadowDecoration->CustomizableEdges->TopRight = false;
			this->photoOtherUser->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->photoOtherUser->Size = System::Drawing::Size(130, 130);
			this->photoOtherUser->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->photoOtherUser->TabIndex = 7;
			this->photoOtherUser->TabStop = false;
			// 
			// guna2Panel_top
			// 
			this->guna2Panel_top->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->guna2Panel_top->Controls->Add(this->currentChatStatus);
			this->guna2Panel_top->Controls->Add(this->currentChatName);
			this->guna2Panel_top->Controls->Add(this->currentChatPicture);
			this->guna2Panel_top->Controls->Add(this->searchText);
			this->guna2Panel_top->Dock = System::Windows::Forms::DockStyle::Top;
			this->guna2Panel_top->Location = System::Drawing::Point(72, 0);
			this->guna2Panel_top->Name = L"guna2Panel_top";
			this->guna2Panel_top->Size = System::Drawing::Size(972, 67);
			this->guna2Panel_top->TabIndex = 2;
			// 
			// currentChatStatus
			// 
			this->currentChatStatus->AutoSize = true;
			this->currentChatStatus->BackColor = System::Drawing::Color::Transparent;
			this->currentChatStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentChatStatus->ForeColor = System::Drawing::Color::Silver;
			this->currentChatStatus->Location = System::Drawing::Point(361, 37);
			this->currentChatStatus->Name = L"currentChatStatus";
			this->currentChatStatus->Size = System::Drawing::Size(45, 16);
			this->currentChatStatus->TabIndex = 17;
			this->currentChatStatus->Text = L"Online";
			// 
			// currentChatName
			// 
			this->currentChatName->AutoSize = true;
			this->currentChatName->BackColor = System::Drawing::Color::Transparent;
			this->currentChatName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->currentChatName->ForeColor = System::Drawing::Color::Silver;
			this->currentChatName->Location = System::Drawing::Point(358, 16);
			this->currentChatName->Name = L"currentChatName";
			this->currentChatName->Size = System::Drawing::Size(48, 18);
			this->currentChatName->TabIndex = 16;
			this->currentChatName->Text = L"User1";
			// 
			// currentChatPicture
			// 
			this->currentChatPicture->BackColor = System::Drawing::Color::Transparent;
			this->currentChatPicture->FillColor = System::Drawing::Color::Transparent;
			this->currentChatPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"currentChatPicture.Image")));
			this->currentChatPicture->ImageRotate = 0;
			this->currentChatPicture->Location = System::Drawing::Point(301, 18);
			this->currentChatPicture->Name = L"currentChatPicture";
			this->currentChatPicture->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->currentChatPicture->ShadowDecoration->Enabled = true;
			this->currentChatPicture->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->currentChatPicture->Size = System::Drawing::Size(36, 36);
			this->currentChatPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->currentChatPicture->TabIndex = 16;
			this->currentChatPicture->TabStop = false;
			// 
			// searchText
			// 
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
			this->searchText->Location = System::Drawing::Point(11, 16);
			this->searchText->Name = L"searchText";
			this->searchText->PasswordChar = '\0';
			this->searchText->PlaceholderText = L"Search";
			this->searchText->SelectedText = L"";
			this->searchText->Size = System::Drawing::Size(268, 36);
			this->searchText->TabIndex = 0;
			// 
			// guna2Panel4
			// 
			this->guna2Panel4->AutoScroll = true;
			this->guna2Panel4->Controls->Add(this->VScrollBarChats);
			this->guna2Panel4->Controls->Add(this->placeForChats);
			this->guna2Panel4->Dock = System::Windows::Forms::DockStyle::Left;
			this->guna2Panel4->Location = System::Drawing::Point(72, 67);
			this->guna2Panel4->Name = L"guna2Panel4";
			this->guna2Panel4->Size = System::Drawing::Size(295, 523);
			this->guna2Panel4->TabIndex = 3;
			// 
			// VScrollBarChats
			// 
			this->VScrollBarChats->AutoRoundedCorners = true;
			this->VScrollBarChats->AutoScroll = true;
			this->VScrollBarChats->BackColor = System::Drawing::Color::Black;
			this->VScrollBarChats->BindingContainer = this->placeForChats;
			this->VScrollBarChats->BorderColor = System::Drawing::Color::Transparent;
			this->VScrollBarChats->BorderRadius = 4;
			this->VScrollBarChats->Dock = System::Windows::Forms::DockStyle::Right;
			this->VScrollBarChats->FillColor = System::Drawing::Color::Transparent;
			this->VScrollBarChats->InUpdate = false;
			this->VScrollBarChats->LargeChange = 10;
			this->VScrollBarChats->Location = System::Drawing::Point(285, 0);
			this->VScrollBarChats->Margin = System::Windows::Forms::Padding(0);
			this->VScrollBarChats->MaximumSize = System::Drawing::Size(10, 0);
			this->VScrollBarChats->Name = L"VScrollBarChats";
			this->VScrollBarChats->ScrollbarSize = 10;
			this->VScrollBarChats->Size = System::Drawing::Size(10, 523);
			this->VScrollBarChats->TabIndex = 19;
			this->VScrollBarChats->ThumbColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->VScrollBarChats->ThumbSize = 5;
			// 
			// placeForChats
			// 
			this->placeForChats->AutoScroll = true;
			this->placeForChats->AutoSize = true;
			this->placeForChats->BackColor = System::Drawing::Color::Transparent;
			this->placeForChats->Dock = System::Windows::Forms::DockStyle::Left;
			this->placeForChats->Location = System::Drawing::Point(0, 0);
			this->placeForChats->Name = L"placeForChats";
			this->placeForChats->Size = System::Drawing::Size(0, 523);
			this->placeForChats->TabIndex = 19;
			this->placeForChats->UseWaitCursor = true;
			// 
			// guna2Panel5
			// 
			this->guna2Panel5->BorderThickness = 1;
			this->guna2Panel5->Controls->Add(this->guna2Panel8);
			this->guna2Panel5->Controls->Add(this->sendText);
			this->guna2Panel5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->guna2Panel5->Location = System::Drawing::Point(367, 533);
			this->guna2Panel5->Name = L"guna2Panel5";
			this->guna2Panel5->Size = System::Drawing::Size(677, 57);
			this->guna2Panel5->TabIndex = 4;
			// 
			// guna2Panel8
			// 
			this->guna2Panel8->BackColor = System::Drawing::Color::Transparent;
			this->guna2Panel8->Controls->Add(this->sendButton);
			this->guna2Panel8->Dock = System::Windows::Forms::DockStyle::Right;
			this->guna2Panel8->Location = System::Drawing::Point(626, 0);
			this->guna2Panel8->Name = L"guna2Panel8";
			this->guna2Panel8->Size = System::Drawing::Size(51, 57);
			this->guna2Panel8->TabIndex = 2;
			// 
			// sendButton
			// 
			this->sendButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->sendButton->BackColor = System::Drawing::Color::Transparent;
			this->sendButton->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->sendButton->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->sendButton->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->sendButton->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->sendButton->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->sendButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->sendButton->ForeColor = System::Drawing::Color::White;
			this->sendButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sendButton.Image")));
			this->sendButton->Location = System::Drawing::Point(5, 7);
			this->sendButton->Name = L"sendButton";
			this->sendButton->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->sendButton->Size = System::Drawing::Size(40, 40);
			this->sendButton->TabIndex = 0;
			this->sendButton->Click += gcnew System::EventHandler(this, &MyForm::sendButton_Click);
			// 
			// sendText
			// 
			this->sendText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->sendText->BorderColor = System::Drawing::Color::Transparent;
			this->sendText->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->sendText->DefaultText = L"";
			this->sendText->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->sendText->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->sendText->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->sendText->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->sendText->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->sendText->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->sendText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->sendText->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->sendText->Location = System::Drawing::Point(6, 12);
			this->sendText->Name = L"sendText";
			this->sendText->PasswordChar = '\0';
			this->sendText->PlaceholderText = L"Message";
			this->sendText->SelectedText = L"";
			this->sendText->Size = System::Drawing::Size(614, 33);
			this->sendText->TabIndex = 1;
			// 
			// guna2DragControl1
			// 
			this->guna2DragControl1->DockIndicatorTransparencyValue = 0.6;
			this->guna2DragControl1->TargetControl = this->guna2Panel_top;
			this->guna2DragControl1->UseTransparentDrag = true;
			// 
			// guna2ShadowForm1
			// 
			this->guna2ShadowForm1->TargetForm = this;
			// 
			// placeForMessages
			// 
			this->placeForMessages->AutoSize = true;
			this->placeForMessages->BackColor = System::Drawing::Color::Transparent;
			this->placeForMessages->Dock = System::Windows::Forms::DockStyle::Fill;
			this->placeForMessages->Location = System::Drawing::Point(367, 67);
			this->placeForMessages->Name = L"placeForMessages";
			this->placeForMessages->Size = System::Drawing::Size(677, 466);
			this->placeForMessages->TabIndex = 6;
			// 
			// VScrollBarForMessages
			// 
			this->VScrollBarForMessages->AutoRoundedCorners = true;
			this->VScrollBarForMessages->AutoScroll = true;
			this->VScrollBarForMessages->BackColor = System::Drawing::Color::Black;
			this->VScrollBarForMessages->BorderColor = System::Drawing::Color::Transparent;
			this->VScrollBarForMessages->BorderRadius = 4;
			this->VScrollBarForMessages->Dock = System::Windows::Forms::DockStyle::Right;
			this->VScrollBarForMessages->FillColor = System::Drawing::Color::Transparent;
			this->VScrollBarForMessages->InUpdate = false;
			this->VScrollBarForMessages->LargeChange = 10;
			this->VScrollBarForMessages->Location = System::Drawing::Point(1034, 67);
			this->VScrollBarForMessages->Margin = System::Windows::Forms::Padding(0);
			this->VScrollBarForMessages->MaximumSize = System::Drawing::Size(10, 0);
			this->VScrollBarForMessages->Name = L"VScrollBarForMessages";
			this->VScrollBarForMessages->ScrollbarSize = 10;
			this->VScrollBarForMessages->Size = System::Drawing::Size(10, 466);
			this->VScrollBarForMessages->TabIndex = 20;
			this->VScrollBarForMessages->ThumbColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->VScrollBarForMessages->ThumbSize = 5;
			// 
			// timerUpdateChats
			// 
			this->timerUpdateChats->Enabled = true;
			this->timerUpdateChats->Interval = 20000;
			this->timerUpdateChats->Tick += gcnew System::EventHandler(this, &MyForm::timerUpdateChats_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->ClientSize = System::Drawing::Size(1311, 590);
			this->Controls->Add(this->VScrollBarForMessages);
			this->Controls->Add(this->placeForMessages);
			this->Controls->Add(this->guna2Panel5);
			this->Controls->Add(this->guna2Panel4);
			this->Controls->Add(this->guna2Panel_top);
			this->Controls->Add(this->guna2Panel2);
			this->Controls->Add(this->guna2Panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->guna2Panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profilePicture))->EndInit();
			this->guna2Panel2->ResumeLayout(false);
			this->guna2Panel2->PerformLayout();
			this->guna2CircleProgressBar2->ResumeLayout(false);
			this->guna2CircleProgressBar1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photoOtherUser))->EndInit();
			this->guna2Panel_top->ResumeLayout(false);
			this->guna2Panel_top->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentChatPicture))->EndInit();
			this->guna2Panel4->ResumeLayout(false);
			this->guna2Panel4->PerformLayout();
			this->guna2Panel5->ResumeLayout(false);
			this->guna2Panel8->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		


		public:
		

	


		public: property ServerConnection* server;
		public:  property ChatNode^ currentNode;
		public:  property ArrayList^ chatNodes;
		public:  static property MyForm^ pointer;
		public: property UserNode^ user;
		public: property Thread^ workerThread;
		public: property MailSlotsReciver* reciver;
	

	protected: System::Void onShow() override;

	public: System::Void downloadChats();

	public: System::Void setCurrentChat(ChatNode^ node);

	private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e);

	public: static void MarshalString(String^ s, std::string& os);

	public: Void receiveMessagesRange();
	
	public: delegate System::Void addMessagesToFormDelegate(array<MessageNode^>^  msg, bool isOld);
	public: System::Void addMessagesToForm(array<MessageNode^>^ msg, bool isOld);

	public: delegate System::Void addChatsToFormDelegate(List<ChatNode^> ^);
	public: System::Void addChatsToForm(List<ChatNode^>^);

	public: delegate System::Void changeChatStatusDelegate(ChatNode^ chat, bool status);
	public: System::Void changeChatStatus(ChatNode ^ chat, bool status);
	
	public: delegate System::Void changeChatUnreadMessagesDelegate(ChatNode^ chat, int unread);
	public: System::Void changeChatUnreadMessages(ChatNode^ chat, int unread);

	private: System::Void CreateNewChat_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void threadReceivMessages();
	private: System::Void maximizeButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void logOutButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timerUpdateChats_Tick(System::Object^ sender, System::EventArgs^ e);
};


}

