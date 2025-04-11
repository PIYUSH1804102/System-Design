#ifndef logger_hpp
#define logger_hpp
#include <string>
#include <mutex>
using namespace std;

class Logger
{
private:
    static int ctr;
    static Logger *loggerInstance;
    static mutex mtx;
    Logger();
    Logger(const Logger &);
    Logger operator=(const Logger &);

public:
    ~Logger();
    static Logger *GetLogger();
    void Log(string msg);
};

#endif
