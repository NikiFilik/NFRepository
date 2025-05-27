#include "CommandFactory.hpp"

#include "Command.hpp"
#include <string>
#include "json.hpp"
#include "Editor.hpp"

#include "KeyCommand.hpp"
#include "VolumeUpCommand.hpp"
#include "VolumeDownCommand.hpp"
#include "MediaPlayerCommand.hpp"

namespace nf {
    nf::Command* CommandFactory::createCommand(const std::string& type, const nlohmann::json& params, nf::Editor& editor) {
        if (type == "PrintChar") {
            char c = params["char"].get<std::string>()[0];
            return new KeyCommand(editor, c);
        }
        else if (type == "VolumeUp") {
            int step = params.value("step", 10);
            return new nf::VolumeUpCommand(editor, step);
        }
        else if (type == "VolumeDown") {
            int step = params.value("step", 10);
            return new nf::VolumeDownCommand(editor, step);
        }
        else if (type == "MediaPlayer") {
            return new nf::MediaPlayerCommand(editor);
        }
        return nullptr;
    }
}