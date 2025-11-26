#pragma once

#include "AdminForm.h"
#include "CuotaForm.h"



namespace Gym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}




		MenuForm(String^ rol) {
			InitializeComponent();
			this->StartPosition = FormStartPosition::Manual;
			this->Location = System::Drawing::Point(10, 10);
			// Configurar botones según rol
			if (rol == "Administrador") {
				buttonAdminForm->Enabled = true;
				buttonCuotaForm->Enabled = true;

			}
			else if (rol == "Profesor") {
				buttonAdminForm->Enabled = true;
				buttonCuotaForm->Enabled = false;
			}
			else if (rol == "Alumno") {
				buttonAdminForm->Enabled = false;
				buttonCuotaForm->Enabled = false;
			}
		}




	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonAdminForm;
	protected:
	private: System::Windows::Forms::Button^ buttonCuotaForm;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ buttonSalirMenu;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonAdminForm = (gcnew System::Windows::Forms::Button());
			this->buttonCuotaForm = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->buttonSalirMenu = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonAdminForm
			// 
			this->buttonAdminForm->Location = System::Drawing::Point(25, 26);
			this->buttonAdminForm->Name = L"buttonAdminForm";
			this->buttonAdminForm->Size = System::Drawing::Size(157, 84);
			this->buttonAdminForm->TabIndex = 0;
			this->buttonAdminForm->Text = L"Administrar usuarios";
			this->buttonAdminForm->UseVisualStyleBackColor = true;
			this->buttonAdminForm->Click += gcnew System::EventHandler(this, &MenuForm::buttonAdminForm_Click);
			// 
			// buttonCuotaForm
			// 
			this->buttonCuotaForm->Location = System::Drawing::Point(25, 116);
			this->buttonCuotaForm->Name = L"buttonCuotaForm";
			this->buttonCuotaForm->Size = System::Drawing::Size(157, 84);
			this->buttonCuotaForm->TabIndex = 1;
			this->buttonCuotaForm->Text = L"Menbresias";
			this->buttonCuotaForm->UseVisualStyleBackColor = true;
			this->buttonCuotaForm->Click += gcnew System::EventHandler(this, &MenuForm::buttonCuotaForm_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(25, 206);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(157, 84);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(25, 298);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(157, 84);
			this->button4->TabIndex = 3;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(25, 388);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(157, 84);
			this->button5->TabIndex = 4;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(25, 478);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(157, 84);
			this->button6->TabIndex = 5;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(25, 568);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(157, 84);
			this->button7->TabIndex = 6;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(25, 658);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(157, 84);
			this->button8->TabIndex = 7;
			this->button8->Text = L"button8";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// buttonSalirMenu
			// 
			this->buttonSalirMenu->Location = System::Drawing::Point(25, 748);
			this->buttonSalirMenu->Name = L"buttonSalirMenu";
			this->buttonSalirMenu->Size = System::Drawing::Size(157, 84);
			this->buttonSalirMenu->TabIndex = 8;
			this->buttonSalirMenu->Text = L"Salir";
			this->buttonSalirMenu->UseVisualStyleBackColor = true;
			this->buttonSalirMenu->Click += gcnew System::EventHandler(this, &MenuForm::buttonSalirMenu_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(213, 862);
			this->Controls->Add(this->buttonSalirMenu);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->buttonCuotaForm);
			this->Controls->Add(this->buttonAdminForm);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonSalirMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}




	private: System::Void buttonAdminForm_Click(System::Object^ sender, System::EventArgs^ e) {
		// Deshabilitar el botón al abrir el form
		buttonAdminForm->Enabled = false;

		// Crear instancia del formulario
		Gym::AdminForm^ af = gcnew Gym::AdminForm();

		// Suscribirse al evento FormClosed para re-habilitar el botón
		af->FormClosed += gcnew FormClosedEventHandler(this, &MenuForm::AdminFormClosed);

		// Mostrar el formulario
		af->Show();
	}

		   // Método que se ejecuta cuando se cierra AdminForm
	private: System::Void AdminFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		buttonAdminForm->Enabled = true;
	}






	private: System::Void buttonCuotaForm_Click(System::Object^ sender, System::EventArgs^ e) {
		// Deshabilitar el botón al abrir el form
		buttonCuotaForm->Enabled = false;

		// Crear instancia del formulario
		Gym::CuotaForm^ cf = gcnew Gym::CuotaForm();

		// Suscribirse al evento FormClosed para re-habilitar el botón
		cf->FormClosed += gcnew FormClosedEventHandler(this, &MenuForm::CuotaFormClosed);

		// Mostrar el formulario
		cf->Show();
	}

		   // Método que se ejecuta cuando se cierra CuotaForm
	private: System::Void CuotaFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		buttonCuotaForm->Enabled = true;
	}



	};
}
