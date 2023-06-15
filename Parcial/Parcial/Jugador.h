#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

 class Jugador
{
private:
	int x;
	int y;
	int dx;
	int dy;
	bool visible;

public:
	Jugador()
	{
		Random dado;
		x = 1;
		y = dado.Next(5, 20);
		dx = 0; dy = 0;
	}
	void dibujar()
	{
		Console::SetCursorPosition(x, y);
		cout << "O";
		Console::SetCursorPosition(x, y+1);
		cout << "+";
		
	}
	void borrar()
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
		Console::SetCursorPosition(x, y+1);
		cout << " ";
	}
	void movimientoD()
	{
		dx=1;
	}
	void movimientoAR()
	{
		dy=1;
	}
	void movimientoAB()
	{
		
		dy=-1;
	}
	void movimientoIZ()
	{
		dx=-1;
	}
	void renicio()
	{
		dx = 0;
		dy = 0;
	}
	void movimiento()
	{
		if (x+dx<120&&x+dx>1)
		{
			x = x + dx;
		}
		if (y+dy>0&&y+dy+1<30)
		{
			y = y + dy;
		}
		renicio();
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int getX() { return x; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
};

