#pragma once
#include "../util.h"
#include "resources.h"



namespace GLogic {

class Cultivation;

namespace Physical {
enum Pstage {
    Mortal = 0,
    Foundation = 1
};




class Pcultivation {
public:
Pcultivation(Cultivation& c);
~Pcultivation();

void update(float dt);
void Action(Pstage group, int id);

//getters
const std::string GetCultivation() { return fmt::format("{} \n  stage: {}", data.getRepr(), stage); }
const Pstage GetStage() {return stage;}
const Cultivation& GetParent() { return c; }
const Physical::Resources::CultivationStage& GetData() const { return data; }

//action friend list
friend void Action00(Pcultivation&);
friend void Action01(Pcultivation&);
friend void Action10(Pcultivation&);
friend void Action11(Pcultivation&);

//Tick friend list
friend void Tick0(Pcultivation&, float);
friend void Tick1(Pcultivation&, float);

private:
    Pstage stage;
    Cultivation& c;
    Physical::Resources::CultivationStage data;
    

};


}}
