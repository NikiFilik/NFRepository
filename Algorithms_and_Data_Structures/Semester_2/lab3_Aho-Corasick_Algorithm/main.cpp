#include <iostream>
#include <vector>

const int ALPHABET_SIZE = 256;

struct bohr_vertex {
    int next_vertex[ALPHABET_SIZE], pattern_num;
    bool flag;
    int suffix_link;
};

std::vector<bohr_vertex> bohr;
std::vector<std::string> pattern;

bohr_vertex make_bohr_vertex() {
    bohr_vertex vertex;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        vertex.next_vertex[i] = -1;
    }
    vertex.flag = false;
    vertex.suffix_link = -1;

    return vertex;
}

void bohr_ini() {
    bohr.push_back(make_bohr_vertex());
}

void add_string_to_bohr(const std::string& str) {
    int num = 0;  
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (bohr[num].next_vertex[ch] == -1) {
            bohr.push_back(make_bohr_vertex());
            bohr[num].next_vertex[ch] = bohr.size() - 1;
        }
        num = bohr[num].next_vertex[ch];
    }
    bohr[num].flag = true;
    pattern.push_back(str);
    bohr[num].pattern_num = pattern.size() - 1;
}

bool is_string_in_bohr(const std::string& str) {
    int num = 0;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (bohr[num].next_vertex[ch] == -1) {
            return false;
        }
        num = bohr[num].next_vertex[ch];
    }
    return true;
}

int main() {
    bohr_vertex v = make_bohr_vertex();
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        std::cout << v.next_vertex[i];
    }
    return 0;
}