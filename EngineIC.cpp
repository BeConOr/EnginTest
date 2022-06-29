#include "EngineIC.h"

double EngineIC::heatingVelocity(const double & velocity)
{
    return mConfiguration.momentumEq.getMomentum(velocity)*mConfiguration.heatByMoment 
        + velocity*velocity*mConfiguration.heatByVelocity;
}

double EngineIC::calculateVelocity(const double & velocity, const double & dt)
{
    return velocity + mConfiguration.momentumEq.getMomentum(velocity) * dt / mConfiguration.massMoment;
}

double EngineIC::coolingVelocity(const double & ambitientT, const double & engineT)
{
    return mConfiguration.coolingCoef * (ambitientT - engineT);
}

EngineIC::EngineIC(double const & ambitientT)
    : mConfiguration()
    , mAmbitientT(ambitientT)
    , mCurrentVelocity(0.)
    , mCurrentEngineT(ambitientT)
{
}

double EngineIC::startStep(const double & dt)
{
    mCurrentVelocity = calculateVelocity(mCurrentVelocity, dt);
    mCurrentEngineT = mCurrentEngineT + (heatingVelocity(mCurrentVelocity) + coolingVelocity(mAmbitientT, mCurrentEngineT)) * dt;

    return mCurrentEngineT;
}

void EngineIC::initializeEngine(const EnginConfiguration & configuration)
{
    mConfiguration = configuration;
}
