#pragma once

#include "Command.hpp"
#include <string>
#include "json.hpp"
#include "Editor.hpp"

namespace nf {
    class CommandFactory {
    public:
        static nf::Command* createCommand(const std::string& type, const nlohmann::json& params, nf::Editor& editor);
    };
}