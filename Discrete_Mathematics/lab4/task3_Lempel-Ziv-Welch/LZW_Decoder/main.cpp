#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

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

    int binaryCodeLength = codeTable[0].binaryCode.size();
    int codeTableMaxSize = intPower(2, binaryCodeLength);



    //READING CODE
    in.open("LZWCode.txt");

    std::string LZWCodeStr;
    std::getline(in, LZWCodeStr);

    in.close();



    //DECODING
    std::ofstream out("LZWDecoded.txt");

    std::string currentBinary, currentStr, lastStr;
    bool previousIsPresent = false;
    for (int i = 0; i < LZWCodeStr.size(); i += binaryCodeLength) {
        currentBinary = std::string(LZWCodeStr, i, binaryCodeLength);
        /*std::string trash;
        std::getline(std::cin, trash);*/

        bool isPresent = false;
        for (int j = 0; j < codeTable.size(); j++) {
            if (codeTable[j].binaryCode == currentBinary) {
                currentStr = codeTable[j].str;
                isPresent = true;
                break;
            }
        }

        if (codeTable.size() < codeTableMaxSize) {

        }
    }

    out.close();
    
    return 0;
}