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
	/// Resumen de CuotaForm
	/// </summary>
	public ref class CuotaForm : public System::Windows::Forms::Form
	{
	public:
		CuotaForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->dataGridView1->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView1->Columns["estado"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			// Ancho de columnas
			Id_usuario->Width = 40;
			dni->Width = 80;
			nombre->Width = 120;
			apellido->Width = 120;
			fecha_inscripcion->Width = 110;
			ultima_fecha_pago->Width = 110;
			fecha_vencimiento->Width = 110;
			tipo_membresia->Width = 60;
			estado->Width = 80;
			// Centrar algunas columnas
			Id_usuario->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dni->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			estado->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			tipo_membresia->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;


			dtp = gcnew DateTimePicker();
			dtp->Format = DateTimePickerFormat::Custom;
			dtp->CustomFormat = "yyyy-MM-dd";   // formato válido para MySQL
			dtp->Visible = false;

			// Eventos del DTP
			dtp->CloseUp += gcnew EventHandler(this, &CuotaForm::dtp_CloseUp);
			dtp->Leave += gcnew EventHandler(this, &CuotaForm::dtp_Leave);

			// Lo agregamos dentro del DataGridView
			this->dataGridView1->Controls->Add(dtp);

			// Eventos del DataGrid
			
			this->dataGridView1->CellEndEdit += gcnew DataGridViewCellEventHandler(this, &CuotaForm::dataGridView1_CellEndEdit);
			this->dataGridView1->Scroll += gcnew ScrollEventHandler(this, &CuotaForm::dataGridView1_Scroll);
			this->dataGridView1->ColumnWidthChanged += gcnew DataGridViewColumnEventHandler(this, &CuotaForm::dataGridView1_ColumnWidthChanged);
			this->dataGridView1->CellClick += gcnew DataGridViewCellEventHandler(this, &CuotaForm::dataGridView1_CellClick);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~CuotaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;









	private: System::Windows::Forms::Button^ buttonListarCuotas;
	private: System::Windows::Forms::Button^ buttonBuscarCuotas;
	private: System::Windows::Forms::Button^ buttonGuardarCuotas;

	private: System::Windows::Forms::Button^ buttonVolverCuotas;

	private: System::Windows::Forms::DateTimePicker^ dtp;
		int editingRow = -1;
		int editingCol = -1;
	private: System::Windows::Forms::Button^ buttonLimpiarCuotas;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id_usuario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dni;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ apellido;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fecha_inscripcion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ultima_fecha_pago;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fecha_vencimiento;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ tipo_membresia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ estado;










	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonListarCuotas = (gcnew System::Windows::Forms::Button());
			this->buttonBuscarCuotas = (gcnew System::Windows::Forms::Button());
			this->buttonGuardarCuotas = (gcnew System::Windows::Forms::Button());
			this->buttonVolverCuotas = (gcnew System::Windows::Forms::Button());
			this->buttonLimpiarCuotas = (gcnew System::Windows::Forms::Button());
			this->Id_usuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dni = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->apellido = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fecha_inscripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ultima_fecha_pago = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fecha_vencimiento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tipo_membresia = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->estado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(399, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(574, 53);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Administracion de Cuotas";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Id_usuario,
					this->dni, this->nombre, this->apellido, this->fecha_inscripcion, this->ultima_fecha_pago, this->fecha_vencimiento, this->tipo_membresia,
					this->estado
			});
			this->dataGridView1->Location = System::Drawing::Point(78, 94);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1224, 197);
			this->dataGridView1->TabIndex = 10;
			// 
			// buttonListarCuotas
			// 
			this->buttonListarCuotas->Location = System::Drawing::Point(162, 481);
			this->buttonListarCuotas->Name = L"buttonListarCuotas";
			this->buttonListarCuotas->Size = System::Drawing::Size(144, 72);
			this->buttonListarCuotas->TabIndex = 11;
			this->buttonListarCuotas->Text = L"Listar";
			this->buttonListarCuotas->UseVisualStyleBackColor = true;
			this->buttonListarCuotas->Click += gcnew System::EventHandler(this, &CuotaForm::buttonListarCuotas_Click);
			// 
			// buttonBuscarCuotas
			// 
			this->buttonBuscarCuotas->Location = System::Drawing::Point(379, 481);
			this->buttonBuscarCuotas->Name = L"buttonBuscarCuotas";
			this->buttonBuscarCuotas->Size = System::Drawing::Size(144, 72);
			this->buttonBuscarCuotas->TabIndex = 12;
			this->buttonBuscarCuotas->Text = L"Buscar";
			this->buttonBuscarCuotas->UseVisualStyleBackColor = true;
			this->buttonBuscarCuotas->Click += gcnew System::EventHandler(this, &CuotaForm::buttonBuscarCuotas_Click);
			// 
			// buttonGuardarCuotas
			// 
			this->buttonGuardarCuotas->Location = System::Drawing::Point(603, 481);
			this->buttonGuardarCuotas->Name = L"buttonGuardarCuotas";
			this->buttonGuardarCuotas->Size = System::Drawing::Size(144, 72);
			this->buttonGuardarCuotas->TabIndex = 13;
			this->buttonGuardarCuotas->Text = L"Guardar";
			this->buttonGuardarCuotas->UseVisualStyleBackColor = true;
			this->buttonGuardarCuotas->Click += gcnew System::EventHandler(this, &CuotaForm::buttonGuardarCuotas_Click);
			// 
			// buttonVolverCuotas
			// 
			this->buttonVolverCuotas->Location = System::Drawing::Point(1051, 481);
			this->buttonVolverCuotas->Name = L"buttonVolverCuotas";
			this->buttonVolverCuotas->Size = System::Drawing::Size(144, 72);
			this->buttonVolverCuotas->TabIndex = 14;
			this->buttonVolverCuotas->Text = L"Volver";
			this->buttonVolverCuotas->UseVisualStyleBackColor = true;
			this->buttonVolverCuotas->Visible = false;
			// 
			// buttonLimpiarCuotas
			// 
			this->buttonLimpiarCuotas->Location = System::Drawing::Point(829, 481);
			this->buttonLimpiarCuotas->Name = L"buttonLimpiarCuotas";
			this->buttonLimpiarCuotas->Size = System::Drawing::Size(144, 72);
			this->buttonLimpiarCuotas->TabIndex = 15;
			this->buttonLimpiarCuotas->Text = L"Limpiar";
			this->buttonLimpiarCuotas->UseVisualStyleBackColor = true;
			this->buttonLimpiarCuotas->Click += gcnew System::EventHandler(this, &CuotaForm::buttonLimpiarCuotas_Click);
			// 
			// Id_usuario
			// 
			this->Id_usuario->HeaderText = L"N° Socio";
			this->Id_usuario->MinimumWidth = 6;
			this->Id_usuario->Name = L"Id_usuario";
			this->Id_usuario->ReadOnly = true;
			this->Id_usuario->Width = 125;
			// 
			// dni
			// 
			this->dni->HeaderText = L"DNI";
			this->dni->MinimumWidth = 6;
			this->dni->Name = L"dni";
			this->dni->ReadOnly = true;
			this->dni->Width = 125;
			// 
			// nombre
			// 
			this->nombre->HeaderText = L"Nombre";
			this->nombre->MinimumWidth = 6;
			this->nombre->Name = L"nombre";
			this->nombre->ReadOnly = true;
			this->nombre->Width = 125;
			// 
			// apellido
			// 
			this->apellido->HeaderText = L"Apellido";
			this->apellido->MinimumWidth = 6;
			this->apellido->Name = L"apellido";
			this->apellido->Width = 125;
			// 
			// fecha_inscripcion
			// 
			this->fecha_inscripcion->HeaderText = L"Fecha de Inscripcion";
			this->fecha_inscripcion->MinimumWidth = 6;
			this->fecha_inscripcion->Name = L"fecha_inscripcion";
			this->fecha_inscripcion->ReadOnly = true;
			this->fecha_inscripcion->Width = 125;
			// 
			// ultima_fecha_pago
			// 
			this->ultima_fecha_pago->HeaderText = L"Fecha Ultimo Pago";
			this->ultima_fecha_pago->MinimumWidth = 6;
			this->ultima_fecha_pago->Name = L"ultima_fecha_pago";
			this->ultima_fecha_pago->Width = 125;
			// 
			// fecha_vencimiento
			// 
			this->fecha_vencimiento->HeaderText = L"Fecha de Vencimiento";
			this->fecha_vencimiento->MinimumWidth = 6;
			this->fecha_vencimiento->Name = L"fecha_vencimiento";
			this->fecha_vencimiento->Width = 125;
			// 
			// tipo_membresia
			// 
			this->tipo_membresia->HeaderText = L"Tipo Membresia";
			this->tipo_membresia->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2 dias", L"3 dias", L"full" });
			this->tipo_membresia->MinimumWidth = 6;
			this->tipo_membresia->Name = L"tipo_membresia";
			this->tipo_membresia->Width = 125;
			// 
			// estado
			// 
			this->estado->HeaderText = L"Estado";
			this->estado->MinimumWidth = 6;
			this->estado->Name = L"estado";
			this->estado->Width = 125;
			// 
			// CuotaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1515, 662);
			this->Controls->Add(this->buttonLimpiarCuotas);
			this->Controls->Add(this->buttonVolverCuotas);
			this->Controls->Add(this->buttonGuardarCuotas);
			this->Controls->Add(this->buttonBuscarCuotas);
			this->Controls->Add(this->buttonListarCuotas);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Name = L"CuotaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CuotaForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		


#pragma endregion
	

		void dataGridView1_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e){

			if(e->RowIndex < 0 || e->ColumnIndex < 0)
				return;

			// Evita errores si la columna no existe
			if (e->ColumnIndex >= dataGridView1->ColumnCount)
				return;

			// Evita errores si la fila no existe
			if (e->RowIndex >= dataGridView1->RowCount)
				return;

			if (e->RowIndex < 0) return; // header

			String^ col = this->dataGridView1->Columns[e->ColumnIndex]->Name;
			if (col == "fecha_inscripcion" || col == "ultima_fecha_pago" || col == "fecha_vencimiento")
			{
				editingRow = e->RowIndex;
				editingCol = e->ColumnIndex;

				Rectangle rect = dataGridView1->GetCellDisplayRectangle(e->ColumnIndex, e->RowIndex, true);
				dtp->Size = System::Drawing::Size(rect.Width, rect.Height);
				dtp->Location = System::Drawing::Point(rect.X, rect.Y);

				Object^ val = dataGridView1[e->ColumnIndex, e->RowIndex]->Value;
				DateTime parsed;
				if (val != nullptr && DateTime::TryParse(val->ToString(), parsed))
					dtp->Value = parsed;
				else
					dtp->Value = DateTime::Now;

				dtp->Visible = true;
				dtp->BringToFront();
				dtp->Focus();
			}
		}



		void CommitDate()
		{
			if (editingRow >= 0 && editingCol >= 0)
			{
				dataGridView1[editingCol, editingRow]->Value = dtp->Value.ToString("yyyy-MM-dd");
			}

			dtp->Visible = false;
			editingRow = -1;
			editingCol = -1;
		}

		void dtp_CloseUp(System::Object^ sender, System::EventArgs^ e)
		{
			CommitDate();
		}

		void dtp_Leave(System::Object^ sender, System::EventArgs^ e)
		{
			CommitDate();
		}

		void dataGridView1_CellEndEdit(System::Object^ sender, DataGridViewCellEventArgs^ e)
		{
			dtp->Visible = false;
		}

		void dataGridView1_Scroll(System::Object^ sender, ScrollEventArgs^ e)
		{
			dtp->Visible = false;
		}

		void dataGridView1_ColumnWidthChanged(System::Object^ sender, DataGridViewColumnEventArgs^ e)
		{
			dtp->Visible = false;
		}





		private: System::Void buttonListarCuotas_Click(System::Object^ sender, System::EventArgs^ e) {

			try {
				String^ url = "http://localhost/api/listar_cuotas.php";
				HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
				request->Method = "GET";

				HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
				StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
				String^ json = reader->ReadToEnd();

				response->Close();

				// Limpia la grilla
				dataGridView1->Rows->Clear();

				// Si la API devolvió vacío
				if (String::IsNullOrWhiteSpace(json)) {
					MessageBox::Show("El servidor devolvió una respuesta vacía.");
					return;
				}

				// Regex para capturar cada objeto { ... }
				Regex^ rx = gcnew Regex("\\{[^}]*\\}");

				MatchCollection^ matches = rx->Matches(json);

				if (matches->Count == 0) {
					MessageBox::Show("No se encontraron datos en el JSON. Revisar API.");
					return;
				}

				// Recorremos los objetos encontrados
				for each (Match ^ match in matches) {

					String^ item = match->Value;

					

					dataGridView1->Rows->Add(
						obtenerCampo(item, "id_usuario"),
						obtenerCampo(item, "dni"),
						obtenerCampo(item, "nombre"),
						obtenerCampo(item, "apellido"),
						obtenerCampo(item, "fecha_inscripcion"),
						obtenerCampo(item, "ultima_fecha_pago"),
						obtenerCampo(item, "fecha_vencimiento"),
						obtenerCampo(item, "tipo_membresia"),
						obtenerCampo(item, "estado")
					);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al listar cuotas: " + ex->Message);
			}
		}




			   String^ obtenerCampo(String^ json, String^ campo) {
				   // patrón que acepta "campo":"valor"  o  "campo":valor
				   String^ patron = campo + "\":\\s*(?:\"([^\"]*)\"|([^,}\\s]+))";
				   System::Text::RegularExpressions::Regex^ rx =
					   gcnew System::Text::RegularExpressions::Regex(patron);

				   System::Text::RegularExpressions::Match^ match = rx->Match(json);

				   if (match->Success) {
					   // grupo 1 = valor entre comillas, grupo 2 = valor sin comillas
					   if (match->Groups[1]->Success && match->Groups[1]->Value->Length > 0)
						   return match->Groups[1]->Value;
					   else
						   return match->Groups[2]->Value;
				   }

				   return "";
			   }



private: System::Void buttonGuardarCuotas_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		if (dataGridView1->CurrentRow == nullptr || dataGridView1->CurrentRow->IsNewRow) {
			MessageBox::Show("No hay ninguna fila seleccionada para guardar.");
			return;
		}

		DataGridViewRow^ row = dataGridView1->CurrentRow;

		String^ id_usuario = row->Cells["Id_usuario"]->Value->ToString();
		String^ ultima_fecha_pago = row->Cells["ultima_fecha_pago"]->Value->ToString();
		String^ fecha_vencimiento = row->Cells["fecha_vencimiento"]->Value->ToString();
		String^ tipo_membresia = row->Cells["tipo_membresia"]->Value->ToString();

		String^ url = "http://localhost/api/update_cuota.php";
		String^ postData = "id_usuario=" + id_usuario +
			"&ultima_fecha_pago=" + ultima_fecha_pago +
			"&fecha_vencimiento=" + fecha_vencimiento +
			"&tipo_membresia=" + tipo_membresia;

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
			MessageBox::Show("Guardado correctamente.");
		}
		else {
			MessageBox::Show("Error: no se pudo guardar la cuota.");
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al guardar cuota: " + ex->Message);
	}
}





private: System::Void buttonBuscarCuotas_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Verificar que haya una celda activa
		if (dataGridView1->CurrentCell == nullptr) {
			MessageBox::Show("No hay ninguna celda activa.");
			return;
		}

		// Tomar el valor de la celda activa
		String^ apellido = dataGridView1->CurrentCell->Value != nullptr
			? dataGridView1->CurrentCell->Value->ToString()
			: "";

		if (String::IsNullOrWhiteSpace(apellido)) {
			MessageBox::Show("La celda está vacía, escriba un apellido.");
			return;
		}

		// Construir URL con ese valor
		String^ url = "http://localhost/api/buscar_cuotas.php?apellido=" + apellido;

		HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
		request->Method = "GET";

		HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
		StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
		String^ json = reader->ReadToEnd();
		response->Close();

		// Limpiar grilla
		dataGridView1->Rows->Clear();

		if (String::IsNullOrWhiteSpace(json)) {
			MessageBox::Show("No se encontraron cuotas para ese apellido.");
			return;
		}

		// Parsear JSON con tu método actual
		Regex^ rx = gcnew Regex("\\{[^}]*\\}");
		MatchCollection^ matches = rx->Matches(json);

		for each (Match ^ match in matches) {
			String^ item = match->Value;

			dataGridView1->Rows->Add(
				obtenerCampo(item, "id_usuario"),
				obtenerCampo(item, "dni"),
				obtenerCampo(item, "nombre"),
				obtenerCampo(item, "apellido"),
				obtenerCampo(item, "fecha_inscripcion"),
				obtenerCampo(item, "ultima_fecha_pago"),
				obtenerCampo(item, "fecha_vencimiento"),
				obtenerCampo(item, "tipo_membresia"),
				obtenerCampo(item, "estado")
			);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al buscar cuotas: " + ex->Message);
	}
}





private: System::Void buttonLimpiarCuotas_Click(System::Object^ sender, System::EventArgs^ e) {
	this->dataGridView1->Rows->Clear();
}
};
}
