#pragma once

#include <string>
#include "json.hpp"

namespace nf {
	class Command {
    public:
        virtual ~Command() = default;

        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual std::string getType() const = 0;
        virtual nlohmann::json getParams() const = 0;
	};
}