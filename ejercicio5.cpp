#include <iostream>

void sortPunteros();

using namespace std;

int main(){
	sortPunteros();
	return 0;
}
void swapQS(int indexA, int indexB, string** array){
	string aux = *array[indexA];
	*array[indexA] = *array[indexB];
	*array[indexB] = aux;
}

int dividirQS(string** array, int inicio, int fin){
	string* pivote = array[fin];
	int i = inicio - 1;
	
	for(int j = inicio; j < fin; j++){
		if(*array[j] < *pivote){
			i++;
			swapQS(i,j, array);
		}
	}
	swapQS(i + 1, fin, array);
	return i + 1;
}

void quicksort(string** array, int inicio, int fin){
	if(inicio < fin){
		int pivote = dividirQS(array, inicio, fin);
		quicksort(array, inicio, pivote - 1);
		quicksort(array, pivote + 1, fin);
	}
}

void sortPunteros(){
	char caracter;
	int indexArregloCadenas = 0;
	string* arregloCadenas [100];
	string* cadena = new string();
	system("clear");
	cout << "Instrucciones:" << endl;
	cout << "Debe ingresar varias lineas de texto, el maximo es de 100, cuando termine para que el programa agarre la ultima linea debe presionar enter y luego crtl + d" << endl;
	cout << "Escriba las lineas aqui:" << endl;
	while (cin.get(caracter)){
		if(caracter == '\n' or caracter == -1){
			*cadena += caracter;
			arregloCadenas[indexArregloCadenas] = cadena;
			indexArregloCadenas ++;
			cadena = new string();
		}
		else{
			*cadena += caracter;
		}
		
	}
	cout << "\nLas cadenas NO ordenadas alfabeticamente son:\n";
	for(int i = 0; i < indexArregloCadenas; i ++){
		cout << *arregloCadenas[i] << endl;
	}
	quicksort(arregloCadenas, 0, indexArregloCadenas - 1);

	cout << "\nLas cadenas ordenadas alfabeticamente son: \n";
	for(int i = 0; i < indexArregloCadenas ; i++){
		cout << *arregloCadenas[i] << endl;
	}
	
} 
