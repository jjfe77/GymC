#pragma once

namespace Gym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;        // Para HttpWebRequest, HttpWebResponse, WebClient
	using namespace System::IO;         // Para StreamReader
	using namespace System::Text::RegularExpressions; // Para Regex
	using namespace System::Collections::Specialized;



	/// <summary>
	/// Resumen de RutinasForm
	/// </summary>
	public ref class RutinasForm : public System::Windows::Forms::Form
	{
	public:
		RutinasForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			// DataGridView Rutinas
			// 👉 Configurar columna alumno como ComboBox

			/**/
			DataGridViewComboBoxColumn^ colAlumno = gcnew DataGridViewComboBoxColumn();
			colAlumno->Name = "alumno";
			colAlumno->HeaderText = "Alumno";

			// Crear DataTable con columnas id y nombre
			DataTable^ dtAlumnos = gcnew DataTable();
			dtAlumnos->Columns->Add("id", int::typeid);
			dtAlumnos->Columns->Add("nombre", String::typeid);

			// Ejemplo de carga manual (luego lo llenás desde listar_alumnos.php)
			//dtAlumnos->Rows->Add(1, "Juan Pérez");
			//dtAlumnos->Rows->Add(2, "María López");

			// Configurar qué se muestra y qué se guarda
			colAlumno->DataSource = dtAlumnos;
			colAlumno->DisplayMember = "nombre";   // 👀 lo que se ve en la grilla
			colAlumno->ValueMember = "id";         // 👀 lo que se guarda en la celda

			// Agregar columna al DataGridView
			//this->dataGridViewRutinas->Columns->Add(colAlumno);



			this->Load += gcnew System::EventHandler(this, &RutinasForm::RutinasForm_Load);
			this->nombre->Width = 150;
			//this->alumno->Width = 150l;

			this->dataGridViewRutinas->Columns["alumno"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

			this->dataGridViewRutinas->CurrentCellDirtyStateChanged +=
				gcnew System::EventHandler(this, &RutinasForm::dataGridViewRutinas_CurrentCellDirtyStateChanged);
			this->dataGridViewRutinas->CellValueChanged +=
				gcnew DataGridViewCellEventHandler(this, &RutinasForm::dataGridViewRutinas_CellValueChanged);


			this->dataGridViewEjerciciosRutina->CurrentCellDirtyStateChanged += gcnew EventHandler(this, &RutinasForm::dataGridViewEjerciciosRutina_CurrentCellDirtyStateChanged);
			this->dataGridViewEjerciciosRutina->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &RutinasForm::dataGridViewEjerciciosRutina_CellValueChanged);

			// Ajustar ancho de columnas del DataGridView
			this->dataGridViewEjerciciosRutina->Columns["Ejercicio"]->Width = 200;
			this->dataGridViewEjerciciosRutina->Columns["Series"]->Width = 60;
			this->dataGridViewEjerciciosRutina->Columns["Repeticiones"]->Width = 80;
			//this->dataGridViewEjerciciosRutina->Columns["Carga"]->Width = 80;

			// Opcional: que la última columna se expanda para ocupar el espacio sobrante
			this->dataGridViewEjerciciosRutina->Columns["Carga"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~RutinasForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridViewRutinas;
	private: System::Windows::Forms::DataGridView^ dataGridViewEjerciciosRutina;




	private: System::Windows::Forms::Button^ buttonCrearRutinas;
	private: System::Windows::Forms::Button^ buttonListarRutinas;
	private: System::Windows::Forms::Button^ buttonEditarRutina;






	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_rutina;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ alumno;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_alumno;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_rutina_ejercicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_ejercicio;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ ejercicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ series;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ repeticiones;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ carga;
	private: System::Windows::Forms::Button^ buttonVerRutina;
	private: System::Windows::Forms::Button^ buttonLimpiar;
	private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Button^ buttonLimpiarRutAlu;
private: System::Windows::Forms::Button^ buttonEliminarEjercicio;
















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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewRutinas = (gcnew System::Windows::Forms::DataGridView());
			this->id_rutina = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->alumno = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->id_alumno = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewEjerciciosRutina = (gcnew System::Windows::Forms::DataGridView());
			this->id_rutina_ejercicio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id_ejercicio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ejercicio = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->series = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->repeticiones = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->carga = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonCrearRutinas = (gcnew System::Windows::Forms::Button());
			this->buttonListarRutinas = (gcnew System::Windows::Forms::Button());
			this->buttonEditarRutina = (gcnew System::Windows::Forms::Button());
			this->buttonVerRutina = (gcnew System::Windows::Forms::Button());
			this->buttonLimpiar = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonLimpiarRutAlu = (gcnew System::Windows::Forms::Button());
			this->buttonEliminarEjercicio = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRutinas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewEjerciciosRutina))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(280, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(588, 53);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Administracion de Rutinas";
			// 
			// dataGridViewRutinas
			// 
			this->dataGridViewRutinas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewRutinas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->id_rutina,
					this->nombre, this->alumno, this->id_alumno
			});
			this->dataGridViewRutinas->Location = System::Drawing::Point(76, 92);
			this->dataGridViewRutinas->Name = L"dataGridViewRutinas";
			this->dataGridViewRutinas->RowHeadersWidth = 51;
			this->dataGridViewRutinas->RowTemplate->Height = 24;
			this->dataGridViewRutinas->Size = System::Drawing::Size(520, 150);
			this->dataGridViewRutinas->TabIndex = 11;
			this->dataGridViewRutinas->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &RutinasForm::dataGridViewRutinas_CellValueChanged);
			// 
			// id_rutina
			// 
			this->id_rutina->HeaderText = L"ID Rutina";
			this->id_rutina->MinimumWidth = 6;
			this->id_rutina->Name = L"id_rutina";
			this->id_rutina->Visible = false;
			this->id_rutina->Width = 125;
			// 
			// nombre
			// 
			this->nombre->HeaderText = L"Nombre Rutina";
			this->nombre->MinimumWidth = 6;
			this->nombre->Name = L"nombre";
			this->nombre->Width = 125;
			// 
			// alumno
			// 
			this->alumno->HeaderText = L"Alumno";
			this->alumno->MinimumWidth = 6;
			this->alumno->Name = L"alumno";
			this->alumno->Width = 125;
			// 
			// id_alumno
			// 
			this->id_alumno->HeaderText = L"id_alumno";
			this->id_alumno->MinimumWidth = 6;
			this->id_alumno->Name = L"id_alumno";
			this->id_alumno->Visible = false;
			this->id_alumno->Width = 125;
			// 
			// dataGridViewEjerciciosRutina
			// 
			this->dataGridViewEjerciciosRutina->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewEjerciciosRutina->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id_rutina_ejercicio,
					this->id_ejercicio, this->ejercicio, this->series, this->repeticiones, this->carga
			});
			this->dataGridViewEjerciciosRutina->Location = System::Drawing::Point(76, 371);
			this->dataGridViewEjerciciosRutina->Name = L"dataGridViewEjerciciosRutina";
			this->dataGridViewEjerciciosRutina->RowHeadersWidth = 51;
			this->dataGridViewEjerciciosRutina->RowTemplate->Height = 24;
			this->dataGridViewEjerciciosRutina->Size = System::Drawing::Size(807, 161);
			this->dataGridViewEjerciciosRutina->TabIndex = 12;
			// 
			// id_rutina_ejercicio
			// 
			this->id_rutina_ejercicio->HeaderText = L"id_rutina_ejercicio";
			this->id_rutina_ejercicio->MinimumWidth = 6;
			this->id_rutina_ejercicio->Name = L"id_rutina_ejercicio";
			this->id_rutina_ejercicio->Visible = false;
			this->id_rutina_ejercicio->Width = 125;
			// 
			// id_ejercicio
			// 
			this->id_ejercicio->HeaderText = L"id_ejercicio";
			this->id_ejercicio->MinimumWidth = 6;
			this->id_ejercicio->Name = L"id_ejercicio";
			this->id_ejercicio->Visible = false;
			this->id_ejercicio->Width = 125;
			// 
			// ejercicio
			// 
			this->ejercicio->HeaderText = L"Ejercicio";
			this->ejercicio->MinimumWidth = 6;
			this->ejercicio->Name = L"ejercicio";
			this->ejercicio->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->ejercicio->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->ejercicio->Width = 125;
			// 
			// series
			// 
			this->series->HeaderText = L"Series";
			this->series->MinimumWidth = 6;
			this->series->Name = L"series";
			this->series->Width = 125;
			// 
			// repeticiones
			// 
			this->repeticiones->HeaderText = L"Repeticiones";
			this->repeticiones->MinimumWidth = 6;
			this->repeticiones->Name = L"repeticiones";
			this->repeticiones->Width = 125;
			// 
			// carga
			// 
			this->carga->HeaderText = L"Carga Utilizada";
			this->carga->MinimumWidth = 6;
			this->carga->Name = L"carga";
			this->carga->Width = 125;
			// 
			// buttonCrearRutinas
			// 
			this->buttonCrearRutinas->Location = System::Drawing::Point(665, 92);
			this->buttonCrearRutinas->Name = L"buttonCrearRutinas";
			this->buttonCrearRutinas->Size = System::Drawing::Size(144, 72);
			this->buttonCrearRutinas->TabIndex = 13;
			this->buttonCrearRutinas->Text = L"Crear";
			this->buttonCrearRutinas->UseVisualStyleBackColor = true;
			this->buttonCrearRutinas->Click += gcnew System::EventHandler(this, &RutinasForm::buttonCrearRutinas_Click);
			// 
			// buttonListarRutinas
			// 
			this->buttonListarRutinas->Location = System::Drawing::Point(839, 92);
			this->buttonListarRutinas->Name = L"buttonListarRutinas";
			this->buttonListarRutinas->Size = System::Drawing::Size(144, 72);
			this->buttonListarRutinas->TabIndex = 14;
			this->buttonListarRutinas->Text = L"Listar";
			this->buttonListarRutinas->UseVisualStyleBackColor = true;
			this->buttonListarRutinas->Click += gcnew System::EventHandler(this, &RutinasForm::buttonListarRutinas_Click);
			// 
			// buttonEditarRutina
			// 
			this->buttonEditarRutina->Location = System::Drawing::Point(665, 170);
			this->buttonEditarRutina->Name = L"buttonEditarRutina";
			this->buttonEditarRutina->Size = System::Drawing::Size(144, 72);
			this->buttonEditarRutina->TabIndex = 15;
			this->buttonEditarRutina->Text = L"Guardar";
			this->buttonEditarRutina->UseVisualStyleBackColor = true;
			this->buttonEditarRutina->Click += gcnew System::EventHandler(this, &RutinasForm::buttonEditarRutina_Click);
			// 
			// buttonVerRutina
			// 
			this->buttonVerRutina->Location = System::Drawing::Point(839, 170);
			this->buttonVerRutina->Name = L"buttonVerRutina";
			this->buttonVerRutina->Size = System::Drawing::Size(144, 72);
			this->buttonVerRutina->TabIndex = 16;
			this->buttonVerRutina->Text = L"Ver Rutina";
			this->buttonVerRutina->UseVisualStyleBackColor = true;
			this->buttonVerRutina->Click += gcnew System::EventHandler(this, &RutinasForm::buttonVerRutina_Click);
			// 
			// buttonLimpiar
			// 
			this->buttonLimpiar->Location = System::Drawing::Point(957, 371);
			this->buttonLimpiar->Name = L"buttonLimpiar";
			this->buttonLimpiar->Size = System::Drawing::Size(144, 72);
			this->buttonLimpiar->TabIndex = 17;
			this->buttonLimpiar->Text = L"Limpiar";
			this->buttonLimpiar->UseVisualStyleBackColor = true;
			this->buttonLimpiar->Click += gcnew System::EventHandler(this, &RutinasForm::buttonLimpiar_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(76, 248);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(491, 117);
			this->textBox1->TabIndex = 18;
			this->textBox1->Text = L"Para crear una rutina:\r\n1- Coloque el nombre de la rutina\r\n2- Selecciones el alum"
				L"no\r\n3- Oprima CREAR\r\n4- Seleccione los ejercicios con sus series, repeticiones y"
				L" cargar\r\n5- Oprima GUARDAR";
			// 
			// buttonLimpiarRutAlu
			// 
			this->buttonLimpiarRutAlu->Location = System::Drawing::Point(1002, 92);
			this->buttonLimpiarRutAlu->Name = L"buttonLimpiarRutAlu";
			this->buttonLimpiarRutAlu->Size = System::Drawing::Size(144, 72);
			this->buttonLimpiarRutAlu->TabIndex = 19;
			this->buttonLimpiarRutAlu->Text = L"Limpiar";
			this->buttonLimpiarRutAlu->UseVisualStyleBackColor = true;
			this->buttonLimpiarRutAlu->Click += gcnew System::EventHandler(this, &RutinasForm::buttonLimpiarRutAlu_Click);
			// 
			// buttonEliminarEjercicio
			// 
			this->buttonEliminarEjercicio->Location = System::Drawing::Point(957, 460);
			this->buttonEliminarEjercicio->Name = L"buttonEliminarEjercicio";
			this->buttonEliminarEjercicio->Size = System::Drawing::Size(144, 72);
			this->buttonEliminarEjercicio->TabIndex = 20;
			this->buttonEliminarEjercicio->Text = L"Eliminar Ejercicio";
			this->buttonEliminarEjercicio->UseVisualStyleBackColor = true;
			this->buttonEliminarEjercicio->Click += gcnew System::EventHandler(this, &RutinasForm::buttonEliminarEjercicio_Click);
			// 
			// RutinasForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1156, 656);
			this->Controls->Add(this->buttonEliminarEjercicio);
			this->Controls->Add(this->buttonLimpiarRutAlu);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonLimpiar);
			this->Controls->Add(this->buttonVerRutina);
			this->Controls->Add(this->buttonEditarRutina);
			this->Controls->Add(this->buttonListarRutinas);
			this->Controls->Add(this->buttonCrearRutinas);
			this->Controls->Add(this->dataGridViewEjerciciosRutina);
			this->Controls->Add(this->dataGridViewRutinas);
			this->Controls->Add(this->label2);
			this->Name = L"RutinasForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RutinasForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRutinas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewEjerciciosRutina))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void RutinasForm_Load(System::Object^ sender, System::EventArgs^ e) {
		cargarAlumnos();
		cargarEjercicios();   // llena el ComboBox de ejercicios en el grid 2

	}


	private: void cargarAlumnos() {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/api/listar_alumnos.php");

		DataTable^ tablaAlumnos = gcnew DataTable();
		tablaAlumnos->Columns->Add("id", int::typeid);
		tablaAlumnos->Columns->Add("nombre", String::typeid);

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each (Match ^ m in matches) {
			String^ item = m->Value;

			// Obtención robusta del id
			String^ idStr = obtenerCampo(item, "id");
			int id;
			if (!Int32::TryParse(idStr, id)) {
				// Si no se puede convertir, saltamos este registro
				continue;
			}

			DataRow^ r = tablaAlumnos->NewRow();
			r["id"] = id;
			r["nombre"] = obtenerCampo(item, "nombre");
			tablaAlumnos->Rows->Add(r);
		}

		// Configurar la columna ComboBox "alumno"
		auto colAlumno = safe_cast<DataGridViewComboBoxColumn^>(this->alumno);
		colAlumno->DataSource = tablaAlumnos;
		colAlumno->DisplayMember = "nombre"; // lo que se muestra
		colAlumno->ValueMember = "id";       // lo que se guarda

		// Opcional: estilo para ver el desplegable
		colAlumno->FlatStyle = FlatStyle::Popup;
	}


		   void cargarEjercicios() {
			   try {
				   WebClient^ client = gcnew WebClient();
				   client->Encoding = System::Text::Encoding::UTF8;
				   String^ json = client->DownloadString("http://localhost/api/listar_ejercicios.php");

				   // Crear DataTable con columnas id_ejercicio y nombre
				   DataTable^ dtEjercicios = gcnew DataTable();
				   dtEjercicios->Columns->Add("id_ejercicio", int::typeid);
				   dtEjercicios->Columns->Add("nombre", String::typeid);

				   // Parsear JSON con tu función obtenerCampo
				   Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
				   auto matches = rx->Matches(json);

				   for each (Match ^ m in matches) {
					   String^ item = m->Value;
					   int id_ejercicio = Int32::Parse(obtenerCampo(item, "id_ejercicio"));
					   String^ nombre = obtenerCampo(item, "nombre");
					   dtEjercicios->Rows->Add(id_ejercicio, nombre);
				   }

				   // Asignar al ComboBoxColumn 'ejercicio'
				   this->ejercicio->DataSource = dtEjercicios;
				   this->ejercicio->DisplayMember = "nombre";       // lo que se ve
				   this->ejercicio->ValueMember = "id_ejercicio";   // lo que se guarda
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error al cargar ejercicios: " + ex->Message);
			   }
		   }

	private: String^ obtenerCampo(String^ jsonItem, String^ campo) {
		try {
			// Soporta "campo":"texto" y "campo":123
			String^ patron = "\\\"" + campo + "\\\":(?:\\\"([^\\\"]*)\\\"|(\\d+))";
			Regex^ rx = gcnew Regex(patron);
			Match^ match = rx->Match(jsonItem);

			if (match->Success) {
				if (match->Groups[1]->Success) return match->Groups[1]->Value; // texto
				if (match->Groups[2]->Success) return match->Groups[2]->Value; // número
			}
			return "";
		}
		catch (Exception^) {
			return "";
		}
	}

	private: System::Void dataGridViewRutinas_CurrentCellDirtyStateChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridViewRutinas->IsCurrentCellDirty) {
			this->dataGridViewRutinas->CommitEdit(DataGridViewDataErrorContexts::Commit);
		}
	}


	private: System::Void buttonCrearRutinas_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (this->dataGridViewRutinas->CurrentRow == nullptr) {
				MessageBox::Show("Seleccione una rutina en la grilla");
				return;
			}

			// Nombre de la rutina desde la celda "nombre"
			String^ nombreRutina = Convert::ToString(this->dataGridViewRutinas->CurrentRow->Cells["nombre"]->Value);
			if (String::IsNullOrEmpty(nombreRutina)) {
				MessageBox::Show("Ingrese un nombre en la columna 'nombre'");
				return;
			}

			// ID del alumno desde la columna "id"
			int idAlumno = Convert::ToInt32(this->dataGridViewRutinas->CurrentRow->Cells["alumno"]->Value);

			// Llamada al PHP crear_rutina.php
			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			auto datos = gcnew System::Collections::Specialized::NameValueCollection();
			datos->Add("nombre", nombreRutina);
			datos->Add("id", idAlumno.ToString());
			MessageBox::Show("Nombre: " + nombreRutina + " | ID: " + idAlumno.ToString());
			auto responseBytes = client->UploadValues("http://localhost/api/crear_rutina.php", "POST", datos);
			String^ responseJson = System::Text::Encoding::UTF8->GetString(responseBytes);

			// Obtener id_rutina de la respuesta
			Regex^ rx = gcnew Regex("\"id_rutina\":(\\d+)");
			Match^ match = rx->Match(responseJson);
			if (!match->Success) {
				MessageBox::Show("Error al crear rutina: " + responseJson);
				return;
			}
			int idRutina = Convert::ToInt32(match->Groups[1]->Value);

			// Guardar id_rutina en la columna oculta si la tenés
			if (this->dataGridViewRutinas->Columns->Contains("id_rutina")) {
				this->dataGridViewRutinas->CurrentRow->Cells["id_rutina"]->Value = idRutina;
			}

			MessageBox::Show("Rutina creada correctamente");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al crear rutina: " + ex->Message);
		}
	}



	private: System::Void dataGridViewRutinas_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0 || e->ColumnIndex < 0) return;

		auto grid = this->dataGridViewRutinas;
		String^ colName = grid->Columns[e->ColumnIndex]->Name;

		if (colName == "alumno") {
			DataGridViewRow^ row = grid->Rows[e->RowIndex];
			auto val = row->Cells["alumno"]->Value;
			if (val != nullptr && grid->Columns->Contains("id")) {
				row->Cells["id"]->Value = val;  // 👈 aquí se copia el ID
			}
		}
	}

	private: System::Void dataGridViewRutinas_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e) {
		e->ThrowException = false;
	}


	private: System::Void buttonListarRutinas_Click(System::Object^ sender, System::EventArgs^ e) {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/api/listar_rutinas.php");

		// Limpiar el DataGridView antes de cargar
		this->dataGridViewRutinas->Rows->Clear();

		// Buscar objetos JSON con Regex
		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each (Match ^ m in matches) {
			String^ item = m->Value;

			int id_rutina = Int32::Parse(obtenerCampo(item, "id_rutina"));
			String^ nombre = obtenerCampo(item, "nombre");
			int id_alumno = Int32::Parse(obtenerCampo(item, "id"));   // FK a usuarios

			// Agregar fila al DataGridView
			this->dataGridViewRutinas->Rows->Add(id_rutina, nombre, id_alumno);
		}
	}

		   // Se dispara cuando cambia el valor de una celda

	//-----------------------------------------------
		   private: System::Void dataGridViewEjerciciosRutina_CurrentCellDirtyStateChanged(System::Object^ sender, System::EventArgs^ e) {
			   if (this->dataGridViewEjerciciosRutina->IsCurrentCellDirty) {
				   this->dataGridViewEjerciciosRutina->CommitEdit(DataGridViewDataErrorContexts::Commit);
			   }
		   }

private: System::Void dataGridViewEjerciciosRutina_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
		auto grid = this->dataGridViewEjerciciosRutina;
		if (grid->Columns[e->ColumnIndex]->Name == "ejercicio") {
			auto row = grid->Rows[e->RowIndex];
			row->Cells["id_ejercicio"]->Value = row->Cells["ejercicio"]->Value;
		}
	}
}









	private: System::Void buttonEditarRutina_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (this->dataGridViewRutinas->CurrentRow == nullptr) {
				MessageBox::Show("Seleccione una rutina primero.");
				return;
			}

			int idRutina = Convert::ToInt32(this->dataGridViewRutinas->CurrentRow->Cells["id_rutina"]->Value);
			String^ nombre = this->dataGridViewRutinas->CurrentRow->Cells["nombre"]->Value->ToString();
			int idAlumno = Convert::ToInt32(this->dataGridViewRutinas->CurrentRow->Cells["alumno"]->Value);

			// Construir JSON de ejercicios
			System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
			sb->Append("[");
			for each (DataGridViewRow ^ row in this->dataGridViewEjerciciosRutina->Rows) {
				if (row->IsNewRow) continue;
				if (row->Cells["id_ejercicio"]->Value == nullptr) continue;

				int idEjercicio = Convert::ToInt32(row->Cells["id_ejercicio"]->Value);
				int series = Convert::ToInt32(row->Cells["series"]->Value);
				int repeticiones = Convert::ToInt32(row->Cells["repeticiones"]->Value);
				int carga = Convert::ToInt32(row->Cells["carga"]->Value);

				sb->Append("{\"id_ejercicio\":");
				sb->Append(idEjercicio);
				sb->Append(",\"series\":");
				sb->Append(series);
				sb->Append(",\"repeticiones\":");
				sb->Append(repeticiones);
				sb->Append(",\"carga\":");
				sb->Append(carga);
				sb->Append("},");
			}
			if (sb->Length > 1 && sb[sb->Length - 1] == ',') sb->Remove(sb->Length - 1, 1);
			sb->Append("]");

			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			NameValueCollection^ datos = gcnew NameValueCollection();
			datos->Add("id_rutina", idRutina.ToString());
			datos->Add("nombre", nombre);
			datos->Add("id_alumno", idAlumno.ToString());
			datos->Add("ejercicios", sb->ToString());

			String^ debugMsg = "id_rutina=" + idRutina.ToString() +
				"\nNombre=" + nombre +
				"\nId_alumno=" + idAlumno.ToString() +
				"\nEjercicios=" + sb->ToString();

			//MessageBox::Show(debugMsg, "Datos que se enviarán al PHP");
		



			//array<Byte>^ responseBytes = client->UploadValues("http://localhost/api/editar_rutina.php", "POST", datos);
			array<Byte>^ responseBytes = client->UploadValues("http://localhost/api/editar_rutina2.php", "POST", datos);
			String^ response = System::Text::Encoding::UTF8->GetString(responseBytes);

			MessageBox::Show("Respuesta del servidor: " + response);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al guardar rutina: " + ex->Message);
		}
	}







/*
private: System::Void buttonVerRutina_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Verificar que haya una rutina seleccionada
		if (this->dataGridViewRutinas->CurrentRow == nullptr) {
			MessageBox::Show("Seleccione una rutina primero.");
			return;
		}

		int idRutina = Convert::ToInt32(this->dataGridViewRutinas->CurrentRow->Cells["id_rutina"]->Value);

		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/api/listar_ejercicios_rutina.php?id_rutina=" + idRutina);

		// Limpiar las filas actuales
		this->dataGridViewEjerciciosRutina->Rows->Clear();

		// Extraer objetos con Regex (cada {…})
		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each (Match ^ m in matches) {
			String^ item = m->Value;

			int idEjercicio = 0, series = 0, repeticiones = 0, carga = 0;
			Int32::TryParse(obtenerCampo(item, "id_ejercicio"), idEjercicio);
			Int32::TryParse(obtenerCampo(item, "series"), series);
			Int32::TryParse(obtenerCampo(item, "repeticiones"), repeticiones);
			Int32::TryParse(obtenerCampo(item, "carga"), carga);

			String^ nombre = obtenerCampo(item, "nombre");

			// Agregar fila directamente al DataGridView
			int rowIndex = this->dataGridViewEjerciciosRutina->Rows->Add();
			DataGridViewRow^ row = this->dataGridViewEjerciciosRutina->Rows[rowIndex];

			// Asignar valores a las columnas existentes
			// id_rutina_ejercicio no lo devuelve tu PHP, lo dejamos vacío o lo completamos si lo agregás
			row->Cells["id_rutina_ejercicio"]->Value = nullptr;

			row->Cells["id_ejercicio"]->Value = idEjercicio;   // oculta
			row->Cells["ejercicio"]->Value = idEjercicio;      // ComboBox espera el ID
			row->Cells["series"]->Value = series;
			row->Cells["repeticiones"]->Value = repeticiones;
			row->Cells["carga"]->Value = carga;
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cargar ejercicios de la rutina: " + ex->Message);
	}
}
*/






	private: System::Void buttonVerRutina_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (this->dataGridViewRutinas->CurrentRow == nullptr) {
				MessageBox::Show("Seleccione una rutina primero.");
				return;
			}

			int idRutina = Convert::ToInt32(
				this->dataGridViewRutinas->CurrentRow->Cells["id_rutina"]->Value
			);

			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			String^ json = client->DownloadString(
				"http://localhost/api/listar_ejercicios_rutina.php?id_rutina=" + idRutina
			);

			// Limpiar DataGridView
			this->dataGridViewEjerciciosRutina->Rows->Clear();

			// ------------------------------
			// Extraer objeto JSON COMPLETO
			// ------------------------------
			// status:"ok", ejercicios:[ {...}, {...} ]
			MatchCollection^ matches = Regex::Matches(json, "\\{[^\\{\\}]+\\}");

			for each (Match ^ m in matches) {
				String^ item = m->Value;

				int idRE = 0, idEj = 0, series = 0, rep = 0, carga = 0;
				String^ nombre = obtenerCampo(item, "nombre");

				Int32::TryParse(obtenerCampo(item, "id_rutina_ejercicio"), idRE);
				Int32::TryParse(obtenerCampo(item, "id_ejercicio"), idEj);
				Int32::TryParse(obtenerCampo(item, "series"), series);
				Int32::TryParse(obtenerCampo(item, "repeticiones"), rep);
				Int32::TryParse(obtenerCampo(item, "carga"), carga);

				// Agregar fila
				int rowIndex = this->dataGridViewEjerciciosRutina->Rows->Add();
				DataGridViewRow^ row = this->dataGridViewEjerciciosRutina->Rows[rowIndex];

				// La tabla ahora DEBE tener estas columnas:
				// id_rutina_ejercicio (visible u oculta)
				// id_ejercicio (oculta)
				// ejercicio (ComboBox)
				// series, repeticiones, carga

				row->Cells["id_rutina_ejercicio"]->Value = idRE;
				row->Cells["id_ejercicio"]->Value = idEj;    // oculto
				row->Cells["ejercicio"]->Value = idEj;       // ComboBox usa idEj
				row->Cells["series"]->Value = series;
				row->Cells["repeticiones"]->Value = rep;
				row->Cells["carga"]->Value = carga;
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cargar ejercicios de la rutina: " + ex->Message);
		}
	}




















private: System::Void buttonLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
	//this->dataGridViewRutinas->Rows->Clear();
	this->dataGridViewEjerciciosRutina->Rows->Clear();
}

private: System::Void buttonLimpiarRutAlu_Click(System::Object^ sender, System::EventArgs^ e) {
	this->dataGridViewRutinas->Rows->Clear();
}




private: System::Void buttonEliminarEjercicio_Click(System::Object^ sender, System::EventArgs^ e) {

	try {
		if (this->dataGridViewEjerciciosRutina->CurrentRow == nullptr) {
			MessageBox::Show("Seleccione un ejercicio para eliminar.");
			return;
		}

		// Tomar id_rutina_ejercicio
		auto cellValue = this->dataGridViewEjerciciosRutina->CurrentRow->Cells["id_rutina_ejercicio"]->Value;

		if (cellValue == nullptr) {
			MessageBox::Show("Este ejercicio no tiene ID en la base de datos (no se puede eliminar).");
			return;
		}

		int idRutinaEj = Convert::ToInt32(cellValue);

		MessageBox::Show("ID seleccionado: " + idRutinaEj.ToString());

		// Confirmación
		if (MessageBox::Show("¿Eliminar ejercicio de la rutina?",
			"Confirmar", MessageBoxButtons::YesNo) != System::Windows::Forms::DialogResult::Yes)
		{
			return;
		}

		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		String^ url = "http://localhost/api/eliminar_ejercicio_rutina.php?id_rutina_ejercicio=" + idRutinaEj;
		String^ respuesta = client->DownloadString(url);

		// Quitar la fila del DataGridView
		this->dataGridViewEjerciciosRutina->Rows->Remove(
			this->dataGridViewEjerciciosRutina->CurrentRow
		);

		MessageBox::Show("Ejercicio eliminado correctamente.");
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error eliminando ejercicio: " + ex->Message);
	}
}

};
}
