#include <iostream>
#include <string>
#include <set>

int* prefixFunction(std::string& str) {
    int* prefixLen = new int[str.size()]();
    for (int i = 1; i < str.size(); i++) {
        int k = prefixLen[i - 1];
        while (k > 0 && str[k] != str[i]) {
            k = prefixLen[k - 1];
        }
        if (str[k] == str[i]) {
            k++;
        }
        prefixLen[i] = k;
    }
    return prefixLen;
}

std::set<int>* KMP_Algorithm(std::string& needle, std::string& haystack) {
    int k = 0;
    std::set<int>* entries = new std::set<int>;
    int* prefixLen = prefixFunction(needle);
    for (int i = 0; i < haystack.size(); i++) {
        while (k > 0 && needle[k] != haystack[i]) {
            k = prefixLen[k - 1];
        }
        if (haystack[i] == needle[k]) {
            k++;
        }
        if (k == needle.size()) {
            entries->insert(i - needle.size() + 1);
            k = prefixLen[k - 1];
        }
    }
    delete[] prefixLen;
    return entries;
}

int main(){
    std::string needle = "ABA", haystack = "ABABBABABA";
    //std::cin >> haystack >> needle;
    std::set<int>* entries = KMP_Algorithm(needle, haystack);
    for (int i: *entries) {
        std::cout << i << " ";
    }
    delete entries;
    return 0;
}