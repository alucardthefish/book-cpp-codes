// **************************************************************************** 
// File: TioRico.cpp 
// Author: Sergio Ortiz Paz 
// Created: Sun Feb 16 20:39:39 2020 
// Description: Programa Tio rico
// Se imprime una tabla que muestra el porcentaje de caracteres en el
// archivo que pertenecen a cinco categorias: caracteres de mayúsculas,
// caracteres de minusculas, digitos decimales, espacios y marccas 
// de puntuacion de fin de enunciado. 
// **************************************************************************** 

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;


// Prototipos de funcion
void OpenFiles(ifstream&, ofstream&);
void IncrementCounter(char, int&, int&, int&, int&, int&, int&);
void PrintTable(ofstream& table, int, int, int, int, int, int);


int main(int argc, char * argv[]) {
    
	// Preparar los archivos para lectura y escritura
	ifstream text;
	ofstream table;
	char character;

	// Declarar e inicializar contadores
	int uppercaseCounter = 0;
	int lowercaseCounter = 0;
	int blankCounter = 0;
	int digitCounter = 0;
	int punctuationCounter = 0;
	int allEseCounter = 0;

	OpenFiles(text, table);
	if (!text || !table) {
		cout << "Los archivos no se abrieron de manera exitosa." << endl;
		return 1;
	}
	text.get(character);		// Introducir un carácter
	do
	{ // Procesar cada carácter
		IncrementCounter(character, uppercaseCounter, lowercaseCounter, blankCounter, digitCounter, punctuationCounter, allElseCounter);
		text.get(character);
	} while (text);

	PrintTable(table, uppercaseCounter, lowercaseCounter, blankCounter, digitCounter, punctuationCounter, allElseCounter);

	text.close();
	table.close();
	return 0;

}

//****************************************************************************************************************

void IncrementCounter(char character, int& uppercaseCounter, int& lowercaseCounter, int& blankCounter, int& digitCounter, int& punctuationCounter, int& allElseCounter)
{
	if (isuper(character)) {
		uppercaseCounter++;
	} else if (islower(character)) {
		lowercaseCounter++;
	} else if (character == ' '){
		blankCounter++;
	} else if (isdigit(character)) {
		digitCounter++;
	} else if ((character == '.') || (character == '?') || (character == '!')) {
		punctuationCounter++;
	} else {
		allElseCounter++;
	}
}

//*****************************************************************************************************************

void PrintTable(ofstream& table, 
		int uppercaseCounter, 
		int lowercaseCounter, 
		int blankCounter, 
		int digitCounter, 
		int punctuationCounter, 
		int allElseCounter)
{
	// Calcualar el número total de caracteres
	float total = uppercaseCounter + lowercaseCounter
		+ blankCounter + digitCounter + punctuationCounter
		+ allElseCounter;

	// Escribir el resultado en la tabla de flujo
	table << fixed << setprecision(3)
		<< "Porcentaje de mayúsculas: "
		<< uppercaseCounter / total * 100 << endl;
	table << fixed << setprecision(3)
		<< "Porcentaje de minúsculas: "
		<< lowercaseCounter / total * 100 << endl;
	table << fixed << setprecision(3)
		<< "Porcentaje de espacios: "
		<< blankCounter / total * 100 << endl;
	table << fixed << setprecision(3)
		<< "Porcentaje de digitos: "
		<< digitCounter / total * 100 << endl;
	table << fixed << setprecision(3)
		<< "Porcentaje de signos de fin de enunciado: "
		<< "Puntuación " << punctuationCounter / total * 100 << endl;

}




