//
// Created by Danial on 2022/2/21.
//

#include <iostream>

class Trace
{
public:
    Trace(const char *name);
    ~Trace();
    void debug(const char *msg);
private:
    std::string theFunctionName;
public:
    static bool traceIsActive;
};

inline Trace::Trace(const char *name) : theFunctionName(name)
{
    if (traceIsActive) {
        std::cout << "Enter function " << name << std::endl;
    }
}

inline void Trace::debug(const char *msg)
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

bool Trace::traceIsActive = false;

int addOne(int x) {
    std::string name = "addOne";
    Trace t(name);

    return (x + 1);
}

int myFunction(int x)
{
    std::cout << "myFunction x = " << x << '\n';
    std::string name = "myFunction";
    Trace t(name);

    // ...
    std::string moreInfo = "more interesting info";
    t.debug(moreInfo);
}

int main(int argc, char **argv)
{
    /*
    for (int i = 0; i < 10; ++i) {
        myFunction(i);
    }
    */

    int count = 1000000;
    std::chrono::high_resolution_clock::time_point timeStart, timeEnd;
    timeStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        addOne(i);
    }
    timeEnd = std::chrono::high_resolution_clock::now();
    std::cout << "addOne time spent " << std::chrono::duration_cast<std::chrono::duration<double>>(timeEnd - timeStart).count() << " seconds" << std::endl;


    return 0;
}