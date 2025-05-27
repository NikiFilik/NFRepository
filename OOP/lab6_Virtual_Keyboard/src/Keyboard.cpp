#include "Keyboard.hpp"

#include <string>
#include "Command.hpp"
#include <stack>
#include "Editor.hpp"
#include "json.hpp"
#include "CommandFactory.hpp"

namespace nf {
    Keyboard::Keyboard(nf::Editor& ed) : editor(ed) {}

    Keyboard::~Keyboard() {
        for (auto& pair : keyCommands) {
            delete pair.second;
        }
    }

    void Keyboard::bindKey(const std::string& keyCombo, nf::Command* cmd) {
        if (keyCommands.find(keyCombo) != keyCommands.end()) {
            delete keyCommands[keyCombo];
        }
        keyCommands[keyCombo] = cmd;
    }

    void Keyboard::pressKey(const std::string& keyCombo) {
        auto it = keyCommands.find(keyCombo);
        if (it != keyCommands.end()) {
            nf::Command* cmd = it->second;
            cmd->execute();
            undoStack.push(cmd);
            while (!redoStack.empty()) {
                redoStack.pop();
            }
        }
    }

    void Keyboard::undo() {
        if (!undoStack.empty()) {
            nf::Command* cmd = undoStack.top();
            cmd->undo();
            undoStack.pop();
            redoStack.push(cmd);
        }
    }

    void Keyboard::redo() {
        if (!redoStack.empty()) {
            nf::Command* cmd = redoStack.top();
            cmd->execute();
            redoStack.pop();
            undoStack.push(cmd);
        }
    }
    
    nlohmann::json Keyboard::getState() const {
        nlohmann::json state;
        for (const auto& pair : keyCommands) {
            const Command* cmd = pair.second;
            nlohmann::json cmdJson;
            cmdJson["type"] = cmd->getType();
            cmdJson["params"] = cmd->getParams();
            state[pair.first] = cmdJson;
        }
        return state;
    }

    void Keyboard::setState(const nlohmann::json& state) {
        for (auto& pair : keyCommands) {
            delete pair.second;
        }
        keyCommands.clear();

        for (auto& el : state.items()) {
            std::string keyCombo = el.key();
            nlohmann::json cmdJson = el.value();
            std::string type = cmdJson["type"];
            nlohmann::json params = cmdJson["params"];
            nf::Command* cmd = nf::CommandFactory::createCommand(type, params, editor);
            if (cmd) {
                keyCommands[keyCombo] = cmd;
            }
        }
    }
}