#pragma once

#include "Command.hpp"
#include "Editor.hpp"
#include <string>
#include "json.hpp"

namespace nf {
	class KeyCommand : public nf::Command {
    private:
        nf::Editor& editor;
        char character;

    public:
        KeyCommand(nf::Editor& ed, char c);

        void execute() override;

        void undo() override;

        std::string getType() const override;

        nlohmann::json getParams() const override;
	};
}