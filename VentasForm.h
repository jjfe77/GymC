#pragma once
#include "HistorialVentasForm.h"

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
	/// Resumen de VentasForm
	/// </summary>
	public ref class VentasForm : public System::Windows::Forms::Form
	{
	public:
		VentasForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->Load += gcnew System::EventHandler(this, &Gym::VentasForm::VentasForm_Load);
			this->comboBoxClientes->SelectedIndexChanged += gcnew System::EventHandler(this, &VentasForm::comboBoxClientes_SelectedIndexChanged);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VentasForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Data::DataTable^ dtProductos;
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBoxClientes;


	private: System::Windows::Forms::TextBox^ textBoxTotal;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridViewDetalleVenta;





	private: System::Windows::Forms::Button^ buttonAgregarVenta;
	private: System::Windows::Forms::Button^ buttonListarVentas;
	private: System::Windows::Forms::Button^ buttonLimpiar;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductoID;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Producto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PrecioUnitario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subtotal;







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
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxClientes = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxTotal = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewDetalleVenta = (gcnew System::Windows::Forms::DataGridView());
			this->ProductoID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Producto = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PrecioUnitario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Subtotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAgregarVenta = (gcnew System::Windows::Forms::Button());
			this->buttonListarVentas = (gcnew System::Windows::Forms::Button());
			this->buttonLimpiar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetalleVenta))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(47, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(406, 53);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Gestion de Ventas";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Location = System::Drawing::Point(685, 36);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(401, 30);
			this->dateTimePicker1->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(52, 121);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 24);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Cliente";
			// 
			// comboBoxClientes
			// 
			this->comboBoxClientes->FormattingEnabled = true;
			this->comboBoxClientes->Location = System::Drawing::Point(162, 121);
			this->comboBoxClientes->Name = L"comboBoxClientes";
			this->comboBoxClientes->Size = System::Drawing::Size(383, 24);
			this->comboBoxClientes->TabIndex = 15;
			// 
			// textBoxTotal
			// 
			this->textBoxTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxTotal->Location = System::Drawing::Point(883, 650);
			this->textBoxTotal->Name = L"textBoxTotal";
			this->textBoxTotal->ReadOnly = true;
			this->textBoxTotal->Size = System::Drawing::Size(203, 38);
			this->textBoxTotal->TabIndex = 16;
			this->textBoxTotal->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(779, 659);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 29);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Total";
			// 
			// dataGridViewDetalleVenta
			// 
			this->dataGridViewDetalleVenta->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDetalleVenta->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ProductoID,
					this->Producto, this->Cantidad, this->PrecioUnitario, this->Subtotal
			});
			this->dataGridViewDetalleVenta->Location = System::Drawing::Point(75, 229);
			this->dataGridViewDetalleVenta->Name = L"dataGridViewDetalleVenta";
			this->dataGridViewDetalleVenta->RowHeadersWidth = 51;
			this->dataGridViewDetalleVenta->RowTemplate->Height = 24;
			this->dataGridViewDetalleVenta->Size = System::Drawing::Size(896, 301);
			this->dataGridViewDetalleVenta->TabIndex = 18;
			// 
			// ProductoID
			// 
			this->ProductoID->HeaderText = L"ProductoID";
			this->ProductoID->MinimumWidth = 6;
			this->ProductoID->Name = L"ProductoID";
			this->ProductoID->Visible = false;
			this->ProductoID->Width = 125;
			// 
			// Producto
			// 
			this->Producto->HeaderText = L"Producto";
			this->Producto->MinimumWidth = 6;
			this->Producto->Name = L"Producto";
			this->Producto->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Producto->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Producto->Width = 125;
			// 
			// Cantidad
			// 
			this->Cantidad->HeaderText = L"Cantidad";
			this->Cantidad->MinimumWidth = 6;
			this->Cantidad->Name = L"Cantidad";
			this->Cantidad->Width = 125;
			// 
			// PrecioUnitario
			// 
			this->PrecioUnitario->HeaderText = L"Precio Unitario";
			this->PrecioUnitario->MinimumWidth = 6;
			this->PrecioUnitario->Name = L"PrecioUnitario";
			this->PrecioUnitario->Width = 125;
			// 
			// Subtotal
			// 
			this->Subtotal->HeaderText = L"Subtotal";
			this->Subtotal->MinimumWidth = 6;
			this->Subtotal->Name = L"Subtotal";
			this->Subtotal->Width = 125;
			// 
			// buttonAgregarVenta
			// 
			this->buttonAgregarVenta->Location = System::Drawing::Point(58, 620);
			this->buttonAgregarVenta->Name = L"buttonAgregarVenta";
			this->buttonAgregarVenta->Size = System::Drawing::Size(154, 68);
			this->buttonAgregarVenta->TabIndex = 19;
			this->buttonAgregarVenta->Text = L"Agregar Venta";
			this->buttonAgregarVenta->UseVisualStyleBackColor = true;
			this->buttonAgregarVenta->Click += gcnew System::EventHandler(this, &VentasForm::buttonAgregarVenta_Click);
			// 
			// buttonListarVentas
			// 
			this->buttonListarVentas->Location = System::Drawing::Point(451, 624);
			this->buttonListarVentas->Name = L"buttonListarVentas";
			this->buttonListarVentas->Size = System::Drawing::Size(154, 68);
			this->buttonListarVentas->TabIndex = 20;
			this->buttonListarVentas->Text = L"Historial de Ventas";
			this->buttonListarVentas->UseVisualStyleBackColor = true;
			this->buttonListarVentas->Click += gcnew System::EventHandler(this, &VentasForm::buttonListarVentas_Click);
			// 
			// buttonLimpiar
			// 
			this->buttonLimpiar->Location = System::Drawing::Point(255, 624);
			this->buttonLimpiar->Name = L"buttonLimpiar";
			this->buttonLimpiar->Size = System::Drawing::Size(154, 68);
			this->buttonLimpiar->TabIndex = 21;
			this->buttonLimpiar->Text = L"Limpiar";
			this->buttonLimpiar->UseVisualStyleBackColor = true;
			this->buttonLimpiar->Click += gcnew System::EventHandler(this, &VentasForm::buttonLimpiar_Click);
			// 
			// VentasForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1122, 731);
			this->Controls->Add(this->buttonLimpiar);
			this->Controls->Add(this->buttonListarVentas);
			this->Controls->Add(this->buttonAgregarVenta);
			this->Controls->Add(this->dataGridViewDetalleVenta);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxTotal);
			this->Controls->Add(this->comboBoxClientes);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label2);
			this->Name = L"VentasForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VentasForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetalleVenta))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void VentasForm_Load(System::Object^ sender, System::EventArgs^ e) {
		cargarClientes();   // 👈 aquí se ejecuta al abrir el form
		cargarProductos();
		this->dataGridViewDetalleVenta->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &Gym::VentasForm::dataGridViewVentas_CellValueChanged);
		this->dataGridViewDetalleVenta->CurrentCellDirtyStateChanged += gcnew EventHandler(this, &Gym::VentasForm::dataGridViewVentas_CurrentCellDirtyStateChanged);
		dataGridViewDetalleVenta->Columns["Cantidad"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;
		dataGridViewDetalleVenta->Columns["PrecioUnitario"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;
		dataGridViewDetalleVenta->Columns["Subtotal"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;
		//dataGridViewDetalleVenta->Columns["Producto"]->Width = 200;
		dataGridViewDetalleVenta->Columns["Producto"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
	}


		   String^ obtenerCampo(String^ jsonItem, String^ campo) {
			   // Busca "campo":"valor"
			   String^ patron = "\\\"" + campo + "\\\"\\s*:\\s*\\\"([^\\\"]*)\\\"";
			   Regex^ rx = gcnew Regex(patron);
			   Match^ m = rx->Match(jsonItem);
			   return m->Success ? m->Groups[1]->Value : "";
		   }

		   void cargarClientes() {
			   WebClient^ client = gcnew WebClient();
			   client->Encoding = System::Text::Encoding::UTF8;
			   String^ json = client->DownloadString("http://localhost/api/listar_clientes_ventas.php");
			   // MessageBox::Show(json);
			   DataTable^ dtClientes = gcnew DataTable();
			   dtClientes->Columns->Add("ClienteID", int::typeid);
			   dtClientes->Columns->Add("NombreCompleto", String::typeid);
			   dtClientes->Columns->Add("Contacto", String::typeid); // 👈 nueva columna

			   Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
			   auto matches = rx->Matches(json);

			   if (matches->Count == 0) {
				   comboBoxClientes->DataSource = nullptr;
				   comboBoxClientes->Items->Clear();
				   MessageBox::Show("No hay clientes cargados.");
				   return;
			   }

			   for each (Match ^ m in matches) {
				   String^ item = m->Value;
				   String^ idStr = obtenerCampo(item, "ClienteID");
				   String^ nombre = obtenerCampo(item, "NombreCompleto");
				   String^ contacto = obtenerCampo(item, "contacto"); // 👈 capturar contacto

				   if (idStr != "" && nombre != "") {
					   dtClientes->Rows->Add(Int32::Parse(idStr), nombre, contacto);
				   }
			   }



			   comboBoxClientes->DisplayMember = "NombreCompleto";
			   comboBoxClientes->ValueMember = "ClienteID";
			   comboBoxClientes->DataSource = dtClientes;
			   comboBoxClientes->SelectedIndex = -1;

		   }
		   void cargarProductos() {
			   WebClient^ client = gcnew WebClient();
			   client->Encoding = System::Text::Encoding::UTF8;
			   String^ json = client->DownloadString("http://localhost/api/listar_productos.php");

			   dtProductos = gcnew DataTable();   // 👈 ahora usa el miembro de clase
			   dtProductos->Columns->Add("ProductoID", int::typeid);
			   dtProductos->Columns->Add("Nombre", String::typeid);
			   dtProductos->Columns->Add("Precio", double::typeid);

			   Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
			   auto matches = rx->Matches(json);

			   for each (Match ^ m in matches) {
				   String^ item = m->Value;
				   int idProducto = Int32::Parse(obtenerCampo(item, "ProductoID"));
				   String^ nombre = obtenerCampo(item, "Nombre");
				   //double precio = Double::Parse(obtenerCampo(item, "Precio"));
				   double precio = Double::Parse(obtenerCampo(item, "Precio"), CultureInfo::InvariantCulture);

				   dtProductos->Rows->Add(idProducto, nombre, precio);
			   }

			   DataGridViewComboBoxColumn^ colProducto =
				   (DataGridViewComboBoxColumn^)dataGridViewDetalleVenta->Columns["Producto"];

			   colProducto->DataSource = dtProductos;
			   colProducto->DisplayMember = "Nombre";
			   colProducto->ValueMember = "ProductoID";
		   }
		   //-------------------------




	private: System::Void dataGridViewVentas_CurrentCellDirtyStateChanged(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridViewDetalleVenta->IsCurrentCellDirty) {
			dataGridViewDetalleVenta->CommitEdit(DataGridViewDataErrorContexts::Commit);
		}
	}





	private: System::Void dataGridViewVentas_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		DataGridViewRow^ row = dataGridViewDetalleVenta->Rows[e->RowIndex];

		// Si cambió el producto → cargar precio
		if (e->ColumnIndex == dataGridViewDetalleVenta->Columns["Producto"]->Index && row->Cells["Producto"]->Value != nullptr) {
			int productoID = Int32::Parse(row->Cells["Producto"]->Value->ToString());

			// Buscar en el DataTable dtProductos
			DataRow^ found = dtProductos->Select("ProductoID = " + productoID)[0];
			double precio = Double::Parse(found["Precio"]->ToString(), System::Globalization::CultureInfo::InvariantCulture);

			row->Cells["PrecioUnitario"]->Value = precio;
		}

		// Si cambió Cantidad o PrecioUnitario → calcular Subtotal
		if ((e->ColumnIndex == dataGridViewDetalleVenta->Columns["Cantidad"]->Index) ||
			(e->ColumnIndex == dataGridViewDetalleVenta->Columns["PrecioUnitario"]->Index)) {

			double cantidad = 0.0;
			double precio = 0.0;

			// Cantidad: si está vacía, tomar 0
			if (row->Cells["Cantidad"]->Value != nullptr && row->Cells["Cantidad"]->Value->ToString() != "")
				cantidad = Double::Parse(row->Cells["Cantidad"]->Value->ToString());

			// Precio: si está vacío, tomar 0
			if (row->Cells["PrecioUnitario"]->Value != nullptr && row->Cells["PrecioUnitario"]->Value->ToString() != "")
				precio = Double::Parse(row->Cells["PrecioUnitario"]->Value->ToString());

			// Calcular subtotal
			row->Cells["Subtotal"]->Value = cantidad * precio;
			calcularTotal();
		}
	}

	private: void calcularTotal() {
		double total = 0.0;

		for each (DataGridViewRow ^ row in dataGridViewDetalleVenta->Rows) {
			if (row->Cells["Subtotal"]->Value != nullptr && row->Cells["Subtotal"]->Value->ToString() != "") {
				double subtotal = Double::Parse(row->Cells["Subtotal"]->Value->ToString());
				total += subtotal;
			}
		}

		textBoxTotal->Text = total.ToString("N2"); // 👈 siempre con 2 decimales
	}



	private: System::Void buttonLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Limpiar todas las filas del DataGridView
		dataGridViewDetalleVenta->Rows->Clear();

		// Reiniciar el total
		textBoxTotal->Text = "0.00";
	}
	private: System::Void comboBoxClientes_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Llamar al mismo código que usa el botón Limpiar
		buttonLimpiar_Click(sender, e);
	}

	private: System::Void buttonAgregarVenta_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// 1. Armar los datos de la venta
			int clienteID = Int32::Parse(comboBoxClientes->SelectedValue->ToString());
			String^ fechaVenta = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
			String^ total = textBoxTotal->Text;

			// 2. Armar el detalle en JSON
			System::Text::StringBuilder^ sbDetalle = gcnew System::Text::StringBuilder();
			sbDetalle->Append("[");
			for each (DataGridViewRow ^ row in dataGridViewDetalleVenta->Rows) {
				if (row->Cells["Producto"]->Value != nullptr) {
					int productoID = Int32::Parse(row->Cells["Producto"]->Value->ToString());
					int cantidad = 0;
					double precioUnitario = 0.0;

					if (row->Cells["Cantidad"]->Value != nullptr)
						cantidad = Int32::Parse(row->Cells["Cantidad"]->Value->ToString());

					if (row->Cells["PrecioUnitario"]->Value != nullptr)
						precioUnitario = Double::Parse(row->Cells["PrecioUnitario"]->Value->ToString());

					// Consultar stock actual
					WebClient^ clientStock = gcnew WebClient();
					clientStock->Encoding = System::Text::Encoding::UTF8;
					String^ stockStr = clientStock->DownloadString("http://localhost/api/consultar_stock.php?ProductoID=" + productoID);
					stockStr = stockStr->Trim();

					int stockActual;
					if (!Int32::TryParse(stockStr, stockActual)) {
						MessageBox::Show("No se pudo obtener stock para ProductoID " + productoID);
						return;
					}

					if (cantidad > stockActual) {
						MessageBox::Show("Controlar Stock: ProductoID " + productoID +
							" tiene stock " + stockActual + ", cantidad solicitada " + cantidad);
						return; // 🚫 cancelar la venta
					}
					
					sbDetalle->Append("{");
					sbDetalle->AppendFormat("\"ProductoID\":{0},\"Cantidad\":{1},\"PrecioUnitario\":{2}", productoID, cantidad, precioUnitario);
					sbDetalle->Append("},");
				}
			}
			if (sbDetalle->Length > 1) sbDetalle->Length--; // quitar última coma
			sbDetalle->Append("]");

			String^ detalleJson = sbDetalle->ToString();

			// 3. Armar el cuerpo POST
			String^ postData = String::Format("ClienteID={0}&FechaVenta={1}&Total={2}&Detalle={3}",
				clienteID, fechaVenta, total, detalleJson);

			array<Byte>^ dataBytes = System::Text::Encoding::UTF8->GetBytes(postData);

			// 4. Enviar al PHP
			HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create("http://localhost/api/guardar_venta.php");
			request->Method = "POST";
			request->ContentType = "application/x-www-form-urlencoded";
			request->ContentLength = dataBytes->Length;

			System::IO::Stream^ stream = request->GetRequestStream();
			stream->Write(dataBytes, 0, dataBytes->Length);
			stream->Close();

			HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(response->GetResponseStream());
			String^ result = reader->ReadToEnd();

			MessageBox::Show("Respuesta del servidor: " + result);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al guardar la venta: " + ex->Message);
		}
	}






	private: System::Void buttonListarVentas_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si hay cliente seleccionado
		if (comboBoxClientes->SelectedValue == nullptr) {
			MessageBox::Show("Seleccione un cliente antes de listar las ventas.");
			return;
		}

		// Obtener el ClienteID desde el ValueMember
		int clienteID = Int32::Parse(comboBoxClientes->SelectedValue->ToString());

		// Crear instancia del formulario HistorialVentasForm
		HistorialVentasForm^ historialForm = gcnew HistorialVentasForm(clienteID);

		// Mostrar el formulario
		historialForm->ShowDialog();
	}

	};
}
