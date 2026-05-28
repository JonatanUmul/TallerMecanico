#pragma once

using namespace System;

public ref class Cliente
{
public:
	int id_cliente;
	int nit;
	String^ nombre;
	int edad;
	String^ direccion;
	String^ correo;
	String^ telefono;
};

public ref class Vehiculo
{
public:
	int id_vehiculo;
	int id_cliente;
	String^ placa;
	String^ n_chasis;
	String^ marca;
	String^ modelo;
	String^ tipo;
	String^ estado;
};

public ref class Mecanico
{
public:
	int id_mecanico;
	String^ nombre;
	String^ telefono;
	String^ especialidad;
};

public ref class Repuesto
{
public:
	int id_repuesto;
	String^ nombre;
	String^ marca;
	Decimal precio;
	int stock;
};

public ref class TipoServicio
{
public:
	int id_tipo_servicio;
	String^ tipo;
	Decimal precio;
};

public ref class ServicioTaller
{
public:
	int id_servicio;
	int id_cliente;
	int id_vehiculo;
	int id_tipo_servicio;
	int id_mecanico;
	DateTime fecha;
	int kilometraje;
	String^ descripcion;
	String^ estado;
	Decimal total;
};

public ref class DetalleTrabajo
{
public:
	int id_detalle;
	int id_servicio;
	int id_repuesto;
	int cantidad;
	String^ descripcion_trabajo;
	Decimal costo_mano_obra;
	String^ observacion;
};

public ref class Factura
{
public:
	int id_factura;
	int id_servicio;
	DateTime fecha;
	Decimal subtotal;
	Decimal descuento;
	Decimal total;
	String^ metodo_pago;
	String^ estado;
	String^ observacion;
};

