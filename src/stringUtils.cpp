#include "stringUtils.hpp"
/// @brief Construtor
stringUtils::stringUtils()
{
}
/// @brief Destrutor
stringUtils::~stringUtils()
{
}
/// @brief Dividir uma string com delimitador final
/// @param text
/// @param deliminator
/// @return Um vetor de todas as strings divididas.
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
/// @brief Separa a string em duas a partir de um delimitador
/// @param text
/// @param deliminator
/// @return O vetor com as string separada
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
