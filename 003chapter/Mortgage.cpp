//******************************************************************
// Programa Calculadora para pago de hipoteca
// Este programa determina los pagos mensuales en una hipoteca dadas
// la cantidad prestada, el interes anual y el numero de años.
//******************************************************************

#include <iostream>     // Acceso a cout
#include <cmath>        // Acceso a funcion de potencia
#include <iomanip>      // Acesso a manipuladores

using namespace std;

const float LOAN_AMOUNT = 50000.00;     // Cantidad del prestamo
const float YEARLY_INTEREST = 0.0524;   // Tasa de interes anual
const int NUMBER_OF_YEARS = 7;          // Numero de años

int main() {
    // Variables locales
    float monthlyInterest;              // Tasa de interes mensual
    int numberOfPayments;               // Numero total de pagos
    float payment;                      // Pago mensual

    // Calcular valores
    monthlyInterest = YEARLY_INTEREST / 12;
    numberOfPayments = NUMBER_OF_YEARS * 12;
    payment = (LOAN_AMOUNT *
                pow(monthlyInterest + 1, numberOfPayments)
                * monthlyInterest) / (pow(monthlyInterest + 1, numberOfPayments) - 1);
    
    // Salida de resultados
    cout << fixed << setprecision(2) << "Para una cantidad prestada de $"
        << LOAN_AMOUNT << " con una tasa de interes de "
        << YEARLY_INTEREST << " y una  hipoteca anual de " << NUMBER_OF_YEARS << " años" << endl;
    cout << " sus pagos mensuales son de $" << payment << "." << endl;
    return 0;
}