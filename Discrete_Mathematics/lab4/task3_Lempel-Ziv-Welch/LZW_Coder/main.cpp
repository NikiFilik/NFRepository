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

struct LZWCode {
    std::string str;
    std::string binaryCode;
    int code;
};

int main() {
    //FILE READING
    const std::string TEXT_FILENAME = "text.txt";

    std::string text;

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

    int binaryCodeLength = 1;
    for (int numOfCodes = 2; numOfCodes < charSet.size(); numOfCodes *= 2) {
        binaryCodeLength++;
    }



    //START OF CREATING CODE TABLE
    std::vector<LZWCode> codeTable;
    
    for (char i : charSet) {
        LZWCode newCode;

        newCode.str = i;
        newCode.code = codeTable.size();
        newCode.binaryCode = std::string(binaryCodeLength - intToBinaryString(newCode.code).size(), '0') + intToBinaryString(codeTable.size());

        codeTable.push_back(newCode);
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

        //std::cout << "---START---" << std::endl;
        //std::cout << "CURRENT STR: " << currentStr << std::endl;

        bool isPresent = false;
        for (int j = 0; j < codeTable.size(); j++) {
            if (codeTable[j].str == currentStr) {
                isPresent = true;
                break;
            }
        }

        if (!isPresent) {
            //ADDING NEW CODE
            LZWCode newCode;

            newCode.str = currentStr;
            newCode.code = codeTable.size();
            newCode.binaryCode = std::string(std::max(int(binaryCodeLength - intToBinaryString(newCode.code).size()), 0), '0') + intToBinaryString(codeTable.size());

            codeTable.push_back(newCode);

            //OUTPUT TO FILE
            for (int j = 0; j < codeTable.size(); j++) {
                if (codeTable[j].str == std::string(currentStr, 0, currentStr.size() - 1)) {
                    //std::cout << "THIS WAS OUTPUTED AS BINARY: " << std::string(currentStr, 0, currentStr.size() - 1) << std::endl;
                    
                    out << codeTable[j].binaryCode;
                }
            }

            currentStr = currentStr[currentStr.size() - 1];
        }
        //std::cout << "---FINISH---" << std::endl;
        //std::string trash;
        //std::getline(std::cin, trash);
    }
    //LAST CODE
    bool isPresent = false;
    for (int i = 0; i < codeTable.size(); i++) {
        if (codeTable[i].str == currentStr) {
            isPresent = true;
            break;
        }
    }

    if (!isPresent) {
        //ADDING NEW CODE
        LZWCode newCode;

        newCode.str = currentStr;
        newCode.code = codeTable.size();
        newCode.binaryCode = std::string(std::max(int(binaryCodeLength - intToBinaryString(newCode.code).size()), 0), '0') + intToBinaryString(codeTable.size());

        codeTable.push_back(newCode);

        //OUTPUT TO FILE
        for (int i = 0; i < codeTable.size(); i++) {
            if (codeTable[i].str == std::string(currentStr, currentStr.size() - 1)) {
                out << codeTable[i].binaryCode;
            }
        }

        currentStr = currentStr[currentStr.size() - 1];

        for (int i = 0; i < codeTable.size(); i++) {
            if (codeTable[i].str == currentStr) {
                out << codeTable[i].binaryCode;
            }
        }
    }
    else {
        for (int i = 0; i < codeTable.size(); i++) {
            if (codeTable[i].str == currentStr) {
                out << codeTable[i].binaryCode;
            }
        }
    }

    out.close();
	return 0;
}