#include "Base.h"



namespace GLogic::Physical::Techniques {

namespace mBase { 

    float Tier1(float x) {
        return 20;
    }

    float FoundationTick(float x) {
        return 1;
    }

    modifier m[(int)ModType::MaxItems] = {Tier1, FoundationTick};
    



    }

}