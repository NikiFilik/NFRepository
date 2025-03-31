#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

std::string intToBinaryString(int n) {
    std::string str;
    while (n > 0) {
        str = std::to_string(n % 2) + str;
        n /= 2;
    }
    return str;
}

int intPower(int base, int exp) {
    int p = 1;
    for (int i = 1; i <= exp; i++) {
        p *= base;
    }
    return p;
}

struct LZWCode {
    std::string str;
    std::string binaryCode;
    int code;
};

int main() {
    const std::string TEXT_FILENAME = "text.txt";
    const int maxBinaryCodeLength = 13;

    std::string text;



    //FILE READING
    std::ifstream in(TEXT_FILENAME);

    while (!in.eof()) {
        std::string str;
        std::getline(in, str);

        text += str + "\n";
    }
    text.pop_back();

    in.close();



    //CREATING SET OF USED CHARACTERS
    std::set<char> charSet;

    for (int i = 0; i < text.size(); i++) {
        charSet.insert(text[i]);
    }



    //START OF CREATING CODE TABLE
    int maxCodeTableMaxSize = intPower(2, maxBinaryCodeLength);

    int currentBinaryCodeLength = 1;
    int currentCodeTableMaxSize = 2;
    while (currentCodeTableMaxSize < charSet.size()) {
        currentBinaryCodeLength++;
        currentCodeTableMaxSize *= 2;
    }

    std::vector<LZWCode> codeTable;
    
    for (char i : charSet) {
        LZWCode newCode;

        newCode.str = i;
        newCode.code = codeTable.size();
        newCode.binaryCode = std::string(currentBinaryCodeLength - intToBinaryString(newCode.code).size(), '0') + intToBinaryString(newCode.code);

        if (codeTable.size() < maxCodeTableMaxSize) {
            codeTable.push_back(newCode);
        }
    }



    //CREATING CODE TABLE FILE
    std::ofstream out("codeTable.txt");

    for (LZWCode i : codeTable) {
        out << "\"" << i.str << "\"" << " " << i.binaryCode << "\n";
    }

    out.close();



    //LZW CODING
    out.open("LZWCode.txt");

    std::string currentStr;
    
    for (int i = 0; i < text.size(); i++) {
        currentStr += text[i];

        bool isPresent = false;
        for (int j = 0; j < codeTable.size(); j++) {
            if (codeTable[j].str == currentStr) {
                isPresent = true;
                break;
            }
        }

        if (codeTable.size() < maxCodeTableMaxSize) {
            if (!isPresent) {
                //OUTPUT TO FILE
                for (int j = 0; j < codeTable.size(); j++) {
                    if (codeTable[j].str == std::string(currentStr, 0, currentStr.size() - 1)) {
                        out << codeTable[j].binaryCode;
                    }
                }
                
                //UPDATING CODE TABLE
                if (codeTable.size() == currentCodeTableMaxSize && currentCodeTableMaxSize < maxCodeTableMaxSize) {
                    currentBinaryCodeLength++;
                    currentCodeTableMaxSize *= 2;
                    for (int j = 0; j < codeTable.size(); j++) {
                        codeTable[j].binaryCode = "0" + codeTable[j].binaryCode;
                    }
                }

                //ADDING NEW CODE
                LZWCode newCode;
                newCode.str = currentStr;
                newCode.code = codeTable.size();
                newCode.binaryCode = std::string(int(currentBinaryCodeLength - intToBinaryString(newCode.code).size()), '0') + intToBinaryString(newCode.code);
                codeTable.push_back(newCode);

                currentStr = currentStr[currentStr.size() - 1];
            }
        }
        else {
            if (isPresent) {
                for (int j = 0; j < codeTable.size(); j++) {
                    if (codeTable[j].str == currentStr) {
                        out << codeTable[j].binaryCode;
                    }
                }

                currentStr.clear();
            }
        }
    }

    //LAST CODE
    for (int j = 0; j < codeTable.size(); j++) {
        if (codeTable[j].str == currentStr) {
            out << codeTable[j].binaryCode;
        }
    }

    out.close();
	return 0;
}
