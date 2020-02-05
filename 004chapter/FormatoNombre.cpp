//*********************************************************************************
// Programa formato nombre
// Este programa lee un numero de seguro social, un nombre, un
// segundo nombre o inicial y el apellido del archivo inData.
// El nombre se escribe en el archivo outData en tres formatos:
//  1. Nombre, segundo nombre, apellido y numero de seguro social.
//  2. Apellido, nombre, segundo nombre y numero de seguro social.
//  3. Apellido, nombre, segundo nombre y numero de seguro social.
//  4. Apellido, nombre, inicial del segundo nombre y numero de seguro social.
//*********************************************************************************

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    // Declarar y abrir archivos
    ifstream inData;
    ofstream outData;
    inData.open("name.dat");
    outData.open("name.out");

    // Declarar variables
    string socialNum;       // Numero de seguro social
    string firstName;       // Nombre
    string lastName;        // Apellido
    string middleName;      // Segundo nombre
    string initial;         // Inicial del segundo nombre

    // Leer los datos del archivo inData
    inData >> socialNum >> firstName >> middleName >> lastName;

    // Tener acceso a la inicial del segundo nombre y anexar un punto
    initial = middleName.substr(0, 1) + '.';

    // Producir informacion en los formatos requeridos
    outData << firstName << " " << middleName << " " << lastName << " " << socialNum << endl;
    outData << lastName << ", " << firstName << " " << middleName << " " << socialNum << endl;
    outData << lastName << ", " << firstName << " " << initial << " " << socialNum << endl;
    outData << firstName << " " << initial << " " << lastName << endl;

    // Cerrar archivos
    inData.close();
    outData.close();
    cout << "Los datos fueron escritos correctamente en el archivo .out" << endl;

    int inputVal;
    cout << "La variable inputVal se asignara cuantas veces se requiera, siempre y cuando no sea 25" << endl;

    while(inputVal != 25){
        cout << endl << "inputVal: ";
        cin >> inputVal;
    }
    cout << "Por fin saliste de ese ciclo eh!" << endl;

    return 0;
}