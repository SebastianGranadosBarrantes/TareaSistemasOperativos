#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std; 

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "No ingreso la cantidad de parametros correcta, verifique y vuelva a intentar\n";
		return 1;
	}
	int cantidadHijos = atoi(argv[1]);
	pid_t hijos [cantidadHijos]; 
	for(int i = 0; i < cantidadHijos; i++){
		hijos[i] = fork();
		if(hijos[i] == -1){
			cout << "ocurrio un error al crear uno de los procesos hijo\n";
			return 1;
		}
		else if(hijos[i] == 0){
				
			cout << "Hijo #" << i + 1 << " PID: " << getpid() << " PPID: " << getppid() <<endl; 
		return 0;
		}
		else{
			int estadoSalida;
			wait(NULL);	
		}

	}

	return 0;
}
