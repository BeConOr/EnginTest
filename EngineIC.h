#pragma once
#include "IEngine.hpp"

class EngineIC :
    public IEngine
{
private:
    double heatingVelocity(const double & velocity);
    double calculateVelocity(const double & velocity, const double & dt);
    double coolingVelocity(const double & ambitientT, const double & engineT);
    
    EnginConfiguration mConfiguration;
    double mCurrentVelocity;
    double mAmbitientT;
    double mCurrentEngineT;

public:
    EngineIC(double const & ambitientT);

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

