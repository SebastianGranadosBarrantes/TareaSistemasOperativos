#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

void collazt (int numero);

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "No ingreso la cantidad correcta de parametros al llamar al programa\n";
		return 1;
	}
	int numero = atoi(argv[1]);
	if(numero <= 0){
		cout << "Error, no ingreso un numero valido!!\n";
		return 1;
	}
	pid_t procesoHijo = fork();
	if(procesoHijo == -1){
		cout << "ocurrio un error al crear el proceso hijo\n";
		return 1;
	}
	else if(procesoHijo == 0){
		collazt(numero);
	}
	else{
	int estadoSalida;
	waitpid(procesoHijo,&estadoSalida,0);
	if(WIFEXITED(estadoSalida)){
		cout << "\nEl proceso hijo termino de manera correcta\n";
	}
	}
	return 0;
}

void collazt(int numero){
	if(numero == 1){
		cout << 1;
		return ;
	}
	else if(numero % 2 == 0){
		cout << numero << ",";
		collazt(numero / 2);
	}
	else{
		cout << numero << ",";
		collazt(3 * numero + 1);
	}
}
