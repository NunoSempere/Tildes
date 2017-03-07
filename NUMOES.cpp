#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	
	ifstream fin;
	fin.open("lemario.txt", ios::in);
	
	int numero_de_ies =0;
	int contador =0;
	int contador_imprimir;
	char mi_caracter;
	char Lista[28];
	
	while (!fin.eof() ) {		
		
		fin.get(mi_caracter);
		
		if (mi_caracter == 'o' or mi_caracter == 'ó' or mi_caracter == 'O' or mi_caracter == 'Ó'){
			numero_de_ies++;
		}
		
		Lista[contador]=mi_caracter;
		
		//cout << mi_caracter<< " "<<	numero_de_ies << Lista[0] << " " <<  Lista[1] << " " << Lista[2] << " " <<  endl;
		
		if (mi_caracter == '\n' or mi_caracter == ' ' or mi_caracter =='.' or mi_caracter ==',' or  mi_caracter =='?'  or mi_caracter =='!'){ 
			contador =-1;
			
			if (numero_de_ies>=6){
				contador_imprimir =0;
				while (Lista[contador_imprimir]!=0){
					cout <<Lista[contador_imprimir];
					contador_imprimir++;
				}
   			}
   			
   			numero_de_ies =0;
   			
 			for( int a = 0; a <= 27; a++ ) {
      			Lista[a]=0;			
			}
		}
		
		contador++;
		
		if (contador>=27){
			contador =0;
			cout<<"Error, muchas letras"<<endl;
		}
	}
}
