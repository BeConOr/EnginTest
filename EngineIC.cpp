#include "EngineIC.hpp"

double EngineIC::heatingVelocity(const double & velocity)
{
    return mConfiguration.momentumEq.getMomentum(velocity) * mConfiguration.heatByMoment 
        + velocity*velocity * mConfiguration.heatByVelocity;
}

double EngineIC::calculateVelocity(const double & velocity, const double & dt)
{
    double newVelocity = velocity + mConfiguration.momentumEq.getMomentum(velocity) * dt / mConfiguration.massMoment;

    if (newVelocity > mConfiguration.momentumEq.velocity.back()) {
        return mConfiguration.momentumEq.velocity.back();
    }

    return newVelocity;
}

double EngineIC::coolingVelocity(const double & ambitientT, const double & engineT)
{
    return mConfiguration.coolingCoef * (ambitientT - engineT);
}

EngineIC::EngineIC()
    : mConfiguration()
    , mAmbitientT(0.)
    , mCurrentVelocity(0.)
    , mCurrentEngineT(0.)
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

bool EngineIC::isOverHeated()
{
    return mCurrentEngineT > mConfiguration.overHeatTemp;
}

double EngineIC::getCurrentT()
{
    return mCurrentEngineT;
}

void EngineIC::setAmbitientT(const double & temp)
{
    mAmbitientT = temp;
    mCurrentEngineT = temp;
}
