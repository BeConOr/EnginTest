#pragma once
#include "IEngine.hpp"
#include <memory>
constexpr auto PRECIS = 0.00000001;

/**
* @brief Class to test engines.
*/
class TestStand
{
private:
	std::shared_ptr<IEngine> mEngine;
	double mTimeStep;
	double mTime;

public:
	TestStand();

	/**
	* @brief Function Function to start engine testing.
	* @return condition of test ending.
	* 0 - engine was overheated. 1 - engine temperature is on plato.
	*/
	int startTest();

	/**
	* @brief Fucntion to change time step.
	* @param timeStep - new time step.
	*/
	void changeTimeStep(const double & timeStep);

	/**
	* @brief Function to set new engine.
	* @param engine - new engine to set for testing.
	*/
	void setNewEngine(const std::shared_ptr<IEngine> & engine);

	/**
	* @brief Function to get current calculation time.
	*/
	double getCurrentTIme();
};

