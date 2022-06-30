#include "ConsoleUI.hpp"

void ConsoleUI::writeInformation(const std::string& inform) const
{
    std::cout << inform;
}

void ConsoleUI::writeInformation(const double & inform) const
{
    std::cout << inform << std::endl;
}

void ConsoleUI::writeErrorInformation(const std::string& inform) const
{
    colorWrapper(inform, 0x0004);
}

void ConsoleUI::writeAccesInformation(const std::string& inform) const
{
    colorWrapper(inform, 0x0002);
}

void ConsoleUI::colorWrapper(const std::string& sentence, const unsigned char& color) const
{
    HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(cout_handle, color);
    std::cout << sentence;
    SetConsoleTextAttribute(cout_handle, 0x0007);
}
