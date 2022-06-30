#pragma once
#include "IEngine.hpp"
#include "EngineIC.hpp"
#include "TestStand.hpp"
#include <memory>
#include <iostream>

class Controller
{
private:
	TestStand mStand;
	std::shared_ptr<IEngine> mEngine;

public:
	Controller();

	/**
	* @brief Function to run application.
	*/
	void run();
};

