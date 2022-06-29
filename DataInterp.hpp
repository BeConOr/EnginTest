#pragma once
#include <vector>

struct MomentumPerVelocity {
    std::vector<double> momentum;
    std::vector<double> velocity;

    double getMomentum(const double & vel) const{
        if(vel < 0.) {
            return momentum[0];
        }
        for(size_t i(0); i < momentum.size(); ++i) {
            if(vel < velocity[i]) {
                double k = (momentum[i] - momentum[i - 1]) / (velocity[i] - velocity[i - 1]);
                return k * vel + momentum[i];
            }
        }
        return momentum.back();
    }
};

struct EnginConfiguration {
    MomentumPerVelocity momentumEq;
    double massMoment;
    double overHeatTemp;
    double heatByMoment;
    double heatByVelocity;
    double coolingCoef;
};
