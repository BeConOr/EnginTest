#include "TestStand.hpp"

TestStand::TestStand()
	: mEngine(std::make_shared<IEngine>())
	, mTimeStep(0.)
{
}

double TestStand::startTest()
{
	double time(0.);

	while (!mEngine->isOverHeated()) {
		mEngine->startStep(mTimeStep);

		time += mTimeStep;
	}

	return time;
}

void TestStand::changeTimeStep(const double& timeStep)
{
	mTimeStep = timeStep;
}

void TestStand::setNewEngine(const std::shared_ptr<IEngine>& engine)
{
	mEngine = engine;
}
