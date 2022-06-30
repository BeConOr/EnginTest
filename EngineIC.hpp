#pragma once
#include "IEngine.hpp"

/**
* @brief Class that simulate internal combustion engine.
*/
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
    EngineIC();

    /**
    * @brief Function to start calculating step.
    * @param dt - time step.
    * @return current engine temerature.
    */
    double startStep(const double & dt) override;

    /**
    * @brief Function to initialize engine.
    */
    void initializeEngine(const EnginConfiguration & configuration) override;

    /**
    * @brief Function to check if engine is overheated.
    */
    bool isOverHeated() override;

    /**
    * @brief Function to get current engine temperature.
    */
    double getCurrentT() override;

    /**
    * @brief Function to set ambitient temperature;
    * @param temp - ambitient temperature.
    */
    void setAmbitientT(const double & temp) override;
};

