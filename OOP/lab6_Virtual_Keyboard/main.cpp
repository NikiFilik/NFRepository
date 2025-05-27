#include <iostream>

#include "Editor.hpp"
#include "Keyboard.hpp"
#include "KeyboardStateSaver.hpp"

#include "KeyCommand.hpp"
#include "VolumeUpCommand.hpp"
#include "VolumeDownCommand.hpp"
#include "MediaPlayerCommand.hpp"

int main() {
    nf::Editor editor;
    nf::Keyboard keyboard(editor);
    nf::KeyboardStateSaver saver;

    saver.load(keyboard, "keyboardState.json");

    if (keyboard.getState().empty()) {
        keyboard.bindKey("a", new nf::KeyCommand(editor, 'a'));
        keyboard.bindKey("b", new nf::KeyCommand(editor, 'b'));
        keyboard.bindKey("c", new nf::KeyCommand(editor, 'c'));
        keyboard.bindKey("d", new nf::KeyCommand(editor, 'd'));
        keyboard.bindKey("e", new nf::KeyCommand(editor, 'e'));
        keyboard.bindKey("ctrl++", new nf::VolumeUpCommand(editor, 20));
        keyboard.bindKey("ctrl+-", new nf::VolumeDownCommand(editor, 20));
        keyboard.bindKey("ctrl+p", new nf::MediaPlayerCommand(editor));
    }

    keyboard.bindKey("ctrl+alt+p", new nf::MediaPlayerCommand(editor));

    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            saver.save(keyboard, "keyboardState.json");
            break;
        }
        else if (input == "undo") {
            keyboard.undo();
        }
        else if (input == "redo") {
            keyboard.redo();
        }
        else {
            keyboard.pressKey(input);
        }
    }

    return 0;
}