#pragma once
#include "../Renderer/renderlib.h"
#include "../Renderer/Renderer.h"
#include "Button.h"
#include "../Renderer/Camera.h"
#include "../Cultivation/Cultivation.h"


namespace Render {



class Panel {
public:
    Panel(const Window& w, int stage, GLogic::CultivationType t);
    ~Panel();

    void Draw();
    Button* CheckButtons(float x, float y);
    
    friend class Button;

    const int GetStage() {return stage;}
    const GLogic::CultivationType GetType() {return t;}

    std::vector<Button *> buttons;
    Camera c;

    int stage;
    GLogic::CultivationType t;

};





}