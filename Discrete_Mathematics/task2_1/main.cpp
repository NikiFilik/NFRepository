#include <iostream>
#include <string>
#include <set>

int main() {
	std::string word = "KOMBINATORIKA";
	std::set<std::string> megaset;

	for (int i = 0; i < word.size(); i++) {
		for (int j = i + 1; j < word.size(); j++) {
			for (int k = j + 1; k < word.size(); k++) {
				for (int q = k + 1; q < word.size(); q++) {
					std::string subword;
					subword += word[i];
					subword += word[j];
					subword += word[k];
					subword += word[q];

					megaset.insert(std::move(subword));
				}
			}
		}
	}

	std::cout << "OTBET: " << megaset.size();
	return 0;
}