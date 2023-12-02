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











































	private: Guna::UI2::WinForms::Guna2GradientPanel^ guna2GradientPanel2;

	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox4;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Label^ label8;
	private: Guna::UI2::WinForms::Guna2VScrollBar^ guna2VScrollBar1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel3;
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox10;
	private: System::Windows::Forms::Label^ label14;
	private: Guna::UI2::WinForms::Guna2CircleButton^ guna2CircleButton4;


	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel8;



	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel7;









	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: Guna::UI2::WinForms::Guna2GradientPanel^ guna2GradientPanel9;
	private: System::Windows::Forms::Label^ label24;
	private: Guna::UI2::WinForms::Guna2CircleButton^ guna2CircleButton8;
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox11;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;












	private: Guna::UI2::WinForms::Guna2GradientPanel^ guna2GradientPanel6;
	private: Guna::UI2::WinForms::Guna2DragControl^ guna2DragControl1;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox3;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox2;
	private: Guna::UI2::WinForms::Guna2ControlBox^ guna2ControlBox1;
	private: Guna::UI2::WinForms::Guna2ShadowForm^ guna2ShadowForm1;







	private: Guna::UI2::WinForms::Guna2GradientPanel^ guna2GradientPanel7;
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox7;
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox1;
	private: Guna::UI2::WinForms::Guna2CircleProgressBar^ guna2CircleProgressBar2;
	private: Guna::UI2::WinForms::Guna2CircleProgressBar^ guna2CircleProgressBar1;
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox8;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;


	private: System::Windows::Forms::Label^ label9;

	private: Guna::UI2::WinForms::Guna2CircleButton^ guna2CircleButton6;
	private: System::Windows::Forms::Label^ label18;
	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox1;
	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox2;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label19;
private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox9;
private: System::ComponentModel::IContainer^ components;













	protected:








	protected:

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
			this->guna2CirclePictureBox1 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->guna2Panel2 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2ControlBox3 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2ControlBox2 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2ControlBox1 = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->guna2CircleProgressBar2 = (gcnew Guna::UI2::WinForms::Guna2CircleProgressBar());
			this->guna2CircleProgressBar1 = (gcnew Guna::UI2::WinForms::Guna2CircleProgressBar());
			this->guna2CirclePictureBox8 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->guna2Panel_top = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->guna2CirclePictureBox9 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->guna2TextBox1 = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2Panel4 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2VScrollBar1 = (gcnew Guna::UI2::WinForms::Guna2VScrollBar());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->guna2GradientPanel2 = (gcnew Guna::UI2::WinForms::Guna2GradientPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->guna2CirclePictureBox4 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->guna2CircleButton4 = (gcnew Guna::UI2::WinForms::Guna2CircleButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->guna2GradientPanel9 = (gcnew Guna::UI2::WinForms::Guna2GradientPanel());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->guna2CircleButton8 = (gcnew Guna::UI2::WinForms::Guna2CircleButton());
			this->guna2CirclePictureBox11 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->guna2Panel5 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel8 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2CircleButton6 = (gcnew Guna::UI2::WinForms::Guna2CircleButton());
			this->guna2TextBox2 = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2GradientPanel6 = (gcnew Guna::UI2::WinForms::Guna2GradientPanel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->guna2CirclePictureBox7 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->guna2GradientPanel7 = (gcnew Guna::UI2::WinForms::Guna2GradientPanel());
			this->guna2CirclePictureBox10 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->guna2DragControl1 = (gcnew Guna::UI2::WinForms::Guna2DragControl(this->components));
			this->guna2ShadowForm1 = (gcnew Guna::UI2::WinForms::Guna2ShadowForm(this->components));
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->guna2Panel7 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel3 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox1))->BeginInit();
			this->guna2Panel2->SuspendLayout();
			this->guna2CircleProgressBar2->SuspendLayout();
			this->guna2CircleProgressBar1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox8))->BeginInit();
			this->guna2Panel_top->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox9))->BeginInit();
			this->guna2Panel4->SuspendLayout();
			this->guna2GradientPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox4))->BeginInit();
			this->guna2GradientPanel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox11))->BeginInit();
			this->guna2Panel5->SuspendLayout();
			this->guna2Panel8->SuspendLayout();
			this->guna2GradientPanel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox7))->BeginInit();
			this->guna2GradientPanel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox10))->BeginInit();
			this->flowLayoutPanel2->SuspendLayout();
			this->guna2Panel7->SuspendLayout();
			this->guna2Panel3->SuspendLayout();
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
			this->guna2Panel1->Controls->Add(this->guna2CirclePictureBox1);
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
			this->guna2Button1->Click += gcnew System::EventHandler(this, &MyForm::guna2Button1_Click);
			// 
			// guna2CirclePictureBox1
			// 
			this->guna2CirclePictureBox1->FillColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox1.Image")));
			this->guna2CirclePictureBox1->ImageRotate = 0;
			this->guna2CirclePictureBox1->Location = System::Drawing::Point(18, 18);
			this->guna2CirclePictureBox1->Name = L"guna2CirclePictureBox1";
			this->guna2CirclePictureBox1->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->guna2CirclePictureBox1->ShadowDecoration->CustomizableEdges->BottomLeft = false;
			this->guna2CirclePictureBox1->ShadowDecoration->CustomizableEdges->BottomRight = false;
			this->guna2CirclePictureBox1->ShadowDecoration->CustomizableEdges->TopLeft = false;
			this->guna2CirclePictureBox1->ShadowDecoration->CustomizableEdges->TopRight = false;
			this->guna2CirclePictureBox1->ShadowDecoration->Enabled = true;
			this->guna2CirclePictureBox1->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox1->Size = System::Drawing::Size(36, 36);
			this->guna2CirclePictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox1->TabIndex = 0;
			this->guna2CirclePictureBox1->TabStop = false;
			// 
			// guna2Panel2
			// 
			this->guna2Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->guna2Panel2->Controls->Add(this->guna2ControlBox3);
			this->guna2Panel2->Controls->Add(this->guna2ControlBox2);
			this->guna2Panel2->Controls->Add(this->guna2ControlBox1);
			this->guna2Panel2->Controls->Add(this->label17);
			this->guna2Panel2->Controls->Add(this->label16);
			this->guna2Panel2->Controls->Add(this->guna2CircleProgressBar2);
			this->guna2Panel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->guna2Panel2->Location = System::Drawing::Point(1038, 0);
			this->guna2Panel2->Name = L"guna2Panel2";
			this->guna2Panel2->Size = System::Drawing::Size(273, 581);
			this->guna2Panel2->TabIndex = 1;
			this->guna2Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::guna2Panel2_Paint);
			// 
			// guna2ControlBox3
			// 
			this->guna2ControlBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox3->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MinimizeBox;
			this->guna2ControlBox3->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox3->IconColor = System::Drawing::Color::White;
			this->guna2ControlBox3->Location = System::Drawing::Point(125, 3);
			this->guna2ControlBox3->Name = L"guna2ControlBox3";
			this->guna2ControlBox3->Size = System::Drawing::Size(45, 29);
			this->guna2ControlBox3->TabIndex = 20;
			// 
			// guna2ControlBox2
			// 
			this->guna2ControlBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox2->ControlBoxType = Guna::UI2::WinForms::Enums::ControlBoxType::MaximizeBox;
			this->guna2ControlBox2->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox2->IconColor = System::Drawing::Color::White;
			this->guna2ControlBox2->Location = System::Drawing::Point(174, 3);
			this->guna2ControlBox2->Name = L"guna2ControlBox2";
			this->guna2ControlBox2->Size = System::Drawing::Size(45, 29);
			this->guna2ControlBox2->TabIndex = 19;
			// 
			// guna2ControlBox1
			// 
			this->guna2ControlBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->guna2ControlBox1->FillColor = System::Drawing::Color::Transparent;
			this->guna2ControlBox1->IconColor = System::Drawing::Color::White;
			this->guna2ControlBox1->Location = System::Drawing::Point(225, 3);
			this->guna2ControlBox1->Name = L"guna2ControlBox1";
			this->guna2ControlBox1->Size = System::Drawing::Size(45, 29);
			this->guna2ControlBox1->TabIndex = 18;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Aqua;
			this->label17->Location = System::Drawing::Point(121, 273);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(44, 20);
			this->label17->TabIndex = 17;
			this->label17->Text = L"Online";
			this->label17->Click += gcnew System::EventHandler(this, &MyForm::label17_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->ForeColor = System::Drawing::Color::Silver;
			this->label16->Location = System::Drawing::Point(121, 243);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(49, 23);
			this->label16->TabIndex = 16;
			this->label16->Text = L"User2";
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
			this->guna2CircleProgressBar1->Controls->Add(this->guna2CirclePictureBox8);
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
			// guna2CirclePictureBox8
			// 
			this->guna2CirclePictureBox8->BackColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox8->FillColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox8.Image")));
			this->guna2CirclePictureBox8->ImageRotate = 0;
			this->guna2CirclePictureBox8->Location = System::Drawing::Point(10, 8);
			this->guna2CirclePictureBox8->Name = L"guna2CirclePictureBox8";
			this->guna2CirclePictureBox8->ShadowDecoration->Color = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox8->ShadowDecoration->CustomizableEdges->BottomLeft = false;
			this->guna2CirclePictureBox8->ShadowDecoration->CustomizableEdges->BottomRight = false;
			this->guna2CirclePictureBox8->ShadowDecoration->CustomizableEdges->TopLeft = false;
			this->guna2CirclePictureBox8->ShadowDecoration->CustomizableEdges->TopRight = false;
			this->guna2CirclePictureBox8->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox8->Size = System::Drawing::Size(130, 130);
			this->guna2CirclePictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox8->TabIndex = 7;
			this->guna2CirclePictureBox8->TabStop = false;
			// 
			// guna2Panel_top
			// 
			this->guna2Panel_top->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->guna2Panel_top->Controls->Add(this->label20);
			this->guna2Panel_top->Controls->Add(this->label19);
			this->guna2Panel_top->Controls->Add(this->guna2CirclePictureBox9);
			this->guna2Panel_top->Controls->Add(this->guna2TextBox1);
			this->guna2Panel_top->Dock = System::Windows::Forms::DockStyle::Top;
			this->guna2Panel_top->Location = System::Drawing::Point(72, 0);
			this->guna2Panel_top->Name = L"guna2Panel_top";
			this->guna2Panel_top->Size = System::Drawing::Size(966, 67);
			this->guna2Panel_top->TabIndex = 2;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::Color::Transparent;
			this->label20->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->ForeColor = System::Drawing::Color::Silver;
			this->label20->Location = System::Drawing::Point(342, 37);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(39, 17);
			this->label20->TabIndex = 17;
			this->label20->Text = L"Online";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->ForeColor = System::Drawing::Color::Silver;
			this->label19->Location = System::Drawing::Point(339, 16);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(42, 20);
			this->label19->TabIndex = 16;
			this->label19->Text = L"User1";
			// 
			// guna2CirclePictureBox9
			// 
			this->guna2CirclePictureBox9->BackColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox9->FillColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox9.Image")));
			this->guna2CirclePictureBox9->ImageRotate = 0;
			this->guna2CirclePictureBox9->Location = System::Drawing::Point(282, 18);
			this->guna2CirclePictureBox9->Name = L"guna2CirclePictureBox9";
			this->guna2CirclePictureBox9->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->guna2CirclePictureBox9->ShadowDecoration->Enabled = true;
			this->guna2CirclePictureBox9->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox9->Size = System::Drawing::Size(36, 36);
			this->guna2CirclePictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox9->TabIndex = 16;
			this->guna2CirclePictureBox9->TabStop = false;
			// 
			// guna2TextBox1
			// 
			this->guna2TextBox1->BorderColor = System::Drawing::Color::Transparent;
			this->guna2TextBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox1->DefaultText = L"";
			this->guna2TextBox1->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox1->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox1->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox1->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox1->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->guna2TextBox1->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2TextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2TextBox1->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2TextBox1->Location = System::Drawing::Point(11, 16);
			this->guna2TextBox1->Name = L"guna2TextBox1";
			this->guna2TextBox1->PasswordChar = '\0';
			this->guna2TextBox1->PlaceholderText = L"Search";
			this->guna2TextBox1->SelectedText = L"";
			this->guna2TextBox1->Size = System::Drawing::Size(240, 36);
			this->guna2TextBox1->TabIndex = 0;
			// 
			// guna2Panel4
			// 
			this->guna2Panel4->Controls->Add(this->guna2VScrollBar1);
			this->guna2Panel4->Controls->Add(this->flowLayoutPanel1);
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
			this->guna2VScrollBar1->BindingContainer = this->flowLayoutPanel1;
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
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(0, 514);
			this->flowLayoutPanel1->TabIndex = 19;
			this->flowLayoutPanel1->UseWaitCursor = true;
			// 
			// guna2GradientPanel2
			// 
			this->guna2GradientPanel2->BorderThickness = 2;
			this->guna2GradientPanel2->Controls->Add(this->label9);
			this->guna2GradientPanel2->Controls->Add(this->guna2CirclePictureBox4);
			this->guna2GradientPanel2->Controls->Add(this->label7);
			this->guna2GradientPanel2->Controls->Add(this->guna2CircleButton4);
			this->guna2GradientPanel2->Controls->Add(this->label8);
			this->guna2GradientPanel2->CustomBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2GradientPanel2->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->guna2GradientPanel2->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->guna2GradientPanel2->Location = System::Drawing::Point(259, 160);
			this->guna2GradientPanel2->Name = L"guna2GradientPanel2";
			this->guna2GradientPanel2->ShadowDecoration->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->guna2GradientPanel2->Size = System::Drawing::Size(250, 80);
			this->guna2GradientPanel2->TabIndex = 14;
			this->guna2GradientPanel2->UseWaitCursor = true;
			this->guna2GradientPanel2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::guna2GradientPanel2_MouseClick);
			this->guna2GradientPanel2->MouseEnter += gcnew System::EventHandler(this, &MyForm::guna2GradientPanel1_MouseEnter);
			this->guna2GradientPanel2->MouseLeave += gcnew System::EventHandler(this, &MyForm::guna2GradientPanel1_MouseLeave);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::Color::Silver;
			this->label9->Location = System::Drawing::Point(70, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(42, 20);
			this->label9->TabIndex = 18;
			this->label9->Text = L"User1";
			this->label9->UseWaitCursor = true;
			// 
			// guna2CirclePictureBox4
			// 
			this->guna2CirclePictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox4->FillColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox4.Image")));
			this->guna2CirclePictureBox4->ImageRotate = 0;
			this->guna2CirclePictureBox4->Location = System::Drawing::Point(20, 20);
			this->guna2CirclePictureBox4->Name = L"guna2CirclePictureBox4";
			this->guna2CirclePictureBox4->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->guna2CirclePictureBox4->ShadowDecoration->Enabled = true;
			this->guna2CirclePictureBox4->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox4->Size = System::Drawing::Size(36, 36);
			this->guna2CirclePictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox4->TabIndex = 11;
			this->guna2CirclePictureBox4->TabStop = false;
			this->guna2CirclePictureBox4->UseWaitCursor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::Silver;
			this->label7->Location = System::Drawing::Point(190, 10);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(39, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Online";
			this->label7->UseWaitCursor = true;
			// 
			// guna2CircleButton4
			// 
			this->guna2CircleButton4->BackColor = System::Drawing::Color::Transparent;
			this->guna2CircleButton4->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2CircleButton4->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2CircleButton4->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2CircleButton4->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2CircleButton4->FillColor = System::Drawing::Color::Magenta;
			this->guna2CircleButton4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->guna2CircleButton4->ForeColor = System::Drawing::Color::White;
			this->guna2CircleButton4->Location = System::Drawing::Point(190, 30);
			this->guna2CircleButton4->Name = L"guna2CircleButton4";
			this->guna2CircleButton4->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CircleButton4->Size = System::Drawing::Size(40, 40);
			this->guna2CircleButton4->TabIndex = 20;
			this->guna2CircleButton4->Text = L"7";
			this->guna2CircleButton4->UseWaitCursor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Gray;
			this->label8->Location = System::Drawing::Point(70, 40);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(85, 20);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Last message";
			this->label8->UseWaitCursor = true;
			// 
			// guna2GradientPanel9
			// 
			this->guna2GradientPanel9->Controls->Add(this->label24);
			this->guna2GradientPanel9->Controls->Add(this->guna2CircleButton8);
			this->guna2GradientPanel9->Controls->Add(this->guna2CirclePictureBox11);
			this->guna2GradientPanel9->Controls->Add(this->label25);
			this->guna2GradientPanel9->Controls->Add(this->label26);
			this->guna2GradientPanel9->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->guna2GradientPanel9->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2GradientPanel9->Location = System::Drawing::Point(3, 160);
			this->guna2GradientPanel9->Name = L"guna2GradientPanel9";
			this->guna2GradientPanel9->ShadowDecoration->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->guna2GradientPanel9->Size = System::Drawing::Size(250, 80);
			this->guna2GradientPanel9->TabIndex = 18;
			this->guna2GradientPanel9->UseWaitCursor = true;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::Color::Transparent;
			this->label24->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label24->ForeColor = System::Drawing::Color::Silver;
			this->label24->Location = System::Drawing::Point(73, 9);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(42, 20);
			this->label24->TabIndex = 17;
			this->label24->Text = L"User1";
			this->label24->UseWaitCursor = true;
			// 
			// guna2CircleButton8
			// 
			this->guna2CircleButton8->BackColor = System::Drawing::Color::Transparent;
			this->guna2CircleButton8->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2CircleButton8->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2CircleButton8->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2CircleButton8->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2CircleButton8->FillColor = System::Drawing::Color::Magenta;
			this->guna2CircleButton8->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->guna2CircleButton8->ForeColor = System::Drawing::Color::White;
			this->guna2CircleButton8->Location = System::Drawing::Point(190, 30);
			this->guna2CircleButton8->Name = L"guna2CircleButton8";
			this->guna2CircleButton8->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CircleButton8->Size = System::Drawing::Size(40, 40);
			this->guna2CircleButton8->TabIndex = 15;
			this->guna2CircleButton8->Text = L"7";
			this->guna2CircleButton8->UseWaitCursor = true;
			// 
			// guna2CirclePictureBox11
			// 
			this->guna2CirclePictureBox11->BackColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox11->FillColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox11.Image")));
			this->guna2CirclePictureBox11->ImageRotate = 0;
			this->guna2CirclePictureBox11->Location = System::Drawing::Point(18, 20);
			this->guna2CirclePictureBox11->Name = L"guna2CirclePictureBox11";
			this->guna2CirclePictureBox11->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->guna2CirclePictureBox11->ShadowDecoration->Enabled = true;
			this->guna2CirclePictureBox11->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox11->Size = System::Drawing::Size(36, 36);
			this->guna2CirclePictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox11->TabIndex = 11;
			this->guna2CirclePictureBox11->TabStop = false;
			this->guna2CirclePictureBox11->UseWaitCursor = true;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->BackColor = System::Drawing::Color::Transparent;
			this->label25->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label25->ForeColor = System::Drawing::Color::Silver;
			this->label25->Location = System::Drawing::Point(191, 9);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(39, 17);
			this->label25->TabIndex = 14;
			this->label25->Text = L"Online";
			this->label25->UseWaitCursor = true;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->BackColor = System::Drawing::Color::Transparent;
			this->label26->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label26->ForeColor = System::Drawing::Color::Gray;
			this->label26->Location = System::Drawing::Point(72, 37);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(85, 20);
			this->label26->TabIndex = 13;
			this->label26->Text = L"Last message";
			this->label26->UseWaitCursor = true;
			// 
			// guna2Panel5
			// 
			this->guna2Panel5->BorderThickness = 1;
			this->guna2Panel5->Controls->Add(this->guna2Panel8);
			this->guna2Panel5->Controls->Add(this->guna2TextBox2);
			this->guna2Panel5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->guna2Panel5->Location = System::Drawing::Point(367, 524);
			this->guna2Panel5->Name = L"guna2Panel5";
			this->guna2Panel5->Size = System::Drawing::Size(671, 57);
			this->guna2Panel5->TabIndex = 4;
			// 
			// guna2Panel8
			// 
			this->guna2Panel8->BackColor = System::Drawing::Color::Transparent;
			this->guna2Panel8->Controls->Add(this->guna2CircleButton6);
			this->guna2Panel8->Dock = System::Windows::Forms::DockStyle::Right;
			this->guna2Panel8->Location = System::Drawing::Point(620, 0);
			this->guna2Panel8->Name = L"guna2Panel8";
			this->guna2Panel8->Size = System::Drawing::Size(51, 57);
			this->guna2Panel8->TabIndex = 2;
			// 
			// guna2CircleButton6
			// 
			this->guna2CircleButton6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2CircleButton6->BackColor = System::Drawing::Color::Transparent;
			this->guna2CircleButton6->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->guna2CircleButton6->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->guna2CircleButton6->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->guna2CircleButton6->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->guna2CircleButton6->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2CircleButton6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2CircleButton6->ForeColor = System::Drawing::Color::White;
			this->guna2CircleButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CircleButton6.Image")));
			this->guna2CircleButton6->Location = System::Drawing::Point(5, 7);
			this->guna2CircleButton6->Name = L"guna2CircleButton6";
			this->guna2CircleButton6->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CircleButton6->Size = System::Drawing::Size(40, 40);
			this->guna2CircleButton6->TabIndex = 0;
			this->guna2CircleButton6->Click += gcnew System::EventHandler(this, &MyForm::guna2CircleButton6_Click);
			// 
			// guna2TextBox2
			// 
			this->guna2TextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox2->BorderColor = System::Drawing::Color::Transparent;
			this->guna2TextBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox2->DefaultText = L"";
			this->guna2TextBox2->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox2->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox2->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox2->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox2->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->guna2TextBox2->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2TextBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->guna2TextBox2->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2TextBox2->Location = System::Drawing::Point(6, 12);
			this->guna2TextBox2->Name = L"guna2TextBox2";
			this->guna2TextBox2->PasswordChar = '\0';
			this->guna2TextBox2->PlaceholderText = L"Search";
			this->guna2TextBox2->SelectedText = L"";
			this->guna2TextBox2->Size = System::Drawing::Size(608, 33);
			this->guna2TextBox2->TabIndex = 1;
			// 
			// guna2GradientPanel6
			// 
			this->guna2GradientPanel6->BorderRadius = 15;
			this->guna2GradientPanel6->Controls->Add(this->label18);
			this->guna2GradientPanel6->Controls->Add(this->guna2CirclePictureBox7);
			this->guna2GradientPanel6->Dock = System::Windows::Forms::DockStyle::Left;
			this->guna2GradientPanel6->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->guna2GradientPanel6->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(61)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->guna2GradientPanel6->Location = System::Drawing::Point(0, 0);
			this->guna2GradientPanel6->Name = L"guna2GradientPanel6";
			this->guna2GradientPanel6->Size = System::Drawing::Size(347, 67);
			this->guna2GradientPanel6->TabIndex = 5;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->ForeColor = System::Drawing::Color::White;
			this->label18->Location = System::Drawing::Point(82, 19);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(189, 23);
			this->label18->TabIndex = 18;
			this->label18->Text = L"Last message: ogkvski skkg";
			// 
			// guna2CirclePictureBox7
			// 
			this->guna2CirclePictureBox7->FillColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox7.Image")));
			this->guna2CirclePictureBox7->ImageRotate = 0;
			this->guna2CirclePictureBox7->Location = System::Drawing::Point(13, 12);
			this->guna2CirclePictureBox7->Name = L"guna2CirclePictureBox7";
			this->guna2CirclePictureBox7->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->guna2CirclePictureBox7->ShadowDecoration->CustomizableEdges->BottomLeft = false;
			this->guna2CirclePictureBox7->ShadowDecoration->CustomizableEdges->BottomRight = false;
			this->guna2CirclePictureBox7->ShadowDecoration->CustomizableEdges->TopLeft = false;
			this->guna2CirclePictureBox7->ShadowDecoration->CustomizableEdges->TopRight = false;
			this->guna2CirclePictureBox7->ShadowDecoration->Enabled = true;
			this->guna2CirclePictureBox7->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox7->Size = System::Drawing::Size(36, 36);
			this->guna2CirclePictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox7->TabIndex = 6;
			this->guna2CirclePictureBox7->TabStop = false;
			// 
			// guna2GradientPanel7
			// 
			this->guna2GradientPanel7->BorderRadius = 15;
			this->guna2GradientPanel7->Controls->Add(this->guna2CirclePictureBox10);
			this->guna2GradientPanel7->Controls->Add(this->label14);
			this->guna2GradientPanel7->Dock = System::Windows::Forms::DockStyle::Right;
			this->guna2GradientPanel7->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->guna2GradientPanel7->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2GradientPanel7->Location = System::Drawing::Point(304, 0);
			this->guna2GradientPanel7->Name = L"guna2GradientPanel7";
			this->guna2GradientPanel7->Size = System::Drawing::Size(347, 78);
			this->guna2GradientPanel7->TabIndex = 6;
			// 
			// guna2CirclePictureBox10
			// 
			this->guna2CirclePictureBox10->FillColor = System::Drawing::Color::Transparent;
			this->guna2CirclePictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox10.Image")));
			this->guna2CirclePictureBox10->ImageRotate = 0;
			this->guna2CirclePictureBox10->Location = System::Drawing::Point(293, 21);
			this->guna2CirclePictureBox10->Name = L"guna2CirclePictureBox10";
			this->guna2CirclePictureBox10->ShadowDecoration->Color = System::Drawing::Color::Fuchsia;
			this->guna2CirclePictureBox10->ShadowDecoration->CustomizableEdges->BottomLeft = false;
			this->guna2CirclePictureBox10->ShadowDecoration->CustomizableEdges->BottomRight = false;
			this->guna2CirclePictureBox10->ShadowDecoration->CustomizableEdges->TopLeft = false;
			this->guna2CirclePictureBox10->ShadowDecoration->CustomizableEdges->TopRight = false;
			this->guna2CirclePictureBox10->ShadowDecoration->Enabled = true;
			this->guna2CirclePictureBox10->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox10->Size = System::Drawing::Size(36, 36);
			this->guna2CirclePictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox10->TabIndex = 19;
			this->guna2CirclePictureBox10->TabStop = false;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(31, 26);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(189, 23);
			this->label14->TabIndex = 19;
			this->label14->Text = L"Last message: ogkvski skkg";
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
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel2->Controls->Add(this->guna2Panel7);
			this->flowLayoutPanel2->Controls->Add(this->guna2Panel3);
			this->flowLayoutPanel2->Controls->Add(this->guna2GradientPanel9);
			this->flowLayoutPanel2->Controls->Add(this->guna2GradientPanel2);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel2->Location = System::Drawing::Point(367, 67);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(671, 457);
			this->flowLayoutPanel2->TabIndex = 5;
			// 
			// guna2Panel7
			// 
			this->guna2Panel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Panel7->Controls->Add(this->guna2GradientPanel7);
			this->guna2Panel7->Location = System::Drawing::Point(3, 3);
			this->guna2Panel7->Name = L"guna2Panel7";
			this->guna2Panel7->Size = System::Drawing::Size(651, 78);
			this->guna2Panel7->TabIndex = 19;
			// 
			// guna2Panel3
			// 
			this->guna2Panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Panel3->Controls->Add(this->guna2GradientPanel6);
			this->guna2Panel3->Location = System::Drawing::Point(3, 87);
			this->guna2Panel3->Name = L"guna2Panel3";
			this->guna2Panel3->Size = System::Drawing::Size(657, 67);
			this->guna2Panel3->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->ClientSize = System::Drawing::Size(1311, 581);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->guna2Panel5);
			this->Controls->Add(this->guna2Panel4);
			this->Controls->Add(this->guna2Panel_top);
			this->Controls->Add(this->guna2Panel2);
			this->Controls->Add(this->guna2Panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->guna2Panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox1))->EndInit();
			this->guna2Panel2->ResumeLayout(false);
			this->guna2Panel2->PerformLayout();
			this->guna2CircleProgressBar2->ResumeLayout(false);
			this->guna2CircleProgressBar1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox8))->EndInit();
			this->guna2Panel_top->ResumeLayout(false);
			this->guna2Panel_top->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox9))->EndInit();
			this->guna2Panel4->ResumeLayout(false);
			this->guna2Panel4->PerformLayout();
			this->guna2GradientPanel2->ResumeLayout(false);
			this->guna2GradientPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox4))->EndInit();
			this->guna2GradientPanel9->ResumeLayout(false);
			this->guna2GradientPanel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox11))->EndInit();
			this->guna2Panel5->ResumeLayout(false);
			this->guna2Panel8->ResumeLayout(false);
			this->guna2GradientPanel6->ResumeLayout(false);
			this->guna2GradientPanel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox7))->EndInit();
			this->guna2GradientPanel7->ResumeLayout(false);
			this->guna2GradientPanel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox10))->EndInit();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->guna2Panel7->ResumeLayout(false);
			this->guna2Panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		SocketServer *s1;

	private: void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
		//std::string str;
		//MarshalString(textBox1->Text, str);
		//s1->Send(SEND_MESSAGE, str.c_str());
		//str.clear();
		//s1->Receive(str);
		////String mess(str.c_str());
		//listBox1->Items->Add(gcnew String(str.c_str()));
	}



		 
		   
		   
		   
		   
		   
		   //void SendButtonClick(Object^ sender, EventArgs^ e)
		   //{
			  // String^ message = inputTextBox->Text;
			  // if (!String::IsNullOrEmpty(message))
			  // {
				 //  Label^ messageLabel = gcnew Label();
				 //  messageLabel->AutoSize = false;
				 //  messageLabel->Text = message;

				 //  // Визначення, чи повідомлення відправляється від користувача (You)
				 //  bool isYou = true;

				 //  // Встановлення вирівнювання
				 //  if (!isYou)
				 //  {
					//   messageLabel->Text = "Them: " + message;
					//   messageLabel->Left = 10; // Ліве вирівнювання
				 //  }
				 //  else
				 //  {
					//   messageLabel->Text = "You: " + message;
					//   messageLabel->Left = chatListBox->Width - messageLabel->Width - 10; // Праве вирівнювання
				 //  }

				 //  messageLabel->WordWrap = true; // Дозволяє перенос слів
				 //  messageLabel->Width = chatListBox->Width - 20; // Змінює ширину Label на ширину ListBox

				 //  chatListBox->Controls->Add(messageLabel);
				 //  chatListBox->Items->Add(""); // Додаємо порожній елемент для розділення повідомлень у ListBox
				 //  inputTextBox->Clear();
			  // }
		   //}
		public: ChatNode^ currentNode;
		public: System::Collections::ArrayList ^ chatNodes;

		public: System::Void setCurrent(ChatNode ^node) {
			   currentNode->resetColor();
			   currentNode = node;
			   flowLayoutPanel2 = node->messageView;
		 }

	private: System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void guna2Button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void guna2Panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label17_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void guna2GradientPanel1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	((Guna::UI2::WinForms::Guna2GradientPanel^)sender)->ShadowDecoration->Color = Color::DeepPink;
}
private: System::Void guna2GradientPanel1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	((Guna::UI2::WinForms::Guna2GradientPanel^)sender)->ShadowDecoration->Color = Color::FromArgb(17,22,32);

}
private: System::Void guna2CircleButton5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void guna2CircleButton6_Click(System::Object^ sender, System::EventArgs^ e) {
	ChatNode ^ p = gcnew ChatNode("Test", "Hello", 5, 1, false);
	p->Size = System::Drawing::Size(200, 80);
	flowLayoutPanel1->Controls->Add(p);
}




private: System::Void guna2GradientPanel2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
};

}
