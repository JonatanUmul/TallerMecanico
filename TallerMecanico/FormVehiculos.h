#pragma once
#include "Conexion.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;

	public ref class FormVehiculos : public System::Windows::Forms::Form
	{
	public:
		FormVehiculos(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormVehiculos::FormVehiculos_Load);
		}

	protected:
		~FormVehiculos()
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
		System::Windows::Forms::TextBox^ txtIdVehiculo;
		System::Windows::Forms::TextBox^ txtPlaca;
		System::Windows::Forms::TextBox^ txtChasis;
		System::Windows::Forms::TextBox^ txtMarca;
		System::Windows::Forms::TextBox^ txtModelo;
		System::Windows::Forms::TextBox^ txtTipo;
		System::Windows::Forms::TextBox^ txtEstado;
		System::Windows::Forms::TextBox^ txtBuscar;
		System::Windows::Forms::ComboBox^ cmbCliente;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblCliente;
		System::Windows::Forms::Label^ lblPlaca;
		System::Windows::Forms::Label^ lblChasis;
		System::Windows::Forms::Label^ lblMarca;
		System::Windows::Forms::Label^ lblModelo;
		System::Windows::Forms::Label^ lblTipo;
		System::Windows::Forms::Label^ lblEstado;
		System::Windows::Forms::Label^ lblBuscar;
		System::Windows::Forms::Button^ btnGuardar;
		System::Windows::Forms::Button^ btnModificar;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Button^ btnRegresar;
		System::Windows::Forms::DataGridView^ dgvVehiculos;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelIzquierdo = gcnew System::Windows::Forms::Panel();
			this->panelDerecho = gcnew System::Windows::Forms::Panel();
			this->txtIdVehiculo = gcnew System::Windows::Forms::TextBox();
			this->txtPlaca = gcnew System::Windows::Forms::TextBox();
			this->txtChasis = gcnew System::Windows::Forms::TextBox();
			this->txtMarca = gcnew System::Windows::Forms::TextBox();
			this->txtModelo = gcnew System::Windows::Forms::TextBox();
			this->txtTipo = gcnew System::Windows::Forms::TextBox();
			this->txtEstado = gcnew System::Windows::Forms::TextBox();
			this->txtBuscar = gcnew System::Windows::Forms::TextBox();
			this->cmbCliente = gcnew System::Windows::Forms::ComboBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblCliente = gcnew System::Windows::Forms::Label();
			this->lblPlaca = gcnew System::Windows::Forms::Label();
			this->lblChasis = gcnew System::Windows::Forms::Label();
			this->lblMarca = gcnew System::Windows::Forms::Label();
			this->lblModelo = gcnew System::Windows::Forms::Label();
			this->lblTipo = gcnew System::Windows::Forms::Label();
			this->lblEstado = gcnew System::Windows::Forms::Label();
			this->lblBuscar = gcnew System::Windows::Forms::Label();
			this->btnGuardar = gcnew System::Windows::Forms::Button();
			this->btnModificar = gcnew System::Windows::Forms::Button();
			this->btnEliminar = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnBuscar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvVehiculos = gcnew System::Windows::Forms::DataGridView();
			this->SuspendLayout();

			this->Text = L"Modulo Vehiculos";
			this->ClientSize = System::Drawing::Size(1180, 700);
			this->MinimumSize = System::Drawing::Size(980, 560);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

			this->panelIzquierdo->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelIzquierdo->Width = 470;
			this->panelIzquierdo->Padding = System::Windows::Forms::Padding(30);
			this->panelIzquierdo->AutoScroll = true;
			this->panelDerecho->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDerecho->Padding = System::Windows::Forms::Padding(20);

			this->txtIdVehiculo->Visible = false;
			this->lblTitulo->Text = L"Registro de Vehiculos";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(30, 25);
			this->lblTitulo->AutoSize = true;

			this->lblCliente->Text = L"Cliente:";
			this->lblCliente->Location = System::Drawing::Point(35, 95);
			this->lblCliente->AutoSize = true;
			this->cmbCliente->Location = System::Drawing::Point(145, 90);
			this->cmbCliente->Size = System::Drawing::Size(290, 25);
			this->cmbCliente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->lblPlaca->Text = L"Placa:";
			this->lblPlaca->Location = System::Drawing::Point(35, 135);
			this->lblPlaca->AutoSize = true;
			this->txtPlaca->Location = System::Drawing::Point(145, 130);
			this->txtPlaca->Size = System::Drawing::Size(160, 25);

			this->lblChasis->Text = L"Chasis:";
			this->lblChasis->Location = System::Drawing::Point(35, 175);
			this->lblChasis->AutoSize = true;
			this->txtChasis->Location = System::Drawing::Point(145, 170);
			this->txtChasis->Size = System::Drawing::Size(220, 25);

			this->lblMarca->Text = L"Marca:";
			this->lblMarca->Location = System::Drawing::Point(35, 215);
			this->lblMarca->AutoSize = true;
			this->txtMarca->Location = System::Drawing::Point(145, 210);
			this->txtMarca->Size = System::Drawing::Size(220, 25);

			this->lblModelo->Text = L"Modelo:";
			this->lblModelo->Location = System::Drawing::Point(35, 255);
			this->lblModelo->AutoSize = true;
			this->txtModelo->Location = System::Drawing::Point(145, 250);
			this->txtModelo->Size = System::Drawing::Size(220, 25);

			this->lblTipo->Text = L"Tipo:";
			this->lblTipo->Location = System::Drawing::Point(35, 295);
			this->lblTipo->AutoSize = true;
			this->txtTipo->Location = System::Drawing::Point(145, 290);
			this->txtTipo->Size = System::Drawing::Size(220, 25);

			this->lblEstado->Text = L"Estado:";
			this->lblEstado->Location = System::Drawing::Point(35, 335);
			this->lblEstado->AutoSize = true;
			this->txtEstado->Location = System::Drawing::Point(145, 330);
			this->txtEstado->Size = System::Drawing::Size(220, 25);

			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->Location = System::Drawing::Point(35, 395);
			this->btnGuardar->Size = System::Drawing::Size(95, 38);
			this->btnGuardar->Click += gcnew System::EventHandler(this, &FormVehiculos::btnGuardar_Click);

			this->btnModificar->Text = L"Modificar";
			this->btnModificar->Location = System::Drawing::Point(140, 395);
			this->btnModificar->Size = System::Drawing::Size(95, 38);
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormVehiculos::btnModificar_Click);

			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Location = System::Drawing::Point(245, 395);
			this->btnEliminar->Size = System::Drawing::Size(95, 38);
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormVehiculos::btnEliminar_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(350, 395);
			this->btnLimpiar->Size = System::Drawing::Size(95, 38);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormVehiculos::btnLimpiar_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(35, 450);
			this->btnRegresar->Size = System::Drawing::Size(410, 38);
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormVehiculos::btnRegresar_Click);

			this->lblBuscar->Text = L"Buscar por placa, cliente, marca o modelo:";
			this->lblBuscar->Location = System::Drawing::Point(20, 35);
			this->lblBuscar->AutoSize = true;
			this->txtBuscar->Location = System::Drawing::Point(20, 65);
			this->txtBuscar->Size = System::Drawing::Size(500, 25);
			this->txtBuscar->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));

			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->Location = System::Drawing::Point(540, 61);
			this->btnBuscar->Size = System::Drawing::Size(120, 34);
			this->btnBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormVehiculos::btnBuscar_Click);

			this->dgvVehiculos->Location = System::Drawing::Point(20, 115);
			this->dgvVehiculos->Size = System::Drawing::Size(660, 520);
			this->dgvVehiculos->ReadOnly = true;
			this->dgvVehiculos->AllowUserToAddRows = false;
			this->dgvVehiculos->AllowUserToDeleteRows = false;
			this->dgvVehiculos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvVehiculos->MultiSelect = false;
			this->dgvVehiculos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvVehiculos->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dgvVehiculos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvVehiculos->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvVehiculos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormVehiculos::dgvVehiculos_CellClick);

			this->panelIzquierdo->Controls->Add(this->txtIdVehiculo);
			this->panelIzquierdo->Controls->Add(this->lblTitulo);
			this->panelIzquierdo->Controls->Add(this->lblCliente);
			this->panelIzquierdo->Controls->Add(this->cmbCliente);
			this->panelIzquierdo->Controls->Add(this->lblPlaca);
			this->panelIzquierdo->Controls->Add(this->txtPlaca);
			this->panelIzquierdo->Controls->Add(this->lblChasis);
			this->panelIzquierdo->Controls->Add(this->txtChasis);
			this->panelIzquierdo->Controls->Add(this->lblMarca);
			this->panelIzquierdo->Controls->Add(this->txtMarca);
			this->panelIzquierdo->Controls->Add(this->lblModelo);
			this->panelIzquierdo->Controls->Add(this->txtModelo);
			this->panelIzquierdo->Controls->Add(this->lblTipo);
			this->panelIzquierdo->Controls->Add(this->txtTipo);
			this->panelIzquierdo->Controls->Add(this->lblEstado);
			this->panelIzquierdo->Controls->Add(this->txtEstado);
			this->panelIzquierdo->Controls->Add(this->btnGuardar);
			this->panelIzquierdo->Controls->Add(this->btnModificar);
			this->panelIzquierdo->Controls->Add(this->btnEliminar);
			this->panelIzquierdo->Controls->Add(this->btnLimpiar);
			this->panelIzquierdo->Controls->Add(this->btnRegresar);
			this->panelDerecho->Controls->Add(this->lblBuscar);
			this->panelDerecho->Controls->Add(this->txtBuscar);
			this->panelDerecho->Controls->Add(this->btnBuscar);
			this->panelDerecho->Controls->Add(this->dgvVehiculos);
			this->Controls->Add(this->panelDerecho);
			this->Controls->Add(this->panelIzquierdo);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormVehiculos_Load(System::Object^ sender, System::EventArgs^ e)
		{
			CargarClientes();
			ListarVehiculos();
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void FormatearTabla()
		{
			if (dgvVehiculos->Columns->Contains("id_vehiculo")) dgvVehiculos->Columns["id_vehiculo"]->Visible = false;
			if (dgvVehiculos->Columns->Contains("id_cliente")) dgvVehiculos->Columns["id_cliente"]->Visible = false;
			if (dgvVehiculos->Columns->Contains("cliente")) dgvVehiculos->Columns["cliente"]->HeaderText = "Cliente";
			if (dgvVehiculos->Columns->Contains("placa")) dgvVehiculos->Columns["placa"]->HeaderText = "Placa";
			if (dgvVehiculos->Columns->Contains("n_chasis")) dgvVehiculos->Columns["n_chasis"]->HeaderText = "Chasis";
			if (dgvVehiculos->Columns->Contains("marca")) dgvVehiculos->Columns["marca"]->HeaderText = "Marca";
			if (dgvVehiculos->Columns->Contains("modelo")) dgvVehiculos->Columns["modelo"]->HeaderText = "Modelo";
			if (dgvVehiculos->Columns->Contains("tipo")) dgvVehiculos->Columns["tipo"]->HeaderText = "Tipo";
			if (dgvVehiculos->Columns->Contains("estado")) dgvVehiculos->Columns["estado"]->HeaderText = "Estado";
			dgvVehiculos->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
		}

		void CargarClientes()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "SELECT id_cliente, CONCAT(nit, ' - ', nombre) AS cliente FROM clientes ORDER BY nombre";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				cmbCliente->DataSource = dt;
				cmbCliente->DisplayMember = "cliente";
				cmbCliente->ValueMember = "id_cliente";
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al cargar clientes: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		bool ValidarCampos()
		{
			if (cmbCliente->SelectedValue == nullptr ||
				String::IsNullOrWhiteSpace(txtPlaca->Text))
			{
				System::Windows::Forms::MessageBox::Show("Debe seleccionar cliente e ingresar placa.");
				return false;
			}
			return true;
		}

		void ListarVehiculos()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT v.id_vehiculo, v.id_cliente, c.nombre AS cliente, v.placa, v.n_chasis, "
					"v.marca, v.modelo, v.tipo, v.estado "
					"FROM vehiculos v INNER JOIN clientes c ON v.id_cliente = c.id_cliente "
					"ORDER BY v.id_vehiculo DESC";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvVehiculos->DataSource = dt;
				FormatearTabla();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar vehiculos: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void Limpiar()
		{
			txtIdVehiculo->Clear();
			txtPlaca->Clear();
			txtChasis->Clear();
			txtMarca->Clear();
			txtModelo->Clear();
			txtTipo->Clear();
			txtEstado->Clear();
			txtBuscar->Clear();
			if (cmbCliente->Items->Count > 0) cmbCliente->SelectedIndex = 0;
			txtPlaca->Focus();
		}

		System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "INSERT INTO vehiculos (id_cliente, placa, n_chasis, marca, modelo, tipo, estado) VALUES (@cliente, @placa, @chasis, @marca, @modelo, @tipo, @estado)";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@cliente", cmbCliente->SelectedValue);
				cmd->Parameters->AddWithValue("@placa", txtPlaca->Text);
				cmd->Parameters->AddWithValue("@chasis", txtChasis->Text);
				cmd->Parameters->AddWithValue("@marca", txtMarca->Text);
				cmd->Parameters->AddWithValue("@modelo", txtModelo->Text);
				cmd->Parameters->AddWithValue("@tipo", txtTipo->Text);
				cmd->Parameters->AddWithValue("@estado", txtEstado->Text);
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Vehiculo guardado correctamente.");
				Limpiar();
				ListarVehiculos();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al guardar: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (String::IsNullOrWhiteSpace(txtIdVehiculo->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un vehiculo de la tabla.");
				return;
			}
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "UPDATE vehiculos SET id_cliente=@cliente, placa=@placa, n_chasis=@chasis, marca=@marca, modelo=@modelo, tipo=@tipo, estado=@estado WHERE id_vehiculo=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdVehiculo->Text));
				cmd->Parameters->AddWithValue("@cliente", cmbCliente->SelectedValue);
				cmd->Parameters->AddWithValue("@placa", txtPlaca->Text);
				cmd->Parameters->AddWithValue("@chasis", txtChasis->Text);
				cmd->Parameters->AddWithValue("@marca", txtMarca->Text);
				cmd->Parameters->AddWithValue("@modelo", txtModelo->Text);
				cmd->Parameters->AddWithValue("@tipo", txtTipo->Text);
				cmd->Parameters->AddWithValue("@estado", txtEstado->Text);
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Vehiculo modificado correctamente.");
				Limpiar();
				ListarVehiculos();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al modificar: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (String::IsNullOrWhiteSpace(txtIdVehiculo->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un vehiculo de la tabla.");
				return;
			}
			if (System::Windows::Forms::MessageBox::Show("Desea eliminar este vehiculo?", "Confirmar", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "DELETE FROM vehiculos WHERE id_vehiculo=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdVehiculo->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Vehiculo eliminado correctamente.");
				Limpiar();
				ListarVehiculos();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al eliminar: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT v.id_vehiculo, v.id_cliente, c.nombre AS cliente, v.placa, v.n_chasis, "
					"v.marca, v.modelo, v.tipo, v.estado "
					"FROM vehiculos v INNER JOIN clientes c ON v.id_cliente = c.id_cliente "
					"WHERE v.placa LIKE @buscar OR c.nombre LIKE @buscar OR v.marca LIKE @buscar OR v.modelo LIKE @buscar "
					"ORDER BY v.id_vehiculo DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@buscar", "%" + txtBuscar->Text + "%");
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvVehiculos->DataSource = dt;
				FormatearTabla();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al buscar: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Limpiar();
			ListarVehiculos();
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dgvVehiculos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvVehiculos->Rows[e->RowIndex];
				txtIdVehiculo->Text = ValorCelda(fila, "id_vehiculo");
				if (!String::IsNullOrWhiteSpace(ValorCelda(fila, "id_cliente")))
				{
					cmbCliente->SelectedValue = Convert::ToInt32(ValorCelda(fila, "id_cliente"));
				}
				txtPlaca->Text = ValorCelda(fila, "placa");
				txtChasis->Text = ValorCelda(fila, "n_chasis");
				txtMarca->Text = ValorCelda(fila, "marca");
				txtModelo->Text = ValorCelda(fila, "modelo");
				txtTipo->Text = ValorCelda(fila, "tipo");
				txtEstado->Text = ValorCelda(fila, "estado");
			}
		}
	};
}
