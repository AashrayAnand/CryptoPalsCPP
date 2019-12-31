#include "HexToB64.h"

int main(){
    // goal: given hexadecimal string, convert to resulting
    // base64 encoded string

    // input hex-encoded string
    std::string hexInput = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

    // expected output b64-encoded string
    std::string b64Expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    // intution: 1 hex character encodes 4 bits, while 1
    // base64 character encodes 6 bits, we can extract 6
    // bits at a time from the hex string (1 hex character
    // plus the 2 LSB of the next hex character) and use
    // these 6 bits to get the resulting base64 character
    std::string resultString = HexToB64(hexInput);
    assert(resultString == b64Expected);
    return 0;
}

std::string HexToB64(std::string HexInput){
    std::string result = "";
    // missingBits is the number of bits needed
    // to complete the current b64 character
    int missingBits = 6;
    // currentChar will be the result of composing
    // 6 bits of the hex string, this value will
    // then be used to index the b64Table string, to
    // determine the next character of the b64 encoded string
    int currentChar = 0;
    for(int i = 0; i < HexInput.length(); i++){
        // get numerical value of hex character
        int charValue = HexInput[i] < 'a' ? HexInput[i] - '0' : HexInput[i] - 'a' + 10;
        // case 1: no bits have been set for the next
        // b64 encoded string, in this case, we use all
        // 4 bits encoded by the current hex character,
        // shifting the bits left twice to act as the 4
        // msb of the current b64 characters 6 bits
        if(missingBits == 6){
            currentChar = charValue << 2;
            missingBits = 2;
        // case 2: 4 most significant bits of current b64
        // character have been set, use the 2 MSB of current
        // hex character as two LSB of current b64 character
        // and add resulting b64 character to result, then use
        // 2 LSB of current hex character as two MSB of 
        // the next b64 character
        } else if(missingBits == 2){
            currentChar += (charValue >> 2) & 3;
            result += b64table[currentChar];
            currentChar = (charValue & 3) << 4;
            missingBits = 4;
        // case 3: 2 most significant bits of current b64
        // character have been set, use all 4 bits of
        // current hex character as 4 LSB of current b64 character
        } else {
            currentChar += charValue;
            result += b64table[currentChar];
            currentChar = 0;
            missingBits = 6;
        }
    }
    return result;
}