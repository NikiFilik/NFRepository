#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct LZWCode {
    std::string str;
    std::string binaryCode;
    int code;
};

std::string intToBinaryString(int n) {
    std::string str;
    while (n > 0) {
        str = std::to_string(n % 2) + str;
        n /= 2;
    }
    return str;
}

int binaryStringToInt(std::string str){
    int n = 0;
    for (int i = 0; i < str.size(); i++) {
        n = n * 2;
        if (str[i] == '1') {
            n++;
        }
    }
    return n;
}

int intPower(int base, int exp) {
    int p = 1;
    for (int i = 1; i <= exp; i++) {
        p *= base;
    }
    return p;
}

int main() {
    //READING CODE TABLE FILE
    std::ifstream in("codeTable.txt");

    std::vector<LZWCode> codeTable;

    while (!in.eof()) {
        std::string trash;
        LZWCode newCode;

        std::getline(in, trash, '"');
        std::getline(in, newCode.str, '"');
        std::getline(in, trash, ' ');
        std::getline(in, newCode.binaryCode);

        newCode.code = binaryStringToInt(newCode.binaryCode);

        codeTable.push_back(newCode);
    }
    codeTable.pop_back();

    in.close();

    const int maxBinaryCodeLength = 13;
    int maxCodeTableMaxSize = intPower(2, maxBinaryCodeLength);
    int currentBinaryCodeLength = codeTable[0].binaryCode.size();
    int currentCodeTableMaxSize = intPower(2, currentBinaryCodeLength);



    //READING CODE
    in.open("LZWCode.txt");

    std::string LZWCodeStr;
    std::getline(in, LZWCodeStr);

    in.close();



    //DECODING
    std::ofstream out("LZWDecoded.txt");

    std::string currentBinary, currentStr, lastStr;
    for (int i = 0; i < LZWCodeStr.size(); i += currentBinaryCodeLength) {
        currentBinary = std::string(LZWCodeStr, i, currentBinaryCodeLength);

        for (int j = 0; j < codeTable.size(); j++) {
            if (codeTable[j].binaryCode == currentBinary) {
                currentStr = codeTable[j].str;
                out << currentStr;
                
                break;
            }
        }

        if (codeTable.size() < maxCodeTableMaxSize && lastStr.size() != 0) {
            LZWCode newCode;

            newCode.str = lastStr + currentStr[0];
            newCode.code = codeTable.size();
            newCode.binaryCode = std::string(currentBinaryCodeLength - intToBinaryString(newCode.code).size(), '0') + intToBinaryString(newCode.code);

            codeTable.push_back(newCode);
        }

        if (codeTable.size() == currentCodeTableMaxSize && codeTable.size() < maxCodeTableMaxSize) {
            currentBinaryCodeLength++;
            currentCodeTableMaxSize *= 2;
            for (int j = 0; j < codeTable.size(); j++) {
                codeTable[j].binaryCode = "0" + codeTable[j].binaryCode;
            }
            i--;
        }

        lastStr = currentStr;
    }

    out.close();
    
    return 0;
}