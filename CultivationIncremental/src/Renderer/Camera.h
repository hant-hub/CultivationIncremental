#pragma once
#include "renderlib.h"

namespace Render {

	

	class Camera
	{
	public:
		Camera(float x, float y, float width, float height);
		~Camera();

		const glm::mat4 GetView() { return view; }
		const void SetState(float x, float y, float z);
		const void SetState(float x, float y);
		const void SetState(float z);
	private:
		float screenWidth, screenHeight;
		glm::vec2 position;
		float zoom;
		glm::mat4 view;

	};

}