#pragma once
#include "renderlib.h"
#include "Camera.h"

namespace Render {


	struct Window {
		GLFWwindow* window;
		int width;
		int height;
	};
	
	

	Window CreateWindow(int width, int height);


};