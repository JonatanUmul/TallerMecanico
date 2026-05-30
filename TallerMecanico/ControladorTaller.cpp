#include "ControladorTaller.h"

ControladorTaller::ControladorTaller()
{
	db = gcnew ConexionBD();
}

ControladorTaller::~ControladorTaller()
{
	if (db != nullptr)
	{
		db->CerrarConexion();
	}
}
//Clientes
DataTable^ ControladorTaller::ListarClientes()
{
	return db->EjecutarConsultaTabla(
		"SELECT id_cliente, nit, nombre, edad, direccion, correo, telefono "
		"FROM clientes ORDER BY id_cliente DESC"
	);
}

DataTable^ ControladorTaller::BuscarClientes(String^ buscar)
{
	String^ sql =
		"SELECT id_cliente, nit, nombre, edad, direccion, correo, telefono "
		"FROM clientes WHERE nombre LIKE @buscar OR CAST(nit AS CHAR) LIKE @buscar "
		"ORDER BY id_cliente DESC";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	cmd->Parameters->AddWithValue("@buscar", "%" + buscar + "%");
	return db->EjecutarConsultaTabla(cmd);
}

bool ControladorTaller::InsertarCliente(Cliente^ cliente)
{
	String^ sql =
		"INSERT INTO clientes (nit, nombre, edad, direccion, correo, telefono) "
		"VALUES (@nit, @nombre, @edad, @direccion, @correo, @telefono)";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	cmd->Parameters->AddWithValue("@nit", cliente->nit);
	cmd->Parameters->AddWithValue("@nombre", cliente->nombre);
	cmd->Parameters->AddWithValue("@edad", cliente->edad);
	cmd->Parameters->AddWithValue("@direccion", cliente->direccion);
	cmd->Parameters->AddWithValue("@correo", cliente->correo);
	cmd->Parameters->AddWithValue("@telefono", cliente->telefono);
	return db->EjecutarIUD(cmd) > 0;
}

bool ControladorTaller::ActualizarCliente(Cliente^ cliente)
{
	String^ sql =
		"UPDATE clientes SET nit=@nit, nombre=@nombre, edad=@edad, direccion=@direccion, "
		"correo=@correo, telefono=@telefono WHERE id_cliente=@id";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	cmd->Parameters->AddWithValue("@id", cliente->id_cliente);
	cmd->Parameters->AddWithValue("@nit", cliente->nit);
	cmd->Parameters->AddWithValue("@nombre", cliente->nombre);
	cmd->Parameters->AddWithValue("@edad", cliente->edad);
	cmd->Parameters->AddWithValue("@direccion", cliente->direccion);
	cmd->Parameters->AddWithValue("@correo", cliente->correo);
	cmd->Parameters->AddWithValue("@telefono", cliente->telefono);
	return db->EjecutarIUD(cmd) > 0;
}

bool ControladorTaller::EliminarCliente(int idCliente)
{
	MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM clientes WHERE id_cliente=@id");
	cmd->Parameters->AddWithValue("@id", idCliente);
	return db->EjecutarIUD(cmd) > 0;
}

//Vehiculos
DataTable^ ControladorTaller::ListarVehiculos()
{
	return db->EjecutarConsultaTabla(
		"SELECT v.id_vehiculo, v.id_cliente, c.nombre AS cliente, v.placa, v.n_chasis, "
		"v.marca, v.modelo, v.tipo, v.estado "
		"FROM vehiculos v INNER JOIN clientes c ON v.id_cliente = c.id_cliente "
		"ORDER BY v.id_vehiculo DESC"
	);
}

//Mecanicos
DataTable^ ControladorTaller::ListarMecanicos()
{
	return db->EjecutarConsultaTabla(
		"SELECT id_mecanico, nombre, telefono, especialidad "
		"FROM mecanico ORDER BY id_mecanico DESC"
	);
}

//Reuestos
DataTable^ ControladorTaller::ListarRepuestos()
{
	return db->EjecutarConsultaTabla(
		"SELECT id_repuesto, nombre, marca, precio, stock "
		"FROM repuestos ORDER BY id_repuesto DESC"
	);
}

//Tipo de servicos

DataTable^ ControladorTaller::ListarTiposServicio()
{
	return db->EjecutarConsultaTabla(
		"SELECT id_tipo_servicio, tipo, precio "
		"FROM tiposervicio ORDER BY id_tipo_servicio DESC"
	);
}

DataTable^ ControladorTaller::ListarServicios(String^ buscar)
{
	String^ sql =
		"SELECT s.id_servicio, s.id_cliente, s.id_vehiculo, s.id_tipo_servicio, s.id_mecanico, "
		"c.nombre AS cliente, v.placa, ts.tipo AS servicio, m.nombre AS mecanico, "
		"s.fecha, s.kilometraje, s.estado, s.total, s.descripcion "
		"FROM servicios s "
		"INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
		"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
		"INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio "
		"INNER JOIN mecanico m ON s.id_mecanico=m.id_mecanico "
		"WHERE c.nombre LIKE @buscar OR v.placa LIKE @buscar OR s.estado LIKE @buscar "
		"ORDER BY s.id_servicio DESC";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	cmd->Parameters->AddWithValue("@buscar", "%" + buscar + "%");
	return db->EjecutarConsultaTabla(cmd);
}

//Facturas
DataTable^ ControladorTaller::ListarFacturas()
{
	return db->EjecutarConsultaTabla(
		"SELECT f.id_factura, f.id_servicio, f.fecha, c.nombre AS cliente, v.placa, ts.tipo AS servicio, "
		"f.subtotal, f.descuento, f.total, f.metodo_pago, f.estado, f.observacion "
		"FROM facturas f INNER JOIN servicios s ON f.id_servicio=s.id_servicio "
		"INNER JOIN clientes c ON s.id_cliente=c.id_cliente "
		"INNER JOIN vehiculos v ON s.id_vehiculo=v.id_vehiculo "
		"INNER JOIN tiposervicio ts ON s.id_tipo_servicio=ts.id_tipo_servicio "
		"ORDER BY f.id_factura DESC"
	);
}

bool ControladorTaller::CrearTablaFacturasSiNoExiste()
{
	String^ sql =
		"CREATE TABLE IF NOT EXISTS facturas ("
		"id_factura INT AUTO_INCREMENT PRIMARY KEY,"
		"id_servicio INT NOT NULL,"
		"fecha DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,"
		"subtotal DECIMAL(10,2) NOT NULL DEFAULT 0.00,"
		"descuento DECIMAL(10,2) NOT NULL DEFAULT 0.00,"
		"total DECIMAL(10,2) NOT NULL DEFAULT 0.00,"
		"metodo_pago VARCHAR(50) NOT NULL,"
		"estado VARCHAR(30) NOT NULL DEFAULT 'EMITIDA',"
		"observacion TEXT NULL,"
		"UNIQUE KEY uq_factura_servicio (id_servicio),"
		"CONSTRAINT fk_facturas_servicios FOREIGN KEY (id_servicio) REFERENCES servicios(id_servicio)"
		")";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	return db->EjecutarIUD(cmd) >= 0;
}

