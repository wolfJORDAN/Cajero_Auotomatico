#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

class Cliente{
	public:
		string nombre;
		string telefono;
		string direccion;
		string numero_cuenta;
		string clave;
		float saldo;
	
	public:
		Cliente(string,string,string,string,string,float);
};

Cliente::Cliente(string _nombre,string _telefono,string _direccion,string _clave, float _saldo){
	nombre = _nombre;
	telefono = _telefono;
	direccion = _direccion;
	clave = _clave;
	saldo = _saldo;
}

bool validar(clave_ingresada){

	ifstream archivo("Clientes.txt");
	
	
	
	if(archivo.is_open()){
		
		string linea;
		
		vector<Cliente> clientes;
		
		while(getline(archivo, linea)){
			string nombre, telefono, direccion, clave, numero_cuenta, saldo_str;
			float saldo;
			
			stringstream ss(linea);
			
			
			getline(ss, nombre, ",");
			getline(ss, numero_cuenta, ",");
			getline(ss, direccion, ",");
			getline(ss, clave, ",");
			getline(ss, saldo_str, ",");
			
			saldo = stof(saldo_str);
			
			Cliente cliente(nombre, numero_cuenta, direccion, clave, saldo);
			
			clientes.push_back(cliente);
			
		}
		
		}
	}


}
	
	
}
void desplegar_menu(){

    string clave;

    /*cout<<"Ingrese una clave: ";
    //cin.ignore(); // Limpiar el búfer de entrada
    getline(cin,clave);

    bool aut = validar(clave);*/

    while(true){
        cout<<"Ingrese una clave: ";
            //cin.ignore(); // Limpiar el búfer de entrada
            getline(cin,clave);

        bool aut = validar(clave);
        if(aut==true){

            /*cout<<"Ingrese una clave: ";
            cin.ignore(); // Limpiar el búfer de entrada
            getline(cin,clave);*/

            //bool aut = validar(clave);

            cout<</*Numero_Cuenta*/"12345678"<<endl;
            cout<</*Nombre*/"Emerson Jordan"<<endl;
            cout<</*telefono*/""<<endl;
            cout<</*Direccion*/"Saspan Chiquimula"<<endl;
            cout<</*Saldo*/""<<endl;
            break;
        }
    }

}

/*clientes= emerson askjfjk
lusi dsfa
*/

int main(){

    desplegar_menu();

    system("PAUSE");

    return 0;
}
