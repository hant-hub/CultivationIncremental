#include "Renderer.h"




void Resize(GLFWwindow* w, int width, int height){
		Render::Window& window = Render::windows[0];
		window.width = width;
		window.height = height;

		glViewport(0, 0, width, height);
	}

Render::Window* Render::CreateWindow(int width, int height) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Render::Window w({nullptr, 0, 0});

	GLFWwindow* window = glfwCreateWindow(width, height, "Test Stuff", NULL, NULL);
	if (window == NULL) {
		std::cout << "ERROR: Window failed to initialize!" << std::endl;
		glfwTerminate();
		return nullptr;
	}



	glfwMakeContextCurrent(window);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "ERROR: GLAD failed to load" << std::endl;
		return nullptr;
	}


	glViewport(0, 0, width, height);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	
	glfwSetFramebufferSizeCallback(window, Resize);

	windows.push_back(Window({ window, width, height }));

	return &windows.back();

}
