#ifndef TERMINAL_ENGINE_H
#define TERMINAL_ENGINE_H

#include <string>

class TerminalEngine
{
public:

    std::string Execute(
        const std::string& command
    );
};

#endif
