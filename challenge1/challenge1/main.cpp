//
//  main.cpp
//  challenge1
//
//  Created by John Davies on 23/11/2021.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// define the convertToBinary helper function
vector<bool> convertToBinary(int charAsDecimal) {
    vector<bool> bitsVector = {0, 0, 0, 0};
    int remainder = charAsDecimal;
    
    for (int i = 3; i == 0; i--) {
        if (remainder - (pow(2, i))) {
            remainder -= pow(2, i);
            int index = 3 - i;
            bitsVector[index] = 1;
        }
    }
    return bitsVector;
}


int main(int argc, const char * argv[]) {
    // list of declarations:
    // string - hexInputString
    string hexInputString;
    // vector of ints - hexInputVector
    vector<char> hexInputVector;
    // vector of strings for storing...
    
    // dictionary lookup (or switch statement?) for converting hex letters to decimal numbers
    // binary vector (int or bool? bool might save memory) - stores the input in binary form after its been converted from hex
    vector<bool> binaryVector;
    // int - number of input groups
    // vector of vectors: input group cache - stores input groups (as vectors), ready for encoding
    // vector - base64 output
    
    // prompt for user input, get hex as string
    cout << "Enter a hex number: ";
    cin >> hexInputString;
    
    // processing: convert string to lower case
    transform(hexInputString.begin(), hexInputString.end(), hexInputString.begin(), ::tolower);
    
    // store each character as an element of a vector
    copy(hexInputString.begin(), hexInputString.end(), back_inserter(hexInputVector));
    
    // if the first two elements are 0 and x, discard them
    if (hexInputVector[0] == '0' && hexInputVector[1] == 'x') {
        cout << "0 and x present - erasing" << "\n";
        hexInputVector.erase(hexInputVector.begin(), hexInputVector.begin() + 2);
    }
    
    cout << hexInputVector[0] << hexInputVector[1] << "\n"; // test
    
    // for each element in the hexInputVector:
    // declare int charAsDecimal;
    // 1. if it's a letter, set charAsDecimal to corresponding number (see the lookup dict above)
    // 2. convert it to binary - use the algorithm from 26/11 (bottom of page) (call a separate function for this?)
    // 3. append that 4-bit chunk to the binary vector (as ints or bools?)
    
    // map each element to its decimal equivalent
    
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
                // convert hexCharacter from char to int and define the result as charAsDecimal
                // charAsDecimal =
                break;
        }
        
        // call convert to binary function here
        convertToBinary(charAsDecimal);
        // append the vector of boolean values (the result of the function call above) to binaryVector;
    }
    
    // find the quotient when we mod the length of the binary vector by 24 (maybe use integer division for this)
    // if the remainder is 0, (number of input groups = q), and thus the length of the inputGroupCache = q
    // else, (number of input groups = q + 1) - the length of the inputGroupCache = q + 1
    
    // for 'quotient' times:
    // remove the first 24 elements of the binary vector.
    // store them in a vector called input group
    // add that input group to the input group cache
    
    // if the length of the remaining binary vector is longer than 0: (judge this based on r that we calculated earlier)
    // (so, if r > 0:)
    // while (the binary vector length % 3 != 0):
    // add two 0 elements to the vector.
    
    // take the difference between 24 and the binary vector length
    // append that many '=' signs to the vector
    // add *this* binary vector to the input group cache (which is a vector of vectors)
    
    // for each input group in the input group cache:
    // for 4 times:
    // store remove the first 6 elements of the input group vector and store them in a 'sextet' input group
    // use the sextet to base64 lookup table to reference to reference its base64 character value.
    // append each of these to the base64 output vector
    
    // use a join method (or similar) to convert this array into a string.
    // output this string to the console
    
    
    
    return 0;
}
