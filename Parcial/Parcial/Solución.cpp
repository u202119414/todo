#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
#include"Controladora.h"
void main()
{
	Controladora* controladora;
	controladora = new Controladora();
	
	while (true)
	{
		
		controladora->juego();
	}
		
	
	getch();
}