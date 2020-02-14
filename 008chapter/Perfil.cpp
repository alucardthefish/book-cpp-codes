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
		healthProfile << "   LDL es óptimo" << endl;
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
}


void EvaluateBMI(ofstream& healthProfile, string name) {
	const int BMI_CONSTANT = 703;

	float pounds;
	float inches;

	// Introducir el peso y la estatura
	cout << "Introducir el peso en libras para " << name << ": ";
	cin >> pounds;
	cout << "Introducir la estatura en pulgadas para " << name << ": ";
	cin >> inches;
	float bodyMassIndex = pounds * BMI_CONSTANT / (inches * inches);
	healthProfile << "Perfil del indice de masa corporal" << endl;
	// imprimir el indice de masa corporal
	healthProfile << "  El indice de masa corporal es " << bodyMassIndex << ". " << endl;
	healthProfile << "  Interpretación del IMC " << endl;

	// Imprimir interpretación del IMC
	if (bodyMassIndex < 20) {
		healthProfile << "  Abajo del peso normal: el IMC  es muy bajo" << endl;
	} else if (bodyMassIndex <= 25) {
		healthProfile << "  Normal: el IMC  es el promedio" << endl;
	} else if (bodyMassIndex <= 30) {
		healthProfile << "  Sobrepeso: el IMC es muy alto" << endl;
	} else {
		healthProfile << "  Obeso: el IMC es peligrosamente alto" << endl;
	}
}


void EvaluateBloodPressure(ofstream& healthProfile, string name) {
	// Declarar las lecturas de tension arterial
	int systolic;
	int diastolic;

	// Introducir las lecturas de tensión arterial del paciente
	cout << "Introducir las lectura de tensión arterial sistólica para " << name << ": ";
	cin >> systolic;
	cout << "Introduzca la lectura de tension arterial diastólica para " << name << ": ";
	cin >> diastolic;

	// Imprimir la interpretación de la lectura sistólica
	healthProfile << "Perfil de tensión arterial " << endl;
	if (systolic < 120) {
		healthProfile << "  La lectura sistólica es óptima" << endl;
	} else if (systolic < 130) {
		healthProfile << "  La lectura sistolica es normal" << endl;
	} else if (systolic < 140) {
		healthProfile << "  La lectura sistólica es normal alta" << endl;
	} else if (systolic < 160) {
		healthProfile << "  La lectura sistólica indica etapa 1 de hipertensión" << endl;
	} else if (systolic < 180) {
		healthProfile << "  La lectura sistólica indica etapa 2 de hipertensión" << endl;
	} else {
		healthProfile << "  La lectura sistólica indica etapa 3 de hipertensión" << endl;
	}

	// Imprimir la interpretación de la lectura diastólica
	if (diastolic < 80) {
		healthProfile << "  La lectura diastólica es óptima" << endl;
	} else if (diastolic < 85) {
		healthProfile << "  La lectura diastólica es normal" << endl;
	} else if (diastolic < 90) {
		healthProfile << "  La lectura diastólica es normal alta" << endl;
	} else if (diastolic < 100) {
		healthProfile << "  La lectura diastólica indica etapa 1 de hipertensión" << endl;
	} else if (diastolic < 110) {
		healthProfile << "  La lectura diastólica indica etapa 2 de hipertensión" << endl;
	} else {
		healthProfile << "  La lectura diastólica indica etapa 3 de hipertensión" << endl;
	}
}




