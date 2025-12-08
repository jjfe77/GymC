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
	using namespace System::Text;
	using namespace System::Globalization;


	/// <summary>
	/// Resumen de HistorialVentasForm
	/// </summary>
	public ref class HistorialVentasForm : public System::Windows::Forms::Form
	{

		int ClienteID;


	public:
		HistorialVentasForm(int ClientID)
		{
			InitializeComponent();
			this->ClienteID = ClientID;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~HistorialVentasForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBoxVentaHistorial;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridViewDetalle;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Producto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PrecioUnitario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subtotal;
	private: System::Windows::Forms::Button^ buttonMostrar;


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
			this->comboBoxVentaHistorial = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->Producto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PrecioUnitario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Subtotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonMostrar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetalle))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(31, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(638, 53);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Historial de ventas de Ventas";
			// 
			// comboBoxVentaHistorial
			// 
			this->comboBoxVentaHistorial->FormattingEnabled = true;
			this->comboBoxVentaHistorial->Location = System::Drawing::Point(181, 144);
			this->comboBoxVentaHistorial->Name = L"comboBoxVentaHistorial";
			this->comboBoxVentaHistorial->Size = System::Drawing::Size(314, 24);
			this->comboBoxVentaHistorial->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(51, 137);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 32);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Venta";
			// 
			// dataGridViewDetalle
			// 
			this->dataGridViewDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDetalle->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Producto,
					this->Cantidad, this->PrecioUnitario, this->Subtotal
			});
			this->dataGridViewDetalle->Location = System::Drawing::Point(75, 224);
			this->dataGridViewDetalle->Name = L"dataGridViewDetalle";
			this->dataGridViewDetalle->RowHeadersWidth = 51;
			this->dataGridViewDetalle->RowTemplate->Height = 24;
			this->dataGridViewDetalle->Size = System::Drawing::Size(872, 277);
			this->dataGridViewDetalle->TabIndex = 16;
			// 
			// Producto
			// 
			this->Producto->HeaderText = L"Producto";
			this->Producto->MinimumWidth = 6;
			this->Producto->Name = L"Producto";
			this->Producto->ReadOnly = true;
			this->Producto->Width = 125;
			// 
			// Cantidad
			// 
			this->Cantidad->HeaderText = L"Cantidad";
			this->Cantidad->MinimumWidth = 6;
			this->Cantidad->Name = L"Cantidad";
			this->Cantidad->ReadOnly = true;
			this->Cantidad->Width = 125;
			// 
			// PrecioUnitario
			// 
			this->PrecioUnitario->HeaderText = L"PrecioUnitario";
			this->PrecioUnitario->MinimumWidth = 6;
			this->PrecioUnitario->Name = L"PrecioUnitario";
			this->PrecioUnitario->ReadOnly = true;
			this->PrecioUnitario->Width = 125;
			// 
			// Subtotal
			// 
			this->Subtotal->HeaderText = L"Subtotal";
			this->Subtotal->MinimumWidth = 6;
			this->Subtotal->Name = L"Subtotal";
			this->Subtotal->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Subtotal->Width = 125;
			// 
			// buttonMostrar
			// 
			this->buttonMostrar->Location = System::Drawing::Point(447, 554);
			this->buttonMostrar->Name = L"buttonMostrar";
			this->buttonMostrar->Size = System::Drawing::Size(143, 52);
			this->buttonMostrar->TabIndex = 17;
			this->buttonMostrar->Text = L"Mostrar";
			this->buttonMostrar->UseVisualStyleBackColor = true;
			this->buttonMostrar->Visible = false;
			// 
			// HistorialVentasForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1045, 718);
			this->Controls->Add(this->buttonMostrar);
			this->Controls->Add(this->dataGridViewDetalle);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxVentaHistorial);
			this->Controls->Add(this->label2);
			this->Name = L"HistorialVentasForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HistorialVentasForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetalle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	protected:
		virtual void OnLoad(System::EventArgs^ e) override {
			Form::OnLoad(e);
			cargarFechasVentas(ClienteID);
			this->comboBoxVentaHistorial->SelectedIndexChanged += gcnew System::EventHandler(this, &HistorialVentasForm::comboBoxVentaHistorial_SelectedIndexChanged);
			this->dataGridViewDetalle->Columns["Producto"]->Width = 200;
		}

	private:
		void cargarFechasVentas(int clienteID) {
			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			String^ url = "http://localhost/api/listar_ventas_cliente.php?ClienteID=" + clienteID;
			String^ json = client->DownloadString(url);

			DataTable^ dt = gcnew DataTable();
			dt->Columns->Add("VentaID", Int32::typeid);
			dt->Columns->Add("FechaVenta", String::typeid);

			Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
			auto matches = rx->Matches(json);

			for each (Match ^ m in matches) {
				String^ item = m->Value;
				int ventaID = Int32::Parse(obtenerCampo(item, "VentaID"));
				String^ fecha = obtenerCampo(item, "FechaVenta");
				dt->Rows->Add(ventaID, fecha);
			}

			dt->Rows->InsertAt(dt->NewRow(), 0);
			dt->Rows[0]["FechaVenta"] = "-- Seleccione una venta --";
			dt->Rows[0]["VentaID"] = DBNull::Value;


			comboBoxVentaHistorial->DataSource = dt;
			comboBoxVentaHistorial->DisplayMember = "FechaVenta"; // lo que ve el usuario
			comboBoxVentaHistorial->ValueMember = "VentaID";      // lo que se guarda
		}

	private: System::String^ obtenerCampo(System::String^ jsonItem, System::String^ campo) {
		// Construir el patrón: "campo":"valor"
		String^ patron = "\"" + campo + "\"\\s*:\\s*\"([^\"]+)\"";
		Regex^ rx = gcnew Regex(patron);

		Match^ m = rx->Match(jsonItem);
		if (m->Success) {
			return m->Groups[1]->Value;
		}

		return ""; // Si no encuentra nada, devolver vacío
	}




	private: System::Void comboBoxVentaHistorial_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBoxVentaHistorial->SelectedValue == nullptr) return;

		if (comboBoxVentaHistorial->SelectedIndex == 0) {
			MessageBox::Show("Seleccione una venta válida.");
			return;
		}

		int ventaID = Int32::Parse(comboBoxVentaHistorial->SelectedValue->ToString());

		try {
			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			String^ url = "http://localhost/api/listar_detalle_venta.php?VentaID=" + ventaID;
			String^ json = client->DownloadString(url);
			//MessageBox::Show("JSON recibido:\n" + json);

			// Limpiar el DataGridView
			dataGridViewDetalle->Rows->Clear();

			// Buscar objetos JSON con Regex
			Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
			auto matches = rx->Matches(json);

			for each (Match ^ m in matches) {
				String^ item = m->Value;

				String^ producto = obtenerCampo(item, "Producto");
				String^ cantidad = obtenerCampo(item, "Cantidad");
				String^ precioUnitario = obtenerCampo(item, "PrecioUnitario");
				String^ subtotal = obtenerCampo(item, "Subtotal");

				// Agregar fila al DataGridView
				dataGridViewDetalle->Rows->Add(producto, cantidad, precioUnitario, subtotal);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cargar detalle de venta: " + ex->Message);
		}
	}

		
	};
}
