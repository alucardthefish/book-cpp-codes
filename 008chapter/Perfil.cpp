// **************************************************************************** 
// File: Perfil.cpp 
// Author: Sergio Ortiz Paz 
// Created: Thu Feb 13 21:13:44 2020 
// Description: Programa Perfil 
// **************************************************************************** 

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Prototipos de función
string Name();
void EvaluateCholesterol(ofstream& healthProfile, string name);
void EvaluateBMI(ofstream& healthProfile, string name);
void EvaluateBloodPressure(ofstream& healthProfile, string name);


int main(int argc, char * argv[]) {
    // Declarar y abir el archivo de entrada
    ofstream healthProfile;
    healthProfile.open("Profile");
    if(!healthProfile) {
	    cout << "No se puede abrir el archivo." << endl;
	    return 1;
    }
    string name;
    name = Name();

    //Escribir el nombre del paciente en el archivo de salida
    healthProfile << "Nombre del paciente " << name << endl;

    // Evaluar las estadisticas del paciente
    EvaluateCholesterol(healthProfile, name);
    EvaluateBMI(healthProfile, name);
    EvaluateBloodPressure(healthProfile, name);
    healthProfile << endl;
    healthProfile.close();
    return 0;
}


string Name() {
	string firstName;
	string lastName;
	char middleInitial;

	// Solicitar e introducir el nombre del paciente
	cout << "Introducir el primer nombre del paciente: ";
	cin >> firstName;
	cout << "Introducir el apellido del paciente: ";
	cin >> lastName;
	cout << "Introduzca la inicial del segundo nombre del paciente; ";
	cin >> middleInitial;
	return firstName + ' ' + middleInitial + ". " + lastName;
}
















