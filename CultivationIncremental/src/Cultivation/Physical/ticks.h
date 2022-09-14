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
   
   float bloodqi = 10.0f * std::max(GLogic::smoothstep((c.data.m.fitness-10.0f)/10.0f), 0.01f) * (1 + (c.data.m.fitness == 20.0f));
   
   float mult = std::pow(1.71, c.data.f.vessels) + 1;
   //printf("%f\n", dt * (mult * (1/bloodqi)));
   c.data.f.progress += Techniques::meth[c.method].Modify(Techniques::ModType::VesselOpeningtick, (dt * 1/(mult * (1/bloodqi))));
}


}}