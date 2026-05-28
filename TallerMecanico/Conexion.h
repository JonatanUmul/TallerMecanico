#pragma once
#include "ConexionBD.h"

public ref class Conexion abstract sealed
{
public:
	static MySqlConnection^ ObtenerConexion()
	{
		return ConexionBD::CrearConexion();
	}
};

