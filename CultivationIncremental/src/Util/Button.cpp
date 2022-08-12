#include "Button.h"
#include "Panel.h"


namespace Render {

Button::Button(Shader* s, Shader* t, Panel& p, Window& w, const char* text, const char* image1, float x, float y, float width, float height, int action) : x(x), y(y), width(width), height(height), textshader(t), trenderer(w, "fonts\\arial.ttf", 48), text(text), visual(Sprite(w, image1, x, y, width, height, 0.0f, s)), id(action){

    p.buttons.push_back(this);

}

Button::~Button() {
printf("button destroyed\n");
}

void Button::Draw(Camera& c) {
    visual.Draw(c);
    
    trenderer.RenderText(*textshader, text, x - width * 0.25f, y - height * 0.1f, 0.5, glm::vec3(0.0f));
    
}


//determines whether a point is inside the button bounds assumes the position is in the center of the button
bool Button::PointInBounds(float cx, float cy, Camera& cam) {
    
    glm::vec4 point(cx, cy, 0.0f, 1.0f);
    glm::mat4 ToModel(1.0f);
    glm::translate(ToModel, glm::vec3(x, y, 0.0f));
    point = glm::inverse(cam.GetView() * ToModel) * point;
    
    
    float UpperBoundY = y + height/2;
    float LowerBoundY = y - height/2;

    float UpperBoundX = x + width/2;
    float LowerBoundX = x - width/2;

    //printf("ux %f, lx %f, uy %f, ly %f", UpperBoundX, LowerBoundX, UpperBoundY, LowerBoundY);

    if (point.y > UpperBoundY) {
        return false;
    }
    if (point.y < LowerBoundY) {
        return false;
    }

    if (point.x > UpperBoundX) {
        return false;
    }
    
    if (point.x < LowerBoundX) {
        return false;
    }

    return true;

}



}