#pragma once
#include "Conexion.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Text;
	using namespace MySql::Data::MySqlClient;

	public ref class FormRecepcion : public System::Windows::Forms::Form
	{
	public:
		FormRecepcion(void)
		{
			cargandoCombos = true;
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormRecepcion::FormRecepcion_Load);
		}

	protected:
		~FormRecepcion()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		bool cargandoCombos;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Panel^ panelIzquierdo;
		System::Windows::Forms::Panel^ panelDerecho;
		System::Windows::Forms::GroupBox^ grpRecepcion;
		System::Windows::Forms::GroupBox^ grpDetalleTrabajo;

		System::Windows::Forms::TextBox^ txtIdServicio;
		System::Windows::Forms::ComboBox^ cmbCliente;
		System::Windows::Forms::ComboBox^ cmbVehiculo;
		System::Windows::Forms::ComboBox^ cmbTipoServicio;
		System::Windows::Forms::ComboBox^ cmbMecanico;
		System::Windows::Forms::DateTimePicker^ dtpFecha;
		System::Windows::Forms::TextBox^ txtKilometraje;
		System::Windows::Forms::TextBox^ txtDescripcion;
		System::Windows::Forms::ComboBox^ cmbEstado;

		System::Windows::Forms::ComboBox^ cmbRepuesto;
		System::Windows::Forms::TextBox^ txtCantidad;
		System::Windows::Forms::TextBox^ txtTrabajo;
		System::Windows::Forms::TextBox^ txtManoObra;
		System::Windows::Forms::TextBox^ txtObservacion;
		System::Windows::Forms::TextBox^ txtBuscar;

		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblCliente;
		System::Windows::Forms::Label^ lblVehiculo;
		System::Windows::Forms::Label^ lblTipoServicio;
		System::Windows::Forms::Label^ lblMecanico;
		System::Windows::Forms::Label^ lblFecha;
		System::Windows::Forms::Label^ lblKilometraje;
		System::Windows::Forms::Label^ lblDescripcion;
		System::Windows::Forms::Label^ lblEstado;
		System::Windows::Forms::Label^ lblDetalle;
		System::Windows::Forms::Label^ lblRepuesto;
		System::Windows::Forms::Label^ lblCantidad;
		System::Windows::Forms::Label^ lblTrabajo;
		System::Windows::Forms::Label^ lblManoObra;
		System::Windows::Forms::Label^ lblObservacion;
		System::Windows::Forms::Label^ lblBuscar;

		System::Windows::Forms::Button^ btnCrearOrden;
		System::Windows::Forms::Button^ btnActualizarEstado;
		System::Windows::Forms::Button^ btnAgregarDetalle;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Button^ btnRegresar;

		System::Windows::Forms::DataGridView^ dgvServicios;
		System::Windows::Forms::DataGridView^ dgvDetalle;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelIzquierdo = gcnew System::Windows::Forms::Panel();
			this->panelDerecho = gcnew System::Windows::Forms::Panel();
			this->grpRecepcion = gcnew System::Windows::Forms::GroupBox();
			this->grpDetalleTrabajo = gcnew System::Windows::Forms::GroupBox();
			this->txtIdServicio = gcnew System::Windows::Forms::TextBox();
			this->cmbCliente = gcnew System::Windows::Forms::ComboBox();
			this->cmbVehiculo = gcnew System::Windows::Forms::ComboBox();
			this->cmbTipoServicio = gcnew System::Windows::Forms::ComboBox();
			this->cmbMecanico = gcnew System::Windows::Forms::ComboBox();
			this->dtpFecha = gcnew System::Windows::Forms::DateTimePicker();
			this->txtKilometraje = gcnew System::Windows::Forms::TextBox();
			this->txtDescripcion = gcnew System::Windows::Forms::TextBox();
			this->cmbEstado = gcnew System::Windows::Forms::ComboBox();
			this->cmbRepuesto = gcnew System::Windows::Forms::ComboBox();
			this->txtCantidad = gcnew System::Windows::Forms::TextBox();
			this->txtTrabajo = gcnew System::Windows::Forms::TextBox();
			this->txtManoObra = gcnew System::Windows::Forms::TextBox();
			this->txtObservacion = gcnew System::Windows::Forms::TextBox();
			this->txtBuscar = gcnew System::Windows::Forms::TextBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblCliente = gcnew System::Windows::Forms::Label();
			this->lblVehiculo = gcnew System::Windows::Forms::Label();
			this->lblTipoServicio = gcnew System::Windows::Forms::Label();
			this->lblMecanico = gcnew System::Windows::Forms::Label();
			this->lblFecha = gcnew System::Windows::Forms::Label();
			this->lblKilometraje = gcnew System::Windows::Forms::Label();
			this->lblDescripcion = gcnew System::Windows::Forms::Label();
			this->lblEstado = gcnew System::Windows::Forms::Label();
			this->lblDetalle = gcnew System::Windows::Forms::Label();
			this->lblRepuesto = gcnew System::Windows::Forms::Label();
			this->lblCantidad = gcnew System::Windows::Forms::Label();
			this->lblTrabajo = gcnew System::Windows::Forms::Label();
			this->lblManoObra = gcnew System::Windows::Forms::Label();
			this->lblObservacion = gcnew System::Windows::Forms::Label();
			this->lblBuscar = gcnew System::Windows::Forms::Label();
			this->btnCrearOrden = gcnew System::Windows::Forms::Button();
			this->btnActualizarEstado = gcnew System::Windows::Forms::Button();
			this->btnAgregarDetalle = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnBuscar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvServicios = gcnew System::Windows::Forms::DataGridView();
			this->dgvDetalle = gcnew System::Windows::Forms::DataGridView();
			this->SuspendLayout();

			this->Text = L"Recepcion y Orden de Servicio";
			this->ClientSize = System::Drawing::Size(1300, 760);
			this->MinimumSize = System::Drawing::Size(1100, 650);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

			this->panelIzquierdo->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelIzquierdo->Width = 520;
			this->panelIzquierdo->Padding = System::Windows::Forms::Padding(30);
			this->panelIzquierdo->AutoScroll = true;
			this->panelDerecho->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDerecho->Padding = System::Windows::Forms::Padding(20);

			this->grpRecepcion->Text = L"Datos de recepcion";
			this->grpRecepcion->Location = System::Drawing::Point(20, 15);
			this->grpRecepcion->Size = System::Drawing::Size(480, 455);

			this->grpDetalleTrabajo->Text = L"Detalle del trabajo";
			this->grpDetalleTrabajo->Location = System::Drawing::Point(20, 470);
			this->grpDetalleTrabajo->Size = System::Drawing::Size(480, 330);

			this->txtIdServicio->Visible = false;
			this->lblTitulo->Text = L"Recepcion de Vehiculo";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(30, 25);
			this->lblTitulo->AutoSize = true;

			this->lblCliente->Text = L"Cliente:";
			this->lblCliente->Location = System::Drawing::Point(35, 85);
			this->lblCliente->AutoSize = true;
			this->cmbCliente->Location = System::Drawing::Point(170, 80);
			this->cmbCliente->Size = System::Drawing::Size(300, 25);
			this->cmbCliente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCliente->SelectedIndexChanged += gcnew System::EventHandler(this, &FormRecepcion::cmbCliente_SelectedIndexChanged);

			this->lblVehiculo->Text = L"Vehiculo:";
			this->lblVehiculo->Location = System::Drawing::Point(35, 120);
			this->lblVehiculo->AutoSize = true;
			this->cmbVehiculo->Location = System::Drawing::Point(170, 115);
			this->cmbVehiculo->Size = System::Drawing::Size(300, 25);
			this->cmbVehiculo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->lblTipoServicio->Text = L"Tipo servicio:";
			this->lblTipoServicio->Location = System::Drawing::Point(35, 155);
			this->lblTipoServicio->AutoSize = true;
			this->cmbTipoServicio->Location = System::Drawing::Point(170, 150);
			this->cmbTipoServicio->Size = System::Drawing::Size(300, 25);
			this->cmbTipoServicio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->lblMecanico->Text = L"Mecanico:";
			this->lblMecanico->Location = System::Drawing::Point(35, 190);
			this->lblMecanico->AutoSize = true;
			this->cmbMecanico->Location = System::Drawing::Point(170, 185);
			this->cmbMecanico->Size = System::Drawing::Size(300, 25);
			this->cmbMecanico->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->lblFecha->Text = L"Fecha:";
			this->lblFecha->Location = System::Drawing::Point(35, 225);
			this->lblFecha->AutoSize = true;
			this->dtpFecha->Location = System::Drawing::Point(170, 220);
			this->dtpFecha->Size = System::Drawing::Size(220, 25);
			this->dtpFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;

			this->lblKilometraje->Text = L"Kilometraje:";
			this->lblKilometraje->Location = System::Drawing::Point(35, 260);
			this->lblKilometraje->AutoSize = true;
			this->txtKilometraje->Location = System::Drawing::Point(170, 255);
			this->txtKilometraje->Size = System::Drawing::Size(130, 25);

			this->lblEstado->Text = L"Estado:";
			this->lblEstado->Location = System::Drawing::Point(35, 295);
			this->lblEstado->AutoSize = true;
			this->cmbEstado->Location = System::Drawing::Point(170, 290);
			this->cmbEstado->Size = System::Drawing::Size(180, 25);
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->Items->Add(L"RECIBIDO");
			this->cmbEstado->Items->Add(L"EN_REVISION");
			this->cmbEstado->Items->Add(L"EN_REPARACION");
			this->cmbEstado->Items->Add(L"LISTO");
			this->cmbEstado->Items->Add(L"ENTREGADO");
			this->cmbEstado->Items->Add(L"CANCELADO");
			this->cmbEstado->SelectedIndex = 0;

			this->lblDescripcion->Text = L"Problema:";
			this->lblDescripcion->Location = System::Drawing::Point(35, 330);
			this->lblDescripcion->AutoSize = true;
			this->txtDescripcion->Location = System::Drawing::Point(170, 325);
			this->txtDescripcion->Size = System::Drawing::Size(300, 70);
			this->txtDescripcion->Multiline = true;

			this->btnCrearOrden->Text = L"Crear orden";
			this->btnCrearOrden->Location = System::Drawing::Point(35, 415);
			this->btnCrearOrden->Size = System::Drawing::Size(135, 38);
			this->btnCrearOrden->Click += gcnew System::EventHandler(this, &FormRecepcion::btnCrearOrden_Click);

			this->btnActualizarEstado->Text = L"Actualizar estado";
			this->btnActualizarEstado->Location = System::Drawing::Point(180, 415);
			this->btnActualizarEstado->Size = System::Drawing::Size(145, 38);
			this->btnActualizarEstado->Click += gcnew System::EventHandler(this, &FormRecepcion::btnActualizarEstado_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(335, 415);
			this->btnLimpiar->Size = System::Drawing::Size(135, 38);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormRecepcion::btnLimpiar_Click);

			this->lblDetalle->Text = L"Detalle del trabajo";
			this->lblDetalle->Font = gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold);
			this->lblDetalle->Location = System::Drawing::Point(35, 480);
			this->lblDetalle->AutoSize = true;

			this->lblRepuesto->Text = L"Repuesto:";
			this->lblRepuesto->Location = System::Drawing::Point(35, 525);
			this->lblRepuesto->AutoSize = true;
			this->cmbRepuesto->Location = System::Drawing::Point(170, 520);
			this->cmbRepuesto->Size = System::Drawing::Size(300, 25);
			this->cmbRepuesto->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->lblCantidad->Text = L"Cantidad:";
			this->lblCantidad->Location = System::Drawing::Point(35, 560);
			this->lblCantidad->AutoSize = true;
			this->txtCantidad->Location = System::Drawing::Point(170, 555);
			this->txtCantidad->Size = System::Drawing::Size(90, 25);
			this->txtCantidad->Text = L"1";

			this->lblManoObra->Text = L"Mano obra:";
			this->lblManoObra->Location = System::Drawing::Point(280, 560);
			this->lblManoObra->AutoSize = true;
			this->txtManoObra->Location = System::Drawing::Point(380, 555);
			this->txtManoObra->Size = System::Drawing::Size(90, 25);
			this->txtManoObra->Text = L"0";

			this->lblTrabajo->Text = L"Trabajo:";
			this->lblTrabajo->Location = System::Drawing::Point(35, 595);
			this->lblTrabajo->AutoSize = true;
			this->txtTrabajo->Location = System::Drawing::Point(170, 590);
			this->txtTrabajo->Size = System::Drawing::Size(300, 55);
			this->txtTrabajo->Multiline = true;

			this->lblObservacion->Text = L"Observacion:";
			this->lblObservacion->Location = System::Drawing::Point(35, 660);
			this->lblObservacion->AutoSize = true;
			this->txtObservacion->Location = System::Drawing::Point(170, 655);
			this->txtObservacion->Size = System::Drawing::Size(300, 55);
			this->txtObservacion->Multiline = true;

			this->btnAgregarDetalle->Text = L"Agregar detalle";
			this->btnAgregarDetalle->Location = System::Drawing::Point(35, 730);
			this->btnAgregarDetalle->Size = System::Drawing::Size(210, 38);
			this->btnAgregarDetalle->Click += gcnew System::EventHandler(this, &FormRecepcion::btnAgregarDetalle_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(260, 730);
			this->btnRegresar->Size = System::Drawing::Size(210, 38);
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormRecepcion::btnRegresar_Click);

			this->lblBuscar->Text = L"Buscar orden por cliente, placa o estado:";
			this->lblBuscar->Location = System::Drawing::Point(20, 30);
			this->lblBuscar->AutoSize = true;
			this->txtBuscar->Location = System::Drawing::Point(20, 60);
			this->txtBuscar->Size = System::Drawing::Size(500, 25);
			this->txtBuscar->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->Location = System::Drawing::Point(540, 56);
			this->btnBuscar->Size = System::Drawing::Size(120, 34);
			this->btnBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormRecepcion::btnBuscar_Click);

			this->dgvServicios->Location = System::Drawing::Point(20, 105);
			this->dgvServicios->Size = System::Drawing::Size(720, 300);
			this->dgvServicios->ReadOnly = true;
			this->dgvServicios->AllowUserToAddRows = false;
			this->dgvServicios->AllowUserToDeleteRows = false;
			this->dgvServicios->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvServicios->MultiSelect = false;
			this->dgvServicios->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvServicios->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dgvServicios->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvServicios->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvServicios->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormRecepcion::dgvServicios_CellClick);

			this->dgvDetalle->Location = System::Drawing::Point(20, 430);
			this->dgvDetalle->Size = System::Drawing::Size(720, 260);
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->AllowUserToAddRows = false;
			this->dgvDetalle->AllowUserToDeleteRows = false;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDetalle->MultiSelect = false;
			this->dgvDetalle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvDetalle->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dgvDetalle->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvDetalle->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));

			this->panelIzquierdo->Controls->Add(this->txtIdServicio);
			this->panelIzquierdo->Controls->Add(this->grpRecepcion);
			this->panelIzquierdo->Controls->Add(this->grpDetalleTrabajo);
			this->panelIzquierdo->Controls->Add(this->lblTitulo);
			this->panelIzquierdo->Controls->Add(this->lblCliente);
			this->panelIzquierdo->Controls->Add(this->cmbCliente);
			this->panelIzquierdo->Controls->Add(this->lblVehiculo);
			this->panelIzquierdo->Controls->Add(this->cmbVehiculo);
			this->panelIzquierdo->Controls->Add(this->lblTipoServicio);
			this->panelIzquierdo->Controls->Add(this->cmbTipoServicio);
			this->panelIzquierdo->Controls->Add(this->lblMecanico);
			this->panelIzquierdo->Controls->Add(this->cmbMecanico);
			this->panelIzquierdo->Controls->Add(this->lblFecha);
			this->panelIzquierdo->Controls->Add(this->dtpFecha);
			this->panelIzquierdo->Controls->Add(this->lblKilometraje);
			this->panelIzquierdo->Controls->Add(this->txtKilometraje);
			this->panelIzquierdo->Controls->Add(this->lblEstado);
			this->panelIzquierdo->Controls->Add(this->cmbEstado);
			this->panelIzquierdo->Controls->Add(this->lblDescripcion);
			this->panelIzquierdo->Controls->Add(this->txtDescripcion);
			this->panelIzquierdo->Controls->Add(this->btnCrearOrden);
			this->panelIzquierdo->Controls->Add(this->btnActualizarEstado);
			this->panelIzquierdo->Controls->Add(this->btnLimpiar);
			this->panelIzquierdo->Controls->Add(this->lblDetalle);
			this->panelIzquierdo->Controls->Add(this->lblRepuesto);
			this->panelIzquierdo->Controls->Add(this->cmbRepuesto);
			this->panelIzquierdo->Controls->Add(this->lblCantidad);
			this->panelIzquierdo->Controls->Add(this->txtCantidad);
			this->panelIzquierdo->Controls->Add(this->lblManoObra);
			this->panelIzquierdo->Controls->Add(this->txtManoObra);
			this->panelIzquierdo->Controls->Add(this->lblTrabajo);
			this->panelIzquierdo->Controls->Add(this->txtTrabajo);
			this->panelIzquierdo->Controls->Add(this->lblObservacion);
			this->panelIzquierdo->Controls->Add(this->txtObservacion);
			this->panelIzquierdo->Controls->Add(this->btnAgregarDetalle);
			this->panelIzquierdo->Controls->Add(this->btnRegresar);
			this->panelDerecho->Controls->Add(this->lblBuscar);
			this->panelDerecho->Controls->Add(this->txtBuscar);
			this->panelDerecho->Controls->Add(this->btnBuscar);
			this->panelDerecho->Controls->Add(this->dgvServicios);
			this->panelDerecho->Controls->Add(this->dgvDetalle);
			this->Controls->Add(this->panelDerecho);
			this->Controls->Add(this->panelIzquierdo);
			this->grpRecepcion->SendToBack();
			this->grpDetalleTrabajo->SendToBack();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormRecepcion_Load(System::Object^ sender, System::EventArgs^ e)
		{
			CargarClientes();
			CargarTiposServicio();
			CargarMecanicos();
			CargarRepuestos();
			cargandoCombos = false;
			CargarVehiculosPorCliente();
			ListarServicios("");
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void OcultarColumna(System::Windows::Forms::DataGridView^ grid, String^ columna)
		{
			if (grid->Columns->Contains(columna))
			{
				grid->Columns[columna]->Visible = false;
			}
		}

		void Encabezado(System::Windows::Forms::DataGridView^ grid, String^ columna, String^ texto)
		{
			if (grid->Columns->Contains(columna))
			{
				grid->Columns[columna]->HeaderText = texto;
			}
		}

		void FormatearServicios()
		{
			OcultarColumna(dgvServicios, "id_servicio");
			OcultarColumna(dgvServicios, "id_cliente");
			OcultarColumna(dgvServicios, "id_vehiculo");
			OcultarColumna(dgvServicios, "id_tipo_servicio");
			OcultarColumna(dgvServicios, "id_mecanico");
			Encabezado(dgvServicios, "cliente", "Cliente");
			Encabezado(dgvServicios, "placa", "Placa");
			Encabezado(dgvServicios, "servicio", "Servicio");
			Encabezado(dgvServicios, "mecanico", "Mecanico");
			Encabezado(dgvServicios, "fecha", "Fecha");
			Encabezado(dgvServicios, "kilometraje", "Kilometraje");
			Encabezado(dgvServicios, "estado", "Estado");
			Encabezado(dgvServicios, "total", "Total");
			Encabezado(dgvServicios, "descripcion", "Problema reportado");
			dgvServicios->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
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

		String^ EscaparJson(String^ valor)
		{
			if (valor == nullptr) return "";
			return valor->Replace("\\", "\\\\")->Replace("\"", "\\\"")->Replace("\r", " ")->Replace("\n", " ");
		}

		String^ FormatearNumeroWhatsApp(String^ telefono)
		{
			StringBuilder^ limpio = gcnew StringBuilder();
			if (telefono != nullptr)
			{
				for each (Char c in telefono)
				{
					if (Char::IsDigit(c))
					{
						limpio->Append(c);
					}
				}
			}

			String^ numero = limpio->ToString();
			if (numero->Length == 8)
			{
				numero = "502" + numero;
			}
			if (!numero->EndsWith("@s.whatsapp.net"))
			{
				numero += "@s.whatsapp.net";
			}
			return numero;
		}

		String^ ObtenerEstadoAnterior(MySqlConnection^ cn, int idServicio)
		{
			MySqlCommand^ cmd = gcnew MySqlCommand("SELECT estado FROM servicios WHERE id_servicio=@id", cn);
			cmd->Parameters->AddWithValue("@id", idServicio);
			Object^ valor = cmd->ExecuteScalar();
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void EnviarWhatsAppListo(int idServicio)
		{
			try
			{
				MySqlConnection^ cn = Conexion::ObtenerConexion();
				try
				{
					cn->Open();
					String^ sql =
						"SELECT c.nombre, c.telefono, v.placa, s.total "
						"FROM servicios s INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
						"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
						"WHERE s.id_servicio=@id";
					MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
					cmd->Parameters->AddWithValue("@id", idServicio);
					MySqlDataReader^ dr = cmd->ExecuteReader();
					if (!dr->Read())
					{
						return;
					}

					String^ cliente = dr["nombre"]->ToString();
					String^ telefono = dr["telefono"]->ToString();
					String^ placa = dr["placa"]->ToString();
					Decimal totalDecimal = Convert::ToDecimal(dr["total"]);
					String^ total = totalDecimal.ToString("0.00");
					dr->Close();

					if (String::IsNullOrWhiteSpace(telefono))
					{
						System::Windows::Forms::MessageBox::Show("La orden esta LISTA, pero el cliente no tiene telefono para WhatsApp.");
						return;
					}

					String^ url = "https://evolutioneco.ecofiltro.net/message/sendText/jonatan_perosonal";
					String^ apiKey = "59B80597F3B1-4A32-BCC7-C256251BDF9E";
					String^ numero = FormatearNumeroWhatsApp(telefono);
					String^ texto = "Hola " + cliente + ", le informamos que su vehiculo placa " + placa +
						" ya esta LISTO para entrega. Total: Q" + total + ". Taller Mecanico.";
					String^ body = "{\"number\":\"" + EscaparJson(numero) + "\",\"text\":\"" + EscaparJson(texto) + "\"}";

					ServicePointManager::SecurityProtocol = SecurityProtocolType::Tls12;
					HttpWebRequest^ request = (HttpWebRequest^)WebRequest::Create(url);
					request->Method = "POST";
					request->ContentType = "application/json";
					request->Headers->Add("apikey", apiKey);

					array<Byte>^ bytes = Encoding::UTF8->GetBytes(body);
					request->ContentLength = bytes->Length;
					Stream^ stream = request->GetRequestStream();
					stream->Write(bytes, 0, bytes->Length);
					stream->Close();

					HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
					response->Close();
					System::Windows::Forms::MessageBox::Show("WhatsApp enviado al cliente.");
				}
				finally
				{
					if (cn->State == ConnectionState::Open) cn->Close();
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Estado actualizado, pero no se pudo enviar WhatsApp: " + ex->Message);
			}
		}

		void CargarCombo(System::Windows::Forms::ComboBox^ combo, String^ sql, String^ display, String^ value)
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				combo->DataSource = dt;
				combo->DisplayMember = display;
				combo->ValueMember = value;
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al cargar datos: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void CargarClientes()
		{
			CargarCombo(cmbCliente, "SELECT id_cliente, CONCAT(nit, ' - ', nombre) AS cliente FROM clientes ORDER BY nombre", "cliente", "id_cliente");
		}

		void CargarTiposServicio()
		{
			CargarCombo(cmbTipoServicio, "SELECT id_tipo_servicio, CONCAT(tipo, ' - Q', precio) AS servicio FROM tiposervicio ORDER BY tipo", "servicio", "id_tipo_servicio");
		}

		void CargarMecanicos()
		{
			CargarCombo(cmbMecanico, "SELECT id_mecanico, CONCAT(nombre, ' - ', especialidad) AS mecanico FROM mecanico ORDER BY nombre", "mecanico", "id_mecanico");
		}

		void CargarRepuestos()
		{
			CargarCombo(cmbRepuesto, "SELECT id_repuesto, CONCAT(nombre, ' - Q', precio, ' - stock ', stock) AS repuesto FROM repuestos ORDER BY nombre", "repuesto", "id_repuesto");
		}

		void CargarVehiculosPorCliente()
		{
			if (cmbCliente->SelectedValue == nullptr) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "SELECT id_vehiculo, CONCAT(placa, ' - ', marca, ' ', modelo) AS vehiculo FROM vehiculos WHERE id_cliente=@cliente ORDER BY placa";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@cliente", cmbCliente->SelectedValue);
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				cmbVehiculo->DataSource = dt;
				cmbVehiculo->DisplayMember = "vehiculo";
				cmbVehiculo->ValueMember = "id_vehiculo";
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al cargar vehiculos: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void ListarServicios(String^ buscar)
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT s.id_servicio, s.id_cliente, s.id_vehiculo, s.id_tipo_servicio, s.id_mecanico, "
					"c.nombre AS cliente, v.placa, ts.tipo AS servicio, m.nombre AS mecanico, "
					"s.fecha, s.kilometraje, s.estado, s.total, s.descripcion "
					"FROM servicios s "
					"INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
					"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
					"INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio "
					"INNER JOIN mecanico m ON s.id_mecanico=m.id_mecanico "
					"WHERE c.nombre LIKE @buscar OR v.placa LIKE @buscar OR s.estado LIKE @buscar "
					"ORDER BY s.id_servicio DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@buscar", "%" + buscar + "%");
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvServicios->DataSource = dt;
				FormatearServicios();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar servicios: " + ex->Message);
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

		bool ValidarOrden()
		{
			if (cmbCliente->SelectedValue == nullptr || cmbVehiculo->SelectedValue == nullptr ||
				cmbTipoServicio->SelectedValue == nullptr || cmbMecanico->SelectedValue == nullptr)
			{
				System::Windows::Forms::MessageBox::Show("Debe seleccionar cliente, vehiculo, tipo de servicio y mecanico.");
				return false;
			}
			if (!String::IsNullOrWhiteSpace(txtKilometraje->Text))
			{
				int km = 0;
				if (!Int32::TryParse(txtKilometraje->Text, km))
				{
					System::Windows::Forms::MessageBox::Show("El kilometraje debe ser numerico.");
					return false;
				}
			}
			return true;
		}

		bool ValidarDetalle()
		{
			if (String::IsNullOrWhiteSpace(txtIdServicio->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione o cree una orden de servicio.");
				return false;
			}
			if (cmbRepuesto->SelectedValue == nullptr)
			{
				System::Windows::Forms::MessageBox::Show("Debe seleccionar un repuesto.");
				return false;
			}
			int cantidad = 0;
			Decimal mano = Decimal::Zero;
			if (!Int32::TryParse(txtCantidad->Text, cantidad) || cantidad < 0)
			{
				System::Windows::Forms::MessageBox::Show("La cantidad debe ser numerica.");
				return false;
			}
			if (!Decimal::TryParse(txtManoObra->Text, mano))
			{
				System::Windows::Forms::MessageBox::Show("La mano de obra debe ser numerica.");
				return false;
			}
			return true;
		}

		Object^ ObtenerKilometraje()
		{
			if (String::IsNullOrWhiteSpace(txtKilometraje->Text)) return System::DBNull::Value;
			return Convert::ToInt32(txtKilometraje->Text);
		}

		void RecalcularTotal(int idServicio, MySqlConnection^ cn)
		{
			String^ sqlTotal =
				"SELECT "
				"(SELECT IFNULL(ts.precio,0) FROM servicios s INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio WHERE s.id_servicio=@id) + "
				"IFNULL((SELECT SUM((IFNULL(r.precio,0) * IFNULL(d.cantidad,0)) + IFNULL(d.costo_mano_obra,0)) "
				"FROM detalletrabajo d LEFT JOIN repuestos r ON d.id_repuesto=r.id_repuesto WHERE d.id_servicio=@id),0)";
			MySqlCommand^ cmdTotal = gcnew MySqlCommand(sqlTotal, cn);
			cmdTotal->Parameters->AddWithValue("@id", idServicio);
			Decimal total = Convert::ToDecimal(cmdTotal->ExecuteScalar());

			MySqlCommand^ cmdUpdate = gcnew MySqlCommand("UPDATE servicios SET total=@total WHERE id_servicio=@id", cn);
			cmdUpdate->Parameters->AddWithValue("@total", total);
			cmdUpdate->Parameters->AddWithValue("@id", idServicio);
			cmdUpdate->ExecuteNonQuery();
		}

		void LimpiarDetalle()
		{
			if (cmbRepuesto->Items->Count > 0) cmbRepuesto->SelectedIndex = 0;
			txtCantidad->Text = L"1";
			txtTrabajo->Clear();
			txtManoObra->Text = L"0";
			txtObservacion->Clear();
		}

		void LimpiarTodo()
		{
			txtIdServicio->Clear();
			if (cmbCliente->Items->Count > 0) cmbCliente->SelectedIndex = 0;
			CargarVehiculosPorCliente();
			if (cmbTipoServicio->Items->Count > 0) cmbTipoServicio->SelectedIndex = 0;
			if (cmbMecanico->Items->Count > 0) cmbMecanico->SelectedIndex = 0;
			dtpFecha->Value = DateTime::Now;
			txtKilometraje->Clear();
			txtDescripcion->Clear();
			cmbEstado->SelectedIndex = 0;
			txtBuscar->Clear();
			LimpiarDetalle();
			dgvDetalle->DataSource = nullptr;
		}

		System::Void cmbCliente_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (!cargandoCombos) CargarVehiculosPorCliente();
		}

		System::Void btnCrearOrden_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidarOrden()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"INSERT INTO servicios (id_cliente, id_vehiculo, id_tipo_servicio, id_mecanico, fecha, kilometraje, descripcion, estado) "
					"VALUES (@cliente, @vehiculo, @tipo, @mecanico, @fecha, @km, @descripcion, @estado); "
					"SELECT LAST_INSERT_ID();";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@cliente", cmbCliente->SelectedValue);
				cmd->Parameters->AddWithValue("@vehiculo", cmbVehiculo->SelectedValue);
				cmd->Parameters->AddWithValue("@tipo", cmbTipoServicio->SelectedValue);
				cmd->Parameters->AddWithValue("@mecanico", cmbMecanico->SelectedValue);
				cmd->Parameters->AddWithValue("@fecha", dtpFecha->Value);
				cmd->Parameters->AddWithValue("@km", ObtenerKilometraje());
				cmd->Parameters->AddWithValue("@descripcion", txtDescripcion->Text);
				cmd->Parameters->AddWithValue("@estado", cmbEstado->Text);
				int idServicio = Convert::ToInt32(cmd->ExecuteScalar());
				txtIdServicio->Text = idServicio.ToString();
				RecalcularTotal(idServicio, cn);
				System::Windows::Forms::MessageBox::Show("Orden creada correctamente. No. " + idServicio.ToString());
				ListarServicios("");
				ListarDetalle(idServicio);
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al crear orden: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnActualizarEstado_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (String::IsNullOrWhiteSpace(txtIdServicio->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione una orden de servicio.");
				return;
			}
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				int idServicio = Convert::ToInt32(txtIdServicio->Text);
				String^ estadoAnterior = ObtenerEstadoAnterior(cn, idServicio);
				String^ sql =
					"UPDATE servicios SET estado=@estado, fecha_entrega=CASE WHEN @estado='ENTREGADO' THEN NOW() ELSE fecha_entrega END "
					"WHERE id_servicio=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@estado", cmbEstado->Text);
				cmd->Parameters->AddWithValue("@id", idServicio);
				cmd->ExecuteNonQuery();

				String^ sqlVehiculo = "UPDATE vehiculos v INNER JOIN servicios s ON v.id_vehiculo=s.id_vehiculo SET v.estado=@estado WHERE s.id_servicio=@id";
				MySqlCommand^ cmdVehiculo = gcnew MySqlCommand(sqlVehiculo, cn);
				cmdVehiculo->Parameters->AddWithValue("@estado", cmbEstado->Text);
				cmdVehiculo->Parameters->AddWithValue("@id", idServicio);
				cmdVehiculo->ExecuteNonQuery();

				System::Windows::Forms::MessageBox::Show("Estado actualizado correctamente.");
				ListarServicios(txtBuscar->Text);
				if (cmbEstado->Text == "LISTO" && estadoAnterior != "LISTO")
				{
					EnviarWhatsAppListo(idServicio);
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al actualizar estado: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnAgregarDetalle_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidarDetalle()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				int idServicio = Convert::ToInt32(txtIdServicio->Text);
				int cantidad = Convert::ToInt32(txtCantidad->Text);
				String^ sql =
					"INSERT INTO detalletrabajo (id_servicio, id_repuesto, cantidad, descripcion_trabajo, costo_mano_obra, observacion) "
					"VALUES (@servicio, @repuesto, @cantidad, @trabajo, @mano, @observacion)";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@servicio", idServicio);
				cmd->Parameters->AddWithValue("@repuesto", cmbRepuesto->SelectedValue);
				cmd->Parameters->AddWithValue("@cantidad", cantidad);
				cmd->Parameters->AddWithValue("@trabajo", txtTrabajo->Text);
				cmd->Parameters->AddWithValue("@mano", Convert::ToDecimal(txtManoObra->Text));
				cmd->Parameters->AddWithValue("@observacion", txtObservacion->Text);
				cmd->ExecuteNonQuery();

				if (cantidad > 0)
				{
					MySqlCommand^ cmdStock = gcnew MySqlCommand("UPDATE repuestos SET stock=stock-@cantidad WHERE id_repuesto=@repuesto", cn);
					cmdStock->Parameters->AddWithValue("@cantidad", cantidad);
					cmdStock->Parameters->AddWithValue("@repuesto", cmbRepuesto->SelectedValue);
					cmdStock->ExecuteNonQuery();
				}

				RecalcularTotal(idServicio, cn);
				System::Windows::Forms::MessageBox::Show("Detalle agregado correctamente.");
				LimpiarDetalle();
				CargarRepuestos();
				ListarServicios(txtBuscar->Text);
				ListarDetalle(idServicio);
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al agregar detalle: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ListarServicios(txtBuscar->Text);
		}

		System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			LimpiarTodo();
			ListarServicios("");
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dgvServicios_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvServicios->Rows[e->RowIndex];
				txtIdServicio->Text = ValorCelda(fila, "id_servicio");
				if (!String::IsNullOrWhiteSpace(ValorCelda(fila, "id_cliente")))
				{
					cmbCliente->SelectedValue = Convert::ToInt32(ValorCelda(fila, "id_cliente"));
					CargarVehiculosPorCliente();
				}
				if (!String::IsNullOrWhiteSpace(ValorCelda(fila, "id_vehiculo"))) cmbVehiculo->SelectedValue = Convert::ToInt32(ValorCelda(fila, "id_vehiculo"));
				if (!String::IsNullOrWhiteSpace(ValorCelda(fila, "id_tipo_servicio"))) cmbTipoServicio->SelectedValue = Convert::ToInt32(ValorCelda(fila, "id_tipo_servicio"));
				if (!String::IsNullOrWhiteSpace(ValorCelda(fila, "id_mecanico"))) cmbMecanico->SelectedValue = Convert::ToInt32(ValorCelda(fila, "id_mecanico"));
				txtKilometraje->Text = ValorCelda(fila, "kilometraje");
				txtDescripcion->Text = ValorCelda(fila, "descripcion");
				if (!String::IsNullOrWhiteSpace(ValorCelda(fila, "estado"))) cmbEstado->Text = ValorCelda(fila, "estado");
				ListarDetalle(Convert::ToInt32(txtIdServicio->Text));
			}
		}
	};
}
