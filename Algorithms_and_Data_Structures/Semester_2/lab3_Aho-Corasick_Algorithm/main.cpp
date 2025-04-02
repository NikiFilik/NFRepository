#include <iostream>
#include <vector>

const int ALPHABET_SIZE = 256;

struct bohr_vertex {
    int next_vertex[ALPHABET_SIZE], pattern_num;
    bool flag;
    int suffix_link;
    int auto_move[ALPHABET_SIZE], parent;
    char symbol;
    int good_suffix_link;
};

std::vector<bohr_vertex> bohr;
std::vector<std::string> pattern;

bohr_vertex make_bohr_vertex(int parent, char symbol) {
    bohr_vertex vertex;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        vertex.next_vertex[i] = -1;
    }
    vertex.flag = false;
    vertex.suffix_link = -1;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        vertex.auto_move[i] = -1;
    }
    vertex.parent = parent;
    vertex.symbol = symbol;

    vertex.good_suffix_link = -1;

    return vertex;
}

void bohr_ini() {
    bohr.push_back(make_bohr_vertex(0, -1));
}

void add_string_to_bohr(const std::string& str) {
    int num = 0;  
    for (int i = 0; i < str.size(); i++) {
        char symbol = str[i];
        if (bohr[num].next_vertex[symbol] == -1) {
            bohr.push_back(make_bohr_vertex(num, symbol));
            bohr[num].next_vertex[symbol] = bohr.size() - 1;
        }
        num = bohr[num].next_vertex[symbol];
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

int get_auto_move(int vertex, char symbol);

int get_suffix_link(int vertex) {
    if (bohr[vertex].suffix_link == -1) {
        if (vertex == 0 || bohr[vertex].parent == 0) {
            bohr[vertex].suffix_link = 0;
        }
        else {
            bohr[vertex].suffix_link = get_auto_move(get_suffix_link(bohr[vertex].parent), bohr[vertex].symbol);
        }
    }
    return bohr[vertex].suffix_link;
}

int get_auto_move(int vertex, char symbol) {
    if (bohr[vertex].auto_move[symbol] == -1) {
        if (bohr[vertex].next_vertex[symbol] != -1) {
            bohr[vertex].auto_move[symbol] = bohr[vertex].next_vertex[symbol];
        }
        else {
            if (vertex == 0) {
                bohr[vertex].auto_move[symbol] = 0;
            }
            else {
                bohr[vertex].auto_move[symbol] = get_auto_move(get_suffix_link(vertex), symbol);
            }
        }
    }
    return bohr[vertex].auto_move[symbol];
}

int get_good_suffix_link(int vertex) {
    if (bohr[vertex].good_suffix_link == -1) {
        int other_vertex = get_suffix_link(vertex);
        if (other_vertex == 0) {
            bohr[vertex].good_suffix_link = 0;
        }
        else {
            if (bohr[other_vertex].flag) {
                bohr[vertex].good_suffix_link = other_vertex;
            }
            else {
                bohr[vertex].good_suffix_link = get_good_suffix_link(other_vertex);
            }
        }
    }
    return bohr[vertex].good_suffix_link;
}

void check(int vertex, int i) {
    for (int u = vertex; u != 0; u = get_good_suffix_link(u)) {
        if (bohr[u].flag) {
            std::cout << i - pattern[bohr[u].pattern_num].size() << " " << pattern[bohr[u].pattern_num] << "\n";
        }
    }
}

void find_all_pos(const std::string& str) {
    int vertex = 0;
    for (int i = 0; i < str.size(); i++) {
        vertex = get_auto_move(vertex, str[i]);
        check(vertex, i + 1);
    }
}

int main() {
    bohr_ini();

    add_string_to_bohr("abc");
    add_string_to_bohr("bcdc");
    add_string_to_bohr("cccb");
    add_string_to_bohr("bcdd");
    add_string_to_bohr("bbbc");

    find_all_pos("abcdcbcddbbbcccbbbcccbb");
    return 0;
}