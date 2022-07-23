#include "Cultivation.h"


namespace GLogic {


Cultivation::Cultivation(){
p = Physical::Pcultivation();
}
Cultivation::~Cultivation(){

}

void Cultivation::update(float dt){
p.update(dt);
}




}