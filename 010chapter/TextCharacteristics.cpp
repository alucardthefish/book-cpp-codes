// **************************************************************************** 
// File: TextCharacteristics.cpp
// Author: Sergio Ortiz Paz
// Created: Fri Jan  3 20:34:26 2020
// Description: Make a stylish analysis of the text
// **************************************************************************** 

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

enum Features {UPPER, LOWER, DIGIT, IGNORE, EOW, EOS};

// Prototypes of the function
void OpenFiles(ifstream&, ofstream&);
Features Decode(char character);
void ProcessCharacter(char, int&, int&, int&, int&, int&, int&);
void PrintTable(ofstream& table, int, int, int, int, int, int);

int main() {
    //Prepare reading and writing files
    ifstream text;
    ofstream table;
    OpenFiles(text, table);
    if (!text || !table) {
        cout << "Files could not be opened!" << endl;
        return 1;
    }

    char character;         // Input character

    // Declare and initialize counters
    int uppercaseCounter = 0;
    int lowercaseCounter = 0;
    int digitCounter = 0;
    int wordCounter = 0;
    int sentenceCounter = 0;
    int ignoreCounter = 0;

    text.get(character);        // Character entered

    do {
        // Process each character
        ProcessCharacter(character, uppercaseCounter, lowercaseCounter, digitCounter, sentenceCounter, wordCounter, ignoreCounter);
        text.get(character);    // Character entered
    } while (text);

    PrintTable(table, uppercaseCounter, lowercaseCounter, digitCounter, sentenceCounter, wordCounter, ignoreCounter);
    text.close();
    table.close();
    return 0;
}


Features Decode(/* in */ char character)    // Decoded character
{
    if (isupper(character))
        return UPPER;
    else if (islower(character))
        return LOWER;
    else if (isdigit(character))
        return DIGIT;
    else
        switch (character){
            case '.':
            case '?':
            case '!':
                return EOS;
            case ' ':
            case ',':
            case ';':
            case ':':
            case '\n': return EOW;
        }
    return IGNORE;
}


void OpenFiles(/* inout */ ifstream& text, /* inout */ ofstream& table) {
    string inFileName;
    string outFileName;
    cout << "Enter the file name to be processed: " << endl;
    cin >> inFileName;
    text.open(inFileName.c_str());
    cout << "Enter the output file name: " << endl;
    cin >> outFileName;
    table.open(outFileName.c_str());
    table << "Analysis of the characters in the input file: " << inFileName << endl << endl;
}


void PrintTable(ofstream& table, int uppercaseCounter, int lowercaseCounter, int digitCounter, int sentenceCounter, int wordCounter, int ignoreCounter)
{
    int totalAlphaNum;
    totalAlphaNum = uppercaseCounter + lowercaseCounter + digitCounter;

    // Print results in file table
    table << "Total number of alphanumeric characters: " << totalAlphaNum << endl;
    table << "Total number of uppercase letters: " << uppercaseCounter << endl;
    table << "Total number of lowercase letter: " << lowercaseCounter << endl;
    table << "Number of digits: " << digitCounter << endl;
    table << "Number of ignored characters: " << ignoreCounter << endl;

    // Add the number of end line character markers to the word counting
    wordCounter = wordCounter + sentenceCounter;

    // Write the remaining results in table
    table << "Number of words: " << wordCounter << endl;
    table << "Number of sentences: " << sentenceCounter << endl;
    table << "Average word length: " << fixed << setprecision(2) << float(totalAlphaNum) / wordCounter << endl;
    table << "Average sentence length: " << fixed << setprecision(2) << float(wordCounter) / sentenceCounter << endl;
}


void ProcessCharacter(char character, int& uppercaseCounter, int& lowercaseCounter, int& digitCounter, int& sentenceCounter, int& wordCounter, int& ignoreCounter){
    static bool endOfWord = false;

    switch(Decode(character)) {
        case UPPER:
            uppercaseCounter++;
            endOfWord = false;
            break;
        case LOWER:
            lowercaseCounter++;
            endOfWord = false;
            break;
        case DIGIT:
            digitCounter++;
            endOfWord = false;
            break;
        case EOW:
            if (!endOfWord) {
                wordCounter++;
                endOfWord = true;
            }
            break;
        case EOS:
            sentenceCounter++;
            break;
        case IGNORE:
            ignoreCounter++;
            break;
    }
}
