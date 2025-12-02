#pragma once

namespace Gym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Resumen de EjerciciosForm
	/// </summary>
	public ref class EjerciciosForm : public System::Windows::Forms::Form
	{
	public:
		EjerciciosForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->Load += gcnew System::EventHandler(this, &EjerciciosForm::EjerciciosForm_Load);
			this->nombre->Width = 150;
			this->descripcion->Width = 250;
			this->grupo->Width = 150;
			this->equipo->Width = 150;
			// Permite que el texto se muestre en varias líneas
			this->dataGridView1->DefaultCellStyle->WrapMode = DataGridViewTriState::True;

			// Ajusta automáticamente la altura de las filas según el contenido
			this->dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~EjerciciosForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonListarEjercicios;
	private: System::Windows::Forms::Button^ buttonAgregarEjercicio;
	private: System::Windows::Forms::Button^ buttonEliminarEjercicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_ejercicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ descripcion;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ grupo;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ equipo;





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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonListarEjercicios = (gcnew System::Windows::Forms::Button());
			this->buttonAgregarEjercicio = (gcnew System::Windows::Forms::Button());
			this->buttonEliminarEjercicio = (gcnew System::Windows::Forms::Button());
			this->id_ejercicio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grupo = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->equipo = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id_ejercicio,
					this->nombre, this->descripcion, this->grupo, this->equipo
			});
			this->dataGridView1->Location = System::Drawing::Point(79, 133);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1025, 225);
			this->dataGridView1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(288, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(639, 53);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Administracion de Ejercicios";
			// 
			// buttonListarEjercicios
			// 
			this->buttonListarEjercicios->Location = System::Drawing::Point(79, 420);
			this->buttonListarEjercicios->Name = L"buttonListarEjercicios";
			this->buttonListarEjercicios->Size = System::Drawing::Size(144, 72);
			this->buttonListarEjercicios->TabIndex = 12;
			this->buttonListarEjercicios->Text = L"Listar";
			this->buttonListarEjercicios->UseVisualStyleBackColor = true;
			this->buttonListarEjercicios->Click += gcnew System::EventHandler(this, &EjerciciosForm::buttonListarEjercicios_Click);
			// 
			// buttonAgregarEjercicio
			// 
			this->buttonAgregarEjercicio->Location = System::Drawing::Point(338, 420);
			this->buttonAgregarEjercicio->Name = L"buttonAgregarEjercicio";
			this->buttonAgregarEjercicio->Size = System::Drawing::Size(144, 72);
			this->buttonAgregarEjercicio->TabIndex = 13;
			this->buttonAgregarEjercicio->Text = L"Agregar";
			this->buttonAgregarEjercicio->UseVisualStyleBackColor = true;
			this->buttonAgregarEjercicio->Click += gcnew System::EventHandler(this, &EjerciciosForm::buttonAgregarEjercicio_Click);
			// 
			// buttonEliminarEjercicio
			// 
			this->buttonEliminarEjercicio->Location = System::Drawing::Point(612, 420);
			this->buttonEliminarEjercicio->Name = L"buttonEliminarEjercicio";
			this->buttonEliminarEjercicio->Size = System::Drawing::Size(144, 72);
			this->buttonEliminarEjercicio->TabIndex = 14;
			this->buttonEliminarEjercicio->Text = L"Eliminar";
			this->buttonEliminarEjercicio->UseVisualStyleBackColor = true;
			this->buttonEliminarEjercicio->Click += gcnew System::EventHandler(this, &EjerciciosForm::buttonEliminarEjercicio_Click);
			// 
			// id_ejercicio
			// 
			this->id_ejercicio->HeaderText = L"id_ejercicio";
			this->id_ejercicio->MinimumWidth = 6;
			this->id_ejercicio->Name = L"id_ejercicio";
			this->id_ejercicio->Visible = false;
			this->id_ejercicio->Width = 125;
			// 
			// nombre
			// 
			this->nombre->HeaderText = L"Nombre Ejercicio";
			this->nombre->MinimumWidth = 6;
			this->nombre->Name = L"nombre";
			this->nombre->Width = 125;
			// 
			// descripcion
			// 
			this->descripcion->HeaderText = L"Descripcion Ejercicio";
			this->descripcion->MinimumWidth = 6;
			this->descripcion->Name = L"descripcion";
			this->descripcion->Width = 125;
			// 
			// grupo
			// 
			this->grupo->HeaderText = L"Grupo Muscular";
			this->grupo->MinimumWidth = 6;
			this->grupo->Name = L"grupo";
			this->grupo->Width = 125;
			// 
			// equipo
			// 
			this->equipo->HeaderText = L"Equipo Utilizado";
			this->equipo->MinimumWidth = 6;
			this->equipo->Name = L"equipo";
			this->equipo->Width = 125;
			// 
			// EjerciciosForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1175, 664);
			this->Controls->Add(this->buttonEliminarEjercicio);
			this->Controls->Add(this->buttonAgregarEjercicio);
			this->Controls->Add(this->buttonListarEjercicios);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"EjerciciosForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EjerciciosForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EjerciciosForm_Load(System::Object^ sender, System::EventArgs^ e) {
		cargarGrupos();
		cargarEquipos();
	}


	private: void cargarGrupos() {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/api/listar_grupos_ejercicios.php");

		DataTable^ tablaGrupos = gcnew DataTable();
		tablaGrupos->Columns->Add("id_grupo", int::typeid);
		tablaGrupos->Columns->Add("nombre", String::typeid);

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each(Match ^ m in matches) {
			String^ item = m->Value;
			DataRow^ r = tablaGrupos->NewRow();
			r["id_grupo"] = Int32::Parse(obtenerCampo(item, "id_grupo"));
			r["nombre"] = obtenerCampo(item, "nombre");
			tablaGrupos->Rows->Add(r);
		}

		auto colGrupo = safe_cast<DataGridViewComboBoxColumn^>(this->grupo);
		colGrupo->DataSource = tablaGrupos;
		colGrupo->DisplayMember = "nombre";
		colGrupo->ValueMember = "id_grupo";
	}

	private: void cargarEquipos() {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/api/listar_equipos_ejercicios.php");

		DataTable^ tablaEquipos = gcnew DataTable();
		tablaEquipos->Columns->Add("id_equipo", int::typeid);
		tablaEquipos->Columns->Add("nombre", String::typeid);

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each(Match ^ m in matches) {
			String^ item = m->Value;
			DataRow^ r = tablaEquipos->NewRow();
			r["id_equipo"] = Int32::Parse(obtenerCampo(item, "id_equipo"));
			r["nombre"] = obtenerCampo(item, "nombre");
			tablaEquipos->Rows->Add(r);
		}

		auto colEquipo = safe_cast<DataGridViewComboBoxColumn^>(this->equipo);
		colEquipo->DataSource = tablaEquipos;
		colEquipo->DisplayMember = "nombre";
		colEquipo->ValueMember = "id_equipo";
	}

	private: String^ obtenerCampo(String^ json, String^ campo) {
		// Busca el patrón "campo":"valor"
		String^ patron = "\\\"" + campo + "\\\":\\\"([^\\\"]+)\\\"";
		System::Text::RegularExpressions::Regex^ rx = gcnew System::Text::RegularExpressions::Regex(patron);
		System::Text::RegularExpressions::Match^ m = rx->Match(json);

		if (m->Success) {
			return m->Groups[1]->Value;
		}
		return "";
	}






	private: System::Void buttonListarEjercicios_Click(System::Object^ sender, System::EventArgs^ e) {
		WebClient^ client = gcnew WebClient();
		client->Encoding = System::Text::Encoding::UTF8;
		String^ json = client->DownloadString("http://localhost/api/listar_ejercicios.php");

		// Limpiar el DataGridView antes de cargar
		this->dataGridView1->Rows->Clear();

		Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
		auto matches = rx->Matches(json);

		for each(Match ^ m in matches) {
			String^ item = m->Value;

			int id_ejercicio = Int32::Parse(obtenerCampo(item, "id_ejercicio"));
			String^ nombre = obtenerCampo(item, "nombre");
			String^ descripcion = obtenerCampo(item, "descripcion");
			int id_grupo = Int32::Parse(obtenerCampo(item, "id_grupo"));
			int id_equipo = Int32::Parse(obtenerCampo(item, "id_equipo"));

			// Agregar fila al DataGridView (incluyendo la columna oculta id_ejercicio)
			this->dataGridView1->Rows->Add(id_ejercicio, nombre, descripcion, id_grupo, id_equipo);
		}
	}

	private: System::Void buttonAgregarEjercicio_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->CurrentRow != nullptr) {
			DataGridViewRow^ row = this->dataGridView1->CurrentRow;

			String^ nombre = safe_cast<String^>(row->Cells["nombre"]->Value);
			String^ descripcion = safe_cast<String^>(row->Cells["descripcion"]->Value);
			int id_grupo = safe_cast<int>(row->Cells["grupo"]->Value);
			int id_equipo = safe_cast<int>(row->Cells["equipo"]->Value);

			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			System::Collections::Specialized::NameValueCollection^ datos = gcnew System::Collections::Specialized::NameValueCollection();
			datos->Add("nombre", nombre);
			datos->Add("descripcion", descripcion);
			datos->Add("id_grupo", id_grupo.ToString());
			datos->Add("id_equipo", id_equipo.ToString());

			array<Byte>^ respuesta = client->UploadValues("http://localhost/api/agregar_ejercicio.php", "POST", datos);
			String^ resultado = System::Text::Encoding::UTF8->GetString(respuesta);

			MessageBox::Show(resultado, "Resultado");
		}
		buttonListarEjercicios_Click(nullptr, nullptr);

	}


	private: System::Void buttonEliminarEjercicio_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->CurrentRow != nullptr) {
			DataGridViewRow^ row = this->dataGridView1->CurrentRow;

			// El id_ejercicio debería estar en una columna oculta o en la fila
			int id_ejercicio = Convert::ToInt32(row->Cells["id_ejercicio"]->Value);

			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			System::Collections::Specialized::NameValueCollection^ datos = gcnew System::Collections::Specialized::NameValueCollection();
			datos->Add("id_ejercicio", id_ejercicio.ToString());

			array<Byte>^ respuesta = client->UploadValues("http://localhost/api/eliminar_ejercicio.php", "POST", datos);
			String^ resultado = System::Text::Encoding::UTF8->GetString(respuesta);

			MessageBox::Show(resultado, "Resultado");

			// Opcional: refrescar la grilla
			// buttonListarEjercicios_Click(nullptr, nullptr);
		}
		buttonListarEjercicios_Click(nullptr, nullptr);

	}
};
}
