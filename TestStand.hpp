#pragma once
#include "IEngine.hpp"
#include <memory>

class TestStand
{
private:
	std::shared_ptr<IEngine> mEngine;
	double mTimeStep;
public:
	TestStand();

	/**
	* @brief Function Function to start engine testing.
	* @return time from beginig to ending. 
	*/
	double startTest();

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
};

