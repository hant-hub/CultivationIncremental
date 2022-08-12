#pragma once
#include "renderlib.h"
#include "Camera.h"

namespace Render {


	struct Window {
		GLFWwindow* window;
		int width;
		int height;
		void Resize(GLFWwindow* _, int w, int h);
	};
	
	

	Window* CreateWindow(int width, int height);

	static std::vector<Window> windows;
};