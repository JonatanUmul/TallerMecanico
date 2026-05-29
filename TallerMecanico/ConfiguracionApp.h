#pragma once

using namespace System;

public ref class ConfiguracionApp abstract sealed
{
public:
	static String^ ServidorBD()
	{
		return "ecofiltro.net";
	}

	static String^ PuertoBD()
	{
		return "3306";
	}

	static String^ UsuarioBD()
	{
		return "admin";
	}

	static String^ ClaveBD()
	{
		return "Controldedatos12";
	}

	static String^ NombreBD()
	{
		return "taller_mecanico";
	}

	static String^ CadenaConexion()
	{
		return
			"server=" + ServidorBD() + ";" +
			"port=" + PuertoBD() + ";" +
			"user id=" + UsuarioBD() + ";" +
			"password=" + ClaveBD() + ";" +
			"database=" + NombreBD() + ";" +
			"SslMode=Preferred;";
	}

	static String^ WhatsAppUrl()
	{
		return "https://evolutioneco.ecofiltro.net/message/sendText/jonatan_perosonal";
	}

	static String^ WhatsAppApiKey()
	{
		return "59B80597F3B1-4A32-BCC7-C256251BDF9E";
	}
};
