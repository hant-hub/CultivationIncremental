#pragma once
#include "Physical/pcultivation.h"

namespace GLogic{

enum class CultivationType {
    Physical,
    Spiritual,
    Mental
};



class Cultivation {
public:
    Cultivation();
    ~Cultivation();

    void update(float dt);

    Physical::Pcultivation p;
};
}