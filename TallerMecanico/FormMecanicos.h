#pragma once
#include "Conexion.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;

	public ref class FormMecanicos : public System::Windows::Forms::Form
	{
	public:
		FormMecanicos(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &FormMecanicos::FormMecanicos_Load);
		}

	protected:
		~FormMecanicos()
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
		System::Windows::Forms::TextBox^ txtIdMecanico;
		System::Windows::Forms::TextBox^ txtNombre;
		System::Windows::Forms::TextBox^ txtTelefono;
		System::Windows::Forms::TextBox^ txtEspecialidad;
		System::Windows::Forms::TextBox^ txtBuscar;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblNombre;
		System::Windows::Forms::Label^ lblTelefono;
		System::Windows::Forms::Label^ lblEspecialidad;
		System::Windows::Forms::Label^ lblBuscar;
		System::Windows::Forms::Button^ btnGuardar;
		System::Windows::Forms::Button^ btnModificar;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Button^ btnRegresar;
		System::Windows::Forms::DataGridView^ dgvMecanicos;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->panelIzquierdo = gcnew System::Windows::Forms::Panel();
			this->panelDerecho = gcnew System::Windows::Forms::Panel();
			this->txtIdMecanico = gcnew System::Windows::Forms::TextBox();
			this->txtNombre = gcnew System::Windows::Forms::TextBox();
			this->txtTelefono = gcnew System::Windows::Forms::TextBox();
			this->txtEspecialidad = gcnew System::Windows::Forms::TextBox();
			this->txtBuscar = gcnew System::Windows::Forms::TextBox();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblNombre = gcnew System::Windows::Forms::Label();
			this->lblTelefono = gcnew System::Windows::Forms::Label();
			this->lblEspecialidad = gcnew System::Windows::Forms::Label();
			this->lblBuscar = gcnew System::Windows::Forms::Label();
			this->btnGuardar = gcnew System::Windows::Forms::Button();
			this->btnModificar = gcnew System::Windows::Forms::Button();
			this->btnEliminar = gcnew System::Windows::Forms::Button();
			this->btnLimpiar = gcnew System::Windows::Forms::Button();
			this->btnBuscar = gcnew System::Windows::Forms::Button();
			this->btnRegresar = gcnew System::Windows::Forms::Button();
			this->dgvMecanicos = gcnew System::Windows::Forms::DataGridView();
			this->SuspendLayout();

			this->Text = L"Modulo Mecanicos";
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

			this->txtIdMecanico->Visible = false;

			this->lblTitulo->Text = L"Registro de Mecanicos";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(30, 25);
			this->lblTitulo->AutoSize = true;

			this->lblNombre->Text = L"Nombre:";
			this->lblNombre->Location = System::Drawing::Point(35, 95);
			this->lblNombre->AutoSize = true;
			this->txtNombre->Location = System::Drawing::Point(145, 90);
			this->txtNombre->Size = System::Drawing::Size(290, 25);

			this->lblTelefono->Text = L"Telefono:";
			this->lblTelefono->Location = System::Drawing::Point(35, 135);
			this->lblTelefono->AutoSize = true;
			this->txtTelefono->Location = System::Drawing::Point(145, 130);
			this->txtTelefono->Size = System::Drawing::Size(180, 25);

			this->lblEspecialidad->Text = L"Especialidad:";
			this->lblEspecialidad->Location = System::Drawing::Point(35, 175);
			this->lblEspecialidad->AutoSize = true;
			this->txtEspecialidad->Location = System::Drawing::Point(145, 170);
			this->txtEspecialidad->Size = System::Drawing::Size(290, 80);
			this->txtEspecialidad->Multiline = true;

			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->Location = System::Drawing::Point(35, 290);
			this->btnGuardar->Size = System::Drawing::Size(95, 38);
			this->btnGuardar->Click += gcnew System::EventHandler(this, &FormMecanicos::btnGuardar_Click);

			this->btnModificar->Text = L"Modificar";
			this->btnModificar->Location = System::Drawing::Point(140, 290);
			this->btnModificar->Size = System::Drawing::Size(95, 38);
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormMecanicos::btnModificar_Click);

			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->Location = System::Drawing::Point(245, 290);
			this->btnEliminar->Size = System::Drawing::Size(95, 38);
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormMecanicos::btnEliminar_Click);

			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->Location = System::Drawing::Point(350, 290);
			this->btnLimpiar->Size = System::Drawing::Size(95, 38);
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &FormMecanicos::btnLimpiar_Click);

			this->btnRegresar->Text = L"Regresar al menu";
			this->btnRegresar->Location = System::Drawing::Point(35, 345);
			this->btnRegresar->Size = System::Drawing::Size(410, 38);
			this->btnRegresar->Click += gcnew System::EventHandler(this, &FormMecanicos::btnRegresar_Click);

			this->lblBuscar->Text = L"Buscar por nombre o especialidad:";
			this->lblBuscar->Location = System::Drawing::Point(20, 35);
			this->lblBuscar->AutoSize = true;
			this->txtBuscar->Location = System::Drawing::Point(20, 65);
			this->txtBuscar->Size = System::Drawing::Size(500, 25);
			this->txtBuscar->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));

			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->Location = System::Drawing::Point(540, 61);
			this->btnBuscar->Size = System::Drawing::Size(120, 34);
			this->btnBuscar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormMecanicos::btnBuscar_Click);

			this->dgvMecanicos->Location = System::Drawing::Point(20, 115);
			this->dgvMecanicos->Size = System::Drawing::Size(660, 520);
			this->dgvMecanicos->ReadOnly = true;
			this->dgvMecanicos->AllowUserToAddRows = false;
			this->dgvMecanicos->AllowUserToDeleteRows = false;
			this->dgvMecanicos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvMecanicos->MultiSelect = false;
			this->dgvMecanicos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dgvMecanicos->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dgvMecanicos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dgvMecanicos->Anchor = (System::Windows::Forms::AnchorStyles)((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvMecanicos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormMecanicos::dgvMecanicos_CellClick);

			this->panelIzquierdo->Controls->Add(this->txtIdMecanico);
			this->panelIzquierdo->Controls->Add(this->lblTitulo);
			this->panelIzquierdo->Controls->Add(this->lblNombre);
			this->panelIzquierdo->Controls->Add(this->txtNombre);
			this->panelIzquierdo->Controls->Add(this->lblTelefono);
			this->panelIzquierdo->Controls->Add(this->txtTelefono);
			this->panelIzquierdo->Controls->Add(this->lblEspecialidad);
			this->panelIzquierdo->Controls->Add(this->txtEspecialidad);
			this->panelIzquierdo->Controls->Add(this->btnGuardar);
			this->panelIzquierdo->Controls->Add(this->btnModificar);
			this->panelIzquierdo->Controls->Add(this->btnEliminar);
			this->panelIzquierdo->Controls->Add(this->btnLimpiar);
			this->panelIzquierdo->Controls->Add(this->btnRegresar);

			this->panelDerecho->Controls->Add(this->lblBuscar);
			this->panelDerecho->Controls->Add(this->txtBuscar);
			this->panelDerecho->Controls->Add(this->btnBuscar);
			this->panelDerecho->Controls->Add(this->dgvMecanicos);
			this->Controls->Add(this->panelDerecho);
			this->Controls->Add(this->panelIzquierdo);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void FormMecanicos_Load(System::Object^ sender, System::EventArgs^ e)
		{
			ListarMecanicos();
		}

		String^ ValorCelda(System::Windows::Forms::DataGridViewRow^ fila, String^ columna)
		{
			Object^ valor = fila->Cells[columna]->Value;
			if (valor == nullptr || valor == System::DBNull::Value) return "";
			return valor->ToString();
		}

		void FormatearTabla()
		{
			if (dgvMecanicos->Columns->Contains("id_mecanico")) dgvMecanicos->Columns["id_mecanico"]->Visible = false;
			if (dgvMecanicos->Columns->Contains("nombre")) dgvMecanicos->Columns["nombre"]->HeaderText = "Nombre";
			if (dgvMecanicos->Columns->Contains("telefono")) dgvMecanicos->Columns["telefono"]->HeaderText = "Telefono";
			if (dgvMecanicos->Columns->Contains("especialidad")) dgvMecanicos->Columns["especialidad"]->HeaderText = "Especialidad";
			dgvMecanicos->AutoResizeColumns(System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells);
		}

		bool ValidarCampos()
		{
			if (String::IsNullOrWhiteSpace(txtNombre->Text))
			{
				System::Windows::Forms::MessageBox::Show("Debe ingresar el nombre del mecanico.");
				return false;
			}
			return true;
		}

		void ListarMecanicos()
		{
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "SELECT id_mecanico, nombre, telefono, especialidad FROM mecanico ORDER BY id_mecanico DESC";
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(sql, cn);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvMecanicos->DataSource = dt;
				FormatearTabla();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show("Error al listar mecanicos: " + ex->Message);
			}
			finally
			{
				if (cn->State == ConnectionState::Open) cn->Close();
			}
		}

		void Limpiar()
		{
			txtIdMecanico->Clear();
			txtNombre->Clear();
			txtTelefono->Clear();
			txtEspecialidad->Clear();
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
				String^ sql = "INSERT INTO mecanico (nombre, telefono, especialidad) VALUES (@nombre, @telefono, @especialidad)";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@nombre", txtNombre->Text);
				cmd->Parameters->AddWithValue("@telefono", txtTelefono->Text);
				cmd->Parameters->AddWithValue("@especialidad", txtEspecialidad->Text);
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Mecanico guardado correctamente.");
				Limpiar();
				ListarMecanicos();
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
			if (String::IsNullOrWhiteSpace(txtIdMecanico->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un mecanico de la tabla.");
				return;
			}
			if (!ValidarCampos()) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "UPDATE mecanico SET nombre=@nombre, telefono=@telefono, especialidad=@especialidad WHERE id_mecanico=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdMecanico->Text));
				cmd->Parameters->AddWithValue("@nombre", txtNombre->Text);
				cmd->Parameters->AddWithValue("@telefono", txtTelefono->Text);
				cmd->Parameters->AddWithValue("@especialidad", txtEspecialidad->Text);
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Mecanico modificado correctamente.");
				Limpiar();
				ListarMecanicos();
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
			if (String::IsNullOrWhiteSpace(txtIdMecanico->Text))
			{
				System::Windows::Forms::MessageBox::Show("Seleccione un mecanico de la tabla.");
				return;
			}
			if (System::Windows::Forms::MessageBox::Show("Desea eliminar este mecanico?", "Confirmar", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) return;
			MySqlConnection^ cn = Conexion::ObtenerConexion();
			try
			{
				cn->Open();
				String^ sql = "DELETE FROM mecanico WHERE id_mecanico=@id";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtIdMecanico->Text));
				cmd->ExecuteNonQuery();
				System::Windows::Forms::MessageBox::Show("Mecanico eliminado correctamente.");
				Limpiar();
				ListarMecanicos();
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
				String^ sql = "SELECT id_mecanico, nombre, telefono, especialidad FROM mecanico WHERE nombre LIKE @buscar OR especialidad LIKE @buscar ORDER BY id_mecanico DESC";
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, cn);
				cmd->Parameters->AddWithValue("@buscar", "%" + txtBuscar->Text + "%");
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);
				dgvMecanicos->DataSource = dt;
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
			ListarMecanicos();
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		System::Void dgvMecanicos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0)
			{
				System::Windows::Forms::DataGridViewRow^ fila = dgvMecanicos->Rows[e->RowIndex];
				txtIdMecanico->Text = ValorCelda(fila, "id_mecanico");
				txtNombre->Text = ValorCelda(fila, "nombre");
				txtTelefono->Text = ValorCelda(fila, "telefono");
				txtEspecialidad->Text = ValorCelda(fila, "especialidad");
			}
		}
	};
}
