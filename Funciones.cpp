#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Cliente {
public:
    std::string nombre;
    std::string numeroCuenta;
    std::string clave;
    std::string direccion;
    std::string telefono;
    float saldo;

    Cliente(std::string, std::string, std::string, std::string, std::string, float);
};

Cliente::Cliente(std::string _nombre, std::string _numeroCuenta, std::string _clave, std::string _direccion, std::string _telefono, float _saldo) {
    nombre = _nombre;
    numeroCuenta = _numeroCuenta;
    clave = _clave;
    direccion = _direccion;
    telefono = _telefono;
    saldo = _saldo;
}

int validar(string clave_ingresada, const vector<Cliente>& clientes) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clave_ingresada == clientes[i].clave) {
            return i;
        }
    }
    return false;
}

float consulta_saldo(int indice, Cliente clientes){

    return clientes[indice].saldo;
    
}

void depositar(int indice, float monto, Cliente clientes){
    
    clientes[indice].saldo += monto;

}


int main(){

    string clave;

    vector <Cliente> clientes{
        Cliente("Cliente1", "Cuenta1", "Clave1", "Direccion1", "Telefono1", 100.0),
        Cliente("Cliente2", "Cuenta2", "Clave2", "Direccion2", "Telefono2", 200.0),
        Cliente("Cliente3", "Cuenta3", "Clave3", "Direccion3", "Telefono3", 300.0),
    };

    int indice_cliente;
    

    while(1){

        cout<<"Ingrese un clave: "<<endl;cin>>clave;

        if(validar(clave, clientes)!= -1 || validar(clave, clientes)>=0){
            indice_cliente = validar(clave, clientes);
            cout<<"Clave correcta"<<endl;
            break;


        }
        else{
            cout<<"La clave ingresada no es valida!"<<endl;
        }
    }

    while(1){
        cout<<"Bienvenido!"<<clientes[indice_cliente].nombre<<endl;

        int opcion;

        cout<<"Que operacion desea realizar?"<<endl;
        cout<<"Consulta de Saldo: Presione 1"<<endl;
        cout<<"Deposito: Presione 2"<<endl;
        cout<<"Retiro: Presione 3"<<endl;
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            float saldo = consulta_saldo(indice_cliente, clientes);
            cout<<"Su saldo actual es de: Q"<<saldo<<endl;
            break;
        
        case2:
            string opcion;
            float monto;
            cout<<"Has seleccionado la cantidad de Deposito."<<endl;
            cout<<"Por favor, ingresa la cantida que deseas depositar: Q";cin>>monto;
            
            while(1){
                if(monto>=1){

                    "Has ingresado la cantidad de Q"<<monto<<endl;
                    cout<<"Deseas continuar con la operacion? Si/No"<<endl;
                    while(1){
                        if(opcion == "Si" || opcion == "si"){
                            depositar(indice_cliente, clientes, monto);
                            cout<<"Deposito exitoso, tu saldo actual es de Q"<<clientes[i].saldo<<endl;
                            cout<<"Deseas realizar otra operacion? Si/No";cin>>opcion;
                            if(opcion == si || opcion == si || opcion == SI){
                                
                            }
                            else{
                                cout<<"Deseas salir?Si/No";cin>>opcion;
                                if()
                            }
                        }
                    }
                    break;
                }
                else{
                    cout<<"LA CANTIDAD DEBE SER MAYOR A CERO!"<<endl;
                }
            }

            break;
        }



    }


    system("PAUSE");

    return 0;
}