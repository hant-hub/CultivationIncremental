#pragma once



namespace GLogic::Physical::Techniques {

enum class ModType {
Exercise = 0,
VesselOpeningtick = 1,
MaxItems = 2
};






typedef float( *modifier )(float);

struct Method {
    Method(const char* name, int max, modifier* m) : name(name), maxrealm(max), mods(m) {}
    ~Method() {std::cout << "bam" << std::endl;}

    float Modify(ModType m, float input) const
    { 
    if ((int)m <= maxrealm) {
        float output = mods[(int)m](input);
        return output;
    }  
    else return input;
    }

    std::string name;
    int maxrealm;
    modifier* mods;
};




}