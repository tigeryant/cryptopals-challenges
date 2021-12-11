//
//  main.cpp
//  challenge2
//
//  Created on 08/12/2021.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// global declarations:

// valid hex characters
vector<char> validHexChars { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

// helper functions

// function - formatInput - takes a string (hexInput) and returns a vector of chars
vector<char> formatInput(string hexInput) {
    vector<char> hexInputVector;
    
    transform(hexInput.begin(), hexInput.end(), hexInput.begin(), ::tolower);
    copy(hexInput.begin(), hexInput.end(), back_inserter(hexInputVector));
    
    if (hexInputVector[0] == '0' && hexInputVector[1] == 'x') {
        hexInputVector.erase(hexInputVector.begin(), hexInputVector.begin() + 2);
    }
    
    return hexInputVector;
}

// function - validate - takes a char vector (hexInputVector) and returns a bool
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

// function - convertToBinary - takes a vector of chars, returns a vector of bools
vector<bool> convertToBinary(vector<char> hexInputVector) {
    vector<bool> binVector;
    
    // for each element of the input vector, convert it to its decimal equivalent
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
        
        // then convert that decimal to its binary equivalent (4 bits)
        // add those bits to a binary vector
        // return the binary vector
        
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

// function - xor
// takes two arguments of type vector <bool>
// xors them and returns a vector <bool>

// function - convertToHex
// takes a vector <bool>, converts it to hex and returns a vector <char>

int main(int argc, const char * argv[]) {
    // Handle invalid input and format the input strings correctly
    // Convert both input strings (plaintext and key) to binary.
    // Use the XOR bitwise operation to find the output (ciphertext). The bitwise operator can be applied to the entire string (no need to XOR one bit at a time).
    // Convert the binary output into hex.
    // Output this to std out.
    
    // declarations
    string hexPlainText;
    vector<char> hexPlainTextVector; // maybe this could be declared locally within convertToBinary (use a generic hexInputVector for any input)
    vector<bool> binPlainTextVector;
    
    
    string hexKey;
    vector<bool> binKeyVector;
    
    vector<bool> binCipherText;
    vector<char> hexCipherText;
    
    // string (hex) --> char vector (hex) --> bool vector (binary)
    
    cout << "Enter the plaintext in hexadecimal format: ";
    cin >> hexPlainText;
    
    // call formatInput, passing it a char vector hexPainTextVector and returning a vector of chars
    hexPlainTextVector = formatInput(hexPlainText);
    
    // call validate, passing it the hexPlainText char vector. It will return a bool
    // if the bool returned is false, terminate execution by returning 0
    if (!validate(hexPlainTextVector)) {
        cout << "invalid input" << endl; // test
        return 0;
    } else { // test
        cout << "valid input" << endl;
    }
    
    // call convertToBinary, passing it a vector of chars and assigning it to vector<bool> binPlainTextVector
    binPlainTextVector = convertToBinary(hexPlainTextVector);
    
    // test
    cout << "binary output: ";
    for (bool bit: binPlainTextVector)
        cout << bit;
    cout << endl;
    
    
    return 0; // test
    
    cout << "Enter the key in hexadecimal format: ";
    cin >> hexKey;
    
    // call validate, passing it the hexKey. It will return a bool.
    // if the bool returned is false, terminate execution by returning 0
    
    // call formatInput, passing it a string hexPainText and returning a vector of chars
    // call convertToBinary, passing it a vector of chars and returning a vector of bools
    
    // from the call to convertToBinary, assign the returned vector<bool> binKeyVector
    
    
    
    // call xor, passing binPlainTextVector and binKeyVector
    // assign the result to binCipherText
    
    // call convertToHex, pass binCipherText
    // assign the result to hexCipherText
    
    // output the vector <char>
    
    
    return 0;
}
