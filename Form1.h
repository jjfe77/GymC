#pragma once
#include <iostream>
#include <string>
//#include <msclr/marshal_cppstd.h>
#include "AdminForm.h"
#include "ProfeForm.h"
#include "UsuarioForm.h"
#include "CuotaForm.h"
#include "MenuForm.h"





namespace CppCLRWinFormsProject {
//namespace Gym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Net;



	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
	
		
			
			try {
				String^ path = System::IO::Path::Combine(Application::StartupPath, "Media\\gym_1.jpg");

				if (System::IO::File::Exists(path)) {
					this->BackgroundImage = System::Drawing::Image::FromFile(path);
					this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				}
				else {
					MessageBox::Show("Archivo no encontrado: " + path);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("No se pudo cargar la imagen: " + ex->Message);
			}
			
			


		
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonIngresar;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxDNI;



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
			this->buttonIngresar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxDNI = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonIngresar
			// 
			this->buttonIngresar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonIngresar->Location = System::Drawing::Point(925, 271);
			this->buttonIngresar->Name = L"buttonIngresar";
			this->buttonIngresar->Size = System::Drawing::Size(189, 82);
			this->buttonIngresar->TabIndex = 0;
			this->buttonIngresar->Text = L"Ingresar";
			this->buttonIngresar->UseVisualStyleBackColor = true;
			this->buttonIngresar->Click += gcnew System::EventHandler(this, &Form1::buttonIngresar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Window;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(878, 167);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"DNI";
			// 
			// textBoxDNI
			// 
			this->textBoxDNI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxDNI->Location = System::Drawing::Point(965, 165);
			this->textBoxDNI->Name = L"textBoxDNI";
			this->textBoxDNI->Size = System::Drawing::Size(199, 34);
			this->textBoxDNI->TabIndex = 2;
			this->textBoxDNI->UseSystemPasswordChar = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1304, 794);
			this->Controls->Add(this->textBoxDNI);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonIngresar);
			this->DoubleBuffered = true;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion


		
		private: System::Void buttonIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ dniManaged = textBoxDNI->Text->Trim();
			if (String::IsNullOrEmpty(dniManaged)) {
				MessageBox::Show("Ingrese un DNI", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			try {
				String^ url = "http://localhost/api/login.php?dni=" + dniManaged;
				HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
				request->Method = "GET";

				HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
				StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
				String^ result = reader->ReadToEnd();

				String^ rol = "";

				if (result->Contains("\"rol\":\"Administrador\"")) {
					rol = "Administrador";
				}
				else if (result->Contains("\"rol\":\"Profesor\"")) {
					rol = "Profesor";
				}
				else if (result->Contains("\"rol\":\"Alumno\"")) {
					rol = "Alumno";
				}
				else {
					MessageBox::Show("DNI no encontrado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Abrir menú principal con rol
				Gym::MenuForm^ menu = gcnew Gym::MenuForm(rol);
				menu->Show();

				this->Hide();

				textBoxDNI->Clear();
				textBoxDNI->Focus();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error de conexión: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		


	};
}
