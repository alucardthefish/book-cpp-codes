#include <iostream>
#include <string>

using namespace std;

const string FIRST = "Herman";
const string LAST = "Smith";
const char MIDDLE = 'G';

int main()
{
    string firstLast;
    string lastFirst;

    firstLast = FIRST + " " + LAST;
    cout << "El nombre con formato nombre-apellido es " << firstLast << endl;

    lastFirst = LAST + ", " + FIRST + ", ";
    cout << "El nombre en formato apellido-nombre-inicial es ";
    cout << lastFirst << MIDDLE << "." << endl;

    return 0;
}