#include "pcultivation.h"
#include "actions.h"
#include "ticks.h"


namespace GLogic {
namespace Physical {

    const tickFunc<Pcultivation> tickmethods[2] = {
                                    Tick0,
                                    Tick1
    };

    const action<Pcultivation> Actions[2][2] = {
                                    {Action00, Action01},
                                    {Action10}
    };


    Pcultivation::Pcultivation() : stage(Mortal), data(Physical::CultivationStage()) {
    }


    Pcultivation::~Pcultivation(){
    }

    void Pcultivation::update(float dt){
        tickmethods[stage](*this, dt);
    }

    void Pcultivation::Action(Pstage group, int id) {
        Actions[group][id](*this);
    }


}}