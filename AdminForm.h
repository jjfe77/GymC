#pragma once
//#include <Windows.h>

namespace Gym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Net;


	/// <summary>
	/// Resumen de AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
	public:
		AdminForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			// Después de InitializeComponent() o al listar/buscar datos
			this->dataGridViewUsuarios->Columns["id"]->Width = 50;          // N° Socio
			this->dataGridViewUsuarios->Columns["dni"]->Width = 80;        // DNI
			this->dataGridViewUsuarios->Columns["nombre"]->Width = 140;     // Nombre
			this->dataGridViewUsuarios->Columns["apellido"]->Width = 140;   // Apellido
			this->dataGridViewUsuarios->Columns["rol"]->Width = 90;         // Rol
			this->dataGridViewUsuarios->Columns["edad"]->Width = 40;        // Edad
			this->dataGridViewUsuarios->Columns["peso"]->Width = 50;        // Peso
			this->dataGridViewUsuarios->Columns["altura"]->Width = 60;      // Altura
			this->dataGridViewUsuarios->Columns["grupo_sanguineo"]->Width = 70; // Grupo Sanguíneo
			this->dataGridViewUsuarios->Columns["direccion"]->Width = 190;  // Dirección
			this->dataGridViewUsuarios->Columns["telefono"]->Width = 80;   // Teléfono
			this->dataGridViewUsuarios->Columns["id"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewUsuarios->Columns["dni"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewUsuarios->Columns["edad"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewUsuarios->Columns["peso"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewUsuarios->Columns["altura"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewUsuarios->Columns["grupo_sanguineo"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;

			for each (DataGridViewColumn ^ col in this->dataGridViewUsuarios->Columns) {
				col->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
				col->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
			}
			// Primero, centramos todas
			for each (DataGridViewColumn ^ col in this->dataGridViewUsuarios->Columns) {
				col->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
				col->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
			}

			// Luego, alineamos a la izquierda las columnas que quieras, por nombre
			this->dataGridViewUsuarios->Columns["nombre"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
			this->dataGridViewUsuarios->Columns["apellido"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
			this->dataGridViewUsuarios->Columns["direccion"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;






		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewUsuarios;
	protected:











	private: System::Windows::Forms::Button^ buttonListar;
	private: System::Windows::Forms::Button^ buttonAgregar;
	private: System::Windows::Forms::Button^ buttonGuardar;
	private: System::Windows::Forms::Button^ buttonEliminar;
	private: System::Windows::Forms::Button^ buttonBuscar;





		   //private: System::Windows::Forms::DataGridViewTextBoxColumn^ rol;






	private: System::Windows::Forms::Button^ buttonLimpiar;
	private: System::Windows::Forms::Button^ buttonCerrar;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dni;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ apellido;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ rol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ edad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ peso;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ altura;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ grupo_sanguineo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ direccion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ telefono;




	protected:












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
			this->dataGridViewUsuarios = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dni = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->apellido = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rol = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->edad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->peso = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->altura = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grupo_sanguineo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->direccion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->telefono = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonListar = (gcnew System::Windows::Forms::Button());
			this->buttonAgregar = (gcnew System::Windows::Forms::Button());
			this->buttonGuardar = (gcnew System::Windows::Forms::Button());
			this->buttonEliminar = (gcnew System::Windows::Forms::Button());
			this->buttonBuscar = (gcnew System::Windows::Forms::Button());
			this->buttonLimpiar = (gcnew System::Windows::Forms::Button());
			this->buttonCerrar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewUsuarios))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewUsuarios
			// 
			this->dataGridViewUsuarios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewUsuarios->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->id,
					this->dni, this->nombre, this->apellido, this->rol, this->edad, this->peso, this->altura, this->grupo_sanguineo, this->direccion,
					this->telefono
			});
			this->dataGridViewUsuarios->Location = System::Drawing::Point(25, 82);
			this->dataGridViewUsuarios->Name = L"dataGridViewUsuarios";
			this->dataGridViewUsuarios->RowHeadersWidth = 51;
			this->dataGridViewUsuarios->RowTemplate->Height = 24;
			this->dataGridViewUsuarios->Size = System::Drawing::Size(1426, 244);
			this->dataGridViewUsuarios->TabIndex = 0;
			// 
			// id
			// 
			this->id->HeaderText = L"N° Socio";
			this->id->MinimumWidth = 6;
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 125;
			// 
			// dni
			// 
			this->dni->HeaderText = L"DNI";
			this->dni->MinimumWidth = 6;
			this->dni->Name = L"dni";
			this->dni->Width = 125;
			// 
			// nombre
			// 
			this->nombre->HeaderText = L"Nombre";
			this->nombre->MinimumWidth = 6;
			this->nombre->Name = L"nombre";
			this->nombre->Width = 125;
			// 
			// apellido
			// 
			this->apellido->HeaderText = L"Apellido";
			this->apellido->MinimumWidth = 6;
			this->apellido->Name = L"apellido";
			this->apellido->Width = 125;
			// 
			// rol
			// 
			this->rol->HeaderText = L"Rol";
			this->rol->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Administrador", L"Profesor", L"Alumno" });
			this->rol->MinimumWidth = 6;
			this->rol->Name = L"rol";
			this->rol->Width = 125;
			// 
			// edad
			// 
			this->edad->HeaderText = L"Edad";
			this->edad->MinimumWidth = 6;
			this->edad->Name = L"edad";
			this->edad->Width = 125;
			// 
			// peso
			// 
			this->peso->HeaderText = L"Peso";
			this->peso->MinimumWidth = 6;
			this->peso->Name = L"peso";
			this->peso->Width = 125;
			// 
			// altura
			// 
			this->altura->HeaderText = L"Altura";
			this->altura->MinimumWidth = 6;
			this->altura->Name = L"altura";
			this->altura->Width = 125;
			// 
			// grupo_sanguineo
			// 
			this->grupo_sanguineo->HeaderText = L"Grupo Sanguineo";
			this->grupo_sanguineo->MinimumWidth = 6;
			this->grupo_sanguineo->Name = L"grupo_sanguineo";
			this->grupo_sanguineo->Width = 125;
			// 
			// direccion
			// 
			this->direccion->HeaderText = L"Direccion / Mail";
			this->direccion->MinimumWidth = 6;
			this->direccion->Name = L"direccion";
			this->direccion->Width = 125;
			// 
			// telefono
			// 
			this->telefono->HeaderText = L"Telefono";
			this->telefono->MinimumWidth = 6;
			this->telefono->Name = L"telefono";
			this->telefono->Width = 125;
			// 
			// buttonListar
			// 
			this->buttonListar->Location = System::Drawing::Point(74, 347);
			this->buttonListar->Name = L"buttonListar";
			this->buttonListar->Size = System::Drawing::Size(144, 72);
			this->buttonListar->TabIndex = 1;
			this->buttonListar->Text = L"Listar";
			this->buttonListar->UseVisualStyleBackColor = true;
			this->buttonListar->Click += gcnew System::EventHandler(this, &AdminForm::buttonListar_Click);
			// 
			// buttonAgregar
			// 
			this->buttonAgregar->Location = System::Drawing::Point(274, 347);
			this->buttonAgregar->Name = L"buttonAgregar";
			this->buttonAgregar->Size = System::Drawing::Size(144, 72);
			this->buttonAgregar->TabIndex = 2;
			this->buttonAgregar->Text = L"Agregar";
			this->buttonAgregar->UseVisualStyleBackColor = true;
			this->buttonAgregar->Click += gcnew System::EventHandler(this, &AdminForm::buttonAgregar_Click);
			// 
			// buttonGuardar
			// 
			this->buttonGuardar->Enabled = false;
			this->buttonGuardar->Location = System::Drawing::Point(475, 347);
			this->buttonGuardar->Name = L"buttonGuardar";
			this->buttonGuardar->Size = System::Drawing::Size(144, 72);
			this->buttonGuardar->TabIndex = 3;
			this->buttonGuardar->Text = L"Guardar";
			this->buttonGuardar->UseVisualStyleBackColor = true;
			this->buttonGuardar->Click += gcnew System::EventHandler(this, &AdminForm::buttonGuardar_Click);
			// 
			// buttonEliminar
			// 
			this->buttonEliminar->Location = System::Drawing::Point(673, 347);
			this->buttonEliminar->Name = L"buttonEliminar";
			this->buttonEliminar->Size = System::Drawing::Size(144, 72);
			this->buttonEliminar->TabIndex = 4;
			this->buttonEliminar->Text = L"Eliminar";
			this->buttonEliminar->UseVisualStyleBackColor = true;
			this->buttonEliminar->Click += gcnew System::EventHandler(this, &AdminForm::buttonEliminar_Click);
			// 
			// buttonBuscar
			// 
			this->buttonBuscar->Location = System::Drawing::Point(863, 347);
			this->buttonBuscar->Name = L"buttonBuscar";
			this->buttonBuscar->Size = System::Drawing::Size(144, 72);
			this->buttonBuscar->TabIndex = 5;
			this->buttonBuscar->Text = L"Buscar";
			this->buttonBuscar->UseVisualStyleBackColor = true;
			this->buttonBuscar->Click += gcnew System::EventHandler(this, &AdminForm::buttonBuscar_Click);
			// 
			// buttonLimpiar
			// 
			this->buttonLimpiar->Location = System::Drawing::Point(1041, 347);
			this->buttonLimpiar->Name = L"buttonLimpiar";
			this->buttonLimpiar->Size = System::Drawing::Size(144, 72);
			this->buttonLimpiar->TabIndex = 6;
			this->buttonLimpiar->Text = L"Limpiar";
			this->buttonLimpiar->UseVisualStyleBackColor = true;
			this->buttonLimpiar->Click += gcnew System::EventHandler(this, &AdminForm::buttonLimpiar_Click);
			// 
			// buttonCerrar
			// 
			this->buttonCerrar->Location = System::Drawing::Point(1216, 347);
			this->buttonCerrar->Name = L"buttonCerrar";
			this->buttonCerrar->Size = System::Drawing::Size(144, 72);
			this->buttonCerrar->TabIndex = 7;
			this->buttonCerrar->Text = L"Cerrar";
			this->buttonCerrar->UseVisualStyleBackColor = true;
			this->buttonCerrar->Click += gcnew System::EventHandler(this, &AdminForm::buttonCerrar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(315, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(866, 53);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Administracion de Usuarios del sistema";
			// 
			// AdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1508, 747);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonCerrar);
			this->Controls->Add(this->buttonLimpiar);
			this->Controls->Add(this->buttonBuscar);
			this->Controls->Add(this->buttonEliminar);
			this->Controls->Add(this->buttonGuardar);
			this->Controls->Add(this->buttonAgregar);
			this->Controls->Add(this->buttonListar);
			this->Controls->Add(this->dataGridViewUsuarios);
			this->Name = L"AdminForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewUsuarios))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private:
		String^ obtenerCampo(String^ jsonItem, String^ campo) {
			System::Text::RegularExpressions::Match^ m =
				System::Text::RegularExpressions::Regex::Match(
					jsonItem, "\"" + campo + "\":\"?([^\"]+)\"?"
				);
			return m->Success ? m->Groups[1]->Value : "";
		}

	private: System::Void buttonAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridViewUsuarios->SelectedRows->Count > 0) {
			// Tomamos la primera fila seleccionada
			DataGridViewRow^ fila = dataGridViewUsuarios->SelectedRows[0];

			// Construimos los parámetros
			String^ dni = Convert::ToString(fila->Cells["dni"]->Value);
			String^ nombre = Convert::ToString(fila->Cells["nombre"]->Value);
			String^ apellido = Convert::ToString(fila->Cells["apellido"]->Value);
			String^ rol = Convert::ToString(fila->Cells["rol"]->Value);
			String^ edad = Convert::ToString(fila->Cells["edad"]->Value);
			String^ peso = Convert::ToString(fila->Cells["peso"]->Value);
			String^ altura = Convert::ToString(fila->Cells["altura"]->Value);
			String^ grupo_sanguineo = Convert::ToString(fila->Cells["grupo_sanguineo"]->Value);
			String^ direccion = Convert::ToString(fila->Cells["direccion"]->Value);
			String^ telefono = Convert::ToString(fila->Cells["telefono"]->Value);

			// Construimos la URL del API
			String^ url = "http://localhost/api/agregar_usuario.php?"
				+ "dni=" + dni
				+ "&nombre=" + nombre
				+ "&apellido=" + apellido
				+ "&rol=" + rol
				+ "&edad=" + edad
				+ "&peso=" + peso
				+ "&altura=" + altura
				+ "&grupo_sanguineo=" + grupo_sanguineo
				+ "&direccion=" + direccion
				+ "&telefono=" + telefono;

			try {
				HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
				request->Method = "GET"; // O POST si quieres

				HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
				StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
				String^ resultado = reader->ReadToEnd();
				MessageBox::Show(resultado, "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);

				response->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al agregar usuario: " + ex->Message);
			}
		}
		else {
			MessageBox::Show("Seleccione la fila con los datos del nuevo usuario.", "Atención");
		}
	}



	private: System::Void buttonListar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->buttonGuardar->Enabled = true;

		try {
			String^ url = "http://localhost/api/listar_usuarios.php";
			HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
			request->Method = "GET";

			HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
			StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
			String^ json = reader->ReadToEnd();
			response->Close();

			dataGridViewUsuarios->Rows->Clear();

			// Obtenemos todos los objetos JSON { ... }
			System::Text::RegularExpressions::Regex^ rx = gcnew System::Text::RegularExpressions::Regex("\\{[^\\}]+\\}");
			System::Text::RegularExpressions::MatchCollection^ matches = rx->Matches(json);

			for each (System::Text::RegularExpressions::Match ^ match in matches) {
				String^ item = match->Value;

				dataGridViewUsuarios->Rows->Add(
					obtenerCampo(item, "id"),
					obtenerCampo(item, "dni"),
					obtenerCampo(item, "nombre"),
					obtenerCampo(item, "apellido"),
					obtenerCampo(item, "rol"),
					obtenerCampo(item, "edad"),
					obtenerCampo(item, "peso"),
					obtenerCampo(item, "altura"),
					obtenerCampo(item, "grupo_sanguineo"),
					obtenerCampo(item, "direccion"),
					obtenerCampo(item, "telefono")
				);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al listar usuarios: " + ex->Message);
		}
	}









	private: System::Void buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar que haya una fila seleccionada
		if (dataGridViewUsuarios->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una fila para modificar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		DataGridViewRow^ fila = dataGridViewUsuarios->SelectedRows[0];

		// Obtener valores de la fila (validando nulls)
		String^ id = (fila->Cells["id"]->Value != nullptr) ? fila->Cells["id"]->Value->ToString() : "";
		String^ dni = (fila->Cells["dni"]->Value != nullptr) ? fila->Cells["dni"]->Value->ToString() : "";
		String^ nombre = (fila->Cells["nombre"]->Value != nullptr) ? fila->Cells["nombre"]->Value->ToString() : "";
		String^ apellido = (fila->Cells["apellido"]->Value != nullptr) ? fila->Cells["apellido"]->Value->ToString() : "";
		String^ rol = (fila->Cells["rol"]->Value != nullptr) ? fila->Cells["rol"]->Value->ToString() : "";
		String^ edad = (fila->Cells["edad"]->Value != nullptr) ? fila->Cells["edad"]->Value->ToString() : "";
		String^ peso = (fila->Cells["peso"]->Value != nullptr) ? fila->Cells["peso"]->Value->ToString() : "";
		String^ altura = (fila->Cells["altura"]->Value != nullptr) ? fila->Cells["altura"]->Value->ToString() : "";
		String^ grupo_sanguineo = (fila->Cells["grupo_sanguineo"]->Value != nullptr) ? fila->Cells["grupo_sanguineo"]->Value->ToString() : "";
		String^ direccion = (fila->Cells["direccion"]->Value != nullptr) ? fila->Cells["direccion"]->Value->ToString() : "";
		String^ telefono = (fila->Cells["telefono"]->Value != nullptr) ? fila->Cells["telefono"]->Value->ToString() : "";

		try {
			// Construir URL para PHP (usar escape para valores con espacios)
			String^ url = "http://localhost/api/modificar_usuario.php?"
				+ "id=" + Uri::EscapeDataString(id)
				+ "&dni=" + Uri::EscapeDataString(dni)
				+ "&nombre=" + Uri::EscapeDataString(nombre)
				+ "&apellido=" + Uri::EscapeDataString(apellido)
				+ "&rol=" + Uri::EscapeDataString(rol)
				+ "&edad=" + Uri::EscapeDataString(edad)
				+ "&peso=" + Uri::EscapeDataString(peso)
				+ "&altura=" + Uri::EscapeDataString(altura)
				+ "&grupo_sanguineo=" + Uri::EscapeDataString(grupo_sanguineo)
				+ "&direccion=" + Uri::EscapeDataString(direccion)
				+ "&telefono=" + Uri::EscapeDataString(telefono);

			System::Net::WebClient^ client = gcnew System::Net::WebClient();
			String^ response = client->DownloadString(url);

			if (response->Contains("success")) {
				MessageBox::Show("Usuario modificado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Error al modificar usuario: " + response, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error de conexión: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->buttonGuardar->Enabled = false;
	}




	private: System::Void buttonEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->buttonGuardar->Enabled = false;
		if (dataGridViewUsuarios->SelectedRows->Count > 0) {
			int id = Convert::ToInt32(dataGridViewUsuarios->SelectedRows[0]->Cells["id"]->Value);

			// Llamada al PHP
			String^ url = "http://localhost/api/eliminar_usuario.php?id=" + id;

			try {
				System::Net::WebClient^ client = gcnew System::Net::WebClient();
				String^ response = client->DownloadString(url);

				if (response->Contains("ok")) {
					MessageBox::Show("Usuario eliminado correctamente.");
					dataGridViewUsuarios->Rows->RemoveAt(dataGridViewUsuarios->SelectedRows[0]->Index);
				}
				else {
					MessageBox::Show("Error al eliminar: " + response);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error de conexión: " + ex->Message);
			}
		}
		else {
			MessageBox::Show("Seleccione un usuario para eliminar.");
		}
	}



/*
	private: System::Void buttonBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->buttonGuardar->Enabled = true;

		if (dataGridViewUsuarios->SelectedCells->Count == 0) {
			MessageBox::Show("Seleccione una celda del apellido en la tabla.", "Error");
			return;
		}

		int rowIndex = dataGridViewUsuarios->SelectedCells[0]->RowIndex;
		DataGridViewRow^ fila = dataGridViewUsuarios->Rows[rowIndex];
		String^ apellido = fila->Cells["apellido"]->Value->ToString()->Trim();

		if (String::IsNullOrEmpty(apellido)) {
			MessageBox::Show("El apellido seleccionado está vacío.", "Error");
			return;
		}

		try {
			String^ url = "http://localhost/api/buscar_usuario.php?apellido=" + System::Uri::EscapeDataString(apellido);
			System::Net::WebClient^ client = gcnew System::Net::WebClient();
			String^ result = client->DownloadString(url);

			dataGridViewUsuarios->Rows->Clear();

			array<String^>^ filas = result->Split(';');
			for each (String ^ filaStr in filas) {
				if (String::IsNullOrWhiteSpace(filaStr)) continue;
				array<String^>^ columnas = filaStr->Split('|');
				dataGridViewUsuarios->Rows->Add(columnas);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al buscar usuarios: " + ex->Message);
		}
	}
*/

		   private: System::Void buttonBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
			   this->buttonGuardar->Enabled = true;

			   // Verificar que haya una celda activa
			   if (dataGridViewUsuarios->CurrentCell == nullptr) {
				   MessageBox::Show("No hay ninguna celda activa.", "Error");
				   return;
			   }

			   // Tomar la fila de la celda activa
			   int rowIndex = dataGridViewUsuarios->CurrentCell->RowIndex;
			   DataGridViewRow^ fila = dataGridViewUsuarios->Rows[rowIndex];

			   // Validar que la celda activa sea la columna 'apellido'
			   if (dataGridViewUsuarios->CurrentCell->OwningColumn->Name != "apellido") {
				   MessageBox::Show("Debe escribir en la columna 'apellido'.", "Error");
				   return;
			   }

			   // Obtener el valor escrito
			   String^ apellido = fila->Cells["apellido"]->Value != nullptr
				   ? fila->Cells["apellido"]->Value->ToString()->Trim()
				   : "";

			   if (String::IsNullOrEmpty(apellido)) {
				   MessageBox::Show("El apellido está vacío.", "Error");
				   return;
			   }

			   try {
				   String^ url = "http://localhost/api/buscar_usuario.php?apellido=" + System::Uri::EscapeDataString(apellido);
				   System::Net::WebClient^ client = gcnew System::Net::WebClient();
				   String^ result = client->DownloadString(url);

				   dataGridViewUsuarios->Rows->Clear();

				   array<String^>^ filas = result->Split(';');
				   for each (String ^ filaStr in filas) {
					   if (String::IsNullOrWhiteSpace(filaStr)) continue;
					   array<String^>^ columnas = filaStr->Split('|');
					   dataGridViewUsuarios->Rows->Add(columnas);
				   }
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error al buscar usuarios: " + ex->Message);
			   }
		   }



	private: System::Void buttonLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->buttonGuardar->Enabled = false;
		dataGridViewUsuarios->Rows->Clear();
	}
	private: System::Void buttonCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		//this->Close();
		//Application::Exit();
	}
	};
}
