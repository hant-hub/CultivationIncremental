#pragma once
#include "../Renderer/renderlib.h"
#include "../Renderer/Shader.h"
#include "../Renderer/Sprite.h"
#include "../Renderer/core.h"

namespace Render {

    class Panel;


    class Button{
    
    public:
        Button(Shader* s, Shader* t,  Panel& p, Window& w, const char* text, const char* image1, float x, float y, float width, float height, int action);
        ~Button();

        void Draw(Camera& c);
        bool PointInBounds(float x, float y, Camera& cam);
        const int GetID() {return id;}

    private:
        float x, y;
        float width, height;
        Sprite visual;
        TextRenderer trenderer;
        Shader* textshader;
        std::string text;
        int id;
    };







}