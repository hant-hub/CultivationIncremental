#pragma once

namespace GLogic::Spiritual::Resources {

//individual stages
struct Mortal {
    Mortal(): progress(0.0f), canAdvance(false) {}

    std::string getRepr() { return fmt::format("progress = {}, canAdvance = {}", progress, canAdvance); }

    float progress;
    bool canAdvance;
};

struct Foundation {
    Foundation(): meridians(0), qi(0.0f), canAdvance(false) {}

    std::string getRepr() { return fmt::format("Meridians = {}, Qi = {}, canAdvance = {}", meridians, qi, canAdvance); }

    float qi;
    int meridians;
    bool canAdvance;
    float cultivationspeed;
};



//main container
struct CultivationStage {
    CultivationStage(): m(Mortal()), f(Foundation()) {}

    std::string getRepr() { return fmt::format("Mortal: {}\nFoundation: {}", m.getRepr(), f.getRepr()); }



    Mortal m;
    Foundation f;
};



};