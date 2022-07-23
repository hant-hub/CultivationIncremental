#pragma once
#include "../Renderer/renderlib.h"
#include "../Renderer/Shader.h"
#include "../Renderer/Sprite.h"


namespace Render {

    class Panel;


    class Button{
    public:
        Button(Shader* s, Panel& p, const char* image1, float x, float y, float width, float height, int action);
        ~Button();

        void Draw(Camera& c);
        bool PointInBounds(float x, float y, Camera& cam);
        const int GetID() {return id;}

    private:
        float x, y;
        float width, height;
        Sprite visual;
        int id;
    };







}