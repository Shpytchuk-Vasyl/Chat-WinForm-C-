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
	private: Guna::UI2::WinForms::Guna2GradientPanel^ guna2GradientPanel1;
	private: Guna::UI2::WinForms::Guna2TextBox^ password;
	private: Guna::UI2::WinForms::Guna2TextBox^ user;
	private: Guna::UI2::WinForms::Guna2Button^ logIn;



	private: Guna::UI2::WinForms::Guna2Button^ singIn;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
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
			this->guna2GradientPanel1 = (gcnew Guna::UI2::WinForms::Guna2GradientPanel());
			this->exitButton = (gcnew Guna::UI2::WinForms::Guna2ControlBox());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->user = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->logIn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->password = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->singIn = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2GradientPanel1->SuspendLayout();
			this->guna2Panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// guna2GradientPanel1
			// 
			this->guna2GradientPanel1->BackColor = System::Drawing::Color::Transparent;
			this->guna2GradientPanel1->Controls->Add(this->exitButton);
			this->guna2GradientPanel1->Controls->Add(this->guna2Panel1);
			this->guna2GradientPanel1->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->guna2GradientPanel1->FillColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->guna2GradientPanel1->Location = System::Drawing::Point(0, 0);
			this->guna2GradientPanel1->Name = L"guna2GradientPanel1";
			this->guna2GradientPanel1->Size = System::Drawing::Size(434, 295);
			this->guna2GradientPanel1->TabIndex = 0;
			this->guna2GradientPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RegisterForm::guna2GradientPanel1_Paint);
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
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->AutoSize = true;
			this->guna2Panel1->Controls->Add(this->user);
			this->guna2Panel1->Controls->Add(this->logIn);
			this->guna2Panel1->Controls->Add(this->password);
			this->guna2Panel1->Controls->Add(this->singIn);
			this->guna2Panel1->Location = System::Drawing::Point(88, 60);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->Size = System::Drawing::Size(236, 151);
			this->guna2Panel1->TabIndex = 5;
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
			this->user->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->user->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->user->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->user->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->user->Location = System::Drawing::Point(17, 0);
			this->user->Name = L"user";
			this->user->PasswordChar = '\0';
			this->user->PlaceholderText = L"User name";
			this->user->SelectedText = L"";
			this->user->Size = System::Drawing::Size(216, 36);
			this->user->TabIndex = 1;
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
			this->logIn->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->logIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->logIn->ForeColor = System::Drawing::Color::White;
			this->logIn->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->logIn->Location = System::Drawing::Point(138, 103);
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
			this->password->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->password->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->password->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->password->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->password->Location = System::Drawing::Point(17, 42);
			this->password->Name = L"password";
			this->password->PasswordChar = '\0';
			this->password->PlaceholderText = L"Password";
			this->password->SelectedText = L"";
			this->password->Size = System::Drawing::Size(216, 36);
			this->password->TabIndex = 2;
			this->password->TextChanged += gcnew System::EventHandler(this, &RegisterForm::guna2TextBox1_TextChanged);
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
			this->singIn->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->singIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->singIn->ForeColor = System::Drawing::Color::White;
			this->singIn->HoverState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->singIn->Location = System::Drawing::Point(17, 103);
			this->singIn->Name = L"singIn";
			this->singIn->Size = System::Drawing::Size(97, 45);
			this->singIn->TabIndex = 3;
			this->singIn->Text = L"Sing in";
			this->singIn->Click += gcnew System::EventHandler(this, &RegisterForm::singIn_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 295);
			this->Controls->Add(this->guna2GradientPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"RegisterForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->guna2GradientPanel1->ResumeLayout(false);
			this->guna2GradientPanel1->PerformLayout();
			this->guna2Panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


		private: System::Void singIn_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void logIn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
