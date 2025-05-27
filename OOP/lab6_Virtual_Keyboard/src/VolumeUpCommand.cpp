#include "VolumeUpCommand.hpp"

#include "Editor.hpp"
#include <string>
#include "json.hpp"

namespace nf {
    VolumeUpCommand::VolumeUpCommand(nf::Editor& ed, int s) : editor(ed), step(s) {}

    void VolumeUpCommand::execute() {
        editor.increaseVolume(step);
    }

    void VolumeUpCommand::undo() {
        editor.decreaseVolume(step);
    }

    std::string VolumeUpCommand::getType() const {
        return "VolumeUp";
    }

    nlohmann::json VolumeUpCommand::getParams() const {
        return { {"step", step} };
    }
}