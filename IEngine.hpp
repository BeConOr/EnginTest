#pragma once
#include "DataInterp.hpp"

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
};