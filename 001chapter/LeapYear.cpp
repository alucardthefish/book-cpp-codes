//*****************************************************************************************
// Programa del año bisiesto
// Este programa ingresa un año e imprime el año
// es año bisiesto o no
//*****************************************************************************************

#include <iostream>     // Acceso de flujo de salida

using namespace std;

bool IsLeapYear(int);   // Prototipo para el subalgoritmo

int main()
{
    int year;           // Año a ser probado
    cout << "Introduzca un año por ejemplo, 1997." << endl;     // Solicita la entrada
    cin >> year;        // Lee año
    
    if(IsLeapYear(year)){   // Prueba para el año bisiesto
        cout << year << " es un año bisiesto." << endl;
    } else {
        cout << year << " no es un año bisiesto." << endl;
    }

    return 0;       // Indica que se completó satisfactoriamente
}

//*******************************************************************************************

bool IsLeapYear(int year)
// IsLeapYear regresa verdadero si year es un año bisiesto y
// falso en cualquier otro caso
{
    if(year % 4 != 0){
        return false;
    }
    else if (year % 100 != 0){
        return true;
    }
    else if(year % 400 != 0){
        return false;
    }
    else {
        return true;
    }
}

