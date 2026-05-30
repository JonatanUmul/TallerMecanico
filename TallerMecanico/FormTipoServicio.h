#pragma once
#include "Conexion.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;

	public ref class FormTipoServicio : public System::Windows::Forms::Form
	{
	public:
		FormTipoServicio(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormTipoServicio::FormTipoServicio_Load);
		}

	protected:
		~FormTipoServicio()
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
		System::Windows::Forms::TextBox^ txtIdTipoServicio;
		System::Windows::Forms::TextBox^ txtTipo;
		System::Windows::Forms::TextBox^ txtPrecio;
		System::Windows::Forms::TextBox^ txtBuscar;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblTipo;
		System::Windows::Forms::Label^ lblPrecio;
		System::Windows::Forms::Label^ lblBuscar;
		System::Windows::Forms::Button^ btnGuardar;
		System::Windows::Forms::Button^ btnModificar;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Button^ btnRegresar;
		System::Windows::Forms::DataGridView^ dgvTiposServicio;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelIzquierdo = gcnew System::Windows::Forms::Panel();
			this->panelDerecho = gcnew System::Windows::Forms::Panel();
			this->txtIdTipoServicio = gcnew System::Windows::Forms::TextBox();
			this->txtTipo = gcnew System::Windows::Forms::TextBox();
			this->txtPrecio = gcnew System::Windows::Forms::TextBox();
			this->txtBuscar = gcnew System::Windows::Forms::TextBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblTipo = gcnew System::Windows::Forms::Label();
			this->lblPrecio = gcnew System::Windows::Forms::Label();
			this->lblBuscar = gcnew System::Windows::Forms::Label();
			this->btnGuardar = gcnew System::Windows::Forms::Button();
			this->btnModificar = gcnew System::Windows::Forms::Button();
			this->btnEliminar = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnBuscar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvTiposServicio = gcnew System::Windows::Forms::DataGridView();
			this->SuspendLayout();

			this->Text = L"Modulo Tipos de Servicio";
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

			this->txtIdTipoServicio->Visible = false;
			this->lblTitulo->Text = L"Tipos de Servicio";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(30, 25);
			this->lblTitulo->AutoSize = true;

			this->lblTipo->Text = L"Servicio:";
			this->lblTipo->Location = System::Drawing::Point(35, 95);
			this->lblTipo->AutoSize = true;
			this->txtTipo->Location = System::Drawing::Point(145, 90);
			this->txtTipo->Size = System::Drawing::Size(290, 25);

			this->lblPrecio->Text = L"Precio:";
			this->lblPrecio->Location = System::Drawing::Point(35, 135);
			this->lblPrecio->AutoSize = true;
			this->txtPrecio->Location = System::Drawing::Point(145, 130);
			this->txtPrecio->Size = System::Drawing::Size(120, 25);

			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->Location = System::Drawing::Point(35, 210);
			this->btnGuardar->Size = System::Drawing::Size(95, 38);
			this->btnGuardar->Click += gcnew System::EventHandler(this, &FormTipoServicio::btnGuardar_Click);

			this->btnModificar->Text = L"Modificar";
			this->btnModificar->Location = System::Drawing::Point(140, 210);
			this->btnModificar->Size = System::Drawing::Size(95, 38);
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormTipoServicio::btnModificar_Click);

			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Location = System::Drawing::Point(245, 210);
			this->btnEliminar->Size = System::Drawing::Size(95, 38);
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormTipoServicio::btnEliminar_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(350, 210);
			this->btnLimpiar->Size = System::Drawing::Size(95, 38);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormTipoServicio::btnLimpiar_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(35, 265);
			this->btnRegresar->Size = System::Drawing::Size(410, 38);
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormTipoServicio::btnRegresar_Click);

			this->lblBuscar->Text = L"Buscar tipo de servicio:";
			this->lblBuscar->Location = System::Drawing::Point(20, 35);
			this->lblBuscar->AutoSize = true;
			this->txtBuscar->Location = System::Drawing::Point(20, 65);
			this->txtBuscar->Size = System::Drawing::Size(260, 25);
			this->txtBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->txtBuscar->TextChanged += gcnew System::EventHandler(this, &FormTipoServicio::txtBuscar_TextChanged);
			this->txtBuscar->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormTipoServicio::txtBuscar_KeyDown);

			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->Location = System::Drawing::Point(300, 61);
			this->btnBuscar->Size = System::Drawing::Size(110, 34);
			this->btnBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormTipoServicio::btnBuscar_Click);

			this->dgvTiposServicio->Location = System::Drawing::Point(20, 115);
			this->dgvTiposServicio->Size = System::Drawing::Size(660, 520);
			this->dgvTiposServicio->ReadOnly = true;
			this->dgvTiposServicio->AllowUserToAddRows = false;
			this->dgvTiposServicio->AllowUserToDeleteRows = false;
			this->dgvTiposServicio->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTiposServicio->MultiSelect = false;
			this->dgvTiposServicio->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvTiposServicio->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dgvTiposServicio->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvTiposServicio->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvTiposServicio->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormTipoServicio::dgvTiposServicio_CellClick);

			this->panelIzquierdo->Controls->Add(this->txtIdTipoServicio);
			this->panelIzquierdo->Controls->Add(this->lblTitulo);
			this->panelIzquierdo->Controls->Add(this->lblTipo);
			this->panelIzquierdo->Controls->Add(this->txtTipo);
			this->panelIzquierdo->Controls->Add(this->lblPrecio);
			this->panelIzquierdo->Controls->Add(this->txtPrecio);
			this->panelIzquierdo->Controls->Add(this->btnGuardar);
			this->panelIzquierdo->Controls->Add(this->btnModificar);
			this->panelIzquierdo->Controls->Add(this->btnEliminar);
			this->panelIzquierdo->Controls->Add(this->btnLimpiar);
			this->panelIzquierdo->Controls->Add(this->btnRegresar);
			this->panelDerecho->Controls->Add(this->lblBuscar);
			this->panelDerecho->Controls->Add(this->txtBuscar);
			this->panelDerecho->Controls->Add(this->dgvTiposServicio);
			this->Controls->Add(this->panelDerecho);
			this->Controls->Add(this->panelIzquierdo);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormTipoServicio_Load(System::Object^ sender, System::EventArgs^ e)
		{
			ListarTiposServicio();
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void FormatearTabla()
		{
			if (dgvTiposServicio->Columns->Contains("id_tipo_servicio")) dgvTiposServicio->Columns["id_tipo_servicio"]->Visible = false;
			if (dgvTiposServicio->Columns->Contains("tipo")) dgvTiposServicio->Columns["tipo"]->HeaderText = "Servicio";
			if (dgvTiposServicio->Columns->Contains("precio")) dgvTiposServicio->Columns["precio"]->HeaderText = "Precio";
			dgvTiposServicio->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
		}

		bool ValidarCampos()
		{
			if (String::IsNullOrWhiteSpace(txtTipo->Text) || String::IsNullOrWhiteSpace(txtPrecio->Text))
			{
				System::Windows::Forms::MessageBox::Show("Debe ingresar tipo y precio.");
				return false;
			}
			Decimal precio = Decimal::Zero;
			if (!Decimal::TryParse(txtPrecio->Text, precio))
			{
				System::Windows::Forms::MessageBox::Show("El precio debe ser numerico.");
				return false;
			}
			return true;
		}

		void ListarTiposServicio()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "SELECT id_tipo_servicio, tipo, precio FROM tiposervicio ORDER BY id_tipo_servicio DESC";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvTiposServicio->DataSource = dt;
				FormatearTabla();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar tipos de servicio: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void Limpiar()
		{
			txtIdTipoServicio->Clear();
			txtTipo->Clear();
			txtPrecio->Clear();
			txtBuscar->Clear();
			txtTipo->Focus();
		}

		System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "INSERT INTO tiposervicio (tipo, precio) VALUES (@tipo, @precio)";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@tipo", txtTipo->Text);
				cmd->Parameters->AddWithValue("@precio", Convert::ToDecimal(txtPrecio->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Tipo de servicio guardado correctamente.");
				Limpiar();
				ListarTiposServicio();
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
			if (String::IsNullOrWhiteSpace(txtIdTipoServicio->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un tipo de servicio de la tabla.");
				return;
			}
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "UPDATE tiposervicio SET tipo=@tipo, precio=@precio WHERE id_tipo_servicio=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdTipoServicio->Text));
				cmd->Parameters->AddWithValue("@tipo", txtTipo->Text);
				cmd->Parameters->AddWithValue("@precio", Convert::ToDecimal(txtPrecio->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Tipo de servicio modificado correctamente.");
				Limpiar();
				ListarTiposServicio();
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
			if (String::IsNullOrWhiteSpace(txtIdTipoServicio->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un tipo de servicio de la tabla.");
				return;
			}
			if (System::Windows::Forms::MessageBox::Show("Desea eliminar este tipo de servicio?", "Confirmar", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "DELETE FROM tiposervicio WHERE id_tipo_servicio=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdTipoServicio->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Tipo de servicio eliminado correctamente.");
				Limpiar();
				ListarTiposServicio();
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
				String^ sql = "SELECT id_tipo_servicio, tipo, precio FROM tiposervicio WHERE tipo LIKE @buscar ORDER BY id_tipo_servicio DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@buscar", "%" + txtBuscar->Text + "%");
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvTiposServicio->DataSource = dt;
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

		System::Void txtBuscar_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			btnBuscar_Click(sender, e);
		}

		System::Void txtBuscar_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == System::Windows::Forms::Keys::Enter)
			{
				btnBuscar_Click(sender, System::EventArgs::Empty);
				e->SuppressKeyPress = true;
			}
		}

		System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Limpiar();
			ListarTiposServicio();
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dgvTiposServicio_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvTiposServicio->Rows[e->RowIndex];
				txtIdTipoServicio->Text = ValorCelda(fila, "id_tipo_servicio");
				txtTipo->Text = ValorCelda(fila, "tipo");
				txtPrecio->Text = ValorCelda(fila, "precio");
			}
		}
	};
}
