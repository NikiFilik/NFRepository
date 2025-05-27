#include "VolumeDownCommand.hpp"

#include "Editor.hpp"
#include <string>
#include "json.hpp"

namespace nf {
    VolumeDownCommand::VolumeDownCommand(nf::Editor& ed, int s) : editor(ed), step(s) {}

    void VolumeDownCommand::execute() {
        editor.decreaseVolume(step);
    }

    void VolumeDownCommand::undo() {
        editor.increaseVolume(step);
    }

    std::string VolumeDownCommand::getType() const {
        return "VolumeDown";
    }

    nlohmann::json VolumeDownCommand::getParams() const {
        return { {"step", step} };
    }
}