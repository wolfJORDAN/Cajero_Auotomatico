#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>


using namespace std;


//Funcion encargada de validar la clave
bool validar(std::string clave_ingresada) {

    string clave_correcta;

    clave_correcta = "8526";

    /*pass = que busque las claves en el archivo txt*/

    if(clave_correcta == clave_ingresada){
        cout<<"Clave valida"<<endl;
        return true;
        

    }
    else{
        cout<<"Clave incorrecta!"<<endl;
        return false;
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

int main(){

    desplegar_menu();

    system("PAUSE");

    return 0;
}
