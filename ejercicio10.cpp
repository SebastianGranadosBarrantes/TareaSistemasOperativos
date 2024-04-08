#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "No ingreso la cantidad correcta de parametros\n";
		return 1;
	}
	int pipes[2];
	if(pipe(pipes) == -1){
		cout << "Error creando la tuberia\n";
		return 1;
	}
	pid_t procesoHijo = fork();
	if(procesoHijo == -1){
		cout << "Error al crear el proceso hijo\n";
		return 1;
	}
	else if(procesoHijo == 0){
		close(pipes[1]);
		char buffer [1024];
	       	ssize_t bytes_read = read(pipes[0],buffer,1024);
		if(bytes_read == -1){
			cout << "Error al leer desde la tuberia\n";
			return 1;
		}
		cout << "Proceso hijo, texto recibido\nEl texto es: " << buffer << endl;
	}
	else {
		
		close(pipes[0]);
		const char* inputUsuario = argv[1];
		ssize_t bytes_escritura = write(pipes[1],inputUsuario,strlen(inputUsuario));
		if(bytes_escritura == -1){
			cout << "Ocurrio un error al escribir en la tuberia\n";
			return 1;
		}
		//Se cierra la tuberia
		close(pipes[1]);
	}
	return 0;
}
