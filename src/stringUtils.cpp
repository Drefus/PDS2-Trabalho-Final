#include "stringUtils.hpp"

stringUtils::stringUtils()
{
}

stringUtils::~stringUtils()
{
}
/// @brief Split a string with end deliminator
/// @param text
/// @param deliminator
/// @return A vector of all split strings.
std::vector<std::string> stringUtils::split(std::string text, char deliminator)
{
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;

    while ((pos = text.find(deliminator)) != std::string::npos)
    {
        token = text.substr(0, pos);
        tokens.push_back(token);
        text.erase(0, pos + 1);
    }

    return tokens;
}

std::vector<std::string> stringUtils::splitInTwo(std::string text, char deliminator)
{
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;

    pos = text.find(deliminator);
    token = text.substr(0, pos);
    tokens.push_back(token);
    text.erase(0, pos + 1);
    tokens.push_back(text);

    return tokens;
}
