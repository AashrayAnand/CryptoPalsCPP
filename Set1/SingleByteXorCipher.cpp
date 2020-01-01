#ifndef IO
#define IO
#include <iostream>
#endif
#ifndef MAP
#define MAP
#include <map>
#endif
#ifndef VEC
#define VEC
#include <vector>
#endif

#ifndef CHARFREQ
#define CHARFREQ
std::map<char, double> charFrequency = {
    {'a', 0.0651738},
    {'b', 0.0124248},
    {'c', 0.0217339}, 
    {'d', 0.0349835}, 
    {'e', 0.1041442}, 
    {'f', 0.0197881}, 
    {'g', 0.0158610},
    {'h', 0.0492888}, 
    {'i', 0.0558094}, 
    {'j', 0.0009033}, 
    {'k', 0.0050529}, 
    {'l', 0.0331490}, 
    {'m', 0.0202124}, 
    {'n', 0.0564513},
    {'o', 0.0596302}, 
    {'p', 0.0137645},
    {'q', 0.0008606}, 
    {'r', 0.0497563}, 
    {'s', 0.0515760}, 
    {'t', 0.0729357}, 
    {'u', 0.0225134},
    {'v', 0.0082903}, 
    {'w', 0.0171272}, 
    {'x', 0.0013692}, 
    {'y', 0.0145984}, 
    {'z', 0.0007836}, 
    {' ', 0.1918182}
};
#endif

#include "SingleByteXorCipher.h"

/*int main(){

    // hex encoded input
    std::string hexEncodedInput = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    // first, want to produce all possible xor-encoded strings
    std::vector<std::string> output = generateStrings(hexEncodedInput);
    std::vector<std::tuple<double, std::string>> stringScoreVector = generateScoreVector(output);
    // sort vector of string/score tuples by character frequency score
    sort(stringScoreVector.begin(), stringScoreVector.end());
    assert(std::get<1>(stringScoreVector.back()) == "Cooking MC's like a pound of bacon");
    return 0;
}*/

// given a string input, generate a tuple string and score, where
// score is the character frequency score of the string
std::tuple<double, std::string> getScore(std::string input){
    double res = 0;
    for(char ch: input){
        if(charFrequency.find(ch) != charFrequency.end()){
            res += charFrequency[ch];
        }
    }
    return std::make_tuple(res, input);
}

// generate a vector of string score tuples, for an input vector of strings
std::vector<std::tuple<double, std::string>> generateScoreVector(std::vector<std::string> input){
    std::vector<std::tuple<double, std::string>> out;
    for(std::string in: input){
        out.push_back(getScore(in));
    }
    return out;
}

// convert a hex string to byte array
std::vector<char> HexToBytes(std::string hexIn){
    std::vector<char> res;
    for(int i = 0; i < hexIn.length() - 1; i+=2){
        std::string hexByte = hexIn.substr(i, 2);
        // interpret string as base 16 (hex), convert to byte 
        char byte = (char) strtol(hexByte.c_str(), NULL, 16);
        res.push_back(byte);
    }
    return res;
}

std::string BytesToHex(std::vector<char> bytesIn){
    std::string result = "";
    for(char ch : bytesIn){
        result += ch;
    }
    return result;
}

std::string SingleByteXor(std::string input, const char key){
    std::vector<char> hexByteIn = HexToBytes(input);
    for(int i = 0; i < hexByteIn.size(); i++){
        hexByteIn[i] = hexByteIn[i] ^ key;
    }
    std::string xorString = BytesToHex(hexByteIn);
    return xorString;
}

std::vector<std::string> generateStrings(std::string input){
    std::vector<std::string> result;
    // apply xor for every possible byte value (0 -> 255)
    for(int i = 0; i < 256; i++){
        result.push_back(SingleByteXor(input, i));
    }
    return result;
}