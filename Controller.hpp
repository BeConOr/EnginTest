#pragma once
#include "IEngine.hpp"
#include "EngineIC.hpp"
#include "TestStand.hpp"
#include <memory>
#include <iostream>
#include "ConsoleUI.hpp"

/**
* @brief Class to connect UI and Testing system.
*/
class Controller
{
private:
	TestStand mStand;
	std::shared_ptr<IEngine> mEngine;
	ConsoleUI mLogger;

public:
	Controller();

	/**
	* @brief Function to run application.
	*/
	void run();
};

