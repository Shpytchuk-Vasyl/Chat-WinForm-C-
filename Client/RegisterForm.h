#pragma once


namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
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
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: Guna::UI2::WinForms::Guna2GradientPanel^ guna2GradientPanel1;
	public: Guna::UI2::WinForms::Guna2TextBox^ password;
	public: Guna::UI2::WinForms::Guna2TextBox^ user;
	public: Guna::UI2::WinForms::Guna2Button^ logIn;



	public: Guna::UI2::WinForms::Guna2Button^ singIn;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: Guna::UI2::WinForms::Guna2ControlBox^ exitButton;
	private: System::Windows::Forms::Label^ errorLabel;
	private: Guna::UI2::WinForms::Guna2ImageRadioButton^ picture1;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: Guna::UI2::WinForms::Guna2ImageRadioButton^ picture2;
	private: Guna::UI2::WinForms::Guna2ImageRadioButton^ picture3;
	private: Guna::UI2::WinForms::Guna2ImageRadioButton^ picture4;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->guna2GradientPanel1 = (gcnew Guna::UI2::WinForms::Guna2GradientPanel());
			this->exitButton = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->picture1 = (gcnew Guna::UI2::WinForms::Guna2ImageRadioButton());
			this->picture2 = (gcnew Guna::UI2::WinForms::Guna2ImageRadioButton());
			this->picture3 = (gcnew Guna::UI2::WinForms::Guna2ImageRadioButton());
			this->picture4 = (gcnew Guna::UI2::WinForms::Guna2ImageRadioButton());
			this->errorLabel = (gcnew System::Windows::Forms::Label());
			this->user = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->logIn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->password = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->singIn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2GradientPanel1->SuspendLayout();
			this->guna2Panel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// guna2GradientPanel1
			// 
			this->guna2GradientPanel1->BackColor = System::Drawing::Color::Transparent;
			this->guna2GradientPanel1->Controls->Add(this->flowLayoutPanel1);
			this->guna2GradientPanel1->Controls->Add(this->exitButton);
			this->guna2GradientPanel1->Controls->Add(this->guna2Panel1);
			this->guna2GradientPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->guna2GradientPanel1->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->guna2GradientPanel1->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2GradientPanel1->Location = System::Drawing::Point(0, 0);
			this->guna2GradientPanel1->Name = L"guna2GradientPanel1";
			this->guna2GradientPanel1->Size = System::Drawing::Size(434, 349);
			this->guna2GradientPanel1->TabIndex = 0;
			// 
			// exitButton
			// 
			this->exitButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exitButton->FillColor = System::Drawing::Color::Transparent;
			this->exitButton->IconColor = System::Drawing::Color::White;
			this->exitButton->Location = System::Drawing::Point(389, 0);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(45, 29);
			this->exitButton->TabIndex = 19;
			this->exitButton->Click += gcnew System::EventHandler(this, &RegisterForm::exitButton_Click);
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->AutoSize = true;
			this->guna2Panel1->Controls->Add(this->errorLabel);
			this->guna2Panel1->Controls->Add(this->user);
			this->guna2Panel1->Controls->Add(this->logIn);
			this->guna2Panel1->Controls->Add(this->password);
			this->guna2Panel1->Controls->Add(this->singIn);
			this->guna2Panel1->Location = System::Drawing::Point(88, 60);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->Size = System::Drawing::Size(252, 292);
			this->guna2Panel1->TabIndex = 5;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->Controls->Add(this->picture1);
			this->flowLayoutPanel1->Controls->Add(this->picture2);
			this->flowLayoutPanel1->Controls->Add(this->picture3);
			this->flowLayoutPanel1->Controls->Add(this->picture4);
			this->flowLayoutPanel1->Location = System::Drawing::Point(43, 260);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(344, 86);
			this->flowLayoutPanel1->TabIndex = 10;
			// 
			// picture1
			// 
			this->picture1->CheckedState->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"resource.Image")));
			this->picture1->CheckedState->ImageSize = System::Drawing::Size(60, 60);
			this->picture1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picture1.Image")));
			this->picture1->ImageOffset = System::Drawing::Point(0, 0);
			this->picture1->ImageRotate = 0;
			this->picture1->ImageSize = System::Drawing::Size(70, 70);
			this->picture1->IndicateFocus = true;
			this->picture1->Location = System::Drawing::Point(3, 3);
			this->picture1->Name = L"picture1";
			this->picture1->Size = System::Drawing::Size(80, 80);
			this->picture1->TabIndex = 9;
			this->picture1->UseTransparentBackground = true;
			this->picture1->CheckedChanged += gcnew System::EventHandler(this, &RegisterForm::guna2ImageRadioButton4_CheckedChanged);
			// 
			// picture2
			// 
			this->picture2->CheckedState->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"resource.Image1")));
			this->picture2->CheckedState->ImageSize = System::Drawing::Size(60, 60);
			this->picture2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picture2.Image")));
			this->picture2->ImageOffset = System::Drawing::Point(0, 0);
			this->picture2->ImageRotate = 0;
			this->picture2->ImageSize = System::Drawing::Size(70, 70);
			this->picture2->IndicateFocus = true;
			this->picture2->Location = System::Drawing::Point(89, 3);
			this->picture2->Name = L"picture2";
			this->picture2->Size = System::Drawing::Size(80, 80);
			this->picture2->TabIndex = 10;
			this->picture2->UseTransparentBackground = true;
			this->picture2->CheckedChanged += gcnew System::EventHandler(this, &RegisterForm::guna2ImageRadioButton1_CheckedChanged);
			// 
			// picture3
			// 
			this->picture3->CheckedState->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"resource.Image2")));
			this->picture3->CheckedState->ImageSize = System::Drawing::Size(60, 60);
			this->picture3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picture3.Image")));
			this->picture3->ImageOffset = System::Drawing::Point(0, 0);
			this->picture3->ImageRotate = 0;
			this->picture3->ImageSize = System::Drawing::Size(70, 70);
			this->picture3->IndicateFocus = true;
			this->picture3->Location = System::Drawing::Point(175, 3);
			this->picture3->Name = L"picture3";
			this->picture3->Size = System::Drawing::Size(80, 80);
			this->picture3->TabIndex = 11;
			this->picture3->UseTransparentBackground = true;
			this->picture3->CheckedChanged += gcnew System::EventHandler(this, &RegisterForm::picture3_CheckedChanged);
			// 
			// picture4
			// 
			this->picture4->CheckedState->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"resource.Image1")));
			this->picture4->CheckedState->ImageSize = System::Drawing::Size(60, 60);
			this->picture4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picture4.Image")));
			this->picture4->ImageOffset = System::Drawing::Point(0, 0);
			this->picture4->ImageRotate = 0;
			this->picture4->ImageSize = System::Drawing::Size(70, 70);
			this->picture4->IndicateFocus = true;
			this->picture4->Location = System::Drawing::Point(261, 3);
			this->picture4->Name = L"picture4";
			this->picture4->Size = System::Drawing::Size(80, 80);
			this->picture4->TabIndex = 12;
			this->picture4->UseTransparentBackground = true;
			this->picture4->CheckedChanged += gcnew System::EventHandler(this, &RegisterForm::picture4_CheckedChanged);
			// 
			// errorLabel
			// 
			this->errorLabel->AutoSize = true;
			this->errorLabel->ForeColor = System::Drawing::Color::Black;
			this->errorLabel->Location = System::Drawing::Point(14, 92);
			this->errorLabel->Name = L"errorLabel";
			this->errorLabel->Size = System::Drawing::Size(0, 16);
			this->errorLabel->TabIndex = 5;
			// 
			// user
			// 
			this->user->BorderColor = System::Drawing::Color::Transparent;
			this->user->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->user->DefaultText = L"";
			this->user->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->user->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->user->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->user->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->user->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->user->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->user->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->user->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->user->Location = System::Drawing::Point(0, 0);
			this->user->Name = L"user";
			this->user->PasswordChar = '\0';
			this->user->PlaceholderText = L"User name";
			this->user->SelectedText = L"";
			this->user->Size = System::Drawing::Size(233, 36);
			this->user->TabIndex = 1;
			this->user->TextChanged += gcnew System::EventHandler(this, &RegisterForm::user_TextChanged);
			// 
			// logIn
			// 
			this->logIn->BackColor = System::Drawing::Color::Magenta;
			this->logIn->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->logIn->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->logIn->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->logIn->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->logIn->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->logIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->logIn->ForeColor = System::Drawing::Color::White;
			this->logIn->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->logIn->Location = System::Drawing::Point(138, 132);
			this->logIn->Name = L"logIn";
			this->logIn->Size = System::Drawing::Size(95, 45);
			this->logIn->TabIndex = 4;
			this->logIn->Text = L"Log in";
			this->logIn->Click += gcnew System::EventHandler(this, &RegisterForm::logIn_Click);
			// 
			// password
			// 
			this->password->BorderColor = System::Drawing::Color::Transparent;
			this->password->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->password->DefaultText = L"";
			this->password->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->password->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->password->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->password->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->password->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->password->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->password->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->password->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->password->Location = System::Drawing::Point(0, 42);
			this->password->Name = L"password";
			this->password->PasswordChar = '\0';
			this->password->PlaceholderText = L"Password";
			this->password->SelectedText = L"";
			this->password->Size = System::Drawing::Size(233, 36);
			this->password->TabIndex = 2;
			this->password->TextChanged += gcnew System::EventHandler(this, &RegisterForm::password_TextChanged);
			// 
			// singIn
			// 
			this->singIn->BackColor = System::Drawing::Color::Magenta;
			this->singIn->BorderThickness = 1;
			this->singIn->DisabledState->BorderColor = System::Drawing::Color::DarkGray;
			this->singIn->DisabledState->CustomBorderColor = System::Drawing::Color::DarkGray;
			this->singIn->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(169)), static_cast<System::Int32>(static_cast<System::Byte>(169)));
			this->singIn->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->singIn->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->singIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->singIn->ForeColor = System::Drawing::Color::White;
			this->singIn->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->singIn->Location = System::Drawing::Point(0, 132);
			this->singIn->Name = L"singIn";
			this->singIn->Size = System::Drawing::Size(95, 45);
			this->singIn->TabIndex = 3;
			this->singIn->Text = L"Sing in";
			this->singIn->Click += gcnew System::EventHandler(this, &RegisterForm::singIn_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(434, 349);
			this->Controls->Add(this->guna2GradientPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"RegisterForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->guna2GradientPanel1->ResumeLayout(false);
			this->guna2GradientPanel1->PerformLayout();
			this->guna2Panel1->ResumeLayout(false);
			this->guna2Panel1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		public: property bool isUserCloseWindow;
		public: property int picture;


		private: System::Void singIn_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void logIn_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void user_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			errorLabel->Text = "";
			user->BorderColor = Color::Transparent;
		}

		private: System::Void password_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			errorLabel->Text = "";
			user->BorderColor = Color::Transparent;
		}

private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	isUserCloseWindow = true;
	this->Close();
}

private: System::Void guna2ImageRadioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	picture = 1;
}
private: System::Void guna2ImageRadioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	picture = 2;

}
private: System::Void picture3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	picture = 3;

}
private: System::Void picture4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	picture = 4;

}
};
}
