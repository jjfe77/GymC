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




	/// <summary>
	/// Resumen de EquiposForm
	/// </summary>
	public ref class EquiposForm : public System::Windows::Forms::Form
	{
	public:
		EquiposForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->Load += gcnew System::EventHandler(this, &EquiposForm::EquiposForm_Load);

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~EquiposForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridViewEquipos;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_equipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ descripcion;
	private: System::Windows::Forms::Button^ buttonAgregarEquipos;

	private: System::Windows::Forms::Button^ buttonListarEquipos;
	private: System::Windows::Forms::Button^ buttonEliminarEquipos;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ estado;

	private: System::Void EquiposForm_Load(System::Object^ sender, System::EventArgs^ e) {
		DataGridViewComboBoxColumn^ estadoCol = (DataGridViewComboBoxColumn^)this->dataGridViewEquipos->Columns["estado"];
		estadoCol->Items->Add("Disponible");
		estadoCol->Items->Add("Mantenimiento");
		estadoCol->Items->Add("Fuera de servicio");

		// Opcional: ajustes estéticos
		this->dataGridViewEquipos->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		//this->dataGridViewEquipos->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewEquipos->Columns["id_equipo"]->Width = 50;
		this->dataGridViewEquipos->Columns["nombre"]->Width = 150;
		this->dataGridViewEquipos->Columns["descripcion"]->Width = 350;
		this->dataGridViewEquipos->Columns["estado"]->Width = 120;
		this->dataGridViewEquipos->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
		this->dataGridViewEquipos->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;


	}
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
			this->dataGridViewEquipos = (gcnew System::Windows::Forms::DataGridView());
			this->id_equipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->estado = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->buttonAgregarEquipos = (gcnew System::Windows::Forms::Button());
			this->buttonListarEquipos = (gcnew System::Windows::Forms::Button());
			this->buttonEliminarEquipos = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewEquipos))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(242, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(598, 53);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Administracion de Equipos";
			// 
			// dataGridViewEquipos
			// 
			this->dataGridViewEquipos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewEquipos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->id_equipo,
					this->nombre, this->descripcion, this->estado
			});
			this->dataGridViewEquipos->Location = System::Drawing::Point(64, 131);
			this->dataGridViewEquipos->Name = L"dataGridViewEquipos";
			this->dataGridViewEquipos->RowHeadersWidth = 51;
			this->dataGridViewEquipos->RowTemplate->Height = 24;
			this->dataGridViewEquipos->Size = System::Drawing::Size(990, 209);
			this->dataGridViewEquipos->TabIndex = 11;
			// 
			// id_equipo
			// 
			this->id_equipo->HeaderText = L"N° de Equipo";
			this->id_equipo->MinimumWidth = 6;
			this->id_equipo->Name = L"id_equipo";
			this->id_equipo->ReadOnly = true;
			this->id_equipo->Width = 125;
			// 
			// nombre
			// 
			this->nombre->HeaderText = L"Nombre";
			this->nombre->MinimumWidth = 6;
			this->nombre->Name = L"nombre";
			this->nombre->Width = 125;
			// 
			// descripcion
			// 
			this->descripcion->HeaderText = L"Descripcion";
			this->descripcion->MinimumWidth = 6;
			this->descripcion->Name = L"descripcion";
			this->descripcion->Width = 125;
			// 
			// estado
			// 
			this->estado->HeaderText = L"Estado";
			this->estado->MinimumWidth = 6;
			this->estado->Name = L"estado";
			this->estado->Width = 125;
			// 
			// buttonAgregarEquipos
			// 
			this->buttonAgregarEquipos->Location = System::Drawing::Point(476, 407);
			this->buttonAgregarEquipos->Name = L"buttonAgregarEquipos";
			this->buttonAgregarEquipos->Size = System::Drawing::Size(144, 72);
			this->buttonAgregarEquipos->TabIndex = 12;
			this->buttonAgregarEquipos->Text = L"Agregar";
			this->buttonAgregarEquipos->UseVisualStyleBackColor = true;
			this->buttonAgregarEquipos->Click += gcnew System::EventHandler(this, &EquiposForm::buttonAgregarEquipos_Click);
			// 
			// buttonListarEquipos
			// 
			this->buttonListarEquipos->Location = System::Drawing::Point(116, 407);
			this->buttonListarEquipos->Name = L"buttonListarEquipos";
			this->buttonListarEquipos->Size = System::Drawing::Size(144, 72);
			this->buttonListarEquipos->TabIndex = 13;
			this->buttonListarEquipos->Text = L"Listar";
			this->buttonListarEquipos->UseVisualStyleBackColor = true;
			this->buttonListarEquipos->Click += gcnew System::EventHandler(this, &EquiposForm::buttonListarEquipos_Click);
			// 
			// buttonEliminarEquipos
			// 
			this->buttonEliminarEquipos->Location = System::Drawing::Point(846, 407);
			this->buttonEliminarEquipos->Name = L"buttonEliminarEquipos";
			this->buttonEliminarEquipos->Size = System::Drawing::Size(144, 72);
			this->buttonEliminarEquipos->TabIndex = 14;
			this->buttonEliminarEquipos->Text = L"Eliminar";
			this->buttonEliminarEquipos->UseVisualStyleBackColor = true;
			this->buttonEliminarEquipos->Click += gcnew System::EventHandler(this, &EquiposForm::buttonEliminarEquipos_Click);
			// 
			// EquiposForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1119, 709);
			this->Controls->Add(this->buttonEliminarEquipos);
			this->Controls->Add(this->buttonListarEquipos);
			this->Controls->Add(this->buttonAgregarEquipos);
			this->Controls->Add(this->dataGridViewEquipos);
			this->Controls->Add(this->label2);
			this->Name = L"EquiposForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EquiposForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewEquipos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonListarEquipos_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ url = "http://localhost/api/listar_equipos.php";
			HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
			request->Method = "GET";

			HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
			StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
			String^ json = reader->ReadToEnd();
			response->Close();

			dataGridViewEquipos->Rows->Clear();

			// Obtenemos todos los objetos JSON { ... }
			System::Text::RegularExpressions::Regex^ rx = gcnew System::Text::RegularExpressions::Regex("\\{[^\\}]+\\}");
			System::Text::RegularExpressions::MatchCollection^ matches = rx->Matches(json);

			for each(System::Text::RegularExpressions::Match ^ match in matches) {
				String^ item = match->Value;

				dataGridViewEquipos->Rows->Add(
					obtenerCampo(item, "id_equipo"),
					obtenerCampo(item, "nombre"),
					obtenerCampo(item, "descripcion"),
					obtenerCampo(item, "estado")
				);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al listar equipos: " + ex->Message);
		}
	}

	private: String^ obtenerCampo(String^ jsonItem, String^ campo) {
		try {
			// Construimos un patrón regex para encontrar "campo":"valor"
			String^ patron = "\\\"" + campo + "\\\":\\\"([^\\\"]*)\\\"";
			System::Text::RegularExpressions::Regex^ rx = gcnew System::Text::RegularExpressions::Regex(patron);
			System::Text::RegularExpressions::Match^ match = rx->Match(jsonItem);

			if (match->Success) {
				return match->Groups[1]->Value;
			}
			else {
				return ""; // Si no encuentra el campo, devolvemos vacío
			}
		}
		catch (Exception^) {
			return "";
		}
	}

	private: System::Void buttonAgregarEquipos_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (dataGridViewEquipos->CurrentRow == nullptr || dataGridViewEquipos->CurrentRow->IsNewRow) {
				MessageBox::Show("No hay ninguna fila seleccionada para guardar.");
				return;
			}

			DataGridViewRow^ row = dataGridViewEquipos->CurrentRow;

			//String^ id_equipo = row->Cells["id_equipo"]->Value->ToString();
			String^ nombre = row->Cells["nombre"]->Value->ToString();
			String^ descripcion = row->Cells["descripcion"]->Value->ToString();
			String^ estado = row->Cells["estado"]->Value->ToString();

			String^ url = "http://localhost/api/agregar_equipo.php";
			String^ postData = "id_equipo=" + id_equipo +
				"&nombre=" + nombre +
				"&descripcion=" + descripcion +
				"&estado=" + estado;

			// ✅ Encoding correcto
			array<Byte>^ data = System::Text::Encoding::UTF8->GetBytes(postData);

			HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
			request->Method = "POST";
			request->ContentType = "application/x-www-form-urlencoded";
			request->ContentLength = data->Length;

			Stream^ requestStream = request->GetRequestStream();
			requestStream->Write(data, 0, data->Length);
			requestStream->Close();

			HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
			StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
			String^ serverResponse = reader->ReadToEnd();

			reader->Close();
			response->Close();

			if (serverResponse->Contains("success")) {
				MessageBox::Show("Equipo guardado correctamente.");
			}
			else {
				MessageBox::Show("Error: no se pudo guardar el equipo.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al guardar equipo: " + ex->Message);
		}
	}




	private: System::Void buttonEliminarEquipos_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (dataGridViewEquipos->CurrentRow == nullptr || dataGridViewEquipos->CurrentRow->IsNewRow) {
				MessageBox::Show("No hay ninguna fila seleccionada para eliminar.");
				return;
			}

			DataGridViewRow^ row = dataGridViewEquipos->CurrentRow;
			String^ id_equipo = row->Cells["id_equipo"]->Value != nullptr ? row->Cells["id_equipo"]->Value->ToString() : "";

			if (id_equipo == "") {
				MessageBox::Show("El equipo seleccionado no tiene ID válido.");
				return;
			}

			String^ url = "http://localhost/api/delete_equipo.php";
			String^ postData = "id_equipo=" + id_equipo;

			array<Byte>^ data = System::Text::Encoding::UTF8->GetBytes(postData);

			HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
			request->Method = "POST";
			request->ContentType = "application/x-www-form-urlencoded";
			request->ContentLength = data->Length;

			Stream^ requestStream = request->GetRequestStream();
			requestStream->Write(data, 0, data->Length);
			requestStream->Close();

			HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
			StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
			String^ serverResponse = reader->ReadToEnd();

			reader->Close();
			response->Close();

			if (serverResponse->Contains("success")) {
				MessageBox::Show("Equipo eliminado correctamente.");
				// Opcional: refrescar la grilla
				dataGridViewEquipos->Rows->Remove(row);
			}
			else {
				MessageBox::Show("Error: no se pudo eliminar el equipo.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al eliminar equipo: " + ex->Message);
		}
	}
	};
}
