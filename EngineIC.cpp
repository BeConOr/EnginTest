#include "EngineIC.h"

double EngineIC::heatingVelocity(const double & momentum, const double & velocity)
{
    return mConfiguration.momentumEq.getMomentum(velocity)*mConfiguration.heatByMoment 
        + velocity*velocity*mConfiguration.heatByVelocity;
}

double EngineIC::calculateVelocity(const double & momentum, const double & velocity, const double & dt)
{
    return velocity + momentum * dt / mConfiguration.massMoment;
}

double EngineIC::coolingVelocity(const double & ambitientT, const double & engineT)
{
    return mConfiguration.coolingCoef * (ambitientT - engineT);
}

EngineIC::EngineIC()
    : mConfiguration()
{
}
