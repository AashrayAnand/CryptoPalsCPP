#include "RepeatingKeyXor.h"

int main(){
    std::string sentenceIn = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    std::string hexExpected = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
    std::string key = "ICE";
    RepeatingKeyXor(sentenceIn, key);
    std::stringstream ss;
    // fill digits in hex bytes with 0 char
    ss << std::hex << std::setfill('0');
    for(unsigned char ch: sentenceIn){
        // set width of each value sent to string stream to
        // be 2 hex bits, will result in single bit hex values
        // being prepended with a trailing '0' char
        ss << std::setw(2) << static_cast<unsigned int>(ch);
    }
    assert(ss.str() == hexExpected);
    return 0;
}

void RepeatingKeyXor(std::string &input, std::string key){
    for(int i = 0; i < input.length(); i++){
        input[i] ^= key[i % key.length()];
    }
}