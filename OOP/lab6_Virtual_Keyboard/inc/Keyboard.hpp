#pragma once

#include <string>
#include "Command.hpp"
#include <stack>
#include "Editor.hpp"
#include "json.hpp"

namespace nf {
    class Keyboard {
    private:
        std::map<std::string, nf::Command*> keyCommands;
        std::stack<nf::Command*> undoStack;
        std::stack<nf::Command*> redoStack;
        nf::Editor& editor;

    public:
        Keyboard(nf::Editor& ed);

        ~Keyboard();

        void bindKey(const std::string& keyCombo, nf::Command* cmd);

        void pressKey(const std::string& keyCombo);

        void undo();
        
        void redo();

        nlohmann::json getState() const;

        void setState(const nlohmann::json& state);
    };
}