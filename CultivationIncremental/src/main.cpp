

#include "Cultivation/Cultivation.h"
#include "Renderer/core.h"
#include "Util/scheduler.h"
#include "Util/ui.h"
#include "Util/scripts.h"


void error_callback(int error, const char* msg) {
	std::string s;
	s = " [" + std::to_string(error) + "] " + msg + '\n';
	std::cerr << s << std::endl;
}
void CheckErrorStack(int i) {
	int code = glGetError();
	if (code) {
		std::cout << code << std::endl;
        std::cout << i << std::endl;
	}

}


void MouseButtonCallback(GLFWwindow* w, int button, int action, int mods) {
    
    if (action == GLFW_PRESS) {
        GUI::GUI* gui = static_cast<GUI::GUI*>(glfwGetWindowUserPointer(w));
        
        double xpos, ypos;
        glfwGetCursorPos(w, &xpos, &ypos);
        
        gui->Clicked(xpos, ypos);
       
        
    
    }

}




int main(int argc, char* argv[]) {


    glfwSetErrorCallback(error_callback);


    GLogic::Cultivation c;
    EventLoop::Scheduler s;
  
    
    Render::Window* window = Render::CreateWindow(1600, 1200);




    Render::Shader textshader("shaders/vText.glsl", "shaders/fText.glsl");
    Render::Shader texturedShader("shaders/vSimple.glsl", "shaders/fSimple.glsl");
    Render::TextRenderer trender(*window, "fonts\\arial.ttf", 48);

    Render::Panel test(*window, 0, GLogic::CultivationType::Physical);

    Render::Button b(&texturedShader, &textshader, test, *window, "test", "images/button.jpg", -50.0f, 0.0f, 100.0f, 100.0f, 0);
    Render::Button a(&texturedShader, &textshader, test, *window, "test2", "images/button.jpg", 50.0f, 0.0f, 100.0f, 100.0f, 1);
    
    Scripts::PanelArray p = Scripts::CreatePanels("scripts/physical.txt", "images/button.png", *window, texturedShader, textshader);
    Scripts::PanelArray sp = Scripts::CreatePanels("scripts/spiritual.txt", "images/button.png", *window, texturedShader, textshader);
    Scripts::PanelArray meta = Scripts::CreatePanels("scripts/meta.txt", "images/button.png", *window, texturedShader, textshader);
    printf("func exits\n");
    //Render::Panel t[] = {test};
    GUI::GUI gui(*window, meta.p[0], p.p, sp.p, nullptr, 0u, c);




    glfwSetWindowUserPointer(window->window, &gui);



   


    glfwSetMouseButtonCallback(window->window, MouseButtonCallback);




    std::function<void(std::chrono::system_clock::time_point)> Renderloop = [&c, window](std::chrono::system_clock::time_point dt){
        std::string input;
        
        std::cin >> input;
       
        if (input == "halt") {
            glfwSetWindowShouldClose(window->window, 1);
        } else if (input == "0") {
            c.p.Action((c.p.GetStage()), 0);
        } else if (input == "1") {
            c.p.Action((c.p.GetStage()), 1);
        }
        printf("stage = %d, progress = %f\n", c.p.GetStage(), 0.0f);
        printf(((c.p.GetCultivation() + "\n").c_str()) );
    };
    
 

    
    
    
    s.ScheduleInterval(std::chrono::milliseconds(50), Renderloop);
    printf("this ran\n");
	
    double start = 0.0f;
    double end;
    double dt;
   while (!glfwWindowShouldClose(window->window)) {
    //for (int i; i<2; i++) {
        
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
        end = glfwGetTime();
        dt = end - start;
        start = glfwGetTime();
        //printf("%f\n", dt);
        c.update(dt);
        
        
        
        gui.Draw();
        
		trender.RenderText(textshader, c.Repr(), 0, -300, 0.4, glm::vec3(0.0f,0.0f,0.0f));
        //trender.RenderText(textshader, c.s.GetCultivation(), -300, 0, 0.4, glm::vec3(0.0f,0.0f,0.0f));
        
        

        // double xpos, ypos;
        // glfwGetCursorPos(window.window, &xpos, &ypos);

        
       // printf("%f,%f\n", (float)xpos, (float)ypos);

        // printf("%i\n", button0.PointInBounds((float)xpos, (float)ypos, test.c));
        // if (button0.PointInBounds((float)xpos, (float)ypos, test.c)) {
        //     c.p.Action(c.p.GetStage(), button0.GetID());
        // }
        
        
        //button0.visual.Draw(test.c);

        //image.Draw(cam);

		glfwSwapBuffers(window->window);
		glfwPollEvents();
        
        //glfwSetWindowShouldClose(window.window, 1);
    }

	glfwTerminate();


    return 0;
}