#include <iostream>
#include <pthread.h>

struct parametrosHilos{
	int numero;
	unsigned long long fibo[50];
};

void* calcularFibo(void* arg);

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "No ingreso la cantidad correcta de parametros\n";
		return 1;
	}
	int numero = atoi(argv[1]);
	if(numero < 0 || numero > 50){
		cout << "El numero debe estar entre 0 y 50\n";
		return 1;
	}

	pthread_t hiloPadre;
	parametrosHilos par;
	par.numero = numero;

	if(pthread_create(&hiloPadre, NULL, calcularFibo, (void*)&par) != 0){
		cout << "Hubo un error al crear el hilo hijo" << endl;
		return 1;
	}
	pthread_join(hiloPadre,NULL);

	cout << "La secuencia de fibonacci para el numero " << numero << " es: \n";
	for(int i = 0; i < numero; i ++){
		cout << par.fibo[i] << "\t";
	}
	cout << endl;

	return 0;
}

void* calcularFibo(void* arg){
	parametrosHilos *pars = (parametrosHilos*)arg;
	pars->fibo[0] = 0;
	pars->fibo[1] = 1;

	for(int i = 2; i <= pars->numero; i++){
		pars->fibo[i] = pars->fibo[i-1] + pars->fibo[i - 2];

	}
	return NULL;
}


