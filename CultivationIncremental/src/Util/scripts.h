#pragma once
#include "Button.h"
#include "Panel.h"


namespace Scripts {
    struct PanelArray {
        Render::Panel * p;
        int length;
    };

    PanelArray CreatePanels(char * filepath, const char * buttonImage, Render::Window& w, Render::Shader& s) {
        //Get Text file and download as string
        std::string scriptText;

        std::ifstream scriptStream;
        scriptStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        
        try {
            scriptStream.open(filepath);
            std::stringstream scriptbuf;
            

            scriptbuf << scriptStream.rdbuf();

            scriptStream.close();

            scriptText = scriptbuf.str();

        } catch(std::ifstream::failure& e) {
            std::cout << "Script Failed to be Loaded: " << e.what() << std::endl;
        }
        
        //split string into panel segments
        std::stringstream buffer(scriptText);
        std::vector<std::string> panelsegments;
        std::string segment;
        int i= 0;
        while (std::getline(buffer, segment, 'P')){
            panelsegments.push_back(segment);
        }
        panelsegments.erase(panelsegments.begin());
    
        
        //split panel into button segments
        std::vector<std::vector<std::string>> objects;
        for (std::string s : panelsegments) {
            
            std::stringstream buf(s);
            std::vector<std::string> buttons;
            std::string segment;
            while (std::getline(buf, segment, 'B')) {
                
                buttons.push_back(segment);
            }
            objects.push_back(buttons);
        }

        
        
        //create Button and Panel Objects
        Render::Panel* panels = (Render::Panel*)calloc(objects.size(), sizeof(Render::Panel));
        
        int index = 0;
        for (std::vector<std::string> p : objects) {
            auto stageStartIndex = p[0].find("stage: ")+7;
            std::size_t stageEndIndex = 1;

            int stage = std::stoi(p[0].substr(stageStartIndex, stageEndIndex));
            
            auto typeStartIndex = p[0].find("type: ")+6;
            std::size_t typeEndIndex = 1;

           
            int type = std::stoi(p[0].substr(typeStartIndex, typeEndIndex));
            
            panels[index] = *(new Render::Panel(w, stage, (GLogic::CultivationType)type));
            printf("hopefully before panel destructor\n");
            p.erase(p.begin());
            
            for (std::string b : p) {
                float x;
                float y;
                float width;
                float height;
                int id;

                std::stringstream button(b);
                std::string parameter;
                while (std::getline(button, parameter, '\n')) {
                    auto end = parameter.length()-1;

                    if (parameter.find("x: ") != std::string::npos) {
                        printf("this one  0\n");
                        auto start = parameter.find("x: ") + 3;
                        auto end = parameter.find("\n");
                        x = std::stof(parameter.substr(start, end-start));
                    } else if (parameter.find("y: ") != std::string::npos) {
                        printf("this one  1\n");
                        auto start = parameter.find("y: ") + 3;
                        auto end = parameter.find("\n");
                        y = std::stof(parameter.substr(start, end-start));
                    } else if (parameter.find("width: ") != std::string::npos) {
                        printf("this one  2\n");
                        auto start = parameter.find("width: ") + 7;
                        auto end = parameter.find("\n");
                        width = std::stof(parameter.substr(start, end-start));
                    } else if (parameter.find("height: ") != std::string::npos) {
                        printf("this one  3\n");
                        auto start = parameter.find("height: ") + 8;
                        auto end = parameter.find("\n");
                        height = std::stof(parameter.substr(start, end-start));
                    } else if (parameter.find("ID: ") != std::string::npos) {
                        printf("this one  4\n");
                        auto start = parameter.find("ID: ") + 4;
                        auto end = parameter.find("\n");
                        id = std::stof(parameter.substr(start, end-start));
                    }
                }
            
                printf("x: %f y: %f width: %f height: %f ID: %i\n", x, y, width, height, id);
                new Render::Button(&s, panels[index], buttonImage, x, y, width, height, id);
            }
            index++;
            
            //panels.push_back(panel);
            printf("panel pushed\n");

        }
        
        //return finished panel objects
        
        return {panels, objects.size()};

        
        

    }



}