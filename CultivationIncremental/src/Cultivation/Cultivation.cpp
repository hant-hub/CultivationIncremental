#include "Cultivation.h"


namespace GLogic {


Cultivation::Cultivation() : p(*this), s(*this) {
}


Cultivation::~Cultivation(){

}

void Cultivation::update(float dt){
p.update(dt);
s.update(dt);
}




}