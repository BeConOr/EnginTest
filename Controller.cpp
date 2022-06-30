#include "Controller.hpp"
#include "DataInterp.hpp"

Controller::Controller()
	:mStand()
	, mEngine(std::make_shared<EngineIC>())
	, mLogger()
{
}

void Controller::run()
{
	double ambitientT(0.);
	
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


	mLogger.writeAccesInformation(systemMessage::TEMP_REQ);
	std::cin >> ambitientT;

	mEngine->setAmbitientT(ambitientT);
	mEngine->initializeEngine(configuration);
	mStand.setNewEngine(mEngine);

	mStand.changeTimeStep(0.001);

	mLogger.writeAccesInformation(systemMessage::START_NOTION);
	switch(mStand.startTest()) {
	case 0:
		mLogger.writeErrorInformation(systemMessage::OVERHEATED);
		mLogger.writeErrorInformation(systemMessage::OVERHEATED_TIME);
		mLogger.writeInformation(mStand.getCurrentTIme());
		break;
	case 1:
		mLogger.writeErrorInformation(systemMessage::PLATO_WARN);
		mLogger.writeErrorInformation(systemMessage::PLATO_TEMP);
		mLogger.writeInformation(mEngine->getCurrentT());
		break;
	};
}
