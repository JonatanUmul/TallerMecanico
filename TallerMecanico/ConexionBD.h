#pragma once
#include "ConfiguracionApp.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

public ref class ConexionBD
{
private:
	MySqlConnection^ conexion;

public:
	ConexionBD()
	{
		conexion = nullptr;
	}

	static MySqlConnection^ CrearConexion()
	{
		return gcnew MySqlConnection(ConfiguracionApp::CadenaConexion());
	}

	MySqlConnection^ AbrirConexion()
	{
		if (conexion == nullptr)
		{
			conexion = CrearConexion();
		}

		if (conexion->State != ConnectionState::Open)
		{
			conexion->Open();
		}

		return conexion;
	}

	void CerrarConexion()
	{
		if (conexion != nullptr && conexion->State == ConnectionState::Open)
		{
			conexion->Close();
		}
	}

	bool ConexionActiva()
	{
		try
		{
			AbrirConexion();
			return true;
		}
		catch (Exception^)
		{
			return false;
		}
	}

	DataTable^ EjecutarConsultaTabla(String^ sql)
	{
		DataTable^ tabla = gcnew DataTable();

		if (String::IsNullOrWhiteSpace(sql))
		{
			return tabla;
		}

		MySqlDataAdapter^ adaptador = gcnew MySqlDataAdapter(sql, AbrirConexion());
		adaptador->Fill(tabla);
		return tabla;
	}

	DataTable^ EjecutarConsultaTabla(MySqlCommand^ comando)
	{
		DataTable^ tabla = gcnew DataTable();

		if (comando == nullptr)
		{
			return tabla;
		}

		comando->Connection = AbrirConexion();
		MySqlDataAdapter^ adaptador = gcnew MySqlDataAdapter(comando);
		adaptador->Fill(tabla);
		return tabla;
	}

	int EjecutarIUD(MySqlCommand^ comando)
	{
		if (comando == nullptr)
		{
			return 0;
		}

		comando->Connection = AbrirConexion();
		return comando->ExecuteNonQuery();
	}

	Object^ EjecutarEscalar(MySqlCommand^ comando)
	{
		if (comando == nullptr)
		{
			return nullptr;
		}

		comando->Connection = AbrirConexion();
		return comando->ExecuteScalar();
	}
};

