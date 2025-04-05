#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> prefix_function(const std::string& str) {
	std::vector<int> prefix(str.size());
	int k = 0;
	prefix[0] = 0;
	for (int i = 1; i < str.length(); i++) {
		while (k > 0 && str[k] != str[i]) {
			k = prefix[k - 1];
		}
		if (str[k] == str[i]) {
			k++;
		}
		prefix[i] = k;
	}
	return prefix;
}

std::vector<int> find(std::string& text, std::string& str) {
	std::vector<int> shifts;

	if (text.length() < str.length()) {
		return shifts;
	}

	if (!str.length()) {
		return shifts;
	}

	std::unordered_map<char, int> stop_table;
	std::unordered_map<int, int> suffix_table;

	for (int i = 0; i < str.length(); i++) {
		stop_table[str[i]] = i;
	}

	std::string str_reverse(str.rbegin(), str.rend());
	std::vector<int> prefix = prefix_function(str), prefix_reverse = prefix_function(str_reverse);
	for (int i = 0; i < str.length() + 1; i++) {
		suffix_table[i] = str.length() - prefix.back();
	}

	for (int i = 1; i < str.length(); i++) {
		int j = prefix_reverse[i];
		suffix_table[j] = std::min(suffix_table[j], i - prefix_reverse[i] + 1);
	}

	for (int shift = 0; shift <= text.length() - str.length();) {
		int pos = str.length() - 1;

		while (str[pos] == text[pos + shift]) {
			if (pos == 0) {
				shifts.push_back(shift);
				break;
			}
			pos--;
		}

		if (pos == str.length() - 1) {
			std::unordered_map<char, int>::const_iterator stop_symbol = stop_table.find(text[pos + shift]);
			int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);
			shift += stop_symbol_additional;
		}
		else {
			shift += suffix_table[str.length() - pos - 1];
		}
	}

	return shifts;
}

int main(){
	std::string text = "ABABBABABA", str = "ABA";

	std::vector<int> shifts = find(text, str);

	for (int i = 0; i < shifts.size(); i++) {
		std::cout << shifts[i] << " ";
	}

    return 0;
}