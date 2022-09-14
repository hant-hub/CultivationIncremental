#include "scultivation.h"
#include "actions.h"
#include "ticks.h"



namespace GLogic {

namespace Spiritual {

const tickFunc<Scultivation> tickmethods[2] = {
                                Tick0,
                                Tick1
};

const action<Scultivation> Actions[1][1] = {
                                {Action00}
                                
};


Scultivation::Scultivation(Cultivation& c) : c(c), stage(Sstage::Mortal), data(Resources::CultivationStage()) {}
Scultivation::~Scultivation() {}

void Scultivation::update(float dt) {
    tickmethods[stage](*this, dt);
}

void Scultivation::Action(Sstage group, int id) {
    Actions[group][id](*this);
}




}
}