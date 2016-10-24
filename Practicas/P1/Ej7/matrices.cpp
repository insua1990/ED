#include <iostream>
#include <ctime>    
#include <cstdlib>  

#define MAX 1000
using namespace std;

void multiplicar (int **A,int **B,int **C,int tam) {
	for (int i=0;i<tam;i++)
	{
		for (int j=0;j<tam;j++){
			for (int k=0;k<tam;k++){
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}
	return;
}

void sintaxis()
{
	cerr << "Sintaxis:" << endl;
	cerr << "  TAM: Tamaño del vector (>0)" << endl;
	cerr << "Se genera un vector de tamaño TAM" << endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
	// Lectura de parámetros
	if (argc!=2)
		sintaxis();
	 // Tamaño del vector
	int tam=atoi(argv[1]);    
	if (tam<=0)
		sintaxis();
	// Generación de matrices
	int** A = new int*[tam];
	int** B = new int*[tam];
	int** C = new int*[tam];
	
	for (int i = 0; i < tam;i++){
	    A[i] = new int[tam];
	    B[i] = new int[tam];
            C[i] = new int[tam];      
	}
	
	for (int i=0;i<tam;i++){
		for (int j=0;j<tam;j++){ 
			A[i][j]= rand() % MAX + 1;
			B[i][j]= rand() % MAX + 1;
			C[i][j] = 0;
		}
	}
	clock_t tini;    
	tini=clock();

	multiplicar(A,B,C,tam);

	clock_t tfin;    
	tfin=clock();

	// Mostramos resultados
	cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
	
	// Liberamos memoria dinámica
	for (int i = 0; i < tam; ++i){
		delete [] A[i];	    
		delete [] B[i];
		delete [] C[i];
	}
	delete [] A;
	delete [] B;     
	delete [] C;     
}
