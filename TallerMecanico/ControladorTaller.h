#pragma once
#include "ConexionBD.h"
#include "ClasesModelo.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

public ref class ControladorTaller
{
private:
	ConexionBD^ db;

public:
	ControladorTaller();
	~ControladorTaller();

	DataTable^ ListarClientes();
	DataTable^ BuscarClientes(String^ buscar);
	bool InsertarCliente(Cliente^ cliente);
	bool ActualizarCliente(Cliente^ cliente);
	bool EliminarCliente(int idCliente);

	DataTable^ ListarVehiculos();
	DataTable^ ListarMecanicos();
	DataTable^ ListarRepuestos();
	DataTable^ ListarTiposServicio();
	DataTable^ ListarServicios(String^ buscar);
	DataTable^ ListarFacturas();

	bool CrearTablaFacturasSiNoExiste();
};

