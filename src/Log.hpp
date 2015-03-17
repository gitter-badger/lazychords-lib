#ifndef LOG_HPP_INCLUDED
#define LOG_HPP_INCLUDED
#ifdef DEBUG
    #define assert(X) Log::reportError(std::string(#X), std::string(__FILE__), __LINE__); if(!(X)) throw std::runtime_error("assertion failed");
#else
    #define assert(X) ;
#endif
class LogImpl;

class Log
{
    static std::unique_ptr<LogImpl> l;
public :
    Log() = delete;
    static void reportError(const std::string& errorMessage, const std::string& file, unsigned line);
};


#endif // LOG_HPP_INCLUDED