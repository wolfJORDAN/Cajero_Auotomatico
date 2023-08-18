#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>


using namespace std;

class Cliente {
    public:
        string nombre;
        string numeroCuenta;
        string clave;
        string direccion;
        string telefono;
        string saldo;
    public:
    Cliente(string, string, string, string,string, float);
    };

Cliente::Cliente(string _nombre, string _numeroCuenta, string _clave,string _direccion, string _telefono, float _saldo) {
    nombre = _nombre;
    numeroCuenta = _numeroCuenta;
    direccion = _direccion;
    telefono = _telefono;
    saldo = _saldo;
};



//Funcion encargada de crear un vector con los clientes del archivo
vector<Cliente> leer_almacenar() {


    ifstream archivo("Clientes.txt");

    vector<Cliente> clientes;//creando un vector con todos los clientes del archivo

    string linea;

    if(archivo.is_open()){//Si elarchivo esta abierto
        while (getline(archivo, linea)) {//lee cada linea del archivo
        stringstream ss(linea);
        string nombre, numeroCuenta, clave, direccion, telefono,saldo_str;
        float saldo;

        getline(ss, nombre, ',');
        getline(ss, numeroCuenta, ',');
        getline(ss, clave, ',');
        getline(ss, direccion, ',');
        getline(ss, telefono, ',');
        getline(ss, saldo_str, ',');
        saldo = stof(saldo_str);/*
        Funcion pendiente, error al convertir a float*/

        Cliente cliente(nombre, numeroCuenta, clave, direccion, telefono, saldo);//crea un objeto cliente cad vez que de una vuelta
        clientes.push_back(cliente);//agregando objeto cliente al arreglo

    }
    archivo.close();//cierra el archivo
    }

    return clientes;//retorna un vector con objetos de la clase: Cliente

}
/*
Esta funcion se encarga de validar si la clave ingresada esta en el vector que retorna la funcion anterior,
usando como parametro la clave ingresada para validar que sea correcta*/
bool validar(const string& clave_ingresada){
    vector<Cliente>clientes = leer_almacenar();

    for (size_t i = 0; i < clientes.size(); i++) {//recorre el vector clientes
        if (clientes[i].clave == clave_ingresada) {//si en clientes [indice]clave del objeto, es igual a la clave ingresada 
            return true;//retorna verdadero y se termina la funcion
        }
    }

    return false;//si no lo encontro va a retornar falso
}




void desplegar_menu(){

    string clave;

    while(true){
        cout<<"Ingrese una clave: ";
            cin.ignore(); // Limpiar el búfer de entrada
            getline(cin,clave);

        bool aut = validar(clave);
        if(aut==true){

            cout<<"12345678"<<endl;
            cout<<"Emerson Jordan"<<endl;
            cout<<""<<endl;
            cout<<"Saspan Chiquimula"<<endl;
            cout<<""<<endl;
            break;
        }
    }

}

int main(){

    desplegar_menu();

    system("PAUSE");

    return 0;
}
