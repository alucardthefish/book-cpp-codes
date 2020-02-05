// **************************************************************************** 
// File: IndiceMasaCorporal.cpp
// Author: Sergio Ortiz Paz
// Created: Sat Jan  4 00:44:28 2020
// Description: Este programa calcula el indice de masa corporal (IMC) dado un peso
// en libras y una estatura en pulgadas e imprime un mensaje de salud
// con base en el IMC. 
// **************************************************************************** 


#include <iostream>
#include <string>

using namespace std;

int main() {
    const int BMI_CONSTANT = 703;                   // Constante de la formula no métrica
    float weight;
    float height;
    float bodyMassIndex;
    bool dataAreOk;

    cout << "El sitema metrico usado por defecto es el americano. Esto significa que se debe ingresar el peso en libras" << endl;
    cout << "y la estatura en pulgadas. Otra opción es el sistema métrico estandar con kilogramos para peso y centimetros para altura" << endl;
    cout << "Desea continuar con el sitema por defecto: ";
    string selection;
    bool isDefault;
    cin >> selection;
    if (selection == "y" || selection == "Y" || selection == "yes" || selection == "YES") {
        cout << "Introduzca su peso en libras: ";
        cin >> weight;
        cout << endl << "Introduzca su estatura en pulgadas: ";
        cin >> height;
        isDefault = true;
    } else {
        cout << "Introduzca su peso en kilogramos: ";
        cin >> weight;
        cout << endl << "Introduzca su estatura en centimetros: ";
        cin >> height;
        isDefault = false;
    }

    

    if (weight < 0 || height < 0) {
        dataAreOk = false;
    } else {
        dataAreOk = true;
    }

    if (dataAreOk) {

        if (!isDefault) {
            const float kiloInPounds = 2.20462;
            const float cmInInches = 0.393701;
            weight = weight * kiloInPounds;
            height = height * cmInInches;
        }

        bodyMassIndex = weight * BMI_CONSTANT / (height * height);

        cout << "Su indice de masa corporal es " << bodyMassIndex << ". " << endl;
        cout << "Interpretación e instrucciones." << endl;

        if (bodyMassIndex < 20) {
            cout << "Peso dabajo del normal: tome una malteada." << endl;
        } else if (bodyMassIndex <= 25) {
            cout << "Normal: tome un vaso de leche." << endl;
        } else if (bodyMassIndex <= 30) {
            cout << "Sobrepeso: tome un vaso de té helado." << endl;
        } else {
            cout << "Obesidad: consulte a su médico." << endl;
        }
    } else {
        cout << "Datos no válidos: el peso y la estatura deben ser positivos." << endl;
    }

    cout << "Juego del while: no contestes si, porque no te sigo preguntando." << endl;
    string answer;
    while (answer != "yes") {
        cout << "¿Eres marica?: ";
        cin >> answer;
        cout << endl;
    }
    return 0;
}

