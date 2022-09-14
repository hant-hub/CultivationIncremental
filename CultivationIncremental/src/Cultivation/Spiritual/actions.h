#pragma once
#include "../Cultivation.h"


namespace GLogic::Spiritual {

//unlock, only avalible after physical Mortal cultivation
void Action00(Scultivation& s) {
    const GLogic::Physical::Pcultivation& phys = (s.GetParent().p);
    const int stage = (int)phys.GetStage();
    if (stage) s.stage = Sstage::QiGathering;

    printf("boom\n");
}





}