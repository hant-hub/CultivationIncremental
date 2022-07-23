#pragma once
#include "pcultivation.h"

namespace GLogic{
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


void Action10(Pcultivation& c){
    
}


}}