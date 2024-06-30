#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <string>
#include <vector>

class stringUtils
{
private:
    /* data */
public:
    stringUtils(/* args */);
    ~stringUtils();
    static std::vector<std::string> split(std::string text,char deliminator);
    static std::vector<std::string> splitInTwo(std::string text,char deliminator);
};

#endif