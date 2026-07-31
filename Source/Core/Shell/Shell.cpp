#include "Shell.h"

#include <cstdio>
#include <array>

std::string Shell::Execute(
    const std::string& command
)
{
    std::array<char,128> buffer;

    std::string result;

    FILE* pipe =
    popen(
        command.c_str(),
        "r"
    );

    if(pipe == nullptr)
    {
        return "Failed to execute command.";
    }

    while(
        fgets(
            buffer.data(),
            buffer.size(),
            pipe
        ) != nullptr
    )
    {
        result += buffer.data();
    }

    pclose(pipe);

    return result;
}
