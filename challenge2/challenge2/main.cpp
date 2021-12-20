//
//  main.cpp
//  challenge2
//
//  Created on 08/12/2021.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <boost/dynamic_bitset.hpp>

using namespace std;

// global declarations:

// valid hex characters
vector<char> validHexChars { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

// helper functions

// formats the hexadecimal input
vector<char> formatInput(string hexInput) {
    vector<char> hexInputVector;
    
    transform(hexInput.begin(), hexInput.end(), hexInput.begin(), ::tolower);
    copy(hexInput.begin(), hexInput.end(), back_inserter(hexInputVector));
    
    if (hexInputVector[0] == '0' && hexInputVector[1] == 'x') {
        hexInputVector.erase(hexInputVector.begin(), hexInputVector.begin() + 2);
    }
    
    return hexInputVector;
}

// performs a validation check on the input by checking for invalid characters
bool validate(vector<char> hexInputVector) {
    for (int i = 0; i < hexInputVector.size(); i++) {
        if(find(validHexChars.begin(), validHexChars.end(), hexInputVector[i]) != validHexChars.end()) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

// converts from hexadecimal to binary
vector<bool> convertToBinary(vector<char> hexInputVector) {
    vector<bool> binVector;
    
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
        
        vector<bool> bits = {0, 0, 0, 0};
        int remainder = charAsDecimal;
        
        for (int i = 3; i > -1; i--) {
            if (remainder - pow(2, i) >= 0) {
                remainder -= pow(2, i);
                int index = 3 - i;
                bits[index] = 1;
            }
        }
        
        binVector.insert(binVector.end(), bits.begin(), bits.end());
    }
    return binVector;
}

// applies the bitwise XOR operation to the plaintext and the key
boost::dynamic_bitset<> xorInputs(vector<bool> binPlainTextVector, vector<bool> binKeyVector) {
    boost::dynamic_bitset<> plainTextBitset(binPlainTextVector.size());
    boost::dynamic_bitset<> keyBitset(binKeyVector.size());
    boost::dynamic_bitset<> xoredBitset(binKeyVector.size());

    for (int i = 0; i < binPlainTextVector.size(); i++) {
        if (binPlainTextVector[i]) {
            plainTextBitset[plainTextBitset.size() - i - 1] = 1;
        }
    }
    
    for (int i = 0; i < binKeyVector.size(); i++) {
        if (binKeyVector[i]) {
            keyBitset[keyBitset.size() - i - 1] = 1;
        }
    }
    
    xoredBitset = plainTextBitset ^ keyBitset;
    
    return xoredBitset;
}


// converts from binary to hexadecimal
vector<char> convertToHex(boost::dynamic_bitset<> cipherText) {
    vector<char> hexVector;
    
    int totalHexChars = (int) cipherText.size() / 4;
    vector<int> hexIntegers;
    
    for (int i = 0; i < totalHexChars; i++) {
        vector<bool> bits;
        
        for (int i = 3; i > -1; i--) {
            bool bit = cipherText[i];
            bits.push_back(bit);
        }
        cipherText >>= 4;
        
        int accumulator = 0;
    
    for (int i = 3; i > -1; i--) {
        if (bits[i]) {
            accumulator += pow(2, (3 - i));
            }
        }
        
        hexIntegers.push_back(accumulator);
    }
    
    for (int i = (int)hexIntegers.size() - 1; i > -1; i--) {
        char decimalAsChar;
        
        switch (hexIntegers[i]) {
            case 10:
                decimalAsChar = 'a';
                break;
            case 11:
                decimalAsChar = 'b';
                break;
            case 12:
                decimalAsChar = 'c';
                break;
            case 13:
                decimalAsChar = 'd';
                break;
            case 14:
                decimalAsChar = 'e';
                break;
            case 15:
                decimalAsChar = 'f';
                break;
                // temporarily hardcoding char assignment - see line 133 from challenge 1 for the proper way (refactoring) (could use casting or a map)
            case 0:
                decimalAsChar = '0';
                break;
            case 1:
                decimalAsChar = '1';
                break;
            case 2:
                decimalAsChar = '2';
                break;
            case 3:
                decimalAsChar = '3';
                break;
            case 4:
                decimalAsChar = '4';
                break;
            case 5:
                decimalAsChar = '5';
                break;
            case 6:
                decimalAsChar = '6';
                break;
            case 7:
                decimalAsChar = '7';
                break;
            case 8:
                decimalAsChar = '8';
                break;
            case 9:
                decimalAsChar = '9';
                break;
            default: // (unreachable)
                decimalAsChar = (char)hexIntegers[i];
                break;
        }
        hexVector.push_back(decimalAsChar);
    }
    return hexVector;
}

int main(int argc, const char * argv[]) {
    // declarations
    string hexPlainText;
    vector<char> hexPlainTextVector;
    vector<bool> binPlainTextVector;
    
    string hexKey;
    vector<char> hexKeyVector;
    vector<bool> binKeyVector;
    
    boost::dynamic_bitset<> binCipherText;
    vector<char> hexCipherText;
    
    // prompts for plaintext input, performs formatting, validation and conversion to binary
    cout << "Enter the plaintext in hexadecimal format: ";
    cin >> hexPlainText;
    hexPlainTextVector = formatInput(hexPlainText);
    if (!validate(hexPlainTextVector)) {
        cout << "invalid input" << endl;
        return 0;
    }
    binPlainTextVector = convertToBinary(hexPlainTextVector);
    
    // prompts for plaintext input, performs formatting, validation and conversion to binary
    cout << "Enter the key in hexadecimal format: ";
    cin >> hexKey;
    hexKeyVector = formatInput(hexKey);
    if (!validate(hexKeyVector) || (hexKeyVector.size() != hexPlainTextVector.size())) {
        cout << "invalid input" << endl; // test
        return 0;
    }
    binKeyVector = convertToBinary(hexKeyVector);
    
    // calls xorInputs, which returns the XORed output of the plaintext and the key (the ciphertext)
    binCipherText = xorInputs(binPlainTextVector, binKeyVector);
    
    // converts the ciphertext from binary to hexadecimal
    hexCipherText = convertToHex(binCipherText);
    
    // outputs the ciphertext
    cout << "Ciphertext: ";
    for (char bit: hexCipherText)
        cout << bit;
    cout << endl;
     
    return 0;
}
