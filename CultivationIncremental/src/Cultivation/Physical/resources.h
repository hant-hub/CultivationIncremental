#pragma once

namespace GLogic{

    namespace Physical{

        //individual stages
        struct Mortal {
            Mortal() : fitness(0.0f), canAdvance(false) {}
            
            std::string getRepr() {   return fmt::format("fitness = {}, canAdvance = {}", std::to_string(fitness), std::to_string(canAdvance));    }
            
            float fitness;
            bool canAdvance;
        };

        struct Foundation {
            Foundation() {}
            std::string getRepr() { return fmt::format("NO ATTRS"); }
        };

        //main container
        struct CultivationStage {
            CultivationStage() : m(Mortal()), f(Foundation()) {}
            ~CultivationStage() {}

            std::string getRepr() { return fmt::format("Mortal: {}\nFoundation: {}", m.getRepr(), f.getRepr()); }

            Mortal m;
            Foundation f;

        };



       


    }

}



