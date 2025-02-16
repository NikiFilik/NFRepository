#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

enum class Color { Black, Blue, Green, Cyan, Red, Magenta, Yellow, White, 
	BrightBlack, BrightBlue, BrightGreen, BrightCyan, BrightRed, BrightMagenta, BrightYellow, BrightWhite };

enum class FontSize { Small = 5, Big = 7};

class PseudographicText {
	std::string str;
	char textChar = '#', backgroundChar = ' ';
	int fontSize = static_cast<int>(FontSize::Small);
	Color textColor = Color::BrightWhite;

	static inline const std::string availableChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,!?0123456789";

public:
	PseudographicText() {

	}

	PseudographicText(const std::string& str, char textChar, char backgroundChar, FontSize fontSize, Color textColor) :
		textChar(textChar), backgroundChar(backgroundChar), textColor(textColor) {
		setString(str);
		setFontSize(fontSize);
	}

	void setString(const std::string& str) {
		for (int i = 0; i < str.size(); i++) {
			if (this->availableChars.find(str[i]) == -1) {
				std::cerr << "Error: character '" << str[i] << "' is unavailable\n";
				return;
			}
		}
		this->str = str;
	}

	void setTextChar(char c) {
		this->textChar = c;
	}

	void setBackgroundChar(char c) {
		this->backgroundChar = c;
	}

	void setFontSize(FontSize size) {
		this->fontSize = static_cast<int>(size);
	}

	void setTextColor(Color color) {
		this->textColor = color;
	}

	std::string state() const {
		return "(String: " + this->str + ", TextChar: " + this->textChar + ", BackgroundChar: " + this->backgroundChar + ", FontSize: "
			+ std::to_string(this->fontSize) + ", TextColor: " + std::to_string(static_cast<int>(this->textColor)) + ")";
	}

	void print(int line, int column) const {
		char*** charTable = this->createCharTable();
		char** text = this->createText(charTable);
		this->output(text, line, column);
		this->deleteCharTable(charTable);
		this->deleteText(text);
	}

	static void print(const std::string& str, char textChar, char backgroundChar, FontSize fontSize, Color textColor, int line, int column) {
		PseudographicText text(str, textChar, backgroundChar, fontSize, textColor);
		text.print(line, column);
	}

private:
	char*** createCharTable() const {
		char*** charTable = new char** [this->availableChars.size()];
		for (int i = 0; i < this->availableChars.size(); i++) {
			charTable[i] = new char* [this->fontSize];
			for (int j = 0; j < this->fontSize; j++) {
				charTable[i][j] = new char[this->fontSize];
			}
		}

		std::ifstream in;
		in.open("font_size_" + std::to_string(this->fontSize) + ".txt", std::ios::in);

		for (int j = 0; j < this->fontSize; j++) {
			for (int i = 0; i < this->availableChars.size(); i++) {
				for (int k = 0; k < this->fontSize; k++) {
					in >> charTable[i][j][k];
				}
			}
		}

		in.close();
		return charTable;
	}

	char** createText(char*** charTable) const {
		char** text = new char* [this->fontSize];
		for (int i = 0; i < this->fontSize; i++) {
			text[i] = new char[this->str.size() * this->fontSize];
		}

		for (int i = 0; i < this->str.size(); i++) {
			for (int j = 0; j < this->fontSize; j++) {
				for (int k = 0; k < this->fontSize; k++) {
					text[j][i * this->fontSize + k] = charTable[this->availableChars.find(this->str[i])][j][k];
					if (charTable[this->availableChars.find(this->str[i])][j][k] == '1') {
						text[j][i * this->fontSize + k] = this->textChar;
					}
					else if (charTable[this->availableChars.find(this->str[i])][j][k] == '0') {
						text[j][i * this->fontSize + k] = this->backgroundChar;
					}
				}
			}
		}
		
		return text;
	}

	void output(char** text, int line, int column) const {
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, static_cast<int>(textColor));
		COORD coord;
		coord.X = column;
		coord.Y = line;
		SetConsoleCursorPosition(hConsole, coord);

		for (int i = 0; i < this->fontSize; i++) {
			coord.Y = line + i;
			SetConsoleCursorPosition(hConsole, coord);
			for (int j = 0; j < this->str.size() * this->fontSize; j++) {
				std::cout << text[i][j];
				if ((j + 1) % this->fontSize == 0) {
					std::cout << backgroundChar;
				}
			}
			std::cout << "\n";
		}

		SetConsoleTextAttribute(hConsole, static_cast<int>(Color::Black) * 16 + static_cast<int>(Color::BrightWhite));
	}

	void deleteCharTable(char*** charTable) const {
		for (int i = 0; i < this->availableChars.size(); i++) {
			for (int j = 0; j < this->fontSize; j++) {
				delete[] charTable[i][j];
			}
			delete[] charTable[i];
		}
		delete[] charTable;
	}

	void deleteText(char** text) const {
		for (int i = 0; i < this->fontSize; i++) {
			delete[] text[i];
		}
		delete[] text;
	}
};

int main() {
	PseudographicText text1;
	text1.setString("BETTER!");
	std::cout << text1.state();
	text1.print(3, 3);

	PseudographicText text2("FASTER!", '@', ' ', FontSize::Big, Color::BrightGreen);
	text2.print(10, 10);

	PseudographicText::print("STRONGER!", '$', ' ', FontSize::Big, Color::BrightYellow, 20, 20);
	return 0;
}