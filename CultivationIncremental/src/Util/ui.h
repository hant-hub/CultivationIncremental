#pragma once
#include "../Renderer/core.h"
#include "../Cultivation/Cultivation.h"
#include "Panel.h"
#include "Button.h"


namespace GUI {

    



    class GUI {
        public:
            GUI(Render::Window& w, Render::Panel* Physical, Render::Panel* Spriritual, Render::Panel* Mental, unsigned int nump, GLogic::Cultivation& c);
            ~GUI();


            void Clicked(float x, float y);
            void SetActivePanel(GLogic::CultivationType type, int stage);

        private:
            GLogic::Cultivation& c;

            unsigned int ActivePanel[2];
            unsigned int numPanels;
            Render::Panel* panels[3];

    };









}