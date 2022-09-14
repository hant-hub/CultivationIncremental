#pragma once
#include "pcultivation.h"
#include "../Cultivation.h"
#include "Techniques/methods_lib.h"

namespace GLogic{
   class Cultivation;

namespace Physical {

//basic physical training
void Action00(Pcultivation& c){
   
   float increase = 1.0f;
   if (c.data.m.fitness > 10.0f){
    increase = 0.01f;
   }

   increase = Techniques::meth[c.method].Modify(Techniques::ModType::Exercise, increase);
   c.data.m.fitness += increase;

}

//breakthrough
void Action01(Pcultivation& c) {
   if (c.data.m.canAdvance) {
      c.stage = VesselOpening;
   }
}

//attack blockage (manages vessels and progress)
void Action10(Pcultivation& c){

   if (c.data.f.vessels == 12) return;

   

   if (c.data.f.progress >= 1.0f) {

      if ((c.data.f.vessels < 8)){
         c.data.f.vessels += 1;
         c.data.f.progress = 0.0f;
      } else if (c.data.f.vessels == 8) {
         c.data.f.vessels += 1;
         c.data.f.progress = 0.0f;
         c.data.f.canAdvance = true;
      } else if (c.data.f.vessels < 11) {
         c.data.f.vessels += 1;
         c.data.f.progress = 0.0f;
      } else if (c.data.f.vessels == 11) {
         c.data.f.vessels += 1;
         c.data.f.progress = 0;
      }

      float bloodqi = 10.0f * std::max(GLogic::smoothstep((c.data.m.fitness-10.0f)/10.0f), 0.01f) * (1 + (c.data.m.fitness == 20.0f));
      c.data.f.maxstrength = bloodqi * std::pow(2, c.data.f.vessels) + 100;


   }
}


//test for getting parent and sibling data
void Action11(Pcultivation& c) {
   if (c.data.f.canAdvance) {
      c.stage = SkinRefinement;
   }
}


}}