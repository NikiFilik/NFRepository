#pragma once

#include "Command.hpp"
#include "Editor.hpp"
#include <string>
#include "json.hpp"

namespace nf {
    class VolumeDownCommand : public nf::Command {
    private:
        nf::Editor& editor;
        int step;

    public:
        VolumeDownCommand(nf::Editor& ed, int s);

        void execute() override;

        void undo() override;

        std::string getType() const override;

        nlohmann::json getParams() const override;
    };
}