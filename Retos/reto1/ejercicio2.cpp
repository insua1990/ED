#include <iostream>
#include <ctime>    
#include <cstdlib> 
#include <math.h>

using namespace std;

// Functions

long int exponente(int n){
	return  pow ( (double) 2,(double) n ) ;
}

long int cubo(int n){
	return  pow( (double) n,(double) 3) ;
}

long int factorial(int n){
	long int result = 1;
	for (int i = 2 ; i <= n ; i++)
		result *= i;
	return result;
}


int tam_problema (long int ini,long int fin,long int (* fp)(int),long int limit) {
	bool encontrado = false;
	int result;	
	for(int i = ini; i < fin && !encontrado; i++){
		result = i;
		if(fp(i) * (pow( (double) 10, (double) -6) ) > limit ) encontrado = true;
	}
	return result -1 ;
}


int main(int argc, char * argv[]){
	long int times[5] = {1,3600,604800,31536000,31536000000}; 
	for (int k = 0; k < 5; k++)
		cout << tam_problema(0,1000000,cubo,times[k]) << endl;
	for (int k = 0; k < 5; k++)
		cout << tam_problema(0,1000000,exponente,times[k]) << endl;
	for (int k = 0; k < 5; k++)
		cout << tam_problema(0,1000000,factorial,times[k]) << endl;
}

























