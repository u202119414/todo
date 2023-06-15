#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
 class Murciélago
{
	
	
	 private:
		 int x;
		 int y;
		 int dx;
		 int dy;
		 bool visible;

	 public:
		 Murciélago()
		 {
			 Random dado;
			 x = 90;
			 y = dado.Next(5, 20);
			 dx = 0; dy = 1;
		 }
		 void dibujar()
		 {
			 Console::SetCursorPosition(x, y);
			 cout << "   _   ,_,    _";
			 Console::SetCursorPosition(x, y + 1);
			 cout << " /  `'=) (=' ` \\";
			 Console::SetCursorPosition(x, y + 2);
			 cout << "/ .-.-.\\ / .-.-.\\";
			 Console::SetCursorPosition(x, y + 3);
			 cout << "`       v       `";
		 }
		 void cambiody()
		 {
			 if (y + dy < 0 || y + dy+3>30)
				 dy = dy * -1;
		 }
		 void movimiento()
		 {
			 cambiody();
				 y = y + dy;
		 }

		 void borrar()
		 {
			 Console::SetCursorPosition(x, y);
			 cout << "               ";
			 Console::SetCursorPosition(x, y + 1);
			 cout << "                ";
			 Console::SetCursorPosition(x, y + 2);
			 cout << "                 ";
			 Console::SetCursorPosition(x, y + 3);
			 cout << "                 ";
		 
		 }
		 int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}

	
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
};

