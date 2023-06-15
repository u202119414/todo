#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
#include "Jugador.h"
#include"Murciélago.h"
#include "Gestordisparo.h"
#define IZQUIERDA 75
#define ARRIBA 80
#define DERECHA 77
#define ABAJO 72

class Controladora
{
private:
	Jugador*juga;
	Murciélago* murci;
	corazon* cora;
	picas* Pica;
	Gestordisparo* gest;
	int key;
	
public:
	Controladora()
	{
		juga = new Jugador();
		murci = new Murciélago();
		gest= new Gestordisparo(murci->getx(), murci->gety());

	
	}
	void Movimientodejuga()
	{
		if (_kbhit()) {
			key = _getch();
			if (key == IZQUIERDA)
			{
				juga->movimientoIZ();
			}
			if (key == ABAJO)
			{
				juga->movimientoAB();
			}
			if (key == ARRIBA)
			{
				juga->movimientoAR();
			}
			if (key == DERECHA)
			{
				juga->movimientoD();
			}
		}
	}

	void juego()
	{
		movimientos();
		dibujos();
		_sleep(50);
		borrar();
	

		
	}
	void dibujos()
	{
		juga->dibujar();
		murci->dibujar();
		gest->mostrar();
	}
	void borrar()
	{
		juga->borrar();
		murci->borrar();
		gest->borrar(murci->getx(), murci->gety());
	}
	void movimientos()
	{
		Movimientodejuga();
		juga->movimiento();
		murci->movimiento();
		gest->movimiento();
	}
	int getjugaX()
	{
		return juga->getx();
	}
	int getjugay()
	{
		return juga->gety();
	}
	int getmurx()
	{
		return murci->getx();
	}
	int getmury()
	{
		return murci->gety();
	}
};

