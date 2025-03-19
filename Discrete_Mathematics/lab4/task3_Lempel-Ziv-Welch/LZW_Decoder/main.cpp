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

    int binaryCodeLength = 1;
    for (int numOfCodes = 2; numOfCodes < codeTable.size(); numOfCodes *= 2) {
        binaryCodeLength++;
    }

    /*for (LZWCode i : codeTable) {
        std::cout << "\"" << i.str << "\"" << " " << i.code << " " << i.binaryCode << std::endl;
    }*/

    //DECODING
    in.open("LZWCode.txt");

    std::string LZWCodeStr;
    std::getline(in, LZWCodeStr);

    in.close();

    std::ofstream out("LZWDecoded.txt");

    std::string currentBinary, currentStr, lastStr;
    bool previousIsPresent = false;
    for (int i = 0; i < LZWCodeStr.size(); i++) {
        std::cout << "---START---" << std::endl;

        currentBinary += LZWCodeStr[i];

        std::cout << "CURRENT BINARY: " << currentBinary << std::endl;
        
        bool isPresent = false;
        for (int j = 0; j < codeTable.size(); j++) {
            if (codeTable[j].binaryCode == currentBinary) {
                currentStr = codeTable[j].str;
                isPresent = true;
                break;
            }
        }

        std::cout << "IS PRESENT: " << isPresent << std::endl;
        std::cout << "IS PREVIOUS PRESENT: " << previousIsPresent << std::endl;

        std::cout << "CURRENT STR: " << "\"" << currentStr << "\"" << std::endl;
        std::cout << "LAST STR: " << "\"" << lastStr << "\"" << std::endl;

        if (!isPresent && previousIsPresent) {
            if (lastStr.size() != 0) {
                LZWCode newCode;

                newCode.str = lastStr + currentStr[0];
                newCode.code = codeTable.size();
                newCode.binaryCode = std::string(std::max(int(binaryCodeLength - intToBinaryString(newCode.code).size()), 0), '0') + intToBinaryString(newCode.code);

                codeTable.push_back(newCode);

                std::cout << "WAS ADDED TO TABLE: " << "\"" << newCode.str << "\"" << " " << newCode.code << " " << newCode.binaryCode << std::endl;
            }
            
            out << currentStr;
            lastStr = currentStr;
            currentBinary = currentBinary[currentBinary.size() - 1];

            std::cout << "WAS PRINTED: " << "\"" << currentStr << "\"" << std::endl;
        }

        previousIsPresent = isPresent;

        std::cout << "---FINISH---" << std::endl;
        std::string trash;
        std::getline(std::cin, trash);
    }

    out.close();

    return 0;
}