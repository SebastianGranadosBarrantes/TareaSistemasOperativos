#include <iostream>
#include <queue>

using namespace std;

void cadenaFormateada();

int main(){
	cadenaFormateada();

	return 0;
}

void cadenaFormateada(){
	cout << "Ingrese una cadena de texto con tabulaciones y espacios\n Presione CRTL+D para dejar de recibir input y mostrar el output"; 
	char caracter;
	queue <char> inputArreglado;
	while(cin.get(caracter)){
		if(caracter != ' ' and caracter != '\t'){
			inputArreglado.push(caracter);	
		}
	
	}
	cout << "\nLa cadena formateada es:\n";
	while(!inputArreglado.empty()){
		cout << inputArreglado.front();
		inputArreglado.pop();
	}
	cout << endl;

}
