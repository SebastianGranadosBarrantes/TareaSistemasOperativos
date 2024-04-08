#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

void buscarErroresC();

using namespace std;

int main(){
	buscarErroresC();
	return 0;
}

void buscarErroresC(){
	char caracter;
	queue <int> lineasConError;
	ifstream lectura;
	string nombreArchivo, linea;
	int contadorLineas = 0, contadorLlaveAbiertas = 0, contadorLlaveCerradas = 0;
	int contadorParntAbiertos = 0, contadorParntCerrados = 0, contadorSqrAbiertos = 0;
	int contadorSqrCerrados = 0;
	int ultimaLinea [3];

	while(!lectura.is_open()){
		cout << "Ingrese el nombre del archivo .c a analizar" << endl;
		cin >> nombreArchivo;
		lectura.open(nombreArchivo);
		if(!lectura.is_open()){
			cout << "Error abriendo el archivo, verifique y vuelva a intentar" << endl;
		}
		else{
			cout << "archivo abierto, verificando la sintaxis del programa..." << endl;
			cout << "Si el programa se cierra sin mostrar ningun output es porque todo esta correcto\n";
		}

	}
	while(getline(lectura,linea)){
		contadorLineas ++;
		for(int i = 0; i < linea.size(); i ++){
			caracter = linea[i];
			if(caracter == 123 ){
				contadorLlaveAbiertas++;
			}	
			else if(caracter == 91){
				contadorSqrAbiertos++;
			}
			else if(caracter == 40){
				contadorParntAbiertos++;
			}
			else if(caracter == 125){
				contadorLlaveCerradas++;
				ultimaLinea[0] = contadorLineas;
			}
			else if(caracter == 93){
				contadorSqrCerrados++;
				ultimaLinea[1] = contadorLineas;
			}
			else if(caracter == 41){
				contadorParntCerrados++;
				ultimaLinea[2] = contadorLineas;
			}
		
		}
	
	}
	if(contadorLlaveAbiertas != contadorLlaveCerradas){
	cout << "error en la linea " << ultimaLinea[0] << endl;
	}
	else if(contadorSqrAbiertos != contadorSqrCerrados){
		cout << "error en la linea " << ultimaLinea[1] << endl;
	}
	else if(contadorParntAbiertos != contadorParntCerrados){
		cout << "error en la linea " << ultimaLinea[2] << endl;
	}

}
