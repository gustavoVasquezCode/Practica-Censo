#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Persona{
	private:
		string nombre;
		float ingreso_mensual;
		string sexo;
	
	public:
		void setNombre(string);
		void setIngreso_mensual(float);
		void setSexo(string);
		string getNombre();
		float getIngreso_mensual();
		string getSexo();
};

class Censo : public Persona{
	public:
		void agregar_personas();
		void mostrar_info();
};

// Implementamos los métodos de la clase derivada <<Censo>>
void Censo::agregar_personas(){
	string nombre;
	float ingreso;
	string sexo;
	cout << "\n---------- Agregar personas ----------" << endl;
	fflush(stdin);
	cout << "Ingrese el nombre: "; 
	getline(cin, nombre); Censo::setNombre(nombre);
	
	cout << "Ingrese los ingresos mensuales: ";
	cin >> ingreso; Censo::setIngreso_mensual(ingreso);
	
	fflush(stdin);
	cout << "Ingrese el sexo: ";
	getline(cin, sexo); Censo::setSexo(sexo);
}

void Censo::mostrar_info(){
	cout << "Nombre: " << Censo::getNombre() << endl;
	cout << "Ingreso mensual: " << Censo::getIngreso_mensual() << endl;
	cout << "Sexo: " << Censo::getSexo() << endl;
	cout << "\n" << endl;
}

// metodos set() y get() de la clase <<Persona>>
void Persona::setNombre(string _nombre){
	nombre = _nombre;
}

void Persona::setIngreso_mensual(float _ingreso){
	ingreso_mensual = _ingreso;
}

void Persona::setSexo(string _sexo){
	sexo = _sexo;
}

string Persona::getNombre(){ return nombre; }

float Persona::getIngreso_mensual(){ return ingreso_mensual; }

string Persona::getSexo(){ return sexo; }

// Metodo de la clase principal, metodo <<main>>
int main(){
	int dimension;
	int i;
	int ch=0, cm=0, mayor_ingreso=0;
	cout << "Ingrese cuantas personas va a agregar: "; cin >> dimension;
	Censo *obj = new Censo[dimension];
	
	for(i=0; i<dimension; ++i){
		obj[i].agregar_personas();
		if(obj[i].getSexo() == "H")
			ch++;
		else if(obj[i].getSexo() == "M")
			cm++;
		
		if(obj[i].getIngreso_mensual() > 8000)
			mayor_ingreso++;
	}
	
	cout << "\n\nMostramos los datos: " << endl;
	for(i=0; i<dimension; ++i){
		obj[i].mostrar_info();
	}
	
	cout << "Numero de hombres: " << ch << endl;
	cout << "Numero de mujeres: " << cm << endl;
	cout << "Numero de personas con ingreso mayor a los 8000: " << mayor_ingreso << endl;
	
	
	system("pause");
	return 0;
}
