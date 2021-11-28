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

// declare and initialize the base64 lookup table
map<string, char> base64Lookup = {
    {"000000", 'A'}, {"000001", 'B'}, {"000010", 'C'}, {"000011", 'D'}, {"000100", 'E'}, {"000101", 'F'}, {"000110", 'G'}, {"000111", 'H'}, {"001000", 'I'}, {"001001", 'J'}, {"001010", 'K'}, {"001011", 'L'}, {"001100", 'M'}, {"001101", 'N'}, {"001110", 'O'}, {"001111", 'P'}, {"010000", 'Q'}, {"010001", 'R'}, {"010010", 'S'}, {"010011", 'T'}, {"010100", 'U'}, {"010101", 'V'}, {"010110", 'W'}, {"010111", 'X'}, {"011000", 'Y'}, {"011001", 'Z'}, {"011010", 'a'}, {"011011", 'b'}, {"011100", 'c'}, {"011101", 'd'}, {"011110", 'e'}, {"011111", 'f'}, {"100000", 'g'}, {"100001", 'h'}, {"100010", 'i'}, {"100011", 'j'}, {"100100", 'k'}, {"100101", 'l'}, {"100110", 'm'}, {"100111", 'n'}, {"101000", 'o'}, {"101001", 'p'}, {"101010", 'q'}, {"101011", 'r'}, {"101100", 's'}, {"101101", 't'}, {"101110", 'u'}, {"101111", 'v'}, {"110000", 'w'}, {"110001", 'x'}, {"110001", 'x'}, {"110010", 'y'}, {"110011", 'z'}, {"110100", '0'}, {"110101", '1'}, {"110110", '2'}, {"110111", '3'}, {"111000", '4'}, {"111001", '5'}, {"111010", '6'}, {"111011", '7'}, {"111100", '8'}, {"111101", '9'}, {"111110", '+'}, {"111111", '/'},
};

// define the convertToBinary helper function
vector<bool> convertToBinary(int charAsDecimal) { // come back to this function - references may be uneccessary after all
    vector<bool> bits = {0, 0, 0, 0};
    vector<bool> &bitsRef = bits;
    
    int remainder = charAsDecimal;
    int &remainderRef = remainder;
    
    for (int i = 3; i > -1; i--) {
        if (remainderRef - pow(2, i) >= 0) {
            remainderRef -= pow(2, i);
            int index = 3 - i;
            bitsRef[index] = 1;
        }
    }
    return bitsRef;
}

void encodeGroup(vector<bool> inputGroup, int sextets, vector<char> output) {
    // test
    cout << "input group: ";
    for (bool bit: inputGroup)
        cout << bit;
    cout << endl;
    
    cout << "sextets: " << sextets << endl;
    
    for (int i = 0; i < sextets; i++) {
        // declare a string of length 6 (call it sextetString?)
        // for the first 6 elements of the inputGroup:
        // if inputGroup[i] (is true):
        // string[i] = 1
        // else:
        // string[i] = 0
        
        // erase the first 6 elements of the inputGroup
        
        string sextetString = "------"; // why does this need to be initialized?
        
        for (int i = 0; i < 6; i++) {
            if (inputGroup[i]) {
                sextetString[i] = '1';
            } else {
                sextetString[i] = '0';
            }
        }
        cout << "sextet string: " << sextetString << endl;
        
        inputGroup.erase(inputGroup.begin(), inputGroup.begin() + 6);
        
        // use the base64 lookup table to reference the output char
        // append this to the output vector
        output.push_back(base64Lookup[sextetString]);
        
        cout << "output size in function: " << output.size() << endl;
    }
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
    // int - number of input groups (not needed, can derive this 'on the fly'
    // vector of vectors: input group cache - stores input groups (as vectors), ready for encoding
    vector<vector<bool>> inputGroupCache;
    // padding length of the final input group
    int paddingLength;
    // vector - base64 output
    vector<char> outputVector;
    vector<char> &ov = outputVector;
    
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
    
    // binary conversion test
//    for (int i = 0; i < 16; i++) {
//        vector<bool> returnedVector = convertToBinary(i);
//        for (bool bit: returnedVector)
//            cout << bit;
//
//        cout << endl;
//
////        cout << convertToBinary(i) << endl;
//    }
    
    // for each element in the hexInputVector:
    // declare int charAsDecimal;
    // 1. if it's a letter, set charAsDecimal to corresponding number (see the lookup dict above)
    // 2. convert it to binary - use the algorithm from 26/11 (bottom of page) (call a separate function for this?)
    // 3. append that 4-bit chunk to the binary vector as bools
    
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
                charAsDecimal = hexCharacter - '0';
                break;
        }
        
        // call function to convert from hex to binary
        vector<bool> bitsVector = convertToBinary(charAsDecimal);
        
        // append the vector of boolean values (the result of the function call above) to binaryVector;
        binaryVector.insert(binaryVector.end(), bitsVector.begin(), bitsVector.end());
    }
    
    cout << "printing binary vector: " << endl;
    // test display of binaryVector
    for (bool bit: binaryVector)
        cout << bit;
    
    cout << endl;
    
    // find the quotient when we mod the length of the binary vector by 24 (maybe use integer division for this)
    int quotient = binaryVector.size() / 24;
    int remainder = binaryVector.size() % 24;
    cout << "q: " << quotient << endl;
    cout << "r: " << remainder << endl;
    // if the remainder is 0, (number of input groups = q), and thus the length of the inputGroupCache = q (is this needed?)
    // else, (number of input groups = q + 1) - the length of the inputGroupCache = q + 1 (inputGroupCache is a vector, and thus dynamic)
    
    // for 'quotient' times:
    // remove the first 24 elements of the binary vector.
    // store them in a vector called input group
    // add that input group to the input group cache
    
    for (int i = 0; i < quotient; i++) { //quotient + 1??
        // declare a vector to store the slice
        vector<bool> inputGroup(24);
        // slice the first 24 elements of the binaryVector, store them in that vector
        copy(binaryVector.begin(), binaryVector.begin() + 25, inputGroup.begin());

        cout << "input group: " << endl;
        for (bool bit: inputGroup)
            cout << bit;
        cout << endl;
        
        // remove those elements from the binary vector
        binaryVector.erase(binaryVector.begin(), binaryVector.begin() + 24);
        
        // add the inputGroup to the inputGroupCache
        inputGroupCache.push_back(inputGroup);
        
        // test:
        cout << "binary vector: " << endl;
        for (bool bit: binaryVector)
            cout << bit;
        cout << endl;
        
        // test:
        cout << "inputGroupCache length: " << inputGroupCache.size() << endl;
    }
    
    cout << endl;
    
    // if the length of the remaining binary vector is longer than 0: (judge this based on r that we calculated earlier)
    // (so, if r > 0:)
    // while (the binary vector length % 3 != 0):
    // add two 0 elements to the vector.
    
    if (remainder > 0) {
        while (binaryVector.size() % 3 != 0) {
            binaryVector.push_back(0);
            binaryVector.push_back(0);
        }
    }
    
    // test:
    cout << "binary vector as sextets: " << endl;
    for (bool bit: binaryVector)
        cout << bit;
    cout << endl;
    
    // take the difference between 24 and the binary vector length
    // add *this* binary vector to the input group cache (which is a vector of vectors)
    
    paddingLength = 24 - binaryVector.size();
    inputGroupCache.push_back(binaryVector);
    
    // test:
    cout << "inputGroupCache length (2nd): " << inputGroupCache.size() << endl;
    
    // work from here - if the remainder is zero, don't push the binary vector to the inputGroupCache. (wrong - a final dry run is fine) - this is determined from the padding length being 24 and cancelling any encoding operations.
    
    
    // for (the inputGroupCache size - 1):
    // load in the next input group and remove it from the cache
    // call the encodeGroup function, passing it the input group, and the number 4 (as the number of sextets to encode)
    // (passing by value is fine here)
    
    for (int i = 0; i < (inputGroupCache.size() - 1); i++) {
        cout << "encoding" << endl;
        encodeGroup(inputGroupCache[0], 4, ov);
        inputGroupCache.erase(inputGroupCache.begin());
    }
    
    // then:
    // load in the next input group and remove it from the cache
    // derive the number of times to encode sextets from the paddingLength
    // call the encodeGroup function, passing it the input group and the number just calculated (as the number of sextets to encode)
    
    encodeGroup(inputGroupCache[0], (binaryVector.size() / 6), ov);
    
    // test
//    cout << base64Lookup["100010"] << endl;
    
    // test
    cout << "output vector size: " << outputVector.size() << endl;
    
    
    // print the base64 output vector
    cout << "output: ";
    for (char bit: outputVector)
        cout << bit;
    cout << endl;
    
    
    
    return 0;
}
