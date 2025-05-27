#pragma once

#include "Keyboard.hpp"
#include <string>

namespace nf {
    class KeyboardStateSaver {
    public:
        void save(const nf::Keyboard& keyboard, const std::string& filename);

        void load(nf::Keyboard& keyboard, const std::string& filename);
    };
}