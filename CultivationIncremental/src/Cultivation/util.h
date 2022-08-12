#pragma once


namespace GLogic {

template<typename c>
using tickFunc = std::function<void(c&, float)>;

template<typename c>
using action = std::function<void(c&)>;

float smoothstep(float x); 

};
