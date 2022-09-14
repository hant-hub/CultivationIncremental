#include "Base.h"

namespace GLogic::Spiritual::Techniques {

namespace mBase { 

    float Tier1(float x) {
        return x;
    }

    float FoundationTick(float x) {
        return x;
    }

    modifier m[(int)ModType::MaxItems] = {Tier1, FoundationTick};
    



    }

}