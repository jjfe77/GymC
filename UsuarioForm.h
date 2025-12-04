#pragma once

#include "ProgresoForm.h"
#include "GaleriaForm.h"


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
	using namespace System::Text;                    // Para Encoding


	/// <summary>
	/// Resumen de UsuarioForm
	/// </summary>
	public ref class UsuarioForm : public System::Windows::Forms::Form
	{
	public:
		UsuarioForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~UsuarioForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelDniAlumno;
	private: System::Windows::Forms::TextBox^ textBoxDNI;
	protected:

	private: System::Windows::Forms::Button^ buttonBuscar;
	private: System::Windows::Forms::ComboBox^ comboRutinas;
	private: System::Windows::Forms::DataGridView^ dataGridViewEjercicios;



	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_rutina_ejercicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ejercicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ series;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ repeticiones;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ carga;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ series_real;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ repeticiones_real;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ carga_real;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ labelAlumno;
	private: System::Windows::Forms::Button^ buttonGuardar;
	private: System::Windows::Forms::Button^ buttonVerProgreso;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonGaleria;




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
			this->labelDniAlumno = (gcnew System::Windows::Forms::Label());
			this->textBoxDNI = (gcnew System::Windows::Forms::TextBox());
			this->buttonBuscar = (gcnew System::Windows::Forms::Button());
			this->comboRutinas = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridViewEjercicios = (gcnew System::Windows::Forms::DataGridView());
			this->id_rutina_ejercicio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ejercicio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->series = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->repeticiones = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->carga = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->series_real = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->repeticiones_real = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->carga_real = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelAlumno = (gcnew System::Windows::Forms::Label());
			this->buttonGuardar = (gcnew System::Windows::Forms::Button());
			this->buttonVerProgreso = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonGaleria = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewEjercicios))->BeginInit();
			this->SuspendLayout();
			// 
			// labelDniAlumno
			// 
			this->labelDniAlumno->AutoSize = true;
			this->labelDniAlumno->Location = System::Drawing::Point(63, 79);
			this->labelDniAlumno->Name = L"labelDniAlumno";
			this->labelDniAlumno->Size = System::Drawing::Size(30, 16);
			this->labelDniAlumno->TabIndex = 0;
			this->labelDniAlumno->Text = L"DNI";
			// 
			// textBoxDNI
			// 
			this->textBoxDNI->Location = System::Drawing::Point(117, 76);
			this->textBoxDNI->Name = L"textBoxDNI";
			this->textBoxDNI->Size = System::Drawing::Size(280, 22);
			this->textBoxDNI->TabIndex = 1;
			// 
			// buttonBuscar
			// 
			this->buttonBuscar->Location = System::Drawing::Point(430, 71);
			this->buttonBuscar->Name = L"buttonBuscar";
			this->buttonBuscar->Size = System::Drawing::Size(161, 58);
			this->buttonBuscar->TabIndex = 2;
			this->buttonBuscar->Text = L"Buscar";
			this->buttonBuscar->UseVisualStyleBackColor = true;
			this->buttonBuscar->Click += gcnew System::EventHandler(this, &UsuarioForm::buttonBuscar_Click);
			// 
			// comboRutinas
			// 
			this->comboRutinas->FormattingEnabled = true;
			this->comboRutinas->Location = System::Drawing::Point(117, 151);
			this->comboRutinas->Name = L"comboRutinas";
			this->comboRutinas->Size = System::Drawing::Size(270, 24);
			this->comboRutinas->TabIndex = 3;
			this->comboRutinas->SelectedIndexChanged += gcnew System::EventHandler(this, &UsuarioForm::comboRutinas_SelectedIndexChanged);
			// 
			// dataGridViewEjercicios
			// 
			this->dataGridViewEjercicios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewEjercicios->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->id_rutina_ejercicio,
					this->ejercicio, this->series, this->repeticiones, this->carga, this->series_real, this->repeticiones_real, this->carga_real
			});
			this->dataGridViewEjercicios->Location = System::Drawing::Point(41, 199);
			this->dataGridViewEjercicios->Name = L"dataGridViewEjercicios";
			this->dataGridViewEjercicios->RowHeadersWidth = 51;
			this->dataGridViewEjercicios->RowTemplate->Height = 24;
			this->dataGridViewEjercicios->Size = System::Drawing::Size(1257, 201);
			this->dataGridViewEjercicios->TabIndex = 4;
			// 
			// id_rutina_ejercicio
			// 
			this->id_rutina_ejercicio->HeaderText = L"id_rutina_ejercicio";
			this->id_rutina_ejercicio->MinimumWidth = 6;
			this->id_rutina_ejercicio->Name = L"id_rutina_ejercicio";
			this->id_rutina_ejercicio->Visible = false;
			this->id_rutina_ejercicio->Width = 125;
			// 
			// ejercicio
			// 
			this->ejercicio->HeaderText = L"Ejercicio";
			this->ejercicio->MinimumWidth = 6;
			this->ejercicio->Name = L"ejercicio";
			this->ejercicio->ReadOnly = true;
			this->ejercicio->Width = 125;
			// 
			// series
			// 
			this->series->HeaderText = L"Series";
			this->series->MinimumWidth = 6;
			this->series->Name = L"series";
			this->series->ReadOnly = true;
			this->series->Width = 125;
			// 
			// repeticiones
			// 
			this->repeticiones->HeaderText = L"Repeticiones";
			this->repeticiones->MinimumWidth = 6;
			this->repeticiones->Name = L"repeticiones";
			this->repeticiones->ReadOnly = true;
			this->repeticiones->Width = 125;
			// 
			// carga
			// 
			this->carga->HeaderText = L"Carga";
			this->carga->MinimumWidth = 6;
			this->carga->Name = L"carga";
			this->carga->ReadOnly = true;
			this->carga->Width = 125;
			// 
			// series_real
			// 
			this->series_real->HeaderText = L"Series Realizadas";
			this->series_real->MinimumWidth = 6;
			this->series_real->Name = L"series_real";
			this->series_real->Width = 125;
			// 
			// repeticiones_real
			// 
			this->repeticiones_real->HeaderText = L"Repeticiones Realizadas";
			this->repeticiones_real->MinimumWidth = 6;
			this->repeticiones_real->Name = L"repeticiones_real";
			this->repeticiones_real->Width = 125;
			// 
			// carga_real
			// 
			this->carga_real->HeaderText = L"Carga utilizada";
			this->carga_real->MinimumWidth = 6;
			this->carga_real->Name = L"carga_real";
			this->carga_real->Width = 125;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(644, 71);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker1->TabIndex = 5;
			// 
			// labelAlumno
			// 
			this->labelAlumno->AutoSize = true;
			this->labelAlumno->Location = System::Drawing::Point(125, 113);
			this->labelAlumno->Name = L"labelAlumno";
			this->labelAlumno->Size = System::Drawing::Size(52, 16);
			this->labelAlumno->TabIndex = 6;
			this->labelAlumno->Text = L"Alumno";
			// 
			// buttonGuardar
			// 
			this->buttonGuardar->Location = System::Drawing::Point(66, 433);
			this->buttonGuardar->Name = L"buttonGuardar";
			this->buttonGuardar->Size = System::Drawing::Size(161, 58);
			this->buttonGuardar->TabIndex = 7;
			this->buttonGuardar->Text = L"Guardar";
			this->buttonGuardar->UseVisualStyleBackColor = true;
			this->buttonGuardar->Click += gcnew System::EventHandler(this, &UsuarioForm::buttonGuardar_Click);
			// 
			// buttonVerProgreso
			// 
			this->buttonVerProgreso->Location = System::Drawing::Point(302, 433);
			this->buttonVerProgreso->Name = L"buttonVerProgreso";
			this->buttonVerProgreso->Size = System::Drawing::Size(161, 58);
			this->buttonVerProgreso->TabIndex = 8;
			this->buttonVerProgreso->Text = L"Ver Progreso";
			this->buttonVerProgreso->UseVisualStyleBackColor = true;
			this->buttonVerProgreso->Click += gcnew System::EventHandler(this, &UsuarioForm::buttonVerProgreso_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(898, 454);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(250, 53);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Tu usuario";
			// 
			// buttonGaleria
			// 
			this->buttonGaleria->Location = System::Drawing::Point(533, 433);
			this->buttonGaleria->Name = L"buttonGaleria";
			this->buttonGaleria->Size = System::Drawing::Size(161, 58);
			this->buttonGaleria->TabIndex = 12;
			this->buttonGaleria->Text = L"Galeria";
			this->buttonGaleria->UseVisualStyleBackColor = true;
			this->buttonGaleria->Click += gcnew System::EventHandler(this, &UsuarioForm::buttonGaleria_Click);
			// 
			// UsuarioForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1356, 552);
			this->Controls->Add(this->buttonGaleria);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonVerProgreso);
			this->Controls->Add(this->buttonGuardar);
			this->Controls->Add(this->labelAlumno);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->dataGridViewEjercicios);
			this->Controls->Add(this->comboRutinas);
			this->Controls->Add(this->buttonBuscar);
			this->Controls->Add(this->textBoxDNI);
			this->Controls->Add(this->labelDniAlumno);
			this->Name = L"UsuarioForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UsuarioForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewEjercicios))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Declarar variable en tu clase del formulario
		int idAlumnoActual;

	private: System::Void comboRutinas_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboRutinas->SelectedValue == nullptr) return;

		// Ahora sí, SelectedValue es el id_rutina (int)
		int idRutina = Convert::ToInt32(comboRutinas->SelectedValue);

		cargarEjerciciosDeRutina(idRutina);
	}
		   //---------------------------------------
	private: System::Void buttonBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ dni = textBoxDNI->Text;
		if (String::IsNullOrEmpty(dni)) {
			MessageBox::Show("Ingrese su DNI");
			return;
		}

		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/api/buscar_usuario_usuario.php?dni=" + dni);

		// Parsear campos del JSON
		String^ idStr = obtenerCampo(json, "id");
		if (String::IsNullOrEmpty(idStr)) {
			// Alumno no encontrado → limpiar controles
			MessageBox::Show("No se encontró el alumno con ese DNI");
			labelAlumno->Text = "";
			comboRutinas->DataSource = nullptr;
			comboRutinas->Items->Clear();
			dataGridViewEjercicios->DataSource = nullptr; // opcional, si tenés un grid
			return;
		}

		idAlumnoActual = Int32::Parse(idStr);
		String^ nombreAlumno = obtenerCampo(json, "nombre");
		String^ apellidoAlumno = obtenerCampo(json, "apellido");

		// Mostrar mensaje con nombre completo
		MessageBox::Show("Alumno encontrado: " + nombreAlumno + " " + apellidoAlumno +
			" (ID=" + idAlumnoActual + ")");

		// Guardar en el Label
		labelAlumno->Text = nombreAlumno + " " + apellidoAlumno;

		// Ahora sí llamamos a cargarRutinasAlumno con la variable
		cargarRutinasAlumno(idAlumnoActual);

	}


		   String^ obtenerCampo(String^ jsonItem, String^ campo) {
			   // Busca "campo":"valor" o "campo":valor en el string
			   String^ patron = "\\\"" + campo + "\\\":\\\"?([^,\\\"}]+)\\\"?";
			   Regex^ rx = gcnew Regex(patron);
			   Match^ match = rx->Match(jsonItem);

			   if (match->Success) {
				   return match->Groups[1]->Value;
			   }
			   return "";
		   }

		   void cargarRutinasAlumno(int idAlumno) {
			   WebClient^ client = gcnew WebClient();
			   client->Encoding = System::Text::Encoding::UTF8;
			   String^ json = client->DownloadString("http://localhost/api/listar_rutinas_usuario.php?id=" + idAlumno);

			   DataTable^ dtRutinas = gcnew DataTable();
			   dtRutinas->Columns->Add("id_rutina", int::typeid);
			   dtRutinas->Columns->Add("nombre", String::typeid);

			   Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
			   auto matches = rx->Matches(json);

			   if (matches->Count == 0) {
				   // No hay rutinas → limpiar ComboBox
				   comboRutinas->DataSource = nullptr;
				   comboRutinas->Items->Clear();
				   MessageBox::Show("Este alumno no tiene rutinas asignadas.");
				   return;
			   }


			   for each (Match ^ m in matches) {
				   String^ item = m->Value;
				   int id_rutina = Int32::Parse(obtenerCampo(item, "id_rutina"));
				   String^ nombre = obtenerCampo(item, "nombre");
				   dtRutinas->Rows->Add(id_rutina, nombre);
			   }


			   //comboRutinas->DisplayMember = "nombre";
			   comboRutinas->DisplayMember = "nombre";
			   comboRutinas->ValueMember = "id_rutina";
			   comboRutinas->DataSource = dtRutinas;

		   }

		   //-------------------------------------------------------------------------------------------------
	private: System::Void buttonGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridViewEjercicios->Rows->Count == 0) return;

		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;

		String^ fechaSeleccionada = dateTimePicker1->Value.ToString("yyyy-MM-dd");

		for each (DataGridViewRow ^ row in dataGridViewEjercicios->Rows) {
			if (row->IsNewRow) continue;

			int idRutinaEjercicio = Convert::ToInt32(row->Cells["id_rutina_ejercicio"]->Value);
			int seriesReal = Convert::ToInt32(row->Cells["series_real"]->Value);
			int repesReal = Convert::ToInt32(row->Cells["repeticiones_real"]->Value);
			int cargaReal = Convert::ToInt32(row->Cells["carga_real"]->Value);

			NameValueCollection^ datos = gcnew NameValueCollection();
			datos->Add("id_alumno", idAlumnoActual.ToString());
			datos->Add("id_rutina", comboRutinas->SelectedValue->ToString());
			datos->Add("id_rutina_ejercicio", idRutinaEjercicio.ToString());
			datos->Add("series_real", seriesReal.ToString());
			datos->Add("repeticiones_real", repesReal.ToString());
			datos->Add("carga_real", cargaReal.ToString());
			datos->Add("fecha", fechaSeleccionada);

			array<Byte>^ response = client->UploadValues("http://localhost/api/guardar_ejercicios.php", "POST", datos);
			String^ respStr = System::Text::Encoding::UTF8->GetString(response);
			// Podés mostrar respStr si querés depurar
		}

		MessageBox::Show("Ejercicios guardados correctamente");
	}

		   //----------------------------

		   void cargarEjerciciosDeRutina(int idRutina) {
			   dataGridViewEjercicios->Rows->Clear();

			   WebClient^ client = gcnew WebClient();
			   client->Encoding = System::Text::Encoding::UTF8;

			   String^ url = "http://localhost/api/listar_rutina_ejercicios.php?id_rutina=" + idRutina;
			   String^ json = client->DownloadString(url);

			   Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
			   auto matches = rx->Matches(json);

			   for each (Match ^ m in matches) {
				   String^ item = m->Value;

				   int idRe = Convert::ToInt32(obtenerCampo(item, "id_rutina_ejercicio"));
				   String^ ejercicio = obtenerCampo(item, "ejercicio");
				   int series = Convert::ToInt32(obtenerCampo(item, "series"));
				   int repes = Convert::ToInt32(obtenerCampo(item, "repeticiones"));
				   double carga = Convert::ToDouble(obtenerCampo(item, "carga"));

				   int idx = dataGridViewEjercicios->Rows->Add();
				   auto row = dataGridViewEjercicios->Rows[idx];

				   row->Cells["id_rutina_ejercicio"]->Value = idRe;
				   row->Cells["ejercicio"]->Value = ejercicio;
				   row->Cells["series"]->Value = series;
				   row->Cells["repeticiones"]->Value = repes;
				   row->Cells["carga"]->Value = carga;

				   // Inicializar columnas reales vacías
				   row->Cells["series_real"]->Value = "";
				   row->Cells["repeticiones_real"]->Value = "";
				   row->Cells["carga_real"]->Value = "";
			   }
		   }


		   //-----------------------------
	private: System::Void buttonVerProgreso_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idAlumnoActual <= 0) {
			MessageBox::Show("Seleccione un alumno primero");
			return;
		}
		MessageBox::Show("" + idAlumnoActual);
		// Desactivar botones mientras se abre el ProgresoForm
		buttonGuardar->Enabled = false;
		buttonVerProgreso->Enabled = false;


		ProgresoForm^ frm = gcnew ProgresoForm(idAlumnoActual);
		frm->ShowDialog(); // abre como ventana modal

		// Cuando se cierra el ProgresoForm, reactivar botones
		buttonGuardar->Enabled = true;
		buttonVerProgreso->Enabled = true;


	}
	private: System::Void buttonGaleria_Click(System::Object^ sender, System::EventArgs^ e) {

		buttonGuardar->Enabled = false;
		buttonVerProgreso->Enabled = false;
		buttonGaleria->Enabled = false;


		GaleriaForm^ galForm = gcnew GaleriaForm();
		galForm->ShowDialog(); // abre como ventana modal

		// Cuando se cierra el ProgresoForm, reactivar botones
		buttonGuardar->Enabled = true;
		buttonVerProgreso->Enabled = true;
		buttonGaleria->Enabled = true;
	}
};
}
