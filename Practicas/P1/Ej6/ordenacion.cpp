#include <iostream>
#include <ctime>    
#include <cstdlib>  

using namespace std;

void ordenar (int *v,int n) {
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(v[j]>v[j+1]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
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
	// Generación del vector 
	int *v=new int[tam];       
	int value = tam;
	for (int i=0; i<tam; i++){
		// Genero vector completamente desordenado, de esta forma forzamos el peor caso  
		v[i] = value;          
		value--;	
	}
	clock_t tini;    
	tini=clock();

	ordenar(v,tam);

	clock_t tfin;    
	tfin=clock();

	// Mostramos resultados
	cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
	
	// Liberamos memoria dinámica
	delete [] v;     

}
