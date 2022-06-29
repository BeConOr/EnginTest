#pragma once
#include "IEngine.hpp"

class EngineIC :
    public IEngine
{
private:
    double heatingVelocity(const double & momentum, const double & velocity);
    double calculateVelocity(const double & momentum, const double & velocity, const double & dt);
    double coolingVelocity(const double & ambitientT, const double & engineT);
    
    EnginConfiguration mConfiguration;

public:
    EngineIC();

    /**
    * @brief Function to start engine.
    * @param dt - time step.
    * @return current engine temerature.
    */
    double startStep(const double & dt) override;

    /**
    * @brief Function to initialize engine.
    */
    void initializeEngine(const EnginConfiguration & configuration) override;
};

