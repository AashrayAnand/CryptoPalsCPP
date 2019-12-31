#include "FixedXor.h"

int main(){
    std::string hexIn1 = "1c0111001f010100061a024b53535009181c";
    std::string hexIn2 = "686974207468652062756c6c277320657965";

    std::string expectedOut = "746865206b696420646f6e277420706c6179";

    std::string output = FixedXor(hexIn1, hexIn2);
    assert(output == expectedOut);
}

std::string FixedXor(std::string in1, std::string in2){
    std::string result = "";
    for(int i = 0; i < in1.length(); i++){
        // for characters from each string, get numerical value
        int hexValue1 = in1[i] < 'a' ? in1[i] - '0' : in1[i] - 'a' + 10;
        int hexValue2 = in2[i] < 'a' ? in2[i] - '0' : in2[i] - 'a' + 10;
        // xor the numerical values of the two characters
        int hexXorValue = hexValue1 ^ hexValue2;
        // get the resulting hex character for the numerical xor output
        result += hex[hexXorValue];
    }
    return result;
}