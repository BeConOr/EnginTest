#pragma once
#include "DataInterp.hpp"

/**
* @brief Engine interface.
*/
class IEngine {
public:
    virtual ~IEngine() = default;

    /**
    * @brief Function to start engine.
    * @param dt - time step.
    * @return current engine temerature.
    */
    virtual double startStep(const double & dt) = 0;

    /**
    * @brief Function to initialize engine.
    */
    virtual void initializeEngine(const EnginConfiguration & configuration) = 0;

    /**
    * @brief Function to check if engine is overheated.
    */
    virtual bool isOverHeated() = 0;

    /**
    * @brief Function to get current engine temperature.
    */
    virtual double getCurrentT() = 0;

    /**
    * @brief Function to set ambitient temperature;
    * @param temp - ambitient temperature.
    */
    virtual void setAmbitientT(const double& temp) = 0;
};