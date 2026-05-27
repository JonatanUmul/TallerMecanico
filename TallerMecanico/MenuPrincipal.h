#pragma once
#include "FormClientes.h"
#include "FormVehiculos.h"
#include "FormMecanicos.h"
#include "FormRepuestos.h"
#include "FormTipoServicio.h"
#include "FormRecepcion.h"
#include "FormHistorial.h"

namespace TallerMecanico {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
		}

	protected:
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Button^ btnClientes;
		System::Windows::Forms::Button^ btnVehiculos;
		System::Windows::Forms::Button^ btnMecanicos;
		System::Windows::Forms::Button^ btnRepuestos;
		System::Windows::Forms::Button^ btnTipoServicio;
		System::Windows::Forms::Button^ btnRecepcion;
		System::Windows::Forms::Button^ btnHistorial;
		System::Windows::Forms::Button^ btnSalir;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->btnClientes = gcnew System::Windows::Forms::Button();
			this->btnVehiculos = gcnew System::Windows::Forms::Button();
			this->btnMecanicos = gcnew System::Windows::Forms::Button();
			this->btnRepuestos = gcnew System::Windows::Forms::Button();
			this->btnTipoServicio = gcnew System::Windows::Forms::Button();
			this->btnRecepcion = gcnew System::Windows::Forms::Button();
			this->btnHistorial = gcnew System::Windows::Forms::Button();
			this->btnSalir = gcnew System::Windows::Forms::Button();
			this->SuspendLayout();

			this->Text = L"Control de Taller Mecanico";
			this->ClientSize = System::Drawing::Size(720, 520);
			this->MinimumSize = System::Drawing::Size(720, 520);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;

			this->lblTitulo->Text = L"Control de Taller Mecanico";
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(150, 35);
			this->lblTitulo->Size = System::Drawing::Size(430, 45);
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblTitulo->Anchor = System::Windows::Forms::AnchorStyles::Top;

			this->btnClientes->Text = L"Clientes";
			this->btnClientes->Location = System::Drawing::Point(90, 125);
			this->btnClientes->Size = System::Drawing::Size(240, 50);
			this->btnClientes->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnClientes_Click);

			this->btnVehiculos->Text = L"Vehiculos";
			this->btnVehiculos->Location = System::Drawing::Point(390, 125);
			this->btnVehiculos->Size = System::Drawing::Size(240, 50);
			this->btnVehiculos->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnVehiculos_Click);

			this->btnMecanicos->Text = L"Mecanicos";
			this->btnMecanicos->Location = System::Drawing::Point(90, 195);
			this->btnMecanicos->Size = System::Drawing::Size(240, 50);
			this->btnMecanicos->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnMecanicos_Click);

			this->btnRepuestos->Text = L"Repuestos";
			this->btnRepuestos->Location = System::Drawing::Point(390, 195);
			this->btnRepuestos->Size = System::Drawing::Size(240, 50);
			this->btnRepuestos->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnRepuestos_Click);

			this->btnTipoServicio->Text = L"Tipos de servicio";
			this->btnTipoServicio->Location = System::Drawing::Point(90, 265);
			this->btnTipoServicio->Size = System::Drawing::Size(240, 50);
			this->btnTipoServicio->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnTipoServicio_Click);

			this->btnRecepcion->Text = L"Recepcion / Orden";
			this->btnRecepcion->Location = System::Drawing::Point(390, 265);
			this->btnRecepcion->Size = System::Drawing::Size(240, 50);
			this->btnRecepcion->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnRecepcion_Click);

			this->btnHistorial->Text = L"Historial";
			this->btnHistorial->Location = System::Drawing::Point(90, 335);
			this->btnHistorial->Size = System::Drawing::Size(240, 50);
			this->btnHistorial->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnHistorial_Click);

			this->btnSalir->Text = L"Salir";
			this->btnSalir->Location = System::Drawing::Point(390, 335);
			this->btnSalir->Size = System::Drawing::Size(240, 50);
			this->btnSalir->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnSalir_Click);

			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->btnClientes);
			this->Controls->Add(this->btnVehiculos);
			this->Controls->Add(this->btnMecanicos);
			this->Controls->Add(this->btnRepuestos);
			this->Controls->Add(this->btnTipoServicio);
			this->Controls->Add(this->btnRecepcion);
			this->Controls->Add(this->btnHistorial);
			this->Controls->Add(this->btnSalir);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void btnClientes_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try { FormClientes^ frm = gcnew FormClientes(); frm->ShowDialog(); }
			catch (Exception^ ex) { MessageBox::Show("Error al abrir Clientes: " + ex->Message); }
		}

		System::Void btnVehiculos_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try { FormVehiculos^ frm = gcnew FormVehiculos(); frm->ShowDialog(); }
			catch (Exception^ ex) { MessageBox::Show("Error al abrir Vehiculos: " + ex->Message); }
		}

		System::Void btnMecanicos_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try { FormMecanicos^ frm = gcnew FormMecanicos(); frm->ShowDialog(); }
			catch (Exception^ ex) { MessageBox::Show("Error al abrir Mecanicos: " + ex->Message); }
		}

		System::Void btnRepuestos_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try { FormRepuestos^ frm = gcnew FormRepuestos(); frm->ShowDialog(); }
			catch (Exception^ ex) { MessageBox::Show("Error al abrir Repuestos: " + ex->Message); }
		}

		System::Void btnTipoServicio_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try { FormTipoServicio^ frm = gcnew FormTipoServicio(); frm->ShowDialog(); }
			catch (Exception^ ex) { MessageBox::Show("Error al abrir Tipos de servicio: " + ex->Message); }
		}

		System::Void btnRecepcion_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try { FormRecepcion^ frm = gcnew FormRecepcion(); frm->ShowDialog(); }
			catch (Exception^ ex) { MessageBox::Show("Error al abrir Recepcion: " + ex->Message); }
		}

		System::Void btnHistorial_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try { FormHistorial^ frm = gcnew FormHistorial(); frm->ShowDialog(); }
			catch (Exception^ ex) { MessageBox::Show("Error al abrir Historial: " + ex->Message); }
		}

		System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Application::Exit();
		}
	};
}

