#pragma once
#include "renderlib.h"
#include "Renderer.h"
#include "Shader.h"
#include "Camera.h"



namespace Render {
	class Sprite
	{
	public:
		Sprite(Window& w, const char* filepath, float x, float y, float width, float height, float rotation, Shader* s);
		~Sprite();

		void Draw(Camera& c);

		const void SetState(float x, float y, float rot);
		const void SetState(float x, float y);
		const void SetState(float rot);


	private:
		Window& w;
		unsigned int VAO;
		unsigned int VBO;
		unsigned int texture;
		float rotation;
		Shader* shader;
		glm::vec2 position;
		glm::vec2 size;

	};

}