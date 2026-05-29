#pragma once
#include "Conexion.h"
#include "ControladorTaller.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;
	using namespace MySql::Data::MySqlClient;

	public ref class FormFacturacion : public System::Windows::Forms::Form
	{
	public:
		FormFacturacion(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormFacturacion::FormFacturacion_Load);
		}

	protected:
		~FormFacturacion()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Panel^ panelIzquierdo;
		System::Windows::Forms::Panel^ panelDerecho;
		System::Windows::Forms::TextBox^ txtIdServicio;
		System::Windows::Forms::ComboBox^ cmbServicio;
		System::Windows::Forms::TextBox^ txtCliente;
		System::Windows::Forms::TextBox^ txtVehiculo;
		System::Windows::Forms::TextBox^ txtTipoServicio;
		System::Windows::Forms::TextBox^ txtMecanico;
		System::Windows::Forms::TextBox^ txtTotalServicio;
		System::Windows::Forms::TextBox^ txtDescuento;
		System::Windows::Forms::ComboBox^ cmbMetodoPago;
		System::Windows::Forms::TextBox^ txtObservacion;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblServicio;
		System::Windows::Forms::Label^ lblCliente;
		System::Windows::Forms::Label^ lblVehiculo;
		System::Windows::Forms::Label^ lblTipoServicio;
		System::Windows::Forms::Label^ lblMecanico;
		System::Windows::Forms::Label^ lblTotalServicio;
		System::Windows::Forms::Label^ lblDescuento;
		System::Windows::Forms::Label^ lblMetodoPago;
		System::Windows::Forms::Label^ lblObservacion;
		System::Windows::Forms::Button^ btnCargarServicio;
		System::Windows::Forms::Button^ btnGenerarFactura;
		System::Windows::Forms::Button^ btnExportarPdf;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnRegresar;
		System::Windows::Forms::DataGridView^ dgvFacturas;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Drawing::Printing::PrintDocument^ documentoFactura;
		System::Data::DataTable^ datosFacturaPdf;
		System::Data::DataTable^ detalleFacturaPdf;
		int filaDetallePdf;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelIzquierdo = gcnew System::Windows::Forms::Panel();
			this->panelDerecho = gcnew System::Windows::Forms::Panel();
			this->txtIdServicio = gcnew System::Windows::Forms::TextBox();
			this->cmbServicio = gcnew System::Windows::Forms::ComboBox();
			this->txtCliente = gcnew System::Windows::Forms::TextBox();
			this->txtVehiculo = gcnew System::Windows::Forms::TextBox();
			this->txtTipoServicio = gcnew System::Windows::Forms::TextBox();
			this->txtMecanico = gcnew System::Windows::Forms::TextBox();
			this->txtTotalServicio = gcnew System::Windows::Forms::TextBox();
			this->txtDescuento = gcnew System::Windows::Forms::TextBox();
			this->cmbMetodoPago = gcnew System::Windows::Forms::ComboBox();
			this->txtObservacion = gcnew System::Windows::Forms::TextBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblServicio = gcnew System::Windows::Forms::Label();
			this->lblCliente = gcnew System::Windows::Forms::Label();
			this->lblVehiculo = gcnew System::Windows::Forms::Label();
			this->lblTipoServicio = gcnew System::Windows::Forms::Label();
			this->lblMecanico = gcnew System::Windows::Forms::Label();
			this->lblTotalServicio = gcnew System::Windows::Forms::Label();
			this->lblDescuento = gcnew System::Windows::Forms::Label();
			this->lblMetodoPago = gcnew System::Windows::Forms::Label();
			this->lblObservacion = gcnew System::Windows::Forms::Label();
			this->btnCargarServicio = gcnew System::Windows::Forms::Button();
			this->btnGenerarFactura = gcnew System::Windows::Forms::Button();
			this->btnExportarPdf = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvFacturas = gcnew System::Windows::Forms::DataGridView();
			this->dgvDetalle = gcnew System::Windows::Forms::DataGridView();
			this->documentoFactura = gcnew System::Drawing::Printing::PrintDocument();
			this->SuspendLayout();

			this->Text = L"Modulo Facturacion";
			this->ClientSize = System::Drawing::Size(1180, 700);
			this->MinimumSize = System::Drawing::Size(980, 560);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

			this->panelIzquierdo->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelIzquierdo->Width = 500;
			this->panelIzquierdo->Padding = System::Windows::Forms::Padding(30);
			this->panelIzquierdo->AutoScroll = true;
			this->panelDerecho->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDerecho->Padding = System::Windows::Forms::Padding(20);

			this->txtIdServicio->Visible = false;
			this->lblTitulo->Text = L"Facturacion";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(30, 25);
			this->lblTitulo->AutoSize = true;

			this->lblServicio->Text = L"Orden:";
			this->lblServicio->Location = System::Drawing::Point(35, 90);
			this->lblServicio->AutoSize = true;
			this->cmbServicio->Location = System::Drawing::Point(165, 85);
			this->cmbServicio->Size = System::Drawing::Size(300, 25);
			this->cmbServicio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->btnCargarServicio->Text = L"Cargar orden";
			this->btnCargarServicio->Location = System::Drawing::Point(165, 120);
			this->btnCargarServicio->Size = System::Drawing::Size(300, 34);
			this->btnCargarServicio->Click += gcnew System::EventHandler(this, &FormFacturacion::btnCargarServicio_Click);

			this->lblCliente->Text = L"Cliente:";
			this->lblCliente->Location = System::Drawing::Point(35, 175);
			this->lblCliente->AutoSize = true;
			this->txtCliente->Location = System::Drawing::Point(165, 170);
			this->txtCliente->Size = System::Drawing::Size(300, 25);
			this->txtCliente->ReadOnly = true;

			this->lblVehiculo->Text = L"Vehiculo:";
			this->lblVehiculo->Location = System::Drawing::Point(35, 215);
			this->lblVehiculo->AutoSize = true;
			this->txtVehiculo->Location = System::Drawing::Point(165, 210);
			this->txtVehiculo->Size = System::Drawing::Size(300, 25);
			this->txtVehiculo->ReadOnly = true;

			this->lblTipoServicio->Text = L"Servicio:";
			this->lblTipoServicio->Location = System::Drawing::Point(35, 255);
			this->lblTipoServicio->AutoSize = true;
			this->txtTipoServicio->Location = System::Drawing::Point(165, 250);
			this->txtTipoServicio->Size = System::Drawing::Size(300, 25);
			this->txtTipoServicio->ReadOnly = true;

			this->lblMecanico->Text = L"Mecanico:";
			this->lblMecanico->Location = System::Drawing::Point(35, 295);
			this->lblMecanico->AutoSize = true;
			this->txtMecanico->Location = System::Drawing::Point(165, 290);
			this->txtMecanico->Size = System::Drawing::Size(300, 25);
			this->txtMecanico->ReadOnly = true;

			this->lblTotalServicio->Text = L"Subtotal:";
			this->lblTotalServicio->Location = System::Drawing::Point(35, 335);
			this->lblTotalServicio->AutoSize = true;
			this->txtTotalServicio->Location = System::Drawing::Point(165, 330);
			this->txtTotalServicio->Size = System::Drawing::Size(130, 25);
			this->txtTotalServicio->ReadOnly = true;

			this->lblDescuento->Text = L"Descuento:";
			this->lblDescuento->Location = System::Drawing::Point(35, 375);
			this->lblDescuento->AutoSize = true;
			this->txtDescuento->Location = System::Drawing::Point(165, 370);
			this->txtDescuento->Size = System::Drawing::Size(130, 25);
			this->txtDescuento->Text = L"0";

			this->lblMetodoPago->Text = L"Pago:";
			this->lblMetodoPago->Location = System::Drawing::Point(35, 415);
			this->lblMetodoPago->AutoSize = true;
			this->cmbMetodoPago->Location = System::Drawing::Point(165, 410);
			this->cmbMetodoPago->Size = System::Drawing::Size(200, 25);
			this->cmbMetodoPago->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbMetodoPago->Items->Add(L"Efectivo");
			this->cmbMetodoPago->Items->Add(L"Tarjeta");
			this->cmbMetodoPago->Items->Add(L"Transferencia");
			this->cmbMetodoPago->Items->Add(L"Credito");
			this->cmbMetodoPago->SelectedIndex = 0;

			this->lblObservacion->Text = L"Observacion:";
			this->lblObservacion->Location = System::Drawing::Point(35, 455);
			this->lblObservacion->AutoSize = true;
			this->txtObservacion->Location = System::Drawing::Point(165, 450);
			this->txtObservacion->Size = System::Drawing::Size(300, 75);
			this->txtObservacion->Multiline = true;

			this->btnGenerarFactura->Text = L"Generar factura";
			this->btnGenerarFactura->Location = System::Drawing::Point(35, 550);
			this->btnGenerarFactura->Size = System::Drawing::Size(135, 38);
			this->btnGenerarFactura->Click += gcnew System::EventHandler(this, &FormFacturacion::btnGenerarFactura_Click);

			this->btnExportarPdf->Text = L"Exportar PDF";
			this->btnExportarPdf->Location = System::Drawing::Point(185, 550);
			this->btnExportarPdf->Size = System::Drawing::Size(135, 38);
			this->btnExportarPdf->Click += gcnew System::EventHandler(this, &FormFacturacion::btnExportarPdf_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(335, 550);
			this->btnLimpiar->Size = System::Drawing::Size(135, 38);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormFacturacion::btnLimpiar_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(165, 600);
			this->btnRegresar->Size = System::Drawing::Size(300, 38);
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormFacturacion::btnRegresar_Click);

			this->documentoFactura->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &FormFacturacion::documentoFactura_PrintPage);

			this->dgvFacturas->Location = System::Drawing::Point(20, 30);
			this->dgvFacturas->Size = System::Drawing::Size(630, 300);
			this->dgvFacturas->ReadOnly = true;
			this->dgvFacturas->AllowUserToAddRows = false;
			this->dgvFacturas->AllowUserToDeleteRows = false;
			this->dgvFacturas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvFacturas->MultiSelect = false;
			this->dgvFacturas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvFacturas->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvFacturas->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvFacturas->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormFacturacion::dgvFacturas_CellClick);

			this->dgvDetalle->Location = System::Drawing::Point(20, 355);
			this->dgvDetalle->Size = System::Drawing::Size(630, 280);
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->AllowUserToAddRows = false;
			this->dgvDetalle->AllowUserToDeleteRows = false;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDetalle->MultiSelect = false;
			this->dgvDetalle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvDetalle->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvDetalle->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));

			this->panelIzquierdo->Controls->Add(this->txtIdServicio);
			this->panelIzquierdo->Controls->Add(this->lblTitulo);
			this->panelIzquierdo->Controls->Add(this->lblServicio);
			this->panelIzquierdo->Controls->Add(this->cmbServicio);
			this->panelIzquierdo->Controls->Add(this->btnCargarServicio);
			this->panelIzquierdo->Controls->Add(this->lblCliente);
			this->panelIzquierdo->Controls->Add(this->txtCliente);
			this->panelIzquierdo->Controls->Add(this->lblVehiculo);
			this->panelIzquierdo->Controls->Add(this->txtVehiculo);
			this->panelIzquierdo->Controls->Add(this->lblTipoServicio);
			this->panelIzquierdo->Controls->Add(this->txtTipoServicio);
			this->panelIzquierdo->Controls->Add(this->lblMecanico);
			this->panelIzquierdo->Controls->Add(this->txtMecanico);
			this->panelIzquierdo->Controls->Add(this->lblTotalServicio);
			this->panelIzquierdo->Controls->Add(this->txtTotalServicio);
			this->panelIzquierdo->Controls->Add(this->lblDescuento);
			this->panelIzquierdo->Controls->Add(this->txtDescuento);
			this->panelIzquierdo->Controls->Add(this->lblMetodoPago);
			this->panelIzquierdo->Controls->Add(this->cmbMetodoPago);
			this->panelIzquierdo->Controls->Add(this->lblObservacion);
			this->panelIzquierdo->Controls->Add(this->txtObservacion);
			this->panelIzquierdo->Controls->Add(this->btnGenerarFactura);
			this->panelIzquierdo->Controls->Add(this->btnExportarPdf);
			this->panelIzquierdo->Controls->Add(this->btnLimpiar);
			this->panelIzquierdo->Controls->Add(this->btnRegresar);
			this->panelDerecho->Controls->Add(this->dgvFacturas);
			this->panelDerecho->Controls->Add(this->dgvDetalle);
			this->Controls->Add(this->panelDerecho);
			this->Controls->Add(this->panelIzquierdo);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormFacturacion_Load(System::Object^ sender, System::EventArgs^ e)
		{
			ControladorTaller^ controlador = gcnew ControladorTaller();
			controlador->CrearTablaFacturasSiNoExiste();
			CargarServiciosFacturables();
			ListarFacturas();
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void OcultarColumna(System::Windows::Forms::DataGridView^ grid, String^ columna)
		{
			if (grid->Columns->Contains(columna)) grid->Columns[columna]->Visible = false;
		}

		void Encabezado(System::Windows::Forms::DataGridView^ grid, String^ columna, String^ texto)
		{
			if (grid->Columns->Contains(columna)) grid->Columns[columna]->HeaderText = texto;
		}

		void FormatearFacturas()
		{
			OcultarColumna(dgvFacturas, "id_factura");
			OcultarColumna(dgvFacturas, "id_servicio");
			Encabezado(dgvFacturas, "fecha", "Fecha");
			Encabezado(dgvFacturas, "cliente", "Cliente");
			Encabezado(dgvFacturas, "placa", "Placa");
			Encabezado(dgvFacturas, "servicio", "Servicio");
			Encabezado(dgvFacturas, "subtotal", "Subtotal");
			Encabezado(dgvFacturas, "descuento", "Descuento");
			Encabezado(dgvFacturas, "total", "Total");
			Encabezado(dgvFacturas, "metodo_pago", "Pago");
			Encabezado(dgvFacturas, "estado", "Estado");
			Encabezado(dgvFacturas, "observacion", "Observacion");
			dgvFacturas->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
		}

		void FormatearDetalle()
		{
			OcultarColumna(dgvDetalle, "id_detalle");
			Encabezado(dgvDetalle, "repuesto", "Repuesto");
			Encabezado(dgvDetalle, "cantidad", "Cantidad");
			Encabezado(dgvDetalle, "descripcion_trabajo", "Trabajo realizado");
			Encabezado(dgvDetalle, "costo_mano_obra", "Mano de obra");
			Encabezado(dgvDetalle, "observacion", "Observacion");
			Encabezado(dgvDetalle, "subtotal", "Subtotal");
			dgvDetalle->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
		}

		String^ TextoDato(System::Data::DataRow^ fila, String^ columna)
		{
			if (fila == nullptr || fila->Table == nullptr || !fila->Table->Columns->Contains(columna))
			{
				return "";
			}
			Object^ valor = fila[columna];
			if (valor == nullptr || valor == System::DBNull::Value)
			{
				return "";
			}
			return valor->ToString();
		}

		String^ TextoMoneda(Object^ valor)
		{
			if (valor == nullptr || valor == System::DBNull::Value)
			{
				return "Q0.00";
			}
			return "Q" + Convert::ToDecimal(valor).ToString("0.00");
		}

		String^ TextoFecha(Object^ valor)
		{
			if (valor == nullptr || valor == System::DBNull::Value)
			{
				return "";
			}
			DateTime fecha;
			if (DateTime::TryParse(valor->ToString(), fecha))
			{
				return fecha.ToString("dd/MM/yyyy HH:mm");
			}
			return valor->ToString();
		}

		String^ ObtenerImpresoraPdf()
		{
			for each (String^ impresora in System::Drawing::Printing::PrinterSettings::InstalledPrinters)
			{
				if (String::Compare(impresora, "Microsoft Print to PDF", true) == 0)
				{
					return impresora;
				}
			}
			for each (String^ impresora in System::Drawing::Printing::PrinterSettings::InstalledPrinters)
			{
				if (impresora->ToUpper()->Contains("PDF"))
				{
					return impresora;
				}
			}
			return "";
		}

		System::Data::DataTable^ CargarDatosFacturaPdf(int idFactura)
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT f.id_factura, f.id_servicio, f.fecha, f.subtotal, f.descuento, f.total, "
					"f.metodo_pago, f.estado, f.observacion, "
					"c.nit, c.nombre AS cliente, c.telefono, c.direccion, "
					"v.placa, v.marca, v.modelo, ts.tipo AS servicio, m.nombre AS mecanico, "
					"s.kilometraje, s.descripcion AS problema "
					"FROM facturas f INNER JOIN servicios s ON f.id_servicio=s.id_servicio "
					"INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
					"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
					"INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio "
					"INNER JOIN mecanico m ON s.id_mecanico=m.id_mecanico "
					"WHERE f.id_factura=@factura";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@factura", idFactura);
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				if (dt->Rows->Count == 0)
				{
					throw gcnew Exception("No se encontro la factura seleccionada.");
				}
				return dt;
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Data::DataTable^ CargarDetalleFacturaPdf(int idServicio)
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT IFNULL(r.nombre,'Servicio') AS repuesto, d.cantidad, d.descripcion_trabajo, "
					"d.costo_mano_obra, d.observacion, "
					"((IFNULL(r.precio,0) * IFNULL(d.cantidad,0)) + IFNULL(d.costo_mano_obra,0)) AS subtotal "
					"FROM detalletrabajo d LEFT JOIN repuestos r ON d.id_repuesto=r.id_repuesto "
					"WHERE d.id_servicio=@servicio ORDER BY d.id_detalle ASC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@servicio", idServicio);
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				return dt;
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		int ObtenerIdFacturaPorServicio(MySqlConnection^ cn, int idServicio)
		{
			MySqlCommand^ cmd = gcnew MySqlCommand("SELECT id_factura FROM facturas WHERE id_servicio=@servicio", cn);
			cmd->Parameters->AddWithValue("@servicio", idServicio);
			Object^ valor = cmd->ExecuteScalar();
			if (valor == nullptr || valor == System::DBNull::Value)
			{
				return 0;
			}
			return Convert::ToInt32(valor);
		}

		void ExportarFacturaPdf(int idFactura)
		{
			String^ impresoraPdf = ObtenerImpresoraPdf();
			if (String::IsNullOrWhiteSpace(impresoraPdf))
			{
				System::Windows::Forms::MessageBox::Show("No se encontro una impresora PDF instalada. Active 'Microsoft Print to PDF' en Windows.");
				return;
			}

			datosFacturaPdf = CargarDatosFacturaPdf(idFactura);
			int idServicio = Convert::ToInt32(datosFacturaPdf->Rows[0]["id_servicio"]);
			detalleFacturaPdf = CargarDetalleFacturaPdf(idServicio);
			filaDetallePdf = 0;

			System::Windows::Forms::SaveFileDialog^ guardar = gcnew System::Windows::Forms::SaveFileDialog();
			guardar->Title = "Guardar factura PDF";
			guardar->Filter = "Archivo PDF (*.pdf)|*.pdf";
			guardar->FileName = "Factura_" + idFactura.ToString() + ".pdf";
			guardar->OverwritePrompt = true;

			if (guardar->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}

			documentoFactura->DocumentName = "Factura " + idFactura.ToString();
			documentoFactura->PrinterSettings->PrinterName = impresoraPdf;
			documentoFactura->PrinterSettings->PrintToFile = true;
			documentoFactura->PrinterSettings->PrintFileName = guardar->FileName;
			documentoFactura->DefaultPageSettings->Margins = gcnew System::Drawing::Printing::Margins(50, 50, 50, 50);
			documentoFactura->PrintController = gcnew System::Drawing::Printing::StandardPrintController();
			documentoFactura->Print();

			System::Windows::Forms::MessageBox::Show("PDF generado correctamente:\n" + guardar->FileName);
		}

		void DibujarTexto(System::Drawing::Graphics^ g, String^ texto, System::Drawing::Font^ fuente, System::Drawing::Brush^ brocha, int x, int y, int ancho, int alto, System::Drawing::StringFormat^ formato)
		{
			g->DrawString(texto, fuente, brocha, System::Drawing::RectangleF((float)x, (float)y, (float)ancho, (float)alto), formato);
		}

		void documentoFactura_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e)
		{
			if (datosFacturaPdf == nullptr || datosFacturaPdf->Rows->Count == 0)
			{
				e->HasMorePages = false;
				return;
			}

			System::Data::DataRow^ factura = datosFacturaPdf->Rows[0];
			System::Drawing::Graphics^ g = e->Graphics;
			int x = e->MarginBounds.Left;
			int y = e->MarginBounds.Top;
			int ancho = e->MarginBounds.Width;
			int fondo = e->MarginBounds.Bottom;

			System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Segoe UI", 18, System::Drawing::FontStyle::Bold);
			System::Drawing::Font^ fuenteSubtitulo = gcnew System::Drawing::Font("Segoe UI", 11, System::Drawing::FontStyle::Bold);
			System::Drawing::Font^ fuenteNormal = gcnew System::Drawing::Font("Segoe UI", 9);
			System::Drawing::Font^ fuenteNegrita = gcnew System::Drawing::Font("Segoe UI", 9, System::Drawing::FontStyle::Bold);
			System::Drawing::Font^ fuentePequena = gcnew System::Drawing::Font("Segoe UI", 8);
			System::Drawing::StringFormat^ derecha = gcnew System::Drawing::StringFormat();
			derecha->Alignment = System::Drawing::StringAlignment::Far;
			System::Drawing::StringFormat^ centro = gcnew System::Drawing::StringFormat();
			centro->Alignment = System::Drawing::StringAlignment::Center;
			System::Drawing::StringFormat^ cortar = gcnew System::Drawing::StringFormat();
			cortar->Trimming = System::Drawing::StringTrimming::EllipsisWord;
			cortar->FormatFlags = System::Drawing::StringFormatFlags::LineLimit;

			g->DrawString("TALLER MECANICO", fuenteTitulo, System::Drawing::Brushes::Black, (float)x, (float)y);
			DibujarTexto(g, "FACTURA No. " + TextoDato(factura, "id_factura"), fuenteSubtitulo, System::Drawing::Brushes::Black, x, y + 5, ancho, 25, derecha);
			y += 38;
			g->DrawString("Control de recepcion, reparacion y mantenimiento", fuentePequena, System::Drawing::Brushes::DimGray, (float)x, (float)y);
			DibujarTexto(g, "Fecha: " + TextoFecha(factura["fecha"]), fuenteNormal, System::Drawing::Brushes::Black, x, y, ancho, 22, derecha);
			y += 35;
			g->DrawLine(System::Drawing::Pens::Black, x, y, x + ancho, y);
			y += 15;

			g->DrawString("Cliente", fuenteSubtitulo, System::Drawing::Brushes::Black, (float)x, (float)y);
			g->DrawString("Vehiculo / Orden", fuenteSubtitulo, System::Drawing::Brushes::Black, (float)(x + ancho / 2), (float)y);
			y += 25;

			g->DrawString("Nombre: " + TextoDato(factura, "cliente"), fuenteNormal, System::Drawing::Brushes::Black, (float)x, (float)y);
			g->DrawString("Placa: " + TextoDato(factura, "placa"), fuenteNormal, System::Drawing::Brushes::Black, (float)(x + ancho / 2), (float)y);
			y += 20;
			g->DrawString("NIT: " + TextoDato(factura, "nit"), fuenteNormal, System::Drawing::Brushes::Black, (float)x, (float)y);
			g->DrawString("Vehiculo: " + TextoDato(factura, "marca") + " " + TextoDato(factura, "modelo"), fuenteNormal, System::Drawing::Brushes::Black, (float)(x + ancho / 2), (float)y);
			y += 20;
			g->DrawString("Telefono: " + TextoDato(factura, "telefono"), fuenteNormal, System::Drawing::Brushes::Black, (float)x, (float)y);
			g->DrawString("Servicio: " + TextoDato(factura, "servicio"), fuenteNormal, System::Drawing::Brushes::Black, (float)(x + ancho / 2), (float)y);
			y += 20;
			g->DrawString("Direccion: " + TextoDato(factura, "direccion"), fuenteNormal, System::Drawing::Brushes::Black, (float)x, (float)y);
			g->DrawString("Mecanico: " + TextoDato(factura, "mecanico"), fuenteNormal, System::Drawing::Brushes::Black, (float)(x + ancho / 2), (float)y);
			y += 30;

			if (!String::IsNullOrWhiteSpace(TextoDato(factura, "problema")))
			{
				g->DrawString("Problema reportado: " + TextoDato(factura, "problema"), fuenteNormal, System::Drawing::Brushes::Black, (float)x, (float)y);
				y += 25;
			}

			g->DrawString("Detalle del trabajo", fuenteSubtitulo, System::Drawing::Brushes::Black, (float)x, (float)y);
			y += 25;

			int colCant = 50;
			int colRep = 150;
			int colTrabajo = ancho - 460;
			int colMano = 110;
			int colSub = 110;
			int altoFila = 34;

			g->FillRectangle(System::Drawing::Brushes::Gainsboro, x, y, ancho, 24);
			g->DrawRectangle(System::Drawing::Pens::Black, x, y, ancho, 24);
			DibujarTexto(g, "Cant.", fuenteNegrita, System::Drawing::Brushes::Black, x + 4, y + 4, colCant - 8, 18, centro);
			DibujarTexto(g, "Repuesto", fuenteNegrita, System::Drawing::Brushes::Black, x + colCant + 4, y + 4, colRep - 8, 18, cortar);
			DibujarTexto(g, "Trabajo realizado", fuenteNegrita, System::Drawing::Brushes::Black, x + colCant + colRep + 4, y + 4, colTrabajo - 8, 18, cortar);
			DibujarTexto(g, "Mano obra", fuenteNegrita, System::Drawing::Brushes::Black, x + colCant + colRep + colTrabajo + 4, y + 4, colMano - 8, 18, derecha);
			DibujarTexto(g, "Subtotal", fuenteNegrita, System::Drawing::Brushes::Black, x + colCant + colRep + colTrabajo + colMano + 4, y + 4, colSub - 8, 18, derecha);
			y += 24;

			while (filaDetallePdf < detalleFacturaPdf->Rows->Count && y + altoFila < fondo - 120)
			{
				System::Data::DataRow^ detalle = detalleFacturaPdf->Rows[filaDetallePdf];
				g->DrawRectangle(System::Drawing::Pens::LightGray, x, y, ancho, altoFila);
				DibujarTexto(g, TextoDato(detalle, "cantidad"), fuenteNormal, System::Drawing::Brushes::Black, x + 4, y + 7, colCant - 8, 20, centro);
				DibujarTexto(g, TextoDato(detalle, "repuesto"), fuenteNormal, System::Drawing::Brushes::Black, x + colCant + 4, y + 7, colRep - 8, 20, cortar);
				DibujarTexto(g, TextoDato(detalle, "descripcion_trabajo"), fuenteNormal, System::Drawing::Brushes::Black, x + colCant + colRep + 4, y + 7, colTrabajo - 8, 20, cortar);
				DibujarTexto(g, TextoMoneda(detalle["costo_mano_obra"]), fuenteNormal, System::Drawing::Brushes::Black, x + colCant + colRep + colTrabajo + 4, y + 7, colMano - 8, 20, derecha);
				DibujarTexto(g, TextoMoneda(detalle["subtotal"]), fuenteNormal, System::Drawing::Brushes::Black, x + colCant + colRep + colTrabajo + colMano + 4, y + 7, colSub - 8, 20, derecha);
				y += altoFila;
				filaDetallePdf++;
			}

			if (filaDetallePdf < detalleFacturaPdf->Rows->Count)
			{
				e->HasMorePages = true;
				return;
			}

			y += 20;
			int cajaTotalesX = x + ancho - 260;
			g->DrawString("Subtotal:", fuenteNegrita, System::Drawing::Brushes::Black, (float)cajaTotalesX, (float)y);
			DibujarTexto(g, TextoMoneda(factura["subtotal"]), fuenteNormal, System::Drawing::Brushes::Black, cajaTotalesX, y, 250, 20, derecha);
			y += 22;
			g->DrawString("Descuento:", fuenteNegrita, System::Drawing::Brushes::Black, (float)cajaTotalesX, (float)y);
			DibujarTexto(g, TextoMoneda(factura["descuento"]), fuenteNormal, System::Drawing::Brushes::Black, cajaTotalesX, y, 250, 20, derecha);
			y += 22;
			g->DrawLine(System::Drawing::Pens::Black, cajaTotalesX, y, x + ancho, y);
			y += 8;
			g->DrawString("Total:", fuenteSubtitulo, System::Drawing::Brushes::Black, (float)cajaTotalesX, (float)y);
			DibujarTexto(g, TextoMoneda(factura["total"]), fuenteSubtitulo, System::Drawing::Brushes::Black, cajaTotalesX, y, 250, 25, derecha);
			y += 40;
			g->DrawString("Metodo de pago: " + TextoDato(factura, "metodo_pago"), fuenteNormal, System::Drawing::Brushes::Black, (float)x, (float)y);
			y += 20;
			if (!String::IsNullOrWhiteSpace(TextoDato(factura, "observacion")))
			{
				g->DrawString("Observacion: " + TextoDato(factura, "observacion"), fuenteNormal, System::Drawing::Brushes::Black, (float)x, (float)y);
			}
			DibujarTexto(g, "Gracias por su preferencia", fuenteNegrita, System::Drawing::Brushes::DimGray, x, fondo - 30, ancho, 25, centro);

			e->HasMorePages = false;
		}

		void CargarServiciosFacturables()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT s.id_servicio, CONCAT('#', s.id_servicio, ' - ', c.nombre, ' - ', v.placa, ' - Q', FORMAT(s.total,2)) AS descripcion "
					"FROM servicios s INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
					"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
					"WHERE s.estado IN ('LISTO','ENTREGADO') ORDER BY s.id_servicio DESC";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				cmbServicio->DataSource = dt;
				cmbServicio->DisplayMember = "descripcion";
				cmbServicio->ValueMember = "id_servicio";
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al cargar ordenes facturables: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void CargarServicioSeleccionado()
		{
			if (cmbServicio->SelectedValue == nullptr) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT s.id_servicio, c.nombre AS cliente, CONCAT(v.placa, ' - ', v.marca, ' ', v.modelo) AS vehiculo, "
					"ts.tipo AS servicio, m.nombre AS mecanico, s.total "
					"FROM servicios s INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
					"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
					"INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio "
					"INNER JOIN mecanico m ON s.id_mecanico=m.id_mecanico WHERE s.id_servicio=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", cmbServicio->SelectedValue);
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				if (dt->Rows->Count == 0) return;

				DataRow^ row = dt->Rows[0];
				txtIdServicio->Text = row["id_servicio"]->ToString();
				txtCliente->Text = row["cliente"]->ToString();
				txtVehiculo->Text = row["vehiculo"]->ToString();
				txtTipoServicio->Text = row["servicio"]->ToString();
				txtMecanico->Text = row["mecanico"]->ToString();
				Decimal total = Convert::ToDecimal(row["total"]);
				txtTotalServicio->Text = total.ToString("0.00");
				ListarDetalle(Convert::ToInt32(txtIdServicio->Text));
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al cargar la orden: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void ListarFacturas()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT f.id_factura, f.id_servicio, f.fecha, c.nombre AS cliente, v.placa, ts.tipo AS servicio, "
					"f.subtotal, f.descuento, f.total, f.metodo_pago, f.estado, f.observacion "
					"FROM facturas f INNER JOIN servicios s ON f.id_servicio=s.id_servicio "
					"INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
					"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
					"INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio "
					"ORDER BY f.id_factura DESC";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvFacturas->DataSource = dt;
				FormatearFacturas();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar facturas: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void ListarDetalle(int idServicio)
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT d.id_detalle, r.nombre AS repuesto, d.cantidad, d.descripcion_trabajo, "
					"d.costo_mano_obra, d.observacion, "
					"((IFNULL(r.precio,0) * IFNULL(d.cantidad,0)) + IFNULL(d.costo_mano_obra,0)) AS subtotal "
					"FROM detalletrabajo d LEFT JOIN repuestos r ON d.id_repuesto=r.id_repuesto "
					"WHERE d.id_servicio=@servicio ORDER BY d.id_detalle DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@servicio", idServicio);
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvDetalle->DataSource = dt;
				FormatearDetalle();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar detalle: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		bool ValidarFactura()
		{
			if (String::IsNullOrWhiteSpace(txtIdServicio->Text))
			{
				System::Windows::Forms::MessageBox::Show("Debe cargar una orden lista o entregada.");
				return false;
			}
			Decimal descuento = Decimal::Zero;
			if (!Decimal::TryParse(txtDescuento->Text, descuento))
			{
				System::Windows::Forms::MessageBox::Show("El descuento debe ser numerico.");
				return false;
			}
			return true;
		}

		void Limpiar()
		{
			txtIdServicio->Clear();
			txtCliente->Clear();
			txtVehiculo->Clear();
			txtTipoServicio->Clear();
			txtMecanico->Clear();
			txtTotalServicio->Clear();
			txtDescuento->Text = L"0";
			txtObservacion->Clear();
			if (cmbMetodoPago->Items->Count > 0) cmbMetodoPago->SelectedIndex = 0;
			dgvDetalle->DataSource = nullptr;
		}

		System::Void btnCargarServicio_Click(System::Object^ sender, System::EventArgs^ e)
		{
			CargarServicioSeleccionado();
		}

		System::Void btnGenerarFactura_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidarFactura()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				int idServicio = Convert::ToInt32(txtIdServicio->Text);
				Decimal subtotal = Convert::ToDecimal(txtTotalServicio->Text);
				Decimal descuento = Convert::ToDecimal(txtDescuento->Text);
				Decimal total = subtotal - descuento;
				if (total < Decimal::Zero) total = Decimal::Zero;

				String^ sql =
					"INSERT INTO facturas (id_servicio, fecha, subtotal, descuento, total, metodo_pago, estado, observacion) "
					"VALUES (@servicio, NOW(), @subtotal, @descuento, @total, @metodo, 'EMITIDA', @observacion) "
					"ON DUPLICATE KEY UPDATE fecha=NOW(), subtotal=@subtotal, descuento=@descuento, total=@total, metodo_pago=@metodo, estado='EMITIDA', observacion=@observacion";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@servicio", idServicio);
				cmd->Parameters->AddWithValue("@subtotal", subtotal);
				cmd->Parameters->AddWithValue("@descuento", descuento);
				cmd->Parameters->AddWithValue("@total", total);
				cmd->Parameters->AddWithValue("@metodo", cmbMetodoPago->Text);
				cmd->Parameters->AddWithValue("@observacion", txtObservacion->Text);
				cmd->ExecuteNonQuery();
				int idFactura = ObtenerIdFacturaPorServicio(cn, idServicio);

				System::Windows::Forms::DialogResult respuestaPdf =
					System::Windows::Forms::MessageBox::Show(
						"Factura generada correctamente. Total: Q" + total.ToString("0.00") + "\n\nDesea guardar el PDF ahora?",
						"Factura generada",
						System::Windows::Forms::MessageBoxButtons::YesNo,
						System::Windows::Forms::MessageBoxIcon::Question);
				Limpiar();
				CargarServiciosFacturables();
				ListarFacturas();
				if (respuestaPdf == System::Windows::Forms::DialogResult::Yes && idFactura > 0)
				{
					ExportarFacturaPdf(idFactura);
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al generar factura: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Limpiar();
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void btnExportarPdf_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (dgvFacturas->SelectedRows->Count == 0)
			{
				System::Windows::Forms::MessageBox::Show("Seleccione una factura de la tabla para exportarla.");
				return;
			}

			try
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvFacturas->SelectedRows[0];
				String^ idFactura = ValorCelda(fila, "id_factura");
				if (String::IsNullOrWhiteSpace(idFactura))
				{
					System::Windows::Forms::MessageBox::Show("No se pudo identificar la factura seleccionada.");
					return;
				}
				ExportarFacturaPdf(Convert::ToInt32(idFactura));
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al exportar PDF: " + ex->Message);
			}
		}

		System::Void dgvFacturas_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvFacturas->Rows[e->RowIndex];
				String^ idServicio = ValorCelda(fila, "id_servicio");
				if (!String::IsNullOrWhiteSpace(idServicio))
				{
					ListarDetalle(Convert::ToInt32(idServicio));
				}
			}
		}
	};
}
