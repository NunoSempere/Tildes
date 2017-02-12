

#include <iostream>
#include <fstream>

using namespace std;
	
int main() {
	
	ifstream fin;
	fin.open("Buscon.txt", ios::in);
	
	char mi_caracter;
	
	int numero_de_tildes = 0;
	int numero_de_espacios = 0;
	int numero_de_palabras = 0;

	bool anterior_tilde=false;
	bool tilde_ahora=false;
	bool anterior_n_o_s=false;
	bool ahora_n_o_s=false;
	bool tilde_en_palabra=false;
	
	int monosilaba = 0;
	
	int llana_en_consonante_sin_tilde=0;
	double tildes_por_palabra = 0;

	while (!fin.eof() ) {		
		
		anterior_tilde=tilde_ahora;
		tilde_ahora=false;
		
		anterior_n_o_s=ahora_n_o_s;
		ahora_n_o_s=false;
		
		
		fin.get(mi_caracter);
				
		if (mi_caracter == 'á' or mi_caracter == 'é' or mi_caracter == 'í' or mi_caracter == 'ó' or mi_caracter == 'ú'){ 
			++numero_de_tildes;
			tilde_ahora=true;
			tilde_en_palabra=true;
			++monosilaba;
		}

		if (mi_caracter == 'a' or mi_caracter == 'e' or mi_caracter == 'i' or mi_caracter == 'o' or mi_caracter == 'u'){
			++monosilaba;
		}
		
		if (mi_caracter == 'n' or mi_caracter == 's'  ){ 
			ahora_n_o_s=true;
		}
		
		// contar el numero de espacios. El numero de palabras sera el numero de espacios +1
		if (mi_caracter == '\n' or mi_caracter == ' ' or mi_caracter =='.' or mi_caracter ==',' or  mi_caracter =='?'  or mi_caracter =='!'){ 

			if (tilde_en_palabra == false and anterior_n_o_s==true and monosilaba>=2){ 
				++llana_en_consonante_sin_tilde;
			}
			
			tilde_en_palabra=false;
			monosilaba =0;
			
			if (mi_caracter == '\n' or mi_caracter == ' '){ 
			++numero_de_espacios;
			}
		}
		
	}

// Para el caso de que termine sin punto o salto de línea o espacio. Por ejemplo, si el .txt es 'Ahora'

	if (tilde_en_palabra == false and ahora_n_o_s==true and monosilaba>=2){ 
		++llana_en_consonante_sin_tilde;
	}
	
	
	
	// obtener el número de palabras y la proporcion palabras por oracion
	numero_de_palabras = numero_de_espacios +1; // El off by one de ' ' se debería ir con el off by one de '/n'. 
	//En otras palabras, si el txt es 'En un lugar /n de la Mancha' cuenta cuatro espacios y un cambio de linea = 5 palabras, pues no tiene en cuenta el punto final.
	// Esto tiene el inconveniente de que si el txt está vacío, se interpreta como que tiene 1 palabra

	// Mensaje final
	cout << "Porcentaje de palabras con tilde = " << (float)numero_de_tildes / numero_de_palabras*100 << endl;
	cout << "Porcentaje de llanas en consonante sin tilde  = " << (float)llana_en_consonante_sin_tilde/ numero_de_palabras*100<< endl;
	cout << "Numero de palabras  = " << numero_de_palabras << endl;
	// Advertencia en cuanto a formato
	cout << "TEN EN CUENTA QUE EL FICHERO DEBE" << endl;
	cout << "ESTAR CODIFICADO EN FORMATO .TXT - ANSI" << endl;
		
}

