// **************************************************************************** 
// File: testTypedef.cpp
// Author: Sergio Ortiz Paz
// Created: Fri Jan  3 19:42:43 2020
// Description: Conociendo los tipos de datos definidos por el programador
// **************************************************************************** 

#include <iostream>

using namespace std;

/*
    The sentence Typedef:
    typedef name_of_existing_data_type name_of_new_type
*/

typedef int Boolean;

const int TRUE = 1;
const int FALSE = 0;

/*
    The sentence enum
    enum name {Enumerator, Enumerator, ...};
    The sentence of enumerator
    identifier = ConstIntExpression
*/

enum Animals {RODENT, CAT, DOG, BIRD, REPTILE, HORSE, BOVINE, SHEEP};


int main () {
    // Main function
    cout << "Welcome to the typedef testing:" << endl;
    Boolean dataOk;
    dataOk = TRUE;
    if (dataOk) {
        cout << "Data is ok" << endl;
    } else {
        cout << "Data is not ok" << endl;
    }

    Animals inPatient;
    Animals outPatient;

    inPatient = DOG;

    cout << "Dog: " << inPatient << endl;
    switch (inPatient) {
        case RODENT:
        case CAT:
        case DOG:
        case BIRD:
            cout << "Jaula" << endl;
            break;
        case REPTILE: cout << "Terrario" << endl;
            break;
        case HORSE:
        case BOVINE:
        case SHEEP: 
            cout << "Establo" << endl;
    }
    return 0;
}

