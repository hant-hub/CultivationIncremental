#include "Panel.h"


namespace Render{


Panel::Panel(const Window& w, int stage, GLogic::CultivationType t) : c(Camera(0.0f, 0.0f, (float)w.width, (float)w.height)), stage(stage), t(t) {

}

Panel::~Panel() {
    printf("panel Destroyed\n");
    for (Button* b : buttons) {
        delete b;
    }
}


void Panel::Draw() {
    

    for (Button* b : buttons) {
        
        b->Draw(c);
        
       
    }

}

Button* Panel::CheckButtons(float x, float y) {

    for (Button* b : buttons) {

        if (b->PointInBounds(x, y, c)) {
            return b;
        }
        
    }

    return nullptr;

}




}