#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <string>
#include <vector>

/// @brief Classe statica de utilidades de strings
static class stringUtils
{
public:
    ~stringUtils();
    /// @brief Dividir string em sub strings
    /// @param text
    /// @param deliminator
    /// @return Vetor de sub string
    static std::vector<std::string> split(std::string text, char deliminator);
    /// @brief Dividir uma string em duas
    /// @param text
    /// @param deliminator
    /// @return Vetor de sub string
    static std::vector<std::string> splitInTwo(std::string text, char deliminator);
};

#endif