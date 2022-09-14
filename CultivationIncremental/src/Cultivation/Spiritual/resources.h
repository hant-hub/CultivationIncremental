#pragma once

namespace GLogic::Spiritual::Resources {

//individual stages
struct Mortal {
    Mortal(): progress(0.0f), canAdvance(false) {}

    std::string getRepr() { return fmt::format("progress = {}, canAdvance = {}", progress, canAdvance); }

    float progress;
    bool canAdvance;
};

struct QiGathering {
    QiGathering(): QiStrands(0.0f), canAdvance(false) {}

    std::string getRepr() { return fmt::format("QiStrands = {}, canAdvance = {}", QiStrands, canAdvance); }

    float QiStrands;
    bool canAdvance;
    float cultivationspeed;
};



//main container
struct CultivationStage {
    CultivationStage(): m(Mortal()), qg(QiGathering()) {}

    std::string getRepr() { return fmt::format("Mortal: {}\nQiGathering: {}", m.getRepr(), qg.getRepr()); }



    Mortal m;
    QiGathering qg;
};



};