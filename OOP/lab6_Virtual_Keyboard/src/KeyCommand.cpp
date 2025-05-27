#include "KeyCommand.hpp"

#include "Editor.hpp"
#include "json.hpp"
#include <string>

namespace nf {
    KeyCommand::KeyCommand(nf::Editor& editor, char c) : editor(editor), character(c) {}

    void KeyCommand::execute() {
        editor.printChar(character);
    }

    void KeyCommand::undo() {
        editor.deleteLastChar();
    }

    std::string KeyCommand::getType() const {
        return "PrintChar";
    }

    nlohmann::json KeyCommand::getParams() const {
        return { {"char", std::string(1, character)} };
    }
}