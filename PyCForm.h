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
	using namespace System::Windows::Forms::DataVisualization::Charting;


	/// <summary>
	/// Resumen de PyCForm
	/// </summary>
	public ref class PyCForm : public System::Windows::Forms::Form
	{
	public:
		PyCForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->Load += gcnew System::EventHandler(this, &Gym::PyCForm::PyCForm_Load);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PyCForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductoID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombreProducto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ descripcion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ precio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ stock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ categoria;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Void PyCForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Configuración columnas Clientes
		dataGridView1->Columns["ClienteID"]->Width = 80;
		dataGridView1->Columns["apellido"]->Width = 120;
		dataGridView1->Columns["nombre"]->Width = 120;
		//dataGridView1->Columns["contacto"]->Width = 200;
		dataGridView1->Columns["contacto"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;


		for each (DataGridViewColumn ^ col in dataGridView1->Columns) {
			col->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		}

		// Configuración columnas Productos
		dataGridViewProductos->Columns["ProductoID"]->Width = 50;
		//dataGridViewProductos->Columns["nombreProducto"]->Width = 160;
		dataGridViewProductos->Columns["nombreProducto"]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewProductos->Columns["descripcion"]->Width = 200;
		dataGridViewProductos->Columns["precio"]->Width = 80;
		dataGridViewProductos->Columns["stock"]->Width = 80;
		dataGridViewProductos->Columns["categoria"]->Width = 90;

		for each (DataGridViewColumn ^ col in dataGridViewProductos->Columns) {
			col->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		}
	}




	private: System::Windows::Forms::Button^ buttonAgregarCliente;
	private: System::Windows::Forms::Button^ buttonListarCliente;
	private: System::Windows::Forms::Button^ buttonEditarCliente;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ClienteID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ apellido;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contacto;
	private: System::Windows::Forms::Button^ buttonLimpiarClientes;
	private: System::Windows::Forms::DataGridView^ dataGridViewProductos;


	private: System::Windows::Forms::Button^ buttonLimpiarProductos;
	private: System::Windows::Forms::Button^ buttonEditarProducto;
	private: System::Windows::Forms::Button^ buttonListarProductos;
	private: System::Windows::Forms::Button^ buttonAgregarProducto;











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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ClienteID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->apellido = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contacto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAgregarCliente = (gcnew System::Windows::Forms::Button());
			this->buttonListarCliente = (gcnew System::Windows::Forms::Button());
			this->buttonEditarCliente = (gcnew System::Windows::Forms::Button());
			this->buttonLimpiarClientes = (gcnew System::Windows::Forms::Button());
			this->dataGridViewProductos = (gcnew System::Windows::Forms::DataGridView());
			this->buttonLimpiarProductos = (gcnew System::Windows::Forms::Button());
			this->buttonEditarProducto = (gcnew System::Windows::Forms::Button());
			this->buttonListarProductos = (gcnew System::Windows::Forms::Button());
			this->buttonAgregarProducto = (gcnew System::Windows::Forms::Button());
			this->ProductoID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nombreProducto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->descripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->precio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoria = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProductos))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(421, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(452, 53);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Productos y clientes";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ClienteID,
					this->apellido, this->nombre, this->contacto
			});
			this->dataGridView1->Location = System::Drawing::Point(56, 126);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(795, 166);
			this->dataGridView1->TabIndex = 12;
			// 
			// ClienteID
			// 
			this->ClienteID->HeaderText = L"N° cliente";
			this->ClienteID->MinimumWidth = 6;
			this->ClienteID->Name = L"ClienteID";
			this->ClienteID->ReadOnly = true;
			this->ClienteID->Width = 125;
			// 
			// apellido
			// 
			this->apellido->HeaderText = L"Apellido";
			this->apellido->MinimumWidth = 6;
			this->apellido->Name = L"apellido";
			this->apellido->Width = 125;
			// 
			// nombre
			// 
			this->nombre->HeaderText = L"Nombre";
			this->nombre->MinimumWidth = 6;
			this->nombre->Name = L"nombre";
			this->nombre->Width = 125;
			// 
			// contacto
			// 
			this->contacto->HeaderText = L"Contacto";
			this->contacto->MinimumWidth = 6;
			this->contacto->Name = L"contacto";
			this->contacto->Width = 125;
			// 
			// buttonAgregarCliente
			// 
			this->buttonAgregarCliente->Location = System::Drawing::Point(984, 126);
			this->buttonAgregarCliente->Name = L"buttonAgregarCliente";
			this->buttonAgregarCliente->Size = System::Drawing::Size(137, 62);
			this->buttonAgregarCliente->TabIndex = 14;
			this->buttonAgregarCliente->Text = L"Agregar";
			this->buttonAgregarCliente->UseVisualStyleBackColor = true;
			this->buttonAgregarCliente->Click += gcnew System::EventHandler(this, &PyCForm::buttonAgregarCliente_Click);
			// 
			// buttonListarCliente
			// 
			this->buttonListarCliente->Location = System::Drawing::Point(984, 208);
			this->buttonListarCliente->Name = L"buttonListarCliente";
			this->buttonListarCliente->Size = System::Drawing::Size(137, 62);
			this->buttonListarCliente->TabIndex = 15;
			this->buttonListarCliente->Text = L"Listar";
			this->buttonListarCliente->UseVisualStyleBackColor = true;
			this->buttonListarCliente->Click += gcnew System::EventHandler(this, &PyCForm::buttonListarCliente_Click);
			// 
			// buttonEditarCliente
			// 
			this->buttonEditarCliente->Location = System::Drawing::Point(1146, 126);
			this->buttonEditarCliente->Name = L"buttonEditarCliente";
			this->buttonEditarCliente->Size = System::Drawing::Size(137, 62);
			this->buttonEditarCliente->TabIndex = 16;
			this->buttonEditarCliente->Text = L"Editar";
			this->buttonEditarCliente->UseVisualStyleBackColor = true;
			this->buttonEditarCliente->Click += gcnew System::EventHandler(this, &PyCForm::buttonEditarCliente_Click);
			// 
			// buttonLimpiarClientes
			// 
			this->buttonLimpiarClientes->Location = System::Drawing::Point(1146, 208);
			this->buttonLimpiarClientes->Name = L"buttonLimpiarClientes";
			this->buttonLimpiarClientes->Size = System::Drawing::Size(137, 62);
			this->buttonLimpiarClientes->TabIndex = 17;
			this->buttonLimpiarClientes->Text = L"Limpiar";
			this->buttonLimpiarClientes->UseVisualStyleBackColor = true;
			this->buttonLimpiarClientes->Click += gcnew System::EventHandler(this, &PyCForm::buttonLimpiarClientes_Click);
			// 
			// dataGridViewProductos
			// 
			this->dataGridViewProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewProductos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ProductoID,
					this->nombreProducto, this->descripcion, this->precio, this->stock, this->categoria
			});
			this->dataGridViewProductos->Location = System::Drawing::Point(56, 435);
			this->dataGridViewProductos->Name = L"dataGridViewProductos";
			this->dataGridViewProductos->RowHeadersWidth = 51;
			this->dataGridViewProductos->RowTemplate->Height = 24;
			this->dataGridViewProductos->Size = System::Drawing::Size(871, 176);
			this->dataGridViewProductos->TabIndex = 18;
			// 
			// buttonLimpiarProductos
			// 
			this->buttonLimpiarProductos->Location = System::Drawing::Point(1146, 517);
			this->buttonLimpiarProductos->Name = L"buttonLimpiarProductos";
			this->buttonLimpiarProductos->Size = System::Drawing::Size(137, 62);
			this->buttonLimpiarProductos->TabIndex = 22;
			this->buttonLimpiarProductos->Text = L"Limpiar";
			this->buttonLimpiarProductos->UseVisualStyleBackColor = true;
			this->buttonLimpiarProductos->Click += gcnew System::EventHandler(this, &PyCForm::buttonLimpiarProductos_Click);
			// 
			// buttonEditarProducto
			// 
			this->buttonEditarProducto->Location = System::Drawing::Point(1146, 435);
			this->buttonEditarProducto->Name = L"buttonEditarProducto";
			this->buttonEditarProducto->Size = System::Drawing::Size(137, 62);
			this->buttonEditarProducto->TabIndex = 21;
			this->buttonEditarProducto->Text = L"Editar";
			this->buttonEditarProducto->UseVisualStyleBackColor = true;
			this->buttonEditarProducto->Click += gcnew System::EventHandler(this, &PyCForm::buttonEditarProducto_Click);
			// 
			// buttonListarProductos
			// 
			this->buttonListarProductos->Location = System::Drawing::Point(984, 517);
			this->buttonListarProductos->Name = L"buttonListarProductos";
			this->buttonListarProductos->Size = System::Drawing::Size(137, 62);
			this->buttonListarProductos->TabIndex = 20;
			this->buttonListarProductos->Text = L"Listar";
			this->buttonListarProductos->UseVisualStyleBackColor = true;
			this->buttonListarProductos->Click += gcnew System::EventHandler(this, &PyCForm::buttonListarProductos_Click);
			// 
			// buttonAgregarProducto
			// 
			this->buttonAgregarProducto->Location = System::Drawing::Point(984, 435);
			this->buttonAgregarProducto->Name = L"buttonAgregarProducto";
			this->buttonAgregarProducto->Size = System::Drawing::Size(137, 62);
			this->buttonAgregarProducto->TabIndex = 19;
			this->buttonAgregarProducto->Text = L"Agregar";
			this->buttonAgregarProducto->UseVisualStyleBackColor = true;
			this->buttonAgregarProducto->Click += gcnew System::EventHandler(this, &PyCForm::buttonAgregarProducto_Click);
			// 
			// ProductoID
			// 
			this->ProductoID->HeaderText = L"Cod. Prod.";
			this->ProductoID->MinimumWidth = 6;
			this->ProductoID->Name = L"ProductoID";
			this->ProductoID->ReadOnly = true;
			this->ProductoID->Width = 125;
			// 
			// nombreProducto
			// 
			this->nombreProducto->HeaderText = L"Nombre";
			this->nombreProducto->MinimumWidth = 6;
			this->nombreProducto->Name = L"nombreProducto";
			this->nombreProducto->Width = 125;
			// 
			// descripcion
			// 
			this->descripcion->HeaderText = L"Descripcion";
			this->descripcion->MinimumWidth = 6;
			this->descripcion->Name = L"descripcion";
			this->descripcion->Width = 125;
			// 
			// precio
			// 
			this->precio->HeaderText = L"Precio";
			this->precio->MinimumWidth = 6;
			this->precio->Name = L"precio";
			this->precio->Width = 125;
			// 
			// stock
			// 
			this->stock->HeaderText = L"Stock";
			this->stock->MinimumWidth = 6;
			this->stock->Name = L"stock";
			this->stock->Width = 125;
			// 
			// categoria
			// 
			this->categoria->HeaderText = L"Categoria";
			this->categoria->MinimumWidth = 6;
			this->categoria->Name = L"categoria";
			this->categoria->Visible = false;
			this->categoria->Width = 125;
			// 
			// PyCForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1309, 757);
			this->Controls->Add(this->buttonLimpiarProductos);
			this->Controls->Add(this->buttonEditarProducto);
			this->Controls->Add(this->buttonListarProductos);
			this->Controls->Add(this->buttonAgregarProducto);
			this->Controls->Add(this->dataGridViewProductos);
			this->Controls->Add(this->buttonLimpiarClientes);
			this->Controls->Add(this->buttonEditarCliente);
			this->Controls->Add(this->buttonListarCliente);
			this->Controls->Add(this->buttonAgregarCliente);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Name = L"PyCForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PyCForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProductos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion







	private: System::Void buttonAgregarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (dataGridView1->CurrentRow == nullptr) {
				MessageBox::Show("Selecciona o edita una fila en la grilla.");
				return;
			}

			// Tomar datos desde la fila seleccionada
			DataGridViewRow^ fila = dataGridView1->CurrentRow;

			String^ nombre = fila->Cells["nombre"]->Value != nullptr ? fila->Cells["nombre"]->Value->ToString() : "";
			String^ apellido = fila->Cells["apellido"]->Value != nullptr ? fila->Cells["apellido"]->Value->ToString() : "";
			String^ contacto = fila->Cells["contacto"]->Value != nullptr ? fila->Cells["contacto"]->Value->ToString() : "";

			if (String::IsNullOrWhiteSpace(nombre) || String::IsNullOrWhiteSpace(apellido)) {
				MessageBox::Show("Nombre y Apellido son obligatorios.");
				return;
			}

			// Preparar POST hacia PHP
			System::Net::WebClient^ client = gcnew System::Net::WebClient();
			System::Collections::Specialized::NameValueCollection^ datos =
				gcnew System::Collections::Specialized::NameValueCollection();

			datos->Add("nombre", nombre);
			datos->Add("apellido", apellido);
			datos->Add("contacto", contacto);

			String^ url = "http://localhost/api/agregar_cliente.php";

			array<Byte>^ respuesta = client->UploadValues(url, "POST", datos);
			String^ resultado = System::Text::Encoding::UTF8->GetString(respuesta);

			MessageBox::Show("Servidor respondió: " + resultado);

			// Refrescar la grilla completa desde la BDD
			//cargarClientes();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al agregar cliente: " + ex->Message);
		}
	}



	private: System::Void buttonListarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ url = "http://localhost/api/listar_clientes.php";
			HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
			request->Method = "GET";

			HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
			StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
			String^ json = reader->ReadToEnd();
			response->Close();

			dataGridView1->Rows->Clear();

			System::Text::RegularExpressions::Regex^ rx = gcnew System::Text::RegularExpressions::Regex("\\{[^\\}]+\\}");
			System::Text::RegularExpressions::MatchCollection^ matches = rx->Matches(json);

			for each (System::Text::RegularExpressions::Match ^ match in matches) {
				String^ item = match->Value;

				// Agregar fila vacía
				int rowIndex = dataGridView1->Rows->Add();

				// Asignar valores por nombre de columna
				dataGridView1->Rows[rowIndex]->Cells["ClienteID"]->Value = obtenerCampo(item, "ClienteID");
				dataGridView1->Rows[rowIndex]->Cells["apellido"]->Value = obtenerCampo(item, "Apellido");
				dataGridView1->Rows[rowIndex]->Cells["nombre"]->Value = obtenerCampo(item, "Nombre");
				dataGridView1->Rows[rowIndex]->Cells["contacto"]->Value = obtenerCampo(item, "Contacto");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al listar clientes: " + ex->Message);
		}
	}






	private: String^ obtenerCampo(String^ jsonItem, String^ campo) {
		try {
			// Patrón que acepta "campo":"valor" o "campo":valor
			String^ patron = "\\\"" + campo + "\\\":(?:\\\"([^\\\"]*)\\\"|(\\d+))";
			System::Text::RegularExpressions::Regex^ rx = gcnew System::Text::RegularExpressions::Regex(patron);
			System::Text::RegularExpressions::Match^ match = rx->Match(jsonItem);

			if (match->Success) {
				if (match->Groups[1]->Success) return match->Groups[1]->Value; // string
				if (match->Groups[2]->Success) return match->Groups[2]->Value; // número
			}
			return "";
		}
		catch (Exception^) {
			return "";
		}
	}

	private: System::Void buttonEditarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (dataGridView1->CurrentRow == nullptr) {
				MessageBox::Show("Selecciona una fila para editar.");
				return;
			}

			DataGridViewRow^ fila = dataGridView1->CurrentRow;

			String^ id = fila->Cells["ClienteID"]->Value->ToString();
			String^ nombre = fila->Cells["nombre"]->Value->ToString();
			String^ apellido = fila->Cells["apellido"]->Value->ToString();
			String^ contacto = fila->Cells["contacto"]->Value->ToString();

			System::Net::WebClient^ client = gcnew System::Net::WebClient();
			System::Collections::Specialized::NameValueCollection^ datos =
				gcnew System::Collections::Specialized::NameValueCollection();

			datos->Add("ClienteID", id);
			datos->Add("Nombre", nombre);
			datos->Add("Apellido", apellido);
			datos->Add("Contacto", contacto);

			String^ url = "http://localhost/api/editar_cliente.php";

			array<Byte>^ respuesta = client->UploadValues(url, "POST", datos);
			String^ resultado = System::Text::Encoding::UTF8->GetString(respuesta);

			MessageBox::Show("Servidor respondió: " + resultado);

			// refrescar grilla
			buttonListarCliente_Click(nullptr, nullptr);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al editar cliente: " + ex->Message);
		}
	}



	private: System::Void buttonLimpiarClientes_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Borra todas las filas del DataGridView
			dataGridView1->Rows->Clear();

			// Opcional: también podés limpiar la selección
			dataGridView1->ClearSelection();

			MessageBox::Show("La grilla de clientes fue limpiada correctamente.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al limpiar clientes: " + ex->Message);
		}
	}
		   //-------------------------------------
		   // PRODUCTO
		   //---------------------------------
	private: System::Void buttonAgregarProducto_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (dataGridViewProductos->CurrentRow == nullptr) {
				MessageBox::Show("Selecciona una fila para agregar producto.");
				return;
			}

			DataGridViewRow^ fila = dataGridViewProductos->CurrentRow;

			String^ nombreProducto = fila->Cells["nombreProducto"]->Value->ToString();
			String^ descripcion = fila->Cells["descripcion"]->Value->ToString();
			String^ precio = fila->Cells["precio"]->Value->ToString();
			String^ stock = fila->Cells["stock"]->Value->ToString();
			//String^ categoria = fila->Cells["categoria"]->Value->ToString();

			System::Net::WebClient^ client = gcnew System::Net::WebClient();
			System::Collections::Specialized::NameValueCollection^ datos =
				gcnew System::Collections::Specialized::NameValueCollection();

			datos->Add("Nombre", nombreProducto);
			datos->Add("Descripcion", descripcion);
			datos->Add("Precio", precio);
			datos->Add("Stock", stock);
			//datos->Add("Categoria", categoria);

			String^ url = "http://localhost/api/agregar_producto.php";

			array<Byte>^ respuesta = client->UploadValues(url, "POST", datos);
			String^ resultado = System::Text::Encoding::UTF8->GetString(respuesta);

			MessageBox::Show("Servidor respondió: " + resultado);

			// refrescar grilla si tenés un botón listar
			// buttonListarProductos_Click(nullptr, nullptr);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al agregar producto: " + ex->Message);
		}
	}


	private: System::Void buttonListarProductos_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ url = "http://localhost/api/listar_productos.php";
			HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
			request->Method = "GET";

			HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
			StreamReader^ reader = gcnew StreamReader(response->GetResponseStream());
			String^ json = reader->ReadToEnd();
			response->Close();

			dataGridViewProductos->Rows->Clear();

			// Capturar cada objeto JSON { ... }
			System::Text::RegularExpressions::Regex^ rx = gcnew System::Text::RegularExpressions::Regex("\\{[^\\}]+\\}");
			System::Text::RegularExpressions::MatchCollection^ matches = rx->Matches(json);

			for each (System::Text::RegularExpressions::Match ^ match in matches) {
				String^ item = match->Value;

				int rowIndex = dataGridViewProductos->Rows->Add();

				// Asignar valores por nombre de columna
				dataGridViewProductos->Rows[rowIndex]->Cells["ProductoID"]->Value = obtenerCampo(item, "ProductoID");
				dataGridViewProductos->Rows[rowIndex]->Cells["nombreProducto"]->Value = obtenerCampo(item, "Nombre");
				dataGridViewProductos->Rows[rowIndex]->Cells["descripcion"]->Value = obtenerCampo(item, "Descripcion");
				dataGridViewProductos->Rows[rowIndex]->Cells["precio"]->Value = obtenerCampo(item, "Precio");
				dataGridViewProductos->Rows[rowIndex]->Cells["stock"]->Value = obtenerCampo(item, "Stock");
				//dataGridViewProductos->Rows[rowIndex]->Cells["categoria"]->Value = obtenerCampo(item, "Categoria");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al listar productos: " + ex->Message);
		}
	}
	private: System::Void buttonLimpiarProductos_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Borra todas las filas del DataGridView de productos
			dataGridViewProductos->Rows->Clear();

			// Opcional: limpiar selección para que no quede ninguna fila marcada
			dataGridViewProductos->ClearSelection();

			MessageBox::Show("La grilla de productos fue limpiada correctamente.");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al limpiar productos: " + ex->Message);
		}
	}

	private: System::Void buttonEditarProducto_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (dataGridViewProductos->CurrentRow == nullptr) {
				MessageBox::Show("Selecciona una fila para editar.");
				return;
			}

			DataGridViewRow^ fila = dataGridViewProductos->CurrentRow;

			String^ id = fila->Cells["ProductoID"]->Value->ToString();
			String^ nombre = fila->Cells["nombreProducto"]->Value->ToString();
			String^ descripcion = fila->Cells["descripcion"]->Value->ToString();
			String^ precio = fila->Cells["precio"]->Value->ToString();
			String^ stock = fila->Cells["stock"]->Value->ToString();
			//String^ categoria = fila->Cells["categoria"]->Value->ToString();

			System::Net::WebClient^ client = gcnew System::Net::WebClient();
			System::Collections::Specialized::NameValueCollection^ datos =
				gcnew System::Collections::Specialized::NameValueCollection();

			datos->Add("ProductoID", id);
			datos->Add("Nombre", nombre);
			datos->Add("Descripcion", descripcion);
			datos->Add("Precio", precio);
			datos->Add("Stock", stock);
			//datos->Add("Categoria", categoria);

			String^ url = "http://localhost/api/editar_producto.php";

			array<Byte>^ respuesta = client->UploadValues(url, "POST", datos);
			String^ resultado = System::Text::Encoding::UTF8->GetString(respuesta);

			MessageBox::Show("Servidor respondió: " + resultado);

			// refrescar grilla
			buttonListarProductos_Click(nullptr, nullptr);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al editar producto: " + ex->Message);
		}
	}

		   //-------------------------------------------------------------------------



	};
}
