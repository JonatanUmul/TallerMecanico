#pragma once
#include "Conexion.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;

	public ref class FormClientes : public System::Windows::Forms::Form
	{
	public:
		FormClientes(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormClientes::FormClientes_Load);
		}

	protected:
		~FormClientes()
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
		System::Windows::Forms::TextBox^ txtIdCliente;
		System::Windows::Forms::TextBox^ txtNit;
		System::Windows::Forms::TextBox^ txtNombre;
		System::Windows::Forms::TextBox^ txtEdad;
		System::Windows::Forms::TextBox^ txtDireccion;
		System::Windows::Forms::TextBox^ txtCorreo;
		System::Windows::Forms::TextBox^ txtTelefono;
		System::Windows::Forms::TextBox^ txtBuscar;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblNit;
		System::Windows::Forms::Label^ lblNombre;
		System::Windows::Forms::Label^ lblEdad;
		System::Windows::Forms::Label^ lblDireccion;
		System::Windows::Forms::Label^ lblCorreo;
		System::Windows::Forms::Label^ lblTelefono;
		System::Windows::Forms::Label^ lblBuscar;
		System::Windows::Forms::Button^ btnGuardar;
		System::Windows::Forms::Button^ btnModificar;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Button^ btnRegresar;
		System::Windows::Forms::DataGridView^ dgvClientes;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelIzquierdo = gcnew System::Windows::Forms::Panel();
			this->panelDerecho = gcnew System::Windows::Forms::Panel();
			this->txtIdCliente = gcnew System::Windows::Forms::TextBox();
			this->txtNit = gcnew System::Windows::Forms::TextBox();
			this->txtNombre = gcnew System::Windows::Forms::TextBox();
			this->txtEdad = gcnew System::Windows::Forms::TextBox();
			this->txtDireccion = gcnew System::Windows::Forms::TextBox();
			this->txtCorreo = gcnew System::Windows::Forms::TextBox();
			this->txtTelefono = gcnew System::Windows::Forms::TextBox();
			this->txtBuscar = gcnew System::Windows::Forms::TextBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblNit = gcnew System::Windows::Forms::Label();
			this->lblNombre = gcnew System::Windows::Forms::Label();
			this->lblEdad = gcnew System::Windows::Forms::Label();
			this->lblDireccion = gcnew System::Windows::Forms::Label();
			this->lblCorreo = gcnew System::Windows::Forms::Label();
			this->lblTelefono = gcnew System::Windows::Forms::Label();
			this->lblBuscar = gcnew System::Windows::Forms::Label();
			this->btnGuardar = gcnew System::Windows::Forms::Button();
			this->btnModificar = gcnew System::Windows::Forms::Button();
			this->btnEliminar = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnBuscar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvClientes = gcnew System::Windows::Forms::DataGridView();
			this->SuspendLayout();

			this->Text = L"Modulo Clientes";
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

			this->txtIdCliente->Visible = false;
			this->lblTitulo->Text = L"Registro de Clientes";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(30, 25);
			this->lblTitulo->AutoSize = true;

			this->lblNit->Text = L"NIT:";
			this->lblNit->Location = System::Drawing::Point(35, 95);
			this->lblNit->AutoSize = true;
			this->txtNit->Location = System::Drawing::Point(145, 90);
			this->txtNit->Size = System::Drawing::Size(260, 25);

			this->lblNombre->Text = L"Nombre:";
			this->lblNombre->Location = System::Drawing::Point(35, 135);
			this->lblNombre->AutoSize = true;
			this->txtNombre->Location = System::Drawing::Point(145, 130);
			this->txtNombre->Size = System::Drawing::Size(290, 25);

			this->lblEdad->Text = L"Edad:";
			this->lblEdad->Location = System::Drawing::Point(35, 175);
			this->lblEdad->AutoSize = true;
			this->txtEdad->Location = System::Drawing::Point(145, 170);
			this->txtEdad->Size = System::Drawing::Size(120, 25);

			this->lblDireccion->Text = L"Direccion:";
			this->lblDireccion->Location = System::Drawing::Point(35, 215);
			this->lblDireccion->AutoSize = true;
			this->txtDireccion->Location = System::Drawing::Point(145, 210);
			this->txtDireccion->Size = System::Drawing::Size(290, 25);

			this->lblCorreo->Text = L"Correo:";
			this->lblCorreo->Location = System::Drawing::Point(35, 255);
			this->lblCorreo->AutoSize = true;
			this->txtCorreo->Location = System::Drawing::Point(145, 250);
			this->txtCorreo->Size = System::Drawing::Size(290, 25);

			this->lblTelefono->Text = L"Telefono:";
			this->lblTelefono->Location = System::Drawing::Point(35, 295);
			this->lblTelefono->AutoSize = true;
			this->txtTelefono->Location = System::Drawing::Point(145, 290);
			this->txtTelefono->Size = System::Drawing::Size(180, 25);

			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->Location = System::Drawing::Point(35, 350);
			this->btnGuardar->Size = System::Drawing::Size(95, 38);
			this->btnGuardar->Click += gcnew System::EventHandler(this, &FormClientes::btnGuardar_Click);

			this->btnModificar->Text = L"Modificar";
			this->btnModificar->Location = System::Drawing::Point(140, 350);
			this->btnModificar->Size = System::Drawing::Size(95, 38);
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormClientes::btnModificar_Click);

			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Location = System::Drawing::Point(245, 350);
			this->btnEliminar->Size = System::Drawing::Size(95, 38);
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormClientes::btnEliminar_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(350, 350);
			this->btnLimpiar->Size = System::Drawing::Size(95, 38);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormClientes::btnLimpiar_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(35, 405);
			this->btnRegresar->Size = System::Drawing::Size(410, 38);
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormClientes::btnRegresar_Click);

			this->lblBuscar->Text = L"Buscar por nombre o NIT:";
			this->lblBuscar->Location = System::Drawing::Point(20, 35);
			this->lblBuscar->AutoSize = true;
			this->txtBuscar->Location = System::Drawing::Point(20, 65);
			this->txtBuscar->Size = System::Drawing::Size(260, 25);
			this->txtBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->txtBuscar->TextChanged += gcnew System::EventHandler(this, &FormClientes::txtBuscar_TextChanged);
			this->txtBuscar->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormClientes::txtBuscar_KeyDown);

			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->Location = System::Drawing::Point(300, 61);
			this->btnBuscar->Size = System::Drawing::Size(110, 34);
			this->btnBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormClientes::btnBuscar_Click);

			this->dgvClientes->Location = System::Drawing::Point(20, 115);
			this->dgvClientes->Size = System::Drawing::Size(660, 520);
			this->dgvClientes->ReadOnly = true;
			this->dgvClientes->AllowUserToAddRows = false;
			this->dgvClientes->AllowUserToDeleteRows = false;
			this->dgvClientes->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvClientes->MultiSelect = false;
			this->dgvClientes->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvClientes->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dgvClientes->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvClientes->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvClientes->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormClientes::dgvClientes_CellClick);

			this->panelIzquierdo->Controls->Add(this->txtIdCliente);
			this->panelIzquierdo->Controls->Add(this->lblTitulo);
			this->panelIzquierdo->Controls->Add(this->lblNit);
			this->panelIzquierdo->Controls->Add(this->txtNit);
			this->panelIzquierdo->Controls->Add(this->lblNombre);
			this->panelIzquierdo->Controls->Add(this->txtNombre);
			this->panelIzquierdo->Controls->Add(this->lblEdad);
			this->panelIzquierdo->Controls->Add(this->txtEdad);
			this->panelIzquierdo->Controls->Add(this->lblDireccion);
			this->panelIzquierdo->Controls->Add(this->txtDireccion);
			this->panelIzquierdo->Controls->Add(this->lblCorreo);
			this->panelIzquierdo->Controls->Add(this->txtCorreo);
			this->panelIzquierdo->Controls->Add(this->lblTelefono);
			this->panelIzquierdo->Controls->Add(this->txtTelefono);
			this->panelIzquierdo->Controls->Add(this->btnGuardar);
			this->panelIzquierdo->Controls->Add(this->btnModificar);
			this->panelIzquierdo->Controls->Add(this->btnEliminar);
			this->panelIzquierdo->Controls->Add(this->btnLimpiar);
			this->panelIzquierdo->Controls->Add(this->btnRegresar);
			this->panelDerecho->Controls->Add(this->lblBuscar);
			this->panelDerecho->Controls->Add(this->txtBuscar);
			this->panelDerecho->Controls->Add(this->dgvClientes);
			this->Controls->Add(this->panelDerecho);
			this->Controls->Add(this->panelIzquierdo);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormClientes_Load(System::Object^ sender, System::EventArgs^ e)
		{
			ListarClientes();
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		Object^ ObtenerEdadValor()
		{
			if (String::IsNullOrWhiteSpace(txtEdad->Text)) return System::DBNull::Value;
			return Convert::ToInt32(txtEdad->Text);
		}

		void FormatearTabla()
		{
			if (dgvClientes->Columns->Contains("id_cliente")) dgvClientes->Columns["id_cliente"]->Visible = false;
			if (dgvClientes->Columns->Contains("nit")) dgvClientes->Columns["nit"]->HeaderText = "NIT";
			if (dgvClientes->Columns->Contains("nombre")) dgvClientes->Columns["nombre"]->HeaderText = "Nombre";
			if (dgvClientes->Columns->Contains("edad")) dgvClientes->Columns["edad"]->HeaderText = "Edad";
			if (dgvClientes->Columns->Contains("direccion")) dgvClientes->Columns["direccion"]->HeaderText = "Direccion";
			if (dgvClientes->Columns->Contains("correo")) dgvClientes->Columns["correo"]->HeaderText = "Correo";
			if (dgvClientes->Columns->Contains("telefono")) dgvClientes->Columns["telefono"]->HeaderText = "Telefono";
			dgvClientes->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
		}

		void ListarClientes()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "SELECT id_cliente, nit, nombre, edad, direccion, correo, telefono FROM clientes ORDER BY id_cliente DESC";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvClientes->DataSource = dt;
				FormatearTabla();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar clientes: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void BuscarClientes()
		{
			String^ buscar = txtBuscar->Text->Trim();
			if (String::IsNullOrWhiteSpace(buscar))
			{
				ListarClientes();
				return;
			}

			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql =
					"SELECT id_cliente, nit, nombre, edad, direccion, correo, telefono "
					"FROM clientes "
					"WHERE nombre LIKE @buscar OR CAST(nit AS CHAR) LIKE @buscar "
					"ORDER BY id_cliente DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@buscar", "%" + buscar + "%");
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvClientes->DataSource = dt;
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

		void Limpiar()
		{
			txtIdCliente->Clear();
			txtNit->Clear();
			txtNombre->Clear();
			txtEdad->Clear();
			txtDireccion->Clear();
			txtCorreo->Clear();
			txtTelefono->Clear();
			txtBuscar->Clear();
			txtNit->Focus();
		}

		bool ValidarCampos()
		{
			if (String::IsNullOrWhiteSpace(txtNit->Text) ||
				String::IsNullOrWhiteSpace(txtNombre->Text) ||
				String::IsNullOrWhiteSpace(txtTelefono->Text))
			{
				System::Windows::Forms::MessageBox::Show("Debe ingresar NIT, nombre y telefono.");
				return false;
			}
			int nit = 0;
			if (!Int32::TryParse(txtNit->Text, nit))
			{
				System::Windows::Forms::MessageBox::Show("El NIT debe ser numerico.");
				return false;
			}
			if (!String::IsNullOrWhiteSpace(txtEdad->Text))
			{
				int edad = 0;
				if (!Int32::TryParse(txtEdad->Text, edad))
				{
					System::Windows::Forms::MessageBox::Show("La edad debe ser numerica.");
					return false;
				}
			}
			return true;
		}

		System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "INSERT INTO clientes (nit, nombre, edad, direccion, correo, telefono) VALUES (@nit, @nombre, @edad, @direccion, @correo, @telefono)";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@nit", Convert::ToInt32(txtNit->Text));
				cmd->Parameters->AddWithValue("@nombre", txtNombre->Text);
				cmd->Parameters->AddWithValue("@edad", ObtenerEdadValor());
				cmd->Parameters->AddWithValue("@direccion", txtDireccion->Text);
				cmd->Parameters->AddWithValue("@correo", txtCorreo->Text);
				cmd->Parameters->AddWithValue("@telefono", txtTelefono->Text);
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Cliente guardado correctamente.");
				Limpiar();
				ListarClientes();
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
			if (String::IsNullOrWhiteSpace(txtIdCliente->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un cliente de la tabla.");
				return;
			}
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "UPDATE clientes SET nit=@nit, nombre=@nombre, edad=@edad, direccion=@direccion, correo=@correo, telefono=@telefono WHERE id_cliente=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdCliente->Text));
				cmd->Parameters->AddWithValue("@nit", Convert::ToInt32(txtNit->Text));
				cmd->Parameters->AddWithValue("@nombre", txtNombre->Text);
				cmd->Parameters->AddWithValue("@edad", ObtenerEdadValor());
				cmd->Parameters->AddWithValue("@direccion", txtDireccion->Text);
				cmd->Parameters->AddWithValue("@correo", txtCorreo->Text);
				cmd->Parameters->AddWithValue("@telefono", txtTelefono->Text);
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Cliente modificado correctamente.");
				Limpiar();
				ListarClientes();
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
			if (String::IsNullOrWhiteSpace(txtIdCliente->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un cliente de la tabla.");
				return;
			}
			if (System::Windows::Forms::MessageBox::Show("Desea eliminar este cliente?", "Confirmar", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "DELETE FROM clientes WHERE id_cliente=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdCliente->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Cliente eliminado correctamente.");
				Limpiar();
				ListarClientes();
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
			BuscarClientes();
		}

		System::Void txtBuscar_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			BuscarClientes();
		}

		System::Void txtBuscar_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == System::Windows::Forms::Keys::Enter)
			{
				BuscarClientes();
				e->SuppressKeyPress = true;
			}
		}

		System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Limpiar();
			ListarClientes();
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dgvClientes_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvClientes->Rows[e->RowIndex];
				txtIdCliente->Text = ValorCelda(fila, "id_cliente");
				txtNit->Text = ValorCelda(fila, "nit");
				txtNombre->Text = ValorCelda(fila, "nombre");
				txtEdad->Text = ValorCelda(fila, "edad");
				txtDireccion->Text = ValorCelda(fila, "direccion");
				txtCorreo->Text = ValorCelda(fila, "correo");
				txtTelefono->Text = ValorCelda(fila, "telefono");
			}
		}
	};
}
