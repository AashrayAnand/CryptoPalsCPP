CXX=g++
STD=-std=c++11
HB=-o HexToB64.exe
FX=-o FixedXor.exe
SBX=-o SingleByteXorCipher.exe
DSC=-o DetectSingleCharXor.exe

detect: DetectSingleCharXor.o SingleByteXorCipher.o
	$(CXX) $(DSC) DetectSingleCharXor.o SingleByteXorCipher.o $(STD)

DetectSingleCharXor.o:
	$(CXX) -c DetectSingleCharXor.cpp $(STD)

SingleByteXorCipher.o:
	$(CXX) -c SingleByteXorCipher.cpp $(STD)

clean:
	rm *.o *.exe
