#include <iostream>
#include <string>
#include <vector>

const int x = 31, q = 1000003;

int power(int base, int exp) {
    int p = 1;
    for (int i = 1; i <= exp; i++) {
        p = (p * base) % q;
    }
    return p;
}

int polynomialHash(std::string& str) {
    int hash = 0;
    for (int i = 0; i < str.size(); i++) {
        hash = (hash * x + str[i]) % q;
    }
    return hash;
}

std::vector<int>* Rabin_Karp_Algorithm(std::string& needle, std::string& haystack) {
    std::vector<int>* entries = new std::vector<int>;
    
    int needleHash = polynomialHash(needle);
    int currentHash = polynomialHash(std::string(haystack, 0, needle.size()));
    
    if (needleHash == currentHash) {
        bool flag = true;
        for (int i = 0; i < needle.size(); i++) {
            if (needle[i] != haystack[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            entries->push_back(0);
            
        }
    }

    for (int i = 1; i <= haystack.size() - needle.size(); i++) {
        currentHash = (currentHash * x - haystack[i - 1] * power(x, needle.size()) + haystack[i + needle.size() - 1]) % q;

        if (needleHash == currentHash) {
            bool flag = true;
            for (int j = 0; j < needle.size(); j++) {
                if (needle[j] != haystack[i + j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                entries->push_back(i);
            }
        }
    }

    return entries;
}

int main(){
    std::string needle = "ABA", haystack = "ABABBABABA";

    //std::cin >> haystack >> needle;

    std::vector<int>* entries = Rabin_Karp_Algorithm(needle, haystack);

    for (int i: *entries) {
        std::cout << i << " ";
    }

    delete entries;
    return 0;
}