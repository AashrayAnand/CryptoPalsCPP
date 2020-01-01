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

#ifndef TUPLE
#define TUPLE
#include <tuple>
#endif

#ifndef FS
#define FS
#include <fstream>
#endif

#include "SingleByteXorCipher.h"
#include "DetectSingleCharXor.h"

int main(){
    std::ifstream file;
    file.open("data4.txt");

    std::vector<std::tuple<double, std::string>> aggregator;
    std::string line;
    while(std::getline(file, line)){
        std::vector<std::string> xorStrings = generateStrings(line);
        std::vector<std::tuple<double, std::string>> xorStringScores = generateScoreVector(xorStrings);
        for(auto stringAndScore: xorStringScores){
            aggregator.push_back(stringAndScore);
        }
    }
    sort(aggregator.begin(), aggregator.end());
    std::cout << std::get<1>(aggregator.back()) << std::endl;
    assert(std::get<1>(aggregator.back()) == "Now that the party is jumping\n");
    return 0;
}