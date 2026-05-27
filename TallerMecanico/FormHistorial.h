#pragma once
#include "Conexion.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;

	public ref class FormHistorial : public System::Windows::Forms::Form
	{
	public:
		FormHistorial(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormHistorial::FormHistorial_Load);
		}

	protected:
		~FormHistorial()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Panel^ panelSuperior;
		System::Windows::Forms::Panel^ panelCentral;
		System::Windows::Forms::TextBox^ txtBuscar;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblBuscar;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnRegresar;
		System::Windows::Forms::DataGridView^ dgvHistorial;
		System::Windows::Forms::DataGridView^ dgvDetalle;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelSuperior = gcnew System::Windows::Forms::Panel();
			this->panelCentral = gcnew System::Windows::Forms::Panel();
			this->txtBuscar = gcnew System::Windows::Forms::TextBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblBuscar = gcnew System::Windows::Forms::Label();
			this->btnBuscar = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvHistorial = gcnew System::Windows::Forms::DataGridView();
			this->dgvDetalle = gcnew System::Windows::Forms::DataGridView();
			this->SuspendLayout();

			this->Text = L"Historial de Servicios";
			this->ClientSize = System::Drawing::Size(1180, 700);
			this->MinimumSize = System::Drawing::Size(980, 560);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

			this->panelSuperior->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelSuperior->Height = 125;
			this->panelSuperior->Padding = System::Windows::Forms::Padding(25);

			this->panelCentral->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelCentral->Padding = System::Windows::Forms::Padding(25);

			this->lblTitulo->Text = L"Historial de Servicios";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(25, 18);
			this->lblTitulo->AutoSize = true;

			this->lblBuscar->Text = L"Buscar por cliente, placa, mecanico o estado:";
			this->lblBuscar->Location = System::Drawing::Point(30, 70);
			this->lblBuscar->AutoSize = true;

			this->txtBuscar->Location = System::Drawing::Point(300, 66);
			this->txtBuscar->Size = System::Drawing::Size(430, 25);
			this->txtBuscar->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));

			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->Location = System::Drawing::Point(750, 62);
			this->btnBuscar->Size = System::Drawing::Size(110, 34);
			this->btnBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormHistorial::btnBuscar_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(870, 62);
			this->btnLimpiar->Size = System::Drawing::Size(110, 34);
			this->btnLimpiar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormHistorial::btnLimpiar_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(990, 62);
			this->btnRegresar->Size = System::Drawing::Size(150, 34);
			this->btnRegresar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormHistorial::btnRegresar_Click);

			this->dgvHistorial->Location = System::Drawing::Point(25, 25);
			this->dgvHistorial->Size = System::Drawing::Size(1100, 300);
			this->dgvHistorial->ReadOnly = true;
			this->dgvHistorial->AllowUserToAddRows = false;
			this->dgvHistorial->AllowUserToDeleteRows = false;
			this->dgvHistorial->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvHistorial->MultiSelect = false;
			this->dgvHistorial->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvHistorial->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvHistorial->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormHistorial::dgvHistorial_CellClick);

			this->dgvDetalle->Location = System::Drawing::Point(25, 350);
			this->dgvDetalle->Size = System::Drawing::Size(1100, 260);
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->AllowUserToAddRows = false;
			this->dgvDetalle->AllowUserToDeleteRows = false;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDetalle->MultiSelect = false;
			this->dgvDetalle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDetalle->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));

			this->panelSuperior->Controls->Add(this->lblTitulo);
			this->panelSuperior->Controls->Add(this->lblBuscar);
			this->panelSuperior->Controls->Add(this->txtBuscar);
			this->panelSuperior->Controls->Add(this->btnBuscar);
			this->panelSuperior->Controls->Add(this->btnLimpiar);
			this->panelSuperior->Controls->Add(this->btnRegresar);
			this->panelCentral->Controls->Add(this->dgvHistorial);
			this->panelCentral->Controls->Add(this->dgvDetalle);
			this->Controls->Add(this->panelCentral);
			this->Controls->Add(this->panelSuperior);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormHistorial_Load(System::Object^ sender, System::EventArgs^ e)
		{
			ListarHistorial("");
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void ListarHistorial(String^ buscar)
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT s.id_servicio, c.nombre AS cliente, c.telefono, v.placa, v.marca, v.modelo, "
					"ts.tipo AS servicio, m.nombre AS mecanico, s.fecha, s.fecha_ingreso, s.fecha_entrega, "
					"s.kilometraje, s.estado, s.total, s.descripcion "
					"FROM servicios s "
					"INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
					"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
					"INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio "
					"INNER JOIN mecanico m ON s.id_mecanico=m.id_mecanico "
					"WHERE c.nombre LIKE @buscar OR v.placa LIKE @buscar OR m.nombre LIKE @buscar OR s.estado LIKE @buscar "
					"ORDER BY s.id_servicio DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@buscar", "%" + buscar + "%");
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvHistorial->DataSource = dt;
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar historial: " + ex->Message);
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
					"SELECT d.id_detalle, r.nombre AS repuesto, r.marca, d.cantidad, d.descripcion_trabajo, "
					"d.costo_mano_obra, d.observacion, d.fecha, "
					"((IFNULL(r.precio,0) * IFNULL(d.cantidad,0)) + IFNULL(d.costo_mano_obra,0)) AS subtotal "
					"FROM detalletrabajo d LEFT JOIN repuestos r ON d.id_repuesto=r.id_repuesto "
					"WHERE d.id_servicio=@servicio ORDER BY d.id_detalle DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@servicio", idServicio);
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvDetalle->DataSource = dt;
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

		System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ListarHistorial(txtBuscar->Text);
		}

		System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			txtBuscar->Clear();
			dgvDetalle->DataSource = nullptr;
			ListarHistorial("");
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dgvHistorial_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvHistorial->Rows[e->RowIndex];
				String^ id = ValorCelda(fila, "id_servicio");
				if (!String::IsNullOrWhiteSpace(id))
				{
					ListarDetalle(Convert::ToInt32(id));
				}
			}
		}
	};
}

