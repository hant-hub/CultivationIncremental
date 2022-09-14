#pragma once
#include "scultivation.h"

namespace GLogic::Spiritual {

void Tick0(Scultivation& s, float dt) {
    
}

void Tick1(Scultivation& s, float dt) {
    const GLogic::Physical::Pcultivation& phys = (s.GetParent().p);
    const int vessels = (int)phys.GetData().f.vessels;
    float speed = vessels;


    s.data.qg.QiStrands += speed * dt;
}


}