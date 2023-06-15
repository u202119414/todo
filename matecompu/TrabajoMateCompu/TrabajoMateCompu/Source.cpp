#include <iostream> 
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//en base a "n" ingresado por el usuario, se genera una matriz n x n de valores positivos, o se le pide al usuario ir ingresando cada valor de la matriz
// ademas, se debe mostrar la red de flujo optima(maxima) asociada a la matriz 
//y calcular el flujo maximo que existe entre 2 vertices seleccionados por el usuario

void generarmatriz(int** mt, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mt[i][j] = rand() % 101 ;
		}
	}
}


void ingresarmatriz(int** mt, int n) {
	int val;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			do {
				cout << "Ingrese un valor positivo en la celda [" << i << ", " << j << "]: ";
				cin >> val;
				mt[i][j] = val;
			} while (val < 0 || val>99);
		}
		cout << endl;
	}
}

void mostrarMatriz(int** mt, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << mt[i][j] << " ";
		}
		cout << endl;
	}
}

//void FlujoOptimo(int** mt, int n){ } //Esta función deberia crear y mostrar algo como un grafo no?

//int FlujoMaximoEncontrado(int** mt, int n){} // del camino del flujo optimo, se calcula el mayor flujo encontrado entre 2 vertices

void main() { //guarden el codigo----------------------------------------------
	int opc;
	int n;
	do {
		cout << "\n Ingrese un numero:";
		cin >> n;
	} while (n < 5 || n>15);

	do {
		cout << "\n Desea generar una matriz(1) o ingresar los valores usted(2)?: ";
		cin >> opc;
	} while (opc < 1 || opc>2);

	int** matriz;
	matriz = new int* [n];
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[n];
	}

	if (opc == 1) {
		generarmatriz(matriz, n);
	}
	else {
		ingresarmatriz(matriz, n);
	}

	mostrarMatriz(matriz, n);
    
	//FlujoOptimo(matriz, n);

	//FlujoMaximoEncontrado(matriz, n)

	_getch();
}

