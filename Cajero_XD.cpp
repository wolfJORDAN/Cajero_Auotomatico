#include <iostream>
#include <string>

using namespace std;

class Cliente {
public:
    string nombre;
    string numeroCuenta;
    string clave;
    string direccion;
    string telefono;
    float saldo;

    Cliente(string _nombre, string _numeroCuenta, string _clave, string _direccion, string _telefono, float _saldo)
        : nombre(_nombre), numeroCuenta(_numeroCuenta), clave(_clave), direccion(_direccion), telefono(_telefono), saldo(_saldo) {}
};

int validar(string clave_ingresada, const Cliente clientes[], int numClientes) {
    for (int i = 0; i < numClientes; i++) {
        if (clave_ingresada == clientes[i].clave) {
            return i;
        }
    }
    return -1;
}

float consulta_saldo(int indice, const Cliente clientes[]) {
    return clientes[indice].saldo;
}

void depositar(int indice, Cliente clientes[], float monto) {
    clientes[indice].saldo += monto;
}

void retirar(int indice, Cliente clientes[], float monto){
    clientes[indice].saldo -= monto;
}

int main() {
    string clave;

    const int numClientes = 3;
    Cliente clientes[numClientes] = {
        Cliente("Cliente1", "Cuenta1", "Clave1", "Direccion1", "Telefono1", 100.0),
        Cliente("Cliente2", "Cuenta2", "Clave2", "Direccion2", "Telefono2", 200.0),
        Cliente("Cliente3", "Cuenta3", "Clave3", "Direccion3", "Telefono3", 300.0)
    };

    int indice_cliente;

    while (true) {
        cout << "Ingrese una clave: ";
        cin >> clave;

        indice_cliente = validar(clave, clientes, numClientes);
        if (indice_cliente != -1) {
            cout << "Clave correcta" << endl;
            cout<<"Numero Cuenta: "<<clientes[indice_cliente].numeroCuenta<<endl;
            cout<<"Nombre: "<<clientes[indice_cliente].nombre<<endl;
            cout<<"Numero Cuenta: "<<clientes[indice_cliente].direccion<<endl;
            cout<<"Numero Cuenta: "<<clientes[indice_cliente].telefono<<endl<<endl;
            break;
        } else {
            cout << "La clave ingresada no es valida" << endl;
        }
    }

    while (true) {
        int opcion;

        cout << "Que operacion desea realizar" << endl;
        cout << "Consulta de Saldo: Presione 1" << endl;
        cout << "Deposito: Presione 2" << endl;
        cout << "Retiro: Presione 3" << endl;
        cout<<"Para salir presione '4'"<<endl;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            float saldo = consulta_saldo(indice_cliente, clientes);
            system("cls");
            cout << "Su saldo actual es de: Q" << saldo << endl;
            break;
        }
        case 2: {
            float monto_deposito;
            system("cls");
            cout << "Ha seleccionado la operación de Depósito." << endl;
            cout << "Por favor, ingrese la cantidad que desea depositar: Q";
            cin >> monto_deposito;

            if (monto_deposito >= 1) {
                cout << "Ha ingresado la cantidad de Q" << monto_deposito << endl;
                cout << "Desea continuar con la operacion Si: Presione 1 / No: Presione 2" << endl;

                int opcion_deposito;
                cin >> opcion_deposito;

                if (opcion_deposito == 1) {
                    system("cls");
                    depositar(indice_cliente, clientes, monto_deposito);
                    cout << "Deposito exitoso, su saldo actual es de Q" << clientes[indice_cliente].saldo << endl;
                } else {
                    cout << "Operacion de depósito cancelada." << endl;
                }
            } else {
                cout << "LA CANTIDAD DEBE SER MAYOR A CERO" << endl;
            }
            break;
        }

        case 3: {
            int opcion_retiro;
            float monto_retiro;
            system("cls");
            cout<<"Retiro de Efectivo"<<endl;
                for(int e =0; e<20; e++){
                    cout<<"-";
                    cout<<"-";
                }
                cout<<endl;
            cout<<"Seleccione la cantidad a retirar: "<<endl;
            cout<<"1. Q100.00"<<endl;
            cout<<"2. Q200.00"<<endl;
            cout<<"3. Q500.00"<<endl;
            cout<<"4. Q1000.00"<<endl;
            cout<<"5. Otro monto"<<endl;

            if(opcion_retiro == 1){
                system("cls");
                while(true){
                cout<<"Ha seleccionado retirar Q1000.00. Desea continuar (Si: 1/ No:2)";cin>>opcion_retiro;cout<<endl;
                if(opcion_retiro == 1){
                    if(1000.0<clientes[indice_cliente].saldo){
                                retirar(indice_cliente, clientes, 1000.0);
                            cout<<"Transaccion completada. Por favor, retire su dinero. Gracias por utilizar nuestros servicios."<<endl;
                            cout<<"Tu saldo actual es de: "<<clientes[indice_cliente].saldo<<endl;
                        break;
                            }
                            else{
                                cout<<"Saldo insuficiente. No es posible completar la transaccion.";
                                cout<<"Ingrese una cantidad valida";
                                system("cls");                                
                                }
                }
                else{
                    cout<<"Operacion de retiro cancelada"<<endl;
                    break;
                }
                }
            }
            else if(opcion_retiro == 2){
                system("cls");
                while(true){
                cout<<"Ha seleccionado retirar Q200.00. Desea continuar (Si: 1/ No:2)";cin>>opcion_retiro;
                if(opcion_retiro == 1){
                    if(200.0<clientes[indice_cliente].saldo){
                                retirar(indice_cliente, clientes, 200.0);
                            cout<<"Transaccion completada. Por favor, retire su dinero. Gracias por utilizar nuestros servicios."<<endl;
                            cout<<"Tu saldo actual es de: "<<clientes[indice_cliente].saldo<<endl;
                        break;
                            }
                            else{
                                cout<<"Saldo insuficiente. No es posible completar la transaccion.";
                                cout<<"Ingrese una cantidad valida";
                                system("cls");                                
                                }
                }
                else{
                    cout<<"Operacion de retiro cancelada"<<endl;
                    break;
                }
                }
            }
            else if(opcion_retiro == 3){
                system("cls");
                while(true){
                cout<<"Ha seleccionado retirar Q500.00. Desea continuar? (Si: 1/ No:2)";cin>>opcion_retiro;cout<<endl;
                if(opcion_retiro == 1){
                    if(500.0<clientes[indice_cliente].saldo){
                                retirar(indice_cliente, clientes, 500.0);
                            cout<<"Transaccion completada. Por favor, retire su dinero. Gracias por utilizar nuestros servicios."<<endl;
                            cout<<"Tu saldo actual es de: "<<clientes[indice_cliente].saldo<<endl;
                        break;
                            }
                            else{
                                cout<<"Saldo insuficiente. No es posible completar la transacción.";
                                cout<<"Ingrese una cantidad valida!";
                                system("cls");                                
                                }
                }
                else{
                    cout<<"Operacion de retiro cancelada!"<<endl;
                    break;
                }
                }
            }
            else if(opcion_retiro == 4){
                system("cls");
                while(true){
                cout<<"Ha seleccionado retirar Q1000.00. Desea continuar (Si: 1/ No:2)";cin>>opcion_retiro;cout<<endl;
                if(opcion_retiro == 1){
                    if(1000.0<clientes[indice_cliente].saldo){
                                retirar(indice_cliente, clientes, 1000.0);
                            cout<<"Transacción completada. Por favor, retire su dinero. Gracias por utilizar nuestros servicios."<<endl;
                            cout<<"Tu saldo actual es de: "<<clientes[indice_cliente].saldo<<endl;
                        break;
                            }
                            else{
                                cout<<"Saldo insuficiente. No es posible completar la transacción.";
                                cout<<"Ingrese una cantidad valida!";                      
                                }
                }
                else{
                    cout<<"Operacion de retiro cancelada"<<endl;
                    break;
                    system("cls");
                }
                }
            }
            else if(opcion_retiro == 5){
                system("cls");
                while(true){
                        cout<<"Que cantidad desea retirar ";cin>>monto_retiro;cout<<endl;
                        cout<<"Ha seleccionado retirar Q"<<monto_retiro<<" Desea continuar? (Si: 1/ No:2)";cin>>opcion_retiro;cout<<endl;
                        if(opcion_retiro == 1){
                            if(monto_retiro<clientes[indice_cliente].saldo){
                                retirar(indice_cliente, clientes, monto_retiro);
                            cout<<"Transacción completada. Por favor, retire su dinero. Gracias por utilizar nuestros servicios."<<endl;
                            cout<<"Tu saldo actual es de: "<<clientes[indice_cliente].saldo<<endl;
                        break;
                            }
                            else{
                                cout<<"Saldo insuficiente. No es posible completar la transaccion.";
                                cout<<"Ingrese una cantidad valida";                                
                                }
                        }
                    }
                }
                else{
                    cout<<"Opcion no valida"<<endl;
                }
                break;
            }
            case 4:{
                exit(1);
            }
        }
    }
  

  return 0;

}
