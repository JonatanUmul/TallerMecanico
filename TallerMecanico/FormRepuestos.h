#pragma once
#include "Conexion.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;

	public ref class FormRepuestos : public System::Windows::Forms::Form
	{
	public:
		FormRepuestos(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormRepuestos::FormRepuestos_Load);
		}

	protected:
		~FormRepuestos()
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
		System::Windows::Forms::TextBox^ txtIdRepuesto;
		System::Windows::Forms::TextBox^ txtNombre;
		System::Windows::Forms::TextBox^ txtMarca;
		System::Windows::Forms::TextBox^ txtPrecio;
		System::Windows::Forms::TextBox^ txtStock;
		System::Windows::Forms::TextBox^ txtBuscar;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblNombre;
		System::Windows::Forms::Label^ lblMarca;
		System::Windows::Forms::Label^ lblPrecio;
		System::Windows::Forms::Label^ lblStock;
		System::Windows::Forms::Label^ lblBuscar;
		System::Windows::Forms::Button^ btnGuardar;
		System::Windows::Forms::Button^ btnModificar;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Button^ btnRegresar;
		System::Windows::Forms::DataGridView^ dgvRepuestos;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelIzquierdo = gcnew System::Windows::Forms::Panel();
			this->panelDerecho = gcnew System::Windows::Forms::Panel();
			this->txtIdRepuesto = gcnew System::Windows::Forms::TextBox();
			this->txtNombre = gcnew System::Windows::Forms::TextBox();
			this->txtMarca = gcnew System::Windows::Forms::TextBox();
			this->txtPrecio = gcnew System::Windows::Forms::TextBox();
			this->txtStock = gcnew System::Windows::Forms::TextBox();
			this->txtBuscar = gcnew System::Windows::Forms::TextBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblNombre = gcnew System::Windows::Forms::Label();
			this->lblMarca = gcnew System::Windows::Forms::Label();
			this->lblPrecio = gcnew System::Windows::Forms::Label();
			this->lblStock = gcnew System::Windows::Forms::Label();
			this->lblBuscar = gcnew System::Windows::Forms::Label();
			this->btnGuardar = gcnew System::Windows::Forms::Button();
			this->btnModificar = gcnew System::Windows::Forms::Button();
			this->btnEliminar = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnBuscar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvRepuestos = gcnew System::Windows::Forms::DataGridView();
			this->SuspendLayout();

			this->Text = L"Modulo Repuestos";
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

			this->txtIdRepuesto->Visible = false;
			this->lblTitulo->Text = L"Inventario de Repuestos";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(30, 25);
			this->lblTitulo->AutoSize = true;

			this->lblNombre->Text = L"Nombre:";
			this->lblNombre->Location = System::Drawing::Point(35, 95);
			this->lblNombre->AutoSize = true;
			this->txtNombre->Location = System::Drawing::Point(145, 90);
			this->txtNombre->Size = System::Drawing::Size(290, 25);

			this->lblMarca->Text = L"Marca:";
			this->lblMarca->Location = System::Drawing::Point(35, 135);
			this->lblMarca->AutoSize = true;
			this->txtMarca->Location = System::Drawing::Point(145, 130);
			this->txtMarca->Size = System::Drawing::Size(220, 25);

			this->lblPrecio->Text = L"Precio:";
			this->lblPrecio->Location = System::Drawing::Point(35, 175);
			this->lblPrecio->AutoSize = true;
			this->txtPrecio->Location = System::Drawing::Point(145, 170);
			this->txtPrecio->Size = System::Drawing::Size(120, 25);

			this->lblStock->Text = L"Stock:";
			this->lblStock->Location = System::Drawing::Point(35, 215);
			this->lblStock->AutoSize = true;
			this->txtStock->Location = System::Drawing::Point(145, 210);
			this->txtStock->Size = System::Drawing::Size(120, 25);

			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->Location = System::Drawing::Point(35, 280);
			this->btnGuardar->Size = System::Drawing::Size(95, 38);
			this->btnGuardar->Click += gcnew System::EventHandler(this, &FormRepuestos::btnGuardar_Click);

			this->btnModificar->Text = L"Modificar";
			this->btnModificar->Location = System::Drawing::Point(140, 280);
			this->btnModificar->Size = System::Drawing::Size(95, 38);
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormRepuestos::btnModificar_Click);

			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Location = System::Drawing::Point(245, 280);
			this->btnEliminar->Size = System::Drawing::Size(95, 38);
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormRepuestos::btnEliminar_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(350, 280);
			this->btnLimpiar->Size = System::Drawing::Size(95, 38);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormRepuestos::btnLimpiar_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(35, 335);
			this->btnRegresar->Size = System::Drawing::Size(410, 38);
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormRepuestos::btnRegresar_Click);

			this->lblBuscar->Text = L"Buscar por nombre o marca:";
			this->lblBuscar->Location = System::Drawing::Point(20, 35);
			this->lblBuscar->AutoSize = true;
			this->txtBuscar->Location = System::Drawing::Point(20, 65);
			this->txtBuscar->Size = System::Drawing::Size(500, 25);
			this->txtBuscar->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));

			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->Location = System::Drawing::Point(540, 61);
			this->btnBuscar->Size = System::Drawing::Size(120, 34);
			this->btnBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormRepuestos::btnBuscar_Click);

			this->dgvRepuestos->Location = System::Drawing::Point(20, 115);
			this->dgvRepuestos->Size = System::Drawing::Size(660, 520);
			this->dgvRepuestos->ReadOnly = true;
			this->dgvRepuestos->AllowUserToAddRows = false;
			this->dgvRepuestos->AllowUserToDeleteRows = false;
			this->dgvRepuestos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRepuestos->MultiSelect = false;
			this->dgvRepuestos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvRepuestos->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dgvRepuestos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvRepuestos->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvRepuestos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormRepuestos::dgvRepuestos_CellClick);

			this->panelIzquierdo->Controls->Add(this->txtIdRepuesto);
			this->panelIzquierdo->Controls->Add(this->lblTitulo);
			this->panelIzquierdo->Controls->Add(this->lblNombre);
			this->panelIzquierdo->Controls->Add(this->txtNombre);
			this->panelIzquierdo->Controls->Add(this->lblMarca);
			this->panelIzquierdo->Controls->Add(this->txtMarca);
			this->panelIzquierdo->Controls->Add(this->lblPrecio);
			this->panelIzquierdo->Controls->Add(this->txtPrecio);
			this->panelIzquierdo->Controls->Add(this->lblStock);
			this->panelIzquierdo->Controls->Add(this->txtStock);
			this->panelIzquierdo->Controls->Add(this->btnGuardar);
			this->panelIzquierdo->Controls->Add(this->btnModificar);
			this->panelIzquierdo->Controls->Add(this->btnEliminar);
			this->panelIzquierdo->Controls->Add(this->btnLimpiar);
			this->panelIzquierdo->Controls->Add(this->btnRegresar);
			this->panelDerecho->Controls->Add(this->lblBuscar);
			this->panelDerecho->Controls->Add(this->txtBuscar);
			this->panelDerecho->Controls->Add(this->btnBuscar);
			this->panelDerecho->Controls->Add(this->dgvRepuestos);
			this->Controls->Add(this->panelDerecho);
			this->Controls->Add(this->panelIzquierdo);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormRepuestos_Load(System::Object^ sender, System::EventArgs^ e)
		{
			ListarRepuestos();
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void FormatearTabla()
		{
			if (dgvRepuestos->Columns->Contains("id_repuesto")) dgvRepuestos->Columns["id_repuesto"]->Visible = false;
			if (dgvRepuestos->Columns->Contains("nombre")) dgvRepuestos->Columns["nombre"]->HeaderText = "Nombre";
			if (dgvRepuestos->Columns->Contains("marca")) dgvRepuestos->Columns["marca"]->HeaderText = "Marca";
			if (dgvRepuestos->Columns->Contains("precio")) dgvRepuestos->Columns["precio"]->HeaderText = "Precio";
			if (dgvRepuestos->Columns->Contains("stock")) dgvRepuestos->Columns["stock"]->HeaderText = "Stock";
			dgvRepuestos->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
		}

		bool ValidarCampos()
		{
			if (String::IsNullOrWhiteSpace(txtNombre->Text) ||
				String::IsNullOrWhiteSpace(txtPrecio->Text) ||
				String::IsNullOrWhiteSpace(txtStock->Text))
			{
				System::Windows::Forms::MessageBox::Show("Debe ingresar nombre, precio y stock.");
				return false;
			}
			Decimal precio = Decimal::Zero;
			int stock = 0;
			if (!Decimal::TryParse(txtPrecio->Text, precio))
			{
				System::Windows::Forms::MessageBox::Show("El precio debe ser numerico.");
				return false;
			}
			if (!Int32::TryParse(txtStock->Text, stock))
			{
				System::Windows::Forms::MessageBox::Show("El stock debe ser numerico.");
				return false;
			}
			return true;
		}

		void ListarRepuestos()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "SELECT id_repuesto, nombre, marca, precio, stock FROM repuestos ORDER BY id_repuesto DESC";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvRepuestos->DataSource = dt;
				FormatearTabla();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar repuestos: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void Limpiar()
		{
			txtIdRepuesto->Clear();
			txtNombre->Clear();
			txtMarca->Clear();
			txtPrecio->Clear();
			txtStock->Clear();
			txtBuscar->Clear();
			txtNombre->Focus();
		}

		System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "INSERT INTO repuestos (nombre, marca, precio, stock) VALUES (@nombre, @marca, @precio, @stock)";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@nombre", txtNombre->Text);
				cmd->Parameters->AddWithValue("@marca", txtMarca->Text);
				cmd->Parameters->AddWithValue("@precio", Convert::ToDecimal(txtPrecio->Text));
				cmd->Parameters->AddWithValue("@stock", Convert::ToInt32(txtStock->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Repuesto guardado correctamente.");
				Limpiar();
				ListarRepuestos();
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
			if (String::IsNullOrWhiteSpace(txtIdRepuesto->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un repuesto de la tabla.");
				return;
			}
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "UPDATE repuestos SET nombre=@nombre, marca=@marca, precio=@precio, stock=@stock WHERE id_repuesto=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdRepuesto->Text));
				cmd->Parameters->AddWithValue("@nombre", txtNombre->Text);
				cmd->Parameters->AddWithValue("@marca", txtMarca->Text);
				cmd->Parameters->AddWithValue("@precio", Convert::ToDecimal(txtPrecio->Text));
				cmd->Parameters->AddWithValue("@stock", Convert::ToInt32(txtStock->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Repuesto modificado correctamente.");
				Limpiar();
				ListarRepuestos();
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
			if (String::IsNullOrWhiteSpace(txtIdRepuesto->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un repuesto de la tabla.");
				return;
			}
			if (System::Windows::Forms::MessageBox::Show("Desea eliminar este repuesto?", "Confirmar", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "DELETE FROM repuestos WHERE id_repuesto=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdRepuesto->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Repuesto eliminado correctamente.");
				Limpiar();
				ListarRepuestos();
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
				String^ sql = "SELECT id_repuesto, nombre, marca, precio, stock FROM repuestos WHERE nombre LIKE @buscar OR marca LIKE @buscar ORDER BY id_repuesto DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@buscar", "%" + txtBuscar->Text + "%");
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvRepuestos->DataSource = dt;
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
			ListarRepuestos();
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dgvRepuestos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvRepuestos->Rows[e->RowIndex];
				txtIdRepuesto->Text = ValorCelda(fila, "id_repuesto");
				txtNombre->Text = ValorCelda(fila, "nombre");
				txtMarca->Text = ValorCelda(fila, "marca");
				txtPrecio->Text = ValorCelda(fila, "precio");
				txtStock->Text = ValorCelda(fila, "stock");
			}
		}
	};
}
