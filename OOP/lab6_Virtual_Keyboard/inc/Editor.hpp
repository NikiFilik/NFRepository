#pragma once

#include <fstream>
#include <string>

namespace nf {
    class Editor {
    public:
        std::string text;
        int volume;
        bool mediaPlaying;
        std::ofstream logFile;

        Editor();

        ~Editor();

        void printChar(char c);
        void deleteLastChar();

        void increaseVolume(int step = 10);
        void decreaseVolume(int step = 10);

        void toggleMediaPlayer();
    };
}