#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class Conexion
{
public:
	static MySqlConnection^ ObtenerConexion()
	{
		String^ cadena =
			"server=ecofiltro.net;"
			"port=3306;"
			"user id=admin;"
			"password=Controldedatos12;"
			"database=taller_mecanico;";

		return gcnew MySqlConnection(cadena);
	}
};