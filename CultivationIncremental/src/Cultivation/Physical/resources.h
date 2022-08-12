#pragma once

namespace GLogic{

    namespace Physical::Resources{

        //individual stages
        struct Mortal {
            Mortal() : fitness(0.0f), canAdvance(false) {}
            
            std::string getRepr() {   return fmt::format("fitness = {}, canAdvance = {}", fitness, canAdvance);    }
            
            float fitness;
            bool canAdvance;
        };

        struct Foundation {
            Foundation() : vessels(0), progress(0.0f), canAdvance(false), maxstrength(0) {}
            std::string getRepr() { return fmt::format("vessels = {}, progress = {}, canAdvance = {}, maxstrength = {}", vessels, progress, canAdvance, maxstrength); }

            int vessels;
            float progress;
            bool canAdvance;
            float maxstrength;

        };

        //main container
        struct CultivationStage {
            CultivationStage() : m(Mortal()), f(Foundation()) {}
            ~CultivationStage() {}

            std::string getRepr() { return fmt::format("Mortal: {}\nFoundation: {}", m.getRepr(), f.getRepr()); }

            Mortal m;
            Foundation f;

        };



       


    };

};



