//
//  main.cpp
//  challenge1
//
//  Created by John Davies on 23/11/2021.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

// global declarations:

vector<char> outputVector;

// valid hex characters
vector<char> validHexChars { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'x'};

// base64 lookup table
map<string, char> base64Lookup = {
    {"000000", 'A'}, {"000001", 'B'}, {"000010", 'C'}, {"000011", 'D'}, {"000100", 'E'}, {"000101", 'F'}, {"000110", 'G'}, {"000111", 'H'}, {"001000", 'I'}, {"001001", 'J'}, {"001010", 'K'}, {"001011", 'L'}, {"001100", 'M'}, {"001101", 'N'}, {"001110", 'O'}, {"001111", 'P'}, {"010000", 'Q'}, {"010001", 'R'}, {"010010", 'S'}, {"010011", 'T'}, {"010100", 'U'}, {"010101", 'V'}, {"010110", 'W'}, {"010111", 'X'}, {"011000", 'Y'}, {"011001", 'Z'}, {"011010", 'a'}, {"011011", 'b'}, {"011100", 'c'}, {"011101", 'd'}, {"011110", 'e'}, {"011111", 'f'}, {"100000", 'g'}, {"100001", 'h'}, {"100010", 'i'}, {"100011", 'j'}, {"100100", 'k'}, {"100101", 'l'}, {"100110", 'm'}, {"100111", 'n'}, {"101000", 'o'}, {"101001", 'p'}, {"101010", 'q'}, {"101011", 'r'}, {"101100", 's'}, {"101101", 't'}, {"101110", 'u'}, {"101111", 'v'}, {"110000", 'w'}, {"110001", 'x'}, {"110001", 'x'}, {"110010", 'y'}, {"110011", 'z'}, {"110100", '0'}, {"110101", '1'}, {"110110", '2'}, {"110111", '3'}, {"111000", '4'}, {"111001", '5'}, {"111010", '6'}, {"111011", '7'}, {"111100", '8'}, {"111101", '9'}, {"111110", '+'}, {"111111", '/'},
};

// helper functions:

vector<bool> convertToBinary(int charAsDecimal) {
    vector<bool> bits = {0, 0, 0, 0};
    int remainder = charAsDecimal;
    
    for (int i = 3; i > -1; i--) {
        if (remainder - pow(2, i) >= 0) {
            remainder -= pow(2, i);
            int index = 3 - i;
            bits[index] = 1;
        }
    }
    return bits;
}

void encodeGroup(vector<bool> inputGroup, int sextets) {
    for (int i = 0; i < sextets; i++) {
        string sextetString = "------";
        
        for (int i = 0; i < 6; i++) {
            if (inputGroup[i]) {
                sextetString[i] = '1';
            } else {
                sextetString[i] = '0';
            }
        }
        
        inputGroup.erase(inputGroup.begin(), inputGroup.begin() + 6);
        outputVector.push_back(base64Lookup[sextetString]);
    }
    
    char paddingChar = '=';
    
    switch (sextets) {
        case 2:
            outputVector.push_back(paddingChar);
            outputVector.push_back(paddingChar);
            break;
        case 1: case 3:
            outputVector.push_back(paddingChar);
            break;
        default:
            break;
    }
}


int main(int argc, const char * argv[]) {
    
    // declarations:
    string hexInputString;
    vector<char> hexInputVector;
    vector<bool> binaryVector;
    vector<vector<bool>> inputGroupCache;
    int paddingLength;
    
    
    // prompt for user input, do preprocessing
    cout << "Enter a hex number: ";
    cin >> hexInputString;
    transform(hexInputString.begin(), hexInputString.end(), hexInputString.begin(), ::tolower);
    copy(hexInputString.begin(), hexInputString.end(), back_inserter(hexInputVector));
    
    for (int i = 0; i < hexInputVector.size(); i++) {
        if(find(validHexChars.begin(), validHexChars.end(), hexInputVector[i]) != validHexChars.end()) {
            continue;
        } else {
            cout << "invalid input" << endl;
            return 0;
        }
    }
    
    if (hexInputVector[0] == '0' && hexInputVector[1] == 'x') {
        hexInputVector.erase(hexInputVector.begin(), hexInputVector.begin() + 2);
    }
    
    if (hexInputVector.size() % 2 != 0) {
        hexInputVector.insert(hexInputVector.begin(), 0);
    }
    
    // convert hex to binary and concatenate the output
    
    for (char hexCharacter : hexInputVector) {
        int charAsDecimal;
        
        switch (hexCharacter) {
            case 'a':
                charAsDecimal = 10;
                break;
            case 'b':
                charAsDecimal = 11;
                break;
            case 'c':
                charAsDecimal = 12;
                break;
            case 'd':
                charAsDecimal = 13;
                break;
            case 'e':
                charAsDecimal = 14;
                break;
            case 'f':
                charAsDecimal = 15;
                break;
            default:
                charAsDecimal = hexCharacter - '0';
                break;
        }
        
        vector<bool> bitsVector = convertToBinary(charAsDecimal);
        binaryVector.insert(binaryVector.end(), bitsVector.begin(), bitsVector.end());
    }
    
    int quotient = binaryVector.size() / 24;
    int remainder = binaryVector.size() % 24;
    
    // package the binary stream into input groups and add padding
    
    for (int i = 0; i < quotient; i++) {
        vector<bool> inputGroup(24);
        copy(binaryVector.begin(), binaryVector.begin() + 25, inputGroup.begin());
        binaryVector.erase(binaryVector.begin(), binaryVector.begin() + 24);
        inputGroupCache.push_back(inputGroup);
    }
    
    if (remainder > 0) {
        while (binaryVector.size() % 3 != 0) {
            binaryVector.push_back(0);
            binaryVector.push_back(0);
        }
    }
    
    paddingLength = 24 - binaryVector.size();
    inputGroupCache.push_back(binaryVector);
    int totalGroups = inputGroupCache.size();
    
    //encode the input groups
    
    for (int i = 0; i < (totalGroups - 1); i++) {
        encodeGroup(inputGroupCache[0], 4);
        inputGroupCache.erase(inputGroupCache.begin());
    }
    
    encodeGroup(inputGroupCache[0], (binaryVector.size() / 6));

    // print the base64 output
    cout << "base64 output: ";
    for (char bit: outputVector)
        cout << bit;
    cout << endl;
    
    
    return 0;
}
