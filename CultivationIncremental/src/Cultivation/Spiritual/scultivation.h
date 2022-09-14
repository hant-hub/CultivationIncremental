#pragma once
#include "../util.h"
#include "resources.h"



namespace GLogic {
    class Cultivation;
    namespace Spiritual {


    enum Sstage{
        Mortal = 0,
        QiGathering = 1
    };


    class Scultivation {
        public:
            Scultivation(Cultivation& c);
            ~Scultivation();

            void update(float dt);
            void Action(Sstage group, int id);

            //getters
            const std::string GetCultivation() { return fmt::format("{} \n  stage: {}", data.getRepr(), stage); }
            const Sstage GetStage() {return stage;}
            const Cultivation& GetParent() { return c; }
            const Spiritual::Resources::CultivationStage& GetData() const { return data; }

            //action friend list
            friend void Action00(Scultivation&);

            //Tick friend list
            friend void Tick0(Scultivation&, float);
            friend void Tick1(Scultivation&, float);


        private:
            Sstage stage;
            Cultivation& c;
            Resources::CultivationStage data;
            int method;


    };



};}