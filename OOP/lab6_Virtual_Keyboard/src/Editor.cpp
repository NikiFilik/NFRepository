#include "Editor.hpp"

#include <iostream>
#include <fstream>
#include <string>

namespace nf {
    Editor::Editor() : volume(50), mediaPlaying(false) {
        logFile.open("output.txt");
    }

    Editor::~Editor() {
        logFile.close();
    }

    void Editor::printChar(char c) {
        text += c;
        std::cout << c << std::endl;
        logFile << text << std::endl;
    }

    void Editor::deleteLastChar() {
        if (!text.empty()) {
            text.pop_back();
            std::cout << "Undo: " << text << std::endl;
            logFile << text << std::endl;
        }
    }

    void Editor::increaseVolume(int step) {
        volume = std::min(volume + step, 100);
        std::cout << "Volume increased to " << volume << "%" << std::endl;
        logFile << "Volume increased to " << volume << "%" << std::endl;
    }

    void Editor::decreaseVolume(int step) {
        volume = std::max(volume - step, 0);
        std::cout << "Volume decreased to " << volume << "%" << std::endl;
        logFile << "Volume decreased to " << volume << "%" << std::endl;
    }

    void Editor::toggleMediaPlayer() {
        mediaPlaying = !mediaPlaying;
        std::string status = mediaPlaying ? "launched" : "closed";
        std::cout << "Media player " << status << std::endl;
        logFile << "Media player " << status << std::endl;
    }
}