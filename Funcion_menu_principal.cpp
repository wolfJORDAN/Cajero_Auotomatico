#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>


using namespace std;


//Funcion encargada de validar la clave
void validar(std::string clave) {

    string pass;

    /*pass = que busque las claves en el archivo txt*/

    cout<<"Ingrese una clave: ";
    getline(cin, pass);

    if(pass == clave){
        cout<<"Clave valida"<<endl;
    }
    else{
        cout<<"Clave incorrecta!"<<endl;
    }
}

