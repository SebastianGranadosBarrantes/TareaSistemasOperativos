#include <iostream>
#include <pthread.h>

struct cuentaBancaria{
	double saldo;
	pthread_mutex_t mutex;
};

cuentaBancaria cuenta;

void realizarDeposito(double monto);

void* funcionHilo(void *arg);

using namespace std;

int main(){
	double montoTransaccion = 10;
	double transaccion[10] ;
	pthread_t hilos[10];
	cuenta.saldo = 0.0;
	pthread_mutex_init(&cuenta.mutex, NULL);
	
	for(int i = 0; i < 10; i ++){
		transaccion[i] = montoTransaccion;
		montoTransaccion += 1;
		pthread_create(&hilos[i], NULL, funcionHilo, (void*)&transaccion[i]);

	}

	for(int i = 0; i < 10; i++){
		pthread_join(hilos[i],NULL);
	}

	cout << "El saldo final es de " << cuenta.saldo << endl;

	cout << "Compuesto por los siguientes depositos con montos de : \n";

	for (int i = 0; i < 10; i ++){
		cout << "\nDeposito # " << i + 1 << " Monto: " << transaccion[i];
	}
	cout << endl;

	return 0;
}

void realizarDeposito(double monto){
	pthread_mutex_lock(&cuenta.mutex);
	cuenta.saldo += monto;
	pthread_mutex_unlock(&cuenta.mutex);
}

void* funcionHilo(void* arg){
	double monto = *((double*)arg);
	realizarDeposito(monto);
	return NULL;
}
