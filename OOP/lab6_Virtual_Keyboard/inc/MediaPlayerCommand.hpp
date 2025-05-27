#pragma once

#include "Command.hpp"
#include "Editor.hpp"
#include "json.hpp"
#include <string>

namespace nf {
    class MediaPlayerCommand : public nf::Command {
    private:
        nf::Editor& editor;

    public:
        MediaPlayerCommand(nf::Editor& ed);

        void execute() override;

        void undo() override;

        std::string getType() const override;

        nlohmann::json getParams() const override;
    };
}