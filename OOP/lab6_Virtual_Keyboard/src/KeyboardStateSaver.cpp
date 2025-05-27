#include "KeyboardStateSaver.hpp"

#include "Keyboard.hpp"
#include <string>
#include "json.hpp"
#include <fstream>

namespace nf {
    void KeyboardStateSaver::save(const nf::Keyboard& keyboard, const std::string& filename) {
        nlohmann::json state = keyboard.getState();
        std::ofstream file(filename);
        if (file.is_open()) {
            file << state.dump(4);
            file.close();
        }
    }

    void KeyboardStateSaver::load(nf::Keyboard& keyboard, const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            nlohmann::json state;
            file >> state;
            keyboard.setState(state);
            file.close();
        }
    }
}