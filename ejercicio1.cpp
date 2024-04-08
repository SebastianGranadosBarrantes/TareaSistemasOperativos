#include <iostream>
#include <iomanip>
using namespace std ;
void fToC();

int main(){

	cout<< "Fahrenheint to Celsius:\n";
	fToC();

	return 0;

}

void fToC(){
	for(int i = 0; i <= 300; i+=20){
		cout << i << "F" << "     ";
	}
	cout<<endl;
	for(int i = 0; i <=300; i += 20){
		double celsius = 5.0/9 * (i -32);
	cout << fixed << setprecision(2) << celsius << "C" << "   ";

	}

}
