#pragma once
#include "Physical/pcultivation.h"
#include "Spiritual/scultivation.h"

namespace GLogic{

enum class CultivationType {
    Physical = 0,
    Spiritual = 1,
    Mental = 2,
    NONE = 3
};



class Cultivation {
public:
    Cultivation();
    ~Cultivation();

    void update(float dt);

    Physical::Pcultivation p;
    Spiritual::Scultivation s;
};
}