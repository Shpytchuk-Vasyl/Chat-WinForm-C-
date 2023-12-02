#pragma once
#include "ServerConnection.h"
#include "ChatNode.h"

namespace Client {
	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			s1 = new SocketServer();
			pointer = this;
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
			}
		}
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel2;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel_top;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel4;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel5;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button1;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button5;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button4;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button3;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button2;
	private: Guna::UI2::WinForms::Guna2VScrollBar^ guna2VScrollBar1;
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
			this->guna2Button1 = (gcnew Guna::UI2::WinForms::Guna2Button());
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
			this->guna2VScrollBar1 = (gcnew Guna::UI2::WinForms::Guna2VScrollBar());
			this->placeForChats = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->guna2Panel5 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel8 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->sendButton = (gcnew Guna::UI2::WinForms::Guna2CircleButton());
			this->sendText = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2DragControl1 = (gcnew Guna::UI2::WinForms::Guna2DragControl(this->components));
			this->guna2ShadowForm1 = (gcnew Guna::UI2::WinForms::Guna2ShadowForm(this->components));
			this->placeForMessages = (gcnew Guna::UI2::WinForms::Guna2Panel());
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
			this->guna2Panel1->Controls->Add(this->guna2Button1);
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
			// guna2Button1
			// 
			this->guna2Button1->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button1->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2Button1->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2Button1->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2Button1->FillColor = System::Drawing::Color::Transparent;
			this->guna2Button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2Button1->ForeColor = System::Drawing::Color::White;
			this->guna2Button1->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->guna2Button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button1.Image")));
			this->guna2Button1->Location = System::Drawing::Point(0, 88);
			this->guna2Button1->Name = L"guna2Button1";
			this->guna2Button1->Size = System::Drawing::Size(72, 45);
			this->guna2Button1->TabIndex = 1;
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
			this->nameOtherUser->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->nameOtherUser->ForeColor = System::Drawing::Color::Silver;
			this->nameOtherUser->Location = System::Drawing::Point(121, 243);
			this->nameOtherUser->Name = L"nameOtherUser";
			this->nameOtherUser->Size = System::Drawing::Size(49, 23);
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
			this->currentChatStatus->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentChatStatus->ForeColor = System::Drawing::Color::Silver;
			this->currentChatStatus->Location = System::Drawing::Point(361, 37);
			this->currentChatStatus->Name = L"currentChatStatus";
			this->currentChatStatus->Size = System::Drawing::Size(39, 17);
			this->currentChatStatus->TabIndex = 17;
			this->currentChatStatus->Text = L"Online";
			// 
			// currentChatName
			// 
			this->currentChatName->AutoSize = true;
			this->currentChatName->BackColor = System::Drawing::Color::Transparent;
			this->currentChatName->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->currentChatName->ForeColor = System::Drawing::Color::Silver;
			this->currentChatName->Location = System::Drawing::Point(358, 16);
			this->currentChatName->Name = L"currentChatName";
			this->currentChatName->Size = System::Drawing::Size(42, 20);
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
			this->guna2Panel4->Controls->Add(this->guna2VScrollBar1);
			this->guna2Panel4->Controls->Add(this->placeForChats);
			this->guna2Panel4->Dock = System::Windows::Forms::DockStyle::Left;
			this->guna2Panel4->Location = System::Drawing::Point(72, 67);
			this->guna2Panel4->Name = L"guna2Panel4";
			this->guna2Panel4->Size = System::Drawing::Size(295, 514);
			this->guna2Panel4->TabIndex = 3;
			// 
			// guna2VScrollBar1
			// 
			this->guna2VScrollBar1->AutoScroll = true;
			this->guna2VScrollBar1->BackColor = System::Drawing::Color::Transparent;
			this->guna2VScrollBar1->BindingContainer = this->placeForChats;
			this->guna2VScrollBar1->BorderColor = System::Drawing::Color::Transparent;
			this->guna2VScrollBar1->Dock = System::Windows::Forms::DockStyle::Right;
			this->guna2VScrollBar1->FillColor = System::Drawing::Color::Transparent;
			this->guna2VScrollBar1->InUpdate = false;
			this->guna2VScrollBar1->LargeChange = 10;
			this->guna2VScrollBar1->Location = System::Drawing::Point(285, 0);
			this->guna2VScrollBar1->Margin = System::Windows::Forms::Padding(0);
			this->guna2VScrollBar1->MaximumSize = System::Drawing::Size(10, 0);
			this->guna2VScrollBar1->Name = L"guna2VScrollBar1";
			this->guna2VScrollBar1->ScrollbarSize = 10;
			this->guna2VScrollBar1->Size = System::Drawing::Size(10, 514);
			this->guna2VScrollBar1->TabIndex = 19;
			this->guna2VScrollBar1->ThumbColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->guna2VScrollBar1->ThumbSize = 5;
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
			this->placeForMessages->BackColor = System::Drawing::Color::Transparent;
			this->placeForMessages->Dock = System::Windows::Forms::DockStyle::Fill;
			this->placeForMessages->Location = System::Drawing::Point(367, 67);
			this->placeForMessages->Name = L"placeForMessages";
			this->placeForMessages->Size = System::Drawing::Size(677, 457);
			this->placeForMessages->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->ClientSize = System::Drawing::Size(1311, 581);
			this->Controls->Add(this->placeForMessages);
			this->Controls->Add(this->guna2Panel5);
			this->Controls->Add(this->guna2Panel4);
			this->Controls->Add(this->guna2Panel_top);
			this->Controls->Add(this->guna2Panel2);
			this->Controls->Add(this->guna2Panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			//this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
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

		}
#pragma endregion

	   
		public: SocketServer* s1;
		public:  ChatNode^ currentNode;
		public:  System::Collections::ArrayList ^ chatNodes;
		public:  static property Object ^ pointer;

		public: System::Void setCurrent(ChatNode ^node) {
			   if(currentNode)
					currentNode->resetColor();
			   currentNode = node;
			   SuspendLayout();
			   placeForMessages->Controls->Clear();
			   placeForMessages->Controls->Add(currentNode->messageView);
			   ResumeLayout();
		}


	private: void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
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

};
}
