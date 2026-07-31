#include "TerminalEngine.h"

#include <cstdio>
#include <array>

std::string TerminalEngine::Execute(
    const std::string& command
)
{
    std::array<char,128> buffer;

    std::string result;

    FILE* pipe =
        popen(command.c_str(),"r");

    if(!pipe)
        return "Failed to execute command.";

    while(
        fgets(
            buffer.data(),
            buffer.size(),
            pipe
        )
    )
    {
        result += buffer.data();
    }

    pclose(pipe);

    return result;
}
