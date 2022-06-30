#include "Controller.hpp"
#include "DataInterp.hpp"

Controller::Controller()
	:mStand()
	, mEngine(std::make_shared<IEngine>())
{
}

void Controller::run()
{
	double ambitientT(0.);
	mEngine = std::make_shared<EngineIC>();
	
	EnginConfiguration configuration;
	configuration.massMoment = 10.;
	configuration.overHeatTemp = 110.;
	configuration.heatByMoment = 0.01;
	configuration.heatByVelocity = 0.0001;
	configuration.coolingCoef = 0.1;

	configuration.momentumEq.momentum.push_back(20.0);
	configuration.momentumEq.momentum.push_back(75.0);
	configuration.momentumEq.momentum.push_back(100.0);
	configuration.momentumEq.momentum.push_back(105.0);
	configuration.momentumEq.momentum.push_back(75.0);
	configuration.momentumEq.momentum.push_back(0.0);

	configuration.momentumEq.velocity.push_back(0.0);
	configuration.momentumEq.velocity.push_back(75.0);
	configuration.momentumEq.velocity.push_back(150.0);
	configuration.momentumEq.velocity.push_back(200.0);
	configuration.momentumEq.velocity.push_back(250.0);
	configuration.momentumEq.velocity.push_back(300.0);


	std::cin >> ambitientT;

	mEngine->setAmbitientT(ambitientT);
	mEngine->initializeEngine(configuration);

	mStand.changeTimeStep(0.001);

	double overHeatingTime = mStand.startTest();
}
