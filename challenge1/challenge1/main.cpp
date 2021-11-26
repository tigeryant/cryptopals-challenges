//
//  main.cpp
//  challenge1
//
//  Created by John Davies on 23/11/2021.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // list of declarations:
    // string - hexInputString
    // vector of ints - hexInputVector
    // dictionary lookup (or switch statement?) for converting hex letters to decimal numbers
    // binary vector (int or bool? bool might save memory) - stores the input in binary form after its been converted from hex
    // int - number of input groups
    // vector of vectors: input group cache - stores input groups (as vectors), ready for encoding
    // vector - base64 output
    
    // input the hex as a string
    
    // split the string up, storing each character as an element of a vector
    
    // if the first two elements are 0 and x, discard them
    
    // for each element in the hexInputVector:
    // 1. if it's a letter, change it to its corresponding number (see the lookup dict above)
    // 2. convert it to binary - use the algorithm from 26/11 (bottom of page)
    // 3. append that 4-bit chunk to the binary vector (as ints or bools?)
    
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
