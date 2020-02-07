// **************************************************************************** 
// File: Acoustic.cpp 
// Author: Sergio Ortiz Paz 
// Created: Sat Feb  1 17:33:09 2020 
// Description: Programa Acoustic
// Este programa introduce 12 lecturas de nive de sonido, tomadas en una
// habitación a diferentes frecuencias. La primera lectura se empelea como un
// valor base. El programa termina al imprimir la depresión más baja
// en las lecturas, donde una depresión se define com una lectura
// seguidade una lectura mayor 
// **************************************************************************** 


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]) {
    // Declarar variables
    float baseValue;
    float preceding;
    float precedingRelative;
    float current;
    float relative;
    float high;
    float highRelative;
    float low;
    float lowRelative;
    int highNumber;
    int lowNumber;
    int readingNumber;

    // Declarar y abrir el archivo de entrada
    ifstream inData;
    inData.open("acoustic.dat");
    if (!inData) {
	    cout << "No es posible abrir el archivo de entrada." << endl;
	    return 1;
    }

    // Inicializar variables y resultado
    cout << setw(14) << "Número de lectura" << setw(15)
	    << "Lectura real" << setw(18) << " Lectura relativa"
	    << endl;
    inData >> baseValue;
    preceding = baseValue;
    precedingRelative = 0.0;
    highNumber = 1;
    lowNumber = 1;
    high = baseValue;
    low = baseValue;
    highRelative = 0.0;
    lowRelative = 0.0;
    readingNumber = 1;
    relative = 0.0;

    // Escribir la primera linea de salida
    cout << fixed << showpoint << setprecision(2) << setw(7)
	    << readingNumber << setw(19)
	    << baseValue << setw(15) << relative << endl;

    readingNumber = 2;

    while (readingNumber <= 12) {
	    inData >> current;
	    relative = current - baseValue;
	    cout << setw(7) << readingNumber << setw(19) << current
		    << setw(15) << relative << endl;
		
		if (current > high) {
			high = current;
			highNumber = readingNumber;
			highRelative = relative;
		}

	    if (current > preceding) {
		    if (preceding < low) {
			    low = preceding;
			    lowNumber = readingNumber - 1;
			    lowRelative = precedingRelative;
		    }
	    }
	    preceding = current;
	    precedingRelative = relative;
	    readingNumber++;
    }

    // Imprimir las lecturas alta y baja
    cout << endl;
    cout << "El número de lectura máxima es " << highNumber << endl;
    cout << "La lectura máxima es " << high << endl;
    cout << "El valor relativo máximo es " << highRelative << endl;
    cout << endl;
    cout << "El número de depresión más baja es " << lowNumber << endl;
    cout << "La depresión más baja es " << low << endl;
    cout << "La depresión relativa más baja es " << lowRelative << endl;

    inData.close();
    return 0;
}

