// **************************************************************************** 
// File: Main.cpp 
// Author: Sergio Ortiz Paz 
// Created: Wed Feb 19 00:04:57 2020 
// Description: Probando objeto Name 
// **************************************************************************** 


#include "Name.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
    cout << "Bienvenido a la clase Name" << endl;
    Name superMan("Clark", "Arthur", "Kent");
    Name spiderMan;
    spiderMan.SetName("Peter", "James", "Parker");
    Name yourName;
    yourName.ReadName();
    string comparisonStrings[3] = {"Antes", "Igual", "Despues"}; 
    cout << "Comparando tu nombre frente al de superman, te encuentras: " << comparisonStrings[yourName.ComparedTo(superMan)] << endl;
    cout << "Comparando tu nombre frente al de spiderman, te encuentras: " << comparisonStrings[yourName.ComparedTo(spiderMan)] << endl;
    return 0;
}

