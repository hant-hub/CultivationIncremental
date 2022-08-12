#include "ui.h"





GUI::GUI::GUI(Render::Window& w, Render::Panel& m, Render::Panel* Physical, Render::Panel* Spriritual, Render::Panel* Mental, unsigned int nump, GLogic::Cultivation& c) : meta(m), panels({Physical, Spriritual, Mental}), numPanels(nump), c(c), ActivePanel({0,0})
{
}




GUI::GUI::~GUI() {
    printf("GUI Destroyed\n");
    delete[] panels;
}

void GUI::GUI::Draw() {
    meta.Draw();
    GetActivePanel()->Draw();
}



void GUI::GUI::Clicked(float x, float y) {
    
    Render::Panel* p = &meta;
    Render::Button* b = meta.CheckButtons(x, y);
    unsigned int type = meta.GetType();
    unsigned int stage = 0;
    if (b == nullptr){

    type = ActivePanel[0];
    stage = ActivePanel[1];

    Render::Panel* p = &(panels[type])[stage];
    

    b = p->CheckButtons(x, y);
    
    if (b == nullptr) return;
    }
    int id = b->GetID();
    
    switch((GLogic::CultivationType)type){
        
        case GLogic::CultivationType::Physical:
            c.p.Action((GLogic::Physical::Pstage)stage, id);
        break;

        case GLogic::CultivationType::NONE:
            int type = id%3;
            int stage = (id - type)/3;
        
        
            SetActivePanel((GLogic::CultivationType)type, stage);
        break;


    }

    printf("type = %i stage = %i  id = %i\n", type, stage, id);

}

void GUI::GUI::SetActivePanel(GLogic::CultivationType type, int stage) {
    ActivePanel[0] = (unsigned int)type;
    ActivePanel[1] = stage;
}

Render::Panel* GUI::GUI::GetActivePanel() {
    return &panels[ActivePanel[0]][ActivePanel[1]];

}