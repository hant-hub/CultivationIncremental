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

        struct VesselOpening {
            VesselOpening() : vessels(0), progress(0.0f), canAdvance(false), maxstrength(0) {}
            std::string getRepr() { return fmt::format("vessels = {}, progress = {}, canAdvance = {}, maxstrength = {}", vessels, progress, canAdvance, maxstrength); }

            int vessels;
            float progress;
            bool canAdvance;
            float maxstrength;

        };

        //main container
        struct CultivationStage {
            CultivationStage() : m(Mortal()), f(VesselOpening()) {}
            ~CultivationStage() {}

            std::string getRepr() { return fmt::format("Mortal: {}\nVesselOpening: {}", m.getRepr(), f.getRepr()); }

            Mortal m;
            VesselOpening f;

        };



       


    };

};



