#ifndef SHELL_H
#define SHELL_H

#include <string>

class Shell
{
public:

    std::string Execute(
        const std::string& command
    );
};

#endif

