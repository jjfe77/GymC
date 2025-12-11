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
	/// Resumen de ProgresoForm
	/// </summary>
	
	
	public ref class ProgresoForm : public System::Windows::Forms::Form
	{
	public:
		ProgresoForm(void)
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
		~ProgresoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridHistorial;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartProgreso;

	protected:

	private:

	private:
		int idAlumno;

	public:
		ProgresoForm(int id) {
			InitializeComponent();
			idAlumno = id;
			cargarHistorial();
		}
		//-----------------------------------------------

		


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridHistorial = (gcnew System::Windows::Forms::DataGridView());
			this->chartProgreso = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridHistorial))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartProgreso))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(830, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(214, 53);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Progreso";
			// 
			// dataGridHistorial
			// 
			this->dataGridHistorial->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridHistorial->Location = System::Drawing::Point(57, 104);
			this->dataGridHistorial->Name = L"dataGridHistorial";
			this->dataGridHistorial->RowHeadersWidth = 51;
			this->dataGridHistorial->RowTemplate->Height = 24;
			this->dataGridHistorial->Size = System::Drawing::Size(973, 439);
			this->dataGridHistorial->TabIndex = 11;
			// 
			// chartProgreso
			// 
			chartArea2->Name = L"ChartArea1";
			this->chartProgreso->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chartProgreso->Legends->Add(legend2);
			this->chartProgreso->Location = System::Drawing::Point(57, 565);
			this->chartProgreso->Name = L"chartProgreso";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chartProgreso->Series->Add(series2);
			this->chartProgreso->Size = System::Drawing::Size(162, 103);
			this->chartProgreso->TabIndex = 12;
			this->chartProgreso->Text = L"chart1";
			this->chartProgreso->Visible = false;
			// 
			// ProgresoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1094, 680);
			this->Controls->Add(this->chartProgreso);
			this->Controls->Add(this->dataGridHistorial);
			this->Controls->Add(this->label2);
			this->Name = L"ProgresoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ProgresoForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridHistorial))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartProgreso))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void cargarHistorial() {
			WebClient^ client = gcnew WebClient();
			client->Encoding = System::Text::Encoding::UTF8;

			String^ url = "http://localhost/api/ver_progreso.php?id_alumno=" + idAlumno;
			String^ json = client->DownloadString(url);

			DataTable^ dt = gcnew DataTable();
			dt->Columns->Add("fecha", String::typeid);
			dt->Columns->Add("ejercicio", String::typeid);
			dt->Columns->Add("series_plan", int::typeid);
			dt->Columns->Add("repes_plan", int::typeid);
			dt->Columns->Add("carga_plan", double::typeid);
			dt->Columns->Add("series_real", int::typeid);
			dt->Columns->Add("repes_real", int::typeid);
			dt->Columns->Add("carga_real", double::typeid);

			/*dt->Columns->Add("series_plan", int::typeid);
			dt->Columns->Add("series_real", int::typeid);
			dt->Columns->Add("repes_plan", int::typeid);
			dt->Columns->Add("repes_real", int::typeid);
			dt->Columns->Add("carga_plan", double::typeid);
			dt->Columns->Add("carga_real", double::typeid);*/

			Regex^ rx = gcnew Regex("\\{[^\\}]+\\}");
			auto matches = rx->Matches(json);

			for each (Match ^ m in matches) {
				String^ item = m->Value;

				String^ fecha = obtenerCampo(item, "fecha");
				String^ ejercicio = obtenerCampo(item, "ejercicio");

				int sp = safeParseInt(obtenerCampo(item, "series_plan"));
				int sr = safeParseInt(obtenerCampo(item, "series_real"));
				int rp = safeParseInt(obtenerCampo(item, "repes_plan"));
				int rr = safeParseInt(obtenerCampo(item, "repes_real"));
				double cp = safeParseDouble(obtenerCampo(item, "carga_plan"));
				double cr = safeParseDouble(obtenerCampo(item, "carga_real"));

				/*int sp = safeParseInt(obtenerCampo(item, "series_plan"));
				int sr = safeParseInt(obtenerCampo(item, "series_real"));
				int rp = safeParseInt(obtenerCampo(item, "repes_plan"));
				int rr = safeParseInt(obtenerCampo(item, "repes_real"));
				double cp = safeParseDouble(obtenerCampo(item, "carga_plan"));
				double cr = safeParseDouble(obtenerCampo(item, "carga_real"));*/

				dt->Rows->Add(fecha, ejercicio, sp,rp, cp,sr,  rr,  cr);
			}

			dataGridHistorial->DataSource = dt;
			/*
			this->dataGridHistorial->Columns["fecha"]->Width = 100;
			this->dataGridHistorial->Columns["ejercicio"]->Width = 150;
			this->dataGridHistorial->Columns["series_plan"]->Width = 80;
			this->dataGridHistorial->Columns["series_real"]->Width = 80;
			this->dataGridHistorial->Columns["carga_plan"]->Width = 90;
			this->dataGridHistorial->Columns["carga_real"]->Width = 90;*/

			// Ejemplo: ajustar ancho de columnas
			dataGridHistorial->Columns["fecha"]->Width = 90;
			dataGridHistorial->Columns["ejercicio"]->Width = 150;
			dataGridHistorial->Columns["series_plan"]->Width = 60;
			dataGridHistorial->Columns["series_real"]->Width = 60;
			dataGridHistorial->Columns["repes_plan"]->Width = 60;
			dataGridHistorial->Columns["repes_real"]->Width = 60;
			dataGridHistorial->Columns["carga_plan"]->Width = 90;
			dataGridHistorial->Columns["carga_real"]->Width = 90;

			// Centrar texto en columnas numéricas
			dataGridHistorial->Columns["series_plan"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridHistorial->Columns["series_real"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridHistorial->Columns["repes_plan"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridHistorial->Columns["repes_real"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridHistorial->Columns["carga_plan"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
			dataGridHistorial->Columns["carga_real"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;

			dataGridHistorial->Sort(dataGridHistorial->Columns["ejercicio"],
				System::ComponentModel::ListSortDirection::Ascending);


			dataGridHistorial->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;


			chartProgreso->Series->Clear();
			Series^ plan = gcnew Series("Planificado");
			plan->ChartType = SeriesChartType::Line;
			plan->BorderWidth = 2;
			plan->Color = Color::Blue;

			Series^ real = gcnew Series("Realizado");
			real->ChartType = SeriesChartType::Line;
			real->BorderWidth = 2;
			real->Color = Color::Green;

			for each (DataRow ^ row in dt->Rows) {
				DateTime fecha = DateTime::Parse(row["fecha"]->ToString(), System::Globalization::CultureInfo::InvariantCulture);
				double cargaPlan = (double)row["carga_plan"];
				double cargaReal = (double)row["carga_real"];
				/*
				plan->Points->AddXY(fecha, cargaPlan);
				real->Points->AddXY(fecha, cargaReal);
				chartProgreso->ChartAreas[0]->AxisX->Interval = 2;*/


				plan->ChartType = SeriesChartType::Bar;
				real->ChartType = SeriesChartType::Bar;

			}

			chartProgreso->Series->Add(plan);
			chartProgreso->Series->Add(real);
			chartProgreso->ChartAreas[0]->AxisX->LabelStyle->Format = "dd/MM";
		}

		String^ obtenerCampo(String^ jsonItem, String^ campo) {
			// Busca el patrón "campo":"valor"
			String^ patron = "\\\"" + campo + "\\\":\\\"([^\\\"]+)\\\"";
			Regex^ rx = gcnew Regex(patron);
			Match^ m = rx->Match(jsonItem);

			if (m->Success) {
				return m->Groups[1]->Value;
			}

			// Si no lo encuentra, intenta con números (sin comillas)
			patron = "\\\"" + campo + "\\\":([^,\\}\\\"]+)";
			rx = gcnew Regex(patron);
			m = rx->Match(jsonItem);

			if (m->Success) {
				return m->Groups[1]->Value;
			}

			return "";
		}

		int safeParseInt(String^ valor) {
			int result = 0;
			if (!String::IsNullOrEmpty(valor)) {
				Int32::TryParse(valor, result);
			}
			return result;
		}

		double safeParseDouble(String^ valor) {
			double result = 0.0;
			if (!String::IsNullOrEmpty(valor)) {
				System::Globalization::CultureInfo^ inv = System::Globalization::CultureInfo::InvariantCulture;
				Double::TryParse(valor, System::Globalization::NumberStyles::Any, inv, result);
			}
			return result;
		}



	};
}
