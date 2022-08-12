#include "util.h"


namespace GLogic {

float smoothstep(float x) {
    if (x < 0.0f)  return 0.0f;
    else if (x >= 1.0f) return 1.0f;
    else return (3*x*x) - (2*x*x*x);
}

}