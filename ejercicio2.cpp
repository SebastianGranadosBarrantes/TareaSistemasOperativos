#include <iostream>

void contarPalabras();

int contador = 0;

bool estaEnPalabra = false;

using namespace std;

int main(){
	contarPalabras();
	return 0;
}

void contarPalabras(){
	cout << "Instrucciones: \n";
	cout << "Introduzca un texto, cuando termine de ingresar los datos presione CRTL+D\n";
	char caracter, anterior;
	while(cin.get(caracter)){
		if((caracter >= 65 and caracter <= 90) or (caracter >= 97 and caracter <= 122)){
			estaEnPalabra = true;
		}
		else if(estaEnPalabra){
			estaEnPalabra = false;
			contador++;
		}
		anterior = caracter;
	}
	if(estaEnPalabra){
		contador++;
	}
	cout << "\nEl total de palabras es: " << contador << endl;

}
// el problema de que si se presiona crtl+d al final de una palabra y se tenga que presionar 
// dos veces crtl + d para que termine la ejecucion es porque quedan caracteres por leer 
// (procesar) en el stream de cin.
