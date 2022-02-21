//
// Created by Danial on 2022/2/21.
//

#include <iostream>

class Trace
{
public:
    Trace(const std::string &name);
    ~Trace();
    void debug(const std::string &msg);
private:
    std::string theFunctionName;
public:
    static bool traceIsActive;
};

inline Trace::Trace(const std::string &name) : theFunctionName(name)
{
    if (traceIsActive) {
        std::cout << "Enter function" << name << std::endl;
    }
}

inline void Trace::debug(const std::string &msg)
{
    if (traceIsActive) {
        std::cout << msg << std::endl;
    }
}

inline Trace::~Trace()
{
    if (traceIsActive) {
        std::cout << "Exit function " << theFunctionName << std::endl;
    }
}

int myFunction(int x)
{
    std::cout << "myFunction x = " << x << '\n';
    std::string name = "myFunction";
    Trace t(name);
    t.traceIsActive = true;

    // ...
    std::string moreInfo = "more interesting info";
    t.debug(moreInfo);
}

int main(int argc, char **argv)
{
    for (int i = 0; i < 10; ++i) {
        myFunction(i);
    }

    return 0;
}