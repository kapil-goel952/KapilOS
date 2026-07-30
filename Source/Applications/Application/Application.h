#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

class Application
{
public:

    Application(const std::string& name);

    virtual ~Application() = default;

    virtual void Draw() = 0;

    const std::string& GetName() const;

    bool IsOpen() const;
    void Open();
    void Close();

protected:

    std::string name;
    bool m_open = true;
};

#endif
