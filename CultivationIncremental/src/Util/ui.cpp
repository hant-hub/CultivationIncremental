#include "ui.h"






GUI::GUI::GUI(Render::Window& w, Render::Panel* Physical, Render::Panel* Spriritual, Render::Panel* Mental, unsigned int nump, GLogic::Cultivation& c) : panels({Physical, Spriritual, Mental}), numPanels(nump), c(c), ActivePanel({0,0})
{
}




GUI::GUI::~GUI() {
    printf("GUI Destroyed\n");
    delete[] panels;
}

void GUI::GUI::Clicked(float x, float y) {
    
    unsigned int type = ActivePanel[0];
    unsigned int stage = ActivePanel[1];

    Render::Panel* p = &(panels[type])[stage];
    

    Render::Button* b = p->CheckButtons(x, y);
    
    if (b == nullptr) return;
    
    int id = b->GetID();
    
    if (type == (unsigned int)GLogic::CultivationType::Physical) {
       
        c.p.Action((GLogic::Physical::Pstage)stage, id);
       
        
    }
    printf("stage = %i  id = %i\n", stage, id);

}

void GUI::GUI::SetActivePanel(GLogic::CultivationType type, int stage) {
    ActivePanel[0] = (unsigned int)type;
    ActivePanel[1] = stage;


}