//******************************************************************
// Programa CostoDeHogar
// Este programa calcula el costo por pie cuadrado de
// espacio vital para una casa, dadas las dimensiones de
// la  casa, el número de pisos, el tamaño del
// espacio no vital y el costo total menos el terreno.
//******************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

const float WIDTH = 30.0;                   // Ancho de la casa
const float LENGTH = 40.0;                  // Longitud de la casa
const float STORIES = 2.5;                  // Número de pisos completos
const float NON_LIVING_SPACE = 825.0;       // Cochera, armarios, etc.
const float PRICE = 150000.0;               // Precio de venta menos el terreno

int main()
{
    float grossFootage;             // Total de pies cuadrados
    float livingFootage;            // Área vital
    float costPerFoot;              // Costo/pie de area vital
    cout << fixed << showpoint;     // Establecer el punto flotante

    grossFootage = LENGTH * WIDTH * STORIES;
    livingFootage = grossFootage - NON_LIVING_SPACE;
    costPerFoot = PRICE / livingFootage;

    cout << "El costo por pie cuadrado es " << setw(6) << setprecision(2) << costPerFoot << endl;

    return 0;
}