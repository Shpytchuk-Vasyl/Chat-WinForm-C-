#pragma once
#include "ServerConnection.h"
#include "ChatNode.h"
#include "RequestManager.h"
#include "UsersViewForm.h"
#include "PipeReciver.h"
	

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
			onShow(nullptr);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
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

	private: Guna::UI2::WinForms::Guna2Button^ guna2Button5;
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
    private: Guna::UI2::WinForms::Guna2Panel^ placeForMessages;
	private: Guna::UI2::WinForms::Guna2VScrollBar^ VScrollBarForMessages;


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
			this->guna2Button5 = (gcnew Guna::UI2::WinForms::Guna2Button());
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
			this->guna2Panel1->Controls->Add(this->guna2Button5);
			this->guna2Panel1->Controls->Add(this->guna2Button4);
			this->guna2Panel1->Controls->Add(this->guna2Button3);
			this->guna2Panel1->Controls->Add(this->guna2Button2);
			this->guna2Panel1->Controls->Add(this->CreateNewChat);
			this->guna2Panel1->Controls->Add(this->profilePicture);
			this->guna2Panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->guna2Panel1->Location = System::Drawing::Point(0, 0);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->Size = System::Drawing::Size(72, 581);
			this->guna2Panel1->TabIndex = 0;
			// 
			// guna2Button5
			// 
			this->guna2Button5->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button5->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button5->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2Button5->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2Button5->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2Button5->ForeColor = System::Drawing::Color::White;
			this->guna2Button5->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->guna2Button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button5.Image")));
			this->guna2Button5->Location = System::Drawing::Point(0, 292);
			this->guna2Button5->Name = L"guna2Button5";
			this->guna2Button5->Size = System::Drawing::Size(72, 45);
			this->guna2Button5->TabIndex = 5;
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
			this->guna2Panel2->Size = System::Drawing::Size(267, 581);
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
			this->guna2Panel4->Size = System::Drawing::Size(295, 514);
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
			this->VScrollBarChats->Size = System::Drawing::Size(10, 514);
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
			this->placeForChats->Size = System::Drawing::Size(0, 514);
			this->placeForChats->TabIndex = 19;
			this->placeForChats->UseWaitCursor = true;
			// 
			// guna2Panel5
			// 
			this->guna2Panel5->BorderThickness = 1;
			this->guna2Panel5->Controls->Add(this->guna2Panel8);
			this->guna2Panel5->Controls->Add(this->sendText);
			this->guna2Panel5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->guna2Panel5->Location = System::Drawing::Point(367, 524);
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
			this->placeForMessages->Size = System::Drawing::Size(677, 457);
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
			this->VScrollBarForMessages->Size = System::Drawing::Size(10, 457);
			this->VScrollBarForMessages->TabIndex = 20;
			this->VScrollBarForMessages->ThumbColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->VScrollBarForMessages->ThumbSize = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->ClientSize = System::Drawing::Size(1311, 581);
			this->Controls->Add(this->VScrollBarForMessages);
			this->Controls->Add(this->placeForMessages);
			this->Controls->Add(this->guna2Panel5);
			this->Controls->Add(this->guna2Panel4);
			this->Controls->Add(this->guna2Panel_top);
			this->Controls->Add(this->guna2Panel2);
			this->Controls->Add(this->guna2Panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
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
		

		ref class ChatNode : public Guna2GradientPanel
		{

		public:
			property Guna2CirclePictureBox^ photo;
			property Label^ chatName;
			property Label^ lastMessage;
			property Label^ online;
			property Guna2CircleButton^ countNewMessage;
			property FlowLayoutPanel^ messageView;
			property int id;
			property int picture;

		public:

			ChatNode(String^ strChatName, String^ strLastMessage, int intCountNewMessage, int photoIndex, bool status, int chat_id) : Guna2GradientPanel() {
				id = chat_id;
				picture = photoIndex;						//тут треба айді чату ?

				messageView = gcnew FlowLayoutPanel();
				this->messageView->BackColor = System::Drawing::Color::Transparent;
				this->messageView->Dock = System::Windows::Forms::DockStyle::Fill;
				this->messageView->Location = System::Drawing::Point(367, 67);
				this->messageView->AutoScroll = false;

				this->countNewMessage = (gcnew Guna::UI2::WinForms::Guna2CircleButton());
				this->countNewMessage->BackColor = System::Drawing::Color::Transparent;
				this->countNewMessage->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
				this->countNewMessage->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
				this->countNewMessage->DisabledState->FillColor = System::Drawing::Color::FromArgb(169, 169, 169);
				this->countNewMessage->DisabledState->ForeColor = System::Drawing::Color::FromArgb(141, 141, 141);
				this->countNewMessage->FillColor = System::Drawing::Color::Magenta;
				this->countNewMessage->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				this->countNewMessage->ForeColor = System::Drawing::Color::White;
				this->countNewMessage->Location = System::Drawing::Point(150, 30);
				this->countNewMessage->Name = "countNewMessage : " + strChatName;
				this->countNewMessage->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
				this->countNewMessage->Size = System::Drawing::Size(30, 30);
				//this->countNewMessage->TabIndex = 20;
				this->countNewMessage->Text = intCountNewMessage.ToString();
				this->countNewMessage->UseWaitCursor = true;


				this->photo = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
				this->photo->BackColor = System::Drawing::Color::Transparent;
				this->photo->FillColor = System::Drawing::Color::Transparent;
				this->photo->Image = Image::FromFile("userPhotos/user" + photoIndex + ".png");
				this->photo->ImageRotate = 0;
				this->photo->Location = System::Drawing::Point(20, 20);
				this->photo->Name = "photo : " + strChatName;
				this->photo->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
				this->photo->ShadowDecoration->Enabled = true;
				this->photo->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
				this->photo->Size = System::Drawing::Size(36, 36);
				this->photo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				//this->photo->TabIndex = 11;
				this->photo->TabStop = false;
				this->photo->UseWaitCursor = true;

				this->online = (gcnew Label);
				this->online->AutoSize = true;
				this->online->BackColor = System::Drawing::Color::Transparent;
				this->online->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->online->ForeColor = System::Drawing::Color::Silver;
				this->online->Location = System::Drawing::Point(150, 10);
				this->online->Name = L"online : " + strChatName;
				this->online->Size = System::Drawing::Size(39, 17);
				//this->online->TabIndex = 14;
				this->online->Text = status ? "Online" : "Offline";
				this->online->UseWaitCursor = true;




				this->lastMessage = (gcnew Label);
				this->lastMessage->AutoSize = true;
				this->lastMessage->BackColor = System::Drawing::Color::Transparent;
				this->lastMessage->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->lastMessage->ForeColor = System::Drawing::Color::Gray;
				this->lastMessage->Location = System::Drawing::Point(60, 40);
				this->lastMessage->Name = L"lastMessage : " + strChatName;
				this->lastMessage->Size = System::Drawing::Size(50, 20);
				//this->lastMessage->TabIndex = 13;
				this->lastMessage->Text = strLastMessage;
				this->lastMessage->UseWaitCursor = true;


				this->chatName = (gcnew Label);
				this->chatName->AutoSize = true;
				this->chatName->BackColor = System::Drawing::Color::Transparent;
				this->chatName->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->chatName->ForeColor = System::Drawing::Color::Silver;
				this->chatName->Location = System::Drawing::Point(60, 10);
				this->chatName->Name = "chatName : " + strChatName;
				this->chatName->Size = System::Drawing::Size(42, 20);
				this->chatName->Text = strChatName;





				this->BorderThickness = 2;
				this->Controls->Add(this->countNewMessage);
				this->Controls->Add(this->online);
				this->Controls->Add(this->chatName);
				this->Controls->Add(this->lastMessage);
				this->Controls->Add(this->photo);
				this->CustomBorderColor = System::Drawing::Color::FromArgb(128, 36, 206);
				this->FillColor = System::Drawing::Color::FromArgb(23, 28, 41);
				this->FillColor2 = System::Drawing::Color::FromArgb(23, 28, 41);
				this->AutoSize = false;
				//this->Anchor = (AnchorStyles::Left | AnchorStyles::Top);
				this->Location = System::Drawing::Point(3, 3);
				this->Name = "ChatNode : " + strChatName;
				this->ShadowDecoration->Color = System::Drawing::Color::FromArgb(17, 22, 32);
				this->Size = System::Drawing::Size(200, 80);
				this->UseWaitCursor = true;

				this->MouseEnter += gcnew System::EventHandler(this, &ChatNode::mouseEnter);
				this->MouseLeave += gcnew System::EventHandler(this, &ChatNode::mouseLeave);
				this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ChatNode::mouseClick);

			}


		public: System::Void resetColor() {
			this->FillColor = System::Drawing::Color::FromArgb(23, 28, 41);
			this->FillColor2 = System::Drawing::Color::FromArgb(23, 28, 41);
		}

		public: System::Void addMessage(MessageNode^ msg) {
			Guna2Panel^ p = gcnew Guna2Panel();
			p->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			p->Controls->Add(msg);
			p->Location = System::Drawing::Point(3, 3);
			p->Size = System::Drawing::Size(this->messageView->Size.Width, 78);
			messageView->SuspendLayout();
			messageView->Controls->Add(p);
			messageView->ResumeLayout();
		}

		private: System::Void mouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->FillColor = System::Drawing::Color::FromArgb(250, 48, 90);
			this->FillColor2 = System::Drawing::Color::FromArgb(128, 36, 206);
			pointer->setCurrentChat(this);						//відкриття чату?
		}

		private: System::Void mouseEnter(System::Object^ sender, System::EventArgs^ e) {
			if (this->FillColor != System::Drawing::Color::FromArgb(250, 48, 90)) {
				this->FillColor = System::Drawing::Color::FromArgb(19, 25, 40);
				this->FillColor2 = System::Drawing::Color::FromArgb(19, 25, 40);
			}
		}
		private: System::Void mouseLeave(System::Object^ sender, System::EventArgs^ e) {
			if(this->FillColor != System::Drawing::Color::FromArgb(250, 48, 90))
			resetColor();
		}

		};


		public: property ServerConnection* server;
		public:  property ChatNode^ currentNode;
		public:  property ArrayList^ chatNodes;
		public:  static property MyForm^ pointer;
		public: property UserNode^ user;
		public: property Thread^ workerThread;
		public: property CPipeReciver* reciver;
	

		protected:   Void onShow(EventArgs^ a) override {
			//this->onShow(a);
			try {
				server = new ServerConnection();
				server->Connect(DEFAULT_IP, DEFAULT_PORT);
				//reciver = new CPipeReciver() передавати поточного юзера 
				UserNode::MyUserData(8, 1, "user 1").WriteToFile("userData/user.bin");
				user = gcnew UserNode("userData/user.bin");
				if (user->isRegistered) {
					downloadChats();
				}
				else {

					//register form

					for (size_t i = 0; i < 100; i++)
					{
						if (server->RegisterUser(CUser(("user " + std::to_string(i)).c_str(), "password", 1))) {
						
							
							break;
						}

					}
				}
			}
			catch (std::exception er) {
				MessageBox::Show("Unable to connect to server", "Unable connection",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		public: System::Void downloadChats() {
			std::string name;
			MarshalString(user->userName, name);
			CUser u(name.c_str(), "", user->pictureIndex);
			server->Start(u);
			std::vector<CChat> v = server->update();
			if (!v.empty()) {
				for (int i = 0; i < v.size(); i++) {
					if(String::Compare(gcnew String(v[i].getUser1().getName()), user->userName) == 0){
						chatNodes->Add(
							gcnew ChatNode(
								gcnew String(v[i].getUser2().getName()),
								"",
								v[i].getUnread1(),
								v[i].getUser2().getPicture(),
								v[i].getUser2().getStatus(),
								v[i].getChatId()));
					} else {
						chatNodes->Add(
							gcnew ChatNode(
								gcnew String(v[i].getUser1().getName()),
								"",
								v[i].getUnread2(),
								v[i].getUser1().getPicture(),
								v[i].getUser1().getStatus(),
								v[i].getChatId()));
					}

				}


				SuspendLayout();

				// Конвертуємо ArrayList до array<ChatNode^>
				array<ChatNode^>^ chatNodesArray = gcnew array<ChatNode^>(chatNodes->Count);
				chatNodes->CopyTo(chatNodesArray);

				placeForChats->Controls->AddRange(chatNodesArray);
				placeForChats->AutoScroll = false;
				ResumeLayout();

			}
		}

		

		public: System::Void setCurrentChat(ChatNode ^node) {
			   if(currentNode)
					currentNode->resetColor();
			   currentNode = node;
			   receiveMessagesRange();

			   SuspendLayout();
			   VScrollBarForMessages->BindingContainer = currentNode->messageView;
			   currentNode->messageView->AutoScroll = true;
			   placeForMessages->Controls->Clear();
			   placeForMessages->Controls->Add(currentNode->messageView);
			   ResumeLayout();
		}

		private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ message = sendText->Text;
			std::string msg;
			if (!String::IsNullOrEmpty(message) && currentNode != nullptr) {
				MarshalString(message, msg);
				if (server->sendMessage(CMessage(msg.c_str(), user->id, currentNode->id))) {
					sendText->Text = "";
					currentNode->addMessage(gcnew MessageNode(message, true, user->pictureIndex));
				}
				else {
					MessageBox::Show("Unable to connect to server", "Unable connection",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}


		private: void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

		public: Void receiveMessagesRange() {
			std::vector<CMessage> v;
			int countCurrentMsg = currentNode->messageView->Controls->Count;
			array<MessageNode^>^ result;
			int newMsg = Int64::Parse(currentNode->countNewMessage->Text);
			v = server->getAllMessageFromChat(CChat(currentNode->id));
			if (countCurrentMsg == 0) {
				int ten = (newMsg + 5 < v.size() ? newMsg + 5 : v.size());
				v = std::vector<CMessage>(v.begin(), v.begin() + ten);
				result = gcnew array<MessageNode^>(v.size());

			}
			else if(newMsg != 0) {
				v = std::vector<CMessage>(v.begin(), v.begin() + newMsg);
				result = gcnew array<MessageNode^>(v.size());

			}
			else {
				int ten = (countCurrentMsg + 10 < v.size() ? countCurrentMsg + 10 : v.size());
				v = std::vector<CMessage>(v.begin() + countCurrentMsg, v.begin() + ten);
				result = gcnew array<MessageNode^>(v.size());

			}
			for (size_t i = 0; i < v.size(); ++i) {
				result[i] = gcnew
					MessageNode(
						gcnew String(v[i].get_text().c_str()),
						v[i].get_user_id() == user->id,
						v[i].get_user_id() == user->id ? user->pictureIndex : currentNode->picture
					);
			}
			addMessagesToForm(result, newMsg == 0);
		}
	

		public: delegate System::Void addMessagesToFormDelegate(array<MessageNode^>^  msg, bool isOld);
		public: System::Void addMessagesToForm(array<MessageNode^>^ msg,bool isOld) {
			SuspendLayout();
			if (isOld) {
				List<Control^>^ oldControls = gcnew List<Control^>();
				for each (Control ^ control in currentNode->messageView->Controls) {
					oldControls->Add(control);//тут наче  ж збирались кожен раз перевантажувати ?
				}
				currentNode->messageView->Controls->Clear();
				currentNode->messageView->Controls->AddRange(msg);
				currentNode->messageView->Controls->AddRange(oldControls->ToArray());
			}
			else {
				currentNode->messageView->Controls->AddRange(msg);
			}
			ResumeLayout();
		}

//private: System::Void guna2CircleButton6_Click(System::Object^ sender, System::EventArgs^ e) {
//	 String^ message = guna2TextBox2->Text;
//	 if (!String::IsNullOrEmpty(message))
//	 {
//		 guna2TextBox2->Text = "";
//		 ChatNode^ p = gcnew ChatNode("Test " + message[1], "Hello", 5, 1, false);
//		 p->Size = System::Drawing::Size(200, 80);
//		 flowLayoutPanel1->Controls->Add(p);
//		 if (currentNode == nullptr) currentNode = p;
//		 currentNode->addMessage(gcnew ChatNode::MessageNode(message, true, 1));
//	 }
//}


private: System::Void CreateNewChat_Click(System::Object^ sender, System::EventArgs^ e) {
	UsersViewForm^ usersWievForm = gcnew UsersViewForm();
	usersWievForm->ShowDialog();
	if (usersWievForm->resultUser != nullptr) {
		std::string name;
		MarshalString(usersWievForm->resultUser->userName, name);
		server->addNewChat(CUser(name.c_str(), "", usersWievForm->resultUser->pictureIndex));
		
	}
}

};


}

