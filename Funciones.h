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

    Cliente(string, string, string, string , string, float);
};

Cliente::Cliente(string _nombre, string _numeroCuenta, string _clave, string _direccion, string _telefono, float _saldo){
    nombre = _nombre;
    numeroCuenta = _numeroCuenta;
    clave = _clave;
    direccion = _direccion;
    telefono = _telefono;
    saldo = _saldo;
    
}

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

void retiro(int indice, Cliente clientes[], float monto){
    clientes[indice].saldo = clientes[indice].saldo - monto;
}

void Operaciones() {
    string clave;

    const int numClientes = 10;

    Cliente clientes[numClientes] = {
        Cliente("Juan Carlos Ramirez Perez", "12345678", "1234", "San Jose La Arada, Chiquimula", "(502)1234-5678", 1000.0),
        Cliente("Maria Isabel Martinez Garcia", "12345679", "1734", "San Jose La Arada, Chiquimula", "(502)1234-5679", 200.0),
        Cliente("Luis Alberto Rodriguez Fernandez", "12345679", "2234", "Ipala, Chiquimula", "(502)1234-5671", 300.0),
        Cliente("Ana Sofia Lopez Torres", "123459789", "1235", "Direccion3", "(502)1234-5688", 400.0),
        Cliente("Pedro Antonio Gonzalez Ramirez", "12345677", "5678", "San Jose La Arada, Chiquimula", "(502)1234-5778", 500.0),
        Cliente("Laura Victoria Hernandez Silva", "12345676", "8998", "Esquipulas, Chiquimula", "(502)5234-5678", 600.0),
        Cliente("Miguel Angel Perez Diaz", "12345675", "6556", "San Jose La Arada, Chiquimula", "(502)1234-5673", 1000.0),
        Cliente("Gabriela Alejandra Torres Ruiz", "12345674", "9983", "San Jose La Arada, Chiquimula", "(502)9636-8525", 550.0),
        Cliente("Manuel Alejandro Sanchez Martines", "12345673", "7887", "Esquipulas, Chiquimula", "(502)9080-6030", 2000.0),
        Cliente("Paola Andrea Gomez Lopez", "12345672", "7896", "San Jose La Arada, Chiquimula", "(502)4586-3645", 300.0)
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
            cout<<"Direccion: "<<clientes[indice_cliente].direccion<<endl;
            cout<<"Telefono: "<<clientes[indice_cliente].telefono<<endl<<endl;
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
            cout << "Ha seleccionado la operacion de Deposito." << endl;
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
                    cout << "Operacion de deposito cancelada." << endl;
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
    cout << "Retiro de Efectivo" << endl;
    for (int e = 0; e < 20; e++) {
        cout << "-";
        cout << "-";
    }
    cout << endl;
    cout << "Seleccione la cantidad a retirar: " << endl;
    cout << "1. Q100.00" << endl;
    cout << "2. Q200.00" << endl;
    cout << "3. Q500.00" << endl;
    cout << "4. Q1000.00" << endl;
    cout << "5. Otro monto" << endl;
    cin >> opcion_retiro;

    switch (opcion_retiro) {
    case 1:
        monto_retiro = 100.0;
        break;
    case 2:
        monto_retiro = 200.0;
        break;
    case 3:
        monto_retiro = 500.0;
        break;
    case 4:
        monto_retiro = 1000.0;
        break;
    case 5:
        cout << "Que cantidad desea retirar: ";
        cin >> monto_retiro;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }

    if (opcion_retiro >= 1 && opcion_retiro <= 5) {
        if (monto_retiro <= clientes[indice_cliente].saldo) {
            system("cls");
            retiro(indice_cliente, clientes, monto_retiro);
            cout << "Transaccion completada. Por favor, retire su dinero. Gracias por utilizar nuestros servicios." << endl;
            cout << "Tu saldo actual es de: " << clientes[indice_cliente].saldo << endl;
            } else {
                system("cls");
                cout << "Saldo insuficiente. No es posible completar la transaccion." << endl;
            }
        }
        break;
    }

            case 4:{
                int opc_salir;
                system("cls");
                cout<<"Deseas salir? Si:1 / No:2"<<endl;
                cin>>opc_salir;
                if(opc_salir == 1){
                    exit(1);
                }
                else{
                    break;
                }
                
            }
        }
    }

}
