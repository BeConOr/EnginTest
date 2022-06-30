#pragma once
#include <iostream>

#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>

namespace systemMessage {
    constexpr auto TEMP_REQ = "Input ambitient temperature: ";
    constexpr auto OVERHEATED = "Engine was overheated.\n";
    constexpr auto OVERHEATED_TIME = "Time to overheating: ";
    constexpr auto START_NOTION = "Test was started\n";
    constexpr auto PLATO_WARN = "Engine temperature is on plato.\n";
    constexpr auto PLATO_TEMP = "Plato temperature: ";
} //systemMessage

/**
* @brief Class to log a system information about app working condition to console.
*/
class ConsoleUI {
public:
    /**
    * @brief Function to write system information to console.
    * @param inform - information to write.
    */
    void writeInformation(const std::string& inform) const;

    /**
    * @brief Function to write system information to console.
    * @param inform - information to write.
    */
    void writeInformation(const double & inform) const;

    /**
    * @brief Function to write error information to console.
    * @param inform - information to write.
    */
    void writeErrorInformation(const std::string& inform) const;

    /**
    * @brief Function to write positive information to console.
    * @param inform - information to write.
    */
    void writeAccesInformation(const std::string& inform) const;

private:
    void colorWrapper(const std::string& sentence, const unsigned char& color) const;
};

