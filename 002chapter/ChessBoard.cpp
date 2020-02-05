// To compile use g++ -o nameForExecutable file.cpp

#include <iostream>
#include <string>

using namespace std;

// const string BLACK = "********";
// const string WHITE = "        ";
const string BLACK = "*";
const string WHITE = " ";

string multiply(string cadena, int num){
    string rst = "";
    for (int i = 1; i<=num; i++){
        rst += cadena;
    }
    return rst;
}

int main(){
    int sizeOfBlock;
    int heightOfBlock;
    string whitening;
    string blackening;
    string whiteRow;
    string blackRow;

    cout << "Welcome to Chess Board maker!" << endl << "Select the size of blocks of the board: ";
    cin >> sizeOfBlock;
    heightOfBlock = sizeOfBlock / 2;

    whitening = multiply(WHITE, sizeOfBlock);
    blackening = multiply(BLACK, sizeOfBlock);

    whiteRow = whitening + blackening + whitening + blackening + whitening + blackening + whitening + blackening;
    blackRow = blackening + whitening + blackening + whitening + blackening + whitening + blackening + whitening;

    for(int j = 1; j <= 4; j++){
        for(int i = 1; i <= heightOfBlock; i++){
            cout << whiteRow << endl;
        }
        for(int i = 1; i <= heightOfBlock; i++){
            cout << blackRow << endl;
        }
    }

    cout << endl << "Testing.........." << endl;
    cout << multiply(BLACK, 3) << endl;

    return 0;
}