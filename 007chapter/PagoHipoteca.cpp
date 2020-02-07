// **************************************************************************** 
// File: PagoHipoteca.cpp 
// Author: Sergio Ortiz Paz 
// Created: Thu Feb  6 20:01:49 2020 
// Description: Programa tablas de pago de hipoteca 
// Este programa imprime una tabla que muestra la cantidad prestada,
// La tasa de interés, la duración del préstamo, los pagos mensuales
// y el costo total de la hipoteca.
// **************************************************************************** 


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// Prototipos de función
void PrintHeading(ofstream&);
void DeterminePayment(float, int, float, float&);
void PrintResults(ofstream&, float, int, float, float);

int main(int argc, char * argv[]) {
	// Variables de entrada
	float loanAmount;
	float yearlyInterest;
	int numberOfYears;
	float payment;
	
	// Declarar y abrir el archivo de entrada
	ofstream dataOut;
	dataOut.open("mortgage.out");
	if(!dataOut) {
		cout << "No se puede abrir el archivo de salida." << endl;
		return 1;
	}
	
	PrintHeading(dataOut);
	
	// Solicitar y leer la cantidad prestada
	cout << "introducir la cantidad total prestada; " << "un valor negativo detiene el proceso. " << endl;
	cin >> loanAmount;
	
	// Ciclo que calcula los pagos mensuales
	while (loanAmount >= 0.0) {
		// Solicitar y leer la tasa de interes y el numero de años.
		cout << "Introducir la tasa de interes." << endl;
		cin >> yearlyInterest;
		cout << "Introducir el numero de años del prestamo" << endl;
		cin >> numberOfYears;
		
		DeterminePayment(loanAmount, numberOfYears, yearlyInterest, payment);
		PrintResults(dataOut, loanAmount, numberOfYears, yearlyInterest, payment);
		
		// Solicitar y leer la cantidad prestada
		cout << "Introducir la cantidad total prestada; "
			<< "un valor negativo detiene el proceso. " << endl;
		cin >> loanAmount;
	}
	
	dataOut.close();
    return 0;
}

//*************************************************************************************************


void DeterminePayment(float loanAmount,
						int numberOfYears,
						float yearlyInterest,
						float& payment)
// Calcula el pago mensual para una cantidad prestada con la
// formula para el interes compuesto.
{
	// variables locales
	float monthlyRate;
	int numberOfPayments;
	
	monthlyRate = yearlyInterest / 1200;
	numberOfPayments = numberOfYears * 12;
	payment = (loanAmount * pow(1 + monthlyRate, numberOfPayments) * monthlyRate) / 
				(pow(1 + monthlyRate, numberOfPayments) - 1);
}

//*************************************************************************************************


void PrintResults(ofstream& dataOut,
				float loanAmount,
				int numberOfYears,
				float yearlyInterest,
				float payment)
{
	dataOut << fixed << setprecision(2) << setw(12) << loanAmount
			<< setw(12) << numberOfYears << setw(12)
			<< yearlyInterest << setw(15) << payment
			<< setw(12) << numberOfYears*12*payment << endl;
}


//*************************************************************************************************

void PrintHeading(ofstream& dataOut) {
	dataOut << fixed << setprecision(2) << setw(12) << "Cantidad prestada"
			<< setw(12) << "Num. de años" << setw(15)
			<< "Tasa de interes" << setw(12) << "Pago"
			<< setw(12) << "Total pagado" << endl;
}


















