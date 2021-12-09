//
//  main.cpp
//  challenge2
//
//  Created on 08/12/2021.
//

#include <iostream>
#include <vector>

using namespace std;

// helper functions

// function - convertToBinary - takes a string, returns a vector of bools
// string (hex) --> char vector (hex) --> bool vector (binary)

// function - rejectInvalidInput

// function - formatInput

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
    
    cout << "Enter the plaintext in hexadecimal format: ";
    cin >> hexPlainText;
    
    // call rejectInvalidInput
    // call formatInput
    // call convertToBinary, assign it to vector<bool> binPlainTextVector
    
    cout << "Enter the key in hexadecimal format: ";
    cin >> hexKey;
    
    // call rejectInvalidInput
    // call formatInput
    // call convertToBinary, assign it to vector<bool> binKeyVector
    
    // call xor, passing binPlainTextVector and binKeyVector
    // assign the result to binCipherText
    
    // call convertToHex, pass binCipherText
    // assign the result to hexCipherText
    
    // output the vector <char>
    
    
    return 0;
}
