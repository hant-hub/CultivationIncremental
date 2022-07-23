#include "Camera.h"

Render::Camera::Camera(float x, float y, float width, float height)
{
	position = -glm::vec2(x, y);
	zoom = 1.0f;
	screenWidth = width;
	screenHeight = height;
	
	view = glm::mat4(1.0f);

	view = glm::translate(view, glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));
	view = glm::scale(view, glm::vec3(zoom));
	view = glm::translate(view, -glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));

	view = glm::translate(view, glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));
	view = glm::translate(view, glm::vec3(position, 0.0f));
}

Render::Camera::~Camera()
{
}

const void Render::Camera::SetState(float x, float y, float z)
{
	position = -glm::vec2(x, y);
	zoom = z;

	view = glm::mat4(1.0f);

	view = glm::translate(view, glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));
	view = glm::scale(view, glm::vec3(zoom));
	view = glm::translate(view, -glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));

	view = glm::translate(view, glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));
	view = glm::translate(view, glm::vec3(position, 0.0f));
}

const void Render::Camera::SetState(float x, float y)
{
	position = -glm::vec2(x, y);

	view = glm::mat4(1.0f);

	view = glm::translate(view, glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));
	view = glm::scale(view, glm::vec3(zoom));
	view = glm::translate(view, -glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));

	view = glm::translate(view, glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));
	view = glm::translate(view, glm::vec3(position, 0.0f));
}

const void Render::Camera::SetState(float z)
{
	zoom = z;

	view = glm::mat4(1.0f);

	view = glm::translate(view, glm::vec3(screenWidth/2, screenHeight/2, 0.0f));
	view = glm::scale(view, glm::vec3(zoom));
	view = glm::translate(view, -glm::vec3(screenWidth/2, screenHeight/2, 0.0f));

	view = glm::translate(view, glm::vec3(screenWidth / 2, screenHeight / 2, 0.0f));
	view = glm::translate(view, glm::vec3(position, 0.0f));
}


