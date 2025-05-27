#include "MediaPlayerCommand.hpp"

namespace nf {
    MediaPlayerCommand::MediaPlayerCommand(nf::Editor& ed) : editor(ed) {}

    void MediaPlayerCommand::execute() {
        editor.toggleMediaPlayer();
    }

    void MediaPlayerCommand::undo() {
        editor.toggleMediaPlayer();
    }

    std::string MediaPlayerCommand::getType() const {
        return "MediaPlayer";
    }

    nlohmann::json MediaPlayerCommand::getParams() const {
        return {};
    }
}