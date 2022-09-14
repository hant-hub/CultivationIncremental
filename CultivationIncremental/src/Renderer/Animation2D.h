#pragma once


namespace Render::Animation {



struct Frame {
float x;
float y;
float width;
float height;
};



class Animation2D {
    Animation2D(const char* filepath, int fps);
    ~Animation2D();

    void Play();

    Frame GetFrame();

    private:
        int texture;
        float timeAcumulator; //accumulates time until next frame should appear (allows non synced frame rates)
        float frametime;

        std::vector<Frame> frames;
};







};