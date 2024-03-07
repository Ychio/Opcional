#include <iostream>
#define BLANCO "\033[30;47m"  // fondo blanco
#define NEGRO "\033[30;40m"  // fondo negro
#define ROJO "\033[30;41m"  // fondo rojo
#define VERDE "\033[30;42m"  // fondo verde
#define AZUL "\033[30;44m"  // fondo azul
#define RESET "\033[0m"  // restablecer colores a los predeterminados
using namespace std;
const int TAM = 8;
const int SIZE = 30;
//78 clave para ver los cuadros
		
void n_binario(int n,bool regla[]){
	for(int i=TAM-1;i>= 0 ;i--){
		regla[i] = n % 2; 
		n /= 2;
	}
}

void inicializa(bool array[]){
	for(int i=0;i<=SIZE;i++){
		array[i] = false;
	}
	array[15] = true;
}


void mostrar(const bool state[]){
	for(int i=0;i<SIZE;i++){
		if(state[i]){
			cout<<BLANCO<<" "<<RESET;
		}
		else{
			cout<<VERDE<<" "<<RESET;
		}
	}
	cout<<endl;
}

string toString(const bool array[],int a,int b,int c){
	return to_string(array[a]) + to_string(array[b]) + to_string(array[c]);
}

int comprueba(string cosa){
	if(cosa == "000"){
		return 0;
	}
	else if(cosa == "001"){
		return 1;
	}
	else if(cosa == "010"){
		return 2;
	}
	else if(cosa == "011"){
		return 3;
	}
	else if(cosa == "100"){
		return 4;
	}
	else if(cosa == "101"){
		return 5;
	}
	else if(cosa == "110"){
		return 6;
	}
	else if(cosa == "111"){
		return 7;
	}
}

void Modifica(bool array1[],bool array2[],const bool array3[]){
	array2[0] = array3[comprueba(toString(array3,SIZE,0,1))];
	array2[SIZE] = array3[comprueba(toString(array3,SIZE-1,SIZE,0))];
	
	for(int i=1;i<SIZE-1;i++){
		array2[i] = array3[comprueba(toString(array1,i-1,i,i+1))];
	}
}

int main(){
	bool regla[TAM]; // array de las reglas
	bool a1[SIZE];
	bool a2[SIZE];
	int iteraciones = 15,num;
	
	cout<<"Introduzca un numero :\n";
	cin>>num;
	n_binario(num,regla);
	inicializa(a1);
	
	cout<<"sigue la siguiente regla\n";
	for(int i=0;i<TAM;i++){
		cout<<regla[i];
	}
	cout<<endl;
	for(int i=0;i<=iteraciones;i++){
		if(i%2 == 0){
			mostrar(a1);
			Modifica(a1,a2,regla);
		}
		else{
			mostrar(a2);
			Modifica(a2,a1,regla);
		}
	}
}