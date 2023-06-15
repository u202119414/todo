#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
class corazon
{
private:
	int x;
	int y;
	int dx;
	int dy;
	bool visible;
public:
	corazon(int xm, int ym)
	{
		Random dado;
		x = xm+3;
		y = ym+4;
		do {
			dx = dado.Next(-1,2);
		} while (dx == 0);
	
	}
	void dibujar()
	{
		if (x > 0&& x<118)
		{
			Console::SetCursorPosition(x, y);
			cout << (char)3;
		}
	}
	void borrar()
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
	void movimiento()
	{
		
		if(x+dx>=0 &&x+dx<120)
		x = x + dx;
	
	}
	int getX() { return x; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	~corazon();
};

class picas
{
private:
	int x;
	int y;
	int dx;
	int dy;
	bool visible;

public:
	picas(int xm, int ym)
	{
		Random dado;
		x = xm + 3;
		y = ym + 4;
		do {
			dy = dado.Next(-1, 2);
		} while (dy == 0);

	}
	~picas()
	{ 
		
	}
	void dibujar()
	{
		if (y > 0 && y < 29)
		{
			Console::SetCursorPosition(x, y);
			cout << (char)6;
		}
	}
	void borrar()
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
	void movimiento()
	{

		if (y + dy >= 0 && y + dy < 30)
			y = y + dy;

	}
	int getX() { return x; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
};

class Gestordisparo
{private:
	corazon *Cora;
	picas* Pica;
	int veri;
public:
	Gestordisparo(int xm, int ym)
	{
		Cora = new corazon(xm,ym);
		Pica = new picas(xm,ym);
		Gestorprincipal();

	}
	
	void Gestorprincipal()
	{
		
			Random dado;
			veri = dado.Next(0, 2);
		
	}
	void reinicio(int xm, int ym)
	{
		Cora = new corazon(xm, ym);
		Pica = new picas(xm, ym);
	}
	void Gestorprincipal2(int xm,int ym)
	{
		if (Cora->getX() ==  118 ||  Cora->getX()==0|| Pica->getY() == 29|| Pica->getY() == 1)
		{
			reinicio(xm, ym);
			Random dado;
			veri = dado.Next(0, 2);
		}
		
	}
	void mostrar()
	{
		if(veri==1)Cora->dibujar();

		if(veri==0)Pica->dibujar();
		
		
	}
	void movimiento()
	{
		if (veri == 1)Cora->movimiento();

		if (veri == 0)Pica->movimiento();
	
	}
	void borrar(int xm, int ym)
	{
		if (veri == 1)	Cora->borrar();

		if (veri == 0)Pica->borrar();
		Gestorprincipal2(xm,ym);

	}
};

