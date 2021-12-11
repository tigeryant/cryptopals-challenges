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

// function - validate - takes a string (hexInput) and returns a bool.
// TODO start writing this function definition

// function - formatInput - takes a string (hexInput) and returns a vector of chars

// function - convertToBinary - takes a vector of chars, returns a vector of bools

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
    
    // call validate, passing it the hexPlainText string. It will return a bool
    // if the bool returned is false, terminate execution by returning 0
    
    // call formatInput, passing it a string hexPainText and returning a vector of chars
    // call convertToBinary, passing it a vector of chars and returning a vector of bools
    
    // from the call to convertToBinary, assign the returned vector<bool> binPlainTextVector
    
    
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
