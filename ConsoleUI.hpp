#pragma once
#include <iostream>

class ConsoleUI
{
};

#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>

namespace systemMessage {
    constexpr auto CONNECTION_ERR = "Connection error.\n";
    constexpr auto SERVER_ERR = "Server error.\n";
    constexpr auto ESTABLISHED = "Connection is established.\n";
    constexpr auto NOT_ESTABLISHED = "Connection is not established.\n";
    constexpr auto SENDING_ERR = "Error of message sending.\n";
    constexpr auto FOUND = "Found messages:\n";
    constexpr auto ACTIVE = "Active users:\n";
    constexpr auto RETURN = "Press any key to return.\n";
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
    * @brief Function to write error information to console.
    * @param inform - information to write.
    */
    void writeErrorInformation(const std::string& inform) const;

    /**
    * @brief Function to write positive information to console.
    * @param inform - information to write.
    */
    void writeAccesInformation(const std::string& inform) const;

    /**
    * @brief Function to write message to console.
    * @param message - message to write.
    */

private:
    void colorWrapper(const std::string& sentence, const unsigned char& color) const;
};

