#pragma once
#include "pcultivation.h"
#include "../Cultivation.h"

namespace GLogic{
   class Cultivation;

namespace Physical {

//basic physical training
void Action00(Pcultivation& c){
   
   if (c.data.m.fitness < 10.0f) {
    c.data.m.fitness += 1.0f;
   } else if (c.data.m.fitness < 20.0f){
    c.data.m.fitness += 0.01f;
   }
}

//breakthrough
void Action01(Pcultivation& c) {
   if (c.data.m.canAdvance) {
      c.stage = Foundation;
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

void Action11(Pcultivation& c) {
   const Cultivation& cul = c.GetParent();
   const Spiritual::Resources::CultivationStage dat = cul.s.GetData();
   printf("%i", dat.m.canAdvance);
}


}}