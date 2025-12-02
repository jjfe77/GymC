#pragma once

#include "AdminForm.h"
#include "CuotaForm.h"
#include "EquiposForm.h"
#include "EjerciciosForm.h"
#include "RutinasForm.h"
#include "UsuarioForm.h"




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
				buttonEquiposForm->Enabled = true;
				buttonEjerciciosForm->Enabled = true;
				buttonRutinasForm->Enabled = true;

			}
			else if (rol == "Profesor") {
				buttonAdminForm->Enabled = false;
				buttonCuotaForm->Enabled = false;
				buttonEquiposForm->Enabled = true;
				buttonEjerciciosForm->Enabled = true;
				buttonRutinasForm->Enabled = true;
			}
			else if (rol == "Alumno") {
				buttonAdminForm->Enabled = false;
				buttonCuotaForm->Enabled = false;
				buttonEquiposForm->Enabled = false;
				buttonEjerciciosForm->Enabled = false;
				buttonRutinasForm->Enabled = false;
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
	private: System::Windows::Forms::Button^ buttonEquiposForm;
	private: System::Windows::Forms::Button^ buttonEjerciciosForm;
	private: System::Windows::Forms::Button^ buttonRutinasForm;
	private: System::Windows::Forms::Button^ buttonUsuariosForm;






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
			this->buttonEquiposForm = (gcnew System::Windows::Forms::Button());
			this->buttonEjerciciosForm = (gcnew System::Windows::Forms::Button());
			this->buttonRutinasForm = (gcnew System::Windows::Forms::Button());
			this->buttonUsuariosForm = (gcnew System::Windows::Forms::Button());
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
			// buttonEquiposForm
			// 
			this->buttonEquiposForm->Location = System::Drawing::Point(25, 206);
			this->buttonEquiposForm->Name = L"buttonEquiposForm";
			this->buttonEquiposForm->Size = System::Drawing::Size(157, 84);
			this->buttonEquiposForm->TabIndex = 2;
			this->buttonEquiposForm->Text = L"Equipos";
			this->buttonEquiposForm->UseVisualStyleBackColor = true;
			this->buttonEquiposForm->Click += gcnew System::EventHandler(this, &MenuForm::buttonEquiposForm_Click);
			// 
			// buttonEjerciciosForm
			// 
			this->buttonEjerciciosForm->Location = System::Drawing::Point(25, 298);
			this->buttonEjerciciosForm->Name = L"buttonEjerciciosForm";
			this->buttonEjerciciosForm->Size = System::Drawing::Size(157, 84);
			this->buttonEjerciciosForm->TabIndex = 3;
			this->buttonEjerciciosForm->Text = L"Ejercicios";
			this->buttonEjerciciosForm->UseVisualStyleBackColor = true;
			this->buttonEjerciciosForm->Click += gcnew System::EventHandler(this, &MenuForm::buttonEjerciciosForm_Click);
			// 
			// buttonRutinasForm
			// 
			this->buttonRutinasForm->Location = System::Drawing::Point(25, 388);
			this->buttonRutinasForm->Name = L"buttonRutinasForm";
			this->buttonRutinasForm->Size = System::Drawing::Size(157, 84);
			this->buttonRutinasForm->TabIndex = 4;
			this->buttonRutinasForm->Text = L"Rutinas";
			this->buttonRutinasForm->UseVisualStyleBackColor = true;
			this->buttonRutinasForm->Click += gcnew System::EventHandler(this, &MenuForm::buttonRutinasForm_Click);
			// 
			// buttonUsuariosForm
			// 
			this->buttonUsuariosForm->Location = System::Drawing::Point(25, 478);
			this->buttonUsuariosForm->Name = L"buttonUsuariosForm";
			this->buttonUsuariosForm->Size = System::Drawing::Size(157, 84);
			this->buttonUsuariosForm->TabIndex = 5;
			this->buttonUsuariosForm->Text = L"Usuarios";
			this->buttonUsuariosForm->UseVisualStyleBackColor = true;
			this->buttonUsuariosForm->Click += gcnew System::EventHandler(this, &MenuForm::buttonUsuariosForm_Click);
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
			this->Controls->Add(this->buttonUsuariosForm);
			this->Controls->Add(this->buttonRutinasForm);
			this->Controls->Add(this->buttonEjerciciosForm);
			this->Controls->Add(this->buttonEquiposForm);
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






	private: System::Void buttonEquiposForm_Click(System::Object^ sender, System::EventArgs^ e) {
		// Deshabilitar el botón al abrir el form
		buttonEquiposForm->Enabled = false;

		// Crear instancia del formulario
		Gym::EquiposForm^ ef = gcnew Gym::EquiposForm();

		// Suscribirse al evento FormClosed para re-habilitar el botón
		ef->FormClosed += gcnew FormClosedEventHandler(this, &MenuForm::EquiposFormClosed);

		// Mostrar el formulario
		ef->Show();
	}

		   // Método que se ejecuta cuando se cierra EquiposForm
	private: System::Void EquiposFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		buttonEquiposForm->Enabled = true;
	}

		   // Evento Click del botón Ejercicios
	private: System::Void buttonEjerciciosForm_Click(System::Object^ sender, System::EventArgs^ e) {
		// Deshabilitar el botón al abrir el form
		buttonEjerciciosForm->Enabled = false;

		// Crear instancia del formulario Ejercicios
		Gym::EjerciciosForm^ ef = gcnew Gym::EjerciciosForm();

		// Suscribirse al evento FormClosed para re-habilitar el botón
		ef->FormClosed += gcnew FormClosedEventHandler(this, &MenuForm::EjerciciosFormClosed);

		// Mostrar el formulario
		ef->Show();
	}

		   // Método que se ejecuta cuando se cierra EjerciciosForm
	private: System::Void EjerciciosFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		buttonEjerciciosForm->Enabled = true;
	}

	private: System::Void buttonRutinasForm_Click(System::Object^ sender, System::EventArgs^ e) {
		// Deshabilitar el botón al abrir el form 
		buttonRutinasForm->Enabled = false;

		// Crear instancia del formulario de Rutinas
		Gym::RutinasForm^ rf = gcnew Gym::RutinasForm();

		// Suscribirse al evento FormClosed para re-habilitar el botón
		rf->FormClosed += gcnew FormClosedEventHandler(this, &MenuForm::RutinasFormClosed);

		// Mostrar el formulario
		rf->Show();
	}

	private: System::Void RutinasFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		buttonRutinasForm->Enabled = true;
	}


private: System::Void buttonUsuariosForm_Click(System::Object^ sender, System::EventArgs^ e) {
	// Deshabilitar el botón al abrir el form 
	buttonUsuariosForm->Enabled = false;
	// Crear instancia del formulario de Usuarios
	Gym::UsuarioForm^ uf = gcnew Gym::UsuarioForm();
	// Suscribirse al evento FormClosed para re-habilitar el botón
	uf->FormClosed += gcnew FormClosedEventHandler(this, &MenuForm::UsuarioFormClosed);
	// Mostrar el formulario
	uf->Show();
}
	private: System::Void UsuarioFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		buttonUsuariosForm->Enabled = true;
	}
};
}
