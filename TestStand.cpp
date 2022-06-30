#include "TestStand.hpp"
#include <math.h>

TestStand::TestStand()
	: mEngine(nullptr)
	, mTimeStep(0.)
	, mTime(0.)
{
}

int TestStand::startTest()
{
	mTime = 0.;
	double engineCurrentT(mEngine->getCurrentT());

	while (!mEngine->isOverHeated()) {

		if(abs(engineCurrentT - mEngine->startStep(mTimeStep)) < PRECIS) {
			return 1;
		}

		engineCurrentT = mEngine->getCurrentT();
		mTime += mTimeStep;
	}

	return 0;
}

void TestStand::changeTimeStep(const double& timeStep)
{
	mTimeStep = timeStep;
}

void TestStand::setNewEngine(const std::shared_ptr<IEngine>& engine)
{
	mEngine = engine;
}

double TestStand::getCurrentTIme()
{
	return mTime;
}
