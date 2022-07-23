#pragma once
#include "pcultivation.h"

namespace GLogic{
namespace Physical{

void Tick0(Pcultivation& c, float dt) {
   if (c.data.m.canAdvance) return;
   
   if (c.data.m.fitness >= 10.0f) {
        c.data.m.canAdvance = true;
   }
}

void Tick1(Pcultivation& c, float dt) {
    
}


}}