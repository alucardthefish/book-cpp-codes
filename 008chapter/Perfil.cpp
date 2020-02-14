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


void EvaluateCholesterol(ofstream& healthProfile, string name){
	int HDL;
	int LDL;

	// Solicitar e introducir HDL y LDL
	cout << "Introducir HDL para " << name << ": ";
	cin >> HDL;
	cout << "Introducir LDL para " << name << ": ";
	cin >> LDL;
	float ratio = LDL/HDL;

	healthProfile << "Perfil de colesterol " << endl;
	// Imprimir un mensaje con en el valor de HDL
	if(HDL < 40){
		healthProfile << "  HDL es demasiado bajo" << endl;
	} else if(HDL < 60) {
		healthProfile << "  HDL es correcto" << endl;
	} else {
		healthProfile << "  HDL es excelente" << endl;
	}
	// Imprimir un mensaje con base en el valor de LDL
	if(LDL < 100) {
		helthProfile << "   LDL es óptimo" << endl;
	} else if (LDL < 130) {
		healthProfile << "  LDL es casi óptimo" << endl;
	} else if (LDL < 160) {
		healthProfile << "  LDL está en el limite alto" << endl;
	} else if (LDL < 190) {
		healthProfile << "  LDL es alto" << endl;
	} else {
		healthProfile << "  LDL es muy bajo" << endl;
	}

	if (ratio < 3.22) {
		healthProfile << "  La relación de LDL a HDL es buena" << endl;
	} else {
		healthProfile << "  La relación de LDL a HDL no es buena" << endl;
	}














